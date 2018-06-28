//
// EPITECH PROJECT, 2018
// ex00
// File description:
// ex00
//

#ifndef C_4008_HPP_
# define C_4008_HPP_

#include <vector>
#include <iostream>
#include "Component.hpp"
#include "Pin.hpp"

namespace nts {
	class C_4008 : public Component {
	public:
		//Construct && Destruct
		~C_4008()
			{
				size_t i = 0;

				if (!this->pin.empty()) {
					while (i < pin.size()) {
						delete pin[i];
						++i;
					}
				}
			}

		C_4008(const std::string &c_name)
				: Component(c_name, "4008", createPin(), 20)
			{
				this->pin[8]->state = nts::FALSE; // NB 9
				this->pin[16]->state = nts::FALSE; // NB 17
				this->pin[17]->state = nts::FALSE; // NB 18
				this->pin[18]->state = nts::FALSE; // NB 19
			}

		//functions
		std::vector<Pin *> createPin()
			{
				std::vector<Pin *> pin = {};
				//NORMALS
				pin.push_back(new PinInput(1));
				pin.push_back(new PinInput(2));
				pin.push_back(new PinInput(3));
				pin.push_back(new PinInput(4));
				pin.push_back(new PinInput(5));
				pin.push_back(new PinInput(6));
				pin.push_back(new PinInput(7));
				pin.push_back(new PinOther(8));//VSS
				pin.push_back(new PinOutput(9, {}, ""));
				//SUM GATE: SOURCE1 SOURCE1 CARRYTARGET CARRYSOURCE
				pin.push_back(new PinOutput(10, {6, 7, 17, 9}, "sum"));// GATE
				pin.push_back(new PinOutput(11, {4, 5, 18, 9, 17}, "sum"));// GATE
				pin.push_back(new PinOutput(12, {2, 3, 19, 9, 17, 18}, "sum"));// GATE
				pin.push_back(new PinOutput(13, {1, 15, 14, 9, 17, 18, 19}, "sum"));// GATE
				pin.push_back(new PinOutput(14, {9, 17, 18, 19}, "sum_carry"));// GATE
				pin.push_back(new PinInput(15));
				pin.push_back(new PinOther(16));// VSS
				//CARRIES
				pin.push_back(new PinOutput(17, {}, ""));// C2
				pin.push_back(new PinOutput(18, {}, ""));// C3
				pin.push_back(new PinOutput(19, {}, ""));// C4
				return pin;
			}
	};
}
#endif /* !C_4008_HPP_ */
