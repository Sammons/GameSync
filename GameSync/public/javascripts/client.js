
function AssetManager(canvas) {
	var zmax = 2;
	var assets = {};
	var canvas = canvas;
	var context = canvas.getContext('2d');
	var assetCounter = 0;
	var renderRate = 75;
	var rendering = true;
	var renderQ = [];	

	var renderLoop = setInterval(function() {
		if (rendering) render();
	},renderRate);

	function paint() {
		for (var j = 0; j < zmax; j++) {
			for (var i in assets) {
				if (assets[i].zindex == i || i==0) {
					renderQ.push(assets[i].canvasCollection[i]);
				}
			}
		}
	}
	function render() {
		context.setTransform(1,0,0,1,0,0);
		context.clearRect(0,0,canvas.width,canvas.height);
		for (var i=0; i<renderQ.length; i++) {
			for (var j = 0; j < renderQ[i].canvasCollection.length; j++) {
				var currentCanvas = renderQ[i].canvasCollection[j];
				context.drawImage(currentCanvas,currentCanvas.relativeX(),currentCanvas.relativeY());
			};
		}
	}
	function asset() {
		this.assetId = assetCounter++;
		this.canvasCollection = [];
		this.repaint = function() {
			for (var i = 0; i < this.canvasCollection.length; i++) {
				storeCanvasAsset(this.canvasCollection[i]);
			}
		}
		return this;
	}
	function start(context,point) {
		context.moveTo(point.x,point.y);
		context.beginPath();
	}
	function end(context,point) {
		context.lineTo(point.x,point.y);
		context.close();
		context.fill();
	}
	function stroke(context,point) {
		context.lineTo(point.x,point.y);
	}
	function min(array,func) {
		var min = array[0];
		for (var i = 0; i< array.length; i++) {
			if (func(min,array[i])) min = array[i];
		}
		return min;
	}
	function max(array, func) {
		var max = array[0];
		for (var i = 0; i< array.length; i++) {
			if (!func(max,array[i])) max = array[i];
		}
		return max;
	}
	function createMiniCanvas(width,height,asset) {
		var newCanvas = document.createElement('canvas');
		asset.canvasCollection.push(newCanvas);
		newCanvas.parent = asset;
		newCanvas.width = width;
		newCanvas.height = height;
		return newCanvas;
	}
	function createRectangleShape(width,height,asset,options) {
		var newRectCanvas = createMiniCanvas(width,height,asset);
		var newRectContext = newRectCanvas.getContext('2d');
		if (options.fillStyle) newRectContext.fillStyle = options.fillStyle
		newRectContext.fillStyle = (options.color ? options.color : 'blue');
		newRectContext.fillRect(0,0,width,height);
		return newRectCanvas;
	}
	function createPolygonShape(arrayOfPoints,asset, options){
		var maxX = max(arrayOfPoints,function(a,b){return (a.x<b.x);});
		var minX = min(arrayOfPoints,function(a,b){return (a.x<b.x);});
		var maxY = max(arrayOfPoints,function(a,b){return (a.y<b.y);});
		var minY = min(arrayOfPoints,function(a,b){return (a.y<b.y);});
		var width = maxX-minX;
		var height = maxY-minY;
		var newPolyCanvas = createMiniCanvas(width,height,asset);
		var newPolyContext = newPolyCanvas.getContext('2d');
		if (options.fillStyle) newRectContext.fillStyle = options.fillStyle
		start(newPolyContext,arrayOfPoints[0]);
		for (var i = 1 ; i< arrayOfPoints.length-1; i++) {
			stroke(newRectContext,arrayOfPoints[i]);
		}
		end(newPolyContext,arrayOfPoints[arrayOfPoints.length-1]);
		return newPolyCanvas;
	}
	function createMultiShapeObject(arrayOfPointCollections, asset) {
		for (var i = 0; i < arrayOfPointCollections.length; i++) {
			createPolygonShape(arrayOfPointCollections[i],asset);
		}
		return asset;
	}
}

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
		renderBox(State.x,State.y,State.a)
	},2);

	/*  warm up rendering  */
	function renderBox(x,y,a) {
		var width = 100;
		Context.clearRect(0,0,500,500);
		Context.fillStyle='rgb(0,0,0)';
		Context.fillRect(55,500-105,10,10);
		Context.setTransform(Math.cos(a), Math.sin(a), -Math.sin(a), Math.cos(a),x,y);
		Context.fillRect(-(width/2),-2,(width/2)+10,4);
		Context.setTransform(1,0,0,1,0,0);

	}	
})

