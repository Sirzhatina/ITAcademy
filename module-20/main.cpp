#include <iostream>
#include <filesystem> 
#include <string>

namespace fs = std::filesystem;

std::string input(const std::string& msg) {
    std::cout << msg;

    std::string str;
    std::getline(std::cin, str);

    return str;
}

class DirectoryContent {
public:
    struct Data {
        std::string m_folderName;

        int m_filesCount{ 0 };
        int m_foldersCount{ 0 };

        std::vector<std::string> m_exeFiles;
    };
public:
    DirectoryContent() = default;

    Data inspectFolder(const std::string& folder) {
        Data d{};
        d.m_folderName = folder;

        for (const auto& entry : fs::directory_iterator(folder)) {
            if (fs::is_directory(entry)) {
                d.m_foldersCount++;
            }
            else if (fs::is_regular_file(entry)) {
                d.m_filesCount++;
                if (entry.path().extension() == ".exe") {
                    d.m_exeFiles.push_back(entry.path().filename().string());
                }
            }
        }
        return d;
    }
};

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