// var Connection = require('tedious').Connection;  
//     var config = {  
//     server: 'SNCCH04LABF09\\TEW_SQLEXPRESS.vmotion.windows.net',  
//      authentication: {
//                  type: 'default',
//          options: {
//              userName: 'nicolle', 
//              password: '123'  
//          }
//         },
//         options: {
           
//             encrypt: true,
//             database: 'vmotion'  //update me
//         }
//     };  
//     var connection = new Connection(config);  
//     connection.on('connect', function(err) {  
//         // If no error, then good to proceed.
//         console.log("Connected");  
//     });
    
//     connection.connect();



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
                database: 'vmotion'  //update me
            }
        };  
    var connection = new Connection(config);  
    connection.on('connect', function(err) {  
        // If no error, then good to proceed.  
        console.log("Connected");  
        executeStatement();  
    });  
    
    connection.connect();
  
    var Request = require('tedious').Request;  
    var TYPES = require('tedious').TYPES;  
  
    function executeStatement() {  
        var request = new Request("SELECT * cadastrados;", function(err) {  
        if (err) {  
            console.log(err);
        }});  
        const result = "";  
        request.on('row', function(columns) {  
            columns.forEach(function(column) {  
              if (column.value === null) {  
                console.log('NULL');  
              } else {  
                result+= column.value + " ";  
              }  
            });  
            console.log(result);  
            result ="";  
        });  
  
        request.on('done', function(rowCount, more) {  
        console.log(rowCount + ' rows returned');  
        });  
        
        // Close the connection after the final event emitted by the request, after the callback passes
        request.on("requestCompleted", function (rowCount, more) {
            connection.close();
        });
        connection.execSql(request);  
    }


    // var Connection = require('tedious').Connection;  
    // var config = {  
    //     server: 'your_server.database.windows.net',  //update me
    //     authentication: {
    //         type: 'default',
    //         options: {
    //             userName: 'your_username', //update me
    //             password: 'your_password'  //update me
    //         }
    //     },
    //     options: {
    //         // If you are on Microsoft Azure, you need encryption:
    //         encrypt: true,
    //         database: 'your_database'  //update me
    //     }
    // }; 
    // var connection = new Connection(config);  
    // connection.on('connect', function(err) {  
    //     // If no error, then good to proceed.  
    //     console.log("Connected");  
    //     executeStatement();  
    // });  
    
    // connection.connect();
  
    // var Request = require('tedious').Request;  
    // var TYPES = require('tedious').TYPES;  
  
    // function executeStatement() {  
    //     var request = new Request("", function(err) {  
    //     if (err) {  
    //         console.log(err);}  
    //     });  
    //     var result = "";  
    //     request.on('row', function(columns) {  
    //         columns.forEach(function(column) {  
    //           if (column.value === null) {  
    //             console.log('NULL');  
    //           } else {  
    //             result+= column.value + " ";  
    //           }  
    //         });  
    //         console.log(result);  
    //         result ="";  
    //     });  
  
    //     request.on('done', function(rowCount, more) {  
    //     console.log(rowCount + ' rows returned');  
    //     });  
        
    //     // Close the connection after the final event emitted by the request, after the callback passes
    //     request.on("requestCompleted", function (rowCount, more) {
    //         connection.close();
    //     });
    //     connection.execSql(request);  
    // }



// var Connection = require('tedious').Connection;  
// var config = {  
//     server: 'SNCCH04LABF09\\TEW_SQLEXPRESS.vmotion.windows.net',  
//     authentication: {
//         type: 'default',
//         options: {
//             userName: 'nicolle', 
//             password: '123'  
//         }
//     },
//     options: {
//         encrypt: true,
//         database: 'vmotion'  // Atualize aqui com o nome do seu banco de dados
//     }
// }; 

// var connection = new Connection(config);  

// connection.on('connect', function(err) {  
//     if (err) {
//         console.error('Connection failed', err);
//         return;
//     }
//     console.log("Connected");  
//     executeStatement();  
// });  

// connection.connect();

// var Request = require('tedious').Request;  
// var TYPES = require('tedious').TYPES;  

// function executeStatement() {  
//     var request = new Request("SELECT * FROM cadastros;", function(err) {  
//         if (err) {  
//             console.log(err);
//         }  
//     });  

//     var result = "";  
//     request.on('row', function(columns) {  
//         columns.forEach(function(column) {  
//             if (column.value === null) {  
//                 console.log('NULL');  
//             } else {  
//                 result += column.value + " ";  
//             }  
//         });  
//         console.log(result);  
//         result = "";  
//     });  

//     request.on('done', function(rowCount, more) {  
//         console.log(rowCount + ' rows returned');  
//     });  

//     // Fechar a conexão após a finalização da requisição
//     request.on("requestCompleted", function (rowCount, more) {
//         connection.close();
//     });

//     connection.execSql(request);  
// }


// var Connection = require('tedious').Connection;  
//     var config = {  
//         server: 'SNCCH04LABF09\\TEW_SQLEXPRESS.vmotion.windows.net',  
//         authentication: {
//             type: 'default',
//             options: {
//                 userName: 'nicolle', 
//                 password: '123'  
//             }
//         },
//         options: {
//             // If you are on Microsoft Azure, you need encryption:
//             encrypt: false,
//             database: 'vmotion' 
//         }
//     }; 
//     var connection = new Connection(config);  
//     connection.on('connect', function(err) {  
//         // If no error, then good to proceed.  
//         console.log("Connected");  
//         executeStatement();  
//     });  
    
//     connection.connect();
  
//     var Request = require('tedious').Request;  
//     var TYPES = require('tedious').TYPES;  
  
//     function executeStatement() {  
//         var request = new Request("SELECT * FROM cadastros;", function(err) {  
//         if (err) {  
//             console.log('erro no cadastro')
//             console.log(err);}
//             console.log('1')  
//         });
//         console.log('chegou aqui');
//         var result = "";  
//         request.on('row', function(columns) {  
//             columns.forEach(function(column) {  
//               if (column.value === null) {  
//                 console.log('NULL');  
//               } else {  
//                 result+= column.value + " ";  
//               }  
//             });  
//             console.log(result);  
//             result =""; 
//             console.log('erro na leitura') 
//         });  
  
//         request.on('done', function(rowCount, more) {  
//         console.log(rowCount + ' rows returned');  
//         });  
//          console.log('1')  
        
//         // Close the connection after the final event emitted by the request, after the callback passes
//         request.on("requestCompleted", function (rowCount, more) {
//             console.log('erro na conexão')
//             connection.close();
//         });
//         connection.execSql(request);  
//     }

//     executeStatement();

// var Connection = require('tedious').Connection;  
//     var config = {  
//         server: 'SNCCH04LABF09\\TEW_SQLEXPRESS.vmotion.windows.net',  
//         authentication: {
//             type: 'default',
//             options: {
//                 userName: 'nicolle', 
//                 password: '123'  
//             }
//         },
//         options: {
//             encrypt: true,
//             database: 'vmotion' 
//         }
//     };  
//     var connection = new Connection(config);  
//     connection.on('connect', function(err) {  
//         console.log("Connected");
//         console.log("está conctando")
//     });

//     connection.connect(); // deu certo ETAPA 1
    
//     console.log("etapa 1 concluida")
  
//     var Request = require('tedious').Request; //etapa 2 
//     console.log("conectado")
//     var TYPES = require('tedious').TYPES;  
  
//     function executeStatement() {  
//         var request = new Request("SELECT * FROM cadastros;", function(err) {  
//         if (err) {  
//             console.log(err);}  
//         });  
//         var result = "";
//         console.log("A requisição" + request)  
//         request.on('row', function(columns) {  
//             columns.forEach(function(column) {  
//               if (column.value === null) {  
//                 console.log('NULL');  
//               } else {  
//                 result+= column.value + " ";  
//               }  
//             });  
//             console.log(result);  
//             result ="";  
//         });  
  
//         request.on('done', function(rowCount, more) {  
//         console.log(rowCount + ' rows returned');  
//         });  
        
//         // Close the connection after the final event emitted by the request, after the callback passes
//         request.on("requestCompleted", function (rowCount, more) {
//             connection.close();
//         });
//         connection.execSql(request);  
//     } 
    
//     executeStatement();
    
    // var Request = require('tedious').Request //etAPA 3  
    // var TYPES = require('tedious').TYPES;  
  
    // function executeStatement1() {  
    //     var request = new Request("INSERT SalesLT.Product (Name, ProductNumber, StandardCost, ListPrice, SellStartDate) OUTPUT INSERTED.ProductID VALUES (@Name, @Number, @Cost, @Price, CURRENT_TIMESTAMP);", function(err) {  
    //      if (err) {  
    //         console.log(err);}  
    //     });  
    //     request.addParameter('Name', TYPES.NVarChar,'SQL Server Express 2014');  
    //     request.addParameter('Number', TYPES.NVarChar , 'SQLEXPRESS2014');  
    //     request.addParameter('Cost', TYPES.Int, 11);  
    //     request.addParameter('Price', TYPES.Int,11);  
    //     request.on('row', function(columns) {  
    //         columns.forEach(function(column) {  
    //           if (column.value === null) {  
    //             console.log('NULL');  
    //           } else {  
    //             console.log("Product id of inserted item is " + column.value);  
    //           }  
    //         });  
    //     });

    //     // Close the connection after the final event emitted by the request, after the callback passes
    //     request.on("requestCompleted", function (rowCount, more) {
    //         connection.close();
    //     });
    //     connection.execSql(request);  
    // }
