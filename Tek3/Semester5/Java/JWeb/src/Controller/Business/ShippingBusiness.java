package Controller.Business;

import javax.servlet.http.HttpServletRequest;
import java.util.HashMap;
import java.util.Map;

public class ShippingBusiness
{
	private Map<String, String> errors = new HashMap<>();

	public void treatRequest(HttpServletRequest request)
	{
		if (request.getParameter("address").isEmpty())
			errors.put("address", "Enter phone number please");
		else if (request.getParameter("city").isEmpty())
			errors.put("city", "Enter city please");
		else if (request.getParameter("postal").isEmpty())
			errors.put("postal", "Enter postal please");
		else if (request.getParameter("phone").isEmpty())
			errors.put("phone", "Enter phone please");
	}

	public Map<String, String>    getErrors()
	{
		return errors;
	}
}
