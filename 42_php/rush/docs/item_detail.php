<?php
include 'inc_head.php';
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <title>Rush</title>

    <link rel="stylesheet" href="styles/base.css" />
    <!-- <link rel="stylesheet" href="styles/items.css" /> -->
    <link rel="stylesheet" href="styles/item_detail.css" />


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
        <div class="item_detail">
            <!-- Item main image col -->
            <div class="item_imgs">
                <img src="https://images.unsplash.com/photo-1580130379624-3a069adbffc5?ixlib=rb-1.2.1&auto=format&fit=crop&w=968&q=80" alt="itemimg1" id="item_mainimg">
                <div id="item_subimgs">
                    <img src="https://images.unsplash.com/photo-1586253633590-db972921177c?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1050&q=80" alt="itemimg1" id="item_subimg">
                    <img src="https://images.unsplash.com/photo-1586253633590-db972921177c?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1050&q=80" alt="itemimg1" id="item_subimg">
                </div>
            </div>
            <!-- Item description col -->
            <div class="item_desc">
                <div id="item_name">
                    Barack Hussein Obama
                </div>
                <div id="item_price">
                    €50
                </div>
                <div id="item_detail">
                    <table id="detail_table">
                        <caption>Detail</caption>
                        <tr>
                            <th>Born</th>
                            <td>August 4, 1961<br /> Honolulu, Hawaii, U.S.</td>
                        </tr>
                        <tr>
                            <th>Politic. party</th>
                            <td>Democratic</td>
                        </tr>
                        <tr>
                            <th>Alma Mater</th>
                            <td>Columbia University (BA)<br /> Havard University (JD)</td>
                        </tr>
                        <tr>
                            <th>Awards</th>
                            <td>Nobel Peace Price (2009)<br />Profile in Courage Award (2017)</td>
                        </tr>
                    </table>
                </div>
                <div id="item_quantities">
                    qunatity counter here
                </div>
                <div id="item_buttons">
                    buttons
                </div>
            </div>
        </div>
        <footer class="footer">
            <p class="copyright">&copy; 2020 <span id="green">Anthony</span>, <span id="pink">Saro</span>, <span id="blue">Jin</span>
                <p>
        </footer>
    </div>
</body>

</html>