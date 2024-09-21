set(TARGET module-15)

find_package(Qt6 REQUIRED)

set(SOURCES
    main.cpp
)

add_executable(${TARGET} )

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

target_link_libraries(${TARGET} PRIVATE qt::qt)