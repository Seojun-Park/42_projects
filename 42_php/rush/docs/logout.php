<?php
include 'inc_head.php';
    if ($login) {
        session_destroy();
        echo "<meta http-equiv='refresh' content='0;url=index.php'>";
    } else {
        echo 'You are not in logged in';
        sleep(3);
        echo "<meta http-equiv='refresh' content='0;url=login.html'>";
    }
