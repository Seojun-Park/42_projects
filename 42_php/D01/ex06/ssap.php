#!/usr/bin/php
<?php
$value = join(" ", $argv);
$split = explode(" ", $value);
sort($split);

for($i = 1; $i < count($split); $i++){
    echo "$split[$i]\n";
}
?>