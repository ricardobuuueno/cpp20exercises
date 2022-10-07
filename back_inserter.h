#pragma once

#include <string>

namespace cpp20
{
    template <typename T, typename U>
    void copy(T* first, T* last, U* out) {
        for (; first != last; ++first) {
            *out++ = *first;
        }
    }

    template <typename InputIt, typename OutputIt>
    void copy(InputIt first, InputIt last, OutputIt out) {
        for (; first != last; ++first) {
            *out++ = *first;
        }
    }

    template <typename C>
    class back_inserter {
        C* cont_;

    public:
        back_inserter(C& c) : cont_(&c) {}

        auto operator*() -> back_inserter& { return *this; }
        auto operator++() -> back_inserter& { return *this; }
        auto operator++(int) -> back_inserter { return *this; }

        auto operator=(typename C::value_type const& val) -> back_inserter& {
            cont_->push_back(val);
            return *this;
        }

    };

    struct Person {
        std::string first;
        std::string last;
    };

}