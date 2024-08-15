CREATE DATABASE db_loja_eletronicos;

USE db_loja_eletronicos;

-- Tabela `produtos`
CREATE TABLE produtos (
    id_produto INT PRIMARY KEY AUTO_INCREMENT,
    nome_produto VARCHAR(100) NOT NULL,
    categoria VARCHAR(50) NOT NULL,
    preco DECIMAL(10, 2) NOT NULL,
    quantidade_estoque INT NOT NULL
);

-- Tabela `clientes`
CREATE TABLE clientes (
    id_cliente INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    telefone VARCHAR(20) DEFAULT NULL,
    valor_total_compras DECIMAL(10, 2) DEFAULT 0.00
);

-- Tabela `vendas`
CREATE TABLE vendas (
    id_venda INT PRIMARY KEY AUTO_INCREMENT,
    id_produto INT NOT NULL,
    id_cliente INT NOT NULL,
    data_venda DATE NOT NULL,
    quantidade INT NOT NULL,
    valor_total DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (id_produto) REFERENCES produtos(id_produto),
    FOREIGN KEY (id_cliente) REFERENCES clientes(id_cliente)
);

-- Tabela `promocoes`
CREATE TABLE promocoes (
    id_promocao INT PRIMARY KEY AUTO_INCREMENT,
    nome_promocao VARCHAR(100) NOT NULL,
    data_inicio DATE NOT NULL,
    data_fim DATE NOT NULL,
    desconto DECIMAL(5, 2) NOT NULL
);

-- Tabela `notificacoes`
CREATE TABLE notificacoes (
    id_notificacao INT PRIMARY KEY AUTO_INCREMENT,
    mensagem TEXT NOT NULL,
    data_notificacao DATETIME DEFAULT CURRENT_TIMESTAMP
);

INSERT INTO produtos (nome_produto, categoria, preco, quantidade_estoque) VALUES
('Smartphone X12', 'Eletrônicos', 2999.99, 50),
('Laptop Pro 15', 'Eletrônicos', 4999.99, 30),
('Cadeira Gamer RGB', 'Móveis', 799.99, 20),
('Headphone Wireless', 'Eletrônicos', 349.99, 100),
('Smartwatch Pro', 'Eletrônicos', 799.99, 70),
('Mouse Óptico', 'Acessórios', 89.99, 200),
('Teclado Mecânico', 'Acessórios', 159.99, 150),
('Cadeira de Escritório', 'Móveis', 499.99, 40),
('Monitor Ultra HD', 'Eletrônicos', 1499.99, 25),
('HD Externo 2TB', 'Eletrônicos', 299.99, 60);

INSERT INTO clientes (nome, email, telefone, valor_total_compras) VALUES
('João Silva', 'joao.silva@example.com', '1234-5678', 1599.99),
('Maria Oliveira', 'maria.oliveira@example.com', '2345-6789', 2399.99),
('Pedro Souza', 'pedro.souza@example.com', '3456-7890', 899.99),
('Ana Costa', 'ana.costa@example.com', '4567-8901', 499.99),
('Carlos Santos', 'carlos.santos@example.com', '5678-9012', 1299.99),
('Lucia Almeida', 'lucia.almeida@example.com', '6789-0123', 699.99),
('Ricardo Lima', 'ricardo.lima@example.com', '7890-1234', 849.99),
('Juliana Martins', 'juliana.martins@example.com', '8901-2345', 1199.99),
('Fernando Pereira', 'fernando.pereira@example.com', '9012-3456', 1499.99),
('Beatriz Rocha', 'beatriz.rocha@example.com', '0123-4567', 349.99);

INSERT INTO vendas (id_produto, id_cliente, data_venda, quantidade, valor_total) VALUES
(1, 1, '2024-08-01', 1, 2999.99),
(2, 2, '2024-08-02', 1, 4999.99),
(3, 3, '2024-08-03', 1, 799.99),
(4, 4, '2024-08-04', 2, 699.98),
(5, 5, '2024-08-05', 1, 799.99),
(6, 6, '2024-08-06', 3, 89.99),
(7, 7, '2024-08-07', 1, 159.99),
(8, 8, '2024-08-08', 1, 499.99),
(9, 9, '2024-08-09', 1, 1499.99),
(10, 10, '2024-08-10', 1, 299.99);

INSERT INTO promocoes (nome_promocao, data_inicio, data_fim, desconto) VALUES
('Desconto de Verão', '2024-08-13', '2024-08-31', 15.00),
('Black Friday', '2024-11-24', '2024-11-30', 25.00),
('Promoção de Natal', '2024-12-01', '2024-12-25', 20.00),
('Liquidação de Inverno', '2024-01-05', '2024-01-20', 30.00),
('Dia das Mães', '2024-05-01', '2024-05-10', 10.00),
('Dia dos Pais', '2024-08-01', '2024-08-15', 12.00),
('Promoção de Outono', '2024-09-01', '2024-09-30', 18.00),
('Dia do Cliente', '2024-10-15', '2024-10-20', 22.00),
('Semana do Frete Grátis', '2024-06-01', '2024-06-07', 5.00),
('Lançamento de Produto', '2024-04-01', '2024-04-15', 8.00);

INSERT INTO notificacoes (mensagem, data_notificacao) VALUES
('Novo produto disponível: Smartphone X12', '2024-08-01 10:00:00'),
('Promoção de verão começou!', '2024-07-01 09:30:00'),
('Atualização de estoque para Cadeira Gamer RGB', '2024-08-02 14:20:00'),
('Novas ofertas de laptops', '2024-08-03 16:45:00'),
('Atenção: Monitor Ultra HD está em promoção!', '2024-08-04 11:15:00'),
('Lançamento do novo modelo de smartwatch', '2024-08-05 13:00:00'),
('Lembre-se do Dia das Mães – ofertas especiais!', '2024-05-01 08:00:00'),
('Atualização de preço para Headphone Wireless', '2024-08-06 15:30:00'),
('Não perca a Black Friday – descontos imperdíveis!', '2024-11-24 10:00:00'),
('Oferta de última hora para HD Externo 2TB', '2024-08-07 17:00:00');

INSERT INTO clientes (nome, email, telefone, valor_total_compras)
VALUES
    ('Lucas Fernandes', 'lucas.fernandes@example.com', '9876-5432', 0.00),
    ('Sofia Rocha', 'sofia.rocha@example.com', '8765-4321', 0.00),
    ('Gabriel Almeida', 'gabriel.almeida@example.com', '7654-3210', 0.00),
    ('Juliana Costa', 'juliana.costa@example.com', '6543-2109', 0.00),
    ('Rafael Oliveira', 'rafael.oliveira@example.com', '5432-1098', 0.00);

-- 1.Registrar uma nova venda e atualizar o valor total de compras por cliente.

DELIMITER //

CREATE TRIGGER after_venda_insert 
AFTER INSERT ON vendas
FOR EACH ROW
BEGIN
    -- Atualiza o valor total de compras do cliente
    UPDATE clientes
    SET valor_total_compras = valor_total_compras + NEW.valor_total
    WHERE id_cliente = NEW.id_cliente;
END;

//

DELIMITER ;

INSERT INTO vendas (id_produto, id_cliente, data_venda, quantidade, valor_total)
VALUES (6, 1, '2024-08-16', 1, 1);

select * from clientes;

-- 2. Trigger para aplicar desconto de promoção em vendas

drop trigger aplicar_descontos;

DELIMITER //
CREATE TRIGGER aplicar_descontos
BEFORE INSERT ON vendas
FOR EACH ROW
BEGIN
    DECLARE desconto_promocao DECIMAL(5, 2);
    DECLARE valor_com_desconto DECIMAL(10, 2);

    SET desconto_promocao = (SELECT desconto
                             FROM promocoes
                             WHERE data_inicio <= NEW.data_venda
                               AND data_fim >= NEW.data_venda
                             LIMIT 1);

    IF desconto_promocao IS NOT NULL THEN
        SET valor_com_desconto = NEW.valor_total * (1 - desconto_promocao / 100);
        SET NEW.valor_total = valor_com_desconto;
    END IF;
END // DELIMITER ;

INSERT INTO vendas (id_produto, id_cliente, data_venda, quantidade, valor_total)
VALUES (6, 14, '2024-08-16', 1, 100);

SELECT * FROM clientes;

-- 3.Atualizar o preço médio de um produto após uma nova venda.

alter table vendas drop column preçoMedio;
alter table produtos add column preçoMedio decimal;
select * from vendas;
select * from produtos;

drop trigger setMidValue;

DELIMITER //
create trigger setMidValue
after insert on vendas
for each row
begin
	declare varValueMid decimal;
    set varValueMid = (
    select 
    sum(valor_total)/count(valor_total)
    from vendas);
    update produtos
    set preçoMedio = varValueMid
    where id_produto = 1;
end
// DELIMITER ;

-- média preço atual + preço com desconto / 2 = preço médio
SET SQL_SAFE_UPDATES = 0;
INSERT INTO vendas (id_produto, id_cliente, data_venda, quantidade, valor_total) VALUES (6, 14, '2024-08-16', 1, 100200);

-- 4.Rastrear alterações no estoque de produtos e registrar uma notificação dentro de um log.

drop table logEstoque;

create table logEstoque(
logEstoque_id int primary key not null auto_increment,
nome_produto varchar(60) not null,
quantidade int not null
);

delimiter //
create trigger updateEstoque
after update on produtos
for each row
begin
	insert into logEstoque (nome_produto, quantidade) values (new.nome_produto, new.quantidade_estoque);
end
// delimiter ;

update produtos
set quantidade_estoque = quantidade_estoque + 5
where nome_produto = 'Laptop Pro 15';

select * from logEstoque;

-- 5.Registrar novos clientes e gerar uma mensagem de usuário cadastrado dentro de um log.

drop table logNewUser;

create table logNewUser(
nome_user varchar(60) not null,
descricao varchar(255)
);

delimiter //
create trigger tg_newUser
after insert on clientes
for each row
begin
	insert into logNewUser (nome_user, descricao) values (new.nome, "novo cliente inserido");
end
// delimiter ;

INSERT INTO clientes (nome, email, telefone, valor_total_compras) VALUES ('fer', 'fer.kriksddjnd@example.com', '9876-5432', 0.00);

select * from logNewUser;

-- nn usar where se eel nn for chave
-- nn usar where dentro no insert

-- 6.Monitorar vendas de produtos em promoção e registrar uma notificação.



-- 7.Registrar produtos em falta no estoque e gerar uma notificação.
-- 8.Atualizar o valor total de vendas de um produto após uma nova venda.
-- 9.Rastrear alterações no valor de produtos e registrar uma notificação.
