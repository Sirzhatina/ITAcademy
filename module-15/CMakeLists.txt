set(TARGET module-15)

set(SOURCES
    main.cpp
)

add_executable(${TARGET} )

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

target_link_libraries(${TARGET} PRIVATE Qt6::Widgets)
set_target_properties(${TARGET} PROPERTIES AUTOMOC ON)