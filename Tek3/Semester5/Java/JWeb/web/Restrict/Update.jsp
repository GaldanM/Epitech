<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<!DOCTYPE html>
<html>
<head>
    <title>Update</title>
    <link rel="stylesheet" type="text/css" href="<c:url value="/style.css"/>">
</head>

<body>
<form method="post" action="<c:url value="/restrict/Update"/>">
    <fieldset>
        <legend>Update</legend>
        <p>You can update your infos on this page.</p>

        <label for="password">Password <span class="requis">*</span></label>
        <input type="password" id="password" name="password" value="" size="20" maxlength="20" />
        <span class="erreur">${requestScope.business.errors['password']}</span>
        <br />

        <label for="email">Email <span class="requis">*</span></label>
        <input type="email" id="email" name="email" value="<c:out value="${sessionScope.sessionUser.email}"/>" size="20" maxlength="20" />
        <span class="erreur">${requestScope.business.errors['email']}</span>
        <br />

        <label for="lastName">FirstName <span class="requis">*</span></label>
        <input type="text" id="lastName" name="lastName" value="<c:out value="${sessionScope.sessionUser.lastName}"/>" size="20" maxlength="20" />
        <span class="erreur">${requestScope.business.errors['lastName']}</span>
        <br />

        <label for="firstName">LastName <span class="requis">*</span></label>
        <input type="text" id="firstName" name="firstName" value="<c:out value="${sessionScope.sessionUser.firstName}"/>" size="20" maxlength="20" />
        <span class="erreur">${requestScope.business.errors['firstName']}</span>
        <br />

        <input type="submit" value="Update" class="sansLabel" />
        <br />

        <p class="${empty requestScope.business.errors ? 'succes' : 'erreur'}">${requestScope.business.result}</p>

        <p class="succes">You're logged as ${sessionScope.sessionUser.userName}</p>
    </fieldset>
</form>
</body>
</html>
