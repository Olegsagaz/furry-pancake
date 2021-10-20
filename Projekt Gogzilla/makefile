CC = clang
NAME = main.c

MKDIR = mkdir -p
PRINT = printf
AR = ar rcs
RM = rm -rf

.DEFAULT_GOAL = all

WFLAGS = -Wall -Wextra -Werror -Wpedantic
DFLAGS = -O1 -g3 -ftrapv -fstandalone-debug
HFLAGS = -I$(INC_DIR)
NCURSES = -lncursesw

COMPILE = $(CC) -std=c11 -pipe $(WFLAGS) $(DFLAGS) $(HFLAGS)

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/

SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(OBJ_DIR):
	@$(MKDIR) $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(COMPILE) -o $@ -c $<
	@$(PRINT) "$< compiled!\n"

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(COMPILE) $(OBJ) -O $(NCURSES) $@
	@$(PRINT) "Program successfuly compiled!\n"

NAME_release = %(NAME)_release.a
OBJ_DIR_release = $(OBJ_DIR)release/

OBJ_DIRS_release = $(DIRS:$(SRC_DIR)%=$(OBJ_DIR_release)%)
OBJ_release = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR_release)%.o)

$(OBJ_DIR_release):
	@$(MKDIR) $(OBJ_DIR) $@ $(OBJ_DIRS_release)

$(OBJ_DIR_release)%.c: $(SRC_DIR)%.c
	@$(COMPILE) -0fast -march=native -flto -o $@ -c $<

$(NAME_release): $(OBJ_DIR_release) $(OBJ_release)
	$(AR) $@ (OBJ_release)

define BUILD_template # 1 - target | 2 - flags
NAME_$1 = $(NAME)_$1.a
BUILD_NAMES += $$(NAME_$1)

OBJ_DIR_$1 = $(OBJ_DIR)$1/
OBJ_DIRS_$1 = $$(DIRS:$(SRC_DIR)%.c=$$(OBJ_DIR_$1)%.o)
OBJ_$1 = $(SRC:(SRC_DIR)%.c=$$(OBJ_DIR_$1)%.o)

$$(OBJ_DIR_$1):
	@$(MKDIR) $$(OBJ_DIR) $$@ $$(OBJ_DIRS_$1)

$$(OBJ_DIR_$1)%.o: $$(SRC_DIR)%.c
	@$(COMPILE) $2 -o $$@ -c $$<

$$(NAME_$1): $$(OBJ_DIR_$1) $$(OBJ_$1)
	@$(AR) $$@ $$(OBJ_$1)
endef

define LIB_template # 1 -  include path  | 2 - link path | 3 - link name
IFLAGS  += $(foreach f, $1, $(f:%=-I%))
LFLAGS  += $(foreach f, $2, $(f:%=-L%))
lFLAGS  += $(foreach f, $3, $(f:%=-l%))
endef

define DEPENDENCY_template # 1 - name | 2 - directory
.PHONY: $1
LIB_$1 = $1

BUILD_LIBS += $1
CLEAN_LIBS += clean_$1
UNINSTALL_LIBS += uninstall_$1

$$(LIB_$1):
	@$(MAKE) -sf Makefile -C  $2

clean_$1:
	@$(MAKE) -sf Makefile -C  $2 clean

uninstall_$1:
	@$(MAKE) -sf Makefile -C $2 uninstall
endef

all: $(BUILD_LIBS) $(BUILD_NAMES)

clean: $(CLEAN_LIBS)
	@$(RM) $(OBJ_DIR)

uninstall: $(UNINSTALL_LIBS)
	@$(RM) $(OBJ_DIR) $(BUILD_NAMES)

reinstall: uninstall all