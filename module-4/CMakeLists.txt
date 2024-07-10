set(TARGET module-4)

set(SOURCES
    main.cpp
    number_converter.hpp
    number_converter.cpp
)

add_executable(${TARGET})

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)