# AssemblySandbox

This project is just a sandbox of Assembly and C code.  

## Why?

Because I would like to know more about the strange world of low level code. Software development is so
saturated with high level JavaScript that it is starting to make me go insane :D.

## Operating System

Ubuntu Linux -- I am running Ubuntu 18.04.2

## Preparing your system for the project

This project is managed through bash scripts rather than a typical build system like CMake.  
I have no particular reason for doing so other than to keep dependencies as limited as possible and it's more fun.

At first, you should run the bash script that gathers all the dependencies (At least I think it does. If it doesn't or you have errors, let me know by opening an issue).

**Type this is your terminal**<br>
`./deps.sh`

You should be good to go.

## Building and cleaning the project

The build.sh and clean.sh bash scripts handle these tasks.  If you make changes to the code and have build files present already, 
you may get build errors.  You should try running the clean.sh script to erase all build files to start fresh as a first step.

**To build type this in your terminal**<br>
`./build.sh`

**To erase all build files and start fresh run this in your terminal**<br>
`./clean.sh`

## Debugging the project

**ddd** is used as the debugger.  It is a user interface that sits on top of gdb, a command-line debugger used in combination with gcc.  You can find more information [here](https://www.gnu.org/software/ddd/) about ddd.

**Type this in your terminal**<br>
`./debug.sh`

An instance of ddd should now be running.

## Viewing disassembled c code

If you have any interest in seeing the assembly output of gcc, than this script does just that.  
It tells gcc to compile, but not assemble all the C source files in *src/* and stores the produced assembly 
files in *src/dasm_files*

**Type this in your terminal**<br>
`./dasm.sh`

## Running the project once it is compiled

To maintain consistency, this is also done through a bash script.

**Type this in your terminal**<br>
`./run.sh`

## Conclusions

Thank you for your interest in this repository.