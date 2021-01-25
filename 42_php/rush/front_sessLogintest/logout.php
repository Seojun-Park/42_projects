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
                session_destroy();
                echo '<h1>you are now logged out</h1>';
            } else {
                echo 'you are not in logged in';
            }
        ?>
    </body>
</html>