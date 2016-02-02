NULL =

SUBDIRS = \
	applications \
	autostart \
	directories \
	menus \
	schemas \
	sessions \
	xsessions \
	$(NULL)

libexec_SCRIPTS = \
	budgie-helper-compiz \
	budgie-helper-metacity \
	$(NULL)

budgie-helper-compiz: Makefile
	$(AM_V_GEN) (echo '#!/bin/sh' && echo '' && \
	             echo 'if [ -z $$XDG_CURRENT_DESKTOP ]; then' && \
	             echo '  export XDG_CURRENT_DESKTOP="Budgie:GNOME"' && \
	             echo 'fi' && echo '' && \
	             echo 'exec gnome-session --session=budgie-helper-compiz "$$@"') > $@
	$(AM_V_at) chmod a+x $@

budgie-helper-metacity: Makefile
	$(AM_V_GEN) (echo '#!/bin/sh' && echo '' && \
	             echo 'if [ -z $$XDG_CURRENT_DESKTOP ]; then' && \
	             echo '  export XDG_CURRENT_DESKTOP="Budgie:GNOME"' && \
	             echo 'fi' && echo '' && \
	             echo 'exec gnome-session --session=budgie-helper-metacity --disable-acceleration-check "$$@"') > $@
	$(AM_V_at) chmod a+x $@

CLEANFILES = \
	budgie-helper-compiz \
	budgie-helper-metacity \
	$(NULL)

-include $(top_srcdir)/git.mk
