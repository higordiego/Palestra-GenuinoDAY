module.exports = function(app){
	var Dados = app.models.dados;
	var indexController = {
		index: function(req,res){
			res.render('index');
		},
		proximo: function(req,res){
			res.render('replicacao');
		},
		fim: function(req,res){
			res.render('fim');
		},
		listar: function(req,res){
			Dados.find(function(err,d){
				res.json(d)
			}).sort(1000);

		}

	};
	return indexController;
}