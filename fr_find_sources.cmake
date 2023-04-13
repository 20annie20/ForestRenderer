function (fr_find_sources OUTVAR)

    # Enumerate source directories.
    # Scan each directory recusively.
    foreach (DIR IN LISTS ARGN)
        file (GLOB_RECURSE DIR_SOURCES CONFIGURE_DEPENDS
            "${DIR}/*.c"
            "${DIR}/*.cc"
            "${DIR}/*.cpp"
            "${DIR}/*.cxx"
            "${DIR}/*.h"
            "${DIR}/*.hh"
            "${DIR}/*.hpp"
            "${DIR}/*.hxx"
            "${DIR}/*.inl"
            "${DIR}/*.hlsl")
        list (APPEND SOURCES ${DIR_SOURCES})
    endforeach (DIR)

    set (${OUTVAR} ${SOURCES} PARENT_SCOPE)

endfunction (fr_find_sources)