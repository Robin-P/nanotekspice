//
// EPITECH PROJECT, 2018
// ex00
// File description:
// ex00
//

#ifndef CIRCUIT_HPP_
# define CIRCUIT_HPP_

#include <map>
#include <memory>
#include "IComponent.hpp"
#include "Component.hpp"

namespace nts {
class Circuit {
public:
	//Attributes
	static std::map<std::string, int (Circuit::*)(void)> commands;
	std::map<std::string, std::unique_ptr<nts::IComponent>> map;
	enum CircuitMode {
		PROMPT,
		LOOP
	};
	CircuitMode mode;

	//Construct && Destruct
	Circuit()
		{
		}

	~Circuit()
		{
		}

	//Functions
	static nts::Component *convert(std::unique_ptr<nts::IComponent> &object)
		{
			nts::Component *component = nullptr;

		        if (object)
				component = static_cast<nts::Component *>(object.get());
		        return component;
		}

	Component *getByName(const std::string &name_id);
	std::vector<Component *> getByType(const std::string &type_id);
	void add(const std::string &n, std::unique_ptr<nts::IComponent> &&c);
	int simulate(void);
	int display(void);
	int loop(void);
	int dump(void);
};
}
#endif /* !CIRCUIT_HPP_ */
