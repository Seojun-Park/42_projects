<?php

function loginCheck($id, $obj)
{
    foreach ($obj as $val)
        if ($val['login'] == $id)
            return true;
    return false;
}

if (isset($_POST['login']) && isset($_POST['passwd']) && $_POST['submit'] === "OK") {
    if (file_exists("private") === false)
        mkdir("private", 0777, true);
    $cont = [];
    if (file_exists("../private/passwd"))
        $cont = file_get_contents("../private/passwd");
    $obj['login'] = $_POST['login'];
    $obj['passwd'] = $_POST['passwd'];
    $newCont = unserialize($cont);
    if (loginCheck($_POST['login'], $newCont) === false) {
        $newCont[] = $obj;
        file_put_contents('../private/passwd', serialize($newCont));
    }
} else {
    echo "ERROR\n";
}
