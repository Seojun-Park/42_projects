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
    if ($logged_in) {
    ?>

        <h1>you are already logged in</h1>
    <?php
    } else {
    ?>
        <h1>Login</h1>
        <form action="login_result.php" method="POST">
            <input type="text" name="login" placeholder="Login ID">
            <input type="password" name="pw" placeholder="Password">
            <button>submit</button>
        </form>
    <?php
    }
    ?>
</body>

</html>