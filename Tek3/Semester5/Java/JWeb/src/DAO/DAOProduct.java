package DAO;

import Model.Bean.Product;

import java.util.ArrayList;

public interface DAOProduct
{
	Product  getProduct(String name);
	ArrayList<Product> getAccessories();

}
