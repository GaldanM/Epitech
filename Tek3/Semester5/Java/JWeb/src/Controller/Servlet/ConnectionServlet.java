package Controller.Servlet;

import Controller.Business.ConnectionBusiness;
import DAO.DAOFactory;
import DAO.DAOUser;
import Model.Bean.Product;
import Model.Bean.User;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ConnectionServlet extends HttpServlet
{
	private static final String VIEW_LOGGED = "/WEB-INF/Views/LoggedFragment.jsp";
	private static final String VIEW_FAIL = "/WEB-INF/Views/LoginFragment.jsp";
	private static final String ATT_FACTORY = "daofactory";
	private static final String ATT_BUSINESS = "business";
	private static final String ATT_USER = "user";
	private static final String ATT_SESS_USER = "sessionUser";
	private static final String ATT_SESS_CART = "cart";

	private DAOUser             daoUser;

	public void init() throws ServletException
	{
		daoUser = ((DAOFactory) getServletContext().getAttribute(ATT_FACTORY)).getDAOUser();
	}
/*
	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		this.getServletContext().getRequestDispatcher(VIEW).forward(request, response);
	}
*/
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		ConnectionBusiness business = new ConnectionBusiness(daoUser);
		User user = business.logInUser(request);

		request.setAttribute(ATT_BUSINESS, business);
		request.setAttribute(ATT_USER, user);

		HttpSession session = request.getSession();
		if (business.getErrors().isEmpty())
		{
			session.setAttribute(ATT_SESS_USER, user);
			session.setAttribute(ATT_SESS_CART, new ArrayList<Product>());
			this.getServletContext().getRequestDispatcher(VIEW_LOGGED).forward(request, response);
		}

		else
		{
			session.setAttribute(ATT_SESS_USER, null);
			session.setAttribute(ATT_SESS_CART, null);
			this.getServletContext().getRequestDispatcher(VIEW_FAIL).forward(request, response);
		}
	}
}
