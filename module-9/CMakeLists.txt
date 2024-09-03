set(TARGET module-9)

set(SOURCES_STATIC
    Forest.h
    Forest.cpp
    Tree.h
    Tree.cpp
    TreeKind.h
    TreeKind.cpp
)

add_library(${TARGET}_STATIC STATIC ${SOURCES_STATIC})

add_executable(${TARGET} main.cpp)

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

target_link_libraries(${TARGET}_STATIC PUBLIC utility)
target_include_directories(${TARGET}_STATIC INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${TARGET} PRIVATE ${TARGET}_STATIC)
