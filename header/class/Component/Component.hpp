//
// EPITECH PROJECT, 2018
// ex00
// File description:
// ex00
//

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <list>
#include "IComponent.hpp"
#include "Pin.hpp"
#include "exception.hpp"

namespace nts {
	class Component : public nts::IComponent {
	public:
		//Construct && Destruct
		~Component()
		{
		}

		Component(const std::string &c_name, std::string c_type,
			  std::vector<Pin *> c_pin, std::size_t c_nbPin)
			{
				this->name = c_name;
				this->type = c_type;
				this->pin = c_pin;
				this->nbPin = c_nbPin;
			}

		//Functions
		void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
		//GetLink take a pin and return a vector that contain all Component linked
		std::vector<link> getLink(std::size_t pinNb);
		virtual void dump() const; // Can be overloaded in Component\'s subclass
		nts::Tristate getState(std::size_t pinNb);
		nts::Tristate compute(size_t pin);

		///Attributes
		std::string name;
		std::string type;
		size_t nbPin;
		std::vector<Pin *> pin;
	};
}
#endif /* !COMPONENT_HPP_ */
