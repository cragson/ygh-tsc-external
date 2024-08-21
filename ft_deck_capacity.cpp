#include "ft_deck_capacity.hpp"
#include "offsets.hpp"
#include "globals.hpp"

#include <print>

void ft_deck_capacity::tick()
{
	if (Globals::g_pAPI->write16(Offsets::deck_capacity, 9999) && Globals::g_pAPI->write16( Offsets::duelist_level, 9999) )
		std::println("[-] Increased deck capacity and duelist level!");
	else
		std::println("[!] Failed to increase stats!");

	Sleep(420);

	this->disable();
}
