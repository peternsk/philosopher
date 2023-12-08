#--- BASIC ---#

NAME    	= philo
CC      	= gcc
FLAGS   	= -Wall -Werror -Wextra -pthread -fsanitize=thread -g
RM      	= rm -rf

#--- GROUP ---#

SRCS_DIR 	= srcs
OBJS_DIR	= objs

SRCS		= 	$(addsuffix .c, $(addprefix $(SRCS_DIR)/parsing/, $(PARSING))) \
				$(addsuffix .c, $(addprefix $(SRCS_DIR)/utils/, $(UTILS))) \
				$(addsuffix .c, $(addprefix $(SRCS_DIR)/utils/, $(PHILO_FUNC)))

OBJS 		= 	$(addprefix ${OBJS_DIR}/, $(subst srcs/,,$(SRCS:.c=.o))) 

PARSING		=	check_dig_arg check_sign_arg parcer ft_atoi philo

PHILO_FUNC	=	

UTILS		=

#--- TARGET ---#

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	@${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@${CC} ${FLAGS} -I ${OBJS} -o ${NAME}

clean: 
	@${RM} ${OBJS_DIR}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
