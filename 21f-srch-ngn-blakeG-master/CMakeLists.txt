cmake_minimum_required(VERSION 3.19)
project(21f_final_proj_template)

set(CMAKE_CXX_STANDARD 17)

include_directories("include/rapidjson")



add_executable(21f_final_proj_template main.cpp catch_setup.cpp avlTree.h sample_tests.cpp catch.hpp indexHandler.cpp indexHandler.h docParser.cpp docParser.h porter2_stemmer.h porter2_stemmer.cpp queryProcessor.cpp queryProcessor.h hashTable.h searcher.cpp searcher.h)
