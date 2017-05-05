package Model.Bean;

public class Product
{
	private Long    id;
	private String  name;
	private Double  price;
	private String  imgPath;
	private boolean type;
	private Integer number;

	public void     setId(Long id) {this.id = id;}
	public Long     getId(){return id;}

	public void     setName(String name) {this.name = name;}
	public String   getName(){return name;}

	public void     setPrice(Double price) {this.price = price;}
	public Double   getPrice(){return price;}

	public void     setImgPath(String imgPath) {this.imgPath = imgPath;}
	public String   getImgPath(){return imgPath;}

	public void     setType(boolean type) {this.type = type;}
	public boolean  getType(){return type;}

	public void     setNumber(Integer num) {this.number = num;}
	public Integer  getNumber() {return number;}
}
