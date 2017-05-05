#ifndef PARSER_HH
# define PARSER_HH

# include	<list>
# include	"Cmd.hh"

std::string	epur_str(const std::string&);
bool		check_cmd(Cmd *);
bool		fill_cmd(const std::string&, Cmd *);
void		display_error(const std::list<Cmd *>::iterator&);
bool		check_errors(std::list<Cmd *> &);

bool		parse_file(std::list<Cmd *>&, const char*);
bool		check_name(const char*);
bool		parse_cmd(std::list<Cmd *>&);

#endif /* !PARSER_HH_ */
