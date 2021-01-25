<?php
session_start();
if (!($_SESSION['logged_in'])) {
    echo "ERROR\n";
    exit;
}

if ($_POST['msg']) {
    if (file_exists("../private") === false)
        mkdir("../private", 0777, true);
    if (file_exists("../private/chat") === false)
        file_put_contents("../private/chat", null);
    $msg = unserialize(file_get_contents("../private/chat"));
    $fp = fopen("../private/chat", "w");
    flock($fp, LOCK_EX);
    $obj['login'] = $_SESSION['logged_in'];
    $obj['time'] = time();
    $obj['msg'] = $_POST['msg'];
    $msg[] = $obj;
    file_put_contents("../private/chat", serialize($msg));
    fclose($fp);
}
?>
<html>

<head>
    <script langage="javascript">
        top.frames['chat'].location = 'chat.php';
    </script>
</head>

<body>
    <form method="POST">
        <input type="text" name="msg" />
        <input type="submit" name="send" />
    </form>
    </div>
</body>

</html>