#!/bin/bash

declare -a result
for n in {100..10000..100}; do
    for i in {1..20}; do
        result[$i]=$(dist/output data/daftar_rumah.small.csv $n loglin "C" | grep -Eo "[0-9]+")
    done
    combine_result=`echo ${result[@]} | sed 's/ /,/g'`
    echo "\"R $n\",$combine_result"
done
