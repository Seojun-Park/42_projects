#!/usr/bin/php
<?php
switch ($argv[2]) {
    case "+":
        $res = intval($argv[1]) + intval($argv[3]);
        echo "$res";
        break;
    case "-":
        $res = intval($argv[1]) - intval($argv[3]);
        echo "$res";
        break;
    case "*":
        $res = intval($argv[1]) * intval($argv[3]);
        echo "$res";
        break;
    case "/":
        $res = intval($argv[1]) / intval($argv[3]);
        echo "$res";
        break;
    case "%":
        $res = intval($argv[1]) % intval($argv[3]);
        echo "$res";
        break;
}
echo "\n";
?>