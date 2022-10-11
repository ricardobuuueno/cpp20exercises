
#include "back_inserter.h"
#include "RPN.h"
#include "word_frequency_counter.h"
#include "long_sentence.h"
#include "todomap.h"

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;
using namespace cpp20;


int main()
{
	todomap todo{
		{1, "wash dishes"},
		{0, "watch teevee"},
		{2, "do homework"},
		{0, "read comics"}
	};
	rprint(todo);
}

//git init
//git add - A
//git commit - m 'Added my project'
//git remote add origin git@github.com:sammy / my - new - project.git
//git push - u - f origin main