set(TARGET module-11)

set(SOURCES
    main.cpp
    AbstractTree.h
    AbstractTree.cpp
)

add_executable(${TARGET} )

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

target_link_libraries(${TARGET} PRIVATE module-9_STATIC)
