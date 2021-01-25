<?php
session_start();
if (isset($_SESSION['logged_in'])){
    $login = TRUE;
}
?>