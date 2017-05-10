# COMPIL

CC		=	gcc

CCPP		=	g++

RM		=	rm -f

# NAMES

NAME_SERVER	=	zappy_server

NAME_IA		=	zappy_ai

# FOLDERS_SRC

FOLD_SERVER	=	Server/Sources/

CMDS		=	$(FOLD_SERVER)Commands/

CMDS_IA		=	$(CMDS)IA/

CMDS_GRAPH	=	$(CMDS)Graph/

DIVERS		=	$(FOLD_SERVER)Divers/

EXEC		=	$(FOLD_SERVER)Exec/

INIT		=	$(FOLD_SERVER)Init/

LISTS		=	$(FOLD_SERVER)Lists/

FOLD_IA		=	Client/IA/Sources/

## INCLUDES

INC_SERVER	=	Server/Includes/

INC_IA		=	Client/IA/Includes/

## SOURCES

SRCS_SERVER	=	$(CMDS_IA)broadcast_contain.c \
			$(CMDS_IA)broadcast_rest.c \
			$(CMDS_IA)command_not_found.c \
			$(CMDS_IA)broadcast.c \
			$(CMDS_IA)broadcast_seeks.c \
			$(CMDS_IA)browse_look.c \
			$(CMDS_IA)connect_nbr.c \
			$(CMDS_IA)expulse.c \
			$(CMDS_IA)fork.c \
			$(CMDS_IA)forward.c \
			$(CMDS_IA)get_str_look.c \
			$(CMDS_IA)incantation.c \
			$(CMDS_IA)inventory.c \
			$(CMDS_IA)look.c \
			$(CMDS_IA)put_object.c \
			$(CMDS_IA)take_object.c \
			$(CMDS_IA)turn.c \
			$(CMDS_GRAPH)bct_case.c \
			$(CMDS_GRAPH)bct_map.c \
			$(CMDS_GRAPH)ebo.c \
			$(CMDS_GRAPH)edi.c \
			$(CMDS_GRAPH)eht.c \
			$(CMDS_GRAPH)enw.c \
			$(CMDS_GRAPH)msz.c \
			$(CMDS_GRAPH)pbc.c \
			$(CMDS_GRAPH)pdi.c \
			$(CMDS_GRAPH)pdr.c \
			$(CMDS_GRAPH)pex.c \
			$(CMDS_GRAPH)pfk.c \
			$(CMDS_GRAPH)pgt.c \
			$(CMDS_GRAPH)pic.c \
			$(CMDS_GRAPH)pie.c \
			$(CMDS_GRAPH)pin.c \
			$(CMDS_GRAPH)plv.c \
			$(CMDS_GRAPH)pnw.c \
			$(CMDS_GRAPH)ppo.c \
			$(CMDS_GRAPH)sbp.c \
			$(CMDS_GRAPH)seg.c \
			$(CMDS_GRAPH)sgt.c \
			$(CMDS_GRAPH)smg.c \
			$(CMDS_GRAPH)suc.c \
			$(CMDS_GRAPH)tna.c \
			$(DIVERS)foncs_divers.c \
			$(DIVERS)get_next_line.c \
			$(DIVERS)str_to_tab.c \
			$(EXEC)exec_server.c \
			$(EXEC)main.c \
			$(EXEC)manage_eggs.c \
			$(EXEC)manage_game.c \
			$(EXEC)manage_players.c \
			$(EXEC)read_client.c \
			$(EXEC)read_graph.c \
			$(EXEC)read_ia.c \
			$(EXEC)read_server.c \
			$(INIT)check_options.c \
			$(INIT)init_all.c \
			$(INIT)init_delay.c \
			$(INIT)init_height.c \
			$(INIT)init_options.c \
			$(INIT)init_players.c \
			$(INIT)init_port.c \
			$(INIT)init_team.c \
			$(INIT)init_width.c \
			$(LISTS)foncs_action_list.c \
			$(LISTS)foncs_case_list.c \
			$(LISTS)foncs_egg_list.c \
			$(LISTS)foncs_graph_list.c \
			$(LISTS)foncs_player_list.c

SRCS_IA		=	$(FOLD_IA)Client.cpp \
			$(FOLD_IA)IA.cpp \
			$(FOLD_IA)main.cpp \
			$(FOLD_IA)MyError.cpp \
			$(FOLD_IA)Param.cpp

## OBJS

OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)

OBJS_IA		=	$(SRCS_IA:.cpp=.o)

## FLAGS

CFLAGS		+=	-W -Wall -Wextra -I $(INC_SERVER)

CPPFLAGS	+=	-W -Wall -Wextra -I $(INC_IA)

## RULES

all:			$(NAME_SERVER) $(NAME_IA)

$(NAME_IA):		$(OBJS_IA)
			$(CCPP) $(OBJS_IA) -o $(NAME_IA)

$(NAME_SERVER):		$(OBJS_SERVER)
			$(CC) $(OBJS_SERVER) -o $(NAME_SERVER) -lm

clean:
			@$(RM) $(OBJS_SERVER)
			@$(RM) $(OBJS_IA)

fclean:			clean
			@$(RM) $(NAME_SERVER)
			@$(RM) $(NAME_IA)

re:			fclean all

.PHONY:			all clean fclean re
