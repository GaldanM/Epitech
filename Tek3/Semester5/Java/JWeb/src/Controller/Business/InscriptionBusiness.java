package Controller.Business;

import DAO.DAOException;
import DAO.DAOUser;
import Model.Bean.User;
import org.jasypt.util.password.ConfigurablePasswordEncryptor;

import javax.servlet.http.HttpServletRequest;
import java.util.HashMap;
import java.util.Map;

public class InscriptionBusiness
{
	private static final String CHAMP_NOM = "userName";
	private static final String CHAMP_MDP = "password";
	private static final String CHAMP_CONF = "confirmation";
	private static final String CHAMP_EMAIL = "email";
	private static final String ALGO_CRYPTO = "SHA-256";

	private DAOUser             daoUser;
	private String              result;
	private Map<String, String> errors = new HashMap<>();

	public InscriptionBusiness(DAOUser daoUser)
	{
		this.daoUser = daoUser;
	}

	public User     signUpUser(HttpServletRequest request)
	{
		String  userName = request.getParameter(CHAMP_NOM);
		String  mdp = request.getParameter(CHAMP_MDP);
		String  conf = request.getParameter(CHAMP_CONF);
		String  email = request.getParameter(CHAMP_EMAIL);

		User user = new User();

		try
		{
			treatUserName(userName, user);
			treatPassword(mdp, conf, user);
			treatEmail(email, user);

			if (errors.isEmpty())
			{
				daoUser.create(user);
				result = "Inscription successful !";
			}
			else
				result = "Inscription failed...";
		}
		catch (DAOException e) {result = "Unable to sign up, try again later.";}

		return user;
	}

	private void    treatUserName(String userName, User user)
	{
		try {validateUserName(userName);}
		catch (BusinessException e) {errors.put(CHAMP_NOM, e.getMessage());}
		user.setUserName(userName);
	}

	private void    treatPassword(String password, String conf, User user)
	{
		try {validatePassword(password, conf);}
		catch (BusinessException e) {errors.put(CHAMP_MDP, e.getMessage());}

		ConfigurablePasswordEncryptor passwordEncryptor = new ConfigurablePasswordEncryptor();
		passwordEncryptor.setAlgorithm(ALGO_CRYPTO);
		passwordEncryptor.setPlainDigest(false);

		user.setPassword(passwordEncryptor.encryptPassword(password));
	}

	private void    treatEmail(String email, User user)
	{
		try {validateEmail(email);}
		catch (BusinessException e) {errors.put(CHAMP_EMAIL, e.getMessage());}
		user.setEmail(email);
	}

	private void    validateUserName(String nom) throws BusinessException
	{
		if (nom != null && nom.trim().length() != 0)
		{
			if (nom.trim().length() < 3)
				throw new BusinessException("Username must be at least 3 characters.");
			else if (daoUser.find(nom) != null)
				throw new BusinessException("Username already exists.");
		}
		else
			throw new BusinessException("Enter an username please.");
	}

	private void    validatePassword(String mdp, String conf) throws BusinessException
	{
		if (mdp != null && mdp.trim().length() != 0
				&& conf != null && conf.trim().length() != 0)
		{
			if (!mdp.equals(conf))
				throw new BusinessException("Passwords don't match, try again please.");
			else if (mdp.trim().length() < 3)
				throw new BusinessException("Password must be at least 3 characters.");
		}
		else
			throw new BusinessException("Confirm your password please.");
	}

	private void    validateEmail(String email) throws BusinessException
	{
		if (email != null && email.trim().length() != 0)
		{
			if (!email.matches("([^.@]+)(\\.[^.@]+)*@([^.@]+\\.)+([^.@]+)"))
				throw new BusinessException("Email is not valid.");
		}
		else
			throw new BusinessException( "Enter your email address please." );
	}

	public String   getResult()
	{
		return result;
	}

	public Map<String, String>  getErrors()
	{
		return errors;
	}
}
