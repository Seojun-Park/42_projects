#!usr/bin/php

<?php
function loginCheck($login, $asset)
{
    foreach ($asset as $val)
        if ($val['login'] == $login)
            return true;
    return false;
}



if (
    isset($_POST['name']) && isset($_POST['login']) && isset($_POST['pw']) && isset($_POST['pw_re']) && isset($_POST['email']) && isset($_POST['addr_h']) && isset($_POST['zip_h']) && isset($_POST['city_h']) && isset($_POST['tel']) && $_POST['submit'] === "OK"
) {
    $data = array(
        'name' => $_POST['name'],
        'login' => $_POST['login'],
        'pw' => $_POST['pw'],
        'pw_re' => $_POST['pw_re'],
        'email' => $_POST['email'],
        'addr_h' => $_POST['addr_h'],
        'zip_h' => $_POST['zip_h'],
        'city_h' => $_POST['city_h'],
        'tel' => $_POST['tel']
    );
    # Create a connection
    $url = 'localhost:8080/api/product/read.php';
    $ch = curl_init($url);
    # Form data string
    $postString = http_build_query($data, '', '&');
    # Setting our options
    curl_setopt($ch, CURLOPT_POST, 1);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $postString);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    # Get the response
    $response = curl_exec($ch);
    echo ($response);
    curl_close($ch);
    // Routing to Login page
    echo "<meta http-equiv='refresh' content='0;url=login.html'>";
} else {
    echo ($response);
}
?>