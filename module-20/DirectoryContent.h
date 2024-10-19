#pragma once

#include <string>
#include <vector>

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

    Data inspectFolder(const std::string& folder);
};
