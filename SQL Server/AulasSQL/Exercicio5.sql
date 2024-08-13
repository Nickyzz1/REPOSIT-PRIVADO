----- ex 5 -----
SELECT
E.Descricao AS "Evento",
S.Nome AS "Sala",
S.Capacidade,
COUNT(EP.IDPessoa) AS "Quantidade Participantes",  -- conta quantos ids uma reunião tem. comnta quantas linhas de acordo com o agrupamento já feito
CASE WHEN S.Capacidade < COUNT(EP.IDPessoa) THEN 'Ultrapassou o Limite!' -- quando a capacidade vor menor que a quantidade de pessoas convidadas o limite é ultrapassado
ELSE 'Limite OK' END AS "Avaliação da Capacidade"  -- cria uma coluna  chamada av. de capacidade para exibir os resultados
FROM EventoPessoa EP
INNER JOIN Evento E
ON EP.IDEvento = E.IDEvento -- define as informações realcionáveis
INNER JOIN Sala S
ON S.IDSala = E.IDSala  -- define as informações realcionáveis
-- junta tds as infos para podermos usar depois
GROUP BY E.Descricao, S.Nome, S.Capacidade, E.IDEvento
-- requisitos, se as linhas foremn iguais vão se juntar
