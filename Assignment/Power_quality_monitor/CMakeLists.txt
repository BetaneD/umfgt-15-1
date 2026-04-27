cmake_minimum_required(VERSION 3.21.1)
project(Power_quality_monitor C)

set(CMAKE_C_STANDARD 99)

add_executable(Power_quality_monitor
        main.c
        waveform.c
        io.c
)