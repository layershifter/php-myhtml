#ifndef MYHTML_PARSER_H
#define MYHTML_PARSER_H

#include "php_myhtml.h"
#include <libxml/tree.h>
#include <myhtml/api.h>

xmlDocPtr myhtml_create_doc();
xmlDocPtr myhtml_parse_string(zend_string *source);

void myhtml_parse_attrs(xmlNodePtr xml_node, myhtml_tree_node_t *node);
void myhtml_parse_recursive(xmlNodePtr parent, myhtml_tree_t *tree, myhtml_tree_node_t *node);

void myhtml_parse_element(xmlNodePtr parent, myhtml_tree_t *tree, myhtml_tree_node_t *node, myhtml_tag_id_t id);
void myhtml_parse_text(xmlNodePtr parent, myhtml_tree_node_t *node);

#endif

