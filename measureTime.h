#pragma once

#include <chrono>
#include <utility>


using namespace std::chrono;


template<class F, class... Args>
static long long measureTime(F&& func, Args&&... args) {

    auto start = high_resolution_clock::now();

    //func(args...);
    //std::forward<F>(func)(std::forward<Args>(args)...);
    //std::forward<decltype(func)>(func)(std::forward<decltype(args)>(args)...);
    std::invoke(std::forward<decltype(func)>(func), std::forward<decltype(args)>(args)...);

    auto finish = high_resolution_clock::now();
    auto elapsed = duration_cast<microseconds>(finish - start);

    std::cout << "Elapsed time: " << elapsed.count() << " microsec.\n";

    return elapsed.count();
}

/*#define measureTime(func) { \
    using clock = std::chrono::high_resolution_clock; \
    auto start = clock::now(); \
    func; \
    auto finish = clock::now(); \
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(finish - start); \
    std::cout << "Elapsed time: " << elapsed.count() << " microsec.\n"; \
}*/

/*static auto measureTime = [](auto&& func, auto&&... params) {
    auto start = high_resolution_clock::now();
    std::forward<decltype(func)>(func)(std::forward<decltype(params)>(params)...);
    auto finish = high_resolution_clock::now();
    auto elapsed = duration_cast<microseconds>(finish - start);
    std::cout << "Elapsed time: " << elapsed.count() << " microsec.\n";
};*/
