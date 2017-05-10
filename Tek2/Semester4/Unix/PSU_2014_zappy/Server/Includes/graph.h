#ifndef GRAPH_H_
# define GRAPH_H_

# include "case.h"

typedef struct 		s_graph
{
	char			root;
	int				id;
	struct s_graph	*next;
}					t_graph;

/*
**	FONCS
*/
t_graph         	*init_graph();
e_bool 				push_graph(t_graph**, int);
e_bool 				delete_graph(t_graph**, int);

#endif /* !GRAPH_H_ */