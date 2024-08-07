document.addEventListener('DOMContentLoaded', function() {
    const user = document.getElementById('user');
    const senha = document.getElementById('senha');
    const entrar = document.getElementById('entrar');

    function validateLogin() {
        if (user.value.trim() !== '' && senha.value.trim() !== '') {
            entrar.disabled = false;
        } else {
            entrar.disabled = true;
        }
    }

    function updateButtonStyle() {
        if (entrar.disabled) {
            entrar.classList.add('disabled');
        } else {
            entrar.classList.remove('disabled');
        }
    }

    user.addEventListener('input', () => { validateLogin(); updateButtonStyle(); });
    senha.addEventListener('input', () => { validateLogin(); updateButtonStyle(); });

    validateLogin();
    updateButtonStyle();
});
