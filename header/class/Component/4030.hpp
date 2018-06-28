//
// EPITECH PROJECT, 2018
// ex00
// File description:
// ex00
//

#ifndef C_4030_HPP_
# define C_4030_HPP_

#include <vector>
#include <iostream>
#include "Component.hpp"
#include "Pin.hpp"

namespace nts {
	class C_4030 : public Component {
	public:
		//Construct && Destruct
		~C_4030()
			{
				size_t i = 0;

				if (!this->pin.empty()) {
					while (i < pin.size()) {
						delete pin[i];
						++i;
					}
				}
			}

		C_4030(const std::string &c_name)
				: Component(c_name, "4030", createPin(), 14)
			{
			}

		//functions
		std::vector<Pin *> createPin()
			{
				std::vector<Pin *> pin = {};

				pin.push_back(new PinInput(1));
				pin.push_back(new PinInput(2));
				pin.push_back(new PinOutput(3, {1, 2}, "xor")); // GATE
				pin.push_back(new PinOutput(4, {5, 6}, "xor")); // GATE
				pin.push_back(new PinInput(5));
				pin.push_back(new PinInput(6));
				pin.push_back(new PinOther(7)); // VSS
				pin.push_back(new PinInput(8));
				pin.push_back(new PinInput(9));
				pin.push_back(new PinOutput(10, {8, 9}, "xor")); // GATE
				pin.push_back(new PinOutput(11, {12, 13}, "xor")); // GATE
				pin.push_back(new PinInput(12));
				pin.push_back(new PinInput(13));
				pin.push_back(new PinOther(14));// VSS
				return pin;
			}
	};
}
#endif /* !C_4030_HPP_ */
