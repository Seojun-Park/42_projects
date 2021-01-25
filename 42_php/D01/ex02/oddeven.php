#!/usr/bin/php
<?php 
echo "Enter a number : ";
fscanf(STDIN, "%d\n", $number);

if(is_numeric($number)){
    if (($number % 2) == 0){
        echo "The number $number is even\n";
    } else if (($number % 2) != 0){
        echo "The number $number is odd\n";
    }
} else {
    echo "'$number' is not a number\n";
}

?>