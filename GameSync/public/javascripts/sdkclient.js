$(document).ready(function() {

console.log("connecting to server");
var socket = new WebSocket('ws://localhost:8080');
setInterval(function() {
	socket.send("keep-alive");
},10000);
socket.onmessage = function(message) {
	console.log(message.data);
};
console.log("preparing assets");

console.log("ready");
});