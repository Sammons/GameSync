
$(document).ready(function() {
	var socket = io.connect('http://162.243.131.246:8000');
	var Settings = {};
	var Canvas = document.getElementById('canvas');
	var Context = Canvas.getContext('2d');
	// $(Canvas).rotate(180);
	socket.on('welcome',function(data) {
		Settings = BISON.decode(data).settings;
		socket.emit('welcome',BISON.encode({'response':'thanks!'}));
		console.log('settings given',Settings);
		Canvas.width = Settings.width;
		Canvas.height = Settings.height;
	})

	var State = {objects: []};//contains everything =)
	socket.on('state',function(data){
		stateupdates = BISON.decode(data);
		State.objects =[];
		for (var i in stateupdates) {
			State.objects.push (stateupdates[i]);
		};
	});

	setInterval(function() {
		Context.setTransform(1,0,0,1,0,0);
		Context.clearRect(0,0,500,500);
		for (var i in State.objects) {
			var o = State.objects[i];
			renderBox(o.pos.x, o.pos.y, o.pos.a, o.width, o.height);
		}
	},5);

	/*  warm up rendering  */
	function renderBox(x,y,a, width, height) {
		Context.fillStyle = 'rgb(0,0,0)';
		a=-a;
		Context.setTransform(Math.cos(a), Math.sin(a), -Math.sin(a), Math.cos(a),x,500-y);
		Context.fillRect(-width/2,-height/2,width,height);
	}	
})

