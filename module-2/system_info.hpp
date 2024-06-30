#pragma  once

#include <string>

class SystemInfo {
public:
    std::string getOsName() const noexcept;
    std::string getCompilerName() const noexcept;
    std::string getCompilerVersion() const noexcept;

    static SystemInfo makeSystemInfo();

    static SystemInfo makeSystemInfoFromCustomSource(
        const char* osName, 
        const char* compilerName, 
        const char* compilerVersion
    );

private:

    SystemInfo(std::string osName, std::string compilerName, std::string compilerVersion);

private:

    std::string m_osName;

    std::string m_compilerName;
    std::string m_compilerVersion;
};