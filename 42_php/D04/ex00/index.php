<?php
session_start();
$id = "jin";
$pwd = "1234";

if (!empty($_GET['login']) && !empty($_GET['passwd']) && !empty($_GET['submit'])) {
    if ($_GET['login'] == $id && $_GET['passwd'] == $pwd && $_GET['submit'] == 'OK') {
        $_SESSION['login'] = $_GET['login'];
        $_SESSION['passwd'] = $_GET['passwd'];
    }
}

?>

<html>

<body>
    <form method="GET">
        Usename: <input type="text" name="login" value=<? $_SESSION['login'] ?> <? echo $_SESSION['login']?> />
        <br />
        Password: <input type="text" name="passwd" value=<? $_SESSION['passwd'] ?> <? echo $_SESSION['passwd'] ?> />
        <input type="submit" value="OK" name="submit" />
    </form>
</body>

</html>