//
// EPITECH PROJECT, 2018
// mdr
// File description:
// mdr
//

#ifndef C_OUTPUT_HPP_
# define C_OUTPUT_HPP_

#include <vector>
#include <iostream>
#include "Component.hpp"
#include "Pin.hpp"

namespace nts {
	class C_Output : public Component {
	public:
		//Construct && Destruct
		~C_Output()
			{
				size_t i = 0;

				if (!this->pin.empty()) {
					while (i < pin.size()) {
						delete pin[i];
						++i;
					}
				}
			}

		C_Output(const std::string &c_name)
				: Component(c_name, "output", createPin(), 1)
			{
				this->pin[0]->state = nts::FALSE;
			}

		//functions
		std::vector<Pin *> createPin()
			{
				std::vector<Pin *> pin = {};

				pin.push_back(new PinInput(1));
				return pin;
			}
	};
}
#endif /* !C_OUTPUT_HPP_ */
