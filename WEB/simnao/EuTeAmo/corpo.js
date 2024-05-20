function updateTime() {
    const startDate = new Date('2023-05-20T00:00:00');
    const now = new Date();
    const elapsedTime = now - startDate;

    const secondsElapsed = Math.floor(elapsedTime / 1000);
    const minutesElapsed = Math.floor(secondsElapsed / 60);
    const hoursElapsed = Math.floor(minutesElapsed / 60);

    const displaySeconds = secondsElapsed % 60;
    const displayMinutes = minutesElapsed % 60;
    const displayHours = hoursElapsed;

    document.getElementById('time-display').textContent = 
        `${displayHours} horas, ${displayMinutes} minutos, ${displaySeconds} segundos`;
}

setInterval(updateTime, 1000);
updateTime();
