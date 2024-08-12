var Connection = require('tedious').Connection;  
    var config = {  
        server: 'SNCCH04LABF09\\TEW_SQLEXPRESS.vmotion.windows.net',  
        authentication: {
            type: 'default',
            options: {
                userName: 'nicolle', 
                password: '123'  
            }
        },
        options: {
            encrypt: true,
            database: 'vmotion' 
        }
    };  
    var connection = new Connection(config);  
    connection.on('connect', function(err) {  
        console.log("Connected");  
    });
    
    connection.connect(); // deu certo
    
    var Request = require('tedious').Request  
    var TYPES = require('tedious').TYPES;  
  
    function executeStatement1() {  
        var request = new Request("INSERT SalesLT.Product (Name, ProductNumber, StandardCost, ListPrice, SellStartDate) OUTPUT INSERTED.ProductID VALUES (@Name, @Number, @Cost, @Price, CURRENT_TIMESTAMP);", function(err) {  
         if (err) {  
            console.log(err);}  
        });  
        request.addParameter('Name', TYPES.NVarChar,'SQL Server Express 2014');  
        request.addParameter('Number', TYPES.NVarChar , 'SQLEXPRESS2014');  
        request.addParameter('Cost', TYPES.Int, 11);  
        request.addParameter('Price', TYPES.Int,11);  
        request.on('row', function(columns) {  
            columns.forEach(function(column) {  
              if (column.value === null) {  
                console.log('NULL');  
              } else {  
                console.log("Product id of inserted item is " + column.value);  
              }  
            });  
        });

        // Close the connection after the final event emitted by the request, after the callback passes
        request.on("requestCompleted", function (rowCount, more) {
            connection.close();
        });
        connection.execSql(request);  
    }