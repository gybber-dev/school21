#! /bin/bash

#https://habr.com/ru/post/119436/

function foo {
    echo $1
}

ls
foo $BASH_COMMAND

BOLD='\033[1m'
NORMAL='\033[0m'
YELLOW='\033[33m'
MY_MSG='\033[1;33m'
ERROR='\033[1;31m'

# Системные сообщения
echo -e "${MY_MSG}Жирный Текст${NORMAL}"

# Сообщения об ошибках
echo -e "${ERROR}\t✗${NORMAL}"
echo "simple text"
echo "simple text"