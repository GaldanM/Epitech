package Controller.Servlet;

import Controller.Business.ShippingBusiness;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class ShippingServlet extends HttpServlet
{
	public void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException
	{
		req.getRequestDispatcher("/WEB-INF/Views/Shipping.jsp").forward(req, resp);
	}

	public void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException
	{
		ShippingBusiness business = new ShippingBusiness();

		business.treatRequest(req);

		req.setAttribute("business", business);

		if (business.getErrors().isEmpty())
			req.getRequestDispatcher("/WEB-INF/Views/Validate.jsp").forward(req, resp);
		else
			req.getRequestDispatcher("/WEB-INF/Views/checkout-index.jsp").forward(req, resp);
	}
}
