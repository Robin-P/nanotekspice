//
// EPITECH PROJECT, 2018
// ex00
// File description:
// ex00
//

#include "Compute.hpp"

std::map<std::string, nts::ComputePin::MEMBER_FUNCTION> nts::ComputePin::map =
{
	{"and", &nts::ComputePin::gate_and},
	{"nand", &nts::ComputePin::gate_nand},
	{"or", &nts::ComputePin::gate_or},
	{"nor", &nts::ComputePin::gate_nor},
	{"xor", &nts::ComputePin::gate_xor},
	{"xnor", &nts::ComputePin::gate_xnor},
	{"inverted", &nts::ComputePin::gate_inverted},
	{"sum", &nts::ComputePin::gate_sum},
	{"sum_carry", &nts::ComputePin::gate_sum_carry}
};
