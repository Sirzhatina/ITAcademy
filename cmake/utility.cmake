
function(write_if_not_exist subdir file text)
    if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/${file})
        file(WRITE ${subdir}/${file} ${text})
    endif()
endfunction()

function(create_source subdir target_type)
    if (${target_type} STREQUAL "EXEC" OR ${target_type} STREQUAL "")
        set(src "main.cpp")
        set(src_content "int main(int argc, char* argv[])
\{

    return 0\\\;
\}"
        )
    else()
        set(src "lib.cpp")
        set(src_content "#include \"lib.h\"\n\n")
        # additional header for library source file
        write_if_not_exist(${subdir} "lib.h" "#pragma once\n\n")
    endif()
       
    write_if_not_exist(${subdir} ${src} ${src_content})
endfunction()

function(create_cmake_lists subdir target_type)

    if (${target_type} STREQUAL "EXEC" OR ${target_type} STREQUAL "")
        set(add_target "add_executable")
        set(src "main.cpp")
    else()
        set(add_target "add_library")
        set(lib_type "${target_type}")
        set(src "lib.h lib.cpp")
    endif()

    write_if_not_exist(${subdir} CMakeLists.txt 
"set(TARGET ${subdir})

set(SOURCES
    ${src}
)

${add_target}($\{TARGET\} ${lib_type})

target_sources($\{TARGET\}
    PRIVATE
        $\{SOURCES\}
)"
    )
endfunction()


function(add_target_subdir subdir)
    set(target_type ${ARGN})

    if ("${target_type}" STREQUAL "")
        set(target_type "EXEC")
    endif()
    if (NOT ${target_type} STREQUAL "EXEC" AND NOT ${target_type} STREQUAL "STATIC" AND NOT ${lib_type} STREQUAL "SHARED")
        message(FATAL_ERROR "-- Fatal, add_target_subdir: passed library type is neither STATIC nor SHARED")
    endif()
    
    create_cmake_lists(${subdir} ${target_type})
    create_source(${subdir} ${target_type})

    add_subdirectory(${subdir})
endfunction()