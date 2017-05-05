<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<div class="container-fragment">
    <div class="header-fragment">
        <p class="title-fragment">Log in</p>
    </div>
    <div class="container-form-fragment">
        <span class="erreur">${requestScope.business.errors['userName']}</span>
        <span class="erreur">${requestScope.business.errors['password']}</span>
        <form method="post" action="<c:url value="/connection.jsp"/>" class="form-signin">
            <label for="inputLogin" class="sr-only">Login</label>
            <input name="userName" type="text" id="inputLogin" class="form-control" placeholder="Login" required="" autofocus="">

            <label for="inputPassword" class="sr-only">Password</label>
            <input name="password" type="password" id="inputPassword" class="form-control" placeholder="Password" required="">

            <div class="checkbox">
                <label>
                    <input type="checkbox" value="remember-me"> Remember me
                </label>
            </div>

            <button class="btn btn-lg btn-primary btn-block btn-login-fragment" type="submit">Log in</button>
        </form>
        <p class="${empty requestScope.business.errors ? "succes" : "erreur"}"><c:out value="${requestScope.business.result}"/></p>
        <a href="#" class="sign-in-link">Sign up</a>
    </div>
</div>
