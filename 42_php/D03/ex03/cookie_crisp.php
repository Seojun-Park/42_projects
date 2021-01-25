<?php
if (isset($_GET['action'])) {
    $value = $_GET['action'];
    $key = $_GET['name'];
    if ($value === 'set') {
        setcookie($key, $_GET['value'], time() + 1000);
    } else if ($value === "get") {
        echo $_COOKIE[$key];
    } else {
        unset($_GET[$key]);
        setcookie($_GET[$key], time() + 1000);
    }
}

