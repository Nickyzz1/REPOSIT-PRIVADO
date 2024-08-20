const img = document.getElementById("img-perfil");

// var inputfile = () => {
//     alert("clicou")
//     img.src = "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcReyI2KHz-7k9zT55sMZSsOcoQxHv_JZ5vpaQ&s"
// }

function PreviewImage() {
    var oFReader = new FileReader();
    oFReader.readAsDataURL(document.getElementById("uploadImage").files[0]);

    oFReader.onload = function (oFREvent) {
        document.getElementById("uploadPreview").src = oFREvent.target.result;
    };
};
