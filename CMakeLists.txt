cmake_minimum_required(VERSION 3.7)
project(php_myhtml)

set(CMAKE_C_STANDARD 99)

include_directories(/usr/include/php/20151012)
include_directories(/usr/include/php/20151012/TSRM)
include_directories(/usr/include/php/20151012/Zend)
include_directories(/usr/include/php/20151012/ext)
include_directories(/usr/include/php/20151012/main)
include_directories(/usr/include/php/20151012/sapi)

set(SOURCE_FILES main.c)
add_executable(php_myhtml ${SOURCE_FILES})