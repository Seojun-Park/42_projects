<?php
// header("Location: ./index.html");
include "auth.php";
session_start();

if (isset($_POST['login']) && isset($_POST['passwd'])) {
    if (auth($_POST['login'], $_POST['passwd']) == true) {
        $_SESSION['logged_in'] = $_POST['login'];
        echo "OK\n";
        sleep(2);
        echo "<meta http-equiv='refresh' content='0;url=index.html'>";
    } else {
        echo "ERROR\n";
    }
}
