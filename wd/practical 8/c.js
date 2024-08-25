function zoomOutImage(){
    const image  = document.getElementById('image');
    image.style.transform = 'scale(0.8)';
}

function resetZoom(){
    const  image  = document.getElementById('image');
    image.style.transform = 'scale(1)';

}