#!/bin/bash

index=0
declare -a result
for n in {100..10000..100}; do
    let "index = $n/2"
    for i in {1..20}; do
        result[$i]=$(dist/output data/daftar_rumah.small.csv $n index $index | grep -Eo "[0-9]+")
    done
    combine_result=`echo ${result[@]} | sed 's/ /,/g'`
    echo "\"R $n\",$combine_result"
done
