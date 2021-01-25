#!/usr/bin/php
<?php
function ft_is_sort($tab)
{
    $sorted = $tab;
    sort($sorted);
    $value = join(" ", $sorted);
    $newValue = join(" ", $tab);

    echo "val : $value\n";
    echo "new val : $newValue\n";
    if (strcmp($value, $newValue) !== 0) {
        return false;
    } else {
        return true;
    }
}

?>