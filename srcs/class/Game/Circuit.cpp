//
// EPITECH PROJECT, 2018
// ex00
// File description:
// ex00
//

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "tekspice.hpp"

nts::Component *nts::Circuit::getByName(const std::string &name_id)
{
	return nts::Circuit::convert(this->map[name_id]);
}

std::vector<nts::Component *> nts::Circuit::getByType(const std::string &type)
{
	std::vector<nts::Component *> array;

	for (auto component = this->map.begin();
	component != this->map.end(); component++) {
		nts::Component *object = Circuit::convert(component->second);
		if (object->type == type) {
			array.push_back(object);
		}
	}
	return array;
}

void nts::Circuit::add(const std::string &name,
		std::unique_ptr<nts::IComponent> &&c)
{
	if (c)
		this->map.insert(std::pair<std::string,
				 std::unique_ptr<nts::IComponent>>(name,
							std::move(c)));
}

int nts::Circuit::simulate(void)
{
	std::vector<nts::Component *> outputs;

	outputs = this->getByType("output");

	for (auto output = outputs.begin() ;
	output != outputs.end() ; ++output) {
		setStateByOutput(this, *output, 1);
	}
	default_commands(this);
	return 0;
}

int nts::Circuit::display(void)
{
	dump_circuit(this, "output");
	return 0;
}

int nts::Circuit::loop(void)
{
	this->mode = nts::Circuit::LOOP;
	return 0;
}

int nts::Circuit::dump(void)
{
	dump_circuit(this);
	return 0;
}

std::map<std::string, int (nts::Circuit::*)()> nts::Circuit::commands =
{
	{"simulate", &nts::Circuit::simulate},
	{"display", &nts::Circuit::display},
	{"loop", &nts::Circuit::loop},
	{"dump", &nts::Circuit::dump}
};
