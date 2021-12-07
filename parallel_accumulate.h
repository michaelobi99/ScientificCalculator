#ifndef PARALLEL_ACCUMULATE_H
#define PARALLEL_ACCUMULATE_H

#include <numeric>
#include <future>
#include <functional>
namespace stl {
    template <typename Iterator , typename T>
    T parallel_accumulate(Iterator first, Iterator last, T init_value, std::function<T(T, T)> func = [](T a, T b) {return a + b; }) {
        std::uint64_t const length = std::distance(first, last);
        std::uint64_t max_chunk_size = 50;
        if (length <= max_chunk_size)
            return std::accumulate(first, last, init_value, func);
        else {
            Iterator midPoint = first;
            std::advance(midPoint, length / 2);
            std::future<T> firstHalfResult = std::async(parallel_accumulate<Iterator, T>, first, midPoint, init_value, func);
            T secondHalfResult = parallel_accumulate(midPoint, last, init_value, func);
            return func(firstHalfResult.get(), secondHalfResult);
        }
    }
}

#endif // PARALLEL_ACCUMULATE_H
