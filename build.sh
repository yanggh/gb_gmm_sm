#!/bin/bash
#make clean
rm -rf ./gen/*.c ./gen/*.h ./gen/*.sql
../bin/nbec ./nbe_proto/gb_main.nbe gen
sed -i "4 i#include \"utils/builtins.h\"" ./gen/nbe_pgtype.c
cp -rf ../include/* /usr/include/
cp ../lib/libnbe.so /usr/local/lib
#mv gen/nbe_pgtype.c .
make -j8
