#!/bin/zsh

# . ~/.zshrc

ldd a.out
valgrind ./a.out a.txt

echo Exit code: $?

