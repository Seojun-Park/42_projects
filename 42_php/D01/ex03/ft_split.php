#!/usr/bin/php
<?php
echo "Array\n(\n";
for ($i = 0; $i < $argc; $i++) {
    echo "      [$i] => $argv[$i]\n";
}
echo ")\n";
?>