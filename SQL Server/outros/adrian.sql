show databases; use oficina;
show tables;

select * from veiculo;
select * from cliente;
select * from servico;
select * from ordem_de_servico;
select * from DETALHE_SERVICO;

SHOW CREATE TABLE ordem_de_servico;
SHOW CREATE TABLE cliente;

ALTER TABLE ordem_de_servico DROP COLUMN observacoes_adicionais;
ALTER TABLE ordem_de_servico DROP FOREIGN KEY ordem_de_servico_ibfk_3;
ALTER TABLE ordem_de_servico DROP COLUMN id_servico;

CREATE TABLE DETALHE_SERVICO(
id int not null primary key,
idordem_servico int,
idservico int,
foreign key (idordem_servico) references ordem_de_servico(id),
foreign key (idservico) references servico(id)
);

insert into veiculo(id, marca, ano, modelo, placa) values(1, "Ford",  2018, "Fiesta", "ABC-1234");
insert into cliente(rg, nome, telefone, endereco, id_veiculo) values('1111',"João Silva", 123456789, "Rua A 123 Cidade X", 1);
insert into servico(id, descricao, preco, servico_tipo) values(1, "Troca de óleo", 150.00, " ");
insert into ordem_de_servico(id, data_entrada, data_saida, status_ordem, id_veiculo) values(1, "2024-07-15", "2024-07-16", "Concluída", 1);
insert into DETALHE_SERVICO(id, idordem_servico, idservico) VALUES(100, 1, 1);



João Silva, 123456789, Rua A, 123, Cidade X

João Silva, Ford, Fiesta, 2018, ABC-1234

Troca de óleo, 150.00

João Silva, Ford Fiesta, 2024-07-15, 2024-07-16, Concluída, Troca de
óleo e filtro

João Silva, Chevrolet Onix, 2024-07-25, NULL, Em andamento, Revisão
periódica e alinhamento

João Silva, Ford Fiesta, Troca de óleo, 5 litros

/*
criar coluna
ALTER TABLE ordem_de_servico ADD COLUMN id_cliente INT;

retirando fk restricao:

ALTER TABLE ordem_de_servico DROP FOREIGN KEY ordem_de_servico_ibfk_1;

add fk
ALTER TABLE ordem_de_servico
ADD CONSTRAINT fk_id_cliente
FOREIGN KEY (id_cliente) REFERENCES clientes(id)
ON DELETE CASCADE
ON UPDATE CASCADE; */


