#include "ScalarConverter.hpp"
#include <cctype>

std::string float_data[4] = {"-inff", "+inff", "inff", "nanf"};
std::string	double_data[4] = {"-inf", "+inf", "inf", "nan"};

// OCCF

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& c)
{
	this->_convertChar = c._convertChar;
	this->_convertInt = c._convertInt;
	this->_convertFloat = c._convertFloat;
	this->_convertDouble = c._convertDouble;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& c)
{
	this->_convertChar = c._convertChar;
	this->_convertInt = c._convertInt;
	this->_convertFloat = c._convertFloat;
	this->_convertDouble = c._convertDouble;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

// func

void	ScalarConverter::caseChar(std::string str)
{
	char	c = str[0];
	if (std::isdigit(static_cast<int>(c)))
	{
		caseInt(str);
		return ;
	}
	if (std::isprint(c))
		this->_convertChar = static_cast<char>(c);
	else
		this->_convertChar = "None displayable";
	this->_convertInt = std::to_string(static_cast<int>(c));
	this->_convertFloat = std::to_string(static_cast<float>(c)) + "f";
	this->_convertDouble = std::to_string(static_cast<double>(c));
}

void	ScalarConverter::caseInt(const std::string str)
{
	int		integer = std::atoi(str.c_str());
	double	d_value = std::strtod(str.c_str(), 0);
	std::string	noSignStr = str;
	if (str[0] == '+' || str[0] == '-')
		noSignStr = str.substr(1, str.length());
	if (std::to_string(integer) != noSignStr)
	{
		int location = std::to_string(d_value).find('.', 0);
		if (std::to_string(d_value).substr(0, location) != str)
			ScalarConverter::caseString();
		else
			ScalarConverter::caseDouble(str);
	}
	else
	{
		if (isascii(static_cast<int>(integer)))
		{
			if (std::isprint(static_cast<int>(integer)))
				this->_convertChar = static_cast<char>(integer);
			else
				this->_convertChar = "Non displayable";
		}
		else
			this->_convertChar = "impossible";
		this->_convertInt = std::to_string(integer);
		float f_value = static_cast<float>(integer);
		int location = std::to_string(f_value).find('.');
		std::string noPlus = str;
		if (str[0] == '+')
			noPlus = str.substr(1, str.length());
		if (std::to_string(f_value).substr(0, location) != noPlus)
			this->_convertFloat = "impossible";
		else
			this->_convertFloat = std::to_string(static_cast<float>(integer)) + "f";
		this->_convertDouble = std::to_string(static_cast<double>(integer));
	}
}

void	ScalarConverter::caseFloat(const std::string str)
{
	bool	infinite = false;
	float	f_value;

	for (int i = 0; i < 4; i++)
	{
		if (str.compare(float_data[i]) == 0)
			infinite = true;
	}

	if (infinite == true)
	{
		this->_convertChar = "impossible";
		this->_convertInt = "impossible";
		if (str == "-inff")
			f_value = __DBL_MAX__ * (-1000);
		else if (str == "+inff" || str == "inff")
			f_value = __DBL_MAX__ * (1000);
		else
			f_value = sqrt(-1.0);
		this->_convertFloat = std::to_string(f_value) + "f";
		this->_convertDouble = std::to_string(static_cast<double>(f_value));
	}
	else
	{
		f_value = std::strtof(str.c_str(), 0);
		if (isascii(static_cast<int>(f_value)))
		{
			if (std::isprint(static_cast<int>(f_value)))
				this->_convertChar = static_cast<char>(f_value);
			else
				this->_convertChar = "Non displayable";
		}
		else
			this->_convertChar = "impossible";
		this->_convertInt = std::to_string(static_cast<int>(f_value));
		this->_convertFloat = std::to_string(f_value) + "f";
		this->_convertDouble = std::to_string(static_cast<double>(f_value));
	}
}

void	ScalarConverter::caseDouble(const std::string str)
{
	bool	infinite = false;
	double	d_value;

	for (int i = 0; i < 4; i++)
	{
		if (str.compare(double_data[i]) == 0)
			infinite = true;
	}

	if (infinite == true)
	{
		this->_convertChar = "impossible";
		this->_convertInt = "impossible";
		if (str == "-inf")
			d_value = __DBL_MAX__ * (-1000);
		else if (str == "+inf" || str == "inf")
			d_value = __DBL_MAX__ * (1000);
		else
			d_value = sqrt(-1.0);
		this->_convertFloat = std::to_string(static_cast<float>(d_value)) + "f";
		this->_convertDouble = std::to_string(d_value);
	}
	else
	{
		d_value = std::strtod(str.c_str(), 0);
		if (isascii(static_cast<int>(d_value)))
		{
			if (std::isprint(static_cast<int>(d_value)))
				this->_convertChar = static_cast<char>(d_value);
			else
				this->_convertChar = "Non displayable";
		}
		else
			this->_convertChar = "impossible";

		int i_value = std::atoi(str.c_str());
		if (std::to_string(i_value) != str)
			this->_convertInt = "impossible";
		else
			this->_convertInt = std::to_string(static_cast<int>(d_value));
		
		float f_value = std::strtof(str.c_str(), 0);
		if (std::to_string(f_value).substr(0, str.length()).c_str() != str)
			this->_convertFloat = "impossible";
		else
			this->_convertFloat = std::to_string(static_cast<float>(d_value)) + "f";
		this->_convertDouble = std::to_string(d_value);
	}
}

void	ScalarConverter::caseString()
{
	this->_convertChar = "impossible";
	this->_convertInt = "impossible";
	this->_convertFloat = "impossible";
	this->_convertDouble = "impossible";
}

static int	isstring(const char *input)
{
	int	idx = 1;
	int	dot_cnt = 0;

	if (input[0] == '.')
		return (1);
	while (input[idx])
	{
		if (input[idx] == '.')
			dot_cnt++;
		else if (input[idx] == 'f')
		{
			if (input[idx + 1])
				return (1);
		}
		else if (isdigit(input[idx]) == 0)
			return (1);
		idx++;
	}
	if (dot_cnt > 1)
		return (1);
	return (0);
}

static	int isint(const char *input)
{
	int	idx = 1;

	if (!(input[0] == '+' || input[0] == '-' || isdigit(input[0])))
		return (0);
	while (input[idx])
	{
		if (isdigit(input[idx]) == 0)
			return (0);
		idx++;
	}
	return (1);
}

static int	checkType(std::string input)
{
	const	char* charInput = input.c_str();

	if (input.length() == 1)
		return (E_CHAR);
	for (int i = 0; i < 4; i++)
	{
		if (input.compare(float_data[i]) == 0)
			return (E_FLOAT);
		if (input.compare(double_data[i]) == 0)
			return (E_DOUBLE);
	}
	if (isstring(charInput))
		return (E_STR);
	if (isint(charInput))
		return (E_INT);
	if (charInput[input.length() - 1] == 'f')
		return (E_FLOAT);
	return (E_DOUBLE);
}

void	ScalarConverter::printResult()
{
	std::cout << "char: " << this->_convertChar << std::endl;
	std::cout << "int: " << this->_convertInt << std::endl;
	std::cout << "float: " << this->_convertFloat << std::endl;
	std::cout << "double: " << this->_convertDouble << std::endl;
}

void	ScalarConverter::convert(std::string input)
{
	switch (checkType(input))
	{
		case E_CHAR :
			ScalarConverter::caseChar(input);
			break;
		case E_STR:
			ScalarConverter::caseString();
			break;
		case E_INT :
			ScalarConverter::caseInt(input);
			break;
		case E_DOUBLE :
			ScalarConverter::caseDouble(input);
			break;
		default:
			ScalarConverter::caseFloat(input);
	}
	printResult();
}