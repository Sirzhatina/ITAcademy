set(TARGET utility)

set(SOURCES
    Generator.h
    StreamChecker.cpp
    StreamChecker.h
    utils.h
)

add_library(${TARGET} STATIC)

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

target_include_directories(${TARGET} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})