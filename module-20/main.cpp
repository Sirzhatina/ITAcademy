#include <iostream>
#include <filesystem> 
#include <string>
#include "DirectoryContent.h"

namespace fs = std::filesystem;

std::string input(const std::string& msg);

int main() {
    std::string folderName = input("Enter folder name: ");

    if (!fs::exists(folderName) || !fs::is_directory(folderName)) {
        std::cerr << "Error: given name doesn't exist or is not a directory." << std::endl;
        return 1;
    }

    DirectoryContent dc{};
    DirectoryContent::Data d = dc.inspectFolder(folderName);

    std::cout << "Files found: " << d.m_filesCount << std::endl;
    std::cout << "Folders found: " << d.m_foldersCount << std::endl;

    if (!d.m_exeFiles.empty()) {
        std::cout << "Files with extension .exe are:" << std::endl;
        for (const auto& file : d.m_exeFiles) {
            std::cout << " - " << file << std::endl;
        }
    }
    else {
        std::cout << ".exe-files not found." << std::endl;
    }

    return 0;
}

std::string input(const std::string& msg) {
    std::cout << msg;

    std::string str;
    std::getline(std::cin, str);

    return str;
}