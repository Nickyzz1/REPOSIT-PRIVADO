// inicnaod router express
const express = require("express");
const cadastro = require("./src/controllers/cadastro");
const route = express.Router(); 

const home = require('./src/controllers/home');

route.get('/', home.pagInicialGet);
route.post("/", home.pagInicialPost)

route.get('/cadastroSala', cadastro.sala);
route.post("/cadastroSala", cadastro.salaInsert);

route.get('/cadastroAluno', cadastro.aluno);
route.post('/cadastroAluno', cadastro.alunoInsert);

module.exports = route;