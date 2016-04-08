dnl **************************************************************************
dnl Define version info
dnl **************************************************************************

m4_define([gf_major_version], [3])
m4_define([gf_minor_version], [18])
m4_define([gf_micro_version], [1])
m4_define([gf_version], [gf_major_version.gf_minor_version.gf_micro_version])

dnl **************************************************************************
dnl Define bugzilla address
dnl **************************************************************************

m4_define([gf_bugzilla_url],
          [https://bugzilla.gnome.org/enter_bug.cgi?product=budgie-helper])

dnl **************************************************************************
dnl Initialize autoconf
dnl **************************************************************************

AC_INIT([budgie-helper], [gf_version], [gf_bugzilla_url])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

dnl **************************************************************************
dnl Set release policy
dnl **************************************************************************

AX_IS_RELEASE([git-directory])

dnl **************************************************************************
dnl Enable debug
dnl **************************************************************************

AX_CHECK_ENABLE_DEBUG([yes])

dnl **************************************************************************
dnl Add warning flags
dnl **************************************************************************

AX_COMPILER_FLAGS([WARN_CFLAGS], [WARN_LDFLAGS])

dnl **************************************************************************
dnl Initialize automake
dnl **************************************************************************

AM_INIT_AUTOMAKE([1.13 no-dist-gzip dist-xz tar-ustar -Wno-portability])
AM_MAINTAINER_MODE([enable])
AM_SILENT_RULES([yes])

dnl **************************************************************************
dnl Initialize libtool
dnl **************************************************************************

LT_INIT
LT_LIB_M

dnl **************************************************************************
dnl Check for required programs
dnl **************************************************************************

AC_PROG_CC
AC_PATH_PROG([GLIB_COMPILE_RESOURCES], [glib-compile-resources])

dnl **************************************************************************
dnl Internationalization
dnl **************************************************************************

AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION([0.19.4])

GETTEXT_PACKAGE=budgie-helper
AC_SUBST([GETTEXT_PACKAGE])
AC_DEFINE_UNQUOTED([GETTEXT_PACKAGE], ["$GETTEXT_PACKAGE"],
                   [Define the gettext package to be used])

dnl **************************************************************************
dnl Desktop settings support
dnl **************************************************************************

GLIB_GSETTINGS

dnl **************************************************************************
dnl Check forrequired packages
dnl **************************************************************************

GTK_REQUIRED=3.15.2
LIBGNOME_DESKTOP_REQUIRED=3.12.0
GLIB_REQUIRED=2.44.0
GSETTINGS_DESKTOP_SCHEMAS_REQUIRED=3.12.0

PKG_CHECK_MODULES([BUDGIE_HELPER], [
  gtk+-3.0 >= $GTK_REQUIRED
])

PKG_CHECK_MODULES([AUTOMOUNT_MANAGER], [
  gtk+-3.0 >= $GTK_REQUIRED
  gsettings-desktop-schemas >= $GSETTINGS_DESKTOP_SCHEMAS_REQUIRED
])

PKG_CHECK_MODULES([DESKTOP_BACKGROUND], [
  gtk+-3.0 >= $GTK_REQUIRED
  gnome-desktop-3.0 >= $LIBGNOME_DESKTOP_REQUIRED
])

PKG_CHECK_MODULES([WORKAROUNDS], [
  glib-2.0 >= $GLIB_REQUIRED
  gtk+-3.0 >= $GTK_REQUIRED
  x11
])

dnl **************************************************************************
dnl Process .in files
dnl **************************************************************************

AC_CONFIG_FILES([
  Makefile

  data/Makefile
  data/autostart/Makefile
  data/schemas/Makefile

  budgie-helper/Makefile
  budgie-helper/libautomount-manager/Makefile
  budgie-helper/libdesktop-background/Makefile
  budgie-helper/libworkarounds/Makefile

  po/Makefile.in
])

AC_OUTPUT

dnl **************************************************************************
dnl Show summary
dnl **************************************************************************

echo ""
echo "  Budgie Helper $VERSION"
echo "  `echo Budgie Helper $VERSION | sed "s/./=/g"`"
echo ""
echo "  srcdir ......................: ${srcdir}"
echo ""
echo "  compiler ....................: ${CC}"
echo "  cflags ......................: ${CFLAGS}"
echo ""
echo "  prefix ......................: ${prefix}"
echo "  exec_prefix .................: ${exec_prefix}"
echo "  libdir ......................: ${libdir}"
echo "  sysconfdir ..................: ${sysconfdir}"
echo "  libexecdir ..................: ${libexecdir}"
echo ""
