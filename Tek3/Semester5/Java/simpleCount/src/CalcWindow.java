import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.text.DecimalFormat;

public class CalcWindow extends JFrame
{
	private String  _number = "0";
	private String  _nb1;
	private boolean _nb1Fill = false;
	private String  _op = "";
	private JPanel  rootPanel;
	private JPanel  buttonsPanel;
	private JPanel  displayPanel;
	private JButton bZero;
	private JButton bOne;
	private JButton bTwo;
	private JButton bThree;
	private JButton bFour;
	private JButton bFive;
	private JButton bSix;
	private JButton bSeven;
	private JButton bEight;
	private JButton bNine;
	private JButton bDecimal;
	private JButton bAdd;
	private JButton bSub;
	private JButton bMul;
	private JButton bDiv;
	private JButton bModulo;
	private JButton bRes;
	private JButton bReset;
	private JButton bBack;
	private JTextField textRes;
	private JTextField textOperation;
	private JButton bPowerN;
	private JButton bPowerTriple;
	private JButton bSquare;
	private JButton bRoot;
	private JButton bLog;
	private JButton bExp;
	private JButton bCos;
	private JButton bSin;
	private JButton bTan;
	private JButton bResNum;

	public CalcWindow()
	{
		super("OptiCalc");

		setWidgets();
		setListeners();

		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		setMinimumSize(new Dimension(520, 500));
		setContentPane(rootPanel);
		pack();
		setVisible(true);
	}

	private void    setWidgets()
	{
		textRes.setText(_number);
		bindButton(bZero, KeyEvent.VK_NUMPAD0);
		bindButton(bOne, KeyEvent.VK_NUMPAD1);
		bindButton(bTwo, KeyEvent.VK_NUMPAD2);
		bindButton(bThree, KeyEvent.VK_NUMPAD3);
		bindButton(bFour, KeyEvent.VK_NUMPAD4);
		bindButton(bFive, KeyEvent.VK_NUMPAD5);
		bindButton(bSix, KeyEvent.VK_NUMPAD6);
		bindButton(bSeven, KeyEvent.VK_NUMPAD7);
		bindButton(bEight, KeyEvent.VK_NUMPAD8);
		bindButton(bNine, KeyEvent.VK_NUMPAD9);
		bindButton(bDecimal, KeyEvent.VK_DECIMAL);
		bindButton(bBack, KeyEvent.VK_BACK_SPACE);
		bindButton(bAdd, KeyEvent.VK_ADD);
		bindButton(bSub, KeyEvent.VK_SUBTRACT);
		bindButton(bMul, KeyEvent.VK_MULTIPLY);
		bindButton(bDiv, KeyEvent.VK_DIVIDE);
		bindButton(bRes, KeyEvent.VK_ENTER);
	}

	private void    bindButton(JButton button, int valKey)
	{
		InputMap im = button.getInputMap(JComponent.WHEN_IN_FOCUSED_WINDOW);
		ActionMap am = button.getActionMap();
		im.put(KeyStroke.getKeyStroke(valKey, 0), "clickMe");
		am.put("clickMe", new AbstractAction()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				JButton btn = (JButton) e.getSource();
				btn.doClick();
			}
		});
	}

	private void    setListeners()
	{
		setListenerButtonNum(bZero, "0");
		setListenerButtonNum(bOne, "1");
		setListenerButtonNum(bTwo, "2");
		setListenerButtonNum(bThree, "3");
		setListenerButtonNum(bFour, "4");
		setListenerButtonNum(bFive, "5");
		setListenerButtonNum(bSix, "6");
		setListenerButtonNum(bSeven, "7");
		setListenerButtonNum(bEight, "8");
		setListenerButtonNum(bNine, "9");
		setListenerButtonOp(bAdd, "+");
		setListenerButtonOp(bSub, "-");
		setListenerButtonOp(bMul, "×");
		setListenerButtonOp(bDiv, "÷");
		setListenerButtonOp(bModulo, "%");
		setListenerButtonOp(bPowerN, "^");
		setListenerButtonScientific(bSquare, "sqr");
		setListenerButtonScientific(bPowerTriple, "powT");
		setListenerButtonScientific(bRoot, "√");
		setListenerButtonScientific(bLog, "log");
		setListenerButtonScientific(bExp, "Exp");
		setListenerButtonScientific(bCos, "cos");
		setListenerButtonScientific(bSin, "sin");
		setListenerButtonScientific(bTan, "tan");
		bDecimal.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				if (_number.length() < 15 && !_number.contains("."))
				{
					_number += ".";
					dispText(_number);
				}
			}
		});
		bBack.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				if (!_number.isEmpty())
					_number = _number.substring(0, _number.length() - 1);
				if (_number.isEmpty())
					_number = "0";
				dispText(_number);
			}
		});
		bRes.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				if (_nb1Fill && !_op.isEmpty() && !_number.isEmpty())
				{
					double nb1 = Double.parseDouble(_nb1);
					double nb2 = Double.parseDouble(_number);

					switch (_op)
					{
						case "+":
							nb1 += nb2;
							break;
						case "-":
							nb1 -= nb2;
							break;
						case "×":
							nb1 *= nb2;
							break;
						case "÷":
							if (nb2 == 0)
								nb1 = 0;
							else
								nb1 /= nb2;
							break;
						case "%":
							if (nb2 == 0)
								nb1 = 0;
							else
								nb1 %= nb2;
							break;
						case "^":
							nb1 = Math.pow(nb1, nb2);
					}
					_number = new DecimalFormat("#.########").format(nb1);
					_number = _number.replace(',', '.');
					_nb1 = "";
					_nb1Fill = false;
					_op = "";
					dispText(_number);
					dispOperation();
				}
			}
		});
		bReset.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				_number = "0";
				_nb1 = "";
				_nb1Fill = false;
				_op = "";
				dispOperation();
				dispText(_number);
			}
		});
		bResNum.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				_number = "0";
				dispText(_number);
			}
		});
	}

	private void    setListenerButtonNum(JButton btn, String digit)
	{
		btn.addActionListener(new MyActionListener(digit)
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				if (_number.length() < 16)
				{
					if (_number.equals("0"))
						_number = _digit;
					else
						_number += _digit;
					dispText(_number);
				}
				else
					Toolkit.getDefaultToolkit().beep();
			}
		});
	}

	private void    setListenerButtonOp(JButton btn, String op)
	{
		btn.addActionListener(new MyActionListener(op)
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				if (_number.length() < 17)
				{
					if (!_nb1Fill)
					{
						_nb1Fill = true;
						_nb1 = _number;
						_number = "0";
						dispText(_number);
						_op = _digit;
					}
					else if (!_op.equals(""))
					{
						bRes.doClick();
						_nb1 = _number;
						_nb1Fill = true;
						_number = "0";
					}
					if (_number.equals("0"))
						_op = _digit;
					dispOperation();
				}
				else
					Toolkit.getDefaultToolkit().beep();
			}
		});
	}

	private void    setListenerButtonScientific(JButton btn, String op)
	{
		btn.addActionListener(new MyActionListener(op)
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				double nb = 0;

				switch (_digit)
				{
					case "sqr":
						nb = Math.pow(Double.parseDouble(_number), 2);
						_nb1 = _digit + "(" + _number + ")";
						break;

					case "powT":
						nb = Math.pow(Double.parseDouble(_number), 3);
						_nb1 = _number + " ^ 3";
						break;

					case "√":
						nb = Math.sqrt(Double.parseDouble(_number));
						_nb1 = "√(" + _number + ")";
						break;

					case "log":
						nb = Math.log10(Double.parseDouble(_number));
						_nb1 = "log(" + _number + ")";
						break;

					case "Exp":
						nb = Math.exp(Double.parseDouble(_number));
						_nb1 = "Exp(" + _number + ")";
						break;

					case "cos":
						nb = Math.cos(Double.parseDouble(_number));
						_nb1 = "cos(" + _number + ")";
						break;

					case "sin":
						nb = Math.sin(Double.parseDouble(_number));
						_nb1 = "sin(" + _number + ")";
						break;

					case "tan":
						nb = Math.tan(Double.parseDouble(_number));
						_nb1 = "tan(" + _number + ")";
						break;
				}
				if (_number.length() < 15)
				{
					if (_number.equals("0") && _digit.equals("log"))
						Toolkit.getDefaultToolkit().beep();
					else
					{
						_number = new DecimalFormat("#.########").format(nb);
						_number = _number.replace(',', '.');
						dispText(_number);
						dispOperation();
					}
				}
				else
					Toolkit.getDefaultToolkit().beep();
			}
		});
	}

	private void    dispOperation()
	{
		String operation;

		operation = getStringFormatted(_nb1) + " " + _op;
		textOperation.setText(operation);
	}

	private void    dispText(String num)
	{
		String      number;

		number = getStringFormatted(num);
		textRes.setText(number);
	}

	private String  getStringFormatted(String num)
	{
		String toDisp = num;
		int i = toDisp.indexOf(".");

		if (num.matches("-?\\d+(\\.\\d+)?"))
		{
			if (i == -1)
				i = toDisp.length();
			for (int j = 0; i > 0; ++j, --i)
			{
				if (j == 3)
				{
					toDisp = new StringBuilder(toDisp).insert(i, " ").toString();
					j = 0;
				}
			}
		}
		return (toDisp);
	}
}
