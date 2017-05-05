#include		"Parser.hh"
#include		"Calculator.hh"

int			main(int argc, char **argv)
{
  std::list<Cmd *>	list;
  Calculator		fonc;

  try
    {
      if (argc > 1)
	{
	  if (!parse_file(list, argv[1]))
	    return(-1);
	}
      else
	{
	  if (!parse_cmd(list))
	    return (-1);
	}
      fonc.exec_cmd(list);
    }
  catch(const std::exception &e)
    {
      std::cout << e.what();
      return (-1);
    }
  return (0);
}
