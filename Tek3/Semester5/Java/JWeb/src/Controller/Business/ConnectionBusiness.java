package Controller.Business;

import DAO.DAOUser;
import Model.Bean.User;
import org.jasypt.util.password.ConfigurablePasswordEncryptor;

import javax.servlet.http.HttpServletRequest;
import java.util.HashMap;
import java.util.Map;

public class ConnectionBusiness
{
	private static final String CHAMP_NAME = "userName";
	private static final String CHAMP_MDP = "password";
	private static final String ALGO_CRYPTO = "SHA-256";

	private DAOUser             daoUser;
	private String              result;
	private Map<String, String> errors = new HashMap<>();

	public ConnectionBusiness(DAOUser daoUser)
	{
		this.daoUser = daoUser;
	}

	public User     logInUser(HttpServletRequest request)
	{
		String  userName = request.getParameter(CHAMP_NAME);
		String  pass = request.getParameter(CHAMP_MDP);

		User    user = null;
		if (userName != null)
			user = daoUser.find(userName);

		try
		{
			treatUserName(userName, user);
			treatPassword(pass, user);
		}
		catch (BusinessException e) {errors.put(CHAMP_NAME, e.getMessage());}

		if (errors.isEmpty())
			result = "Connection successful !";
		else
			result = "Connection failed...";

		return user;
	}

	private void    treatUserName(String userName, User user) throws BusinessException
	{
		if (userName != null)
		{
			if (user == null)
				throw new BusinessException("Incorrect password or username.");
		}
		else
			throw new BusinessException("Enter an username.");
	}

	private void    treatPassword(String pass, User user) throws BusinessException
	{
		if (pass != null)
		{
			ConfigurablePasswordEncryptor passwordEncryptor = new ConfigurablePasswordEncryptor();
			passwordEncryptor.setAlgorithm(ALGO_CRYPTO);
			passwordEncryptor.setPlainDigest( false );

			if (!passwordEncryptor.checkPassword(pass, user.getPassword()))
				throw new BusinessException("Incorrect password or username.");
		}
		else
			throw new BusinessException("Enter a password.");
	}

	public String               getResult()
	{
		return result;
	}

	public Map<String, String>  getErrors()
		{
			return errors;
		}
}
