set(TARGET module-5)

set(SOURCES
    main.cpp
    Shape.h
    Shape.cpp
    ShapeHandler.h
    ShapeHandler.cpp
)

add_executable(${TARGET})

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)