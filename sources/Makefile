##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## My makefile
##

# ========================= VAR ========================= #

NAME = brainfuck2

BIN_SRC = ../bf2

MAIN_SRC = src/main.c

SRC = $(filter-out $(MAIN_SRC), $(shell find src/ -name *.c))

TEST_NAME = unit_tests

TESTS_SRC = $(shell find tests/ -name *.c)

LIBS =

CFLAGS = -Wall -Wextra

IFLAGS = -I./include

LFLAGS =

TESTS_FLAGS = -lcriterion --coverage

OTHER_FLAGS =

# ======================================================= #

## echo
ECHO = echo -e

NO_COLOR = \x1b[0m
OK_COLOR = \x1b[32;01m
ERROR_COLOR = \x1b[31;01m
WARN_COLOR = \x1b[33;01m

OK_STRING = $(OK_COLOR)[✔]$(NO_COLOR)
ERROR_STRING = $(ERROR_COLOR)[X]$(NO_COLOR)
WARN_STRING = $(WARN_COLOR)[!]$(NO_COLOR)

## shell
CC = gcc -fdiagnostics-color=always
RM = rm -f

## obj
MAIN_OBJ = $(MAIN_SRC:.c=.o)
OBJ = $(SRC:.c=.o)
TESTS_OBJ = $(TESTS_SRC:.c=.o)

## flag
IFLAGS += $(addprefix -I./include/lib/, $(LIBS))
TMP_LFLAGS += $(addsuffix .a, $(addprefix lib/lib, $(LIBS)))
LFLAGS := $(LFLAGS) $(addprefix -L. , $(TMP_LFLAGS))

## tests
TEST_BUILD = *.gcno *.gcda *.cor

## build
BUILD_WARN_LOG = build_warn.log
BUILD_ERROR_LOG = build_error.log
LOGS = $(BUILD_WARN_LOG) $(BUILD_ERROR_LOG)

## rules
all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) $(OTHER_FLAGS) -c $< -o $@ 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(MAKE) -s check_error

check_error:
	@if [ -e $(BUILD_ERROR_LOG) ] && [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(ERROR_STRING) "; \
		cat $(BUILD_WARN_LOG); \
		$(RM) $(BUILD_ERROR_LOG); \
	elif [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(WARN_STRING) "; \
		cat $(BUILD_WARN_LOG); \
	fi

$(NAME): make_lib $(OBJ) $(MAIN_OBJ)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OTHER_FLAGS) -o $(BIN_SRC) $(OBJ) $(MAIN_OBJ) $(LFLAGS) 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(call print_build_status, $@)

make_lib:
	@for i in $(LIBS); do \
		(cd lib/$$i/ && make -s); \
	done

make_debug_lib:
	@for i in $(LIBS); do \
		(cd lib/$$i/ && make -s CFLAGS='-Wall -Wextra -g'); \
	done

fclean_not_lib:
	@$(RM) $(TEST_BUILD) vgcore.*
	@$(RM) $(LOGS)
	@$(RM) $(OBJ) $(MAIN_OBJ) $(TESTS_OBJ)
	@$(RM) $(BIN_SRC) $(TEST_NAME)

clean:
	@for i in $(LIBS); do \
		(cd lib/$$i/ && make -s clean) > /dev/null; \
	done
	@$(RM) $(OBJ) $(MAIN_OBJ) $(TESTS_OBJ)
	@$(RM) $(LOGS)
	@$(RM) $(TEST_BUILD) vgcore.*
	@$(ECHO) "$(OK_STRING) $(NAME) -> $@"

fclean:
	@$(MAKE) clean > /dev/null
	@for i in $(LIBS); do \
		(cd lib/$$i/ && make -s fclean) > /dev/null; \
	done
	@$(RM) $(BIN_SRC) $(TEST_NAME)
	@$(ECHO) "$(OK_STRING) $(NAME) -> $@"

re: fclean_not_lib all

tests_run: make_lib $(TESTS_OBJ)
	@$(RM) $(TEST_BUILD) $(TEST_NAME)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OTHER_FLAGS) -o $(TEST_NAME) $(SRC) $(TESTS_OBJ) $(LFLAGS) $(TESTS_FLAGS) 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(call print_build_status, $@)
	@./$(TEST_NAME)

coverage: tests_run
	gcovr --exclude tests/

debug: fclean make_debug_lib
	@$(CC) -g3 $(CFLAGS) $(IFLAGS) $(OTHER_FLAGS) -o $(BIN_SRC) $(SRC) $(MAIN_SRC) $(LFLAGS) 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(call print_build_status, $@)

define print_build_status
	@if [ -e $(BUILD_ERROR_LOG) ] && [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(ERROR_STRING) "; \
		cat $(BUILD_WARN_LOG); \
		$(ECHO) "$(ERROR_STRING) $(NAME) -> $1"; \
		$(RM) $(BUILD_ERROR_LOG); \
	elif [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(WARN_STRING) "; \
		cat $(BUILD_WARN_LOG); \
		$(ECHO) "$(WARN_STRING) $(NAME) -> $1"; \
	else \
		$(ECHO) "$(OK_STRING) $(NAME) -> $1"; \
	fi
endef

.PHONY: $(NAME) all clean fclean re tests_run coverage debug