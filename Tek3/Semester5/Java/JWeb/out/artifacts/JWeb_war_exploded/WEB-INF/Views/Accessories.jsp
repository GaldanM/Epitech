<%--
  Created by IntelliJ IDEA.
  User: olivier.medec
  Date: 26/12/2015
  Time: 18:46
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<%@include file="../Includes/Common/header.jsp"%>
<link type="text/css" rel="stylesheet" href="${pageContext.request.contextPath}/resources/css/accessoires.css" />
<body>
<%@include file="../Includes/Common/navigation-bar.jsp"%>
<div class="container-full">
    <div class="page-header page-header-accessoire">
        <div class="center-cell">
            <p class="text-white text-normal">Store</p>
            <h1 class="text-white text-normal">Accessories</h1>
            <div class="margin-medium"></div>
        </div>
    </div>
    <div class="log-fragment"></div>
    <div class="accessoire-container row">
        <c:forEach var="accessorie" items="${requestScope.accessories}">
            <div class="col-md-4 pres-accessoire">
                <div style="background: url('${accessorie.imgPath}') no-repeat center; background-size: 100% 100%;" class="img-accessoire-container"></div>
                <p class="p-center">${accessorie.name}</p>
                <p>${accessorie.price}</p>
                <form  method="post" action="<c:out value="/restrict/addToCart"/>">
                    <button name="productName" value="${accessorie.name}" class="btn btn-lg btn-primary btn-block buy" type="submit">Add to cart</button>
                </form>
            </div>
        </c:forEach>

    </div>
    <%@include file="../Includes/Common/footer.jsp"%>
</div>
</body>
</html>
<script type="text/javascript" src="<c:url value="/resources/js/accessoires.js"/>"></script>