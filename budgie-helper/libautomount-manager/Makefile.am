NULL =

noinst_LTLIBRARIES = \
	libautomount-manager.la \
	$(NULL)

libautomount_manager_la_CFLAGS = \
	$(AUTOMOUNT_MANAGER_CFLAGS) \
	$(WARN_CFLAGS) \
	$(AM_CFLAGS) \
	-I$(top_builddir)/budgie-helper/libautomount-manager \
	$(NULL)

libautomount_manager_la_SOURCES = \
	gsd-automount-manager.c \
	gsd-automount-manager.h \
	gsd-autorun.c \
	gsd-autorun.h \
	$(NULL)

libautomount_manager_la_LDFLAGS = \
	$(WARN_LDFLAGS) \
	$(AM_LDFLAGS) \
	$(NULL)

libautomount_manager_la_LIBADD =	\
	$(AUTOMOUNT_MANAGER_LIBS) \
	$(NULL)

-include $(top_srcdir)/git.mk
