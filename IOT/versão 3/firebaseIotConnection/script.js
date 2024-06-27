import { service } from "./js/datebaseConfig.js";

const endPoint = "/Nicolle";

// Definindo estrutura do corpo do meu objeto do banco.
let body = {
    LivingRoom: {
        temperature: 0,
        humidity: 0,
        light: 0,
        tv: 0
    },
    Office: {
        temperature: 0,
        humidity: 0,
        light: 0,
        tv: 0
    },
    PrincipalRoom: {
        temperature: 0,
        humidity: 0,
        light: 0,
        tv: 0
    }
};

// Carregando dados do Firebase
const loadData = () => {
    service.load(endPoint).then(data => {
        body = data; // Atualiza o objeto body com os dados do Firebase

        const rooms = ['LivingRoom', 'Office', 'PrincipalRoom'];
        rooms.forEach(room => {
            getLightsValues(room);
            getTvValues(room);
            setTempValues(room);
        });
    });
};

// Funções para obter e exibir valores no HTML
const getLightsValues = (idLocal) => {
    let lamp = document.getElementById('lightBulb' + idLocal);
    let lightOn = body[idLocal].light; // Ajusta para usar body[idLocal].light

    if (lightOn == 1) {
        lamp.classList.add("light-on");
    } else {
        lamp.classList.remove("light-on");
    }
};

const getTvValues = (idLocal) => {
    let tv = document.getElementById(idLocal + "Tv");
    let tvOn = body[idLocal].tv; // Ajusta para usar body[idLocal].tv

    if (tvOn == 1) {
        tv.innerHTML = 'On';
    } else {
        tv.innerHTML = 'OFF';
    }
};

const setTempValues = (idLocal) => {
    const TempElement = document.getElementById(idLocal + "Temp");
    const HumidElement = document.getElementById(idLocal + "Humidity");

    let Hvalue = body[idLocal].humidity; // Ajusta para usar body[idLocal].humidity
    let Tvalue = body[idLocal].temperature; // Ajusta para usar body[idLocal].temperature

    TempElement.innerHTML = Tvalue;
    HumidElement.innerHTML = Hvalue;
};

// Funções de interação com HTML
const toggleLamp = (idRoom) => {
    const element = document.getElementById("lightBulb" + idRoom);
    element.classList.toggle('light-on');

    body[idRoom].light = !body[idRoom].light; // Ajusta para usar body[idRoom].light
    service.set(endPoint, body);
};

const toggleTv = (idRoom) => {
    const element = document.getElementById(idRoom + "Tv");
    body[idRoom].tv = !body[idRoom].tv; // Ajusta para usar body[idRoom].tv

    if (body[idRoom].tv) {
        element.innerHTML = "ON";
    } else {
        element.innerHTML = "OFF";
    }

    service.set(endPoint, body);
};

// Inicia o carregamento dos dados e as funções de interação com HTML
console.log('script loaded');

window.toggleLamp = toggleLamp;
window.toggleTv = toggleTv;

setInterval(() => {
    loadData();
}, 2000);
