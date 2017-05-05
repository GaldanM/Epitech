package DAO;

import Model.Bean.Product;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import static DAO.DAOUtils.*;

public class DAOProductImpl implements DAOProduct
{
	private DAOFactory      factory;
	private final String    SQL_FIND_PRODUCT = "SELECT * FROM products WHERE name = ?;";
	private final String    SQL_FIND_ACCESSORIES = "SELECT * FROM products WHERE type = ?;";

	DAOProductImpl(DAOFactory factory)
	{
		this.factory = factory;
	}

	@Override
	public Product  getProduct(String name)
	{
		Connection connection = null;
		PreparedStatement preparedStatement = null;
		ResultSet result = null;
		Product product = new Product();

		try
		{
			connection = factory.getConnection();
			preparedStatement = initRequest(connection, SQL_FIND_PRODUCT, false, name);
			result = preparedStatement.executeQuery();
			if (result.next())
				product = fillProduct(result);
		}
		catch (SQLException e) {throw new DAOException(e);}
		finally {close(result, preparedStatement, connection);}

		return product;
	}

	@Override
	public ArrayList<Product>   getAccessories()
	{
		Connection connection = null;
		PreparedStatement preparedStatement = null;
		ResultSet result = null;
		ArrayList<Product> list = new ArrayList<>();
		Product product;

		try
		{
			connection = factory.getConnection();
			preparedStatement = initRequest(connection, SQL_FIND_ACCESSORIES, false, true);
			result = preparedStatement.executeQuery();
			while (result.next())
			{
				product = fillProduct(result);
				list.add(product);
			}
		}
		catch (SQLException e) {throw new DAOException(e);}
		finally {close(result, preparedStatement, connection);}

		return list;
	}
}
