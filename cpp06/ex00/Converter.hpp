#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>

class	Converter
{
	private :
		std::string	convertChar;
		std::string	convertInt;
		std::string	convertFloat;
		std::string	convertDouble;

	public :
		// OCCF
		Converter();
		Converter(const Converter&);
		Converter& operator=(const Converter&);
		~Converter();

		// getter setter
		std::string	getChar() const;
		std::string	getInt() const;
		std::string getFloat() const;
		std::string getDouble() const;
		void	setChar(const std::string);
		void	setInt(const std::string);
		void	setFloat(const std::string);
		void	setDouble(const std::string);

		// static function
		static void	convert(std::string);
	

};

#endif