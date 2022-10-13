
#include "back_inserter.h"
#include "RPN.h"
#include "word_frequency_counter.h"
#include "long_sentence.h"
#include "todomap.h"
#include "iterable_range.h"
#include "fibonacci.h"

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;
using namespace cpp20;

void printc(const auto& v, const string_view s = "") {
	if (s.size()) {
		cout << format("{}: \n", s);
	}
	for (auto e : v) {
		cout << format("{} ", e);
	}
	cout << '\n';
}


int main()
{
	fib_generator fib(10);
	printc(fib, "Fibonacci");

	auto x = ranges::views::transform(fib, [](unsigned long x) { return x * x; });
	printc(x, "Squared");

}

//git init
//git add - A
//git commit - m 'Added my project'
//git remote add origin git@github.com:sammy / my - new - project.git
//git push - u - f origin main