NAME = fixed
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I include

SRCDIR = src
INCDIR = include
OBJDIR = obj

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))


.PHONY: all clean

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) -r $(OBJDIR) $(NAME)

re: fclean all

.PHONY: all clean fclean re
