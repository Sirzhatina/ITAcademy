#pragma  once

#include <string>

/**
 * @brief SystemInfo class keeps data like your OS name, compiler name
 * and compiler version
 */
class SystemInfo {
public:

    SystemInfo(std::string osName, std::string compilerName, std::string compilerVersion);

    std::string getOsName() const noexcept;
    std::string getCompilerName() const noexcept;
    std::string getCompilerVersion() const noexcept;
private:

    std::string m_osName;

    std::string m_compilerName;
    std::string m_compilerVersion;
};