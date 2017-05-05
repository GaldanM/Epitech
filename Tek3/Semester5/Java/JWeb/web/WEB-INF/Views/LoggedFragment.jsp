<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<div class="container-logged-fragment">
    <div class="header-loogged-fragment">
        <p class="greetings-logged">Welcome !</p>
        <p class="title-logged-fragment"><c:out value="${sessionScope.sessionUser.userName}"/></p>
    </div>
    <div class="container-logged-fragment">
        <form method="get" action="<c:url value="/myAccount"/>">
            <input type="hidden" name="id" value="0"/>
            <button class="btn-logout-fragment-cart" type="submit" class="btn">MyAccount</button>
        </form>
        <form method="post" action="<c:url value="/disconnect"/>">
            <button class="btn btn-logout">Logout</button>
        </form>
    </div>
</div>