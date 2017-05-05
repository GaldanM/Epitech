package DAO;

import Model.Bean.Product;
import Model.Bean.User;
import javafx.util.Pair;
import org.jasypt.util.password.ConfigurablePasswordEncryptor;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class DAOUtils
{
	public static PreparedStatement initRequest(Connection connexion, String sql, boolean returnGeneratedKeys, Object... objets) throws SQLException
	{
		PreparedStatement preparedStatement = connexion.prepareStatement(sql, returnGeneratedKeys ? Statement.RETURN_GENERATED_KEYS : Statement.NO_GENERATED_KEYS);
		for (int i = 0; i < objets.length; i++)
			preparedStatement.setObject(i + 1, objets[i]);
		return preparedStatement;
	}

	public static User fillUser(ResultSet resultSet) throws SQLException
	{
		User user = new User();

		user.setId(resultSet.getLong("id"));
		user.setAdmin(resultSet.getBoolean("isAdmin"));
		user.setUserName(resultSet.getString("userName"));
		user.setPassword(resultSet.getString("password"));
		user.setEmail(resultSet.getString("email"));
		user.setLastName(resultSet.getString("lastName"));
		user.setFirstName(resultSet.getString("firstName"));
		user.setAddress(resultSet.getString("address"));
		user.setCity(resultSet.getString("city"));
		user.setPostal(resultSet.getString("postal"));

		return user;
	}

	public static Product fillProduct(ResultSet resultSet) throws SQLException
	{
		Product prod = new Product();

		prod.setId(resultSet.getLong("id"));
		prod.setName(resultSet.getString("name"));
		prod.setPrice(resultSet.getDouble("price"));
		prod.setImgPath(resultSet.getString("imgPath"));
		prod.setType(resultSet.getBoolean("type"));

		return prod;
	}

	public static void silentClose(ResultSet resultSet)
	{
		if (resultSet != null)
		{
			try {resultSet.close();}
			catch (SQLException e) {System.out.println("Échec de la fermeture du ResultSet : " + e.getMessage());}
		}
	}

	public static void silentClose(Statement statement)
	{
		if (statement != null)
		{
			try {statement.close();}
			catch (SQLException e) {System.out.println("Échec de la fermeture du Statement : " + e.getMessage());}
		}
	}

	public static void silentClose(Connection connexion)
	{
		if (connexion != null)
		{
			try {connexion.close();}
			catch (SQLException e) {System.out.println("Échec de la fermeture de la connexion : " + e.getMessage());}
		}
	}

	public static void close(Statement statement, Connection connexion)
	{
		silentClose(statement);
		silentClose(connexion);
	}

	public static void close(ResultSet resultSet, Statement statement, Connection connexion)
	{
		silentClose(resultSet);
		silentClose(statement);
		silentClose(connexion);
	}

}