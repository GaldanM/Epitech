/**
 * Created by olivier.medec on 20/12/2015.
 */
$(function(){
    var navOffset = $(".smartPhone-nav-bar").offset().top;

    $(window).scroll(function(){
        var scrollPos = $(window).scrollTop();
        var nav = $(".smartPhone-nav-bar");

        if (scrollPos >= navOffset) {
            nav.addClass("fixed");
            nav.removeAttr("style")
            console.log("fixed");
        }
        else {
            nav.removeClass("fixed");
            nav.css("bottom", "0");
        }
    });

    $(".li-smartphone-nav").addClass("active");

    $(".presentation-btn-bar").click(function() {
        $(".sticky-li-smartphone").removeClass("active");
        $(".li-niv-1").addClass("active");
        $('html, body').animate({
            scrollTop: $(".niv1").offset().top
        }, 800);
    });

    $(".design-btn-bar").click(function() {
        $(".sticky-li-smartphone").removeClass("active");
        $(".li-niv-2").addClass("active");
        $('html, body').animate({
            scrollTop: $(".niv2").offset().top
        }, 800);
    });

    $(".car-btn-bar").click(function() {
        $(".sticky-li-smartphone").removeClass("active");
        $(".li-niv-3").addClass("active");
        $('html, body').animate({
            scrollTop: $(".niv3").offset().top
        }, 800);
    });
});