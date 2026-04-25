cmake_minimum_required(version 3.14)
project(Power_quality_monitor C)

set(CMAKE_C_STANDARD 99)
add_executable(Power_quality_monitor
        main.c
        waveform.c
        waveform.h
        io.c
        io.h
        sort.c
        sort.h
)