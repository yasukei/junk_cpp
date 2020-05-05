#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <array>
#include <vector>
#include <map>
#include <memory>

class Object
{
public:
	virtual std::string to_string() const = 0;
	virtual ~Object() {}

	bool isSameType(const Object& other) const
	{
		return typeid(this) == typeid(other);
	}
};

class None : public Object
{
public:
	std::string to_string() const override
	{
		return "+";
	}

	static None* getInstance()
	{
		return &_instance;
	}
private:
	static None _instance;
};
None None::_instance;

class BlackStone : public Object
{
public:
	std::string to_string() const override
	{
		return "@";
	}

	static BlackStone* getInstance()
	{
		return &_instance;
	}
private:
	static BlackStone _instance;
};
BlackStone BlackStone::_instance;

class WhiteStone : public Object
{
public:
	std::string to_string() const override
	{
		
		return "O";
	}

	static WhiteStone* getInstance()
	{
		return &_instance;
	}
private:
	static WhiteStone _instance;
};
WhiteStone WhiteStone::_instance;

class Board
{
public:
	Board(
		size_t row_size = 8,
		size_t col_size = 8,
		char first_row_label = '1',
		char first_col_label = 'a'
	) :
		_board(row_size, std::vector<Object*>(col_size, None::getInstance())),
		_row_label(),
		_col_label()
	{
		if (row_size <= 0 || 9 <= row_size)
		{
			// TODO: exception
			return;
		}
		if (col_size <= 0 || 9 <= col_size)
		{
			// TODO: exception
			return;
		}

		for (int i = 0; i < row_size; i++)
		{
			_row_label.push_back(first_row_label + i);
		}
		for (int i = 0; i < col_size; i++)
		{
			_col_label.push_back(first_col_label + i);
		}
	}

	std::string to_string() const
	{
		std::string spacer = " ";
		std::string new_line = "\n";
		std::string output = "";

		output += spacer;
		for (int i = 0; i < _board.size(); i++)
		{
			output += spacer + _col_label[i];
		}
		output += new_line;

		for (int i = 0; i < _board.size(); i++)
		{
			output += _row_label[i];
			for (int j = 0; j < _board[i].size(); j++)
			{
				output += spacer + _board[i][j]->to_string();
			}
			output += new_line;
		}

		return output;
	}

	void put(size_t row, size_t col, Object* object)
	{
		_board.at(row).at(col) = object;
	}
	const Object* get(size_t row, size_t col) const
	{
		return _board.at(row).at(col);
	}
	const Object* take(size_t row, size_t col)
	{
		const Object* obj = get(row, col);
		put(row, col, None::getInstance());
		return obj;
	}

private:
	std::vector<std::vector<Object*>> _board;
	std::vector<char> _row_label;
	std::vector<char> _col_label;
};

class Command
{
public:
	virtual const std::string& getCommandName() const = 0; // TODO: can I return 'reference'?
	virtual void execute(const std::vector<std::string>& command_args, std::ostream& out) = 0;
};

class EchoCommand : public Command
{
public:
	const std::string& getCommandName() const override
	{
		static std::string name("echo");
		return name;
	}
	void execute(const std::vector<std::string>& command_args, std::ostream& out) override
	{
		for (auto arg : command_args)
		{
			out << arg << " ";
		}
		out << std::endl;
	}
};

class PutCommand : public Command
{
public:
	PutCommand(std::shared_ptr<Board> board) :
		_board(board)
	{
	}

	const std::string& getCommandName() const override
	{
		static std::string name("put");
		return name;
	}
	void execute(const std::vector<std::string>& command_args, std::ostream& out) override
	{
		if (command_args.size() < 3)
		{
			out << "Error: not enough arguments" << std::endl;
			return;
		}
		size_t row = std::stoul(command_args[0]);
		size_t col = std::stoul(command_args[1]);
		
		if (command_args[2].front() == 'b')
		{
			_board->put(row, col, BlackStone::getInstance());
		}
		else if (command_args[2].front() == 'w')
		{
			_board->put(row, col, WhiteStone::getInstance());
		}
		else
		{
			out << "Error: invalid arguments" << std::endl;
		}
		out << _board->to_string().c_str();
	}
private:
	std::shared_ptr<Board> _board;
};


class Commands
{
public:
	void addCommand(std::shared_ptr<Command> command)
	{
		std::string key(command->getCommandName());
		_commands.insert(std::make_pair(key, command));
	}

	void execute(const std::string& command_name, const std::vector<std::string>& command_args, std::ostream& out)
	{
		auto it = _commands.find(command_name);
		if (it == _commands.end())
		{
			out << "Error: '" << command_name << "' not found." << std::endl;
			return;
		}
		it->second->execute(command_args, out);
		out << std::endl;
	}

private:
	std::map<std::string, std::shared_ptr<Command>> _commands;
};

class CUI
{
public:
	CUI(
		Commands& commands,
		std::istream& in = std::cin,
		std::ostream& out = std::cout
	) :
		_in(in),
		_out(out),
		_commands(commands)
	{
	}

	void run()
	{
		std::array<char, 64> buf;

		while (true)
		{
			_in.getline(buf.data(), buf.size());
			if (!_in.good())
			{
				break;
			}

			std::string s(buf.data());
			std::istringstream iss(s);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };

			std::string command_name = tokens.front();
			tokens.erase(tokens.begin());
			_commands.execute(command_name, tokens, _out);
		}
	}

private:
	Commands& _commands;
	std::istream& _in;
	std::ostream& _out;
};

int main()
{
	std::shared_ptr<Board> board(new Board());
	BlackStone black;
	WhiteStone white;

	std::cout << board->to_string().c_str();

	Commands commands;
	std::shared_ptr<Command> echo(new EchoCommand());
	std::shared_ptr<Command> put(new PutCommand(board));
	commands.addCommand(echo);
	commands.addCommand(put);
	CUI cui(commands);
	//cui.run();

	return 0;
}
