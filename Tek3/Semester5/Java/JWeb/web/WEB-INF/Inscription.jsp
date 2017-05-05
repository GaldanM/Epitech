<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<!DOCTYPE html>
<html>
    <head>
        <title>Inscription</title>
        <link rel="stylesheet" type="text/css" href="<c:url value="/style.css"/>">
    </head>

    <body>
        <form method="post" action="<c:url value="/inscription.jsp"/>">
            <fieldset>
                <legend>Inscription</legend>
                <p>Vous pouvez vous inscrire via ce formulaire.</p>

                <label for="userName">Nom d'utilisateur <span class="requis">*</span></label>
                <input type="text" id="userName" name="userName" value="<c:out value="${requestScope.user.userName}"/>" size="20" maxlength="20" />
                <span class="erreur">${requestScope.business.errors['userName']}</span>
                <br />

                <label for="password">Mot de passe <span class="requis">*</span></label>
                <input type="password" id="password" name="password" value="" size="20" maxlength="20" />
                <span class="erreur">${requestScope.business.errors['password']}</span>
                <br />

                <label for="confirmation">Confirmation du mot de passe <span class="requis">*</span></label>
                <input type="password" id="confirmation" name="confirmation" value="" size="20" maxlength="20" />
                <br />

                <label for="email">Adresse email <span class="requis">*</span></label>
                <input type="text" id="email" name="email" value="<c:out value="${requestScope.user.email}"/>" size="20" maxlength="60" />
                <span class="erreur">${requestScope.business.errors['email']}</span>
                <br />

                <input type="submit" value="Inscription" class="sansLabel" />
                <br />

                <p class="${empty requestScope.business.errors ? "succes" : "erreur"}"><c:out value="${requestScope.business.result}"/></p>
            </fieldset>
        </form>
    </body>
</html>