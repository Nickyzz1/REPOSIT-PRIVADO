const config = {
    user: '', // Deixe vazio para autenticação do Windows
    password: '', // Deixe vazio para autenticação do Windows
    server: 'DESKTOP-UE8GTGU\\MSSQLSERVEROF',
    database: 'vmotion',
    options: {
      encrypt: false, // Use `true` se estiver usando Azure
      enableArithAbort: true,
      trustedConnection: true // Habilita a autenticação do Windows
    }
  };
  
module.exports = config;
  