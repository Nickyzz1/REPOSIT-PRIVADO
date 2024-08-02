create database db_aula; use db_aula;

create table tb_boschinhos(
id int not null primary key auto_increment,
nome varchar(60),
datanascimento datetime
)default charset utf8mb4; -- ddl

create table setor(
id int not null primary key auto_increment,
nome varchar(60)
)default charset utf8mb4; -- ddl

insert into tb_boschinhos(nome, datanascimento) values("ni", '2006-02-26');
insert into tb_boschinhos(id, nome, datanascimento) values(default, "sasa", "2004-10-27");
insert into tb_boschinhos(id, nome, datanascimento) values(default, "sasa", "2004-10-01");
insert into tb_boschinhos(id, nome, datanascimento) values(default, "fer", "2005-01-03");

insert into setor(id, nome) values(default, "ETS");
insert into setor(id, nome) values(default, "RH");

-- adc uma fk
alter table tb_boschinhos add column idSetor int, add foreign key (idSetor) references setor(id);

update tb_boschinhos set idSetor = 1 where id > 0;

show tables;

select * from setor;
select * from tb_boschinhos;

select 
nome 						   as 'Nome',
convert(dataNascimento, date)  as 'Data de nascimento'
from tb_boschinhos where nome = "sasa" and convert(dataNascimento, date) = "2004-10-01";

