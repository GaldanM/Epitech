package Controller.Business;

import DAO.DAOException;
import DAO.DAOProduct;
import Model.Bean.Product;

import java.util.ArrayList;
import java.util.List;

public class CartBusiness
{
	private DAOProduct  daoProduct;
	private String      result = null;

	public CartBusiness(DAOProduct daoProduct) {this.daoProduct = daoProduct;}

	public void     addToCart(String name, List<Product> list)
	{
		int i = 0;
		Product prod;

		while (i < list.size() && !name.equals(list.get(i).getName()))
			++i;

		if (i < list.size())
		{
			prod = list.get(i);
			prod.setNumber(prod.getNumber() + 1);
		}
		else
		{
			try
			{
				prod = daoProduct.getProduct(name);
				prod.setNumber(1);
				list.add(prod);
			}
			catch (DAOException e) {result = e.getMessage();}
		}
	}

	public ArrayList<Product>   getAccessories()
	{
		return daoProduct.getAccessories();
	}

	public String   getResult() {return result;}
}
