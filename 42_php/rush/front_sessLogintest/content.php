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
            if ($login){
                echo '<h1>Hi</h1>';
            } else {
                echo '<h1>you need to login</h1>';
            }
        ?>
    </body>
</html>