<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<div class="form-group">
    <label for="inputAddress" class="col-sm-2 control-label">Address</label>
    <div class="col-sm-10">
        <input name="address" type="text" class="form-control" id="inputAddress" placeholder="Address">
        <span class="erreur">${requestScope.business.errors['address']}</span>
    </div>
</div>
<div class="form-group">
    <label for="inputCity" class="col-sm-2 control-label">City</label>
    <div class="col-sm-10">
        <input name="city" type="text" class="form-control" id="inputCity" placeholder="City">
        <span class="erreur">${requestScope.business.errors['city']}</span>
    </div>
</div>
<div class="form-group">
    <label for="inputZipCode" class="col-sm-2 control-label">Postal Code</label>
    <div class="col-sm-10">
        <input name="postal" type="text" class="form-control" id="inputZipCode" placeholder="Zip Code">
        <span class="erreur">${requestScope.business.errors['postal']}</span>
    </div>
</div>
<div class="form-group">
    <label for="inputPhoneNumber" class="col-sm-2 control-label">Telephone</label>
    <div class="col-sm-10">
        <input name="phone" type="text" class="form-control" id="inputPhoneNumber" placeholder="Telephone">
        <span class="erreur">${requestScope.business.errors['phone']}</span>
    </div>
</div>