// inicnaod router express
const express = require("express");
const route = express.Router(); 

// importando controlers

const home = require('./src/controllers/home');

// inicinando as rotas
// o barra significa index
route.get('/', home.pagInicialGet);

module.exports = route;

const cadastro = require("./src/controllers/cadastro");
route.post("/cadastroSala", cadastro.salaInsert)