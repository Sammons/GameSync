var WebSocketServer = require('ws').Server;
var wss = new WebSocketServer({port: 8080});


wss.on('connection', function(ws) {

    ws.send("true");

    ws.on('message', function(message) {
    	//do something
    });

    ws.on('error',function(something) {
    	ws.close();
    });
    ws.on('close',function() {
    });
});

exports.send = function(message) {
	for (var i = wss.clients.length - 1; i >= 0; i--) {
		wss.clients[i].send(message);
	};
};