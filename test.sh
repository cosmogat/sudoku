#!/bin/bash
# 05-03-2013
# alejandro
# test.sh

make > /dev/null

for i in $(ls sud/*) ; do 
    AUX=$(echo $i | cut -d'/' -f2-)
    NUM=$(echo $AUX | cut -d'.' -f1)
    echo "Resolvent sudoku numero $NUM."
    ./sudoku sud/$AUX > res_tmp
    DIF=$(diff res/$AUX res_tmp | wc -c)
    if [ $DIF -gt 1 ] ; then
	echo "\tHi ha diferencies en $i."
    fi
    rm res_tmp > /dev/null
done
