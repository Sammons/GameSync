cmd_Release/obj.target/engine.node := flock ./Release/linker.lock g++ -shared -pthread -rdynamic -m64  -Wl,-soname=engine.node -o Release/obj.target/engine.node -Wl,--start-group Release/obj.target/engine/engine.o -Wl,--end-group 
