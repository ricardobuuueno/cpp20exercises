
#include "back_inserter.h"
#include "RPN.h"
#include "word_frequency_counter.h"
#include "long_sentence.h"

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;
using namespace cpp20;


int main()
{
	vector<vector<string>> vv_senteces{ vector<string>{} };

	for (string s{}; cin >> s;) {
		vv_senteces.back().emplace_back(s);
		if (is_eos(s)) {
			vv_senteces.emplace_back(vector<string>{});
		}
	}

	if (vv_senteces.back().empty()) {
		vv_senteces.pop_back();
	}

	std::ranges::sort(vv_senteces, [](const auto& l, const auto& r) { return l.size() > r.size(); });

	constexpr int WLIMIT{ 10 };
	for (auto& v : vv_senteces) {
		size_t size = v.size();
		size_t limit{ WLIMIT };
		cout << format("{}: ", size);
		for (auto& s : v) {
			cout << format("{} ", s);
			if (--limit == 0) {
				if (size > WLIMIT) {
					cout << "...";
				}
				break;
			}
		}
		cout << '\n';
	}
}

//git init
//git add - A
//git commit - m 'Added my project'
//git remote add origin git@github.com:sammy / my - new - project.git
//git push - u - f origin main