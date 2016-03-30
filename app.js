var express           = require('express')
,   path              = require('path')
,   favicon           = require('serve-favicon')
,   logger            = require('morgan')
,   cookieParser      = require('cookie-parser')
,   bodyParser        = require('body-parser')
,   cors              = require('cors')
,   validator         = require('express-validator')
,   compression       = require('compression')
,   load              = require('express-load')
,   app               = express();



app.use(function(req, res, next){
   res.setHeader("Cache-Control", "public, max-age=2592000");//Cache de 1 dia
   res.setHeader("Expires", new Date(Date.now() + 2592000000).toUTCString());
   next();
});

// view engine setup
app.set('views', path.join(__dirname, 'app/views'));
app.set('view engine', 'jade');

// uncomment after placing your favicon in /public
//app.use(favicon(path.join(__dirname, 'public', 'favicon.ico')));
app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
app.use(validator());
app.use(cors());
app.use(compression());

load('models',{cwd: 'app'})
.then('controllers')
.then('routes')
.then('config')
.into(app);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});

// error handlers

// development error handler
// will print stacktrace
if (app.get('env') === 'development') {
  app.use(function(err, req, res, next) {
    res.status(err.status || 500);
    res.render('error', {
      message: err.message,
      error: err
    });
  });
}

// production error handler
// no stacktraces leaked to user
app.use(function(err, req, res, next) {
  res.status(err.status || 500);
  res.render('error', {
    message: err.message,
    error: {}
  });
});


module.exports = app;
