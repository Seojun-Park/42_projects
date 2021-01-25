<?php
$filepath ='/../img/42.png';
$filesize = filesize($filepath);
$path_parts = pathinfo($filepath);

header("Content-Type: image/png");
header("Content-Disposition: attachment; filename=$filename");

ob_clean();
flush();
readfile($filepath);