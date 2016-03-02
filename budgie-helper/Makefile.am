NULL =

SUBDIRS = \
	libautomount-manager \
	libbluetooth-applet \
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
	$(BUILT_SOURCES) \
	$(NULL)

budgie_helper_LDFLAGS = \
	$(WARN_LDFLAGS) \
	$(AM_LDFLAGS) \
	$(NULL)

budgie_helper_LDADD = \
	$(BUDGIE_HELPER_LIBS) \
	$(top_builddir)/budgie-helper/libautomount-manager/libautomount-manager.la \
	$(top_builddir)/budgie-helper/libbluetooth-applet/libbluetooth-applet.la \
	$(top_builddir)/budgie-helper/libdesktop-background/libdesktop-background.la \
	$(top_builddir)/budgie-helper/libworkarounds/libworkarounds.la \
	$(NULL)

gf-resources.c: flashback.gresource.xml $(shell $(GLIB_COMPILE_RESOURCES) --sourcedir=$(srcdir) --generate-dependencies $(srcdir)/flashback.gresource.xml)
	$(AM_V_GEN)$(GLIB_COMPILE_RESOURCES) --target=$@ --sourcedir=$(srcdir) --generate --c-name gf $<

gf-resources.h: flashback.gresource.xml $(shell $(GLIB_COMPILE_RESOURCES) --sourcedir=$(srcdir) --generate-dependencies $(srcdir)/flashback.gresource.xml)
	$(AM_V_GEN)$(GLIB_COMPILE_RESOURCES) --target=$@ --sourcedir=$(srcdir) --generate --c-name gf $<

BUILT_SOURCES = \
	gf-resources.c \
	gf-resources.h \
	$(NULL)

EXTRA_DIST = \
	Adwaita.css \
	flashback.gresource.xml \
	HighContrast.css \
	$(NULL)

CLEANFILES = \
	$(BUILT_SOURCES) \
	$(NULL)

-include $(top_srcdir)/git.mk
