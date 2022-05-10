cmake_minimum_required(VERSION 3.21)
project(philo_with_Ohnuki C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(philo_with_Ohnuki
        include/philo.h
        src/free.c
        src/main.c
        src/utils.c)
