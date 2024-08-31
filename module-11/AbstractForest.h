#pragma once

#include <memory>
#include <vector>
#include <type_traits>

class AbstractTree;

class AbstractForest {
public:
	AbstractForest() = default;
	virtual ~AbstractForest() = default;

	template <std::derived_from<AbstractTree>... Tree>
	bool growUp(std::shared_ptr<Tree>... at) {
		return (growUpImpl(at) && ...);
	}

	void wind() const;
		
protected:
	virtual bool growUpImpl(std::shared_ptr<AbstractTree> at) = 0;

	const auto& trees() const { return m_trees; }
	auto& trees() { return m_trees; }

private:

	std::vector<std::shared_ptr<AbstractTree>> m_trees;
};


/// The macro that creates repetitive structure of a class derived from the AbstractForest.
/// It implements the AbstractForest abstract method and declares only two methods in general, 
/// one of which is static and must be implemented manually by the user.
#define DefForest(ForestType)										\
class ForestType : public AbstractForest {							\
protected:															\
	bool growUpImpl(std::shared_ptr<AbstractTree> at) override {	\
		if (is##ForestType(*at)) {									\
			trees().push_back(at);									\
			return true;											\
		}															\
		return false;												\
	}																\
private:															\
	static bool is##ForestType(const AbstractTree& at);				\
};

DefForest(Coniferous)
DefForest(Deciduous)

#undef DefForest