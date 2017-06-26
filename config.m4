CFLAGS="$CFLAGS -std=c99"

PHP_ARG_ENABLE(myhtml, whether to enable my_ext support,
[ --enable-myhtml   Enable My Ext support])

if test "$PHP_MYHTML" = "yes"; then
    PHP_NEW_EXTENSION(myhtml, src/myhtml.c, $ext_shared)
    PHP_ADD_BUILD_DIR([$ext_builddir/src/])
fi
