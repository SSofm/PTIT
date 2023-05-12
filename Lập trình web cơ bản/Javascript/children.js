var slideIndex = 0;
showSlides_child();

function showSlides_child() {
    var i;
    var slides = document.getElementsByClassName("mySlides_child");
    var dots = document.getElementsByClassName("dot_child");
    for (i = 0; i < slides.length; i++) {
        slides[i].style.display = "none";  
    }
    slideIndex++;
    if (slideIndex > slides.length) {slideIndex = 1}    
    for (i = 0; i < dots.length; i++) {
        dots[i].className = dots[i].className.replace(" active_child", "");
    }
    slides[slideIndex-1].style.display = "block";  
    dots[slideIndex-1].className += " active_child";
    setTimeout(showSlides_child, 2000); 
}