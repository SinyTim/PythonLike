#pragma once

#include "EnumerateIterator.h"



template<
    class Iterable, 
    class IterType = decltype(std::begin(std::declval<Iterable>()))
>
class Enumerate {

public:

    Enumerate(const Iterable& iterable) 
        : _iterable(iterable) {
    }

    virtual ~Enumerate() = default;

    auto begin() const {
        return EnumerateIterator<IterType>(std::begin(_iterable));
    }

    auto end() const {
        return EnumerateIterator<IterType>(std::end(_iterable));
    }


private:
    const Iterable& _iterable;
};
