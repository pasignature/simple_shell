LISTFILES = ls -l
REMOVE = rm -f *.o *.a *~ *.exe *.exec
GITSTATUS = git status
GITCOMMIT = git commit -m "fixes"
GITPUSH = git push origin andrew
COMPILE_PROGRAM = gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
RUN_SHELL = ./hsh

all:
	@echo "Please wait while compiling Andrew and Mohamed shell program..."
	$(COMPILE_PROGRAM)

l:
	$(LISTFILES)

c:
	$(GITCOMMIT)

p:
	$(GITPUSH)

remote:
	git remote -v

b:
	git branch

s:
	$(GITSTATUS)

run:
	$(RUN_SHELL)

clean:
	@echo "Pls wait while cleaning up garbages..."
	$(REMOVE)
cleanall:
	@echo "Pls wait while cleaning up garbages ALL directories..."
	$(REMOVE)
