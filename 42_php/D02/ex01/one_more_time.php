#!/usr/bin/php
<?php

date_default_timezone_set('Europe/Paris');

function recursive_array_search($needle, $haystack)
{
    foreach ($haystack as $key => $value) {
        $current_key = $key;
        if ($needle === $value or (is_array($value) && recursive_array_search($needle, $value) !== false)) {
            return true;
        }
    }
    return false;
}

function formatChecker($value)
{
    $monthArr = ["Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Setembre", "Octobre", "Novembre", "Décembre"];
    $weekday = ["lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"];
    $line = explode(" ", $value);
    $time = explode(":", $line[4]);
    $flag = true;
    $dname = $line[0];
    $date = $line[1];
    $month = $line[2];
    $year = $line[3];
    $hour = $time[0];
    $min = $time[1];
    $sec = $time[2];

    if (!recursive_array_search($dname, $weekday))
        $flag = false;
    if (!recursive_array_search($month, $monthArr))
        $flag = false;
    if (strlen($date) !== 1 && strlen($date) !== 2)
        $flag = false;
    if (strlen($year) !== 4)
        $flag = false;
    if (strlen($hour) !== 2)
        $flag = false;
    if (strlen($min) !== 2)
        $flag = false;
    if (strlen($sec) !== 2)
        $flag = false;
    return $flag;
}

function printTime($value)
{
    $monthArr = ["Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Setembre", "Octobre", "Novembre", "Décembre"];
    $monthArr = array(
        0 => array(
            "name" => "Janvier",
            "num" => "01"
        ),
        1 => array(
            "name" => "Février",
            "num" => "02"
        ),
        2 => array(
            "name" => "Mars",
            "num" => "03"
        ),
        3 => array(
            "name" => "Avril",
            "num" => "04"
        ),
        4 => array(
            "name" => "Mai",
            "num" => "05"
        ),
        5 => array(
            "name" => "Juin",
            "num" => "06"
        ),
        6 => array(
            "name" => "Julliet",
            "num" => "07"
        ),
        7 => array(
            "name" => "Août",
            "num" => "08"
        ),
        8 => array(
            "name" => "Setembre",
            "num" => "09"
        ),
        9 => array(
            "name" => "Octobre",
            "num" => "10"
        ),
        10 => array(
            "name" => "Novembre",
            "num" => "11"
        ),
        11 => array(
            "name" => "Décembre",
            "num" => "12"
        ),
    );

    $line = explode(" ", $value);
    $time = $line[4];
    $date = $line[1];
    $month = $line[2];
    $year = $line[3];
    $index = array_search($month, array_column($monthArr, "name"));
    $index += 1;

    echo strtotime("$year-$index-$date$time");
}


unset($argv[0]);
$value = join($argv);
$flag = formatChecker($value);

if ($flag === true) {
    printTime($value);
} else {
    echo "Wrong Foramt";
}

?>