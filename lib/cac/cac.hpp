#pragma once

#include <iostream>
#include <vector>
#include <array>

#define cCacMaxDataSize 1024

namespace cac
{

//---------------------------------------------------------
struct TypeId
{
	enum Enum
	{
		Request = 1,
		Response = 2,
	};
	Enum data;
};

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
	TypeId typeId;
	FormatId formatId;
	Priority priority;
	TransactionId transactionId;
	uint32_t size;

	struct MemoryMapping
	{
		union
		{
			uint8_t typeId : 2;
			uint8_t formatId : 2;
			uint8_t priority: 4;
		}u;
		uint8_t transactionId;
		uint8_t size[4];
	};
	uint8_t* pack(uint8_t* buffer)
	{
		MemoryMapping* m = (MemoryMapping*)buffer;
		m->u.typeId = typeId.data & NbitMask(2);
		m->u.formatId = formatId.data & NbitMask(2);
		m->u.priority = priority.data & NbitMask(4);
		m->transactionId = transactionId.data;
		memcpy(m->size, &size, sizeof(m->size));
		return buffer + sizeof(MemoryMapping);
	}
	uint8_t unpack(uint8_t buffer)
	{
		MemoryMapping* m = (MemoryMapping*)buffer;
		typeId.data = (TypeId::Enum)(m->u.typeId & NbitMask(2));
		formatId.data = (FormatId::Enum)(m->u.formatId & NbitMask(2));
		priority.data = m->u.priority & NbitMask(4);
		transactionId.data = m->transactionId;
		memcpy(&size, m->size, sizeof(m->size));
		return buffer + sizeof(MemoryMapping);
	}
};

//---------------------------------------------------------
struct ResponseHeader
{
	TypeId typeId;
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
class CacPacket
{

};

//---------------------------------------------------------
class CacFrame
{

};

//---------------------------------------------------------
struct SequenceId
{
	enum Enum
	{
		Initial = 0x00,
		Standby = 0x01,
		Min     = 0x02,
		Max     = 0xFE,
		Reset   = 0xFF,
	};
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
	struct Setting
	{
		uint8_t* sequenceIdArea;
		uint8_t* repeatIdArea;
		uint8_t* dataArea;
		uint32_t dataAreaSize;
	};

	void initialize(
		const Setting& inputSetting,
		const Setting& outputSetting,
		CallbackIF* callback
		)
	{
		_inputSetting = inputSetting;
		_outputSetting = outputSetting;
	}

	void refreshInput()
	{
		uint8_t sequenceId = *_inputSetting.sequenceIdArea;
		uint8_t repeatId = *_inputSetting.repeatIdArea;
		uint8_t* inputData = _inputSetting.dataArea;

		_sequence.update(sequenceId, repeatId);
		if (!_sequence.isInDataValid())
		{
			return;
		}

		// TODO: processInputData();
	}
	void refreshOutput()
	{
		if (!_sequence.isOutDataValid())
		{
			return;
		}
		// TODO:
	}



private:
	Setting _inputSetting;
	Setting _outputSetting;

	Sequence _sequence;
	CallbackIF* _callback;

	void processInputData(uint8_t* inputData, uint32_t inputDataSize)
	{
		
	}
};

} // namespace cac

