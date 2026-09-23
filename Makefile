PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
MANDIR = $(PREFIX)/share/man/man3

.PHONY: all clean install

all:
	$(MAKE) -C src

clean:
	$(MAKE) -C src clean

install:
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 bin/client_dynamic $(DESTDIR)$(BINDIR)/client
	install -d $(DESTDIR)$(MANDIR)
	install -m 644 man/man3/*.1 $(DESTDIR)$(MANDIR)/
