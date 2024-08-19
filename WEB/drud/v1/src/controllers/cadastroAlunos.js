const aluno = require('../model/aluno'); // importa o script de criação de tabelas no swl server que está em aluno, que vai criar todas as tabelas para aluno
// const aluno = require('../model/aluno');
module.exports = {
async aluno(req, res){
res.render('../views/cadastroAluno');
},
async alunoInsert(req, res){
// Recebe as informações do front-end
// pega todos os dados do body
const dados = req.body;
// Criando sala no banco de dados
//define pelo name quais dados do body quer pegar
await aluno.create({
Nome: dados.nome,
Idade: dados.idade,
Sexo: dados.sexo,
Sala: dados.sala,
Foto: dados.foto
});
// depois de inserir o user é redirecionado a página princiapal
// Redirecionar para a página principal
res.redirect('/');
}
}
