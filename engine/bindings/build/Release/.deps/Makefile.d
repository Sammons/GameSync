cmd_Makefile := cd ..; /usr/lib/node_modules/node-gyp/gyp/gyp_main.py -fmake --ignore-environment "--toplevel-dir=." -I/home/ben/Desktop/GameSync/engine/bindings/build/config.gypi -I/usr/lib/node_modules/node-gyp/addon.gypi -I/home/ben/.node-gyp/0.10.23/common.gypi "--depth=." "-Goutput_dir=." "--generator-output=build" "-Dlibrary=shared_library" "-Dvisibility=default" "-Dnode_root_dir=/home/ben/.node-gyp/0.10.23" "-Dmodule_root_dir=/home/ben/Desktop/GameSync/engine/bindings" binding.gyp