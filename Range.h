#pragma once

#include <algorithm>
#include <initializer_list>
#include "RangeIterator.h"



template <class Type>
class Range {

public:

    Range(Type stop) 
        : Range(static_cast<Type>(0), stop) {
    }

    Range(Type start, Type stop, Type step = static_cast<Type>(1))
        : _start(start)
        , _stop(stop)
        , _step(step) {
    }

    virtual ~Range() = default;

    auto begin() const {
        return RangeIterator<Type>(_start, _step);
    }

    auto end() const {
        return RangeIterator<Type>(_stop, _step);
    }

    operator std::initializer_list<Type>() const {
        auto size = getSize();
        Type* arr = new Type[size];
        std::copy(begin(), end(), arr);
        return std::initializer_list<Type>(arr, arr + size);
    }

    size_t getSize() const {
        size_t size = 0;
        for (auto&& x : *this) {
            ++size;
        }
        return size;
    }


private:
    Type _start;
    Type _stop;
    Type _step;
};



typedef Range<size_t> irange;
