#!/bin/bash
PATH=./tests/
FILES=./tests/*
BFILES=./tests2/*
ERROR="syntax error"

echo -e "\033[1;4mTesting valid syntaxes:\033[0m"
for f in $FILES
do
	echo "Running $f:"
	OUTPUT=`./parser $f`
	if [[ $OUTPUT =~ $ERROR ]]; then
		echo -e "\033[1;31mTest Failed\033[0m"
		echo "$OUTPUT"
	else
		echo -e "\033[1;32mTest Passed\033[0m"
	fi
done

echo -e "\033[1;4mTesting for syntax error catching:\033[0m"
for f in $BFILES
do
	echo "Running $f:"
	OUTPUT=`./parser $f`
	if [[ $OUTPUT =~ $ERROR ]]; then
		echo -e "\033[1;32mTest Passed\033[0m"
	else
		echo -e "\033[1;31mTest Failed\033[0m"
		echo "$OUTPUT"
	fi
done
