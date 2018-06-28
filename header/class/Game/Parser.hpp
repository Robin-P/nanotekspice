//
// EPITECH PROJECT, 2018
// ex00
// File description:
// ex00
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include "exception.hpp"
#include "Factory.hpp"
#include "Component.hpp"
#include "Circuit.hpp"

namespace nts {
class Parser {
public:
	// FUNCTION FOR PARSER
	static const std::vector<std::string> explode(const std::string &s,
						      const char &sep)
		{
			std::string buff("");
			std::vector<std::string> vec;

			for (auto n:s) {
				if (n != sep)
					buff += n;
				else if (n == sep && buff != "") {
					vec.push_back(buff);
					buff = "";
				}
			}
			if (buff != "")
				vec.push_back(buff);
			return vec;
		}

	static size_t stringToNumber(const std::string &str)
		{
			std::istringstream ss(str);
			size_t size;

			ss >> size;
			return size;
		}

	static bool check_first(std::string str, std::string part)
		{
			auto i = str.begin();
			auto j = part.begin();

			if (!str.empty() && !part.empty()) {
				while (i != str.end() && j != part.end()
				       && *i == *j) {
					++i;
					++j;
				}
				if (*j == '\0')
					return true;
			}
			return false;
		}

		//PARSER
	void apply_links(Circuit *circuit, std::vector<std::string> array_from,
			std::vector<std::string> array_to, std::string str)
		{
			Component *tmp = circuit->getByName(array_from[0]);
			Component *component_to = nullptr;
			Component *component_from = nullptr;
			size_t pinNb = 0;

			if (tmp) {
				pinNb = Parser::stringToNumber(array_from[1]) - 1;
				if (static_cast<int>(pinNb) < 0 || pinNb > tmp->pin.size())
					throw nts::LogicError("Index out of range");
				component_from = circuit->getByName(array_from[0]);
				component_to = circuit->getByName(array_to[0]);
			}
			if (component_from == nullptr || component_to == nullptr)
				throw nts::ParserError(str + " Unknown component in links section.");
			if (tmp->pin[pinNb]->type == nts::Pin::INPUT) {
				component_to->setLink(Parser::stringToNumber(array_to[1]), *component_from,
						      Parser::stringToNumber(array_from[1]));
			} else {
				component_from->setLink(Parser::stringToNumber(array_from[1]), *component_to,
							Parser::stringToNumber(array_to[1]));
			}
		}
	void links(Circuit *circuit, std::string str)
		{
			std::istringstream stream(str);
			std::string from;
			std::string to;

			stream >> from;
			stream >> to;
			std::vector<std::string> array_from = Parser::explode(from, ':');
			std::vector<std::string> array_to = Parser::explode(to, ':');
			if (array_from.size() < 2 || array_to.size() < 2) {
				throw nts::ParserError(str +
						       " Please check the links section format: " +
						       "(component_name:pin) (other_component_name:other_pin).");
			}
			apply_links(circuit, array_from, array_to, str);
		}

	void find_links(Circuit *circuit, std::ifstream &file)
		{
			std::string str;

			while (!file.eof()) {
				getline(file, str);
				std::stringstream ss;
				std::string tmp;
				ss << str;
				ss >> tmp;
				if (!tmp.empty() && tmp[0] != '#'
				&& !str.empty()) {
					str = (Parser::explode(str, '#'))[0];
					if (!str.empty())
						this->links(circuit, str);
				}
			}
		}

	void chipsets(Circuit *circuit, std::ifstream &file)
		{
			Factory factory;
			std::string str;
			std::string type;
			std::string name;

			while (!file.eof()) {
				type = "";
				name = "";
				getline(file, str);
				if (Parser::check_first(str, ".links:"))
					return this->find_links(circuit, file);
				std::istringstream stream(str);
				stream >> type;
				stream >> name;
				circuit->add(name,
					factory.createComponent(type, name));
			}
		}

		//CONSTRUCT && DESTRUCT
	~Parser()
		{
		}

	Parser(const std::string &filename, Circuit *circuit)
		{
			std::ifstream file(filename);
			std::string str;

			if (!file.is_open())
				throw nts::ParserError("File not found.");
			while (!file.eof()) {
				getline(file, str);
				if (Parser::check_first(str, ".chipsets:"))
					chipsets(circuit, file);
			}
		}
	};
}
#endif /* !PARSER_HPP_ */
