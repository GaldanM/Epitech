import java.awt.event.ActionListener;

public abstract class MyActionListener implements ActionListener
{
	public String _digit;

	public MyActionListener(String digit)
	{
		super();
		_digit = digit;
	}
}
