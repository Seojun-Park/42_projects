<?php
include 'inc_head.php'
?>

<!doctype html>
<html>

<head>
    <title>session login test</title>
</head>

<body>
    <?php
    if ($login) {
        echo '<h1>You are already logged in</h1>';
    } else {
        $login_id = $_POST['login'];
        $pw = $_POST['pw'];
        if ($login_id == 'qwe' && $pw == '123') {
            $_SESSION['logged_in'] = $login_id;
            echo '<h1>Hi!<h/1>';
        } else {
            echo "<p>wrong passwd and id</p>";
        }
    }
    ?>
</body>

</html>