package theleatherguy.contactsmanager.model;

public class Contact {
	private int id;
	private String firstName;
	private String lastName;
	private String homePhone;
	private String mobilePhone;
	private String email;

	public Contact() {
		firstName = "";
		lastName = "";
		homePhone = "";
		mobilePhone = "";
		email = "";
	}

	public Contact(int nId, String fN, String lN, String hP, String mP, String mail) {
		super();
		id = nId;
		firstName = fN;
		lastName = lN;
		homePhone = hP;
		mobilePhone = mP;
		email = mail;
	}

	public int getId() {
		return id;
	}
	public void setId(int newId) {
		id = newId;
	}
	
	public String getFirstName() {
		return firstName;
	}
	public void setFirstName(String newFirstName) {
		firstName = newFirstName;
	}

	public String getLastName() {
		return lastName;
	}
	public void setLastName(String newLastName) {
		lastName = newLastName;
	}

	public String getHomePhone() {
		return homePhone;
	}
	public void setHomePhone(String newHomePhone) {
		homePhone = newHomePhone;
	}

	public String getMobilePhone() {
		return mobilePhone;
	}
	public void setMobilePhone(String newMobilePhone) {
		mobilePhone = newMobilePhone;
	}

	public String getEmail() {
		return email;
	}
	public void setEmail(String newEmail) {
		email = newEmail;
	}
}
