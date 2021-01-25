#! /bin/ksh

echo -e "\n\n🔥🔥🔥🔥\n\033[33mLearn up's version / asset managing tool\033[0m \n🔥🔥🔥🔥\n"

echo -e "\033[32m작업물을 업로드 할까요? [Y/N]: \033[0m"
read  word

value="y"
cancled="n"

if [ ${value} = $word ];then

    git add README.md
    git add Asset/*
    git add log/*
    git status


elif [ ${value} != $word ];then
    
    cancled="y"

fi

if [ ${cancled} = "y" ];then

    echo "Cancled"

fi

if [ ${cancled} = "n" ];then

    echo -e "\033[32m푸쉬 할까요?[Y/N]: \033[0m"
    read word

    if [ ${value} -eq $word ];then

       git commit -m "update"
       git push origin master

    fi

fi