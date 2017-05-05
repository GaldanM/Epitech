/**
 * Created by olivier.medec on 21/12/2015.
 */
$(function(){
    $(".homeNavBar").css("position", "");

    $('.panel-container').animate({
        marginBottom: "+=10%",
        marginTop: "+=5%"
    }, 1500, function() {
    });

    var MyVar = $('.list-account-option a');

    MyVar.click(function(e){
        $('.list-account-option li').removeClass("active");
        $(this).parent().addClass("active");
        if (e.target.className == "option-account-1") {
            $.get( "/myAccount?id=1", function(data) {
                $(".form-horizontal").html(data);
            })
        } else if (e.target.className == "option-account-2"){
            $.get( "/myAccount?id=2", function(data) {
                $(".form-horizontal").html(data);
            })
        } else if (e.target.className == "option-account-3"){
            $.get( "/myAccount?id=3", function(data) {
                $(".form-horizontal").html(data);
            })
        }
    })
});