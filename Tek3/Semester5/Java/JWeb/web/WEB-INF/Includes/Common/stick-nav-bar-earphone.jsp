<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<style>
    .btn-smartphone-buy {
        border-radius: 0px;
        background-color: #009688;
        border-color: #009688;
    }

    .btn-smartphone-buy:hover,
    .btn-smartphone-buy:focus,
    .btn-smartphone-buy:active {
        border-radius: 0px;
        background-color: #004f42;
        border-color: #004f42;
        height: 100%;
    }
</style>
<nav class="smartPhone-nav-bar navbar-inverse" style="bottom: 0">
    <div class="container-fluid">
        <div class="navbar-header">
            <a class="navbar-brand" href="#">Meet the Robin</a>
        </div>
        <div>
            <ul class="nav navbar-nav">
                <li class="active sticky-li-smartphone li-niv-1"><a href="#" class="presentation-btn-bar">Presentation</a></li>
                <li class="li-niv-2 sticky-li-smartphone"><a href="#" class="design-btn-bar">Design</a></li>
           </ul>
            <ul class="nav navbar-nav navbar-right">
                <li>
                    <button type="submit" class="btn btn-primary btn-lg btn-smartphone-buy" data-toggle="modal" data-target="#myModal">
                            <span class="glyphicon glyphicon-shopping-cart"></span> Add to cart
                    </button>
                </li>
            </ul>
        </div>
    </div>
</nav>