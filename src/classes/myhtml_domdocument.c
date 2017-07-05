#include "myhtml_domdocument.h"
#include "ext/dom/xml_common.h"
#include "../dom.h"
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

    xmlDocPtr document = myhtml_parse_string(source);
    xmlNodePtr object = (xmlNodePtr) document;

//    zval *retval;
//    object_init_ex(retval, NULL);
//
//    zend_string *name = zend_string_init(ZEND_STRL("DOMDocument"), 1);
//    zend_string *lc_name = zend_string_tolower(name);
//    zend_class_entry *base_ce = zend_hash_find_ptr(CG(class_table), lc_name);
//    zend_string_release(lc_name);
//
//    myhtml_dom_set_classmap(retval, base_ce, myhtml_domdocument_class_entry);

//    php_dom_create_object((xmlNodePtr) doc, return_value,  Z_DOMOBJ_P(retval));

    object_init_ex(return_value, myhtml_domdocument_class_entry);
//    dom_object *intern =  Z_DOMOBJ_P(return_value);
//
//    if (obj->doc != NULL) {
//        php_libxml_increment_doc_ref((php_libxml_node_object *)intern, obj->doc);
//    }
//
//    php_libxml_increment_node_ptr((php_libxml_node_object *)intern, obj, (void *)intern);
}