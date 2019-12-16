GREEN='\033[0;32m'
DARK_BLUE='\e[1;34m'
RED='\x1B[31m'
BLUE='\e[96m'
NC='\033[0m'
i=0
success=0
error=0

# $1 = text, $2 = test number
test()
{
	printf "$1" >> test-printf/result.log
	test-printf/test.out $2 > test-printf/original_output
	echo $? >> test-printf/original_output
	sh test-printf/timeout.sh 1 test-printf/test.out $2 user > test-printf/user_output 2> /dev/null
	ret=$(echo $?)
	echo $ret >> test-printf/user_output
	if diff "test-printf/original_output" "test-printf/user_output" >> /dev/null
	then
		if [ $error -eq 1 ]
		then
			printf "\n"
		fi
    	printf "${GREEN}OK ${NC}"
    	printf "${GREEN}OK ${NC}\n" >> test-printf/result.log
		((success++))
		error=0
	else
    	printf "\n${RED}$1"
		if [ $ret -eq 142 ] #timeout
		then
			printf "${RED}TIMEOUT${NC}"
			printf "${RED}TIMEOUT${NC}\n" >> test-printf/result.log
		else
			printf "${RED}FAILED${NC}"
			printf "${RED}FAILED${NC}\n" >> test-printf/result.log
		fi
		error=1
	fi
	((i++))
}

rm test-printf/result.log
make all
make bonus
gcc -Wall -Wextra -Werror -Wformat=0 test-printf/test-main.c libftprintf.a -o test-printf/test.out
printf "\n${BLUE}[A - Tests without options]${NC}\n"
test "$i - (\"\") : ${NC}" $i 
test "$i - (\"1\") : ${NC}" $i 
test "$i - (\"%%%%\") : ${NC}" $i 
test "$i - (\"%%%%%%%%\") : ${NC}" $i 
test "$i - (\"%%%%%%%%%%%%\") : ${NC}" $i 
test "$i - (\"%%c\", '1') : ${NC}" $i 
test "$i - (\"%%c\", -207) : ${NC}" $i 
test "$i - (\"%%c\", 256 + 48) : ${NC}" $i 
test "$i - (\"%%c%%%%\", '3') : ${NC}" $i 
test "$i - (\"0%%c\", 0) : ${NC}" $i 
test "$i - (\"%%c\", -129) : ${NC}" $i 
test "$i - (\"%%c\", 128) : ${NC}" $i 
test "$i - (\"%%c\", 0) : ${NC}" $i 
test "$i - (\"%%s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%s%%%%\", \"Hello3\") : ${NC}" $i 
test "$i - (\"%%s\", \"\") : ${NC}" $i 
test "$i - (\"%%s\", \"1\") : ${NC}" $i 
test "$i - (\"%%i\", 0) : ${NC}" $i 
test "$i - (\"%%i\", -1) : ${NC}" $i 
test "$i - (\"%%i\", -42) : ${NC}" $i 
test "$i - (\"%%i\", 1) : ${NC}" $i 
test "$i - (\"%%i\", 42) : ${NC}" $i 
test "$i - (\"%%i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%i\", INT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%i\", INT_MIN) : ${NC}" $i 
test "$i - (\"%%i\", 1000) : ${NC}" $i 
test "$i - (\"%%i\", -1000) : ${NC}" $i 
test "$i - (\"%%d\", 0) : ${NC}" $i 
test "$i - (\"%%d\", -1) : ${NC}" $i 
test "$i - (\"%%d\", -42) : ${NC}" $i 
test "$i - (\"%%d\", 1) : ${NC}" $i 
test "$i - (\"%%d\", 42) : ${NC}" $i 
test "$i - (\"%%d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%d\", INT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%d\", INT_MIN) : ${NC}" $i 
test "$i - (\"%%d\", 1000) : ${NC}" $i 
test "$i - (\"%%d\", -1000) : ${NC}" $i 
test "$i - (\"%%u\", 0) : ${NC}" $i 
test "$i - (\"%%u\", -1) : ${NC}" $i 
test "$i - (\"%%u\", 1) : ${NC}" $i 
test "$i - (\"%%u\", 42) : ${NC}" $i 
test "$i - (\"%%u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%u\", UINT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%u\", 1000) : ${NC}" $i 
test "$i - (\"%%x\", 0) : ${NC}" $i 
test "$i - (\"%%x\", -1) : ${NC}" $i 
test "$i - (\"%%x\", -42) : ${NC}" $i 
test "$i - (\"%%x\", 1) : ${NC}" $i 
test "$i - (\"%%x\", 42) : ${NC}" $i 
test "$i - (\"%%x\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%x\", INT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%x\", INT_MIN) : ${NC}" $i 
test "$i - (\"%%x\", 1000) : ${NC}" $i 
test "$i - (\"%%x\", -1000) : ${NC}" $i 
test "$i - (\"%%X\", 0) : ${NC}" $i 
test "$i - (\"%%X\", -1) : ${NC}" $i 
test "$i - (\"%%X\", -42) : ${NC}" $i 
test "$i - (\"%%X\", 1) : ${NC}" $i 
test "$i - (\"%%X\", 42) : ${NC}" $i 
test "$i - (\"%%X\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%X\", INT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%X\", INT_MIN) : ${NC}" $i 
test "$i - (\"%%X\", 1000) : ${NC}" $i 
test "$i - (\"%%X\", -1000) : ${NC}" $i 
test "$i - (\"%%p\", (void*)1) : ${NC}" $i 
test "$i - (\"%%p\", (void*)-1) : ${NC}" $i 
test "$i - (\"%%p\", (void*)42) : ${NC}" $i 
test "$i - (\"%%p\", (void*)1000) : ${NC}" $i 
test "$i - (\"%%p\", (void*)ULONG_MAX) : ${NC}" $i 
test "$i - (\"%%p\", (void*)ULONG_MAX + 1) : ${NC}" $i 
printf "\n\n${DARK_BLUE}Result [$success/$i]${NC}"
