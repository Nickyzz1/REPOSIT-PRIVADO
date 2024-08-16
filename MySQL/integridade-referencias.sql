CREATE DATABASE SchoolManagement;
USE SchoolManagement;

CREATE TABLE Students (
    student_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);

CREATE TABLE Courses (
    course_id INT AUTO_INCREMENT PRIMARY KEY,
    course_name VARCHAR(100) NOT NULL
);

CREATE TABLE Enrollments (
    enrollment_id INT AUTO_INCREMENT PRIMARY KEY,
    student_id INT,
    course_id INT,
    enrollment_date DATE,
    FOREIGN KEY (student_id) REFERENCES Students(student_id)
		on update cascade
		on delete restrict,
    FOREIGN KEY (course_id) REFERENCES Courses(course_id)
		on update set null
		on delete set null
);

-- Inserindo registros na tabela Students
INSERT INTO Students (name) VALUES
('Alice'),
('Bob'),
('Charlie'),
('David'),
('Eva');

-- Inserindo registros na tabela Courses
INSERT INTO Courses (course_name) VALUES
('Mathematics'),
('Physics'),
('Chemistry'),
('Biology'),
('Computer Science');

-- Inserindo registros na tabela Enrollments
INSERT INTO Enrollments (student_id, course_id, enrollment_date) VALUES 
(1, 1, '2023-01-10'), 
(2, 2, '2023-02-15'), 
(3, 3, '2023-03-20'), 
(4, 4, '2023-04-25'), 
(5, 5, '2023-05-30');

-- Seleciona todos os registros da tabela Students
SELECT * FROM Students;

-- Seleciona todos os registros da tabela Courses
SELECT * FROM Courses;

-- Seleciona todos os registros da tabela Enrollments
SELECT * FROM Enrollments;

delete from Students where name = 'Alice';
delete from Courses where course_name = 'Chemistry';

Exercício 1: Exclusão de Aluno
Desafio: Dada a estrutura das tabelas, modifique o código para que, ao excluir um registro da tabela Students, todos os registros relacionados na tabela Enrollments sejam também removidos automaticamente. Por exemplo, se um aluno chamado "Alice" for excluído, todas as suas inscrições em cursos devem ser removidas sem deixar rastros.

Exercício 2: Exclusão de Curso
Desafio: Modifique a estrutura da tabela para que, ao excluir um curso na tabela Courses, as inscrições correspondentes na tabela Enrollments permaneçam intactas, mas a coluna course_id deve ser atualizada para refletir que o curso foi removido. Isso significa que o campo deve ser definido para um valor que indique a ausência do curso original.

Exercício 3: Atualização de Aluno
Desafio: Altere a estrutura da tabela para garantir que, se o student_id de um aluno na tabela Students for atualizado, o novo student_id seja propagado automaticamente em todos os registros relacionados na tabela Enrollments. Isso garante a integridade referencial entre as tabelas sem a necessidade de modificar manualmente os registros de inscrição.

Exercício 4: Atualização de Curso
Desafio: Faça uma modificação na tabela de modo que, ao atualizar o course_id em Courses, os registros relacionados na tabela Enrollments mantenham o antigo course_id e não sejam afetados. Esse comportamento deve ser útil para manter o histórico de inscrições no caso de cursos que foram renomeados ou substituídos.

Exercício 5: Exclusão Restritiva
Desafio: Ajuste o esquema para que seja impossível excluir um aluno na tabela Students se ele ainda estiver matriculado em qualquer curso na tabela Enrollments. Esse comportamento deve impedir a perda de dados críticos relacionados às matrículas de alunos.

Exercício 6: Tratamento Nulo
Desafio: Modifique a estrutura para que, ao excluir um curso da tabela Courses, os registros na tabela Enrollments tenham o course_id definido como nulo, indicando que o aluno estava matriculado em um curso que foi removido do sistema.
