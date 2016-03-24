module.exports = function(app){
	var indexController = {
		index: function(req,res){
			res.render('index');
		}
	};
	return indexController;
}