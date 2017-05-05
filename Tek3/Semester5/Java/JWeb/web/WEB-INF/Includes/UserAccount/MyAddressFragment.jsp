<%--
  Created by IntelliJ IDEA.
  User: olivier.medec
  Date: 23/12/2015
  Time: 00:57
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<form method="post" action="<c:url value="/restrict/Update"/>">
    <%@include file="/WEB-INF/Includes/Common/address.jsp"%>
    <div class="form-group">
        <div class="col-sm-offset-2 col-sm-10">
            <button type="submit" class="btn btn-default">Save</button>
        </div>
    </div>
</form>