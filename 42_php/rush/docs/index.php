<?php
include 'inc_head.php';
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <title>Rush</title>
    <link rel="stylesheet" href="styles/reset.css" />
    <link rel="stylesheet" href="styles/base.css" />

</head>

<body>
    <div class="header">
        <!-- Header -->
        <div class="navbar">
            <div class="cover"></div>
            <div id="logo">
                <a href="index.php">Logo</a></div>
            <div class="col">
                <!-- Main menu box -->
                <ul class="menu">
                    <li id="box">item1
                        <ul class="box_submenu">
                            <li>
                                <a href="items.php">item1-1</a>
                            </li>
                            <li>
                                <a href="items.php">item1-1</a>
                            </li>
                            <li>
                                <a href="items.php">item1-1</a>
                            </li>
                        </ul>
                    </li>
                    <li id="box">item2
                        <ul class="box_submenu">
                            <li>
                                <a href="items.php">item2-1</a>
                            </li>
                            <li>
                                <a href="items.php">item2-1</a>
                            </li>
                            <li>
                                <a href="items.php">item2-1</a>
                            </li>
                        </ul>
                    </li>
                    <li id="box">item3
                        <ul class="box_submenu">
                            <li>
                                <a href="items.php">item3-1</a>
                            </li>
                            <li>
                                <a href="items.php">item3-1</a>
                            </li>
                            <li>
                                <a href="items.php">item3-1</a>
                            </li>
                        </ul>
                    </li>
                    <li id="box">ABOUT US
                        <ul class="box_submenu">
                            <li>
                                <a href="items.php">item4-1</a>
                            </li>
                            <li>
                                <a href="items.php">item4-1</a>
                            </li>
                            <li>
                                <a href="items.php">item4-1</a>
                            </li>
                        </ul>
                    </li>
                </ul>
                <!-- Auth menu -->
                <div class="col_sm">
                    <div id="col_sm_box">
                        <?php
                        if ($login == FALSE) {
                            ?>
                            <a href="login.html">
                                LOGIN</a>
                        <?php
                        } else {
                            ?>
                            <!-- <a href="#">LOGOUT</a> -->
                            <form method="post">
                                <input type="submit" name="logout" id="logout" value="LOGOUT" />
                            </form>
                        <?php
                            if (array_key_exists('logout', $_POST)) {
                                session_destroy();
                                echo "<meta http-equiv='refresh' content='0;url=index.php'>";
                            }
                        }
                        ?>
                    </div>
                    <div id="col_sm_box">
                        <?php
                        if ($login == FALSE) {
                            ?>
                            <a href="signup.html">
                                JOIN US
                            </a>
                        <?php
                        } else {
                            ?>
                            <a href="#">MY PAGE</a>
                        <?php
                        }
                        ?>
                    </div>
                    <div id="col_sm_box">
                        <a href="cart.php">
                            CART
                        </a>
                    </div>
                    <div id="col_sm_box">
                        <?php
                        if ($login == FALSE) {
                            ?><a href="mypage.html">TBU IN LOGOUT</a>
                        <?php } else {
                            ?>
                            <a href="mypage.html">TBU IN LOGIN</a>
                        <?php
                        }
                        ?>
                    </div>
                    <img src="https://img.icons8.com/ios/16/000000/search--v1.png" id="searchIcon" />
                </div>
            </div>
        </div>
    </div>
    <div class="container">
        <div id="slide">
            <input type="radio" name="pos" id="pos1" checked>
            <input type="radio" name="pos" id="pos2">
            <input type="radio" name="pos" id="pos3">
            <input type="radio" name="pos" id="pos4">
            <ul>
                <li><img src="https://images.unsplash.com/photo-1499856871958-5b9627545d1a?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1307&q=80" alt="slide1"></li>
                <li><img src="https://images.unsplash.com/photo-1449265614232-03dfc33163a0?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1350&q=80" alt="slide2"></li>
                <li><img src="https://images.unsplash.com/photo-1506816561089-5cc37b3aa9b0?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1141&q=80" alt="slide3"></li>
                <li><img src="https://images.unsplash.com/photo-1576158505250-d8a764bf1b42?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1050&q=80" alt="slide4"></li>
            </ul>
            <p class="pos">
                <label for="pos1"></label>
                <label for="pos2"></label>
                <label for="pos3"></label>
                <label for="pos4"></label>
            </p>
        </div>
        <div class="cont">
            <div class="notice">
                <div class="notice_col">
                    <span id="notice_title">Promotion</span>
                    <span id="notice_sub">Check out items on promotion</span>
                    <a href="">
                        <div id="notice_box">
                            GO >
                        </div>
                    </a>
                </div>
                <div class="notice_col">
                    <div id="second_sub">
                        <span id="notice_title">Notice</span>
                        <span>should we put list on here?</span>
                    </div>
                </div>
                <div class="notice_col">
                    <div class="col_insta">
                        <span id="notice_insta"># OUR SOCAIL MEDIA</span>
                    </div>

                </div>
            </div>
            <div class="items">
                hooo
            </div>
        </div>
        <footer class="footer">
            <p class="copyright">&copy; 2020 <span id="green">Anthony</span>, <span id="pink">Saro</span>, <span id="blue">Jin</span>
                <p>
        </footer>
    </div>

</body>

</html>