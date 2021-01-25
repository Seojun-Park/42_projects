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
    <link rel="stylesheet" href="styles/cart.css" />
</head>

<body>
    <div class="header">
        <div class="navbar">
            <div class="cover"></div>
            <div id="logo">
                <a href="index.php">Logo</a></div>
            <div class="col">
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
                        <a href="mypage.html">
                            MY PAGE
                        </a>
                    </div>
                    <img src="https://img.icons8.com/ios/16/000000/search--v1.png" id="searchIcon" />
                </div>
            </div>
        </div>
    </div>
    <div class="container">
        <div id="cont_header">
            <span id="cont_title">item Title</span>
        </div>
        <div id="cart_nav">
            <div id="cart_amount">
                <span style="color: black;"> n</span> is in your cart
            </div>
        </div>
        <div id="cart_content">
            <ul class="cart_list">
                <li id="cart_row">
                    <div class="cart_detail">
                        <img src="/" alt="thumbnail" id="cart_thumnail" />
                        <div class="item_detail">
                            <a href="cart.html">
                                <div id="item_title">
                                    title
                                </div>
                                <div id="item_desc">
                                    description
                                </div>
                            </a>
                        </div>
                        <div class="cart_buttons">
                            <span id="cart_price">€500</span>
                            <button id="cart_del_button" type="submit">Delete</button>
                        </div>
                    </div>
                </li>
                <li id="cart_row">
                    <div class="cart_detail">
                        <img src="/" alt="thumbnail" id="cart_thumnail" />
                        <div class="item_detail">
                            <a href="cart.html">
                                <div id="item_title">
                                    title
                                </div>
                                <div id="item_desc">
                                    description
                                </div>
                            </a>
                        </div>
                        <div class="cart_buttons">
                            <span id="cart_price">€500</span>
                            <button id="cart_del_button" name="cartdel" type="submit">Delete</button>
                        </div>
                    </div>
                </li>
            </ul>
            <div class="cart_total">
                <div id="cart_total_align">
                    <span id="total_span">
                        total : €
                    </span>
                    <span id="total_amount">
                        500
                    </span>
                </div>
            </div>
            <div class="cart_confirm">
                <button id="cart_confirm_btn" name="cartconf" type="submit">Confirm</button>
            </div>
        </div>
        <footer class="footer">
            <p class="copyright">&copy; 2020 <span id="green">Anthony</span>, <span id="pink">Saro</span>, <span id="blue">Jin</span>
                <p>
        </footer>
    </div>

</body>

</html>