set(TARGET module-6)

set(SOURCES
    main.cpp
    StringReverser.h
    StringReverser.cpp
    VectorGenerator.h
    VectorGenerator.cpp
)

add_executable(${TARGET})

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

target_include_directories(${TARGET} PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(${TARGET} PRIVATE utility)