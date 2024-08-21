#pragma once
#include "mgba-api/mgba-api/mgba_api.hpp"
#include "ygh_cheat.hpp"

namespace Globals
{
	inline auto g_pCheat = std::make_unique< ygh_cheat >();

	inline auto g_pAPI = std::make_unique< mgba_api >();
}