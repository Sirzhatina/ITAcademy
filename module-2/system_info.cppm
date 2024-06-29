module;

#include <string>
#include <optional>
#include <format>
#include <ostream>

export module system_info;

#define SYSTEM_INFO_FIELDS \



export class SystemInfo {
public:


private:
    std::string m_osName;

    std::string m_compilerName;
    std::string m_compilerVersion;
};