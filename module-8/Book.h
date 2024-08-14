#pragma once

#include <string>

namespace hw8 {
	/// @brief simple class that allows you to store information about a book and
	/// get this information from each field. The class stores the author, title and
	/// the year of publishing.
	class Book {
	public:
		/// @brief consturctor that initializes each class field in the given order.
		/// @param title - the book's title
		/// @param author - the book's author
		/// @param yearOfPublishing - the book's year of publishing
		Book(std::string title, std::string author, std::uint16_t yearOfPublishing);
		/// @brief getter to get the book's title.
		/// @return the title of the book.
		const std::string& getTitle() const;
		/// @brief getter to get the book's author.
		/// @return the author of the book.
		const std::string& getAuthor() const;
		/// @brief getter to get the book's year of publishing.
		/// @return the year of publishing of the book.
		std::uint16_t getYearOfPublishing() const;
		/// @brief prints each data member to the standard output.
		/// The method does failure checks for the stream object, so if one occurs,
		/// the program stops instantly with the error.
		void printInfo() const;

	private:
		std::string m_title;
		std::string m_author;

		std::uint16_t m_yearOfPublishing;
	};
}

