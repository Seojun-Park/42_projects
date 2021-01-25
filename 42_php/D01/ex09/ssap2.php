#!/usr/bin/php
<?php
function isAlpa($str)
{
    if (($str[0] >= 'a' && $str[0] <= 'z') || ($str[0] >= 'A' && $str[0] <= 'Z')) {
        return true;
    } else {
        return false;
    }
}

function isNumeric($str)
{
    if ($str[0] >= '0' && $str[0] <= '9') {
        return true;
    } else {
        return false;
    }
}

$arr = join(" ", $argv);
$cnt = 0;
$val = explode(" ", $arr);
$alpa = [];
$numeric = [];
$other = [];


for ($i = 1; $i < count($val); $i++) {
    if (isAlpa($val[$i])) {
        array_push($alpa, $val[$i]);
    } else if (isNumeric($val[$i])) {
        array_push($numeric, $val[$i]);
    } else {
        array_push($other, $val[$i]);
    }
}

sort($alpa);
sort($numeric);
sort($other);

for ($i = 0; $i < count($alpa); $i++) {
    echo "$alpa[$i]\n";
}

for ($i = 0; $i < count($numeric); $i++) {
    echo "$numeric[$i]\n";
}

for ($i = 0; $i < count($other); $i++) {
    echo "$other[$i]\n";
}
?>