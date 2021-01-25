<?php
include 'inc_head.php';
if (isset($_POST['login']) && isset($_POST['pw']) && $_POST['submit'] == "OK") {
    $data = array(
        'login' => $_POST['login'],
        'pw' => $_POST['pw']
    );

    // // create connection
    // $url = 'localhost:8080/api/product/login.php';
    // $ch = curl_init($url);
    // // Form data string
    // $postString = http_build_query($data, '', '&');
    // // Setting out options
    // curl_setopt($ch, CURLOPT_POST, 1);
    // curl_setopt($ch, CURLOPT_POSTFIELDS, $postString);
    // curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    // // Get the response
    // $res = curl_exec($ch);


    // testing 
    if ($data['login'] == "qwe" && $data['pw'] == "123") {
        $res = "OK";
    } else {
        echo "Your ID / password is not matched, Please check it again";
        sleep(2);
        echo "<meta http-equiv='refresh' content='0;url=login.html'>";
    }

    // session login example / routing to main page

    if ($res == "OK") {
        $_SESSION['logged_in'] = $data['login'];
        echo "<meta http-equiv='refresh' content='0;url=index.php'>";
    }

    // curl_close($ch);
} else {
    echo "err check needed";
}
