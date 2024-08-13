create database aula;
use aula;

create table tb_pai(
id int not null primary key auto_increment,
nome varchar(60)
);

create table tb_filho(
id int not null primary key auto_increment,
nome varchar(60),
id_pai int,
foreign key(id_pai) references tb_pai(id) -- caScade vai onde tem a chave estrangeira
-- on delete cascade
-- on update cascade
ON DELETE restrict
ON UPDATE cascade
);

drop table tb_pai;
drop table tb_filho;

insert into tb_pai (nome) values('Darth Vader');
insert into tb_pai (nome) values('Goku');
insert into tb_pai (nome) values('Vegeta');
insert into tb_pai (nome) values('Seu Cebola');
insert into tb_pai (nome) values('Zurg');
insert into tb_pai (nome) values('Neymar');

insert into tb_filho (nome, id_pai) values('Luke Skywalker', 1);
insert into tb_filho (nome, id_pai) values('Gohan', 2);
insert into tb_filho (nome, id_pai) values('Trunks', 3);
insert into tb_filho (nome, id_pai) values('Cebolinha', 4);
insert into tb_filho (nome, id_pai) values('Buzz Lightyear', 5);
insert into tb_filho (nome, id_pai) values('Neymar Jr', 6);

set SQL_SAFE_UPDATES =0;

select * from tb_pai;
select * from tb_filho;

delete from tb_filho where nome = 'Cebolinha';
delete from tb_pai where nome = 'Darth Vader';




