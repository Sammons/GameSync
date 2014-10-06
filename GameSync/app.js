var server 			= require('./servers/server.js').initialize();
var socketServer 	= require('./servers/socket-server.js').initialize(server);
var engine			= require('../engine/engine.js');
process.nextTick(function() {
	engine.createWorld(0,-9.8);

		var pivot = new engine.body(290,25,'pivot',false);
		pivot.addBoxFixture(50,50);
		// socketServer.broadcast({who: 'pivot', x: 250, y: 0});

		var actualFloor = new engine.body(250,0,'boundary',false);
		actualFloor.addBoxFixture(1000,2);

		var box_counter = 0;
		server.app.get('/create/:x/:y',function(req,res){
					box_counter++;
					var box = new engine.body(req.params.x/1,req.params.y/1,'box-'+box_counter,true);
					box.addBoxFixture(50,4);
					res.end();
		})

		setInterval(function() {
			engine.tick();
		},5);
		setInterval(function() {
			engine.update();
			socketServer.broadcast(engine.bodies);
		},40);
});



