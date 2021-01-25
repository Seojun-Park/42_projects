#!usr/bin/php
<?php

function loginCheck($login, $asset)
{
    foreach ($asset as $val)
        if ($val['login'] == $login)
            return true;
    return false;
}



if (
    isset($_POST['name']) && isset($_POST['login']) && isset($_POST['pw']) && isset($_POST['pw_re']) && isset($_POST['email']) && isset($_POST['addr_h']) && isset($_POST['zip_h']) && isset($_POST['city_h']) && isset($_POST['tel']) && $_POST['submit'] === "OK"
) {
  echo "coucouc";
    if (file_exists("private/account") === false)
        mkdir("private", 0777, true);
    $cont = [];
    if (file_exists("private/account")) {
        $cont = unserialize(file_get_contents("private/account"));
    }
    $obj['name'] = $_POST['name'];
    $obj['login'] = $_POST['login'];
    $obj['pw'] = $_POST['pw'];
    $obj['pw_re'] = $_POST['pw_re'];
    $obj['email'] = $_POST['email'];
    $obj['addr_h'] = $_POST['addr_h'];
    $obj['zip_h'] = $_POST['zip_h'];
    $obj['city_h'] = $_POST['city_h'];
    $obj['tel'] = $_POST['tel'];
    if (loginCheck($obj['login'], $cont) === false) {
        $cont[] = $obj;
        file_put_contents('private/account', serialize($cont));
    } else {
        echo "Id is already taken";
    }
    sleep(2);
    echo "<meta http-equiv='refresh' content='0;url=login.html'>";
} else {
    echo "Err";
}
?>
