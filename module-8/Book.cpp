#include <iostream>
#include "Book.h"
#include "utils.h"
#include "StreamChecker.h"

using namespace hw8;

Book::Book(std::string title, std::string author, std::uint16_t yearOfPublishing)
	: m_title{ std::move(title) }
	, m_author{ std::move(author) }
	, m_yearOfPublishing{ yearOfPublishing } { }

const std::string& Book::getTitle() const { return m_title; }
const std::string& Book::getAuthor() const { return m_author; }
std::uint16_t Book::getYearOfPublishing() const { return m_yearOfPublishing; }

void Book::printInfo() const {
	itac::print(
		"The book info:\n"
		"The author: {}\n"
		"The title: {}\n"
		"The year of publishing: {}",
		m_author,
		m_title,
		m_yearOfPublishing
	) << std::endl;

	StreamChecker{}.processStreamFailure(std::cout);
}