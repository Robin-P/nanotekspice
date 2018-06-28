//
// EPITECH PROJECT, 2018
// ex00
// File description:
// ex00
//

#ifndef C_4069_HPP_
# define C_4069_HPP_

#include <vector>
#include <iostream>
#include "Component.hpp"
#include "Pin.hpp"

namespace nts {
	class C_4069 : public Component {
	public:
		//Construct && Destruct
		~C_4069()
			{
				size_t i = 0;

				if (!this->pin.empty()) {
					while (i < pin.size()) {
						delete pin[i];
						++i;
					}
				}
			}

		C_4069(const std::string &c_name)
				: Component(c_name, "4069", createPin(), 14)
			{
			}

		//functions
		std::vector<Pin *> createPin()
			{
				std::vector<Pin *> pin = {};

				pin.push_back(new PinInput(1));
				pin.push_back(new PinOutput(2, {1}, "inverted")); //FATE
				pin.push_back(new PinInput(3));
				pin.push_back(new PinOutput(4, {3}, "inverted")); // GATE
				pin.push_back(new PinInput(5));
				pin.push_back(new PinOutput(6, {5}, "inverted")); // GATE
				pin.push_back(new PinOther(7)); // VSS
				pin.push_back(new PinOutput(8, {9}, "inverted"));
				pin.push_back(new PinInput(9));
				pin.push_back(new PinOutput(10, {11}, "inverted"));
				pin.push_back(new PinInput(11));
				pin.push_back(new PinOutput(12, {13}, "inverted"));
				pin.push_back(new PinInput(13));
				pin.push_back(new PinOther(14)); // VSS
				return pin;
			}
	};
}
#endif /* !C_4069_HPP_ */
