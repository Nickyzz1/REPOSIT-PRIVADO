const Conection = require('tedious'). Connection;

const config = {
    

}

const connection = new Connection(config);

connection.connect();
