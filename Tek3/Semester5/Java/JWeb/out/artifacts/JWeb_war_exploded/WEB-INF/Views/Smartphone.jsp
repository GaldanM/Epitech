<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <%@include file="../Includes/Common/header.jsp"%>
  <body>
    <%@include file="../Includes/Common/navigation-bar.jsp"%>
    <div class="container-full">
      <div class="page-header page-header-smarphone"></div>
      <div class="log-fragment"></div>
      <%@include file="../Includes/Common/sticky-nav-bar-smartphone.jsp"%>
        <div class="case-presentation niv1">
        <div class="row">
          <div class="col-md-6"><img class="img-pres" src="${pageContext.request.contextPath}/resources/images/nextbit-robin-5.jpeg"></div>
          <div class="col-md-6">
            <p class="text-container">A truly different smartphone.</br>
              It gets smarter every day, and makes</br>
              running out of space history.</p>
          </div>
        </div>
      </div>
      <div class="case-presentation niv2">
        <div class="row">
          <div class="col-md-6"><img class="img-pres" style="width: 504px;" src="${pageContext.request.contextPath}/resources/images/nextbit-robin-4.jpeg"></div>
          <div class="col-md-6">
            <p class="text-container">We went through hundreds of iterations of the OnePlus 2 before finalizing the design that perfected a balance of look and feel.<br/> It’s about everything being in the right place, creating a seamless, fluid experience. No detail is too small to be perfected.</p>
          </div>
        </div>
      </div>
      <div class="case-presentation niv3">
        <div class="row">
          <div class="col-md-6"><img class="img-pres" style="width: 810px;" src="${pageContext.request.contextPath}/resources/images/nextbit-robin-7.jpeg"></div>
          <div class="col-md-6">
            <p class="text-container">Robin runs on a premium Qualcomm® Snapdragon™808 processor. </br>Its battery is engineered for efficiency to get you through the day,</br>and its camera is optimized for taking incredible photos and videos.</br> </p>
          </div>
        </div>
      </div>
      <div class="modal fade" id="myModal" tabindex="-1" role="dialog">
        <div class="modal-dialog">
          <div class="modal-content">
            <div class="modal-header">
              <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
              <h4 class="modal-title">Smartphone</h4>
            </div>

            <form action="<c:out value="/restrict/addToCart"/>" method="post">
              <div class="modal-body">
                <div class="radio">
                  <label>
                    <input type="radio" name="productName" id="blue" value="blue" checked>
                    Robin - blue 16Go - 349€
                  </label>
                </div>
                <div class="radio">
                  <label>
                    <input type="radio" name="productName" id="grey" value="grey">
                    Robin - Grey 16 Go - 349€
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
      <%@include file="../Includes/Common/footer.jsp"%>
    </div>
  </body>
</html>
<script type="text/javascript" src="<c:url value="/resources/js/smartphone.js"/>"></script>
