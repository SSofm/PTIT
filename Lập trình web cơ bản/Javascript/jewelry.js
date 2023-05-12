var slideI = 0;
showSlides_jewelry();

function showSlides_jewelry() {
    var i;
    var slides = document.getElementsByClassName("mySlides_jewelry");
    var dots = document.getElementsByClassName("dot_jewelry");
    for (i = 0; i < slides.length; i++) {
        slides[i].style.display = "none";  
    }
    slideI++;
    if (slideI > slides.length) {slideI = 1}    
    for (i = 0; i < dots.length; i++) {
        dots[i].className = dots[i].className.replace(" active_jewelry", "");
    }
    slides[slideI-1].style.display = "block";  
    dots[slideI-1].className += " active_jewelry";
    setTimeout(showSlides_jewelry, 2000);
}