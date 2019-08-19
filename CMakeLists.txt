project("BTree" CXX)

include(CheckCXXCompilerFlag)
#versione minima
cmake_minimum_required(VERSION 3.5)

CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)

if (COMPILER_SUPPORTS_CXX14)
    ADD_COMPILE_OPTIONS("-std=c++14")
else()
    message(FATAL_ERROR "Il compilatore ${CMAKE_CXX_COMPILER} non supporta C++14")
endif()

add_compile_options("-Wall")
add_compile_options("-Wextra")
add_compile_options("-Wpedantic")
add_compile_options("-Werror")

#modalità release
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options("-O3")
    add_compile_options("-DNDEBUG")
#modalità debug
elseif (CMAKE_BUILD_TYPE STREQUAL "Debug")
    if (CMAKE_COMPILER_IS_GNUCXX)
        add_compile_options("-ggdb3")
    elseif (CMAKE_CXX_COMPILER_ID EQUAL "Clang")
        add_compile_options("-ggdb")
    else()
        add_compile_options("-g")
    endif()
endif()


#doxygen
find_program(DOX doxygen)
if (DOX)
    add_custom_target(doc COMMAND doxygen ${PROJECT_SOURCE_DIR}/doxygen.cfg)
endif()
#valgrind test
find_program(Valg valgrind)
if (Valg)
    add_custom_target(valgrind COMMAND valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./BTreeTest)
endif()

###################
include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/lib)

file(GLOB_RECURSE src ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(BinaryTree ${src})

add_executable(BTreeTest #EXCLUDE_FROM_ALL
        ${PROJECT_SOURCE_DIR}/test/BTretest.cpp)

target_link_libraries(BTreeTest BinaryTree)

set_target_properties(BinaryTree PROPERTIES PREFIX "")
set_target_properties(BinaryTree PROPERTIES OUTPUT_NAME "Binary_search_tree")
set_target_properties(BinaryTree PROPERTIES SUFFIX "")

####################
#target install e install_and_move
install(TARGETS BTreeTest DESTINATION ${PROJECT_SOURCE_DIR}/bin) #copia l'eseguibile in /bin
add_custom_target(install_and_move COMMAND mv BTreeTest ../bin/)  #muove l'eseguibile in /bin
#####################
#test
enable_testing()

add_test(NAME Compile_test
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
        COMMAND make BTreeTest)
    
add_test(NAME Read_file_test
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
    COMMAND ./BTreeTest [ReadFile])

add_test(NAME Int_Bynary_Tree
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
        COMMAND ./BTreeTest [IntBTree])
add_test(NAME String_Bynary_Tree
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
        COMMAND ./BTreeTest [StringBTree])

#valgrind test
if (Valg)
    add_test(NAME ValgrindTest_Read_file_test
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
            COMMAND valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./BTreeTest [ReadFile])
    add_test(NAME ValgrindTest_Int_Bynary_Tree
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
            COMMAND valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./BTreeTest [IntBTree])
    add_test(NAME ValgrindTest_String_Bynary_Tree
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
            COMMAND ./BTreeTest [StringBTree])
endif()
