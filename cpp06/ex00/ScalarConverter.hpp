#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>

enum Type
{
	E_STR,
	E_CHAR,
	E_INT,
	E_FLOAT,
	E_DOUBLE,
};

class	ScalarConverter
{
	private :
		std::string	_convertChar;
		std::string	_convertInt;
		std::string	_convertFloat;
		std::string	_convertDouble;

		void	printResult();

	public :
		// OCCF
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

		void	caseChar(std::string str);
		void	caseInt(const std::string str);
		void	caseFloat(const std::string str);
		void	caseDouble(const std::string str);
		void	caseString();
		// static function
		void	convert(std::string);

};

#endif