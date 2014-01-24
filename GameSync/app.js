var server 			= require('./servers/server.js').initialize();
var socketServer 	= require('./servers/socket-server.js').initialize(server);
var engine			= require('../engine/engine.js');
process.nextTick(function() {
	setTimeout(function() {
		engine.HelloWorld(function(num) {
			socketServer.broadcast({'x':num*50-50, 'y':0+40});
		});
	},1000)
});



