package Controller.Servlet;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * Created by gmoul on 27/12/2015.
 */
public class FragSigninServlet extends HttpServlet
{
	public void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException
	{
		this.getServletContext().getRequestDispatcher("/WEB-INF/Views/SigninFragment.jsp").forward(req, resp);
	}
}