//
// EPITECH PROJECT, 2018
// ptdr
// File description:
// ptdr
//

#ifndef C_TRUE_HPP_
# define C_TRUE_HPP_

#include <vector>
#include <iostream>
#include "Component.hpp"
#include "Pin.hpp"

namespace nts {
	class C_True : public Component {
	public:
		//Construct && Destruct
		~C_True()
			{
				size_t i = 0;

				if (!this->pin.empty()) {
					while (i < pin.size()) {
						delete pin[i];
						++i;
					}
				}
			}

		C_True(const std::string &c_name)
				: Component(c_name, "true", createPin(), 1)
			{
				this->pin[0]->state = nts::TRUE;
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
#endif /* !C_TRUE_HPP_ */
