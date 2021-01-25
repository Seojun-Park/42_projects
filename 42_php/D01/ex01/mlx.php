#!/usr/bin/php
<?php
$i = 1;

while ($i <= 1000) {
    echo "X";
    if (($i % 100) == 0)
        echo "\n";
    $i++;
}
?>