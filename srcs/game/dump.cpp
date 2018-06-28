//
// EPITECH PROJECT, 2018
// exOO
// File description:
// exOO
//

#include "tekspice.hpp"

int dump_circuit(nts::Circuit *circuit, const std::string &c_type)
{
	std::vector<nts::Component *> array = circuit->getByType(c_type);

	for (auto component = array.begin() ;
	component != array.end(); component++) {
		std::cout << (*component)->name
			  << "=";
		if ((*component)->pin[0]->state == -1)
			std::cout << 'U';
		else
			std::cout << (*component)->pin[0]->state;
		std::cout << std::endl;
	}
	return SUCCESS;
}

int dump_circuit(nts::Circuit *circuit)
{
	for (auto component = circuit->map.begin() ;
	component != circuit->map.end(); component++) {
		nts::Component *object = circuit->convert(component->second);
		object->dump();
	}
	return SUCCESS;
}
