// tem todas as intrruções necessárias opara criar uma tabela no banco de dados
const Sequelize = require('sequelize');
const database = require('../config/db');
const sala = require('../model/sala');
const { MAX } = require('mssql');

const aluno = database.define('Aluno', {
IDAluno: {
type: Sequelize.INTEGER,
autoIncrement: true,
allowNull: false,
primaryKey: true
},
Nome: {
type: Sequelize.STRING(100),
allowNull: false
},
Idade: {
type: Sequelize.INTEGER,
allowNull: false
},
Sexo: {
type: Sequelize.STRING(20),
allowNull: false
},
Foto: {
    type: Sequelize.BLOB('long'),
    allowNull: false
    }
    });

aluno.belongsTo(sala, {
    constraint: true, //Garantir integridade referencial
    foreignKey: 'IDSala'
        });

module.exports = aluno; // exporta essas instruções
