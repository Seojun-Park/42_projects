<?php
header("Location: ./index.html");

function loginCheck($id, $obj)
{
    foreach ($obj as $val)
        if ($val['login'] == $id)
            return true;
    return false;
}

if (isset($_POST['login']) && isset($_POST['passwd']) && $_POST['submit'] === "OK") {
    if (file_exists("../private") === false)
        mkdir("../private", 0777, true);
    $cont = [];
    if (file_exists("../private/passwd")) {
        $cont = unserialize(file_get_contents("../private/passwd"));
    }
    $obj['login'] = $_POST['login'];
    $obj['passwd'] = $_POST['passwd'];
    if (loginCheck($_POST['login'], $cont) === false) {
        $cont[] = $obj;
        file_put_contents('../private/passwd', serialize($cont));
    }
    echo "OK\n";
    // sleep(2);
    // echo "<meta http-equiv='refresh' content='0;url=index.html'>";
} else {
    echo "ERROR\n";
}
