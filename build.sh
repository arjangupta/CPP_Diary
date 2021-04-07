#!/bin/sh

if [ ! -z $1 ]; then
    if { [ "--full-build" = $1 ] || [ "--full-rebuild" = $1 ]; }; then
        rm -rf build/linux/
    fi
fi
cmake -H. -Bbuild/linux/
cd build/linux
make -j $(nproc)
