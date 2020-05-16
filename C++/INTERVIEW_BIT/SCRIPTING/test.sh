#!/bin/bash
# Incase you have to take input, please take it from file named 'input' (without quotes) [e.g. cat input]
# Print your final output to console. Do not redirect to another file.
# E.g. Suppose the question is to print the content of a file.
#      Your solution should be 'cat input'(without quotes) instead of 'cat input > output'. That's it!
# Your code starts from here...
startRange = head -1 input | grep -o '.*[0-9] ' | grep -o '.*[0-9]'
stopRange = head -1 input | grep -o ' .*[0-9]$' | grep -o '[0-9].*$'
delta=$(((stopRange+1)-startRange))
 (head -n $stopRange input | tail -n $delta) >> output