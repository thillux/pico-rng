add_executable(pico_rng
        pico_rng.c
        )

target_link_libraries(pico_rng PRIVATE
        pico_mbedtls
        pico_rand
        pico_stdlib
)

target_include_directories(pico_rng PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

pico_enable_stdio_uart(pico_rng 1)
pico_add_extra_outputs(pico_rng)
