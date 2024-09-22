#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <array>
#include <format>
#include <forward_list>
#include <list>

static std::mt19937 mt{ std::random_device{}() };

class Generator {
public:
    Generator(int min, int max): m_distr{min, max} { }

    template <template <class> class Container>
    Container<int> generate(std::size_t size) {
        Container<int> result;
        result.resize(size);

        std::ranges::generate(result, [this]() { return m_distr(mt); });

        return result;
    }

private:
    std::uniform_int_distribution<int> m_distr;
};

struct Data {
    char id;
    int value;

    bool operator<(const Data& rhs) const {
        return value < rhs.value;
    }
};

template <class C>
void print(const std::string& msg, const C& c) {
    std::cout << msg;
    std::ranges::copy(c, std::ostream_iterator<typename C::value_type>{std::cout, " "});
    std::cout << std::endl;
}

template <int size>
void printData(const std::string& msg, const std::array<Data, size>& d) {
    std::cout << msg << '\n';
    for (const auto& [id, value] : d) {
        std::cout << std::format("({}; {})\n", id, value);
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    Generator gen{ 1, 100 };

    std::vector<int> vec = gen.generate<std::vector>(10);
   
    print("Before sort: ", vec);
    std::ranges::sort(vec);
    print("After sort: ", vec);
    std::cout << std::endl;

    std::ranges::shuffle(vec, mt);

    print("Before partial sort: ", vec);
    std::ranges::partial_sort(vec, std::ranges::begin(vec) + 3);
    print("After partial sort (first 3 elements are sorted): ", vec);
    std::cout << std::endl;

    std::array<Data, 5> data{
        Data{'a', 7},
        Data{'b', 3},
        Data{'c', 3},
        Data{'d', 2},
        Data{'e', 9}
    };
    printData("Before stable sort:\n", data);
    std::ranges::stable_sort(data, [](auto lhs, auto rhs) { return lhs.value < rhs.value; });
    printData("After stable sort (data with id 'b' and 'c' have preserved their positions):\n", data);
    std::cout << std::endl;

    std::list<int> list = gen.generate<std::list>(10);

    print("Before list::sort: ", list);
    list.sort();
    print("After list::sort: ", list);
    std::cout << std::endl;

    std::forward_list<int> fList = gen.generate<std::forward_list>(10);

    print("Before forward_list::sort: ", fList);
    fList.sort();
    print("After forward_list::sort: ", fList);

    return 0;
}