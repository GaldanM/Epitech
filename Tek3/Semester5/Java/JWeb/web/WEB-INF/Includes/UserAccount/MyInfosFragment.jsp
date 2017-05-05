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
        <label for="inputOldMdp" class="col-sm-2 control-label">Old password</label>
        <div class="col-sm-10">
            <input name="oldPassword" type="password" class="form-control" id="inputOldMdp" placeholder="Old password">
        </div>
    </div>
    <div class="form-group">
        <label for="inputNewMdp" class="col-sm-2 control-label">New password</label>
        <div class="col-sm-10">
            <input name="newPassword" type="password" class="form-control" id="inputNewMdp" placeholder="New password">
        </div>
    </div>
    <div class="form-group">
        <label for="inputConfirm" class="col-sm-2 control-label">Confirm</label>
        <div class="col-sm-10">
            <input name="confirmation" type="password" class="form-control" id="inputConfirm" placeholder="Confirm">
        </div>
    </div>
    <div class="form-group">
        <div class="col-sm-offset-2 col-sm-10">
            <button type="submit" class="btn btn-default">Save</button>
        </div>
    </div>
</form>