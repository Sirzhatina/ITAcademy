set(TARGET module-3)

set(SOURCES
    main.cpp
    table.h
    table.cpp
    number_parser.h
    number_parser.cpp
)

add_executable(${TARGET})

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)