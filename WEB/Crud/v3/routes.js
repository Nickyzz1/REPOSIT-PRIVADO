// inicnaod router express
const express = require("express");
const cadastro = require("./src/controllers/cadastro");
const route = express.Router(); 
const multer = require("multer");
const config = require('./src/config/multer');

const home = require('./src/controllers/home');

route.get('/', home.pagInicialGet);
route.post("/", home.pagInicialPost)

route.get('/cadastroSala', cadastro.sala);
route.post("/cadastroSala", cadastro.salaInsert);

route.get('/cadastroAluno', cadastro.aluno);

// route.get('/editarAluno/:id', editar.alunos);

route.post('/cadastroAluno', multer(config).single('foto'), cadastro.alunoInsert);
route.post('/cadastroAluno', cadastro.alunoInsert);

module.exports = route;

// Recebendo arquivo do multer que criamos
// Cadastro de aluno irá receber um arquivo com o "name" do HTML chamado de "foto"