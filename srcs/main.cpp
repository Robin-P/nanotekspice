//
// EPITECH PROJECT, 2018
// main
// File description:
// main
//

#include "tekspice.hpp"

void check_component_link_and_input_value(nts::Circuit *circuit)
{
	for (auto component = circuit->map.begin();
	     component != circuit->map.end(); component++) {
		nts::Component *object = nts::Circuit::convert(component->second);
		if ((object->type == "input"
		|| object->type == "clock")
		&& object->pin[0]->state == nts::UNDEFINED)
			throw nts::LogicError(object->name
					 + "\' is an input without value");
		std::vector<nts::Pin *> pin = object->pin;
		bool isLink = false;
		for (auto one = pin.begin(); one != pin.end(); one++) {
			std::vector<nts::link> links = object->getLink((*one)->pinName);
			for (auto link = links.begin() ;
			     link != links.end() ; link++) {
				nts::Component *com = circuit->getByName((*link).name);
				if (com != nullptr)
					isLink = true;
			}
		}
		if (!isLink)
			throw nts::LogicError(object->name
					+ "\' is not linked to anything.");
	}
}

void assign_value(char **array, nts::Circuit *circuit)
{
	size_t index = 0;
	nts::Tristate state;

	while (array[index]) {
		std::vector<std::string> vec = nts::Parser::explode(array[index], '=');
		if (vec.size() < 2)
			throw nts::LogicError(std::string("\'")
					+ array[index]
					+ std::string("\' Syntax error."));
		nts::Component *component = circuit->getByName(vec[0]);
		if (!component)
			throw nts::LogicError(vec[0] + " component not found.");
		state = static_cast<nts::Tristate>(nts::Parser::stringToNumber(vec[1]));
		if (state < -1 || state > 1)
			throw nts::LogicError(vec[1] + " unknown value.");
		component->pin[0]->state = state;
		++index;
	}
}

int main(int ac, char **av)
{
	nts::Circuit *circuit = new nts::Circuit();

	try {
		if (ac >= 2 && av[1] != nullptr)
			nts::Parser parser(av[1], circuit);
		else
			throw nts::LogicError("Program need a file pathname.");
		if (ac > 2)
			assign_value(&av[2], circuit);
		check_component_link_and_input_value(circuit);
		launch(circuit);
		delete circuit;
		return 0;
	} catch (nts::ParserError &err) {
		std::cout << err.what() << std::endl;
	} catch (nts::LogicError &err) {
		std::cout << err.what() << std::endl;
	}
	delete circuit;
	return 84;
}
