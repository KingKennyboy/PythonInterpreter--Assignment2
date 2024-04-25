#!/bin/bash

lf_result="./lf_result.txt"
lf_output="./lf_output.txt"
for testcase in "./testcases/in"*".py"; do
    output="./testcases/out"${testcase:14:2}".txt"
    ./mypython "$testcase" > "$lf_result"
    cat "$output" | sed 's/\r//g' > "$lf_output"
    if [ "$(md5sum < "$lf_output")" = "$(md5sum < "$lf_result")" ]; then
        echo "PASS "$testcase
    else
        echo "FAIL "$testcase
    fi
done

# rm -f "$lf_result"
# rm -f "$lf_output"
