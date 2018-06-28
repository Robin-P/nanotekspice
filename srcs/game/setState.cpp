//
// EPITECH PROJECT, 2018
// EX00
// File description:
// eX00
//

#include "tekspice.hpp"

void setStateByInput(nts::Circuit *circuit, nts::Component *object,
		size_t pinNb, size_t protectedPin, std::string protectedName)
{
	if (!object->getLink(pinNb).empty()) {
		nts::link list = object->getLink(pinNb)[0];
		nts::Component *component = circuit->getByName(list.name);
		nts::PinOutput *pin;
		pin = static_cast<nts::PinOutput *>(component->pin[list.from
								- 1]);
		if (!pin->dependencies.empty()) {
			if (!(protectedName == component->name
			&& pin->pinName == protectedPin))
			setStateByOutput(circuit, component, pin->pinName);
		}
		object->pin[list.to - 1]->state = pin->state;
	}
}

void setStateByOutput(nts::Circuit *cir, nts::Component *object, size_t pinNb)
{
	nts::ComputePin computePin;

	std::string name = (object->getLink(pinNb))[0].name;
	size_t pinFrom = (object->getLink(pinNb))[0].from;
	nts::Component *from = cir->getByName(name);
	nts::PinOutput *pin;
	pin = static_cast<nts::PinOutput *>(from->pin[pinFrom - 1]);
	if (!pin->dependencies.empty()) {
		for (auto dependence = pin->dependencies.begin() ;
		dependence != pin->dependencies.end(); ++dependence) {
			setStateByInput(cir, from, (*dependence),
					pin->pinName, from->name);
		}
		pin->state = computePin.compute_pin(pin, from);
	}
	object->pin[pinNb - 1]->state = pin->state;
}
