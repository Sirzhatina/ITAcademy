#include "system_info.hpp"
#include <format>

SystemInfo::SystemInfo(std::string osName, std::string compilerName, std::string compilerVersion)
: m_osName{std::move(osName)}
, m_compilerName{std::move(compilerName)}
, m_compilerVersion{std::move(compilerVersion)}
{
    
}


std::string SystemInfo::getOsName() const noexcept { return m_osName; }
std::string SystemInfo::getCompilerName() const noexcept { return m_compilerName; }
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
    
#ifdef __GNUC__
    auto compilerName = "GCC";
    auto compilerVersion = std::format("{}.{}.{}", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#elif __clang__
    auto compilerName = "Clang";
    auto compilerVersion = std::format("{}.{}.{}", __clang_major__, __clang_minor__, __clang_patchlevel__);
#elif _MSC_VER
    auto compilerName = "MSVC";
    auto compilerVersion = std::format("{}", _MSC_VER);
#else
    auto compilerName = "Unknown";
    auto compilerVersion = "";
#endif

    return SystemInfo{osName, compilerName, compilerVersion};
}

SystemInfo SystemInfo::makeSystemInfoFromCustomSource(
    const char* osName, 
    const char* compilerName, 
    const char* compilerVersion
) {
    return SystemInfo{osName, compilerName, compilerVersion};
}
