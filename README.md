# malgster's Minesweeper

A classic minesweeper game entirely made in C

## game tutorial :

The objective of the game is to clear a grid containing hidden "mines" or bombs without detonating any of them, with help from clues about the number of neighboring mines printed in the empty cell.

* choose the number of bombs you want (0-64)
* choose the cell number by entering the lign's number (a-h) and the column's (0-7) at the same time (EX : a4, c7, d6...)

![](https://i.imgur.com/YEmFtrm.jpg)
![](https://i.imgur.com/NkBayhl.jpg)

## compile the game

Compiling's done through a makefile, just type the command <code>make</code> in your *linux* terminal

### note :

if you ever get a **Unknown command : make**, you need to install it :

<code>sudo apt-get install make</code>

it's also recommanded to install packages needed to build the code :

<code>sudo apt-get install build-essential</code>

## run the game :

the compiling will create an executable file called **MMS**, to execute it :

<code>./prog</code>