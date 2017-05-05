package Controller.Servlet;

import DAO.DAOFactory;
import DAO.DAOUser;
import Controller.Business.InscriptionBusiness;
import Model.Bean.User;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class InscriptionServlet extends HttpServlet
{
	private static final String ATT_FACTORY = "daofactory";
	private static final String ATT_BUSINESS = "business";
	private static final String ATT_USER  = "user";
	private static final String VIEW_LOGIN = "/WEB-INF/Views/LoginFragment.jsp";
	private static final String VIEW_SIGNUP = "/WEB-INF/Views/SigninFragment.jsp";

	private DAOUser             daoUser;

	public void init() throws ServletException
	{
		daoUser = ((DAOFactory) getServletContext().getAttribute(ATT_FACTORY)).getDAOUser();
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		InscriptionBusiness business = new InscriptionBusiness(daoUser);
		User user = business.signUpUser(request);

		request.setAttribute(ATT_BUSINESS, business);
		request.setAttribute(ATT_USER, user);

		if (business.getErrors().isEmpty())
			this.getServletContext().getRequestDispatcher(VIEW_LOGIN).forward(request, response);
		else
			this.getServletContext().getRequestDispatcher(VIEW_SIGNUP).forward(request, response);

	}
}