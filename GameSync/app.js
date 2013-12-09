var server 			= require('./servers/server.js');
var socketServer 	= require('./servers/socket-server.js')
var collision 		= require('collision');
var physics			= require('physics');

collision.initialize();
physics.initialize(collision);