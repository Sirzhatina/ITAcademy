#include <vector>
#include <random>
#include <algorithm>

class Generator {
public:
    Generator(int min, int max): m_distr{min, max} { }

    std::vector<int> operator()(std::size_t size) {
        std::vector<int> result;
        result.resize(size);

        static std::mt19937 mt{ std::random_device{}() };

        std::ranges::generate(result, [this]() { return m_distr(mt); });

        return result;
    }
private:
    std::uniform_int_distribution<int> m_distr;
};


int main(int argc, char* argv[])
{

    return 0;
}