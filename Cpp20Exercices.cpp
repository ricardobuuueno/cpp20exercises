
#include "back_inserter.h"
#include "RPN.h"
#include "word_frequency_counter.h"

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;
using namespace cpp20;


int main()
{
	std::map<std::string, int> wordmap{};
	std::vector<std::pair<std::string, int>> wordvec{};
	std::regex word_re{ re };
	size_t total_words{};

	for (std::string s{}; std::cin >> s; ) {
		auto words_begin{ sregex_iterator(s.begin(), s.end(), word_re) };
		auto words_end{ sregex_iterator() };

		for (auto r_it{ words_begin }; r_it != words_end; ++r_it) {
			smatch match{ *r_it };
			auto word_str{ match.str() };
			ranges::transform(word_str, word_str.begin(), [](unsigned char c) { return std::tolower(c); });
			auto [map_it, result] = wordmap.try_emplace(word_str, 0);
			auto& [w, count] = *map_it;
			++total_words;
			++count;
		}
	}

	auto unique_words = wordmap.size();
	wordvec.reserve(unique_words);
	ranges::move(wordmap, std::back_inserter(wordvec));
	ranges::sort(wordvec, [](const auto& a, const auto& b) {
								if (a.second != b.second) {
									return (a.second > b.second);
								}
								return (a.first < b.first);
							});
	std::cout << std::format("total word count: {}\n", total_words);
	std::cout << std::format("unique word count: {}\n", unique_words);

	for (int limit{ 20 }; auto & [w, count] : wordvec) {
		std::cout << std::format("{}: {}\n", count, w);
		if (--limit == 0) {
			break;
		}
	}
}

//git init
//git add - A
//git commit - m 'Added my project'
//git remote add origin git@github.com:sammy / my - new - project.git
//git push - u - f origin main