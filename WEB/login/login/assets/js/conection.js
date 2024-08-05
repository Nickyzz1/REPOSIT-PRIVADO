const config = {
    user: '', // Deixe vazio para autenticação do Windows
    password: '', // Deixe vazio para autenticação do Windows
    server: 'NOME_DO_SEU_SERVIDOR',
    database: 'NOME_DA_SUA_BASE_DE_DADOS',
    options: {
      encrypt: false, // Use `true` se estiver usando Azure
      enableArithAbort: true,
      trustedConnection: true // Habilita a autenticação do Windows
    }
  };
  
  module.exports = config;
  