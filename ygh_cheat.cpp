#include "ygh_cheat.hpp"

#include "globals.hpp"
#include "utils.hpp"

#include "ft_enemy_lp.hpp"
#include "ft_money.hpp"
#include "ft_deck_capacity.hpp"
#include "ft_unlock_cards.hpp"

#include "offsets.hpp"

bool ygh_cheat::setup_offsets()
{
	return true;
}

bool ygh_cheat::setup_features()
{
	auto lp = std::make_unique< ft_enemy_lp >();
	lp->disable_drawing();
	lp->set_activation_delay(420);
	lp->set_virtual_key_code(VK_NUMPAD1);
	lp->set_print_status(false);
	lp->set_name(L"Set enemy lifepoints to One");

	auto money = std::make_unique< ft_money >();
	money->disable_drawing();
	money->set_activation_delay(420);
	money->set_virtual_key_code(VK_NUMPAD2);
	money->set_print_status(false);
	money->set_name(L"Get domino money");

	auto cap = std::make_unique< ft_deck_capacity >();
	cap->disable_drawing();
	cap->set_activation_delay(420);
	cap->set_virtual_key_code(VK_NUMPAD3);
	cap->set_print_status(false);
	cap->set_name(L"Increased stats");

	auto unl = std::make_unique< ft_unlock_cards >();
	unl->disable_drawing();
	unl->set_activation_delay(420);
	unl->set_virtual_key_code(VK_NUMPAD4);
	unl->set_print_status(false);
	unl->set_name(L"Unlock all cards");

	this->m_features.push_back(std::move(lp));
	this->m_features.push_back(std::move(money));
	this->m_features.push_back(std::move(cap));
	this->m_features.push_back(std::move(unl));

	return true;
}

void ygh_cheat::print_features()
{
	printf("\n");

	printf("Feature-Name -> Feature-Hotkey\n");

	for (const auto& feature : this->m_features)
		printf("[>] %-25ws -> %s\n", feature->get_name().c_str(),
			utils::virtual_key_as_string(feature->get_virtual_key_code()).c_str()
		);

	printf("\n");
}

void ygh_cheat::print_offsets()
{
	printf("\n");

	const auto msg = [](const std::string& name, const std::uintptr_t value)
		{
			printf("[>] %-35s -> 0x%08X\n", name.c_str(), value);
		};


	msg("Enemy Lifepoints", Offsets::enemy_life_points);
	msg("Domino Money", Offsets::domino_money);
	msg("Deck Capacity", Offsets::deck_capacity);
	msg("Duelist Level", Offsets::duelist_level);
	msg("Card Array", Offsets::card_array);

	printf("\n");
}

void ygh_cheat::run()
{
	for (const auto& feature : this->m_features)
	{
		// before tick'ing the feature, check first if the state will eventually change
		if (GetAsyncKeyState(feature->get_virtual_key_code()) & 0x8000)
			feature->toggle();

		// let the feature tick() when active
		if (feature->is_active())
			feature->tick();
	}
}

void ygh_cheat::shutdown()
{
	// disable every feature here
	for (const auto& feature : this->m_features)
		if (feature->is_active())
			feature->disable();
}