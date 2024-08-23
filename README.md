## Functionality
I wrote this program to make reinstalling Arch less tedious and more declarative. Essentially, it automates installing packages and distributing files around the system.

## Requirements
1. Arch: This program is intended to be used on Arch linux
2. [yay AUR helper](https://github.com/Jguer/yay): yay is utilized to simplify the installation process and is absolutely required for the program to run
3. make: Make is used to make compilation easier, though it's not strictly necessary if you already know how to compile cpp files
4. gcc: Used to compile the program, required whether you want to use make or not

## Config formatting
### Package config
Simply write the name of the package you want to install, one per line.\
Comments start with a number sign(\#). 
### Structure config
Directory structures are formatted as shown below, with a colon(:) separating the two file paths
```
<file-path-in-arch-reload>:<file-path-in-home-folder>
```
If, for example, you had a background.png file at "./files/background.png", and you wanted it in "/home/user-home/Pictures/", you would write either:
```
./files/background.png:~/Pictures/background.png
./files/background.png:~/Pictures/
```
### Command config
Write out commands as you would like them executed in the terminal. Comments are indicated like before(with a '\#').

## Installation/Setup
1. Clone the repository
```
git clone https://github.com/mikasli/arch-reload
```
2. Move into the repository directory
```
cd arch-reload
```
3. Build the ArchReload binary
```
make
```
or without make
```
g++ -o ArchReload src/main.cpp
```
4. Give the binary executing permissions 
```
chmod u=rwx ./ArchReload
```
5. Edit the structure and packages config files, and add you own files to ./files/
6. Execute the binary
```
./ArchReload
```
7. Follow any prompts yay may give you

## TODO
~~1. Inline comment support~~\
~~2. Command support~~

