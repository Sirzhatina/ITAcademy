#pragma once

#include <iostream>
#include <string>
#include <format>

namespace itac {
	template <class... Args>
	std::ostream& print(const std::string& fmt, Args&&... args) {
		return std::cout << std::vformat(fmt, std::make_format_args(std::forward<Args>(args)...));
	}
}