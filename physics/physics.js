var physics = require('./bindings/build/Release/physics');
exports.initialize = function(collisionSystem) {
	physics.initialize();
}