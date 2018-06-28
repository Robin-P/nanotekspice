//
// EPITECH PROJECT, 2018
// mdr
// File description:
// mdr
//

#ifndef C_INPUT_HPP_
# define C_INPUT_HPP_

#include <vector>
#include <iostream>
#include "Component.hpp"
#include "Pin.hpp"

namespace nts {
	class C_Input : public Component {
	public:
		//Construct && Destruct
		~C_Input()
			{
				size_t i = 0;

				if (!this->pin.empty()) {
					while (i < pin.size()) {
						delete pin[i];
						++i;
					}
				}
			}

		C_Input(const std::string &c_name)
				: Component(c_name, "input", createPin(), 1)
			{
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
#endif /* !C_INPUT_HPP_ */
