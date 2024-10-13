#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <future>
#include <numeric>
#include <algorithm>
#include "Generator.h"

std::packaged_task taskSum{ [](const std::vector<int>& v) { 
    return std::accumulate(std::begin(v), std::end(v), 0); 
}};
std::packaged_task taskMax{ [](const std::vector<int>& v) { 
    return *std::ranges::max_element(v); 
}};
std::packaged_task taskMin{ [](const std::vector<int>& v) { 
    return *std::ranges::min_element(v); 
}};

int main() {
    Generator g{ 1, 100 };

    auto data = g.generate<std::vector>(100);

    std::future<int> sum = taskSum.get_future();
    std::future<int> max = taskMax.get_future();
    std::future<int> min = taskMin.get_future();

    std::jthread sumThread(std::move(taskSum), std::cref(data));
    std::jthread maxThread(std::move(taskMax), std::cref(data));
    std::jthread minThread(std::move(taskMin), std::cref(data));

    std::cout << "Sum: " << sum.get() << std::endl;
    std::cout << "Max: " << max.get() << std::endl;
    std::cout << "Min: " << min.get() << std::endl;

    return 0;
}
