// inicnaod router express
const express = require("express");
const route = express.Router(); 

// importando controlers

const home = require('./src/controllers/home');

// inicinando as rotas
// o barra significa index
route.get('/', home.pagInicialGet);

const cadastro = require("./src/controllers/cadastro");
const cadastroAluno = require("./src/controllers/cadastroAlunos");

route.get('/cadastroSala', cadastro.sala);
route.post("/cadastroSala", cadastro.salaInsert);

route.get('/cadastroAluno', cadastroAluno.aluno);
route.post('/cadastroAluno', cadastroAluno.alunoInsert);

module.exports = route;