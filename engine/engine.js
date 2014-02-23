var engine = require('./bindings/build/Release/engine');

exports.HelloWorld = function(callback) {
	engine.HelloWorld(callback);
};


exports.createWorld = function(gravityX, gravityY){
	engine.initWorld(gravityX,gravityY);
};

function createFixedBody(posX,posY) {
	var body = {};
	return body;
}

function createDynamicBody(posX,posY) {

}

exports.createBox = function(posX,posY,width,height) {

};

exports.createBox = function(posX,posY,friction,density) {

}

engine.CreateWorld();
//x,y,name
engine.CreateDynamicBody(10,10,'ok');
//name, width, height, x, y, angle, density, friction, restitution;
engine.AttachBoxFixture('ok',5,5,0,0,0,1,0.3,0.1);