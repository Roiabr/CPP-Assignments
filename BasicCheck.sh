#!/bin/bash
Folder_Name=$1
executeble=$2

cd "$Folder_Name"
num=0
make &>/dev/null
sucssesmakeFile=$?
if [[ $sucssesmakeFile -gt 0 ]];then
    OutPutCompilar="fail"
    exit 7
    else
    OutPutCompilar="pass"

fi  

valgrind --leak-check=full --error-exitcode=1   ./"$executeble" shift 2 "$@" &> /dev/null
fullmemoryout=$?
if [[ $fullmemoryout -gt 0 ]];then
    OutputMemory="fail"
    num=$(("$num"+2))
    else
    OutputMemory="pass"

fi
valgrind --tool=helgrind  --error-exitcode=1   ./"$executeble" shift 2 "$@" &>/dev/null
sucssesthreadout=$?
if [[ $sucssesthreadout -gt 0 ]];then
    OutPutThread="fail"
    num=$(("$num"+1))
    else
      OutPutThread="pass"
fi


    echo "compilation           memory leak             thread race;
   $OutPutCompilar                  $OutputMemory                     $OutPutThread "
   exit "$num"


