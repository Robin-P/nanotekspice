//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// exception
//

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <iostream>

namespace nts {
	class ParserError : public std::exception {
	public:
		ParserError(const std::string &message)
			{
				this->_message = message;
			}

		std::string const &getMessage() const
			{
				return this->_message;
			}

		virtual std::string what()
			{
				return "Error: Parser: " + this->_message;
			}

	private:
		std::string _message;
		std::string _component;
	};

	class LogicError : public std::exception {
	public:
		LogicError(const std::string &message)
			{
				this->_message = message;
			}

		std::string const &getMessage() const
			{
				return this->_message;
			}

		virtual std::string what()
			{
				return "Error: Logic: " + this->_message;
			}

	private:
		std::string _message;
	};
}
#endif /* !EXCEPTION_HPP_ */
