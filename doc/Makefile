MAN=todo.1
PREFIX=$(DESTDIR)/usr
MANDIR=$(PREFIX)/share/man

install:
	@echo "Installing Docs and Man Pages.."
	@mkdir -p $(MANDIR)/man1/ 2>/dev/null
	@install --mode=644 $(MAN) $(MANDIR)/man1/ || echo "\033[31m FAILED. \033[39m Try "make PREFIX=~ install" ?"
	@gzip -f $(MANDIR)/man1/$(MAN) || echo "\033[31m FAILED. \033[39m Try "make PREFIX=~ install" ?"

uninstall:
	@rm -f $(MANDIR)/man1/$(MAN).gz 2>/dev/null
