# Cannot add any prefixes. This will fail for no prefix and is lite for now. This cannot be put in too many places.

install:
	@echo "Installing Bash Completion.."
	@mkdir -p /etc/bash_completion.d/ 2>/dev/null
	@install -g 0 -o 0 -m 0644 todo /etc/bash_completion.d/ || echo "\033[31m FAILED. \033[39m Need root level access for installing BASH Completion Module"

uninstall:
	@rm -f /etc/bash_completion.d/todo 2>/dev/null
