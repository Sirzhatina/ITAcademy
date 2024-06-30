#include "system_info.hpp"


SystemInfo::SystemInfo(std::string osName, std::string compilerName, std::string compilerVersion)
: m_osName{std::move(osName)}
, m_compilerName{std::move(compilerName)}
, m_compilerVersion{std::move(compilerVersion)}
{
    
}

std::string SystemInfo::getOsName() const noexcept { return m_osName; }
std::string SystemInfo::getCompilerName() const noexcept { return m_compilerName; }
std::string SystemInfo::getCompilerVersion() const noexcept { return m_compilerVersion; }
