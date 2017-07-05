#include "php_myhtml.h"

extern zend_function_entry myhtml_domdocument_methods[];

PHP_MINIT_FUNCTION (myhtml) {
    zend_class_entry domdocument_ce;
    INIT_CLASS_ENTRY(domdocument_ce, "MyHTML\\DOMDocument", myhtml_domdocument_methods);

    zend_string *name = zend_string_init(ZEND_STRL("DOMDocument"), 1);
    zend_string *lc_name = zend_string_tolower(name);
    zend_class_entry *base_ce = zend_hash_find_ptr(CG(class_table), lc_name);
    zend_string_release(lc_name);

    zend_register_internal_class_ex(&domdocument_ce, base_ce);

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