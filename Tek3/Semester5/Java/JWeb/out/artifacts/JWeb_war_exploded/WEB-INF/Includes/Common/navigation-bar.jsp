<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<nav class="homeNavBar navbar navbar-inverse">
    <div class="container-fluid">
        <div class="navbar-header">
            <a class="navbar-brand" href="#">NextByte</a>
        </div>
        <div>
            <ul class="nav navbar-nav">
                <li class="li-smartphone-nav"><a href="<c:out value="/smartphone.jsp"/>">Smartphone</a></li>
                <li class="li-earphone-nav"><a href="<c:out value="/earphone.jsp"/>">Earphone</a></li>
                <li class="li-accessoire-nav"><a href="<c:out value="/accessories.jsp"/>">Accessories</a></li>
            </ul>
            <ul class="nav navbar-nav navbar-right">
                <li><a class="user-login" href="#"><span class="glyphicon glyphicon-user"></span></a></li>
                <li><a class="user-cart" href="#"><span class="glyphicon glyphicon-shopping-cart"></span></a></li>
            </ul>
        </div>
    </div>
</nav>