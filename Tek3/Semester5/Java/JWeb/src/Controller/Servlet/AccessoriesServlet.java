package Controller.Servlet;

import Controller.Business.CartBusiness;
import DAO.DAOFactory;
import DAO.DAOProduct;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class AccessoriesServlet extends HttpServlet
{
    private static final String ATT_FACTORY = "daofactory";

    private DAOProduct daoProduct;

    public void init() throws ServletException
    {
        daoProduct = ((DAOFactory) getServletContext().getAttribute(ATT_FACTORY)).getDAOProduct();
    }

    public void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException
    {
        CartBusiness business = new CartBusiness(daoProduct);

        req.setAttribute("accessories", business.getAccessories());
        this.getServletContext().getRequestDispatcher("/WEB-INF/Views/Accessories.jsp").forward(req, resp);
    }
}
