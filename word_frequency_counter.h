#pragma once

#include <ranges>
#include <regex>

namespace cpp20 {

	namespace ranges = std::ranges;
	namespace regex_constants = std::regex_constants;

	constexpr const char* re{ "(\\w+)" };

}