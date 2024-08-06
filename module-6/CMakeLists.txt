set(TARGET module-6)

set(SOURCES
    main.cpp
    StringReverser.h
    StringReverser.cpp
)

add_executable(${TARGET})

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)