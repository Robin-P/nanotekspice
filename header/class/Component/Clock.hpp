//
// EPITECH PROJECT, 2018
// lol
// File description:
// lol
//

#ifndef C_CLOCK_HPP_
# define C_CLOCK_HPP_

#include <vector>
#include <iostream>
#include "Component.hpp"
#include "Pin.hpp"

namespace nts {
	class C_Clock : public Component {
	public:
		//Construct && Destruct
		~C_Clock()
			{
				size_t i = 0;

				if (!this->pin.empty()) {
					while (i < pin.size()) {
						delete pin[i];
						++i;
					}
				}
			}

		C_Clock(const std::string &c_name)
				: Component(c_name, "clock", createPin(), 1)
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
#endif /* !C_CLOCK_HPP_ */
