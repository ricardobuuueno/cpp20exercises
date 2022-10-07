
#include "back_inserter.h"
#include "RPN.h"

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;
using namespace cpp20;


int main()
{
	RPN rpn;
	for (std::string o{}; std::cin >> o; ) {
		rpn.op(o);
		auto stack_str{ rpn.get_stack_string() };
		std::cout << std::format("{}: {}\n", o, stack_str);
	}
}

