#include "php_myhtml.h"

PHP_MINIT_FUNCTION (myhtml) {
    return SUCCESS;
}

zend_module_entry myhtml_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_MYHTML_EXTNAME,
    NULL,
    PHP_MINIT(myhtml),
    NULL,
    NULL,
    NULL,
    NULL,
    PHP_MYHTML_VERSION,
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(myhtml);