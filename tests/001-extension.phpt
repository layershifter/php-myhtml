--TEST--
Check for ref extension presence
--SKIPIF--
<?php if (!extension_loaded('myhtml')) echo 'skip'; ?>
--FILE--
<?php
echo 'extension is available';
?>
--EXPECT--
extension is available