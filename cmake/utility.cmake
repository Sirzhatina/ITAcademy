
function(write_if_not_exist subdir file text)
    if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/${file})
        file(WRITE ${subdir}/${file} ${text})
    endif()
endfunction()

function(create_cmake_lists subdir)
    write_if_not_exist(${subdir} CMakeLists.txt 
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
endfunction()


function(add_subdir subdir)
    create_cmake_lists(${subdir})
    add_subdirectory(${subdir})
endfunction()