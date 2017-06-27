CFLAGS="$CFLAGS -std=c99"

PHP_ARG_ENABLE(myhtml, whether to enable my_ext support,
[ --enable-myhtml   Enable My Ext support])

if test "$PHP_MYHTML" = "yes"; then
 SEARCH_PATH="/usr/local /usr"
  SEARCH_FOR="/myhtml/api.h"

    AC_MSG_CHECKING([for myhtml files in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        MYHTML_DIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done


  PHP_ADD_INCLUDE($MYHTML_DIR/include)
  PHP_CHECK_LIBRARY(myhtml, myhtml_create,
  [
    PHP_ADD_LIBRARY_WITH_PATH(myhtml, $MYHTML/lib, MYHTML_SHARED_LIBADD)
  ],[
    AC_MSG_ERROR([wrong version of gumbo of it's not found])
  ], [
    -L$MYHTML_DIR/lib -lm
  ])

    PHP_SETUP_LIBXML(MYHTML_SHARED_LIBADD, [
      PHP_NEW_EXTENSION(myhtml, src/myhtml.c src/parser.c src/classes/myhtml_domdocument.c, $ext_shared)
      PHP_ADD_BUILD_DIR([$ext_builddir/src/])
      PHP_ADD_EXTENSION_DEP(dom, libxml)
      PHP_SUBST(MYHTML_SHARED_LIBADD)
    ], [
      AC_MSG_ERROR([xml2-config not found. Please check your libxml2 installation.])
    ])
fi
