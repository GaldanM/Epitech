<%--
  Created by IntelliJ IDEA.
  User: gmoul
  Date: 26/12/2015
  Time: 18:22
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>ADD</title>
</head>
<body>
    <form action="<c:url value="/restrict/Addcart"/>" method="post">
        <input type="hidden" name="Button" value="blue">
        <button type="submit">SMARTPHONE</button>
    </form>

    <form action="<c:url value="/restrict/Addcart"/>" method="post">
        <input type="hidden" name="Button" value="earphone">
        <button type="submit">EARPHONE</button>
    </form>
    <c:forEach var="product" items="${sessionScope.cart}">
        <c:out value="${product.name} x${product.number}"/><br/>
    </c:forEach>
</body>
</html>
