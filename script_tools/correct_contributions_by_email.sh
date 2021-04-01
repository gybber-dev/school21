#!/bin/sh
# see instruction on:
# https://stackoverflow.com/questions/15289768/github-commits-arent-recorded-in-the-your-contributions-calendar/19183663
# msg from user GinTonic

git filter-branch --env-filter '

OLD_EMAIL="yeschall@student.21-school.ru"
CORRECT_NAME="farscince"
CORRECT_EMAIL="farscince@gmail.com"

if [ "$GIT_COMMITTER_EMAIL" = "$OLD_EMAIL" ]
then
export GIT_COMMITTER_NAME="$CORRECT_NAME"
export GIT_COMMITTER_EMAIL="$CORRECT_EMAIL"
fi
if [ "$GIT_AUTHOR_EMAIL" = "$OLD_EMAIL" ]
then
export GIT_AUTHOR_NAME="$CORRECT_NAME"
export GIT_AUTHOR_EMAIL="$CORRECT_EMAIL"
fi
' --tag-name-filter cat -- --branches --tags