#!/bin/bash

lf_result="./lf_result.txt"
crlf_result="./crlf_result.txt"
for testcase in "./testcases/in"*".py"; do
    output="./testcases/out"${testcase:14:2}".txt"
    ./mypython.exe "$testcase" > "$lf_result"
    cat "$lf_result" | sed 's/\r$//' > "$crlf_result"
    if [ "$(md5sum < "$output")" = "$(md5sum < "$crlf_result")" ]; then
        echo "PASS "$testcase
    else
        echo "FAIL "$testcase
    fi
done

rm -f "$lf_result"
rm -f "$crlf_result"
