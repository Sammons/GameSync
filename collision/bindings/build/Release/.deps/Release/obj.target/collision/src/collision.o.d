cmd_Release/obj.target/collision/src/collision.o := g++ '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/home/ben/.node-gyp/0.10.22/src -I/home/ben/.node-gyp/0.10.22/deps/uv/include -I/home/ben/.node-gyp/0.10.22/deps/v8/include  -fPIC -Wall -Wextra -Wno-unused-parameter -pthread -m64 -O2 -fno-strict-aliasing -fno-tree-vrp -fno-rtti -fno-exceptions -MMD -MF ./Release/.deps/Release/obj.target/collision/src/collision.o.d.raw  -c -o Release/obj.target/collision/src/collision.o ../src/collision.cpp
Release/obj.target/collision/src/collision.o: ../src/collision.cpp \
 ../src/collision.h
../src/collision.cpp:
../src/collision.h: