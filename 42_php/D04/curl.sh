
# ex01
# create
# curl -d login=toto3 -d passwd=titi1 -d submit=OK 'http://localhost:8080/D04/ex01/create.php'

# ex02
#Success case

# curl -d login=x -d passwd=21 -d submit=OK 'http://localhost:8080/D04/ex01/create.php'
# curl -d login=x -d oldpw=21 -d newpw=42 -d submit=OK 'http://localhost:8080/D04/ex02/modif.php'
# cat ./ex01/private/passwd

# Error case

# curl -d login=x -d oldpw=21 -d newpw=42 -d submit=OK 'http://localhost:8080/D04/ex02/modif.php

# curl -d login=toto3 -d passwd=titi3 -d submit=OK 'http://localhost:8080/D04/ex01/create.php'

# curl -c cook.txt 'http://localhost:8080/D04/ex03/login.php?login=toto3&passwd=titi3'

# curl -b cook.txt 'http://localhost:8080/D04/ex03/whoami.php'


# rm -rf ./ex01/private/
# if [[ ($1) && ($1 = "v") ]]; then
#   echo "curl -d login=toto1 -d passwd=titi1 -d submit=OK 'http://localhost:8080/D04/ex01/create.php'"
# fi
# curl -d login=toto1 -d passwd=titi1 -d submit=OK 'http://localhost:8080/D04/ex01/create.php'
# echo "Supposed to have : OK"
# if [[ ($1) && ($1 = "v") ]]; then
#   cat ./ex01/private/passwd
#   echo ""
# fi
# echo ""
# if [[ ($1) && ($1 = "v") ]]; then
#   echo "curl -d login=toto1 -d passwd=titi1 -d submit=OK 'http://localhost:8080/D04/ex01/create.php"
# fi
# curl -d login=toto1 -d passwd=titi1 -d submit=OK'http://localhost:8080/D04/ex01/create.php'
# echo "Supposed to have : ERROR"
# if [[ ($1) && ($1 = "v") ]]; then
#   cat ./ex01/private/passwd
#   echo ""
# fi
# echo ""
# if [[ ($1) && ($1 = "v") ]]; then
#   echo "curl -d login=toto2 -d passwd= -d submit=OK 'http://localhost:8080/D04/ex01/create.php'"
# fi
# curl -d login=toto2 -d passwd= -d submit=OK'http://localhost:8080/D04/ex01/create.php'
# echo "Supposed to have : ERROR"
# if [[ ($1) && ($1 = "v") ]]; then
#   cat ./ex01/private/passwd
#   echo ""
# fi
# echo ""