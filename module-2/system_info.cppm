module;

#include <string>
#include <optional>
#include <format>
#include <ostream>

export module system_info;

#define SYSTEM_INFO_FIELDS \



export class SystemInfo {
public:
    std::string getOsInfo() const noexcept { return m_osName; }

    std::string getCompilerVersion() { return m_compilerVersion; }

private:
    std::string m_osName;

    std::string m_compilerName;
    std::string m_compilerVersion;
};