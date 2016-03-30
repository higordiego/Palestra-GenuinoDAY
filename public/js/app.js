var app = angular.module('app',['btford.socket-io']);

app.factory('mySocket', function (socketFactory) {
  return socketFactory();
});
