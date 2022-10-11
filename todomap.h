#pragma once

#include <map>
#include <string>
#include <format>
#include <iostream>

namespace cpp20
{

	using todomap = std::multimap<int, std::string>;

	void rprint(todomap& todo) {
		for (auto it = todo.rbegin(); it != todo.rend(); ++it) {
			std::cout << format("{}: {}\n", it->first, it->second);
		}
		std::cout << '\n';
	}

}