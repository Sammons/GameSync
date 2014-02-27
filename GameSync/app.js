var server 			= require('./servers/server.js').initialize();
var socketServer 	= require('./servers/socket-server.js').initialize(server);
var engine			= require('../engine/engine.js');
process.nextTick(function() {
		engine.createWorld(0,-9.8);
		var box = new engine.body(55,500,'box',true);
		box.addBoxFixture(50,4);

		var floor = new engine.body(50,100,'floor',false);
		floor.addBoxFixture(1,1);

		var actualFloor = new engine.body(250,0,'boundary',false);
		actualFloor.addBoxFixture(250,2);

		box.bind('update',function(x,y,a) {
			console.log(x,y,a);
			socketServer.broadcast({'x':x, 'y':500-y, 'a':a});
		});

		setInterval(function() {
			engine.tick();
		},5);
		setInterval(function() {
			engine.update();
		},40);
});



