set(TARGET utility)

set(SOURCES
    StreamChecker.cpp
    StreamChecker.h
)

add_library(${TARGET} STATIC)

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)