const sequelize = require('sequelize');
// import dotenv from 'dotenv';
// import { resolve } from 'path';

// console.log('Carregando .env de:', resolve(__dirname, '../../.env'));

// dotenv.config({ path: resolve(__dirname, '../../.env') });

// console.log('DB_USER:', process.env.DB_USER);

// const sequelize = require("sequelize");

//config base de dados

const database = new sequelize('controleAlunos', 'nicolle', '235711131719', {
    dialect: 'mssql', host: 'localhost', port: 1433
});

database.sync();
module.exports = database;