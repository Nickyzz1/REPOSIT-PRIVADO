const sala = require('../model/sala');
const aluno = require('../model/aluno');
// const aluno = require('../model/aluno');
module.exports = {

    async sala(req, res){
    res.render('../views/cadastroSala');
    },

    async salaInsert(req, res){
    // Recebe as informações do front-end
    const dados = req.body;
    // Criando sala no banco de dados
    await sala.create({
    Nome: dados.nome,
    Capacidade: dados.capacidade

    });

    // Redirecionar para a página principal
    res.redirect('/');
    },

    async aluno(req, res) {
        const salas = await sala.findAll({
            raw: true,
            attributes: ['IDSala', 'Nome']
        });

        res.render('../views/cadastroAluno', {salas})
    },

    async alunoInsert(req, res){
        // Recebendo as informações pelo Body
        const dados = req.body;
        // Nome padrão da foto
        let foto = 'usuario.png';
        // Criando aluno no banco de dados
        await aluno.create({
        Nome: dados.nome,
        Idade: dados.idade,
        Sexo: dados.sexo,
        IDSala: dados.salaInput,
        Foto: foto
        });
        // Redirecionar para a página principal
        res.redirect('/');
    }
}