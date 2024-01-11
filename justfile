default: build
    ./game

build:
    gcc -lncurses src/main.c -o game
