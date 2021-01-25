#!/usr/bin/php
<?php
function imgDownload($url, $path)
{
    $headers[] = 'Accept: image/gif, image/x-bitmap, image/jpeg, image/pjpeg';
    $headers[] = 'Connection: Keep-Alive';
    $headers[] = 'Content-type: application/x-www-form-urlencoded;charset=UTF-8';
    $user_agent = 'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.7) Gecko/20040803 Firefox/0.9.3';
    
    $ch = curl_init($url);
    curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
    curl_setopt($ch, CURLOPT_HEADER, 0);
    curl_setopt($ch, CURLOPT_USERAGENT, $user_agent);
    curl_setopt($ch, CURLOPT_TIMEOUT, 30);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);
    $return = curl_exec($ch);
    curl_close($ch);
    return $return;
    
    // file_put_contents($img, $url);
}


$folder = preg_replace("/^.*?:\/\//", "", $argv[1]);
$filename = 'logo42-site.gif';
if (file_exists($folder) == false){
    mkdir($folder, 0777, true);
}
$html = file_get_contents($argv[1]);
$tag = strstr($html, "<img src");
$tag = strstr($tag, "alt", true);
$tag = strstr($tag, "\"");
$tag = trim($tag, " \"");

echo $tag;


$image = imgDownload($tag, $file);
file_put_contents($folder.'/'.$filename, $image);
?>