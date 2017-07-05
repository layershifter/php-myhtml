#ifndef PHP_MYHTML_DOM_H
#define PHP_MYHTML_DOM_H

#include "dom.h"
#include "php.h"
#include "ext/dom/xml_common.h"

dom_doc_propsptr myhtml_dom_get_props(php_libxml_ref_obj *document);
void myhtml_dom_set_classmap(zval *object, zend_class_entry *base_ce, zend_class_entry *ce);

#endif //PHP_MYHTML_DOM_H
