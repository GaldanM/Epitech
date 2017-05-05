<%--
  Created by IntelliJ IDEA.
  User: olivier.medec
  Date: 26/12/2015
  Time: 21:16
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<div class="container-fragment">
    <div class="header-fragment">
        <p class="title-fragment">Sign up</p>
    </div>
    <div class="container-form-fragment">
        <form method="post" action="<c:url value="/inscription.jsp"/>" class="form-signin">
            <label for="inputLogin" class="sr-only">Login</label>
            <input name="userName" type="text" id="inputLogin" class="form-control" placeholder="Login" required="" autofocus="">

            <label for="inputPassword" class="sr-only">Password</label>
            <input name="password" type="password" id="inputPassword" class="form-control" placeholder="Password" required="">

            <label for="inputPassword" class="sr-only">Confirm password</label>
            <input name="confirmation" type="password" id="inputConfirm" class="form-control" placeholder="Confirm Password" required="" style="margin-top: 4%;">

            <label for="inputEmail" class="sr-only">email</label>
            <input name="email" type="email" id="inputEmail" class="form-control" placeholder="Email" required="" style="margin-top: 4%;">

            <button class="btn btn-lg btn-primary btn-block btn-signup-fragment" type="submit" style="margin-top: 4%;">Sign in</button>
        </form>
        <p class="${empty requestScope.business.errors ? "succes" : "erreur"}"><c:out value="${requestScope.business.result}"/></p>
    </div>
</div>
