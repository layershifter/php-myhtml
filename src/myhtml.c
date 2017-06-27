#include "php_myhtml.h"

extern zend_class_entry *myhtml_domdocument_class_entry;
extern zend_function_entry myhtml_domdocument_methods[];


PHP_MINIT_FUNCTION (myhtml) {
    zend_class_entry domdocument_entry;
    INIT_CLASS_ENTRY(domdocument_entry, "MyHTML\\DOMDocument", myhtml_domdocument_methods);

    myhtml_domdocument_class_entry = zend_register_internal_class(&domdocument_entry);

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