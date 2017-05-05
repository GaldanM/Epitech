package DAO;

import Model.Bean.User;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import static DAO.DAOUtils.*;

public class DAOUserImpl implements DAOUser
{
	private DAOFactory      factory;
	private final String    SQL_FIND_USER_BY_USERNAME = "SELECT * FROM users WHERE userName = ?";
	private final String    SQL_CREATE_USER = "INSERT INTO users (userName, password, email) VALUES (?, ?, ?)";
	private final String    SQL_UPDATE_USER = "UPDATE users SET password=?, email=?, lastName=?, firstName=?, address=?, city=?, postal=? WHERE userName = ?";

	DAOUserImpl(DAOFactory factory)
	{
		this.factory = factory;
	}

	@Override
	public User find(String userName) throws DAOException
	{
		Connection connection = null;
		PreparedStatement preparedStatement = null;
		ResultSet result = null;
		User user = null;

		try
		{
			connection = factory.getConnection();
			preparedStatement = initRequest(connection, SQL_FIND_USER_BY_USERNAME, false, userName);
			result = preparedStatement.executeQuery();
			if (result.next())
				user = fillUser(result);
		}
		catch (SQLException e) {throw new DAOException(e);}
		finally {close(result, preparedStatement, connection);}

		return user;
	}

	@Override
	public void create(User user) throws DAOException
	{
		Connection connection = null;
		PreparedStatement preparedStatement = null;
		ResultSet result = null;

		try
		{
			connection = factory.getConnection();
			preparedStatement = initRequest(connection, SQL_CREATE_USER, true,
					user.getUserName(), user.getPassword(), user.getEmail());

			int status = preparedStatement.executeUpdate();
			if (status == 0)
				throw new DAOException("Could not create new user, database hasn't change");

			result = preparedStatement.getGeneratedKeys();
			if (result.next())
				user.setId(result.getLong(1));
			else
				throw new DAOException("Could not create new user, no ID generated");
		}
		catch (SQLException e) {throw new DAOException(e);}
		finally {close(result, preparedStatement, connection);}
	}

	@Override
	public void update(User nouv) throws DAOException
	{
		Connection connection = null;
		PreparedStatement preparedStatement = null;
		ResultSet result = null;

		try
		{
			connection = factory.getConnection();

			preparedStatement = initRequest(connection, SQL_UPDATE_USER, false,
					nouv.getPassword(), nouv.getEmail(), nouv.getLastName(), nouv.getFirstName(),
					nouv.getAddress(), nouv.getCity(), nouv.getPostal(), nouv.getUserName());
			int status = preparedStatement.executeUpdate();
			if (status == 0)
				throw new DAOException("Could not update user, database hasn't change");
		}
		catch (SQLException e) {throw new DAOException(e);}
		finally {close(preparedStatement, connection);}
	}
}
