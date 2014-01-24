var engine = require('./bindings/build/Release/engine');

exports.HelloWorld = function(callback) {
	engine.HelloWorld(callback);
}