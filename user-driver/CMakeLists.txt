cmake_minimum_required(VERSION 3.13)
project(prng-user VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost 1.70.0 CONFIG COMPONENTS program_options REQUIRED)

find_package(Threads)
find_package(PkgConfig)
pkg_check_modules(libusb libusb-1.0 IMPORTED_TARGET)


find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

qt_add_executable(prng-user
    main.cpp
)

target_include_directories(prng-user PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(prng-user PUBLIC ${libusb_INCLUDE_DIRS})

target_link_libraries(prng-user PRIVATE Qt6::Core)
target_link_libraries(prng-user PRIVATE ${Boost_LIBRARIES})
target_link_libraries(prng-user PRIVATE ${libusb_LIBRARIES})
