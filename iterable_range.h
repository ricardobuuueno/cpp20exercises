#pragma once

namespace cpp20
{

	template <typename T>
	class seq {
		T start_{};
		T end_{};
	public:
		seq(T start, T end) : start_{ start }, end_{ end } {}

		class iterator {
			T value_{};
		public:
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
		};

		iterator begin() const {
			return iterator{ start_ };
		}
		iterator end() const {
			return iterator{ end_ };
		}
	};

}