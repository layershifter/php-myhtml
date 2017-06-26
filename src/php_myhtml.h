#ifndef PHP_MYHTML_H

#define PHP_MYHTML_H

#include "php.h"

#ifdef ZTS
#include "TSRM.h"
#endif

#define PHP_MYHTML_EXTNAME "myhtml"
#define PHP_MYHTML_VERSION "0.1"

extern zend_module_entry myhtml_module_entry;
#define phpext_myhtml_ptr &myhtml_module_entry

#endif