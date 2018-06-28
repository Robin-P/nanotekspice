//
// EPITECH PROJECT, 2018
// waw
// File description:
// waw
//

#ifndef C_FALSE_HPP_
# define C_FALSE_HPP_

#include <vector>
#include <iostream>
#include "Component.hpp"
#include "Pin.hpp"

namespace nts {
	class C_False : public Component {
	public:
		//Construct && Destruct
		~C_False()
			{
				size_t i = 0;

				if (!this->pin.empty()) {
					while (i < pin.size()) {
						delete pin[i];
						++i;
					}
				}
			}

		C_False(const std::string &c_name)
				: Component(c_name, "false", createPin(), 1)
			{
				this->pin[0]->state = nts::FALSE;
			}

		//functions
		std::vector<Pin *> createPin()
			{
				std::vector<Pin *> pin = {};

				pin.push_back(new PinOutput(1, {}, ""));
				return pin;
			}
	};
}
#endif /* !C_FALSE_HPP_ */
