
var fs = require('fs');
var index = fs.readFileSync('./views/index.html');
var test = fs.readFileSync('./views/test.html');

exports.index = function(req, res){
	res.end(index);
};
exports.test = function(req, res) {
	res.end(test);
};