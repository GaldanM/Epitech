<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<div class="container-fragment">
    <div class="header-fragment">
        <p class="title-fragment">Cart</p>
    </div>
    <c:choose>
        <c:when test="${!empty sessionScope.cart}">
            <c:forEach var="product" items="${sessionScope.cart}">
                <div class="product-cart-container">
                    <c:out value="${product.name} x${product.number}"/><br/>
                </div>
            </c:forEach>
            <a href="/restrict/Checkout">Checkout</a>
        </c:when>
        <c:otherwise>
            You're cart is empty
        </c:otherwise>
    </c:choose>
</div>

