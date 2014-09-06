install:
	@echo "Installing Bash Completion.."
	@mkdir -p /etc/bash_completion.d/ 2>/dev/null
	@install -g 0 -o 0 -m 0644 ../bash_completion/todo /etc/bash_completion.d/
	@echo

uninstall:
	@rm -f /etc/bash_completion.d/todo 2>/dev/null
