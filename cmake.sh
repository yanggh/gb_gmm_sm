#!/bin/bash
rm -rf ./CMakeFiles ./Makefile ./gen/CMakeFiles ./gen/Makefile
../bin/nbec ./nbe_proto/gb_main.nbe gen
#mv gen/nbe_pgtype.c .
cmake .
