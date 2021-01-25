<?php
session_start();
if (!($_SESSION['logged_in'])) {
    echo "ERROR\n";
    exit;
}

if (file_exists("../private") && file_exists("../private/chat")) {
    $chat = unserialize(file_get_contents("../private/chat"));
    foreach ($chat as $val) {
        echo "[" . date('H:i', $val['time']) . "] <b>" . $val['login'] . "</b>: " . $val['msg'] . "<br />";
    }
}
?>

<html>

<head>
    <script langage="javascript">
        top.frames['chat'].location = 'chat.php';
    </script>
</head>

</html>