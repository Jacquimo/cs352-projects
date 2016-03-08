#!/bin/bash
if [ "$#" -eq 0 ]; then
	OPTION=5
else OPTION=$1
fi

PATH=./tests/
OLDv=./tests/parsing_project1/valid/*
OLDi=./tests/parsing_project1/invalid/*
PARSINGv=./tests/parsing/valid/*
PARSINGi=./tests/parsing/invalid/*
TYPESv=./tests/types/valid/*
TYPESi=./tests/types/invalid/*

ERROR="syntax error"
TERROR="type error"

#Counter variables for each set of tests
OLDCORRECT=0
OLDTOTAL=0
OLDFAIL=0
PARSINGCORRECT=0
PARSINGTOTAL=0
PARSINGFAIL=0
TYPESCORRECT=0
TYPESTOTAL=0
TYPESFAIL=0
OUTCORRECT=0
OUTTOTAL=0
OUTFAIL=0

#overall counters
TOTAL=0
CORRECT=0
FAIL_COUNT=0

#########################################
#PART ONE: OLD SYNTAX TESTS
#########################################

#run the old tests first

if [[ $OPTION == 1 || $OPTION > 4 ]]; then
	echo -e "\033[96m---------------------------------\033[0m"
	echo -e "\033[91mOld Syntax Tests:\033[0m"
	echo -e "\033[96m---------------------------------\033[0m"
fi

if [[ $OPTION == 1 || $OPTION > 4 ]]; then
	echo -e "\033[1;4;93mTesting valid syntaxes from Project 1:\033[0m"
fi
for f in $OLDv
do
	let TOTAL=TOTAL+1
	let OLDTOTAL=OLDTOTAL+1
	if [[ $OPTION == 1 || $OPTION > 4 ]]; then
		echo "Running $f:"
	fi
	OUTPUT=`./parser $f`
	if [[ $OUTPUT =~ $ERROR ]]; then
		if [[ $OPTION == 1 || $OPTION > 4 ]]; then
			echo -e "\033[1;31mTest Failed\033[0m"
			echo "$OUTPUT"
		fi
		let FAIL_COUNT=FAIL_COUNT+1
		let OLDFAIL=OLDFAIL+1
	else
		let CORRECT=CORRECT+1
		let OLDCORRECT=OLDCORRECT+1
		if [[ $OPTION == 1 || $OPTION > 4 ]]; then
			echo -e "\033[1;32mTest Passed\033[0m"
		fi
	fi
done

if [[ $OPTION == 1 || $OPTION > 4 ]]; then
	echo -e "\033[1;4;93m\nTesting invalid syntaxes from Project 1:\033[0m"
fi
for f in $OLDi
do
	let TOTAL=TOTAL+1
	let OLDTOTAL=OLDTOTAL+1
	if [[ $OPTION == 1 || $OPTION > 4 ]]; then
		echo "Running $f:"
	fi
        OUTPUT=`./parser $f`
	if [[ $OUTPUT =~ $ERROR ]]; then
		if [[ $OPTION == 1 || $OPTION > 4 ]]; then
			echo -e "\033[1;32mTest Passed\033[0m"
		fi
		let CORRECT=CORRECT+1
		let OLDCORRECT=OLDCORRECT+1
	else
		if [[ $OPTION == 1 || $OPTION > 4 ]]; then
			echo -e "\033[1;31mTest Failed\033[0m"
			echo "$OUTPUT"
		fi
		let FAIL_COUNT=FAIL_COUNT+1
		let OLDFAIL=OLDFAIL+1
	fi
done

#print score for old tests
if [[ $OPTION == 1 || $OPTION > 4 ]]; then
	echo
	echo -e "\033[1;4mOld Syntax Score:\033[0m $OLDCORRECT/$OLDTOTAL"
	if [[ $OLDCORRECT == $OLDTOTAL ]]; then
		echo -e "\033[1;32mAll Project 1 Parsing Tests Passed\033[0m"
	else
		echo -e "\033[1;31m$OLDFAIL Old Test(s) Failed from Project 1\033[0m"
	fi
	echo
fi


#########################################
#PART TWO: MORE SYNTAX ERRORS
#########################################

#run the new tests for syntax validity
if [[ $OPTION == 2 || $OPTION > 4 ]]; then
	echo -e "\033[96m---------------------------------\033[0m"
	echo -e "\033[91mNew Syntax Tests:\033[0m"
	echo -e "\033[96m---------------------------------\033[0m"
fi

if [[ $OPTION == 2 || $OPTION > 4 ]]; then
	echo -e "\033[1;4;93mTesting new valid syntaxes:\033[0m"
fi
for f in $PARSINGv
do
	let TOTAL=TOTAL+1
	let PARSINGTOTAL=PARSINGTOTAL+1
	if [[ $OPTION == 2 || $OPTION > 4 ]]; then
		echo "Running $f:"
	fi
	OUTPUT=`./parser $f`
	if [[ $OUTPUT =~ $ERROR ]]; then
		if [[ $OPTION == 2 || $OPTION > 4 ]]; then
			echo -e "\033[1;31mTest Failed\033[0m"
			echo "$OUTPUT"
		fi
		let FAIL_COUNT=FAIL_COUNT+1
		let PARSINGFAIL=PARSINGFAIL+1
	else
		let CORRECT=CORRECT+1
		let PARSINGCORRECT=PARSINGCORRECT+1
		if [[ $OPTION == 2 || $OPTION > 4 ]]; then
			echo -e "\033[1;32mTest Passed\033[0m"
		fi
	fi
done

if [[ $OPTION == 2 || $OPTION > 4 ]]; then
	echo -e "\033[1;4;93m\nTesting new invalid syntaxes:\033[0m"
fi
for f in $PARSINGi
do
	let TOTAL=TOTAL+1
	let PARSINGTOTAL=PARSINGTOTAL+1
	if [[ $OPTION == 2 || $OPTION > 4 ]]; then
		echo "Running $f:"
	fi
        OUTPUT=`./parser $f`
	if [[ $OUTPUT =~ $ERROR ]]; then
		if [[ $OPTION == 2 || $OPTION > 4 ]]; then
			echo -e "\033[1;32mTest Passed\033[0m"
		fi
		let CORRECT=CORRECT+1
		let PARSINGCORRECT=PARSINGCORRECT+1
	else
		if [[ $OPTION == 2 || $OPTION > 4 ]]; then
			echo -e "\033[1;31mTest Failed\033[0m"
			echo "$OUTPUT"
		fi
		let FAIL_COUNT=FAIL_COUNT+1
		let PARSINGFAIL=PARSINGFAIL+1
	fi
done

#print score for new syntax tests
if [[ $OPTION == 2 || $OPTION > 4 ]]; then
	echo
	echo -e "\033[1;4mScore for Parsing New Syntaxes:\033[0m $PARSINGCORRECT/$PARSINGTOTAL"
	if [[ $PARSINGCORRECT == $PARSINGTOTAL ]]; then
		echo -e "\033[1;32mAll New Parsing Tests Passed\033[0m"
	else
		echo -e "\033[1;31m$PARSINGFAIL New Parsing Test(s) Failed\033[0m"
	fi
	echo
fi

#########################################
#PART THREE: TYPE ERRORS
#########################################

#run the new tests for type violation detection
if [[ $OPTION == 3 || $OPTION > 4 ]]; then
	echo -e "\033[96m---------------------------------\033[0m"
	echo -e "\033[91mType Error Detection Tests:\033[0m"
	echo -e "\033[96m---------------------------------\033[0m"
fi

if [[ $OPTION == 3 || $OPTION > 4 ]]; then
	echo -e "\033[1;4;93mTesting for type validity:\033[0m"
fi
for f in $TYPESv
do
	let TOTAL=TOTAL+1
	let TYPESTOTAL=TYPESTOTAL+1
	if [[ $OPTION == 3 || $OPTION > 4 ]]; then
		echo "Running $f:"
	fi
	OUTPUT=`./parser $f`
	if [[ $OUTPUT =~ $TERROR ]]; then
		if [[ $OPTION == 2 || $OPTION > 4 ]]; then
			echo -e "\033[1;31mTest Failed\033[0m"
			echo "$OUTPUT"
		fi
		let FAIL_COUNT=FAIL_COUNT+1
		let TYPESFAIL=TYPESFAIL+1
	else
		let CORRECT=CORRECT+1
		let TYPESCORRECT=TYPESCORRECT+1
		if [[ $OPTION == 3 || $OPTION > 4 ]]; then
			echo -e "\033[1;32mTest Passed\033[0m"
		fi
	fi
done

if [[ $OPTION == 3 || $OPTION > 4 ]]; then
	echo -e "\033[1;4;93m\nTesting for type violation detection:\033[0m"
fi
for f in $TYPESi
do
	let TOTAL=TOTAL+1
	let TYPESTOTAL=TYPESTOTAL+1
	if [[ $OPTION == 3 || $OPTION > 4 ]]; then
		echo "Running $f:"
	fi
        OUTPUT=`./parser $f`
	if [[ $OUTPUT =~ $TERROR ]]; then
		if [[ $OPTION == 3 || $OPTION > 4 ]]; then
			echo -e "\033[1;32mTest Passed\033[0m"
		fi
		let CORRECT=CORRECT+1
		let TYPESCORRECT=TYPESCORRECT+1
	else
		if [[ $OPTION == 3 || $OPTION > 4 ]]; then
			echo -e "\033[1;31mTest Failed\033[0m"
			echo "$OUTPUT"
		fi
		let FAIL_COUNT=FAIL_COUNT+1
		let TYPESFAIL=TYPESFAIL+1
	fi
done

#print score for new syntax tests
if [[ $OPTION == 3 || $OPTION > 4 ]]; then
	echo
	echo -e "\033[1;4mScore for Parsing Detection of Type Violations:\033[0m $TYPESCORRECT/$TYPESTOTAL"
	if [[ $TYPESCORRECT == $TYPESTOTAL ]]; then
		echo -e "\033[1;32mAll Type Violation Tests Passed\033[0m"
	else
		echo -e "\033[1;31m$TYPESFAIL Type Violation Test(s) Failed\033[0m"
	fi
	echo
fi


#########################################
#PART FOUR: OUTPUTS (File names and outputs)
#########################################

#run the new tests for type violation detection
if [[  $OPTION > 3 ]]; then
	echo -e "\033[96m---------------------------------\033[0m"
	echo -e "\033[91mOutput Validity Tests:\033[0m"
	echo -e "\033[96m---------------------------------\033[0m"
fi

##declare array of test names and the corresponding desired output
declare -a testNames
declare -a testResults
declare -a altResults

#testNames[X]=./tests/output/
#testResults[X]=$(printf "")

testNames[0]=./tests/output/docwrites
testResults[0]="two plus ten = string"
testNames[1]=./tests/output/piazza_scopes
testResults[1]=$(printf "50\n50\n5\n")
testNames[2]=./tests/output/long_param_list
testResults[2]=$(printf "This will output a string ending with a newline.\n")
testNames[3]=./tests/output/multi_docwrite
testResults[3]=$(printf "2string\n")
testNames[4]=./tests/output/print_then_error
testResults[4]=$(printf "50\n$ERROR")
testNames[5]=./tests/output/print_then_error2
testResults[5]=$(printf "Two semicolons follow this statement.$ERROR")
testNames[6]=./tests/output/piazza_types
testResults[6]=$(printf "a new string\n")
testNames[7]=./tests/output/type_error_report
testResults[7]=$(printf "Line 2, type violation\n")
altResults[7]=$(printf "Line 3, type violation\n")
testNames[8]=./tests/output/type_error_report2
testResults[8]=$(printf "Line 2, type violation\n")
altResults[8]=$(printf "Line 3, type violation\n")
testNames[9]=./tests/output/type_error_report3
testResults[9]=$(printf "Line 2, type violation\n")
altResults[9]=$(printf "Line 3, type violation\n")
testNames[10]=./tests/output/arith_params
testResults[10]=$(printf "26+10 = 36\n")
testNames[11]=./tests/output/error_in_docwrite
testResults[11]=$(printf "$ERROR")
testNames[12]=./tests/output/error_in_docwrite2
testResults[12]=$(printf "$ERROR")
testNames[13]=./tests/output/empty
testResults[13]=$(printf "")
testNames[14]=./tests/output/simple_undeclared
testResults[14]=$(printf "Line 2, type violation")
testNames[15]=./tests/output/simple_print
testResults[15]=$(printf "a")
testNames[16]=./tests/output/misspelled_docwrite_syntax
testResults[16]=$(printf "$ERROR")
testNames[17]=./tests/output/bad_open
testResults[17]=$(printf "$ERROR")
testNames[18]=./tests/output/bad_close
testResults[18]=$(printf "$ERROR")
testNames[19]=./tests/output/bad_syntax
testResults[19]=$(printf "$ERROR")
testNames[20]=./tests/output/handout_sample
testResults[20]=$(printf "two plus ten = 12\nten * ten = 100\nten / two = 5\n5")
testNames[21]=./tests/output/multiple_undeclared
testResults[21]=$(printf "Line 2, type violation")
testNames[22]=./tests/output/var_undeclared
testResults[22]=$(printf "Line 6, type violation")
altResults[22]=$(printf "Line 7, type violation")
testNames[23]=./tests/output/multi_docwrite2
testResults[23]=$(printf "thing)")
testNames[24]=./tests/output/invalid_params
testResults[24]=$(printf "$ERROR")

###################################
#Part 2

testNames[25]=./tests/output/invalid_expr
testResults[25]=$(printf "Line 5, type violation")
altResults[25]=$(printf "Line 6, type violation")
testNames[26]=./tests/output/expression_syntax
testResults[26]=$(printf "$ERROR")
testNames[27]=./tests/output/docwrite_interpretation
testResults[27]="11-51%d1%d113"
testNames[28]=./tests/output/blank
testResults[28]=$(printf "")
testNames[29]=./tests/output/very_long_output
testResults[29]=$(printf "two plus ten = 12<br 	asdfl;jhkl;gah ;lkasjdflkjaklsgdj klashjasdfASDFASGHASDGKJ-980192785071\`5t71871289357978tywe/>ten * ten = 100<br 	asdfl;jhkl;gah ;lkasjdflkjaklsgdj klashjasdfASDFASGHASDGKJ-980192785071\`5t71871289357978tywe/>ten / two = 5<br 	asdfl;jhkl;gah ;lkasjdflkjaklsgdj klashjasdfASDFASGHASDGKJ-980192785071\`5t71871289357978tywe/>5")
testNames[30]=./tests/output/undeclared_nonstatement
testResults[30]=$(printf "$ERROR")
testNames[31]=./tests/output/undeclared_nonstatement2
testResults[31]=$(printf "$ERROR")
testNames[32]=./tests/output/long_output_carriage_returns
testResults[32]=$(printf "$ERROR")
testNames[33]=./tests/output/double_semicolon
testResults[33]=$(printf "$ERROR")
testNames[34]=./tests/output/double_semicolon2
testResults[34]=$(printf "$ERROR")
testNames[35]=./tests/output/mixed_type_expr
testResults[35]=$(printf "two plus ten = Line 6, type violation")
testNames[36]=./tests/output/mixed_type_expr2
testResults[36]=$(printf "Line 2, type violation")
testNames[37]=./tests/output/undeclared_in_expr
testResults[37]=$(printf "Line 2, type violation")
testNames[38]=./tests/output/evaluate_and_print
testResults[38]=$(printf "15\n15\n15\n")
testNames[39]=./tests/output/print_then_error3
testResults[39]=$(printf "two plus ten = -228Line 13, type violation")
testNames[40]=./tests/output/empty2
testResults[40]=$(printf "")
testNames[41]=./tests/output/print_then_error4
testResults[41]=$(printf "five510two\nLine 5, type violation")
testNames[42]=./tests/output/print_then_error5
testResults[42]=$(printf "two plus ten = Line 8, type violation")
testNames[43]=./tests/output/invalid_param_expr
testResults[43]=$(printf "Line 3, type violation")
testNames[44]=./tests/output/multi_prints
testResults[44]="two plus ten != -228ten * ten = 223151"
testNames[45]=./tests/output/simple_eval_output
testResults[45]="two*ten = 20"
testNames[46]=./tests/output/leading_zeroes
testResults[46]=$(printf "5")
testNames[47]=./tests/output/params_multi_quotes
testResults[47]=$(printf "parsing list with (separated!) quotes.\n-6466")
testNames[48]=./tests/output/multi_docwrite3
testResults[48]=$(printf "6string 10")
testNames[49]=./tests/output/not_a_linebreak
testResults[49]=$(printf "thing)\n<br/>\n")

######################
# part 3
testNames[50]=./tests/output/linebreak_string_concat
testResults[50]=$(printf "thing)\nLine 6, type violation")
altResults[50]=$(printf "thing)\nLine 7, type violation")
testNames[51]=./tests/output/object_fields
testResults[51]=$(printf "44")
testNames[52]=./tests/output/scope_redeclaration
testResults[52]=$(printf "42Line 8, type violation")
testNames[53]=./tests/output/multi_scopes
testResults[53]=$(printf "22323")
testNames[54]=./tests/output/multi_scopes2
testResults[54]=$(printf "2232")
testNames[55]=./tests/output/multi_scopes2b
testResults[55]=$(printf "2232")
testNames[56]=./tests/output/politics
testResults[56]=$(printf "the dump is donald trump\nplease don't vote for donald trump, unless you're a guy who really likes the trump\n\n\n")
testNames[57]=./tests/output/scopes_in_scopes
testResults[57]=$(printf "Hello from cirtuit city\nWashington, D.C. is located at a longitude of -77.0164 and a latitude of 38.9047.\n(Donald Trump probably won't make it in.)\nBut since Donald prefers only significant numbers (those larger than a million), lets multiply the longitude by a million.\n-77.0164 times one million = -77000000\n\n\nThat's enough of that. For scope city, we flew back to cirtuit city\nBut that's not a city!\nSo we moved to Ely, Minnesota\nSince it is summer in Ely, Minnesota, the delicious blue soda is available.\n\n\nSome time went by. How long was I on vacation?\n8 months\nSince it is winter in Ely, Minnesota, the delicious blue soda is unavailable.\nWe stayed awhile in Ely, Minnesota, but slowly vacation times ended.\nWe ended up leaving and going back to metropolis.\nHard to put that one on a map, though.\nAnd now we're in West Lafayette.\n")
testNames[58]=./tests/output/piazza_object_error
testResults[58]=$(printf "Line 13, type violation")
testNames[59]=./tests/output/use_unin_var
testResults[59]=$(printf "Line 3, type violation")
altResults[59]="Line 4, type violation"
testNames[60]=./tests/output/init_in_docwrite
testResults[60]=$(printf "$ERROR")
testNames[61]=./tests/output/nested_var
testResults[61]=$(printf "Line 15, type violation")
testNames[62]=./tests/output/nested_var2
testResults[62]=$(printf "3216Line 18, type violation")
testNames[63]="./tests/output/test01"
testResults[63]=$(printf "two plus ten = 12\nten * ten = 12\nten / two = 1234511550123hello53")
testNames[64]=./tests/output/docwrite_as_expr
testResults[64]=$(printf "$ERROR")
testNames[65]=./tests/output/int_declare
testResults[65]=$(printf "$ERROR")
testNames[66]=./tests/output/syntax_or_type
testResults[66]=$(printf "two plus ten = $ERROR")
altResults[66]=$(printf "two plus ten = Line 7, type violation")
testNames[67]=./tests/output/mismatched_quotes
testResults[67]=$(printf "$ERROR")
testNames[68]=./tests/output/mod
testResults[68]=$(printf "$ERROR")
testNames[69]=./tests/output/empty_string
testResults[69]=$(printf "")
testNames[70]=./tests/output/empty_string2
testResults[70]=$(printf "")
testNames[71]=./tests/output/hello_world_expr
testResults[71]=$(printf "15kwasdhello world")
testNames[72]=./tests/output/scopes1
testResults[72]=$(printf "2\nYour test...\nAs good as scoped!\n44\nlion oil 32\n32\n2\n")
testNames[73]=./tests/output/scopes2
testResults[73]=$(printf "2\nLine 7, type violation")
testNames[74]=./tests/output/object_data_inches
testResults[74]=$(printf "22 inches")

########################
# part 4: part 4

testNames[75]=./tests/output/object1
testResults[75]=$(printf "12")
testNames[76]=./tests/output/object2
testResults[76]=$(printf "12\n99\n")
testNames[77]=./tests/output/object3
testResults[77]=$(printf "100\n100\nAbe\nPresident Lincoln\n")
testNames[78]=./tests/output/object4
testResults[78]=$(printf "100\n100\nAbe\nMr. Lincoln\nLine 28, type violation")
testNames[79]=./tests/output/redeclaring
testResults[79]=$(printf "12\ntesting...\nredeclared\n9001\n")
testNames[80]=./tests/output/bad_reassign
testResults[80]=$(printf "Line 5, type violation")
testNames[81]=./tests/output/object_assignment
testResults[81]=$(printf "Line 8, type violation")
altResults[81]=$(printf "Line 9, type violation")
testNames[82]=./tests/output/field_assignment
testResults[82]=$(printf "3")
testNames[83]=./tests/output/docwrite_scope
testResults[83]=$(printf "3$ERROR")
testNames[84]=./tests/output/undeclared
testResults[84]=$(printf "Line 10, type violation")
altResults[84]=$(printf "Line 11, type violation")
testNames[84]=./tests/output/undeclared2
testResults[84]=$(printf "Line 7, type violation")
testNames[85]=./tests/output/unusual_whitespace_expr
testResults[85]=$(printf "two plus ten = 12")
testNames[86]=./tests/output/eratic_caps
testResults[86]=$(printf "Line 4, type violation")
testNames[87]=./tests/output/monty_python
testResults[87]=$(printf "Knock Knock.  We're here for you liver\nBring out your dead.  Bring out your dead\nNow being sued for copyright enfringement by Monty Python 90\n")
testNames[88]=./tests/output/assignment_syntax
testResults[88]=$(printf "$ERROR")
testNames[89]=./tests/output/invalid_param_list
testResults[89]=$(printf "$ERROR")
testNames[90]=./tests/output/double_semicolon3
testResults[90]=$(printf "Two semicolons follow this statement.$ERROR")
testNames[91]=./tests/output/object_as_field
testResults[91]=$(printf "$ERROR")
testNames[92]=./tests/output/confession
testResults[92]=$(printf "100\n101\n42\n99\n42 and 2\nhonestly tests always had newlines because it made them easier to write\n24\n")
testNames[93]=./tests/output/test02
testResults[93]=$(printf "1912 = 1912\n9\n16\n107\n107\n5748468\n")
testNames[94]=./tests/output/rumor
testResults[94]=$(printf "3216the 240 project required us to solve isol, a test case built on many columns\nrumor had it that only 2 students were able to get full credit.\n\nbut I knew one of them, and let's be honest...\nHe just put\n\nif (nColumns > 300) {\n    nColumns /= 32; //beat isol\n}\nLine 38, type violation")
testNames[95]=./tests/output/field_declare
testResults[95]=$(printf "999\n34\n$ERROR")
testNames[96]=./tests/output/field_assign
testResults[96]=$(printf "999\n34\n4")
testNames[97]=./tests/output/scopes3
testResults[97]=$(printf "<script type=17>\ntext/JavaScript\ntext/JavaScript\nJavaScript\n34\nscope3 is best\n\nexcessive scoping...Whoa, wait, please wait for me!\nWOHPLZW84ME\n34\n1991\n")
testNames[98]=./tests/output/field_initialized_as_other_field
testResults[98]=$(printf "Line 8, type violation")
testNames[99]=./tests/output/associativity
testResults[99]=$(printf "116201621")
testNames[100]=./tests/output/associativity2
testResults[100]=$(printf "2342140136162-5")


#testNames[X]=./tests/output/
#testResults[X]=$(printf "")


#########################################
#PART FOUR: OUTPUTS (Actual Testing)
#########################################

partcount=0
for (( i = 0; i< ${#testNames[@]}; i=$i+1));
do
	modulo=$(( $OUTTOTAL % 25 ))
	if [[ $OPTION > 3 && $modulo == 0 ]]; then
		let partcount=partcount+1
		echo
		echo -e "\033[1;4;93mTesting output correctness: Part $partcount\033[0m"
	fi

	let TOTAL=TOTAL+1
	let OUTTOTAL=OUTTOTAL+1
	if [[ $OPTION > 3 ]]; then
		echo "Running ${testNames[${i}]}:"
	fi
        OUTPUT=`./parser ${testNames[${i}]}`
	if [[ "$OUTPUT" == ${testResults[${i}]} ]] || [[  "$OUTPUT" == ${altResults[${i}]} && ${altResults[${i}]} != "" ]]; then
		if [[ $OPTION > 3 ]]; then
			echo -e "\033[1;32mTest Passed\033[0m"
		fi
		let CORRECT=CORRECT+1
		let OUTCORRECT=OUTCORRECT+1
	else
		if [[ $OPTION > 3 ]]; then
			echo -e "\033[1;31mTest Failed\033[0m"
			echo "PARSER OUTPUT: "
			echo $OUTPUT
			echo "EXPECTED: "
			echo ${testResults[${i}]}
		fi
		let FAIL_COUNT=FAIL_COUNT+1
		let OUTFAIL=OUTFAIL+1
	fi
done



#print score for output tests
if [[ $OPTION > 3 ]]; then
	echo
	echo -e "\033[1;4mScore for Output Validity:\033[0m $OUTCORRECT/$OUTTOTAL"
	if [[ $OUTCORRECT == $OUTTOTAL ]]; then
		echo -e "\033[1;32mAll Output Validity Tests Passed\033[0m"
	else
		echo -e "\033[1;31m$OUTFAIL Output Validity Test(s) Failed\033[0m"
	fi
	echo
fi

############################################
#FINAL RESULTS: print the overall results
###########################################
echo -e "\033[96m---------------------------------\033[0m"
echo -e "\033[91mOverall Testing Results:\033[0m"
echo -e "\033[96m---------------------------------\033[0m"
#print the old syntax score again
echo -e "\033[1;4mOld Syntax Score:\033[0m $OLDCORRECT/$OLDTOTAL"
if [[ $OLDCORRECT == $OLDTOTAL ]]; then
        echo -e "\033[1;32mAll Project 1 Parsing Tests Passed\033[0m"
else
        echo -e "\033[1;31m$OLDFAIL Old Test(s) Failed from Project 1\033[0m"
fi
#print the new syntax score
echo -e "\033[1;4mScore for Parsing New Syntaxes:\033[0m $PARSINGCORRECT/$PARSINGTOTAL"
if [[ $PARSINGCORRECT == $PARSINGTOTAL ]]; then
        echo -e "\033[1;32mAll New Parsing Tests Passed\033[0m"
else
        echo -e "\033[1;31m$PARSINGFAIL New Parsing Test(s) Failed\033[0m"
fi
#reprint the type violation test score
echo -e "\033[1;4mScore for Parsing Detection of Type Violations:\033[0m $TYPESCORRECT/$TYPESTOTAL"
if [[ $TYPESCORRECT == $TYPESTOTAL ]]; then
	echo -e "\033[1;32mAll Type Violation Tests Passed\033[0m"
else
	echo -e "\033[1;31m$TYPESFAIL Type Violation Test(s) Failed\033[0m"
fi
#print score for output tests
echo -e "\033[1;4mScore for Output Validity:\033[0m $OUTCORRECT/$OUTTOTAL"
if [[ $OUTCORRECT == $OUTTOTAL ]]; then
	echo -e "\033[1;32mAll Output Validity Tests Passed\033[0m"
else
	echo -e "\033[1;31m$OUTFAIL Output Validity Test(s) Failed\033[0m"
fi
echo

#print the overall score
echo
echo -e "\033[1;4mFinal Score:\033[0m $CORRECT/$TOTAL"
if [[ $CORRECT == $TOTAL ]]; then
	echo -e "\033[1;32mAll Tests Passed\033[0m"
else
	echo -e "\033[1;31m$FAIL_COUNT Test(s) Failed\033[0m"
fi
