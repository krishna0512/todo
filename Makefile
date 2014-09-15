# Master MakeFile that calls the other makefiles.
# each subdirectory consists of tis own makefile.
# this divides the task of making the software into modules.

all:
	$(MAKE) -C src/

clear:
	$(MAKE) -C src/ clear

clean:
	$(MAKE) -C src/ clear

install:
	$(MAKE) -C src/ install
	$(MAKE) -C doc/ install
	$(MAKE) -C bash_completion/ install
	@echo
	@echo "Please add this line to your ~/.bashrc or ~/.bash_aliases (for comfort only)"
	@echo "alias t='todo'"
	@echo "Please ensure that the prefix location is in PATH and MANPATH environment variables."


uninstall: clear
	$(MAKE) -C src/ uninstall
	$(MAKE) -C doc/ uninstall
	$(MAKE) -C bash_completion/ uninstall
	@rm -f ~/.todo.txt
