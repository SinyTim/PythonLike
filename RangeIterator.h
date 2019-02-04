#pragma once

#include <iterator>



template <class Type>
class RangeIterator {

public:

    typedef std::input_iterator_tag   iterator_category;
    typedef Type                      value_type;
    typedef std::ptrdiff_t            difference_type;
    typedef Type*                     pointer; 
    typedef Type&                     reference;
    
    RangeIterator(Type i = static_cast<Type>(0), 
                  Type step = static_cast<Type>(1))
        : _i(i)
        , _step(step) {
    }

    RangeIterator(const RangeIterator<Type>& other)
        : _i(other._i)
        , _step(other._step) {
    }

    virtual ~RangeIterator() = default;

    RangeIterator<Type>& operator=(const RangeIterator<Type>& other) {
        _i = other._i;
        _step = other._step;
        return *this;
    }

    bool operator==(const RangeIterator<Type>& other) const {
        return (_step >= static_cast<Type>(0)) 
            ? (_i >= other._i) 
            : (_i <= other._i);
    }

    bool operator!=(const RangeIterator<Type>& other) const {
        return !(*this == other);
    }

    Type operator*() const {
        return _i;
    }

    RangeIterator<Type>& operator++() {
        _i += _step;
        return *this;
    }

    RangeIterator<Type> operator++(int) {
        auto thisCopy = *this;
        ++(*this);
        return thisCopy;
    }


private:
    Type _i;
    Type _step;
};
