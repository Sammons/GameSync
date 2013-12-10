var engine = require('./bindings/build/Release/engine');

engine.initialize(500,500,0,1000,function() {
//cleanup
});

 var addShape = function(shape) {
 	var collisionHandler = function(type) {
 		console.log("crap I hit something:", type);
 	};
 	engine.addShape(shape.x,shape.y,0,collisionHandler,function(id) {
 		shape.id = id;
 		console.log("shape added ",id);
 	});
 }
 var i = {};
 i.x = 7.5;
 i.y = 7.5;
 i.angle = 0;
 addShape(i);
 i.x = 50;
 i.y = 7.5;
 addShape(i);
// 	//create object
// 	engine.addShape(shape.id,shape.x,shape.y,shape.onCollision);
// 	//populate it
// 	for (var i = shape.segments.length - 1; i >= 0; i--) {
// 		var seg = shape.segments[i];
// 		engine.addSegment(shape.id,seg.x1,seg.y1,seg.x2,seg.y2);
// 	};
// };

// //move shape
// var updateShape = function(shape,coord) {

// }

// //delete shape from collision scene
// var removeShape = function(shape) {
// 	engine.removeShape(shape.id);
// };

