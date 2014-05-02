var express = require('express');
var routes = require('../routes');
var http = require('http');
var app = express();

exports.initialize = function() {
	// all environments
	app.set('port',  3000);
	app.use(express.logger('dev'));
	app.use(express.json());
	app.use(express.urlencoded());
	app.use(express.methodOverride());
	app.use(app.router);
	app.use(express.static('./public'));

	app.get('/', routes.index);
	app.get('/test', routes.test);

	var server = http.createServer(app);
	server.listen(app.get('port'), function(){
	  console.log('Express server listening on port ' + app.get('port'));
	});
	return server;
}