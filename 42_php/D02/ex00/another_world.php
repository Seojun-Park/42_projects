#!/usr/bin/php
<?php
$line = trim($argv[1], " \t");
$value = explode(" ", $line);

for($i = 0; $i < count($value); $i++){
    if (strlen($value[$i]) !==0){
        echo "$value[$i] ";
    }
}

echo "\n";
?>