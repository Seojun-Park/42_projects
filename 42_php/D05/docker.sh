#!/bin/bash

# brew install docker-machine && docker

echo -e "type your machine name"
read word

# docker-machine create --driver virtualbox $word
docker-machine start $word
docker-machine env $word
eval $(docker-machine env $word)

# echo -e "please set the password for MYSQL"
# read pass

# echo -e "set password is $pass"
# docker run -d -p 8080:8080 -e MYSQL_ROOT_PASSWORD=$pass --name $word mysql

docker exec -i -t $word bash
