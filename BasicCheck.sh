#!/bin/bash
Folder_Name=$1
executeble=$2
currentLoction=`pwd`
cd $Folder_Name
num=0
make
sucssesmakeFile=$?
if [[ $sucssesmakeFile -gt 0 ]];then
    OutPutCompilar="fail"
    exit 7
    else
    OutPutCompilar="pass"

fi  

valgrind --tool=memcheck --leak-check=full --error-exitcode=1   ./"$executeble" "$@" &> /dev/null
fullmemoryout=$?
echo $fullmemoryout
if [[ $fullmemoryout -gt 0 ]];then
    OutputMemory="fail"
    num=$(("$num"+2))
    else
    OutputMemory="pass"

fi
valgrind --tool=helgrind  --error-exitcode=1   ./"$executeble" "$@" &>/dev/null
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


