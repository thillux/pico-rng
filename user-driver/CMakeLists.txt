cmake_minimum_required(VERSION 3.19)
project(prng-user)

find_package(Boost 1.70.0 CONFIG COMPONENTS program_options REQUIRED)

find_package(Threads)
find_package(PkgConfig)
pkg_check_modules(libusb libusb-1.0 IMPORTED_TARGET)

add_executable(prng-user main.cpp)

target_include_directories(prng-user PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(prng-user PUBLIC ${libusb_INCLUDE_DIRS})

target_link_libraries(prng-user ${Boost_LIBRARIES})
target_link_libraries(prng-user ${libusb_LIBRARIES})