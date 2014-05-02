var server 			= require('./servers/server.js').initialize();
var socketServer 	= require('./servers/socket-server.js').initialize(server);
var engine			= require('../engine/engine.js');
process.nextTick(function() {
	engine.createWorld(0,-9.8);
		var box = new engine.body(250,500,'box',true);
		box.addBoxFixture(50,4);


		var pivot = new engine.body(290,25,'pivot',false);
		pivot.addBoxFixture(50,50);
		// socketServer.broadcast({who: 'pivot', x: 250, y: 0});

		var actualFloor = new engine.body(250,0,'boundary',false);
		actualFloor.addBoxFixture(1000,2);

		box.bind('update',function(x,y,a) {
			// console.log(x,y,a);
			// console.log(x,y,a)
			socketServer.broadcast({who: 'box', 'x':x, 'y':y, 'a':a, stat: false});
		});

		setInterval(function() {
			engine.tick();
		},5);
		setInterval(function() {
			engine.update();
		},40);
});



