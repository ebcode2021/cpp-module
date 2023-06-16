# include "RPN.hpp"

/* OCCF */
RPN::RPN(){}

RPN::RPN(const RPN& rpn)
{
	this->_stack = rpn._stack;
}

RPN& RPN::operator=(const RPN& rpn)
{
	if (this != &rpn)
	{
		this->_stack = rpn._stack;
	}
	return (*this);
}

RPN::~RPN(){}

/* constructor */
RPN::RPN(char *argument)
{
	run(std::string(argument));
}

/* method */

void	RPN::run(const std::string& input)
{
	std::string			token;
	std::istringstream	iss(input);

	while (std::getline(iss, token, ' '))
	{
		if (isdigit(token[0]))
		{
			int	num = std::atoi(token.c_str());
			if (num < -9 || num > 9)
				printErrorWithExit();
			this->_stack.push(num);
		}
		else if (token[0] == '+' || token[0] == '-' || token[0] == '/' || token[0] == '*')
		{
			if (this->_stack.size() < 2)
				printErrorWithExit();
			int	num2 = this->_stack.top();
			this->_stack.pop();
			int	num1 = this->_stack.top();
			this->_stack.pop();

			int	result;
			switch (token[0])
			{
				case '+' :
					result = num1 + num2;
					break ;
				case '-' :
					result = num1 - num2;
					break ;
				case '*' :
					result = num1 * num2;
					break ;
				case '/' :
					if (num2 == 0)
						printErrorWithExit();
					result = num1 / num2;
					break ;
				default:
					printErrorWithExit();
					break;
			}
			this->_stack.push(result);
		}
		else
			printErrorWithExit();
	}
	std::cout << this->_stack.top() << std::endl;
}

void	RPN::printErrorWithExit()
{
	std::cout << "Error" << std::endl;
	exit(1);
}
