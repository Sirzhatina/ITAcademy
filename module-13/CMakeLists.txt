set(TARGET module-13)

set(SOURCES
    main.cpp
    ICar.h
    ServiceStation.h
)

add_executable(${TARGET} )

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

target_link_libraries(${TARGET} PRIVATE utility)