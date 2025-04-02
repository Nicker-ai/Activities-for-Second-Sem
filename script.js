let slides = document.getElementsByClassName("slider_slide");
let navlinks = document.getElementsByClassName("slider_navlink");
let currentSlide = 0;
    let slideInterval;

function startSlideShow() {
    slideInterval = setInterval(() => {
        changeSlide(currentSlide + 1);
    }, 3500);
}

function stopSlideShow() {
    clearInterval(slideInterval);
}

document.getElementById("nav-button--next").addEventListener("click", () => {
    changeSlide(currentSlide + 1);
});

document.getElementById("nav-button--prev").addEventListener("click", () => {
    changeSlide(currentSlide - 1);
});

function changeSlide(moveTo) {

    if (moveTo >= slides.length) {
        moveTo = 0;
    }

    if (moveTo < 0) {
        moveTo = slides.length - 1;
    }

    slides[currentSlide].classList.remove("active");
    navlinks[currentSlide].classList.remove("active");
    slides[moveTo].classList.add("active");
    navlinks[moveTo].classList.add("active");

    currentSlide = moveTo;

}

document.querySelectorAll('.slider_navlink').forEach((bullet, bulletIndex) => {
    bullet.addEventListener('click', () => {
        if (currentSlide !== bulletIndex){
            changeSlide(bulletIndex);
        }
    })
})

startSlideShow;