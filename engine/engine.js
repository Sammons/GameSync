var engine = require('./bindings/build/Release/engine');
engine.bodies = [];

function createWorld (gravityX, gravityY){
	engine.CreateWorld();
};

function createFixedBody( entity ) {

	engine.CreateFixedBody(
	 entity.pos.x,
	 entity.pos.y,
	 entity.name,
	 function () {
	 	entity.trigger('create');
	 },
	 function (x,y) {
	 	entity.pos.x = x;
	 	entity.pos.y = y;
	 	entity.trigger('update',x,y);
	 },
	 function (myID,theirID) {
 		entity.trigger('collide',myID,theirID);
	 },
	 function () {
		entity.trigger('destroy');
	  });
}

function createDynamicBody(entity ) {

	engine.CreateDynamicBody(
	 entity.pos.x,
	 entity.pos.y,
	 entity.name,
	 function () {
	 	entity.trigger('create');
	 },
	 function (x,y) {
	 	entity.pos.x = x;
	 	entity.pos.y = y;
	 	entity.trigger('update',x,y);
	 },
	 function (myID,theirID) {
 		entity.trigger('collide',myID,theirID);
	 },
	 function () {
		entity.trigger('destroy');
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
	this.trigger = function(eventName) {
		for (var i in this.listeners[eventName]) {
			//pass all but first arg
			this.listeners[eventName][i].apply(this,Array.prototype.slice.call(arguments,1));
		}
	}
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
	this.addBoxFixture = function(width,height) {
		//TODO rendering is affected by this
		if (this.dynamic) {
			engine.AttachDynamicBoxFixture(
				this.name,
				width,
				height,
				0,0,0,1,0.3,0.3);
		} else {
			engine.AttachFixedBoxFixture(this.name,width,height)
		}
	}
	if (this.dynamic==true)createDynamicBody(this);
	else createFixedBody(this);
}


function Tick_Update() {
	
	engine.Tick();
}

engine.CreateWorld(0,-10);
//x,y,name
var newBox = new Body(5,20,'first',true);
newBox.addBoxFixture(20,1)

var floor = new Body(0,-10,'floor',false);
floor.addBoxFixture(1,5);
floor.onupdate(function(x,y) {
	//console.log(x,y);
})
newBox.onupdate(function(x,y) {
	console.log(x,y);
});
for (var i = 500- 1; i >= 0; i--) {
	Tick_Update();
	if (i%20==0) engine.Update();
};