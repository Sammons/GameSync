cmd_Release/obj.target/engine/engine.o := g++ '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/home/chasm/.node-gyp/0.10.25/src -I/home/chasm/.node-gyp/0.10.25/deps/uv/include -I/home/chasm/.node-gyp/0.10.25/deps/v8/include  -fPIC -Wall -Wextra -Wno-unused-parameter -pthread -m64 -std=c++11 -lib=libc++ -O2 -fno-strict-aliasing -fno-tree-vrp -fno-omit-frame-pointer -fno-rtti -fno-exceptions -MMD -MF ./Release/.deps/Release/obj.target/engine/engine.o.d.raw  -c -o Release/obj.target/engine/engine.o ../engine.cc
Release/obj.target/engine/engine.o: ../engine.cc \
 /home/chasm/.node-gyp/0.10.25/src/node.h \
 /home/chasm/.node-gyp/0.10.25/deps/uv/include/uv.h \
 /home/chasm/.node-gyp/0.10.25/deps/uv/include/uv-private/uv-unix.h \
 /home/chasm/.node-gyp/0.10.25/deps/uv/include/uv-private/ngx-queue.h \
 /home/chasm/.node-gyp/0.10.25/deps/uv/include/uv-private/uv-linux.h \
 /home/chasm/.node-gyp/0.10.25/deps/v8/include/v8.h \
 /home/chasm/.node-gyp/0.10.25/deps/v8/include/v8stdint.h \
 /home/chasm/.node-gyp/0.10.25/src/node_object_wrap.h \
 /home/chasm/.node-gyp/0.10.25/src/node.h ../src/wrapper.h \
 ../src/Box2D/Box2D.h ../src/Box2D/Common/b2Settings.h \
 ../src/Box2D/Common/b2Draw.h ../src/Box2D/Common/b2Math.h \
 ../src/Box2D/Common/b2Settings.h ../src/Box2D/Common/b2Timer.h \
 ../src/Box2D/Collision/Shapes/b2CircleShape.h \
 ../src/Box2D/Collision/Shapes/b2Shape.h \
 ../src/Box2D/Collision/Shapes/../../Common/b2BlockAllocator.h \
 ../src/Box2D/Collision/Shapes/../../Common/b2Settings.h \
 ../src/Box2D/Collision/Shapes/../../Common/b2Math.h \
 ../src/Box2D/Collision/Shapes/../b2Collision.h \
 ../src/Box2D/Collision/Shapes/../../Common/b2Math.h \
 ../src/Box2D/Collision/Shapes/b2EdgeShape.h \
 ../src/Box2D/Collision/Shapes/b2ChainShape.h \
 ../src/Box2D/Collision/Shapes/b2PolygonShape.h \
 ../src/Box2D/Collision/b2BroadPhase.h \
 ../src/Box2D/Collision/../Common/b2Settings.h \
 ../src/Box2D/Collision/../Collision/b2Collision.h \
 ../src/Box2D/Collision/../Collision/b2DynamicTree.h \
 ../src/Box2D/Collision/../Collision/b2Collision.h \
 ../src/Box2D/Collision/../Collision/../Common/b2GrowableStack.h \
 ../src/Box2D/Collision/../Collision/../Common/b2Settings.h \
 ../src/Box2D/Collision/b2Distance.h \
 ../src/Box2D/Collision/../Common/b2Math.h \
 ../src/Box2D/Collision/b2DynamicTree.h \
 ../src/Box2D/Collision/b2TimeOfImpact.h \
 ../src/Box2D/Collision/b2Distance.h ../src/Box2D/Dynamics/b2Body.h \
 ../src/Box2D/Dynamics/../Common/b2Math.h \
 ../src/Box2D/Dynamics/../Collision/Shapes/b2Shape.h \
 ../src/Box2D/Dynamics/b2Fixture.h \
 ../src/Box2D/Dynamics/../Dynamics/b2Body.h \
 ../src/Box2D/Dynamics/../Collision/b2Collision.h \
 ../src/Box2D/Dynamics/b2WorldCallbacks.h \
 ../src/Box2D/Dynamics/../Common/b2Settings.h \
 ../src/Box2D/Dynamics/b2TimeStep.h ../src/Box2D/Dynamics/b2World.h \
 ../src/Box2D/Dynamics/../Common/b2BlockAllocator.h \
 ../src/Box2D/Dynamics/../Common/b2StackAllocator.h \
 ../src/Box2D/Dynamics/../Common/b2Settings.h \
 ../src/Box2D/Dynamics/../Dynamics/b2ContactManager.h \
 ../src/Box2D/Dynamics/../Dynamics/../Collision/b2BroadPhase.h \
 ../src/Box2D/Dynamics/../Dynamics/b2WorldCallbacks.h \
 ../src/Box2D/Dynamics/../Dynamics/b2TimeStep.h \
 ../src/Box2D/Dynamics/Contacts/b2Contact.h \
 ../src/Box2D/Dynamics/Contacts/../../Common/b2Math.h \
 ../src/Box2D/Dynamics/Contacts/../../Collision/b2Collision.h \
 ../src/Box2D/Dynamics/Contacts/../../Collision/Shapes/b2Shape.h \
 ../src/Box2D/Dynamics/Contacts/../../Dynamics/b2Fixture.h \
 ../src/Box2D/Dynamics/Joints/b2DistanceJoint.h \
 ../src/Box2D/Dynamics/Joints/b2Joint.h \
 ../src/Box2D/Dynamics/Joints/../../Common/b2Math.h \
 ../src/Box2D/Dynamics/Joints/b2FrictionJoint.h \
 ../src/Box2D/Dynamics/Joints/b2GearJoint.h \
 ../src/Box2D/Dynamics/Joints/b2MotorJoint.h \
 ../src/Box2D/Dynamics/Joints/b2MouseJoint.h \
 ../src/Box2D/Dynamics/Joints/b2PrismaticJoint.h \
 ../src/Box2D/Dynamics/Joints/b2PulleyJoint.h \
 ../src/Box2D/Dynamics/Joints/b2RevoluteJoint.h \
 ../src/Box2D/Dynamics/Joints/b2RopeJoint.h \
 ../src/Box2D/Dynamics/Joints/b2WeldJoint.h \
 ../src/Box2D/Dynamics/Joints/b2WheelJoint.h ../src/HelloWorld.cpp
../engine.cc:
/home/chasm/.node-gyp/0.10.25/src/node.h:
/home/chasm/.node-gyp/0.10.25/deps/uv/include/uv.h:
/home/chasm/.node-gyp/0.10.25/deps/uv/include/uv-private/uv-unix.h:
/home/chasm/.node-gyp/0.10.25/deps/uv/include/uv-private/ngx-queue.h:
/home/chasm/.node-gyp/0.10.25/deps/uv/include/uv-private/uv-linux.h:
/home/chasm/.node-gyp/0.10.25/deps/v8/include/v8.h:
/home/chasm/.node-gyp/0.10.25/deps/v8/include/v8stdint.h:
/home/chasm/.node-gyp/0.10.25/src/node_object_wrap.h:
/home/chasm/.node-gyp/0.10.25/src/node.h:
../src/wrapper.h:
../src/Box2D/Box2D.h:
../src/Box2D/Common/b2Settings.h:
../src/Box2D/Common/b2Draw.h:
../src/Box2D/Common/b2Math.h:
../src/Box2D/Common/b2Settings.h:
../src/Box2D/Common/b2Timer.h:
../src/Box2D/Collision/Shapes/b2CircleShape.h:
../src/Box2D/Collision/Shapes/b2Shape.h:
../src/Box2D/Collision/Shapes/../../Common/b2BlockAllocator.h:
../src/Box2D/Collision/Shapes/../../Common/b2Settings.h:
../src/Box2D/Collision/Shapes/../../Common/b2Math.h:
../src/Box2D/Collision/Shapes/../b2Collision.h:
../src/Box2D/Collision/Shapes/../../Common/b2Math.h:
../src/Box2D/Collision/Shapes/b2EdgeShape.h:
../src/Box2D/Collision/Shapes/b2ChainShape.h:
../src/Box2D/Collision/Shapes/b2PolygonShape.h:
../src/Box2D/Collision/b2BroadPhase.h:
../src/Box2D/Collision/../Common/b2Settings.h:
../src/Box2D/Collision/../Collision/b2Collision.h:
../src/Box2D/Collision/../Collision/b2DynamicTree.h:
../src/Box2D/Collision/../Collision/b2Collision.h:
../src/Box2D/Collision/../Collision/../Common/b2GrowableStack.h:
../src/Box2D/Collision/../Collision/../Common/b2Settings.h:
../src/Box2D/Collision/b2Distance.h:
../src/Box2D/Collision/../Common/b2Math.h:
../src/Box2D/Collision/b2DynamicTree.h:
../src/Box2D/Collision/b2TimeOfImpact.h:
../src/Box2D/Collision/b2Distance.h:
../src/Box2D/Dynamics/b2Body.h:
../src/Box2D/Dynamics/../Common/b2Math.h:
../src/Box2D/Dynamics/../Collision/Shapes/b2Shape.h:
../src/Box2D/Dynamics/b2Fixture.h:
../src/Box2D/Dynamics/../Dynamics/b2Body.h:
../src/Box2D/Dynamics/../Collision/b2Collision.h:
../src/Box2D/Dynamics/b2WorldCallbacks.h:
../src/Box2D/Dynamics/../Common/b2Settings.h:
../src/Box2D/Dynamics/b2TimeStep.h:
../src/Box2D/Dynamics/b2World.h:
../src/Box2D/Dynamics/../Common/b2BlockAllocator.h:
../src/Box2D/Dynamics/../Common/b2StackAllocator.h:
../src/Box2D/Dynamics/../Common/b2Settings.h:
../src/Box2D/Dynamics/../Dynamics/b2ContactManager.h:
../src/Box2D/Dynamics/../Dynamics/../Collision/b2BroadPhase.h:
../src/Box2D/Dynamics/../Dynamics/b2WorldCallbacks.h:
../src/Box2D/Dynamics/../Dynamics/b2TimeStep.h:
../src/Box2D/Dynamics/Contacts/b2Contact.h:
../src/Box2D/Dynamics/Contacts/../../Common/b2Math.h:
../src/Box2D/Dynamics/Contacts/../../Collision/b2Collision.h:
../src/Box2D/Dynamics/Contacts/../../Collision/Shapes/b2Shape.h:
../src/Box2D/Dynamics/Contacts/../../Dynamics/b2Fixture.h:
../src/Box2D/Dynamics/Joints/b2DistanceJoint.h:
../src/Box2D/Dynamics/Joints/b2Joint.h:
../src/Box2D/Dynamics/Joints/../../Common/b2Math.h:
../src/Box2D/Dynamics/Joints/b2FrictionJoint.h:
../src/Box2D/Dynamics/Joints/b2GearJoint.h:
../src/Box2D/Dynamics/Joints/b2MotorJoint.h:
../src/Box2D/Dynamics/Joints/b2MouseJoint.h:
../src/Box2D/Dynamics/Joints/b2PrismaticJoint.h:
../src/Box2D/Dynamics/Joints/b2PulleyJoint.h:
../src/Box2D/Dynamics/Joints/b2RevoluteJoint.h:
../src/Box2D/Dynamics/Joints/b2RopeJoint.h:
../src/Box2D/Dynamics/Joints/b2WeldJoint.h:
../src/Box2D/Dynamics/Joints/b2WheelJoint.h:
../src/HelloWorld.cpp:
