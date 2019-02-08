#pragma once

#include <chrono>
#include <ctime>
#include <iostream>



class TimeUtilities {

public:

    static void printCurrentTime() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        //std::cout << std::ctime(&time) << "\n";
        char str[26];
        ctime_s(str, sizeof(str), &time);
        std::cout << str << "\n";
    }

    template<class F, class... Args>
    static long long measureTime(F&& func, Args&&... args) {

        auto start = std::chrono::high_resolution_clock::now();

        std::invoke(std::forward<decltype(func)>(func), std::forward<decltype(args)>(args)...);

        auto finish = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);

        std::cout << "Elapsed time: " << elapsed.count() << " microsec.\n";

        return elapsed.count();
    }
};
