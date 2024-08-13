Claro! Vou criar seis exercícios desafiadores incorporando os conceitos e competências que você mencionou, incluindo a implementação de um banco de dados, comandos SQL avançados, e manipulação de dados.

1. Relatório de Vendas com Ordenação e Junção de Tabelas
Descrição: Crie uma consulta que gere um relatório de vendas por produto e cliente. O relatório deve incluir o nome do cliente, nome do produto, a quantidade total vendida e o valor total. Ordene o relatório por valor total em ordem decrescente.

Tabelas Usadas: clientes, notas fiscais, itens notas fiscais, produtos

Exemplo de Consulta:

sql
Copiar código
SELECT 
    c.nome AS NomeCliente,
    p.nome_do_produto AS NomeProduto,
    SUM(i.quantidade) AS QuantidadeTotal,
    SUM(i.preço * i.quantidade) AS ValorTotal
FROM 
    clientes c
JOIN 
    notas_fiscais nf ON c.cpf = nf.cpf
JOIN 
    itens_notas_fiscais i ON nf.numero = i.numero
JOIN 
    produtos p ON i.cod_do_produto = p.código_do_produto
GROUP BY 
    c.nome, p.nome_do_produto
ORDER BY 
    ValorTotal DESC;
2. Procedimento Armazenado para Atualização de Preços
Descrição: Crie um procedimento armazenado que atualize o preço de todos os produtos em uma categoria específica, aumentando-o em 10%. O procedimento deve receber a categoria como parâmetro.

Tabelas Usadas: produtos

Exemplo de Stored Procedure:

sql
Copiar código
DELIMITER //

CREATE PROCEDURE AtualizaPrecosCategoria(
    IN categoria_nome VARCHAR(255)
)
BEGIN
    UPDATE produtos
    SET preco_de_lista = preco_de_lista * 1.10
    WHERE embalagem = categoria_nome;
END //

DELIMITER ;
3. Trigger para Registro de Alterações no Volume de Compra
Descrição: Crie uma trigger que registre todas as alterações no volume de compra dos clientes em uma tabela de log. A tabela de log deve conter o CPF do cliente, o antigo volume de compra, o novo volume de compra e a data da alteração.

Tabelas Usadas: clientes (Tabela de Log a ser criada)

Exemplo de Criação da Tabela de Log e Trigger:

sql
Copiar código
-- Criar a tabela de log
CREATE TABLE log_volume_compra (
    cpf VARCHAR(14),
    antigo_volume FLOAT,
    novo_volume FLOAT,
    data_alteracao DATETIME,
    PRIMARY KEY (cpf, data_alteracao)
);

-- Criar a trigger
DELIMITER //

CREATE TRIGGER LogVolumeCompraAlteracao
AFTER UPDATE ON clientes
FOR EACH ROW
BEGIN
    INSERT INTO log_volume_compra (cpf, antigo_volume, novo_volume, data_alteracao)
    VALUES (OLD.cpf, OLD.volume_de_compra, NEW.volume_de_compra, NOW());
END //

DELIMITER ;
4. Consulta com Subselect e Agrupamento de Dados
Descrição: Crie uma consulta que retorne os clientes que fizeram mais de 5 compras no último mês. A consulta deve usar um subselect para calcular o número de compras e aplicar um comando de agrupamento para contar as compras.

Tabelas Usadas: clientes, notas fiscais

Exemplo de Consulta:

sql
Copiar código
SELECT 
    c.nome AS NomeCliente,
    COUNT(*) AS TotalCompras
FROM 
    clientes c
JOIN 
    notas_fiscais nf ON c.cpf = nf.cpf
WHERE 
    nf.data_venda > DATE_SUB(NOW(), INTERVAL 1 MONTH)
GROUP BY 
    c.nome
HAVING 
    COUNT(*) > 5;
5. Atualização Condicional com CASE WHEN
Descrição: Atualize o limite de crédito dos clientes com base no volume de compras. Use o comando CASE WHEN para definir novos limites de crédito: se o volume de compra for maior que 5000, o limite de crédito deve ser aumentado em 20%, caso contrário, diminua-o em 10%.

Tabelas Usadas: clientes

Exemplo de Consulta:

sql
Copiar código
UPDATE clientes
SET limite_de_credito = CASE
    WHEN volume_de_compra > 5000 THEN limite_de_credito * 1.20
    ELSE limite_de_credito * 0.90
END;
6. Consulta com LIKE e Variáveis
Descrição: Crie uma consulta que retorne todos os produtos cujo nome começa com a letra "C" e contenha "Refresco" em seu nome. Utilize uma variável para definir a letra inicial e a substring.

Tabelas Usadas: produtos

Exemplo de Consulta:

sql
Copiar código
SET @letra_inicial = 'C';
SET @substring = 'Refresco';

SELECT 
    nome_do_produto
FROM 
    produtos
WHERE 
    nome_do_produto LIKE CONCAT(@letra_inicial, '%') 
    AND nome_do_produto LIKE CONCAT('%', @substring, '%');
Resumo dos Exercícios
Relatório de Vendas com Ordenação e Junção de Tabelas: Utiliza JOIN, GROUP BY e ORDER BY.
Procedimento Armazenado para Atualização de Preços: Inclui criação e utilização de STORED PROCEDURE.
Trigger para Registro de Alterações no Volume de Compra: Implementa TRIGGER e INSERT.
Consulta com Subselect e Agrupamento de Dados: Usa SUBSELECT e GROUP BY.
Atualização Condicional com CASE WHEN: Aplica o comando CASE WHEN.
Consulta com LIKE e Variáveis: Utiliza LIKE e variáveis.
