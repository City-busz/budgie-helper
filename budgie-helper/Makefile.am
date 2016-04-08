NULL =

SUBDIRS = \
	libautomount-manager \
	libdesktop-background \
	libworkarounds \
	$(NULL)

bin_PROGRAMS = \
	budgie-helper \
	$(NULL)

budgie_helper_CFLAGS = \
	$(BUDGIE_HELPER_CFLAGS) \
	$(WARN_CFLAGS) \
	$(AM_CFLAGS) \
	-I$(top_builddir)/budgie-helper \
	-DLOCALE_DIR=\""$(localedir)"\" \
	$(NULL)

budgie_helper_SOURCES = \
	gf-application.c \
	gf-application.h \
	gf-main.c \
	gf-session.c \
	gf-session.h \
	$(NULL)

budgie_helper_LDFLAGS = \
	$(WARN_LDFLAGS) \
	$(AM_LDFLAGS) \
	$(NULL)

budgie_helper_LDADD = \
	$(BUDGIE_HELPER_LIBS) \
	$(top_builddir)/budgie-helper/libautomount-manager/libautomount-manager.la \
	$(top_builddir)/budgie-helper/libdesktop-background/libdesktop-background.la \
	$(top_builddir)/budgie-helper/libworkarounds/libworkarounds.la \
	$(NULL)

-include $(top_srcdir)/git.mk
