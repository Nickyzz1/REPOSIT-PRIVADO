// inicnaod router express
const express = require("express");
const cadastro = require("./src/controllers/cadastro");
const home = require('./src/controllers/home');
const editar = require("./src/controllers/editar");

const route = express.Router(); 
const multer = require("multer");
const config = require('./src/config/multer');

route.get('/', home.pagInicialGet);
route.post("/", home.pagInicialPost)

route.get('/cadastroSala', cadastro.sala);
route.post("/cadastroSala", cadastro.salaInsert);

route.get('/cadastroAluno', cadastro.aluno);

// route.get('/editarAluno/:id', editar.alunos);

route.post('/cadastroAluno', multer(config).single('foto'), cadastro.alunoInsert);
// route.post('/cadastroAluno', cadastro.alunoInsert);

// editar alunos
route.get('/editarAluno/:id', editar.alunos);
route.post('/editarAluno/:id', multer(config).single('foto'), editar.adicionar);

route.get('/editarSala/:id', editar.salas);
route.post('/editarSala/:id', editar.adicionarSala);

module.exports = route;

// Recebendo arquivo do multer que criamos
// Cadastro de aluno irá receber um arquivo com o "name" do HTML chamado de "foto"