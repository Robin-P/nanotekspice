//
// EPITECH PROJECT, 2018
// ex00
// File description:
// ex00
//

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <map>
#include <memory>
//Unique Component
#include "Input.hpp"
#include "Output.hpp"
#include "False.hpp"
#include "Clock.hpp"
#include "True.hpp"
#include "4001.hpp"
#include "4008.hpp"
#include "4011.hpp"
#include "4030.hpp"
#include "4069.hpp"
#include "4071.hpp"
#include "4081.hpp"
//Generic Component
#include "IComponent.hpp"

namespace nts {
class Factory {
public:
	// TYPEDEF && USING
	using MEMBER_FUNCTION = std::unique_ptr<nts::IComponent>
		(Factory::*)(const std::string &value) const noexcept;
	// ATTRIBUTES
	std::map<const std::string, MEMBER_FUNCTION> map;

	//CONSTRUCT && DESTRUCT
	Factory()
		{
			this->map["4081"] = &Factory::create4081;
			this->map["4071"] = &Factory::create4071;
			this->map["4069"] = &Factory::create4069;
			this->map["4030"] = &Factory::create4030;
			this->map["4011"] = &Factory::create4011;
			//	this->map["4008"] = &Factory::create4008;
			this->map["4001"] = &Factory::create4001;
			this->map["input"] = &Factory::createInput;
			this->map["output"] = &Factory::createOutput;
			this->map["true"] = &Factory::createTrue;
			this->map["false"] = &Factory::createFalse;
			this->map["clock"] = &Factory::createClock;
		}

	~Factory()
		{
		}

		//FUNCTIONS
	std::unique_ptr<nts::IComponent> createComponent(const std::string &type,
							 const std::string &value)
		{
			auto ptr = this->map[type];
			std::unique_ptr<nts::IComponent> component;

			if (ptr)
				component = (this->*ptr)(value);
			return component;
		}

private:
	std::unique_ptr<nts::IComponent> create4001(const std::string &value)
		const noexcept
		{
			return std::make_unique<C_4001>(value);
		}

	std::unique_ptr<nts::IComponent> create4008(const std::string &value)
		const noexcept
		{
			return std::make_unique<C_4008>(value);
		}

	std::unique_ptr<nts::IComponent> create4011(const std::string &value)
		const noexcept
		{
			return std::make_unique<C_4011>(value);
		}

	std::unique_ptr<nts::IComponent> create4030(const std::string &value)
		const noexcept
		{
			return std::make_unique<C_4030>(value);
		}

	std::unique_ptr<nts::IComponent> create4069(const std::string &value)
		const noexcept
		{
			return std::make_unique<C_4069>(value);
		}

	std::unique_ptr<nts::IComponent> create4071(const std::string &value)
		const noexcept
		{
			return std::make_unique<C_4071>(value);
		}

	std::unique_ptr<nts::IComponent> create4081(const std::string &value)
		const noexcept
		{
			return std::make_unique<C_4081>(value);
		}

	std::unique_ptr<nts::IComponent> createInput(const std::string &value)
		const noexcept
		{
			return std::make_unique<C_Input>(value);
		}

	std::unique_ptr<nts::IComponent> createOutput(const std::string &value)
		const noexcept
		{
			return std::make_unique<C_Output>(value);
		}

	std::unique_ptr<nts::IComponent> createTrue(const std::string &value)
		const noexcept
		{
			return std::make_unique<C_True>(value);
		}

	std::unique_ptr<nts::IComponent> createFalse(const std::string &value)
		const noexcept
		{
			return std::make_unique<C_False>(value);
		}

	std::unique_ptr<nts::IComponent> createClock(const std::string &value)
		const noexcept
		{
			return std::make_unique<C_Clock>(value);
		}
	};
}
#endif /* !FACTORY_HPP_*/
