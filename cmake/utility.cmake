function(create_cmake_lists subdir)
    if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt)
        file(WRITE ${subdir}/CMakeLists.txt 
"set(TARGET ${subdir})

set(SOURCES
    main.cpp
)

add_executable($\{TARGET\})

target_sources($\{TARGET\}
    PRIVATE
        $\{SOURCES\}
)"
        )
    endif()
endfunction()


function(add_subdir subdir)
    create_cmake_lists(${subdir})
    add_subdirectory(${subdir})
endfunction()