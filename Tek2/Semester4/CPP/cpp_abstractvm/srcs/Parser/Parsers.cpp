#include	<fstream>
#include	"Parser.hh"

bool		parse_cmd(std::list<Cmd *> &list)
{
  int		i = 1;
  std::string	line;
  Cmd		*cmd;

  while (std::getline(std::cin, line) && line != ";;")
    {
      cmd = new Cmd(i);
      line = epur_str(line);
      if (line != "")
	{
	  if (fill_cmd(line, cmd))
	    check_cmd(cmd);
	}
      list.push_back(cmd);
      ++i;
    }
  if (check_errors(list))
    return (true);
  return (false);
}

bool		check_name(const char *name)
{
  int		i = 0;

  while (name[i])
    i++;
  i = i - 4;
  if (i <= 0)
    return (false);
  if (name[i] == '.' && name[i + 1] == 'a' && name[i + 2] == 'v' && name[i + 3] == 'm')
    return (true);
  return (false);
}

bool		parse_file(std::list<Cmd *> &list, const char *name)
{
  int		i = 1;
  std::fstream	file;
  std::string	line;
  Cmd		*cmd;

  file.open(name, std::fstream::in);
  if (!file.is_open() || !check_name(name))
    {
      std::cout << "Wrong file !" << std::endl;
      return (false);
    }
  while (std::getline(file, line))
    {
      cmd = new Cmd(i);
      line = epur_str(line);
      if (line != "")
	{
	  if (fill_cmd(line, cmd))
	    check_cmd(cmd);
	}
      list.push_back(cmd);
      ++i;
    }
  file.close();
  if (check_errors(list))
    return (true);
  return (false);
}
