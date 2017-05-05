<%--
  Created by IntelliJ IDEA.
  User: olivier.medec
  Date: 26/12/2015
  Time: 21:44
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<%@include file="../Includes/Common/header.jsp"%>
<link type="text/css" rel="stylesheet" href="${pageContext.request.contextPath}/resources/css/checkout.css" />
<link type="text/css" rel="stylesheet" href="${pageContext.request.contextPath}/resources/css/connexion.css" />
<body>
<%@include file="../Includes/Common/navigation-bar.jsp"%>
<div class="container-full">
    <div class="log-fragment"></div>
    <div class="container">
        <div class="panel panel-default panel-checkout">
            <div class="panel-container">
                <div class="panel-option-items">
                    <form method="post" action="<c:url value="/connection.jsp"/>" class="form-horizontal">
                        <label for="inputLogin" class="sr-only">Login</label>
                        <input name="userName" type="text" id="inputLogin" class="form-control" placeholder="Login" required="" autofocus="">

                        <label for="inputPassword" class="sr-only">Password</label>
                        <input name="password" type="password" id="inputPassword" class="form-control" placeholder="Password" required="">

                        <button class="btn btn-lg btn-primary btn-block btn-login-fragment" type="submit" style="margin-top: 4%;">Sign in</button>
                    </form>
                    <br />
                    <p class="${empty requestScope.business.errors ? 'succes' : 'erreur'}">${requestScope.business.result}</p>
                </div>
            </div>
        </div>
    </div>
</div>
<%@include file="../Includes/Common/footer.jsp"%>
</body>
</html>