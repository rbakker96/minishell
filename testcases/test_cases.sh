#!/bin/bash

# Set color
Color_Off='\033[0m'       # Text Reset
lack='\033[0;30m'         # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

####################################################################
#                           CD			                           #
####################################################################

echo -e "$CD TESTING $Color_Off"

# Relative path
cd test

# Absolute path 
cd /Users/roybakker/Documents/Codam/minishell/5_execution/executable

# non existing path
cd asdf

# To much arguments
cd test with four arguments

# ignored with pipe
cd test | cat main.c

# non existing input file
cd test < out99

# with output file and pipe
cd test > out | cat main.c

# with non existing input file and pipe
cd test < out99 | echo hallo

# non existing path and working second command
cd nothing ; echo hallo

# if cd is after or followed by a pipe, it does not execute anything or change directory
# nothing is executed. ls -la output is lost and directory stays the same
ls -la | cd

#if test directory does not exist, error message
#if test directory exists, nothing is executed. ls -la output is lost and directory stays the same
#if there's output redirection before the pipe, out is created with ls output. However, cd still does not change dir
ls -la | cd test
ls -la > out | cd test

#if test directory does not exist, error message
#if test directory exists, ls -la is executed. However, directory stays the same
cd test | ls -la

####################################################################
#                           PWD 		                           #
####################################################################

echo -e "$PWD TESTING $Color_Off"

# pwd output will be cat to the stdout
ls -la | pwd | cat

# echo will be executed
ls -la | pwd | echo

# ####################################################################
# #                           ECHO 		                           #
# ####################################################################

# echo -e "$ECHO TESTING $Color_Off"

# # multiline commands
# # missing "
# echo "hallo
# echo "echo   ; echo hi
# echo "hi  \"

# # missing '
# echo 'hi
# echo 'hi   ; echo hi

# # Redirections
# # input redirection error's
# echo <
# echo hallo < | echo
# echo <   < test
# echo <<   < test
# echo <   ; echo hallo
# echo <<< hallo

# #output redirection error's
# echo >
# echo hallo > | test
# echo hallo >> | echo
# echo >   > test
# echo >>   > test
# echo >   ; echo hallo
# echo >>> hallo

# # Pipe situations
# echo hallo ||   t
# echo hallo ||   ;
# echo hallo ||   echo hi; echo hallo
# echo hallo ||| hallo

# # Tokens at end of line
# echo hallo |
# echo hallo >
# echo hallo >>
# echo hallo <
# echo hallo \

# # Tokens at begin of line
# ; echo
# | echo

# # Double ommand seperators
# echo hallo ;; echo hi

####################################################################
#                           PIPE 		                           #
####################################################################

echo -e "$PIPE TESTING $Color_Off"

# no pipe

cat < main.c > out
./test/linux_child > out
./test/child > out

# pipe after & pipe before

pwd | cat

pwd | cat > out

ls -la | grep Oct > out

ls -la | grep Oct

ls -la > out | grep Oct

ls | grep Oct < input

ls > out | grep Oct < input

# pipe both before & after

ls -la | grep Oct | grep test > out

ls -la | grep Oct | grep test | grep test_pipe

ls -la | grep Oct | grep test | grep test_pipe > out

ls -la | grep Oct | grep qli | grep 30 | grep test | grep test_pipe > out

pwd | cat | grep /home/ > out

ls -la | grep Oct > out| grep test | grep test_pipe

ls -la | grep Oct | grep test > out | grep test_pipe

ls -la > out| grep Oct | grep test > out | grep test_pipe

ls -la | grep Oct | cat

####################################################################
#                           REDIRECTION	                           #
####################################################################

### output redirection ###

# out is created and main.c is sent to out. No input goes to grep
cat main.c > out | grep codam

# out and out1 are both created. main.c is sent to out
cat main.c > out | > out1

# multiple output files: out, out1 & out2 are created; main.c gets directed to out2; echo hello is executed
cat main.c > out > out1 > out2 | echo hello

# multiple output files: out, out1 & out2 are created; main.c gets directed to out2. BUT cat does not keep on waiting
cat main.c > out > out1 > out2 | cat

# however, if it's not a pipe but a ; cat is a fresh command and will wait for input
cat main.c > out > out1 > out2 ; cat

### input redirection ###

# if int does not exist, it will say no file or directory
# if int exist, cat main.c will be executed. < int will be disregarded 
cat main.c < input

# if int does not exist, error message
# if int exist, this command does not do anything. cat main.c goes into the pipe, however, it is not used by < int following the pipe
cat main.c | < input

# if any input file does not exist, error messsagev
# if all files exist, cat will display info from int3 (the last input file)
cat <int1 <int2 < int3

### only input or output redirection ###

# regardless of the content, out file will be truncated to 0
> out

# will create the file or leave the original file intact
>> out

# if file does not exist, it will say no such file or redirectory
< int

# if file exist, it will do nothing with the input
< int

####################################################################
#                           EXIT STATUS	                           #
####################################################################

# 126 exit code -> it's a directory
./test

# 127 exit code -> permission denied
./test/child_no_permission

# 0 exit code
./test/child

# 127 exit code -> command not found
adsafdsfas

# 0 exit code -> expansion to nothing
$hihihi

# 0 exit code -> echo \n
echo $hkskks
