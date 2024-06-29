#include "system_info.hpp"
#include <format>

SystemInfo::SystemInfo(std::string osName, std::string compilerName, std::string compilerVersion)
: m_osName{std::move(osName)}
, m_compilerName{std::move(compilerName)}
, m_compilerVersion{std::move(compilerVersion)}
{
    
}


std::string SystemInfo::getOsInfo() const noexcept { return m_osName; }

std::string SystemInfo::getCompilerVersion() const noexcept { return m_compilerVersion; }

SystemInfo SystemInfo::makeSystemInfo() {
    std::string osName = 
#ifdef __linux__
    "Linux"
#elif _WIN32
    "Windows"
#elif __APPLE__
    "Apple";
#elif __FreeBSD__
    "FreeBSD"
#elif __ANDROID__
    "Android"
#else
    "Unknown"
#endif 
    ; 
    std::string compilerInfo = std::format(
#ifdef __GNUC__
    "GCC {}.{}.{}", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__
#elif __clang__
    "Clang {}.{}.{}", __clang_major__, __clang_minor__, __clang_patchlevel__
#elif _MSC_VER
    "MSVC {}", _MSC_VER
#else
    "Unknown"
#endif
    );

    auto [compilerName, compilerVersion] = parseCompilerInfo(std::move(compilerInfo));

    return SystemInfo{osName, compilerName, compilerVersion};
}

SystemInfo SystemInfo::makeSystemInfoFromCustomSource(
    const char* osName, 
    const char* compilerName, 
    const char* compilerVersion
) {
    return SystemInfo{osName, compilerName, compilerVersion};
}

std::ostream& operator<<(std::ostream& os, const SystemInfo& sys) {
    return os << std::format(
        "OS name: {}\n"
        "Compiler name: {}\n"
        "Compiler version: {}\n",
        sys.m_osName,
        sys.m_compilerName,
        sys.m_compilerVersion
    ) << std::endl;
}

std::pair<std::string, std::string> SystemInfo::parseCompilerInfo(const std::string compInfo) {
    auto foundPos = compInfo.find(' ');

    if (foundPos == std::string::npos) {
        return {compInfo, {}};
    }
    
    return {compInfo.substr(0, foundPos), 
            compInfo.substr(foundPos)
    };
}