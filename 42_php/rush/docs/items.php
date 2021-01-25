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
    <link rel="stylesheet" href="styles/items.css" />
</head>

<body>
    <!-- Main header -->
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
        <!-- Body Contents header title -->
        <div id="cont_header">
            <span id="cont_title">item Title</span>
        </div>
        <div id="items_nav">
            <!-- Body Content header left Informing -->
            <div id="items_amount">
                <span style="color: black;"> n</span> amounts of items found
            </div>
            <!-- Body Content header right menu -->
            <div id="items_sort">
                <a href="/">new
                </a> |
                <a href="/">by name
                </a> |
                <a href="/">min
                </a> |
                <a href="/">max
                </a>
            </div>
        </div>
        <div id="items_content">
            <!-- Item view list part -->
            <ul class="items_card">
                <li id="card_box">
                    <span id="cardCheck">
                        <input type="checkbox" class="card_checkbox displaynone">
                    </span>
                    <div class="card_thumbnail">
                        <a href="item_detail.php">
                            <img id="thumbnail_img" src="https://images.unsplash.com/photo-1485546784815-e380f3297414?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1350&q=80" alt="thumbnail">
                            <img id="imghover" src="https://images.unsplash.com/photo-1497048679117-1a29644559e3?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1350&q=80" alt="itemimage">
                        </a>
                    </div>
                    <div class="card_description">
                        <a href="item_detail.php" id="card_itemname">Item name</a>
                        <ul id="card_detail">
                            <li id="card_itemprice">
                                €50
                            </li>
                            <li id="card_itemdetail">
                                Item description will be placed on this part
                            </li>
                    </div>
                    <div class="card_badge">
                        <div id="new">
                            new
                        </div>
                        <div id="hot">
                            hot
                        </div>
                    </div>
                </li>
            </ul>
        </div>
        <footer class="footer">
            <p class="copyright">&copy; 2020 <span id="green">Anthony</span>, <span id="pink">Saro</span>, <span id="blue">Jin</span>
                <p>
        </footer>
    </div>

</body>

</html>