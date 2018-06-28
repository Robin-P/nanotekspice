//
// EPITECH PROJECT, 2018
// ex00
// File description:
// ex00
//

#include "Component.hpp"

void nts::Component::setLink(std::size_t pin, nts::IComponent &other,
			     std::size_t otherPin)
{
	nts::Component c_link = dynamic_cast<nts::Component &>(other);

	if ((this->pin.size() < pin - 1) || c_link.pin.size() < otherPin - 1)
		throw nts::LogicError("Index out of range");
	nts::Pin *from = this->pin[pin - 1];
	nts::Pin *to = c_link.pin[otherPin - 1];
	if (&c_link == this)
		throw nts::LogicError("You are linking yourself.");
	if (!(from->type == Pin::OUTPUT && to->type == Pin::INPUT))
		throw nts::LogicError("Incompatible plug, check the pin type.");
	nts::PinInput *input = static_cast<nts::PinInput *>(from);
	nts::PinOutput *output = static_cast<nts::PinOutput *>(to);
	if (output->list.size() != 0)
		throw nts::LogicError("Output already use by an other.");
	nts::link link_to = {pin, otherPin, this->name};
	nts::link link_from = {pin, otherPin, this->name};
	input->list.push_back(link_to);
	input->status = Pin::PLUGGED;
	output->list.push_back(link_from);
	output->status = Pin::PLUGGED;
}

std::vector<nts::link> nts::Component::getLink(std::size_t pinNb)
{
	std::vector<nts::link> vec;
	nts::Pin *res_pin = this->pin[pinNb - 1];

	if (res_pin)
		vec = res_pin->list;
	return vec;
}

void nts::Component::dump() const
{
	std::cout << "(name) " << this->name
		<< "\t(type) " << this->type
		<< "\t(nb pin) " << this->nbPin
		<< std::endl;
}

nts::Tristate nts::Component::getState(std::size_t pinNb)
{
	nts::Pin *pin = this->pin[pinNb - 1];

	return pin->state;
}

nts::Tristate nts::Component::compute(size_t pin)
{
	pin = pin;
	return nts::UNDEFINED;
}
