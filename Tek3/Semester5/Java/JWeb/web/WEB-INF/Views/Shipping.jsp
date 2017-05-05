<%--
  Created by IntelliJ IDEA.
  User: olivier.medec
  Date: 26/12/2015
  Time: 02:24
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<%@include file="../Includes/Common/header.jsp"%>
<link type="text/css" rel="stylesheet" href="${pageContext.request.contextPath}/resources/css/checkout.css" />
<body>
<%@include file="../Includes/Common/navigation-bar.jsp"%>
<div class="container-full">
    <div class="log-fragment"></div>
    <div class="container">
        <div class="panel-container">
            <div class="panel-option-items">
                <form method="post" action="<c:url value="/restrict/Shipping"/>" class="form-horizontal">
                    <%@include file="/WEB-INF/Includes/Common/address.jsp"%>
                    <div class="form-group">
                        <div class="col-sm-offset-2 col-sm-10">
                            <button type="submit" class="btn btn-default btn-login-fragment">Buy</button>
                        </div>
                    </div>
                </form>
            </div>
        </div>
    </div>
    </div>
    <%@include file="../Includes/Common/footer.jsp"%>
</div>
</body>
</html>