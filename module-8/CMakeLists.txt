set(TARGET module-8)

set(SOURCES
    main.cpp
    Book.h
    Book.cpp
)

add_executable(${TARGET} )

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

target_link_libraries(${TARGET} PRIVATE utility)