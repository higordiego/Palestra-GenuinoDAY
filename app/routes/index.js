module.exports = function(app){
	var index = app.controllers.index;
	app.get('/', index.index);
	app.get('/proximo', index.proximo);
	app.get('/fim', index.fim);
	app.get('/listar', index.listar);
}