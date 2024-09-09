USE db_highway;
-- nome, cpf, email,dt_nascimento, tipo_acesso
-- cria conta

call createAccount("maria", "12345678900", "maria@email.com", '2016-02-12', 2);
select * from tb_usuario; -- 11

-- criar endereço
-- pc_cep int, pc_numero int, pc_complemento varchar(255);
call createAdress(81350668, 84, 'nada');
select * from tb_endereco; -- 1

-- criar hamburguer
-- cod_pao, cod_carne, cod_salada, cod_molho, cod_queijo, obs
call createHamburguer(1,1,1,1,1, "sem molho");
select * from tb_hamburguer; -- 1

-- tabelas
select * from tb_pao;
select * from tb_queijo;
select * from tb_adicional;
select * from tb_produto;
select * from tb_molho;
select * from tb_salada ;
select * from tb_carne;
select * from tb_hamburguer;

-- criar pedido
-- usuario int, endereco int, total decimal, obs
call createPedido(11,1, 0, 'alergico a molho picante');
select * from tb_pedido;

-- relaciona o hamburguer com o pedido
-- cod_pedido int, cod_hamburguer int, quantidade int
call pedidoHamburguer(1, 1, 2);
select * from tb_hamburguer;

-- mostra tds os pedidos do usuário;
-- parametro é o user
call pc_pedidos(11);
