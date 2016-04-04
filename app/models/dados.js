module.exports = function(app){
	var mongoose = require('mongoose')
	,	Schema = mongoose.Schema;

	var dados = new Schema(
	{
		serial: 	{ type: String, required: true},
		created_at: { type: Date, default: Date.now },
		updated_at: { type: Date, default: Date.now }
	}
	);
	return mongoose.model('Dados', dados);
	
}