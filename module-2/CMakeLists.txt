set(TARGET module-2)

set(SOURCES
    main.cpp
    factorial.hpp
    factorial.cpp
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
