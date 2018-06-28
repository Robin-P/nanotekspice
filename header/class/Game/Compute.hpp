//
// EPITECH PROJECT, 2018
// ex00
// File description:
// ex00
//

#ifndef COMPUTE_HPP_
# define COMPUTE_HPP_

#include "Circuit.hpp"

namespace nts {
class ComputePin {
public:
	ComputePin()
		{
		}

	~ComputePin()
		{
		}

	static Tristate gate_inverted(PinOutput *pin,
				      Component *object)
		{
			Tristate a = object->getState(pin->dependencies[0]);

			if (a == nts::UNDEFINED)
				return nts::UNDEFINED;
			return a == nts::TRUE ? nts::FALSE : nts::TRUE;
		}


	static Tristate gate_and(PinOutput *pin, Component *object)
		{
			Tristate a = object->getState(pin->dependencies[0]);
			Tristate b = object->getState(pin->dependencies[1]);

			if ((a == nts::UNDEFINED && b == nts::UNDEFINED) ||
			    (a == nts::UNDEFINED && b == nts::TRUE) ||
			    (b == nts::UNDEFINED && a == nts::TRUE))
				return nts::UNDEFINED;
			if (a == nts::TRUE && b == nts::TRUE) {
				return nts::TRUE;
			}
			return nts::FALSE;
		}

	static Tristate gate_nand(PinOutput *pin, Component *object)
		{
			Tristate a = object->getState(pin->dependencies[0]);
			Tristate b = object->getState(pin->dependencies[1]);

			if ((a == nts::UNDEFINED && b == nts::UNDEFINED) ||
			    (a == nts::UNDEFINED && b == nts::TRUE) ||
			    (b == nts::UNDEFINED && a == nts::TRUE))
				return nts::UNDEFINED;
			if (a == nts::TRUE && b == nts::TRUE) {
				return nts::FALSE;
			}
			return nts::TRUE;
		}

	static Tristate gate_or(PinOutput *pin, Component *object)
		{
			Tristate a = object->getState(pin->dependencies[0]);
			Tristate b = object->getState(pin->dependencies[1]);

			if ((a == nts::UNDEFINED && b == nts::UNDEFINED) ||
			    (a == nts::UNDEFINED && b == nts::FALSE) ||
			    (b == nts::UNDEFINED && a == nts::FALSE))
				return nts::UNDEFINED;
			if (a == nts::TRUE || b == nts::TRUE)
				return nts::TRUE;
			return nts::FALSE;
		}

	static Tristate gate_nor(PinOutput *pin, Component *object)
		{
			Tristate a = object->getState(pin->dependencies[0]);
			Tristate b = object->getState(pin->dependencies[1]);

			if ((a == nts::UNDEFINED && b == nts::UNDEFINED) ||
			    (a == nts::UNDEFINED && b == nts::FALSE) ||
			    (b == nts::UNDEFINED && a == nts::FALSE))
				return nts::UNDEFINED;
			if (a == nts::TRUE || b == nts::TRUE)
				return nts::FALSE;
			return nts::TRUE;
		}

	static Tristate gate_xnor(PinOutput *pin, Component *object)
		{
			Tristate a = object->getState(pin->dependencies[0]);
			Tristate b = object->getState(pin->dependencies[1]);

			if (a == nts::UNDEFINED || b == nts::UNDEFINED)
				return nts::UNDEFINED;
			if ((a == nts::TRUE && b == nts::FALSE) ||
			    (a == nts::FALSE && b == nts::TRUE))
				return nts::FALSE;
			return nts::TRUE;
		}

	static Tristate gate_xor(PinOutput *pin, Component *object)
		{
			Tristate a = object->getState(pin->dependencies[0]);
			Tristate b = object->getState(pin->dependencies[1]);

			if (a == nts::UNDEFINED || b == nts::UNDEFINED)
				return nts::UNDEFINED;
			if ((a == nts::TRUE && b == nts::FALSE) ||
			    (a == nts::FALSE && b == nts::TRUE))
				return nts::TRUE;
			return nts::FALSE;
		}

	static Tristate gate_sum(PinOutput *pin, Component *object)
		{
			Tristate a = object->getState(pin->dependencies[0]);
			Tristate b = object->getState(pin->dependencies[1]);
			int carry_sum = 0;
			int sum = a + b;

			for (size_t i = 3; i < pin->dependencies.size(); ++i) {
				carry_sum += object->pin[pin->dependencies[i] - 1]->state;
			}
			sum += carry_sum;
			if (sum >= 2) {
				object->pin[pin->dependencies[2] - 1]->state = nts::TRUE;
				return nts::TRUE;
			}
			return static_cast<Tristate>(sum);
		}

	static Tristate gate_sum_carry(PinOutput *pin, Component *object)
		{
			int sum = 0;

			for (auto carry = pin->dependencies.begin();
			     carry != pin->dependencies.end(); ++carry) {
				sum += static_cast<int>(object->pin[*carry - 1]->state);
			}
			return sum >= 1 ? nts::TRUE : nts::FALSE;
		}

	//USING FOR STATIC FUNCTION PTR
	using MEMBER_FUNCTION = Tristate (*)(PinOutput *pin, Component *object);

	//ATTRIBUTES
	static std::map<std::string, MEMBER_FUNCTION> map;

	static Tristate compute_pin(PinOutput *pin, Component *object)
		{
			if (pin && !pin->gate.empty()) {
				return (ComputePin::map[pin->gate])(pin, object);
			}
			return pin ? pin->state : nts::UNDEFINED;
		}
	};
}
#endif /* !COMPUTE_HPP_ */
