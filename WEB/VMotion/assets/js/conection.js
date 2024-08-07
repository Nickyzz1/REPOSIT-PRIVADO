const sql = require('mssql');

const config = {
    user: '', // Deixe vazio para autenticação do Windows
    password: '', // Deixe vazio para autenticação do Windows
    server: 'DESKTOP-UE8GTGU\\MSSQLSERVEROF', // Nome do servidor e instância
    database: 'vmotion',
    options: {
        encrypt: false, // Altere para `true` se estiver usando Azure
        enableArithAbort: true,
        trustedConnection: true // Habilita autenticação do Windows
    }
};

sql.connect(config).then(pool => {
    return pool.request()
        .query('select 1 as number')
}).then(result => {
    console.dir(result)
}).catch(err => {
    console.error('Erro ao conectar ao SQL Server:', err)
});
