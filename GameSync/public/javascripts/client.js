window.messages = {};

$(document).ready(function() {
	try {//initialize websocket connection
		var socket = new WebSocket('ws://localhost:8080');
	} catch (e) {
		console.log('websocket failed to connect', e);
	}
setInterval(function() {
	socket.send("keep-alive");
},10000);
socket.onmessage = function(message) {
	console.log(message.data);
};
});