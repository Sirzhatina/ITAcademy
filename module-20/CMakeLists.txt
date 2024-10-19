set(TARGET module-20)

set(SOURCES
    DirectoryContent.h
    DirectoryContent.cpp
    main.cpp
)

add_executable(${TARGET} )

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)