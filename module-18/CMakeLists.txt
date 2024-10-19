set(TARGET module-18)

set(SOURCES
    main.cpp
    Order.h
    Order.cpp
)

add_executable(${TARGET} )

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

target_link_libraries(${TARGET} PRIVATE utility)