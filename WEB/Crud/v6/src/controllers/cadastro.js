const sala = require('../model/sala');
const aluno = require('../model/aluno');
const DataBase = require('../config/db');
// const aluno = require('../model/aluno');
module.exports = {
    //req (Requisição) é o que o back-end recebe do front;
    //res (Resposta) é o que o back-end retorna para o front;

    // get
    async sala(req, res){
        res.render('../views/cadastroSala'); //r enderiza uma págimna
    },


// post geralmente o post coloca algo no sql
    async salaInsert(req, res){
    // Recebe as informações do front-end
    const dados = req.body;
    // Criando sala no banco de dados
    await sala.create({
    Nome: dados.nome,
    Capacidade: dados.capacidade

    }); //post tem informações da requisição 

    // Redirecionar para a página principal
    res.redirect('/');
    },

    async aluno(req, res) {
        const salas = await sala.findAll({
            raw: true,
            attributes: ['IDSala', 'Nome']
        });
        const results = await DataBase.query(`
        SELECT
        s.IDSala,
        s.Nome,
        s.Capacidade - count(a.IDAluno) as Vagas
        FROM 
        Alunos as a
        RIGHT JOIN Salas as s
        ON s.IDSala = a.IDSala
        group by s.IDSala, s.Capacidade, s.Nome
        having s.Capacidade - count(a.IDAluno)!= 0;
        `, {type: DataBase.SELECT, raw: true});

        res.render('../views/cadastroAluno', {salas, results})
    }, // uma get existente para onde eu preciso

    //post para o slq
    async alunoInsert(req, res){
        // Recebendo as informações pelo Body
        const dados = req.body;
        // Nome padrão da foto
        let foto = 'usuario.png';
        // Verificando se foi enviada alguma foto
        if (req.file) {
        // Pegar novo nome da foto
        foto = req.file.filename;
        }
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