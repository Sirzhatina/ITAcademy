#pragma once

#include <iostream>
#include <string>
#include <format>

namespace itac {
	template <class... Args>
	void print(const std::string& fmt, Args&&... args) {
		std::cout << std::vformat(fmt, std::make_format_args(std::forward<Args>(args)...));
	}
}