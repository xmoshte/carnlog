cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(carnlog)

target_include_directories(app PRIVATE src)

target_sources(app PRIVATE 
src/main.c
src/lsm6ds0/lsm6ds0.c
)
