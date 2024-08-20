const aluno = require('../model/aluno');
// const aluno = require('../model/aluno');
module.exports = {
async aluno(req, res){
res.render('../views/cadastroAluno');
},
async alunoInsert(req, res){
// Recebe as informações do front-end
const dados = req.body;
// Criando sala no banco de dados
await aluno.create({
Nome: dados.nome,
Idade: dados.idade,
Sexo: dados.sexo,
Sala: dados.sala,
Foto: dados.foto
});
// Redirecionar para a página principal
res.redirect('/');
}
}