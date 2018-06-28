//
// EPITECH PROJECT, 2018
// ex00
// File description:
// ex00
//

#include <algorithm>
#include "Parser.hpp"
#include "tekspice.hpp"

int my_assignement(nts::Circuit *circuit, const std::string &str)
{
	std::vector<std::string> array = nts::Parser::explode(str, '=');
	nts::Tristate state;

	if (array.size() < 2 || array[0].empty() || array[1].empty()) {
		std::cout << "Error: " << str
			  << " syntax error (component_name=value)."
			  << std::endl;
		return ERROR;
	}
	nts::Component *component = circuit->getByName(array[0]);
	if (component != nullptr && component->type == "input") {
		state = static_cast<nts::Tristate>(nts::Parser::stringToNumber(array[1]));
		if (state < 0 || state > 1)
			std::cout << "Error: " << state
				  << " value out of range." << std::endl;
		else
			component->pin[0]->state = state;
	} else {
		std::cout << "Error: " << array[0]
			  << " component not found or is not an input."
			  << std::endl;
		return SUCCESS; // Don\'t stop the game
	}
	return SUCCESS;
}

int my_commands(nts::Circuit *circuit, const std::string &str)
{
	auto ptr = circuit->commands[str];

	if (ptr)
		(circuit->*ptr)();
	else
		std::cout << "Error: " << str
			<< " command not found." << std::endl;
	return SUCCESS;
}

void default_commands(nts::Circuit *circuit)
{
	std::vector<nts::Component *> clocks = circuit->getByType("clock");

	if (!clocks.empty()) {
		for (auto clock = clocks.begin() ;
		clock != clocks.end() ; ++clock) {
			if ((*clock)->pin[0]->state == nts::TRUE)
				(*clock)->pin[0]->state = nts::FALSE;
			else
				(*clock)->pin[0]->state = nts::TRUE;
		}
	}
}
