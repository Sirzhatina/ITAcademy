set(TARGET module-14)

set(SOURCES
    main.cpp
    Task1.h
    Task1.cpp
    Circle.h
    Circle.cpp
)

add_executable(${TARGET} )

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

target_link_libraries(${TARGET} PRIVATE utility)