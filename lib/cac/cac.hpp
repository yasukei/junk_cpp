#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <cstring>
#include <map>

#define cCacMaxDataSize 1024

namespace cac
{

//---------------------------------------------------------
struct FormatId
{
	enum Enum
	{
		Full = 1,
		Fragmented = 2,
	};
	Enum data;
};

//---------------------------------------------------------
struct Priority
{
	enum Enum
	{
		Low = 0,
		Middle = 1,
		High = 2,
	};
	uint8_t data;
};

//---------------------------------------------------------
struct TransactionId
{
	enum Enum
	{
		Min = 0x00,
		Max = 0xFF,
	};
	uint8_t data;
};

//---------------------------------------------------------
struct Status
{
	enum Enum
	{
		Processing = 0x0,
		Complete   = 0x1,
		Busy       = 0xE,
		Error      = 0xF,
	};
	uint8_t data;
};

//---------------------------------------------------------
struct FragmentId
{
	enum Enum
	{
		Min = 0x00,
		Max = 0xFF,
	};
	uint16_t data;
};

//---------------------------------------------------------
#define NbitMask(n) (~(~0 << (n)))

//---------------------------------------------------------
struct RequestHeader
{
	RequestHeader(
		FormatId formatId,
		Priority priority,
		TransactionId transactionId,
		uint32_t size
	)
	{
	}

	struct MemoryMapping
	{
		union
		{
			uint8_t formatId : 4;
			uint8_t priority : 4;
		}u;
		uint8_t transactionId;
		uint8_t size[4];
	};

	size_t getSize() { return sizeof(MemoryMapping); }
	void serialize();
	void deserialize();

	FormatId formatId();
	Priority priority();
	TransactionId transactionId();
	uint32_t size();

	//uint8_t* pack(uint8_t* buffer)
	//{
	//	MemoryMapping* m = (MemoryMapping*)buffer;
	//	m->u.typeId = typeId.data & NbitMask(2);
	//	m->u.formatId = formatId.data & NbitMask(2);
	//	m->u.priority = priority.data & NbitMask(4);
	//	m->transactionId = transactionId.data;
	//	memcpy(m->size, &size, sizeof(m->size));
	//	return buffer + sizeof(MemoryMapping);
	//}
	//uint8_t unpack(uint8_t buffer)
	//{
	//	MemoryMapping* m = (MemoryMapping*)buffer;
	//	typeId.data = (TypeId::Enum)(m->u.typeId & NbitMask(2));
	//	formatId.data = (FormatId::Enum)(m->u.formatId & NbitMask(2));
	//	priority.data = m->u.priority & NbitMask(4);
	//	transactionId.data = m->transactionId;
	//	memcpy(&size, m->size, sizeof(m->size));
	//	return buffer + sizeof(MemoryMapping);
	//}
};

//---------------------------------------------------------
struct ResponseHeader
{
	FormatId formatId;
	Priority priority;
	TransactionId transactionId;
	Status status;
	uint32_t size;
};

//---------------------------------------------------------
struct FragmentHeader
{
	FragmentId fragmentId;
	uint16_t fragmentedSize;
};

//---------------------------------------------------------
struct RequestFragmentData
{
	RequestHeader requestHeader;
	FragmentHeader fragmentHeader;
	uint8_t* requestData;
};

//---------------------------------------------------------
struct RequestFullData
{
	RequestHeader requestHeader;
	uint8_t* requestData;
};

//---------------------------------------------------------
struct ResponseFragmentData
{
	ResponseHeader responseHeader;
	FragmentHeader fragmentHeader;
	uint8_t* responseData;
};

//---------------------------------------------------------
struct ResponseFullData
{
	ResponseHeader responseHeader;
	uint8_t* responseData;
};

//---------------------------------------------------------
class RequestData
{
public:

};

//---------------------------------------------------------
class ResponseData
{

};

//---------------------------------------------------------
class Transaction
{
public:
	void initialize(Priority::Enum priority, uint8_t id)
	{
		_priority = priority;
		_id = id;
	}

	Priority::Enum getPriority()
	{
		return _priority;
	}

	uint32_t getTransactionId()
	{
		return (_priority << 16) || _id;
	}

	void setSendData(uint8_t* sendData, uint32_t sendDataSize)
	{
		_sendData = sendData;
		_sendDataSize = sendDataSize;
	}

private:
	Priority::Enum _priority;
	uint8_t _id;

	uint8_t* _sendData;
	uint32_t _sendDataSize;
};

//---------------------------------------------------------
class TransactionPool
{
public:
	void initialize(
		uint8_t numofHighPriority,
		uint8_t numofMiddlePriority,
		uint8_t numofLowPriority
	)
	{
		uint32_t total = numofHighPriority + numofMiddlePriority + numofLowPriority;
		_transactions.reserve(total);
		
		assignTransactionsToPool(
			_transactions.data(),
			Priority::High,
			_highPool,
			numofHighPriority
		);
		assignTransactionsToPool(
			&(_transactions.data())[numofHighPriority],
			Priority::Middle,
			_middlePool,
			numofMiddlePriority
		);
		assignTransactionsToPool(
			&(_transactions.data())[numofHighPriority + numofMiddlePriority],
			Priority::Low,
			_lowPool,
			numofLowPriority
		);
	}

	Transaction* getFreeTransaction(Priority::Enum priority)
	{
		std::vector<Transaction*> pool = choosePoolByPriority(priority);

		return getFreeTransaction(pool);
	}

	void returnTransaction(Transaction* transaction)
	{
		std::vector<Transaction*> pool = choosePoolByPriority(transaction->getPriority());

		returnTransaction(pool, transaction);
	}

private:
	std::vector<Transaction> _transactions;
	std::vector<Transaction*> _highPool;
	std::vector<Transaction*> _middlePool;
	std::vector<Transaction*> _lowPool;

	void assignTransactionsToPool(Transaction* transactions, Priority::Enum priority, std::vector<Transaction*>& pool, uint32_t numofAssignment)
	{
		pool.reserve(numofAssignment);
		for (int i = 0; i < numofAssignment; i++)
		{
			pool.push_back(&transactions[i]);
		}
		for (int i = 0; i < pool.size(); i++)
		{
			pool[i]->initialize(priority, i);
		}

	}

	std::vector<Transaction*>& choosePoolByPriority(Priority::Enum priority)
	{
		switch (priority)
		{
		case cac::Priority::Low:
			return _lowPool;
		case cac::Priority::Middle:
			return _middlePool;
		case cac::Priority::High:
			return _highPool;
		}
	}

	Transaction* getFreeTransaction(std::vector<Transaction*>& pool)
	{
		if (pool.empty())
		{
			return NULL;
		}

		Transaction* transaction = pool.back();
		pool.pop_back();
		return transaction;
	}

	void returnTransaction(std::vector<Transaction*>& pool, Transaction* transaction)
	{
		pool.push_back(transaction);
	}
};

//---------------------------------------------------------
class ActiveTransactions
{
public:
	void push(Transaction* transaction)
	{
		_map.insert({ transaction->getTransactionId(), transaction });
	}

	void pop(uint32_t transactionId)
	{
		_map.erase(transactionId);
	}
	Transaction* find(uint32_t transactionId)
	{
		std::map<uint32_t, Transaction*>::iterator it = _map.find(transactionId);
		if (it == _map.end())
		{
			return NULL;
		}
		return it->second;
	}

private:
	std::map<uint32_t, Transaction*> _map;
};

//---------------------------------------------------------
class Serializer
{
public:
	void serialize(uint8_t* rawData, uint32_t rawDataSize, ActiveTransactions& activeTransactions)
	{
		
	}

	void deserialize(uint8_t* rawData, uint32_t rawDataSize, ActiveTransactions& activeTransactions)
	{

	}

};

//---------------------------------------------------------
class PastData
{
public:
	void save(uint8_t* data, uint32_t dataSize, uint8_t transactionId)
	{
		// TODO
	}
	void restore(uint8_t* buffer, uint32_t bufferSize, uint8_t transactionId)
	{
		// TODO
	}
};

//---------------------------------------------------------
class Sequence
{
public:
	void reset() {}
	void update(uint8_t recvSeqId, uint8_t recvRepId){}
	uint8_t getSendSeqId() { return 0; }
	uint8_t getSendRepId() { return 0; }
	bool isReset() { return false; }
	bool isInDataValid() { return true; }
	bool isOutDataValid() { return true; }
};

//---------------------------------------------------------
class CallbackIF
{
public:
	virtual void onResestSent() {}
	virtual void onResponseReceived() {}

	virtual void onRequestReceived() {}
	virtual void onResponseSent() {}
};

//---------------------------------------------------------
class Cac
{
public:
	struct DataConfig
	{
		uint8_t* sequenceId;
		uint8_t* repeatId;
		uint8_t* data;
		uint32_t dataSize;
	};
	struct GeneralConfig
	{
		uint8_t numofHighPriority;
		uint8_t numofMiddlePriority;
		uint8_t numofLowPriority;
	};

	void initialize(
		const DataConfig& inputDataConfig,
		const DataConfig& outputDataConfig,
		const GeneralConfig& generalConfig,
		CallbackIF* callback
		)
	{
		_inputDataConfig = inputDataConfig;
		_outputDataConfig = outputDataConfig;
		_pool.initialize(
			generalConfig.numofHighPriority,
			generalConfig.numofMiddlePriority,
			generalConfig.numofLowPriority
		);
	}

	void inRefresh()
	{
		_sequence.update(*_inputDataConfig.sequenceId, *_inputDataConfig.repeatId);
		if (!_sequence.isInDataValid())
		{
			return;
		}

		// TODO: deserialize(_inputDataConfig.data, _inputDataConfig.dataSize, activeTransactions);
	}
	void outRefresh()
	{
		if (!_sequence.isOutDataValid())
		{
			// TODO: send past data
			return;
		}
		
		// TODO: serialize(_outputDataConfig.data, _outputDataConfig.dataSize, activeTransactions);
	}

	bool send(Priority::Enum priority, uint8_t* sendData, uint32_t sendDataSize, uint32_t& transactionId)
	{
		Transaction* transaction = _pool.getFreeTransaction(priority);
		if (transaction == NULL)
		{
			return false;
		}

		transactionId = transaction->getTransactionId();
		transaction->setSendData(sendData, sendDataSize);

		_activeTransactions.push(transaction);

		return true;
	}

	void cancel(uint32_t transactionId)
	{
		// TODO:
	}
	void reset()
	{
		// TODO:
	}

private:
	DataConfig _inputDataConfig;
	DataConfig _outputDataConfig;

	Sequence _sequence;
	CallbackIF* _callback;

	TransactionPool _pool;
	ActiveTransactions _activeTransactions;
};

} // namespace cac

