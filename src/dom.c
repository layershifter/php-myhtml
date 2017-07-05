#include "dom.h"
#include "php.h"
#include "ext/dom/xml_common.h"

dom_doc_propsptr myhtml_dom_get_props(php_libxml_ref_obj *document) {
    dom_doc_propsptr doc_props;

    if (document && document->doc_props) {
        return document->doc_props;
    }
    doc_props = emalloc(sizeof(libxml_doc_props));
    doc_props->formatoutput = 0;
    doc_props->validateonparse = 0;
    doc_props->resolveexternals = 0;
    doc_props->preservewhitespace = 1;
    doc_props->substituteentities = 0;
    doc_props->stricterror = 1;
    doc_props->recover = 0;
    doc_props->classmap = NULL;

    if (document) {
        document->doc_props = doc_props;
    }

    return doc_props;
}

void myhtml_dom_set_classmap(zval *object, zend_class_entry *base_ce, zend_class_entry *ce) {
    dom_object *intern = Z_DOMOBJ_P(object);
    php_libxml_ref_obj *document = intern->document;
    dom_doc_propsptr doc_props = myhtml_dom_get_props(document);

    if (doc_props->classmap == NULL) {
        ALLOC_HASHTABLE(doc_props->classmap);
        zend_hash_init(doc_props->classmap, 0, NULL, NULL, 0);
    }

    zend_hash_update_ptr(doc_props->classmap, base_ce->name, ce);
}
