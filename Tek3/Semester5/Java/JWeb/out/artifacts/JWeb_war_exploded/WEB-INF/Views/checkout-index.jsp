<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<%@include file="../Includes/Common/header.jsp"%>
<link type="text/css" rel="stylesheet" href="${pageContext.request.contextPath}/resources/css/checkout.css" />
<body>
<%@include file="../Includes/Common/navigation-bar.jsp"%>
<div class="container-full">
    <div class="log-fragment"></div>
    <div class="container">
        <div class="panel panel-default panel-checkout">
            <div class="panel-heading">Item(s) in your cart</div>
            <table class="table">
                <thead>
                <tr>
                    <th>Item</th>
                    <th>Price</th>
                </tr>
                </thead>
                <tbody>
                <c:forEach var="product" items="${sessionScope.cart}">
                    <tr>
                        <td>${product.name}</td>
                        <td>${product.price}€</td>
                    </tr>
                </c:forEach>
                </tbody>
            </table>
        </div>
        <button class="btn btn-lg btn-primary btn-block btn-login-fragment btn-checkout" type="submit"><a href="/restrict/Shipping">Checkout</a></button>
    </div>
    <%@include file="../Includes/Common/footer.jsp"%>
</div>
</body>
</html>