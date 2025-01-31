cmake_minimum_required(VERSION 3.22)
project(shlibs VERSION 0.1)

add_library(private private.cc)
target_include_directories(private
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
set_target_properties(private PROPERTIES
    SOVERSION "${shlibs_VERSION_MAJOR}"
    VERSION "${shlibs_VERSION}"
)

add_library(transitive transitive.cc)
target_include_directories(transitive
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(transitive
    PRIVATE
        private
)
set_target_properties(transitive PROPERTIES
    SOVERSION "${shlibs_VERSION_MAJOR}"
    VERSION "${shlibs_VERSION}"
)

add_library(dep dep.cc)
target_include_directories(dep
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(dep
    PUBLIC
        transitive
)
set_target_properties(dep PROPERTIES
    SOVERSION "${shlibs_VERSION_MAJOR}"
    VERSION "${shlibs_VERSION}"
)

add_executable(main main.cc)
target_link_libraries(main dep)
