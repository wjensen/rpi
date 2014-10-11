console.log('starting up')
var http = require('http');
var SerialPort = require('serialport').SerialPort;
var serialport = new SerialPort('/dev/ttyACM0' { baudRate: 9600} )

http.createServer( function(req,res) {
	serialport.on('open', function(){
		console.log('serial port opened');
		serialport.on('data',function(data){
			console.log(data[0])
			var currentTime = new Date();
			console.log('Client called at '+currentTime);

   			res.writeHead(200, {'Content-Type':'text/plain'});
   			res.write('The temperature is' + data[0]);
   			//res.write('Enjoy the Beach !\n');
   			res.end();
		});
	});
   
   

}).listen('3000');