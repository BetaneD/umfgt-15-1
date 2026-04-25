cmake_minimum_required(VERSION 3.14)
project(Power_quality_monitor(2) C)

set(CMAKE_C_STANDARD 99)

add_executable(Power_quality_monitor
        main.c
        waveform.c
        io.c
        sort.c)
