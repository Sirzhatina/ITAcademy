set(TARGET module-5)

set(SOURCES
    main.cpp
    Shape.h
)

add_executable(${TARGET})

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)