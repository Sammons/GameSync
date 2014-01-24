$(document).ready(function() {
	var socket = io.connect('http://localhost:3000');
	var Settings = {};
	var Canvas = document.getElementById('canvas');
	var Context = Canvas.getContext('2d');

	socket.on('welcome',function(data) {
		Settings = BISON.decode(data).settings;
		socket.emit('welcome',BISON.encode({'response':'thanks!'}));
		console.log('settings given',Settings);
		Canvas.width = Settings.width;
		Canvas.height = Settings.height;
	})

	var State = {};//contains everything =)
	socket.on('state',function(data){
		stateupdates = BISON.decode(data);
		for (var i in stateupdates) {
			State[i] = stateupdates[i];
		};
	});

	setInterval(function() {
		console.log(State);
		renderBox(State.x,State.y)
	},2);

	/*  warm up rendering  */
	function renderBox(x,y) {
		Context.clearRect(0,0,500,500);
		Context.fillStyle='rgb(0,0,0)';
		Context.fillRect(x,y,10,10);
	}	
})
