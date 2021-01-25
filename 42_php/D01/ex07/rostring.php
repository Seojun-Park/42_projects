#!/usr/bin/php
<?php
$value = explode(" ", $argv[1]);
for ($i = 1; $i < count($value); $i++) {
    echo "$value[$i] ";
}
echo "$value[0]";
echo "\n";
?>