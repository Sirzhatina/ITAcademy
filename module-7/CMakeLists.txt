set(TARGET module-7)

set(SOURCES
    main.cpp
    PointedArr.h
    PointedArr.cpp
)

add_executable(${TARGET} )

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

target_link_libraries(${TARGET} PRIVATE utility)