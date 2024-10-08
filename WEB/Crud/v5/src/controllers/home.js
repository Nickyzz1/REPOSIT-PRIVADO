const sala = require('../model/sala');
const aluno = require('../model/aluno');
module.exports = {
    //exportado essa função
    async pagInicialGet(req, res){
        const salas = await sala.findAll({
        raw: true, // sem metadados
        attributes: ['IDSala', 'Nome'] //ele pega da tabela que read
        });
        res.render('../views/index', {salas, alunos: '', id: ''}); //reenderiza essas informações na pag e manda alunos compo jnulo
    },

    async pagInicialPost(req, res){
        const id = req.body.nome;
        const alunos = await aluno.findAll({
        raw: true,
        attributes: ['IDAluno', 'Nome', 'Idade', 'Foto'],
        where: id != 0? {IDSala : id } : ''});
        const salas = await sala.findAll({ raw: true, attributes: ['IDSala', 'Nome', 'Capacidade'] });
        res.render('../views/index', {salas, alunos, id});
        },
}

// module.exports = 
// {
//     //exportado essa função
//     async pagInicialGet(req, res) 
//     {
//         res.render('../views/index'); //renderiza o index
//     }
// }
