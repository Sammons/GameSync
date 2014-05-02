var server 			= require('./servers/server.js').initialize();
var socketServer 	= require('./servers/socket-server.js').initialize(server);
var engine			= require('../engine/engine.js');
process.nextTick(function() {
});



