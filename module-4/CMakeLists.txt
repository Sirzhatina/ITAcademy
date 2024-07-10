set(TARGET module-4)

set(SOURCES
    main.cpp
)

add_executable(${TARGET})

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)