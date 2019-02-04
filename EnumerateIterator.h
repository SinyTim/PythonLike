#pragma once

#include <iterator>
#include <tuple>



template <
    class IterType, 
    class Type = typename std::iterator_traits<IterType>::reference
>
class EnumerateIterator {

public:

    EnumerateIterator(const IterType& iter, size_t i = 0)
        : _iter(iter)
        , _i(i) {
    };

    EnumerateIterator(const EnumerateIterator<IterType>& other)
        : _iter(other._iter)
        , _i(other._i) {
    };

    virtual ~EnumerateIterator() = default;

    EnumerateIterator<IterType>& operator=(const EnumerateIterator<IterType>& other) {
        _iter = other._iter;
        _i = other._i;
        return *this;
    }

    bool operator==(const EnumerateIterator<IterType>& other) const {
        return (_iter == other._iter);
    }

    bool operator!=(const EnumerateIterator<IterType>& other) const {
        return !(*this == other);
    }

    std::tuple<size_t, Type> operator*() const {
        return std::tie(_i, *_iter);
    }

    EnumerateIterator<IterType>& operator++() {
        ++_iter;
        ++_i;
        return *this;
    }

    EnumerateIterator<IterType> operator++(int) {
        auto thisCopy = *this;
        ++(*this);
        return thisCopy;
    }


private:
    IterType _iter;
    size_t _i;
};
