<%--
  Created by IntelliJ IDEA.
  User: olivier.medec
  Date: 23/12/2015
  Time: 00:56
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<form method="post" action="<c:url value="/restrict/Update"/>">
    <div class="form-group">
        <label for="inputLastName" class="col-sm-2 control-label">Last Name</label>
        <div class="col-sm-10">
            <input name="lastName" type="text" class="form-control" id="inputLastName" placeholder="Last Name">
        </div>
    </div>

    <div class="form-group">
        <label for="inputName" class="col-sm-2 control-label">First Name</label>
        <div class="col-sm-10">
            <input name="firstName" type="text" class="form-control" id="inputName" placeholder="First Name">
        </div>
    </div>

    <div class="form-group">
        <label for="inputEmail" class="col-sm-2 control-label">Email</label>
        <div class="col-sm-10">
            <input name="email" type="email" class="form-control" id="inputEmail" placeholder="Email">
        </div>
    </div>

    <div class="form-group">
        <div class="col-sm-offset-2 col-sm-10">
            <button type="submit" class="btn btn-default">Save</button>
        </div>
    </div>
</form>