package Controller.Servlet;

import Controller.Business.UpdateBusiness;
import DAO.DAOFactory;
import DAO.DAOUser;
import Model.Bean.User;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class UpdateServlet extends HttpServlet
{
	private static final String ATT_FACTORY = "daofactory";
	private static final String ATT_BUSINESS = "business";
	private static final String ATT_USER  = "sessionUser";
	private static final String VIEW = "/WEB-INF/Views/MyAccount.jsp";

	private DAOUser             daoUser;

	public void init() throws ServletException
	{
		daoUser = ((DAOFactory) getServletContext().getAttribute(ATT_FACTORY)).getDAOUser();
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		UpdateBusiness business = new UpdateBusiness(daoUser);
		User user = business.updateUser(request);

		request.setAttribute(ATT_BUSINESS, business);
		request.getSession().setAttribute(ATT_USER, user);
		request.setAttribute("id", "0");

		this.getServletContext().getRequestDispatcher(VIEW).forward(request, response);
	}
}