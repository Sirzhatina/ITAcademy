#pragma  once

#include <string>

class SystemInfo {
public:

    SystemInfo(std::string osName, std::string compilerName, std::string compilerVersion);

    std::string getOsName() const noexcept;
    std::string getCompilerName() const noexcept;
    std::string getCompilerVersion() const noexcept;

    static SystemInfo makeSystemInfo();

private:

    std::string m_osName;

    std::string m_compilerName;
    std::string m_compilerVersion;
};