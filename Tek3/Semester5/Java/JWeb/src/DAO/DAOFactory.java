package DAO;

import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class DAOFactory
{

	private static final String PROPERTIES_FILE     = "/DAO/dao.properties";
	private static final String PROPERTY_URL        = "url";
	private static final String PROPERTY_DRIVER     = "driver";
	private static final String PROPERTY_USER       = "user";
	private static final String PROPERTY_PASSWORD   = "password";

	private String              url;
	private String              username;
	private String              password;

	DAOFactory(String url, String username, String password)
	{
		this.url = url;
		this.username = username;
		this.password = password;
	}

	public static DAOFactory getInstance() throws DAOConfigurationException
	{
		Properties properties = new Properties();
		String url;
		String driver;
		String user;
		String password;

		InputStream propertiesFile =  Thread.currentThread().getContextClassLoader().getResourceAsStream(PROPERTIES_FILE);
		if (propertiesFile == null)
			throw new DAOConfigurationException("Properties file " + PROPERTIES_FILE + " could not be found.");

		try
		{
			properties.load(propertiesFile);
			url = properties.getProperty(PROPERTY_URL);
			driver = properties.getProperty(PROPERTY_DRIVER);
			user = properties.getProperty(PROPERTY_USER);
			password = properties.getProperty(PROPERTY_PASSWORD);
		}
		catch (IOException e)
		{
			throw new DAOConfigurationException("Unable to load properties file " + PROPERTIES_FILE, e);
		}

		try
		{
			Class.forName(driver);
		}
		catch (ClassNotFoundException e)
		{
			throw new DAOConfigurationException("Driver not found in the classpath.", e);
		}

		return new DAOFactory(url, user, password);
	}

	public Connection   getConnection() throws SQLException
	{
		return DriverManager.getConnection(url, username, password);
	}

	public DAOUser      getDAOUser()
	{
		return new DAOUserImpl(this);
	}
	public DAOProduct   getDAOProduct() {return new DAOProductImpl(this);}
}