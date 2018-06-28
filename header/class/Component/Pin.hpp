//
// EPITECH PROJECT, 2018
// eXOO
// File description:
// eXOO
//


#ifndef PIN_HPP_
# define PIN_HPP_

#include <vector>
#include "IComponent.hpp"

namespace nts {
	typedef struct s_link {
		size_t from;
		size_t to;
		std::string name;
	} link;

	class Pin {
	public:
		//Enum
		enum PinType {
			INPUT,
			OUTPUT,
			UNDEFINED
		};
		enum PinStatus {
			PLUGGED,
			UNPLUGGED
		};
		//Attributes
		std::vector<link> list;
		size_t pinName;
		PinType type;
		PinStatus status;
		nts::Tristate state;
	};

	class PinInput : public Pin {
	public:
		//Construct && Destruct
		PinInput(const size_t nb)
			{
				this->type = Pin::INPUT;
				this->pinName = nb;
				this->status = Pin::UNPLUGGED;
				this->state = nts::Tristate::UNDEFINED;
				this->list = {};
			}

		~PinInput()
			{
			}
	};

	class PinOutput : public Pin {
	public:
		//Construct && Destruct
		PinOutput(const size_t nb, std::vector<std::size_t> p_dependencies, const std::string &p_gate)
			{
				this->type = Pin::OUTPUT;
				this->pinName = nb;
				this->status = Pin::UNPLUGGED;
				this->state = nts::Tristate::UNDEFINED;
				this->list = {};
				this->dependencies = p_dependencies;
				this->gate = p_gate;
			}

		~PinOutput()
			{
			}

		//Attributes
		std::vector<std::size_t> dependencies;
		std::string gate;
	};

	class PinOther : public Pin {
	public:
		PinOther(const size_t nb)
			{
				this->type = Pin::UNDEFINED;
				this->pinName = nb;
				this->status = Pin::UNPLUGGED;
				this->state = nts::Tristate::UNDEFINED;
			}

		~PinOther()
			{
			}
	};
}
#endif /*!PIN_HPP_*/
