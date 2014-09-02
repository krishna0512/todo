# Master MakeFile that calls the other makefiles.
# each subdirectory consists of tis own makefile.
# this divides the task of making the software into modules.

clear:
	$(MAKE) -C src/ clear

clean:
	$(MAKE) -C src/ clear

install:
	$(MAKE) -C src/ install
	$(MAKE) -C doc/ install
	@echo
	@echo "Please add this line to your ~/.bashrc or ~/.bash_aliases (for comfort only)"
	@echo "alias t='todo'"
	

uninstall: clear
	$(MAKE) -C src/ uninstall
	$(MAKE) -C doc/ uninstall
	@rm -rf ~/.todo.txt 2>/dev/null
