set(TARGET module-2)

set(SOURCES
    main.cpp
    factorial.hpp
    factorial.cpp
    system_info.hpp
    system_info.cpp
)

add_executable(${TARGET})

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

if (NOT DEFINED FACTORIAL_USED_TYPE)
    set(FACTORIAL_USED_TYPE int)
endif()

target_compile_definitions(${TARGET} PRIVATE FACTORIAL_USED_TYPE=${FACTORIAL_USED_TYPE})

if (DEFINED RECURSIVE_FACTORIAL)
    target_compile_definitions(${TARGET} PRIVATE RECURSIVE_FACTORIAL)
endif()

configure_file(os_compiler.h.in os_compiler.h)
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/)