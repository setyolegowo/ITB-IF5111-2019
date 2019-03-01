#!/bin/bash

index=0
declare -a result
for n in {100000..1000000..100000}; do
    let "index = $n/2"
    for i in {1..20}; do
        result[$i]=$(dist/output data/daftar_rumah.medium.csv $n index $index | grep -Eo "[0-9]+")
    done
    combine_result=`echo ${result[@]} | sed 's/ /;/g'`
    echo "\"R $n\";$combine_result"
done
