var io = require('socket.io');
var BISON = require('bison');
var map = require('../map.js').settings;
var userCount = 0;
exports.initialize = function(app) {
	io = io.listen(app,{log: false});
	var socketHandlers = [];
	io.sockets.on('connection', function(socket) {
		socket.broadcast.emit('welcome',BISON.encode(
			{'user':userCount++}
			));
		socket.emit('welcome',BISON.encode(
			{'user':userCount, 'settings':map}
			));
		socket = playerSocket(socket);
	});
	io.broadcast = function(message) {
		io.sockets.emit('state',BISON.encode(message));
	}
	return io;
}

function screamDisconnected() {console.log("I'm out");}
function screamError(e) {console.log("something broke",e);}
function tryFunc(func,errorHandler) {
	try {
		func();
	} catch(e) {
		errorHandler(e);
	}
}

//I have got to stop naming things like this
function handleUserInput(data) {
	var message = data;
	console.log(message);
}

function playerSocket(socket) {
	socket.on('disconnect',screamDisconnected);
	socket.on('playerUpdate',handleUserInput);
	socket.on('welcome',function(data) {
		console.log(BISON.decode(data));
	});
	return socket;
}



