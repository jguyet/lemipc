# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/25 15:18:38 by jguyet            #+#    #+#              #
#    Updated: 2017/03/19 04:47:40 by jguyet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STUDENT		=	jguyet

AUTHOR		=	auteur

PROG1		=	lemipc

NAMEBASE    =   $(shell basename $(PROG1) .a)

LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`

MAX_COLS	=	$$(echo "$$(tput cols)-21-$(LENGTHNAME)"|bc)

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

SRCDIR		=

OBJDIR		=	.objs/

INCDIR		=	includes/

LIBFTDIR	=	libft/

INCDIRLIBFT	=	$(LIBFTDIR)/includes/

SRCSPROG1	=	\
				srcs/main.c																	\
				srcs/ipcs/create_ipc_segment.c												\
				srcs/ipcs/get_ipc_segment.c													\
				srcs/ipcs/get_ipc_segment_data.c											\
				srcs/ipcs/remove_ipc_segment.c												\
				srcs/ipcs/ipc_segment_exists.c												\
				srcs/ipcs/ipc_data_wrapper.c												\
				srcs/ipcs/ipc_detache_segment.c												\
				srcs/lemipc_protocol_header.c												\
				srcs/lemipc_player.c														\
				srcs/prepare_lem.c															\
				srcs/lem.c

DSRCSPROG1	=	$(addprefix $(SRCDIR), $(SRCSPROG1))

OBJSPROG1	=	$(addprefix $(OBJDIR), $(DSRCSPROG1:.c=.o))

.SILENT:

all:
	##if test ! -f $(AUTHOR) ; then															\
	##	echo "$(STUDENT)" > $(AUTHOR);														\
	##fi
	if test -f $(PROG1) ; then																\
		echo "make: Nothing to be done for \`all\`.";										\
	else																					\
		$(MAKE) -j $(STUDENT);																\
	fi

$(STUDENT):
	make -C $(LIBFTDIR)
	$(MAKE) $(PROG1)

$(PROG1):	$(OBJDIR) $(OBJSPROG1)
	$(CC) $(FLAGS) -o $(PROG1) $(OBJSPROG1) -L $(LIBFTDIR) -lft
	echo "MAKE    [$(PROG1)]"
	echo "\033[38;5;227mAUTHOR  :\033[0m"
	cat -e $(AUTHOR)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJSPROG1))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@															\
		-I $(INCDIR) -I $(INCDIRLIBFT)
	printf "\r\033[38;5;117m%s\033[38;5;092m%*.*s\033[0m\033[K"								\
	"MAKE    "$(NAMEBASE)" plz wait ..."	$(MAX_COLS)	$(MAX_COLS)	"[$(@)]"

clean:
	echo -en "\r\033[38;5;101mCLEAN  "														\
		"[\033[0m$(NAMEBASE)\033[38;5;101m]\033[K\033[0m";									\
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean:
	echo -en "\r\033[38;5;124mFCLEAN "														\
		"[\033[0m$(NAMEBASE)\033[38;5;124m]\033[K\033[0m";									\
	rm -rf $(PROG1)
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) fclean

re:			fclean all

.PHONY: all clean fclean re
