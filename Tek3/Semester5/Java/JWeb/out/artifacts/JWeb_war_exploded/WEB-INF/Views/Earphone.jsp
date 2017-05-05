<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<%@include file="../Includes/Common/header.jsp"%>
<link type="text/css" rel="stylesheet" href="${pageContext.request.contextPath}/resources/css/earphone.css" />
<body>
<%@include file="../Includes/Common/navigation-bar.jsp"%>
<div class="container-full">
    <div class="page-header page-header-earphone"></div>
    <div class="log-fragment"></div>
    <%@include file="../Includes/Common/stick-nav-bar-earphone.jsp"%>

    <div class="modal fade" id="myModal" tabindex="-1" role="dialog">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                    <h4 class="modal-title">Earphone</h4>
                </div>

                <form action="<c:out value="/restrict/addToCart"/>" method="post">
                    <div class="modal-body">
                        <div class="radio">
                            <label>
                                <input class="productName" type="radio" name="productName" value="earphone" checked>
                                Earhone - 149€
                            </label>
                        </div>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
                        <button type="submit" class="btn btn-primary buy">Add to cart</button>
                    </div>
                </form>


            </div>
        </div>
    </div>

    <div class="case-presentation niv1">
        <div class="row">
            <div class="col-md-6"><img class="img-pres" src="${pageContext.request.contextPath}/resources/images/earphone_gif.gif"></div>
            <div class="col-md-6">
                <p class="text-container">PUGZ-World's smallest wireless earbuds <br/></p>
            </div>
        </div>
    </div>
    <div class="case-presentation niv2">
        <div class="row">
            <div class="col-md-6"><img class="img-pres" style="width: 890px;" src="${pageContext.request.contextPath}/resources/images/la-meuf-chiante.jpg"></div>
            <div class="col-md-6">
                <p class="text-container">They are designed and constructed to simply stay in place. <br/>We defy you to try shaking them out of your ears!<br/></p>
            </div>
        </div>
    </div>
    <%@include file="../Includes/Common/footer.jsp"%>
</div>
</body>
</html>
<script type="text/javascript" src="<c:url value="/resources/js/earphone.js"/>"></script>