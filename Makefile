PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
LIBDIR = $(PREFIX)/lib
MANDIR = $(PREFIX)/share/man/man3

.PHONY: all clean install

all:
	$(MAKE) -C src

clean:
	$(MAKE) -C src clean

install: all
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 bin/client_dynamic $(DESTDIR)$(BINDIR)/client
	install -d $(DESTDIR)$(LIBDIR)
	install -m 755 lib/libmyutils.so $(DESTDIR)$(LIBDIR)/libmyutils.so
	install -d $(DESTDIR)$(MANDIR)
	for page in man/man3/*.1; do \
		name=$$(basename "$$page" .1); \
		install -m 644 "$$page" "$(DESTDIR)$(MANDIR)/$$name.3"; \
	done
	if [ -z "$(DESTDIR)" ]; then \
		ldconfig; \
		mandb >/dev/null 2>&1 || true; \
	fi
