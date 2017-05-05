package Controller.Servlet;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class MyAccountServlet extends HttpServlet
{
		public void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException
		{
			String id = req.getParameter("id");

			if (id == null)
				id = "0";
			switch (id)
			{
				case "0":
					req.getRequestDispatcher("/WEB-INF/Views/MyAccount.jsp").forward(req, resp);
					break;
				case "1":
					req.getRequestDispatcher("/WEB-INF/Includes/UserAccount/MyAccountFragment.jsp").forward(req, resp);
					break;
				case "2":
					req.getRequestDispatcher("/WEB-INF/Includes/UserAccount/MyInfosFragment.jsp").forward(req, resp);
					break;
				case "3":
					req.getRequestDispatcher("/WEB-INF/Includes/UserAccount/MyAddressFragment.jsp").forward(req, resp);
					break;
			}
		}
}
