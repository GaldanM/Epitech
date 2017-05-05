<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<%@include file="../Includes/Common/header.jsp"%>
<link type="text/css" rel="stylesheet" href="${pageContext.request.contextPath}/resources/css/user-account.css" />
<body>
<div class="container-full">
    <div class="log-fragment"></div>

    <div class="container">
        <%@include file="../Includes/Common/navigation-bar.jsp"%>
        <div class="panel-container row">
            <div class="col-md-4 side-bar-option-account">
                <ul class="list-account-option">
                    <li>Mon compte WebSiteName</li>
                    <li class="active"><div></div><a class="option-account-1" href="#">Mon compte</a></li>
                    <li><span></span><a class="option-account-2" href="#">Informations</a></li>
                    <li><span></span><a class="option-account-3" href="#">Mon addresse</a></li>
                </ul>
            </div>
            <div class="col-md-8 panel-option-items">
                <form class="form-horizontal">
                    <%@include file="/WEB-INF/Includes/UserAccount/MyAccountFragment.jsp"%>
                </form>
            </div>
        </div>
    </div>

    <%@include file="../Includes/Common/footer.jsp"%>
</div>
</body>
</html>
<script type="text/javascript" src="<c:url value="/resources/js/UserAccount.js"/>"></script>