package Controller.Business;

import DAO.DAOException;
import DAO.DAOUser;
import Model.Bean.User;
import org.jasypt.util.password.ConfigurablePasswordEncryptor;

import javax.servlet.http.HttpServletRequest;
import java.util.HashMap;
import java.util.Map;

public class UpdateBusiness
{
	private final   String  ATT_CHAMP_PASS = "password";
	private final   String  ATT_CHAMP_EMAIL = "email";
	private final   String  ATT_CHAMP_LAST = "lastName";
	private final   String  ATT_CHAMP_FIRST = "firstName";
	private final   String  ATT_CHAMP_ADDRESS = "address";
	private final   String  ATT_CHAMP_CITY = "city";
	private final   String  ATT_CHAMP_POSTAL = "postal";
	private final   String  ATT_SESS_USER = "sessionUser";

	private         DAOUser             daoUser;
	private         String              result;
	private         Map<String, String> errors = new HashMap<>();

	public UpdateBusiness(DAOUser daoUser){this.daoUser = daoUser;}

	public User updateUser(HttpServletRequest request)
	{
		User    nouv = new User();
		User    old = (User) request.getSession().getAttribute(ATT_SESS_USER);

		nouv.setUserName(old.getUserName());
		treatPassword(request.getParameter(ATT_CHAMP_PASS), nouv, old);
		treatEmail(request.getParameter(ATT_CHAMP_EMAIL), nouv, old);
		treatLastName(request.getParameter(ATT_CHAMP_LAST), nouv, old);
		treatFirstName(request.getParameter(ATT_CHAMP_FIRST), nouv, old);
		treatAddress(request.getParameter(ATT_CHAMP_ADDRESS), nouv, old);
		treatCity(request.getParameter(ATT_CHAMP_CITY), nouv, old);
		treatPostal(request.getParameter(ATT_CHAMP_POSTAL), nouv, old);

		try
		{
			if (errors.isEmpty())
			{
				daoUser.update(nouv);
				result = "Update successful !";
			}
			else
				result = "Update failed...";
		}
		catch (DAOException e){result = e.getMessage();}

		return nouv;
	}

	private void    treatPassword(String pass, User nouv, User old)
	{
		if (pass != null && !pass.isEmpty())
		{
			try {validatePassword(pass, old.getPassword());}
			catch (BusinessException e) {errors.put(ATT_CHAMP_PASS, e.getMessage());}
		}
		else
			pass = old.getPassword();
		nouv.setPassword(pass);
	}

	private void    validatePassword(String password, String old) throws BusinessException
	{
		if (password.trim().length() != 0)
		{
			if (password.trim().length() < 3)
				throw new BusinessException("Password must be at least 3 characters lenght.");
			ConfigurablePasswordEncryptor passwordEncryptor = new ConfigurablePasswordEncryptor();
			passwordEncryptor.setAlgorithm("SHA-256");
			passwordEncryptor.setPlainDigest(false);
			if (passwordEncryptor.checkPassword(password, old))
				throw new BusinessException("Password is the same as the old one.");
		}
	}

	private void    treatEmail(String email, User nouv, User old)
	{
		if (email != null && !email.isEmpty())
		{
			try {validateEmail(email, old.getEmail());}
			catch (BusinessException e) {errors.put(ATT_CHAMP_EMAIL, e.getMessage());}
		}
		else
			email = old.getEmail();
		nouv.setEmail(email);
	}

	private void    validateEmail(String email, String old) throws BusinessException
	{
		if (email.trim().length() != 0)
		{
			if (!email.matches("([^.@]+)(\\.[^.@]+)*@([^.@]+\\.)+([^.@]+)"))
				throw new BusinessException("Email is not valid.");
			else if (email.equals(old))
				throw new BusinessException("Email is the same as the old one.");
		}
	}

	private void    treatLastName(String lastName, User nouv, User old)
	{
		if (lastName != null && !lastName.isEmpty())
		{
			try
			{
				validateLastName(lastName, old.getEmail());
			} catch (BusinessException e)
			{
				errors.put(ATT_CHAMP_LAST, e.getMessage());
			}
		}
		else
			lastName = old.getLastName();
		nouv.setLastName(lastName);
	}

	private void    validateLastName(String lastName, String old) throws BusinessException
	{
		if (lastName.trim().length() != 0)
		{
			if (lastName.equals(old))
				throw new BusinessException("Lastname is the same as the old one.");
		}
	}
	private void    treatFirstName(String firstName, User nouv, User old)
	{
		if (firstName != null && !firstName.isEmpty())
		{
			try
			{
				validateFirstName(firstName, old.getEmail());
			} catch (BusinessException e)
			{
				errors.put(ATT_CHAMP_FIRST, e.getMessage());
			}
		}
		else
			firstName = old.getFirstName();
		nouv.setFirstName(firstName);
	}

	private void    validateFirstName(String firstName, String old) throws BusinessException
	{
		if (firstName.trim().length() != 0)
		{
			if (firstName.equals(old))
				throw new BusinessException("Firstname is the same as the old one.");
		}
	}

	private void    treatAddress(String address, User nouv, User old)
	{
		if (address != null && !address.isEmpty())
		{
			try
			{
				validateAddress(address, old.getEmail());
			} catch (BusinessException e)
			{
				errors.put(ATT_CHAMP_ADDRESS, e.getMessage());
			}
		}
		else
			address = old.getAddress();
		nouv.setAddress(address);
	}

	private void    validateAddress(String address, String old) throws BusinessException
	{
		if (address.trim().length() != 0)
		{
			if (address.equals(old))
				throw new BusinessException("Address is the same as the old one.");
		}
	}

	private void    treatCity(String city, User nouv, User old)
	{
		if (city != null && !city.isEmpty())
		{
			try
			{
				validateCity(city, old.getEmail());
			} catch (BusinessException e)
			{
				errors.put(ATT_CHAMP_CITY, e.getMessage());
			}
		}
		else
			city = old.getCity();
		nouv.setCity(city);
	}

	private void    validateCity(String city, String old) throws BusinessException
	{
		if (city.trim().length() != 0)
		{
			if (city.equals(old))
				throw new BusinessException("City is the same as the old one.");
		}
	}

	private void    treatPostal(String postal, User nouv, User old)
	{
		if (postal != null && !postal.isEmpty())
		{
			try
			{
				validatePostal(postal, old.getEmail());
			} catch (BusinessException e)
			{
				errors.put(ATT_CHAMP_POSTAL, e.getMessage());
			}
		}
		else
			postal = old.getPostal();
		nouv.setPostal(postal);
	}

	private void    validatePostal(String postal, String old) throws BusinessException
	{
		if (postal.trim().length() != 0)
		{
			if (!postal.matches("^[0-9]{5}"))
				throw new BusinessException("Postal code is 5 digits.");
			else if (postal.equals(old))
				throw new BusinessException("Postal code is the same as the old one.");
		}
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
