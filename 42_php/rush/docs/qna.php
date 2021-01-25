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
    <link rel="stylesheet" href="styles/qna.css" />
</head>

<body>
    <div class="header">
        <div class="navbar">
            <div class="cover"></div>
            <div id="logo">
                <a href="index.php">Logo</a></div>
            <div class="col">
                <ul class="menu">
                    <li id="box">
                        item1
                        <ul class="box_submenu">
                            <li>
                                <a href="items.php">
                                    item1-1</a>
                            </li>
                            <li>
                                <a href="items.php">
                                    item1-1</a>
                            </li>
                            <li>
                                <a href="items.php">
                                    item1-1</a>
                            </li>
                        </ul>
                    </li>
                    <li id="box">
                        item2
                        <ul class="box_submenu">
                            <li>
                                <a href="items.php">
                                    item2-1</a>
                            </li>
                            <li>
                                <a href="items.php">
                                    item2-1</a>
                            </li>
                            <li>
                                <a href="items.php">
                                    item2-1</a>
                            </li>
                        </ul>
                    </li>
                    <li id="box">
                        item3
                        <ul class="box_submenu">
                            <li>
                                <a href="items.php">
                                    item3-1</a>
                            </li>
                            <li>
                                <a href="items.php">
                                    item3-1</a>
                            </li>
                            <li>
                                <a href="items.php">
                                    item3-1</a>
                            </li>
                        </ul>
                    </li>
                    <li id="box">
                        item4
                        <ul class="box_submenu">
                            <li>
                                <a href="items.php">
                                    item4-1</a>
                            </li>
                            <li>
                                <a href="items.php">
                                    item4-1</a>
                            </li>
                            <li>
                                <a href="items.php">
                                    item4-1</a>
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
            <span id="cont_title">
                Q & A
            </span>
        </div>
        <div class="qna_board">
            <div class="qna_board_head">board header, maybe put the way of sorting?</div>
            <table class="qna_board_table">
                <colgroup>
                    <col width="5%">
                    <col width="50%">
                    <col width="20%">
                    <col width="20%">
                    <col width="5%">
                </colgroup>
                <thead>
                    <tr>
                        <th>#</th>
                        <th>Title</th>
                        <th>Writer</th>
                        <th>Date</th>
                        <th>Hit</th>
                    </tr>
                </thead>
                <tbody aria-rowspan="15">
                    <tr>
                        <td>3</td>
                        <td id="td_title"><a href="#">statement title3</a></td>
                        <td><a href="#">Jin</a></td>
                        <td>2020.08.03</td>
                        <td>16</td>
                    </tr>
                    <tr>
                        <td>2</td>
                        <td id="td_title"><a href="#">statement title2</a></td>
                        <td><a href="#">Jin</a></td>
                        <td>2020.08.03</td>
                        <td>2</td>
                    </tr>
                    <tr>
                        <td>1</td>
                        <td id="td_title"><a href="#">statement title</a></td>
                        <td><a href="#">Jin</a></td>
                        <td>2020.08.03</td>
                        <td>1</td>
                    </tr>
                </tbody>
                <tfoot>
                    <td colspan=12>
                        <a href="#">prev</a>
                        <a href="#">1</a>
                        <a href="#">2</a>
                        <a href="#">3</a>
                        <a href="#">4</a>
                        <a href="#">5</a>
                        <a href="#">6</a>
                        <a href="#">7</a>
                        <a href="#">8</a>
                        <a href="#">9</a>
                        <a href="#">10</a>
                        <a href="#">next</a>
                    </td>
                </tfoot>
            </table>

        </div>
        <footer class="footer">
            <p class="copyright">&copy; 2020 <span id="green">Anthony</span>, <span id="pink">Saro</span>, <span id="blue">Jin</span>
                <p>
        </footer>
    </div>

</body>

</html>