#!/bin/sh

rm watchdog_obj watchdog_cstyle
arm-linux-gnueabihf-g++ watchdog_object.cpp -o watchdog_obj
arm-linux-gnueabihf-g++ watchdog.cpp        -o watchdog_cstyle