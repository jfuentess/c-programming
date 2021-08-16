OBJDIR = obj
SRCDIR = src
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(wildcard $(SRCDIR)/*.c))
LIBS = -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
DEPS = $(wildcard $(SRCDIR)/*.h)


bomberman: $(OBJ)
	gcc $^ -o $@ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS) | $(OBJDIR)
	gcc -c $< -o $@

$(OBJDIR):
	mkdir $@

.PHONY: clean
clean:
	-rm -r $(OBJDIR)
	-rm bomberman*
