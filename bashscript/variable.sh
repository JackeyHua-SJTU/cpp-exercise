#!/bin/bash

# ref : https://linuxconfig.org/bash-scripting-tutorial

# set a variable and dequote it with $ or ${}
STRING="Hello World"
echo ${STRING}

# read arguments, which are passed to the script
echo $1, $2 "-> $1 and $2"
args=("$@")
# $@ is an array of all arguments
echo ${args[0]}, ${args[1]} "-> ${args[0]} and ${args[1]}"
echo $@ "-> $@"
echo $# "-> Number of args is $#."

# $() is used to execute a command and return its output
echo $(pwd)

echo "Enter name:"
# read from input while running the script
read NAME
echo "your name is ${NAME}"
echo "Enter your hobbies:"
# -a can read an array into a variable
read -a HOBBIES
echo "your hobbies are ${HOBBIES[0]}, ${HOBBIES[1]}, ${HOBBIES[2]}"
# @ means all
echo "your hobbies are ${HOBBIES[@]}"

interrupt() {
    echo "Detect Ctrl + C interrupt."
}
# INT means Ctrl+C Interrupt
# when Ctrl+C is pressed, the script will execute the function `interrupt`, namely try and catch
trap interrupt INT

for a in `seq 1 10`; do
    echo $a
    sleep 1
done