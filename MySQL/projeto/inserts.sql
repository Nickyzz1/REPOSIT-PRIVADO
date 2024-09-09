USE db_highway;
INSERT INTO tb_acesso (tipo_acesso) VALUES
('Admin'),
('User'),
('Manager'),
('Editor'),
('Viewer'),
('Guest'),
('SuperAdmin'),
('Operator'),
('Analyst'),
('Tester');

INSERT INTO tb_usuario (nome, cpf, email, dt_nascimento, tipo_acesso) VALUES
('Nicolle Souza', '12345678901', 'nicolle1@email.com', '2000-01-01', 1),
('Carlos Lima', '12345678902', 'carlos2@email.com', '1998-02-14', 2),
('Ana Paula', '12345678903', 'ana3@email.com', '1995-03-20', 3),
('Roberto Silva', '12345678904', 'roberto4@email.com', '1989-04-25', 4),
('Juliana Alves', '12345678905', 'juliana5@email.com', '1990-05-30', 5),
('Fernando Torres', '12345678906', 'fernando6@email.com', '1985-06-15', 6),
('Mariana Costa', '12345678907', 'mariana7@email.com', '1993-07-10', 7),
('Renato Gomes', '12345678908', 'renato8@email.com', '1982-08-22', 8),
('Patrícia Silva', '12345678909', 'patricia9@email.com', '2001-09-17', 9),
('Lucas Martins', '12345678910', 'lucas10@email.com', '1999-10-05', 10);

INSERT INTO tb_telefone (cod_usuario, telefone) VALUES
(1, '11987654321'),
(2, '11987654322'),
(3, '11987654323'),
(4, '11987654324'),
(5, '11987654325'),
(6, '11987654326'),
(7, '11987654327'),
(8, '11987654328'),
(9, '11987654329'),
(10, '11987654330');


INSERT INTO tb_carne (nome, valor) VALUES
('Fraldinha', 25.90),
('Picanha', 35.90),
('Alcatra', 30.50),
('Costela', 28.00),
('Maminha', 27.80),
('Coxão Duro', 22.50),
('Filet Mignon', 45.00),
('Cupim', 26.40),
('Patinho', 20.00),
('Acém', 18.50);

INSERT INTO tb_salada (nome, valor) VALUES
('Alface', 3.00),
('Rúcula', 4.00),
('Agrião', 3.50),
('Couve', 3.20),
('Espinafre', 4.50),
('Tomate', 5.00),
('Pepino', 2.80),
('Cenoura', 3.50),
('Beterraba', 4.00),
('Repolho', 3.90);

INSERT INTO tb_molho (nome, valor) VALUES
('Barbecue', 2.50),
('Maionese', 1.80),
('Ketchup', 1.50),
('Mostarda', 1.50),
('Molho Verde', 2.20),
('Chimichurri', 2.70),
('Pesto', 3.00),
('Alho', 1.80),
('Tártaro', 2.50),
('Rosé', 2.50);

INSERT INTO tb_pao (nome, valor) VALUES
('Pão Brioche', 4.50),
('Pão Australiano', 5.00),
('Pão Francês', 2.80),
('Pão de Batata', 3.50),
('Pão Integral', 4.00),
('Pão de Milho', 4.20),
('Pão Sírio', 3.80),
('Pão de Queijo', 3.00),
('Pão Multigrãos', 5.50),
('Pão de Centeio', 4.60);


INSERT INTO tb_queijo (nome, valor) VALUES
('Queijo Cheddar', 4.00),
('Queijo Mussarela', 3.50),
('Queijo Gorgonzola', 5.50),
('Queijo Parmesão', 4.80),
('Queijo Suíço', 6.00),
('Queijo Gouda', 5.00),
('Queijo Provolone', 4.80),
('Queijo Coalho', 3.50),
('Queijo Minas', 4.20),
('Queijo Roquefort', 6.50);


INSERT INTO tb_adicional (nome, valor) VALUES
('Ovo', 2.00),
('Bacon', 3.50),
('Cebola Caramelizada', 2.50),
('Picles', 2.00),
('Tomate Seco', 3.00),
('Azeitona', 2.20),
('Cebola Roxa', 1.80),
('Alho Frito', 1.50),
('Rúcula', 2.20),
('Milho Verde', 1.50);

INSERT INTO tb_produto (nome, valor) VALUES
('Coca-Cola', 5.00),
('Fanta', 4.50),
('Guaraná', 4.50),
('Água', 3.00),
('Suco Natural', 6.00),
('Cerveja', 7.50),
('Refrigerante Zero', 5.00),
('Ice Tea', 4.80),
('Energético', 10.00),
('Água com Gás', 3.50);
