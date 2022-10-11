#pragma once

#include <string_view>

namespace cpp20
{
	
	bool is_eos(const std::string_view& str) {
		constexpr const char* end_punct{ ".!?" };
		for (auto c : str) {
			if (strchr(end_punct, c) != nullptr) {
				return true;
			}
		}
		return false;
	}

}