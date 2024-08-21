#include "ft_money.hpp"

#include "offsets.hpp"
#include "globals.hpp"

#include <print>

void ft_money::tick()
{
	if (Globals::g_pAPI->write16(Offsets::domino_money, 60770))
		std::println("[+] Added money!");
	else
		std::println("[!] Failed to add money!");

	Sleep(420);

	this->disable();
}