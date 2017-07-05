--TEST--
MyHTML\DOMDocument - inheritance, loadHTML()
--SKIPIF--
<?php if (!extension_loaded('myhtml')) echo 'skip'; ?>
--FILE--
<?php

$helper = require __DIR__ . '/.helper.php';

$helper->assert('MyHTML\DOMDocument inherits \DOMDocument', is_subclass_of(new MyHTML\DOMDocument(), 'DOMDocument'));
$helper->line();
?>
--EXPECT--
MyHTML\DOMDocument inherits \DOMDocument: true