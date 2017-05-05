<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<!DOCTYPE html>
<html>
    <head>
        <title>Connection</title>
        <link rel="stylesheet" type="text/css" href="<c:url value="/style.css"/>">
    </head>

    <body>
    <form method="post" action="<c:url value="/connection.jsp"/>">
        <fieldset>
            <legend>Connection</legend>
            <p>You can log in on this page.</p>

            <label for="userName">Username <span class="requis">*</span></label>
            <input type="text" id="userName" name="userName" value="<c:out value="${requestScope.user.userName}"/>" size="20" maxlength="60" />
            <span class="erreur">${requestScope.business.errors['userName']}</span>
            <br />

            <label for="password">Password <span class="requis">*</span></label>
            <input type="password" id="password" name="password" value="" size="20" maxlength="20" />
            <span class="erreur">${requestScope.business.errors['password']}</span>
            <br />

            <input type="submit" value="Connection" class="sansLabel" />
            <br />

            <p class="${empty requestScope.business.errors ? 'succes' : 'erreur'}">${requestScope.business.result}</p>

            <c:if test="${!empty sessionScope.sessionUser}">
                <p class="succes">You're logged as ${sessionScope.sessionUser.userName}</p>
            </c:if>
        </fieldset>
    </form>
    </body>
</html>
