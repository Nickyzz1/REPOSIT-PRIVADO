-- Criação do banco de dados
CREATE DATABASE DetranDB;
USE DetranDB;

drop database DetranDB;

-- Tabela para registrar proprietários
CREATE TABLE Proprietarios (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(255) NOT NULL,
    cpf VARCHAR(11) UNIQUE NOT NULL,
    endereco VARCHAR(255),
    telefone VARCHAR(20),
    pontos_cartreira INT DEFAULT 0
);

-- Tabela para registrar veículos
CREATE TABLE Veiculos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    marca VARCHAR(255) NOT NULL,
    modelo VARCHAR(255) NOT NULL,
    placa VARCHAR(7) UNIQUE NOT NULL,
    ano INT,
    proprietario_id INT,
    FOREIGN KEY (proprietario_id) REFERENCES Proprietarios(id)
    on delete cascade
    on update cascade
);

-- Tabela para registrar infrações de trânsito
CREATE TABLE Infracoes (
    id INT AUTO_INCREMENT PRIMARY KEY,
    descricao VARCHAR(255) NOT NULL,
    gravidade ENUM('Leve', 'Média', 'Grave', 'Gravíssima'),
    data_ocorrencia DATE NOT NULL,
    veiculo_id INT,
    FOREIGN KEY (veiculo_id) REFERENCES Veiculos(id)
    on delete cascade
    on update cascade
);

-- Tabela para registrar licenciamentos dos veículos
CREATE TABLE Licenciamentos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    data_validade DATE NOT NULL,
    veiculo_id INT,
    FOREIGN KEY (veiculo_id) REFERENCES Veiculos(id)
	on delete cascade
    on update cascade
);

-- Tabela para registrar multas aplicadas
CREATE TABLE Multas (
    id INT AUTO_INCREMENT PRIMARY KEY,
    valor DECIMAL(10, 2) NOT NULL,
    pontos INT DEFAULT 0,
    data_aplicacao DATE NOT NULL,
    infracao_id INT,
    FOREIGN KEY (infracao_id) REFERENCES Infracoes(id)
	on delete cascade
    on update cascade
);

-- Inserção de dados nas tabelas
-- Proprietarios
INSERT INTO Proprietarios (nome, cpf, endereco, telefone) VALUES
('João Silva', '12345678901', 'Rua A, 123', '(11) 1234-5678'),
('Maria Oliveira', '98765432101', 'Rua B, 456', '(11) 9876-5432'),
('Carlos Souza', '11122233344', 'Rua C, 789', '(11) 1111-2222'),
('Ana Lima', '55566677788', 'Rua D, 1011', '(11) 5555-6666'),
('Pedro Costa', '99988877766', 'Rua E, 1213', '(11) 9999-8888');

-- Veiculos
INSERT INTO Veiculos (marca, modelo, placa, ano, proprietario_id) VALUES
('Fiat', 'Uno', 'ABC1234', 2020, 1),
('Volkswagen', 'Gol', 'DEF5678', 2018, 2),
('Chevrolet', 'Onix', 'GHI9101', 2021, 3),
('Ford', 'Ka', 'JKL1112', 2019, 4),
('Honda', 'Civic', 'MNO1314', 2022, 5),
('Toyota', 'Corolla', 'PQR1516', 2020, 1),
('Hyundai', 'HB20', 'STU1718', 2017, 2),
('Renault', 'Kwid', 'VWX1920', 2018, 3),
('Nissan', 'Versa', 'YZA2122', 2019, 4),
('Jeep', 'Compass', 'BCD2324', 2021, 5);

-- Infracoes
INSERT INTO Infracoes (descricao, gravidade, data_ocorrencia, veiculo_id) VALUES
('Excesso de velocidade', 'Média', '2024-04-20', 1),
('Estacionamento irregular', 'Leve', '2024-04-21', 2),
('Ultrapassagem em local proibido', 'Grave', '2024-04-22', 3),
('Falta de cinto de segurança', 'Leve', '2024-04-23', 4),
('Dirigir sob efeito de álcool', 'Gravíssima', '2024-04-24', 5),
('Uso de celular ao volante', 'Média', '2024-04-25', 6),
('Não respeitar a sinalização', 'Grave', '2024-04-26', 7),
('Estacionamento em vaga de idoso', 'Leve', '2024-04-27', 8),
('Falta de inspeção veicular', 'Grave', '2024-04-28', 9),
('Excesso de lotação', 'Média', '2024-04-29', 10);

-- Licenciamentos
INSERT INTO Licenciamentos (data_validade, veiculo_id) VALUES
('2024-04-30', 1),
('2023-05-01', 2),
('2023-05-02', 3),
('2024-05-03', 4),
('2023-05-04', 5),
('2024-05-05', 6),
('2025-05-06', 7),
('2012-05-07', 8),
('2022-05-08', 9),
('2008-05-09', 10);

-- Multas
INSERT INTO Multas (valor, pontos, data_aplicacao, infracao_id) VALUES
(150.00, 5, '2024-04-20', 1),
(100.00, 3, '2024-04-21', 2),
(500.00, 7, '2024-04-22', 3),
(80.00, 2, '2024-04-23', 4),
(2000.00, 10, '2024-04-24', 5),
(130.00, 4, '2024-04-25', 6),
(500.00, 7, '2024-04-26', 7),
(50.00, 2, '2024-04-27', 8),
(250.00, 6, '2024-04-28', 9),
(120.00, 4, '2024-04-29', 10);


-- Inserir um novo veículo e seu proprietário (com trigger)
drop procedure pc_new_vehicles;

delimiter //
create procedure pc_new_vehicles(marca varchar(255), modelo varchar(255), placa varchar(7), ano int,proprietario_id int,
nome varchar(255), cpf varchar(11), endereco varchar(255), telefone varchar(20))
begin
    INSERT INTO Veiculos (marca, modelo, placa, ano, proprietario_id) VALUES(marca, modelo, placa, ano, proprietario_id);
	INSERT INTO Proprietarios (nome, cpf, endereco, telefone) VALUES (nome, cpf, endereco, telefone);
end
// delimiter ;

drop table  log_new_vehicles;

create table log_new_vehicles(
id int not null primary key auto_increment,
proprietario_id int not null,
description varchar(255) not null
);

drop trigger tg_new_vehicles;

delimiter //
create trigger tg_new_vehicles
after insert on Veiculos
for each row
begin
	insert into log_new_vehicles (proprietario_id, description) values (new.proprietario_id, "novo cliente inserido");
end
// delimiter ;

call pc_new_vehicles('Fiat', 'Uno', 'ABcde00', 2020, 5, 'João Frango', '11345678209', 'Rua A, 123', '(11) 1234-5678');

select * from log_new_vehicles;

truncate log_new_vehicles;

-- Deletar um veículo e suas multas associadas (com trigger)
-- 23
delimiter //
create procedure pc_del_vehicle(id_veiculo int)
begin
	delete from Veiculos where id_veiculo = id;
    delete from Infracoes where id_veiculo = veiculo_id;
end
//  delimiter ;

create table log_del_veiculos(
id int not null auto_increment primary key,
id_veiculo int not null,
marca VARCHAR(255) NOT NULL,
modelo VARCHAR(255) NOT NULL,
placa VARCHAR(7) UNIQUE NOT NULL,
ano INT,
proprietario_id INT
);

create table log_del_infracoes(
id int not null auto_increment primary key,
veiculo_id int not null,
descricao VARCHAR(255) NOT NULL,
gravidade ENUM('Leve', 'Média', 'Grave', 'Gravíssima'),
data_ocorrencia DATE NOT NULL
);

delimiter //
create trigger tg_del_vehicle
before delete on veiculos
for each row
begin
	insert into log_del_veiculos(id_veiculo, marca, modelo, placa, ano, proprietario_id)  values (old.id, old.marca, old.modelo, old.placa, old.ano, old.proprietario_id);
end
//  delimiter ;

describe veiculos;

delimiter //
create trigger tg_del_infracoes
before delete on Infracoes
for each row
begin
	insert into log_del_infracoes(veiculo_id, descricao, gravidade, data_ocorrencia)  values (old.veiculo_id , old.descricao, old.gravidade, old.data_ocorrencia);
end
//  delimiter ;

call pc_del_vehicle(3);

select * from infracoes;
select * from multas;
select * from proprietarios;
select * from veiculos;

select * from veiculos;
select * from log_del_veiculos;
select * from log_del_infracoes;

-- Inserir uma nova infração e atualizar multas associadas (com trigger)

delimiter //
create procedure pc_infracao_multa(veiculo_id int, descricao varchar(255), gravidade enum('Leve', 'Média', 'Grave', 'Gravíssima'), data_ocorrencia date)
begin
	insert into infracoes (descricao, gravidade, data_ocorrencia, veiculo_id) values (descricao, gravidade, data_ocorrencia, veiculo_id);
end
// delimiter ;

delimiter // 
create trigger tg_update_multas
after insert on infracoes
for each row
begin
	insert into multas(valor, pontos, data_aplicacao, infracao_id) values(100, 4, curdate(), new.id);
end
// delimiter ;

call pc_infracao_multa(1,'Boniteza', 'Grave', '2024-04-20');

-- Atualizar pontos na carteira de um proprietário específico que levou uma multa(com trigger)

delimiter //
create trigger tg_update_pontos
after insert on multas
for each row
begin
	declare proprietario int;
    
	set proprietario = (
    select
    p.id
    from multas as m
    inner join infracoes as i
    on new.infracao_id = i.id
    inner join veiculos as v
    on v.id = i.veiculo_id
    inner join proprietarios as p
    on p.id = v.proprietario_id
    limit 1
    );
    
    update proprietarios
    set pontos_cartreira = pontos_cartreira + new.pontos
    where id = proprietario;
end
// delimiter ;

-- Deletar um proprietário e seus veículos associados (com trigger)

delete from proprietarios 
where id = 7;

-- Selecionar veículos com licenciamento expirado

select
v.marca,
v.placa,
v.proprietario_id,
l.data_validade
from veiculos as v
inner join licenciamentos as l
on data_validade < curdate();

-- Selecionar veículos que possuem multas graves

select
v.marca,
v.placa,
v.proprietario_id,
i.data_ocorrencia,
i.gravidade,
i.descricao
from veiculos as v
inner join infracoes as i
on gravidade = "Grave";

-- Selecionar veículos acima de 2021 
select
marca,
placa,
proprietario_id,
ano
from veiculos
where ano > 2021;

-- Selecionar multas de veículos abaixo de 2020

select
m.id,
m.valor,
m.pontos,
m.data_aplicacao,
v.id as 'id do veiculo'
from multas as m
inner join infracoes as i
on i.id = m.infracao_id
inner join veiculos as v
on i.veiculo_id = v.id
where v.ano < 2020;

select * from infracoes;
select * from multas;
select * from proprietarios;
select * from veiculos;
select * from Licenciamentos;

-- Selecionar todos os veículos com multas pendentes

alter table multas add column Pendente enum('false', 'true');

update multas
set Pendente = 'true'
where id=4;

select
v.marca,
v.placa,
v.proprietario_id,
i.data_ocorrencia,
i.gravidade,
i.descricao,
m.valor,
m.pontos,
m.data_aplicacao
from veiculos as v
inner join infracoes as i
on i.veiculo_id = v.id
inner join multas as m
on m.infracao_id = i.id;

-- Inserir um novo proprietário

insert into proprietarios(nome,cpf, endereco, telefone, pontos_cartreira) values("joao emo", '111', 'sjjska', '2121', 0);

-- Atualizar informações de um proprietário

update proprietarios
set nome = 'joao emo'
where id = 1;

-- Deletar um proprietário

delete from proprietarios
where endereco = 'sjjska';

-- Selecionar todos os proprietários

select * from proprietarios;

-- Inserir uma nova infração
DESCRIBE INFRACOES;

insert into infracoes(descricao, gravidade, data_ocorrencia, veiculo_id) values('pois então', 'Média', curdate(), 4);

-- Atualizar informações de uma infração
update infracoes
set descricao = 'Veja bem'
where descricao = 'pois então';

-- Deletar uma infração

delete from infracoes
where descricao = 'pois então';

-- Selecionar todas as infrações

select * from infracoes;

-- Inserir um novo licenciamento

describe licenciamentos;
insert into licenciamentos (data_validade, veiculo_id) values (curdate(), 1);

-- Atualizar informações de um licenciamento

select * from licenciamentos;

update licenciamentos
set id = 99
where id = 11;


    


