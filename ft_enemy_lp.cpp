#include "ft_enemy_lp.hpp"

#include "offsets.hpp"
#include "globals.hpp"

#include <print>

void ft_enemy_lp::tick()
{
	if (Globals::g_pAPI->write16(Offsets::enemy_life_points, 1))
		std::println("[-] Set enemy lifepoints to 1!");
	else
		std::println("[!] Failed to reduce enemy lifepoints!");

	Sleep(420);

	this->disable();
}