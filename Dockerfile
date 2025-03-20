FROM ubuntu:24.04

RUN apt update && \
    apt -y install cmake python3 build-essential gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib git

RUN cd root && \
    git clone https://github.com/raspberrypi/pico-sdk.git --recursive

WORKDIR /build
