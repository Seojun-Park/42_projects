<?php
function auth($id, $passwd)
{
    $db = unserialize(file_get_contents("../private/passwd"));
    foreach ($db as $val) {
        if (($val['login'] == $id) && ($val['passwd'] == $passwd))
            return true;
    }
    return false;
}
