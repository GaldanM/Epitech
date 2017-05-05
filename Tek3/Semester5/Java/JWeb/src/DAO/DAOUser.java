package DAO;

import Model.Bean.User;

public interface DAOUser
{
	User    find(String userName) throws DAOException;
	void    create(User user) throws DAOException;
	void    update(User nouv) throws DAOException;
}
