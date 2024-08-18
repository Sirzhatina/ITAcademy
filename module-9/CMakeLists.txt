set(TARGET module-9)

set(SOURCES
    main.cpp
    Forest.h
    Forest.cpp
    Tree.h
    Tree.cpp
    TreeKind.h
    TreeKind.cpp
)

add_executable(${TARGET} )

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

target_link_libraries(${TARGET} PRIVATE utility)