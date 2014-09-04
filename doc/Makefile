install:
	@echo "Installing Docs and Man Pages.."
	@mkdir -p /usr/local/man/man1/ 2>/dev/null
	@install -g 0 -o 0 -m 0644 ../doc/todo.1 /usr/local/man/man1/
	@gzip -f /usr/local/man/man1/todo.1
	@echo

uninstall:
	@rm -rf /usr/local/man/man1/todo.1.gz 2>/dev/null
