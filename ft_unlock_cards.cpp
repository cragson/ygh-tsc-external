#include "ft_unlock_cards.hpp"
#include "offsets.hpp"
#include "globals.hpp"

#include <print>

void ft_unlock_cards::tick()
{
	std::print("[#] Unlocking and adding cards..");

	for (uint16_t idx = 0; idx < 901; idx += 4)
		if (!Globals::g_pAPI->write32(Offsets::card_array + idx, 0xffffffffff))
			std::println("[!] Failed to unlock card with nr: {}", idx);

	std::print("done!\n");

	Sleep(420);

	this->disable();
}
