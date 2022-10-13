#pragma once

namespace cpp20
{

	class fib_generator {
	
		using fib_t = unsigned long;
		fib_t stop_{};
		fib_t count_{ 0 };
		fib_t a_{ 0 };
		fib_t b_{ 1 };

		constexpr void do_fib() {
			const fib_t old_b = b_;
			b_ += a_;
			a_ = old_b;
		}

	public:
		using iterator_concept = std::forward_iterator_tag;
		using iterator_category = std::forward_iterator_tag;
		using value_type = std::remove_cv_t<fib_t>;
		using difference_type = std::ptrdiff_t;
		using pointer = const fib_t*;
		using reference = const fib_t&;

		explicit fib_generator(fib_t stop = 0) : stop_{ stop } {}

		fib_t operator*() const {
			return b_;
		}

		constexpr fib_generator& operator++() {
			do_fib();
			++count_;
			return *this;
		}

		fib_generator operator++(int) {
			auto temp{ *this };
			++*this;
			return temp;
		}

		bool operator!=(const fib_generator& o) const {
			return count_ != o.count_;
		}

		bool operator==(const fib_generator& o) const {
			return count_ == o.count_;
		}

		const fib_generator& begin() const {
			return *this;
		}

		const fib_generator end() const {
			auto sentinel = fib_generator();
			sentinel.count_ = stop_;
			return sentinel;
		}

		fib_t size() {
			return stop_;
		}

	};

}