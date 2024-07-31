//var -> acessíovel em qualquwe lugar que a função foi criada ou globalmente se for declada fora da função

//console.log(x) --> é o printf

// let -> Escopo: O let tem escopo de bloco, o que significa que uma variável declarada com let é acessível apenas dentro do bloco ({}) 

// const --> variáveis que não pudem mudr de valor

console.log("hello world");

console.error("ué");

function exemploVar() {
    console.log(x); // undefined (hoisting) ele mostra undefined
    var x = 10;
    console.log(x); // 10
}
exemploVar();

//exibir arrays e matriz de forma mais organizada

console.table([
    { nome: 'Ana', idade: 25 },
    { nome: 'João', idade: 30 }
]);

console.time(); //mostra emn quanto tenpo foi feita a execução do código

console.timeEnd();
