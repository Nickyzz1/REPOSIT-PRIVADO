create database vmotion; 
use vmotion;

create table cadastro(
id int not null primary key identity,
nome varchar(60) not null,
senha varchar(60) not null
);

insert into cadastro (nome, senha) values('nii', '4566');

select * from cadastro;
