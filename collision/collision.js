var collision = require('./bindings/build/Release/collision');
module.exports.initialize = function() {
	this.initialized = true;
	collision.initialize();
};
module.exports.destroy = function() {
	this.initialized = false;
	collision.destroy();
};

module.exports.add = function(segment,cb) {
};
module.exports.move = function(segment,cb) {
};
module.exports.remove = function(segment,cb) {
};
