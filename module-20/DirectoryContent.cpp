#include "DirectoryContent.h"
#include <filesystem>

namespace fs = std::filesystem;

DirectoryContent::Data DirectoryContent::inspectFolder(const std::string& folder) {
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