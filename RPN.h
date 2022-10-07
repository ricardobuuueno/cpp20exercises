#pragma once

#include <deque>
#include <string>
#include <format>
#include <map>

namespace cpp20
{

	class RPN {
	public:
		std::pair<double, double> pop_get2() {
			if (deq_.size() < 2) {
				return { zero_, zero_ };
			}
			double v1{ deq_.front() };
			deq_.pop_front();
			double v2{ deq_.front() };
			deq_.pop_front();
			return { v2, v1 };
		}

		bool is_numeric(const std::string& s) {
			for (auto const& c : s) {
				if (c != '.' && !std::isdigit(c)) {
					return false;
				}
			}
			return true;
		}

		double optor(const std::string& op) {
			static std::map<std::string, double(*)(double, double)> opmap{
				{"+", [](double l, double r) { return l + r; }},
				{"-", [](double l, double r) { return l - r; }},
				{"*", [](double l, double r) { return l * r; }},
				{"/", [](double l, double r) { return l / r; }},
				{"^", [](double l, double r) { return std::pow(l, r); }},
				{"%", [](double l, double r) { return fmod(l, r); }}
			};
			if (opmap.find(op) == opmap.end()) {
				return zero_;
			}
			auto [l, r] = pop_get2();
			if (op == "/" && r == zero_) {
				deq_.push_front(inf_);
			}
			else {
				deq_.push_front(opmap.at(op)(l, r));
			}
			return deq_.front();
		}

		double op(const std::string& s) {
			if (is_numeric(s)) {
				double v{ std::stod(s, nullptr) };
				deq_.push_front(v);
				return v;
			}
			else {
				return optor(s);
			}
		}

		void clear() {
			deq_.clear();
		}

		std::string get_stack_string() const {
			std::string s{};
			for (auto const& v : deq_) {
				s += std::format("{} ", v);
			}
			return s;
		}

	private:
		std::deque<double> deq_{};
		constexpr static double zero_{ 0.0 };
		constexpr static double inf_{ std::numeric_limits<double>::infinity() };

	};

}