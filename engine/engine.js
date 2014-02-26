var engine = require('./bindings/build/Release/engine');
engine.bodies = [];

function createWorld = function(gravityX, gravityY){
	engine.CreateWorld();
};

function createFixedBody( posX, posY, entity ) {

	engine.CreateDynamicBody( posX, posY);	
}

function createDynamicBody( posX, posY, entity ) {

	engine.CreateDynamicBody(
	 posX,
	 posY,
	 entity.name,
	 function () {
	 	for (var i = entity.listeners.create.length - 1; i >= 0; i--) {
	 		entity.listeners.create[i]();
	 	};
	 },
	 function (x,y) {
	 	entity.pos.x = x;
	 	entity.pos.y = y;
	 	for (var i = entity.listeners.create.length - 1; i >= 0; i--) {
	 		entity.listeners.update[i](x,y);
	 	};
	 },
	 function (myID,theirID) {
	 	for (var i = entity.listeners.collide.length - 1; i >= 0; i--) {
	 		entity.listeners.collide[i](myID, theirID);
	 	};
	 },
	 function () {
	  	for (var i = entity.listeners.destroy.length - 1; i >= 0; i--) {
	  			entity.listeners.destroy[i]
	  		};	
	  });

}

function Body(posX, posY, name, dynamic) {
	this.name = name;
	this.pos = {x: posX, y: posY, angle:0};//TODO: add angle to construction of bodies
	this.dynamic = (dynamic ? true : false);
	this.listeners = {
		create: [],
		update: [],
		collide: [],
		destroy:[]
	};
	this.bind = function ( eventName, func) {
		if (!this.listeners[eventName]) this.listeners[eventName] = [];
		this.listeners[eventName].push(func);
		return this;
	}
	this.unbind = function (eventName, func ) {
		if (!this.listeners[eventName]) 
			throw "Attempt to unbind a function from a nonexistent event-type "+eventName;
		for (var i = this.listeners[eventName].length - 1; i >= 0; i--) {
			if (func === this.listeners[eventName][i]) {
				this.listeners[eventName].splice(i,1);
			}
		};
		return this;
	}
	this.oncreate = function(func) {
		this.bind('create',func);
		return this;
	}
	this.onupdate = function(func) {
		this.bind('update',func);
		return this;
	}
	this.oncollide = function(func) {
		this.bind('collide',func);
		return this;
	}
	this.ondestroy = function(func) {
		this.bind('destroy',func);
		return this;
	}
	//apply force
	this.push = function(x,y) {
		if (!y) {
			//x == vector
		} else {
			//x,y are coords
		}
		return this;
	}
	//opposite of push
	this.pull = function(x,y) {
		this.push(-x,-y);
	}
	//offset the object
	this.move = function(x,y) {
		if(!y) {
			//x == vector
		} else {
			//x,y are coords
		}
	}
	//move to absolute coords
	this.teleport = function(x,y) {
		if(!y) {
			//x == vector
		} else {
			//x,y are coords
		}
	}
	this.addBox = function(width,height,relX,relY,name) {
		if (this.dynamic) {

		} else {

		}
	}
}

// engine.CreateWorld();
// //x,y,name
// engine.CreateDynamicBody(10,10,'ok',function(x,y) {
// 	this.x = x;
// 	this.y = y;
// 	console.log('update')
// });
// //name, width, height, x, y, angle, density, friction, restitution;
// engine.AttachBoxFixture('ok',5,5,0,0,0,1,0.3,0.1);

// engine.tick();