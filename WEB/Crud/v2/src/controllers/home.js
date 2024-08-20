const sala = require('../model/sala');
const aluno = require('../model/aluno');
module.exports = {
    //exportado essa função
    async pagInicialGet(req, res){
        const salas = await sala.findAll({
        raw: true,
        attributes: ['IDSala', 'Nome']
        });
        res.render('../views/index', {salas, alunos: ' ', id: ''});
    },

    async pagInicialPost(req, res){

        const id = req.body.nome;
        
        const alunos = await aluno.findAll({
        raw: true,
        attributes: ['IDAluno', 'Nome', 'Idade', 'Foto'],
        where: { IDSala: id }});
        const salas = await sala.findAll({ raw: true, attributes: ['IDSala', 'Nome'] });
        res.render('../views/index', {salas, alunos, id});
    }
}

// module.exports = 
// {
//     //exportado essa função
//     async pagInicialGet(req, res) 
//     {
//         res.render('../views/index'); //renderiza o index
//     }
// }
