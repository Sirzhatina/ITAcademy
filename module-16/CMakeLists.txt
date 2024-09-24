set(TARGET module-16)

set(SOURCES
    main.cpp
    Generator.h
    Data.h
    Print.h
)

add_executable(${TARGET} )

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)