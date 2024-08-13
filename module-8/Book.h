#pragma once

#include <string>
#include <iostream>
#include "utils.h"

class Book {
public:
	Book(std::string title, std::string author, std::uint16_t yearOfPublishing)
		: m_title{std::move(title)}
		, m_author{std::move(author)}
		, m_yearOfPublishing{yearOfPublishing} { }

	const std::string& getTitle() const { return m_title; }
	const std::string& getAuthor() const { return m_author;  }
	std::uint16_t getYearOfPublishing() const { return m_yearOfPublishing; }

	void printInfo() const {
		itac::print(
			"The book info:\n"
			"The author: {}\n"
			"The title: {}\n"
			"The year of publishing: {}",
			m_author,
			m_title,
			m_yearOfPublishing
		) << std::endl;
	}

private:
	std::string m_title;
	std::string m_author;

	std::uint16_t m_yearOfPublishing;
};