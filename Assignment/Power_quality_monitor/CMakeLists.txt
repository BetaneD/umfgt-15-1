cmake_minimum_required(VERSION 4.2)
project(Power_quality_monitor C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled3 main.c
        waveform.c
        waveform.h
        io.c
        io.h
        main.c
)