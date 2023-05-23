#!/bin/bash

font_files="";

for file in "$@"; do
    font_files+="$file "
done

echo $font_files;
g++ $font_files -lglut -lGLU -lGL -lm
./a.out