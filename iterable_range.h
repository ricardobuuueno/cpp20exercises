#pragma once

#include <format>
#include <iostream>

namespace cpp20
{

	template <typename T>
	requires std::forward_iterator<typename T::iterator>
	void print_forward_it(const T& c) {
		for (auto v : c) {
			std::cout << std::format("{} ", v);
		}
		std::cout << '\n';
	}

	template <typename T>
	class seq {
		T start_{};
		T end_{};
	public:
		seq(T start, T end) : start_{ start }, end_{ end } {}

		class iterator {
			T value_{};
		public:
			using iterator_concept = std::forward_iterator_tag;
			using iterator_category = std::forward_iterator_tag;
			using value_type = std::remove_cv_t<T>;
			using difference_type = std::ptrdiff_t;
			using pointer = const T*;
			using reference = const T&;

			explicit iterator(T position = 0) : value_{ position } {}
			T operator*() const {
				return value_;
			}
			iterator& operator++() {
				++value_;
				return *this;
			}
			bool operator!=(const iterator& other) const {
				return value_ != other.value_;
			}
			bool operator==(const iterator& other) const {
				return value_ == other.value_;
			}
		};

		iterator begin() const {
			return iterator{ start_ };
		}
		iterator end() const {
			return iterator{ end_ };
		}
	};

}