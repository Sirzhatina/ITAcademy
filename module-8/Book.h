#pragma once

#include <string>

namespace hw8 {
	class Book {
	public:
		Book(std::string title, std::string author, std::uint16_t yearOfPublishing);

		const std::string& getTitle() const;
		const std::string& getAuthor() const;

		std::uint16_t getYearOfPublishing() const;

		void printInfo() const;

	private:
		std::string m_title;
		std::string m_author;

		std::uint16_t m_yearOfPublishing;
	};
}

