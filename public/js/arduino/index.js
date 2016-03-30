app.controller('arduino', ['$scope','$http','mySocket', function($scope,$http,mySocket){
	$scope.desligar = true;
	mySocket.on('connect', function(){
		console.log('Usuário Conectado');
		
		$scope.ligarLuz = function(){
			$scope.ligar = true;
			$scope.desligar = false;
			mySocket.emit('ligar');
		};
		$scope.apagarLuz = function(){
			$scope.desligar = true;
			$scope.ligar = false;
			mySocket.emit('desligar');
		};
		mySocket.on('Arduino',function(data){
			console.log(data);
			if(data.msg == true){
				$scope.Arduino = 'alert-success';	
				$scope.arduino = 'Conexão com Arduino ok!'
			}else{
				$scope.Arduino = 'alert-warning';	
				$scope.arduino = 'Erro na conexão com o  Arduino'
			}
		});
	})	
}])