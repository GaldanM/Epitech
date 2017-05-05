$(function() {
    $(".user-login").click(function() {
        $('.log-fragment').before('<div class="log-fragment-background"></div>');
        $.get( "/fragLog", function(data) {
            $(".log-fragment").html(data);
        }).error(function(){
            $(".log-fragment").html("Error1");
        });
        $(".log-fragment").animate({
            opacity: 1,
            width: "+=300px"
        }, 400, function() {
        });
    });

    $(".user-cart").click(function() {
        $('.log-fragment').before('<div class="log-fragment-background"></div>');
        $.get( "/fragCart", function(data) {
            $(".log-fragment").html(data);
        }).error(function(){
            $(".log-fragment").html("Error cart");
        });
        $(".log-fragment").animate({
            opacity: 1,
            width: "+=300px"
        }, 400, function() {
        });
    });

    $(window).click(function(e) {
        console.log(e.target.className);
        if (e.target.className == "log-fragment-background") {
            $(".log-fragment").animate({
                opacity: 1,
                width: "-=30%"
            }, 400, function() {
                $('.log-fragment-background').remove();
            });
        }

        if (e.target.className == "sign-in-link") {
            $.get( "/fragSignin", function(data) {
                $(".log-fragment").html(data);
            }).error(function(){
                $(".log-fragment").html("Error signin");
            });
        }

        if (e.target.className == "btn btn-lg btn-primary btn-block btn-login-fragment") {
            e.preventDefault();
            var name = $('#inputLogin').val();
            var pwd = $('#inputPassword').val();
            $.post( "/connection.jsp", {userName: name, password: pwd}).done(function(data) {
                $(".log-fragment").html(data);
            }).error(function(){
                $(".log-fragment").html("error login");
            });
        }

        if (e.target.className == "btn btn-lg btn-primary btn-block btn-signup-fragment") {
            e.preventDefault();
            var name = $('#inputLogin').val();
            var pwd = $('#inputPassword').val();
            var confirm = $('#inputConfirm').val();
            var mail = $('#inputEmail').val();
            $.post( "/inscription.jsp", {userName: name, password: pwd,
                confirmation: confirm, email: mail}).done(function(data) {
                $(".log-fragment").html(data);
            }).error(function(){
                $(".log-fragment").html("error login");
            });
        }

        if (e.target.className == "btn btn-logout") {
            e.preventDefault();
            $.get("/disconnect").error(function(){
                $(".log-fragment").html("Error disconnect");
            }).done(function(){
                $.get( "/fragLog", function(data) {
                    $(".log-fragment").html(data);
                }).error(function(){
                    $(".log-fragment").html("Error !logout");
                });
            });
        }
    });
});