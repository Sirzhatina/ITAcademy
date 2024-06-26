set(TARGET module-2)

set(SOURCES
    main.cpp
    factorial.hpp
    factorial.cpp
    os_info.hpp
    os_info.cpp
    compiler_info.hpp
    compiler_info.cpp
)

add_executable(${TARGET})

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

if (NOT DEFINED FACTORIAL_USED_TYPE)
    set(FACTORIAL_USED_TYPE int)
endif()

target_compile_definitions(${TARGET} PRIVATE FACTORIAL_USED_TYPE=int)
