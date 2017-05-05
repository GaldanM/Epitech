package Controller.Servlet;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * Created by olivier.medec on 19/12/2015.
 */
public class FragLogServlet extends HttpServlet
{
    public void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException
    {
        if (req.getSession().getAttribute("sessionUser") == null)
            this.getServletContext().getRequestDispatcher("/WEB-INF/Views/LoginFragment.jsp").forward(req, resp);
        else
            this.getServletContext().getRequestDispatcher("/WEB-INF/Views/LoggedFragment.jsp").forward(req, resp);
    }
}
