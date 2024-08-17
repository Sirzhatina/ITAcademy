#include <random>
#include <algorithm>
#include "Forest.h"
#include "Tree.h"
#include "utils.h"

namespace hw9 {
    std::weak_ptr<Tree> Forest::growUp(TreeKind t) {
        auto res = std::make_shared<Tree>(t);
        
        m_trees.push_back(res);
        return res;
    }

    std::weak_ptr<Tree> Forest::growUp() {
        static std::mt19937 mt{ std::random_device{}() };

        if (!m_trees.empty()) {
            std::uniform_int_distribution<std::size_t> distr{ 0, m_trees.size() - 1 };

            auto tree = growUp(m_trees[distr(mt)]->getKind());

            return tree;
        }
        return std::weak_ptr<Tree>{};
    }

    void Forest::cutAll() { m_trees.clear(); }

    void Forest::wind() const {
        for (const auto& t : m_trees) {
            t->wind();
            itac::print("") << std::endl; // not cout to keep the stream object generic and more consistent
        }
        itac::print("") << std::endl;
    }

    Forest Forest::operator+(const Forest& rhs) const {
        namespace rng = std::ranges;

        Forest res;
        res.m_trees.reserve(this->m_trees.size() + rhs.m_trees.size());

        rng::copy(this->m_trees, std::back_inserter(res.m_trees));
        rng::copy(rhs.m_trees, std::back_inserter(res.m_trees));

        return res;
    }
}
