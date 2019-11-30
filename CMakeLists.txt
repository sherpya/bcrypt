cmake_minimum_required(VERSION 3.1)
project(bcrypt)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    link_libraries("-static")
    set(CMAKE_C_FLAGS "-Wall")
    set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--enable-stdcall-fixup ${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
endif()

add_library(bcrypt SHARED bcrypt.c bcrypt.rc bcrypt.def)
set_target_properties(bcrypt PROPERTIES PREFIX "")
