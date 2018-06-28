//
// EPITECH PROJECT, 2018
// nano
// File description:
// tek
//

#ifndef TEKSPICE_HPP_
# define TEKSPICE_HPP_

#include "exception.hpp"
#include "Parser.hpp"
#include "Compute.hpp"
#include "Pin.hpp"
#include "Circuit.hpp"

//INCLUDES
int dump_circuit(nts::Circuit *circuit);
int dump_circuit(nts::Circuit *circuit, const std::string &type);
void setStateByInput(nts::Circuit *c, nts::Component *object, size_t pinNb);
void setStateByOutput(nts::Circuit *c, nts::Component *object, size_t pinNb);
int launch(nts::Circuit *circuit);
int my_commands(nts::Circuit *circuit, const std::string &str);
void default_commands(nts::Circuit *circuit);
int my_assignement(nts::Circuit *circuit, const std::string &str);
//DEFINES
#define ERROR 84
#define SUCCESS 0
#endif /* !TEKSPICE_HPP_ */
