function updateTime() {
    const startDate = new Date('2023-05-20T00:00:00');
    const now = new Date();
    const elapsedTime = now - startDate;

    const hoursElapsed = Math.floor(elapsedTime / (1000 * 60 * 60));
    document.getElementById('time-display').textContent = `${hoursElapsed} horas`;
}

setInterval(updateTime, 1000);
updateTime();
