var server 			= require('./servers/server.js').initialize();
var socketServer 	= require('./servers/socket-server.js').initialize(server);
var engine			= require('../engine/engine.js');
process.nextTick(function() {
	setTimeout(function() {
		engine.HelloWorld(function(num) {
			socketServer.broadcast({'y':-num*50+500, 'x':0+40});
		});
	},2000)
});



