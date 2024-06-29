#pragma  once

#include <string>
#include <ostream>
#include <utility>

class SystemInfo {
public:
    std::string getOsInfo() const noexcept;

    std::string getCompilerVersion() const noexcept;

    static SystemInfo makeSystemInfo();

    static SystemInfo makeSystemInfoFromCustomSource(
        const char* osName, 
        const char* compilerName, 
        const char* compilerVersion
    );
    friend std::ostream& operator<<(std::ostream& os, const SystemInfo& sys);

private:

    SystemInfo(std::string osName, std::string compilerName, std::string compilerVersion);

    static std::pair<std::string, std::string> parseCompilerInfo(const std::string compInfo);

private:

    std::string m_osName;

    std::string m_compilerName;
    std::string m_compilerVersion;
};