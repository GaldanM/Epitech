package Model.Bean;

public class User
{
	private Long    id;
	private boolean admin;
	private String  userName;
	private String  password;
	private String  email;
	private String  lastName;
	private String  firstName;
	private String  address;
	private String  city;
	private String  postal;

	public void     setId(Long id){this.id = id;}
	public Long     getId(){return id;}

	public void     setAdmin(boolean admin){this.admin = admin;}
	public boolean  getAdmin(){return admin;}

	public void     setUserName(String name) {this.userName = name;}
	public String   getUserName() {return userName;}

	public void     setPassword(String password) {this.password = password;}
	public String   getPassword() {return password;}

	public void     setEmail(String email) {this.email = email;}
	public String   getEmail() {return email;}

	public void     setLastName(String lastName) {this.lastName = lastName;}
	public String   getLastName() {return lastName;}

	public void     setFirstName(String firstName) {this.firstName = firstName;}
	public String   getFirstName() {return firstName;}

	public void     setAddress(String address) {this.address = address;}
	public String   getAddress() {return address;}

	public void     setCity(String city) {this.city = city;}
	public String   getCity() {return city;}

	public void     setPostal(String postal) {this.postal = postal;}
	public String   getPostal() {return postal;}
}
