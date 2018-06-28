//
// EPITECH PROJECT, 2018
// ex00
// File description:
// eX00
//

#include <signal.h>
#include <unistd.h>
#include <algorithm>
#include "Parser.hpp"
#include "tekspice.hpp"

nts::Tristate g_break = nts::FALSE;

void my_handler(int s)
{
	(void) s;
	g_break = nts::TRUE;
}

int signal()
{
	struct sigaction sigIntHandler;

	sigIntHandler.sa_handler = my_handler;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT, &sigIntHandler, NULL);
	return 0;
}

void setup(nts::Circuit *circuit)
{
	signal();
	circuit->mode = nts::Circuit::PROMPT;
	circuit->simulate();
	dump_circuit(circuit, "output");
	std::cout << "> ";
}

int launch(nts::Circuit *circuit)
{
	std::string str;

	setup(circuit);
	while ((circuit->mode == nts::Circuit::LOOP)
	|| (std::cin >> str && str != "exit")) {
		if (str.find('=') != (size_t) -1) {
			if (my_assignement(circuit, str) == ERROR)
				return ERROR;
		} else {
			if (my_commands(circuit, str) == ERROR)
				return ERROR;
		}
		if (g_break == nts::TRUE) {
			circuit->mode = nts::Circuit::PROMPT;
			g_break = nts::FALSE;
		}
		if (circuit->mode == nts::Circuit::LOOP) {
			sleep(1);
			circuit->simulate();
		} else
			std::cout << "> ";
	}
	return 0;
}
