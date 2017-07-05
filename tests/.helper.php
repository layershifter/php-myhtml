<?php

class TestHelper
{
    public function assert(string $name, $condition)
    {
        echo sprintf('%s: %s', $name, var_export($condition === true, true));
    }

    public function line()
    {
        echo PHP_EOL;
    }
}

return new TestHelper();
