#include "myhtml_domdocument.h"
#include "ext/dom/xml_common.h"
#include "../parser.h"

zend_class_entry *myhtml_domdocument_class_entry;

ZEND_BEGIN_ARG_INFO_EX(arginfo_myhtml_domdocument_loadhtml, 0, 0, 1)
        ZEND_ARG_INFO(0, source)
        ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

zend_function_entry myhtml_domdocument_methods[] = {
    PHP_ME(myhtml_domdocument, loadHTML, arginfo_myhtml_domdocument_loadhtml, ZEND_ACC_PUBLIC)
    {NULL, NULL, NULL}
};

PHP_METHOD (myhtml_domdocument, loadHTML) {
    zend_string *source;
    zend_long options = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "S|l", &source, &options) == FAILURE) {
        RETURN_FALSE;
    }

    int ret;
    xmlDocPtr doc = myhtml_parse_string(source);

    DOM_RET_OBJ((xmlNodePtr) doc, &ret, NULL);
}