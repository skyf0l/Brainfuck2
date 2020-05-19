##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## My makefile
##

all:
	@(cd sources && make -s)

clean:
	@(cd sources && make clean -s)

fclean:
	@(cd sources && make fclean -s)

re:
	@(cd sources && make re -s)

tests_run:
	@(cd sources && make tests_run -s)

coverage:
	@(cd sources && make coverage -s)

debug:
	@(cd sources && make debug -s)

.PHONY: $(NAME) all clean fclean re tests_run coverage debug