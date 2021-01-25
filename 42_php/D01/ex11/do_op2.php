#!/usr/bin/php
<?php

function do_op($sign, $n1, $n2)
{
    switch ($sign) {
        case "+":
            $res = intval($n1) + intval($n2);
            echo "$res";
            break;
        case "-":
            $res = intval($n1) - intval($n2);
            echo "$res";
            break;
        case "*":
            $res = intval($n1) * intval($n2);
            echo "$res";
            break;
        case "/":
            $res = intval($n1) / intval($n2);
            echo "$res";
            break;
        case "%":
            $res = intval($n1) % intval($n2);
            echo "$res";
            break;
    }
}

$arr = $argv[1];
$flag = false;
for ($i = 0; $i < strlen($arr); $i++) {
    if (($arr[$i] == "+" || $arr[$i] == "-" || $arr[$i] == "*" || $arr[$i] == "/" || $arr[$i] == "%")) {
        $flag = true;
        $sign = $arr[$i];
        $array = explode($sign, $arr);
    } else if (($arr[$i] >= 'a' && $arr[$i] <= 'z') || ($arr[$i] >= 'A' && $arr[$i] <= 'Z')) {
        $flag = false;
        break;
    }
}

if ($flag === true) {
    do_op($sign, $array[0], $array[1]);
} else if ($flag === false) {
    echo "Syntax Error";
}
echo "\n";

?>