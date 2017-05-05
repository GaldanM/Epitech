package Controller.Servlet;

import Controller.Business.CartBusiness;
import DAO.DAOFactory;
import DAO.DAOProduct;
import Model.Bean.Product;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;

public class AddToCartServlet extends HttpServlet
{
	private static final String CART_VIEW = "/Restrict/AddToCart.jsp";
	private static final String ATT_FACTORY = "daofactory";

	private DAOProduct          daoProduct;

	public void init() throws ServletException
	{
		daoProduct = ((DAOFactory) getServletContext().getAttribute(ATT_FACTORY)).getDAOProduct();
	}

	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		this.getServletContext().getRequestDispatcher(CART_VIEW).forward(request, response);
	}

	@SuppressWarnings("unchecked")
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		CartBusiness business = new CartBusiness(daoProduct);

		business.addToCart(request.getParameter("productName"), (ArrayList<Product>) request.getSession().getAttribute("cart"));

		response.sendRedirect(request.getContextPath() + "/smartphone.jsp");
	}
}
