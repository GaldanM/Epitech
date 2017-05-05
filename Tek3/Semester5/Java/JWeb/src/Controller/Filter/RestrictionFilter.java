package Controller.Filter;

import java.io.IOException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class RestrictionFilter implements Filter
{
	public static final String ATT_SESSION_USER = "sessionUser";

	public void init( FilterConfig config ) throws ServletException
	{
	}

	public void doFilter( ServletRequest req, ServletResponse resp, FilterChain chain ) throws IOException, ServletException
	{
		HttpServletRequest request = (HttpServletRequest) req;
		HttpServletResponse response = (HttpServletResponse) resp;

     	HttpSession session = request.getSession();

		if (session.getAttribute(ATT_SESSION_USER) == null)
    		response.sendRedirect(request.getContextPath() + "/smartphone.jsp");
		else
    		chain.doFilter(request, response);
	}

	public void destroy()
	{
	}
}