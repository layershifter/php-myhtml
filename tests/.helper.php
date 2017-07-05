<?php

class TestHelper
{
    public function assert(string $name, $condition)
    {
        echo sprintf('%s: %s%s', $name, var_export($condition === true, true), PHP_EOL);
    }

    public function line()
    {
        echo PHP_EOL;
    }

    public function methodThrows($object, string $method, string $exception, array $args = [])
    {
        $className = get_class($object);

        try {
            call_user_func_array([$object, $method], $args);
        } catch (Throwable $e) {
            if ($e instanceof $exception) {
                echo sprintf('%s::%s(): exception was thrown correctly%s', $className, $method, PHP_EOL);

                return;
            }

            echo sprintf('%s::%s(): threw unexpected exception%s', $className, $method, PHP_EOL);
            echo $className, '::', $method, '()', ' threw unexpected exception', PHP_EOL;
        }
    }
}

return new TestHelper();
