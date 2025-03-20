#include <cassert>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <libusb-1.0/libusb.h>
#include <memory>
#include <thread>

int main(void) {
    libusb_context* context = nullptr;
    int status = libusb_init(&context);
    if (status != 0) {
        std::cerr << "Error initializing libusb" << std::endl;
        return EXIT_FAILURE;
    }
    libusb_set_debug(context, 3);

    libusb_device_handle* dev = libusb_open_device_with_vid_pid(context, 0x0, 0x4);
    assert(dev != nullptr);

    unsigned char buffer[64];
    memset(buffer, '\0', sizeof(buffer));
    int readLength = 0;

    // get exclusive usage
    if (libusb_kernel_driver_active(dev, 0) == 1) { //find out if kernel driver is attached
        libusb_detach_kernel_driver(dev, 0); //detach it
    }
    libusb_claim_interface(dev, 0);

    while(true) {
        if (0 != libusb_bulk_transfer(dev, 1 | LIBUSB_ENDPOINT_IN, buffer, sizeof(buffer), &readLength, 1000))
            continue;
        
        // for (int i = 0; i < readLength; ++i) {
        //     std::cout << std::hex << static_cast<int>(buffer[i]);
        // }
        // std::cout << std::endl;
        std::cout.write(reinterpret_cast<const char*>(&buffer[0]), readLength);

        using namespace std::chrono_literals;
        // std::this_thread::sleep_for(2000ms);
    }

    libusb_release_interface(dev, 0);

    libusb_close(dev);
    dev = nullptr;

    libusb_exit(nullptr);
    return EXIT_SUCCESS;
}