module;

#include <string>
#include <format>
#include <ostream>
#include <utility>

export module system_info;

export class SystemInfo {
public:
    std::string getOsInfo() const noexcept { return m_osName; }

    std::string getCompilerVersion() { return m_compilerVersion; }

    static SystemInfo makeSystemInfo() {
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
        ; std::string compilerInfo = std::format(
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

    friend std::ostream& operator<<(std::ostream& os, const SystemInfo& sys) {
        return os << std::format(
            "OS name: {}\n"
            "Compiler name: {}\n"
            "Compiler version: {}\n",
            sys.m_osName,
            sys.m_compilerName,
            sys.m_compilerVersion
        ) << std::endl;
    }

private:

    SystemInfo(std::string osName, std::string compilerName, std::string compilerVersion)
    : m_osName{std::move(osName)}
    , m_compilerName{std::move(compilerName)}
    , m_compilerVersion{std::move(compilerVersion)}
    {
        
    }

    static std::pair<std::string, std::string> parseCompilerInfo(const std::string compInfo) {
        auto foundPos = compInfo.find(' ');

        if (foundPos == std::string::npos) {
            return {compInfo, {}};
        }
        
        return {compInfo.substr(0, foundPos), 
                compInfo.substr(foundPos)
        };
    }

private:

    std::string m_osName;

    std::string m_compilerName;
    std::string m_compilerVersion;
};