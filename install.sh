#!/bin/bash
#rm -rf ./gen/*.c ./gen/*.h ./gen/*.sql
#../bin/nbec ./nbe_proto/gb_main.nbe gen
rm -rf ../gb_ext_v1/gen/*.h ../gb_ext_v1/gen/*.c
cp -rf ./gen/*.c ./gen/*.h ../gb_ext_v1/gen
#rm -rf ../gb_ext_v1/gen/CMakeFiles ../gb_ext_v1/gen/cmake_install.cmake ../gb_ext_v1/gen/CMakeLists.txt ../gb_ext_v1/gen/Makefile
#cp ./nbe_pgtype.c ../gb_ext_v1/gen
cp gen/nbe_pgtype--1.0.sql ../gb_ext_v1/gb_server--1.0.sql
cp gb_app_common.h ../gb_ext_v1/gen/
cp gb_fcs_check.h ../gb_ext_v1/gen/
cp dict.h ../gb_ext_v1/gen/
cp nbe_common.h ../gb_ext_v1/gen/
cp gb_fr_common.h ../gb_ext_v1/gen/
cp gb_llc_common.h ../gb_ext_v1/gen/
cp gb_l3_common.h ../gb_ext_v1/gen/
cp gmm_sm_dict.h  ../gb_ext_v1/gen/
cp gb_gmm_sm.h   ../gb_ext_v1/gen/
echo "install ok"
