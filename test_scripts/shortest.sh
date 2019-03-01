#!/bin/bash

index=0
declare -a result
for n in {3..27..2}; do
    let "index = ($n/2) + 1"
    for i in {1..20}; do
        result[$i]=$(dist/output data/daftar_rumah.small.csv $n shortest $index | grep -Eo "[0-9]+")
    done
    combine_result=`echo ${result[@]} | sed 's/ /,/g'`
    echo "\"R $n\",$combine_result"
done
