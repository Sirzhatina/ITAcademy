set(TARGET module-3)

set(SOURCES
    main.cpp
    table.h
    table.cpp
)

add_executable(${TARGET})

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)