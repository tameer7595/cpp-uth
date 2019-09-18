cmake_minimum_required(VERSION 3.14)
project(cTranslator C)

set(CMAKE_C_STANDARD 99)

add_executable(cTranslator main.c c_encapsulation_defs.c c_encapsulation_defs.h  c_inheritance_defs.c c_inheritance_defs.h)