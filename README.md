# Seashell

Seashell is a minimal shell for Linux.

## Features

* Supports built-in commands: `cd`, `setp`, and `exit`
* Automatically prepends a single default `PATH` to every command
* Supports formatted prompt text, which can include useful information: current user name, current working directory, error code of the last command executed
    * Supports changing the prompt format string at runtime, using `setp` built-in command

## Building

### Prerequisities
* make
* A C++ compiler

Build the project by running 

    make

at the project root directory. The built executable can be found at `./build/bin/seashell`.

The building and running process can be simply done using one command:

    make run

