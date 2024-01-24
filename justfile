default: build
    ./game

build:
    gcc -lncursesw -lm src/*.c -o game -Wall
