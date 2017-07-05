#include "php_myhtml.h"
#include "parser.h"
#include "ext/dom/xml_common.h"
#include <libxml/tree.h>
#include <myhtml/api.h>

xmlDocPtr myhtml_create_doc() {
    xmlDocPtr xml_doc = xmlNewDoc(BAD_CAST "1.0");

    // TODO: if HTML page has DTD (Document Type Definition) then add it to xmlDoc
    // xmlDtdPtr doc_type = xmlNewDtd(
    //     xml_doc,
    //     BAD_CAST name,
    //     BAD_CAST public_identifier,
    //     BAD_CAST system_identifier
    // );
    // xml_doc->intSubset = doc_type;

    return xml_doc;
}

xmlDocPtr myhtml_parse_string(zend_string *source) {
    xmlDocPtr doc = myhtml_create_doc();

    myhtml_t *myhtml = myhtml_create();
    myhtml_init(myhtml, MyHTML_OPTIONS_DEFAULT, 1, 0);

    myhtml_tree_t *tree = myhtml_tree_create();
    myhtml_tree_init(tree, myhtml);

    myhtml_parse(tree, MyENCODING_UTF_8, source->val, source->len);
    myhtml_tree_node_t *node = myhtml_tree_get_document(tree);

    myhtml_parse_recursive((xmlNodePtr) doc, tree, myhtml_node_child(node));

    myhtml_tree_destroy(tree);
    myhtml_destroy(myhtml);

    return doc;
}

void myhtml_parse_recursive(xmlNodePtr parent, myhtml_tree_t *tree, myhtml_tree_node_t *node) {
    while (node) {
        const myhtml_tag_id_t id = myhtml_node_tag_id(node);

        switch (id) {
            case MyHTML_TAG__COMMENT:
            case MyHTML_TAG__TEXT:
                myhtml_parse_text(parent, node);
                break;

            default:
                myhtml_parse_element(parent, tree, node, id);
                break;
        }

        node = myhtml_node_next(node);
    }
}

void myhtml_parse_attrs(xmlNodePtr xml_node, myhtml_tree_node_t *node) {
    myhtml_tree_attr_t *attr = myhtml_node_attribute_first(node);

    while (attr) {
        const char *name = myhtml_attribute_key(attr, NULL);
        const char *value = myhtml_attribute_value(attr, NULL);

        xmlNewProp(xml_node, BAD_CAST name, BAD_CAST value);
        attr = myhtml_attribute_next(attr);
    }
}

void myhtml_parse_element(xmlNodePtr parent, myhtml_tree_t *tree, myhtml_tree_node_t *node, myhtml_tag_id_t id) {
    const char *name = myhtml_tag_name_by_id(tree, myhtml_node_tag_id(node), NULL);

    xmlNodePtr result_node = xmlNewNode(NULL, name);
    xmlAddChild(parent, result_node);

    myhtml_parse_attrs(result_node, node);
    myhtml_parse_recursive(result_node, tree, myhtml_node_child(node));
}

void myhtml_parse_text(xmlNodePtr parent, myhtml_tree_node_t *node) {
    const char *text = myhtml_node_text(node, NULL);

    xmlAddChild(parent, xmlNewText(text));
}