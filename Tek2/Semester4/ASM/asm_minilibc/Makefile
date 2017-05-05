CC	=	gcc -fPIC -shared

NASM	=	nasm -f elf64

RM	=	rm -f

NAME	=	libasm.so

SRCS	=	memmove.S \
		strcasecmp.S \
		strcmp.S \
		strcspn.S \
		strlen.S \
		strncmp.S \
		strpbrk.S \
		strstr.S \
		memcpy.S \
		memset.S \
		rindex.S \
		strchr.S \
		strcpy.S

OBJS	=	$(SRCS:.S=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

.S.o:
		$(NASM) $<

clean:
		$(RM)  $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
