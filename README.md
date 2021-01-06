##### Conway's Game of Life README
* Name: Mack Anderson
* Student ID: 1099411
* Email: mander39@uoguelph.ca

### Executable Source Files
cgol.c
dynCGOL.c

### Description:
This project is a console application written in the C programming language that replicates Conway's Game of Life.Conway's Game of Life, also known as the Game of Life or simply Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is the best-known example of a cellular automaton.

The "game" is actually a zero-player game, meaning that its evolution is determined by its initial state, needing no input from human players. One interacts with the Game of Life by creating an initial configuration and observing how it evolves.

### Rules:
The universe of the Game of Life is an infinite two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead. Every cell interacts with its eight neighbours, which are the cells that are directly horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

    1. Any live cell with fewer than two live neighbours dies (referred to as underpopulation or exposure[1]).
    2. Any live cell with more than three live neighbours dies (referred to as overpopulation or overcrowding).
    3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
    4. Any dead cell with exactly three live neighbours will come to life.

The initial pattern constitutes the 'seed' of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed — births and deaths happen simultaneously, and the discrete moment at which this happens is sometimes called a tick. (In other words, each generation is a pure function of the one before.) The rules continue to be applied repeatedly to create further generations.

### Program Usage:

## Command Line Arguments to Run dynCGOL:

# dynCGol Usage Format
make all
./dynCGOL file.seed verticalSize horizontalSize ticks

# dynCGOL Usage Example: 
    $ make all
    $ ./dynCGOL diehard20X40.seed 20 40 100

# Included Seed Files for dynCGOL (adjust verticalSize and horizontalSize parameters accordingly)
beacon6X6.seed
blinker5X5.seed
diehard10X20.seed
diehard20X40.seed
glider20X40.seed
gun20X40.seed
penta18X11.seed
pufferTrain20X40.seed
R-pentomino20X40.seed

## Command Line Arguments to Run cgol:

# cgol Usage Format
make all
./cgol file.seed

# cgol Usage Example: 
    $ make all
    $ ./dynCGOL diehard.seed

# Included Seed Files for cgol
diehard.seed
R-pentomino.seed
R-pentomino20X40.seed