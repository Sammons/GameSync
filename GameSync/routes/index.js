
/*
 * GET home page.
 */
var fs = require('fs');
var index = fs.readFileSync('./views/index.html');

exports.index = function(req, res){
  res.end(index);
};