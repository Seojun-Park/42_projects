<?php
if (!isset($_SERVER['PHP_AUTH_USER'])){
    header('WWW-Authenticate: Basic realm="My realm"');
    header('HTTP/1.0 401 Unauthorized');
    exit;
} else {
    $filepath=file_get_contents("../img/42.png");
    header("Content-type: data:image/png;base64");
    echo "<html><body>\nHello {$_SERVER['PHP_AUTH_USER']}<br />\n";
    echo "<img src=data:image/png;base64,".base64_encode($filepath).">";
    echo "\n</body></html>\n";
}
