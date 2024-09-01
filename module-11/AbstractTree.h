#pragma once

#include "TreeKind.h"
#include "utils.h"

namespace hw11 {
	/// @brief Class representing a tree. The actual tree derived from this one
	/// is expected to correspond to one of TreeKind enumeration variants.
	class AbstractTree {
	public:
		AbstractTree() = default;
		virtual ~AbstractTree() = default;

		/// @brief getter to get underlying TreeKind variant.
		/// @return the variant of enumeration TreeKind corresponding the actual
		/// type of tree.
		[[nodiscard]] hw9::TreeKind getKind() const;
		/// @brief abstract method which should print the info about the actual tree
		/// to the console in its own manner.
		virtual void wind() const = 0;

	protected:
		/// @brief constructs the object from the passed tree kind.
		/// Should be called only by constructor of derived type that will pass
		/// the right kind of tree to the parent type.
		/// @param tk - TreeKind that the tree will have.
		AbstractTree(hw9::TreeKind tk);
	private:
		hw9::TreeKind m_kind{ hw9::TreeKind::Unknown };
	};

/// @brief Macro simplifying creation of repetetive types that do similar things.
/// In this case, macro creates a concrete tree derived from the abstract tree
/// and overrides its virtual methods. Also, it adds counter that assigns to trees of the current type
/// as their IDs.
/// @param TreeName - the name of the future class.
#define DefTree(TreeName)									   \
class TreeName : public AbstractTree {						   \
	static inline std::size_t m_kindCounter = 0;			   \
public:														   \
	TreeName() : AbstractTree{ hw9::TreeKind::##TreeName } { } \
	~TreeName() { --m_kindCounter; }						   \
															   \
	void wind() const override {							   \
		itac::print(										   \
			"Calling the wind() of {}; The counter is: {}\n",  \
			#TreeName,										   \
			m_##TreeName##Id								   \
		);													   \
		AbstractTree::wind();								   \
	}														   \
															   \
private:													   \
		std::size_t m_##TreeName##Id{ ++m_kindCounter };	   \
};

	DefTree(Pine)
		DefTree(Oak)
		DefTree(Maple)
		DefTree(Sequoia)

#undef DefTree // undefined to prevent misproper usage
} // namespace hw11

