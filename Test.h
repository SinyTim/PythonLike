#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "Range.h"
#include "Enumerate.h"
#include "measureTime.h"



class Test {

public:

    static void run() {

        testRange();

        std::cout << "\n\n";

        testEnumerate();
    }

private:

    static void testRange() {

        std::cout << "Test Range:\n";

        for (auto i : irange(18)) {
            std::cout << i << " ";
        }

        std::cout << "\n";

        auto r = Range<int>(10, 0, -1);
        std::copy(r.begin(), r.end(), std::ostream_iterator<int>(std::cout, " "));

        std::cout << "\n";

        testRangeTime();
    }

    static void testRangeTime() {

        std::vector<int> v;

        auto t1 = measureTime([&v]() {
            for (size_t i = 0; i < 10'000'000ll; ++i) {
                v.push_back(17);
            }
        });

        v.clear();

        auto t2 = measureTime([&v]() {
            for (auto i : irange(10'000'000ll)) {
                v.push_back(17);
            }
        });

        std::cout << "Ratio: " << static_cast<double>(t2) / static_cast<double>(t1) << "\n";
        // ~1 -> equal time.
    }

    static void testEnumerate() {

        std::cout << "Test Enumerate:\n";

        std::vector<char> v(Range<char>('A', 'I'));

        for (auto[i, x] : Enumerate(v)) {
            std::cout << i << ": " << x << "\n";
        }
    }
};
