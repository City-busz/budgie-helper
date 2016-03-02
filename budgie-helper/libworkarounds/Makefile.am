NULL =

noinst_LTLIBRARIES = \
	libworkarounds.la \
	$(NULL)

libworkarounds_la_CFLAGS = \
	$(WORKAROUNDS_CFLAGS) \
	$(WARN_CFLAGS) \
	$(AM_CFLAGS) \
	-I$(top_builddir)/budgie-helper/libworkarounds \
	$(NULL)

libworkarounds_la_SOURCES = \
	gf-workarounds.c \
	gf-workarounds.h \
	$(NULL)

libworkarounds_la_LDFLAGS = \
	$(WARN_LDFLAGS) \
	$(AM_LDFLAGS) \
	$(NULL)

libworkarounds_la_LIBADD = \
	$(WORKAROUNDS_LIBS) \
	$(NULL)

-include $(top_srcdir)/git.mk
