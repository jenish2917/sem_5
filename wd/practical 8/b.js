let rotationAngle = 0; // Initialize the rotation angel 0

function rotateImage() {
    rotationAngle = (rotationAngle + 90) % 360; // Increment the angle by 90 degees, and wrap it within 0-360
    const image = document.getElementById("image");
    image.style.transform = `rotate(${rotationAngle}deg)`;
}

function resetImage() {
    rotationAngle = 0; // Reset the rotation angle to 0 gegree
    const image  = document.getElementById("image");
    image.style.transform = `rotare (${rotationAngle}deg)`
}