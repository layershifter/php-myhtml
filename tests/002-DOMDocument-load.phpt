--TEST--
MyHTML\DOMDocument - load(), loadHTML(), loadHTMLFile(), loadXML()
--SKIPIF--
<?php if (!extension_loaded('myhtml')) echo 'skip'; ?>
--FILE--
<?php

$document = new MyHTML\DOMDocument();
$helper = require __DIR__ . '/.helper.php';

$helper->assert(
    'MyHTML\DOMDocument::loadHTML() returns MyHTML\DOMDocument',
    $document->loadHTML('<a></a>') instanceof MyHTML\DOMDocument
);
var_dump($document->loadHTML('<a></a>'));
// $helper->methodThrows($document, 'load', MyHTML\Exceptions\UnsupportMethodException::class);
// $helper->methodThrows($document, 'loadHTMLFile', MyHTML\Exceptions\UnsupportMethodException::class);
// $helper->methodThrows($document, 'loadXML', MyHTML\Exceptions\UnsupportMethodException::class);

?>
--EXPECT--
MyHTML\DOMDocument::loadHTML() returns MyHTML\DOMDocument: true