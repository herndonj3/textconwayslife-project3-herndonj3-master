# ASCII Implementation of Conway's Life, Project 3

## An EVEN More Dynamic John Conway's *Life* Cellular Automata

In project 2, you expanded our Conway Life simulation so that the board could be dynamically resized.  That was a kind of data structure dynamics.  In this project, we're going to make the project even more flexible by allowing the user to specify different kinds of rules.  Even better, our variation will easily allow future programmers to expand our work to add more rules.  Additionally, we'll be moving our "Initialize" functionality into proper constructors, as well as making sure there are appropriate destructors.

Recall that John Conway was a mathematician who constructed one of the first 2D *cellular automata* (CA).  Imagine a large 2D field of cells, where each cell might be alive (filled in) or dead (empty).  Each time step, this field of cells changes based on a few simple rules.  In Conway's Life,
the **Standard Rule** was as follows:

1. If a cell is alive and has fewer than 2 immediate neighbors, it has insufficient support and dies.
2. If a cell is alive and has more than 3 immediate neighbors, it suffocates and dies.
3. If a cell is dead and has precisely 3 immediate neighbors, it is reborn!

Typically these rules are applied to some initial field of cells (called a "seed"), then the rules are applied to produce a new field that replaces the old field, etc.  Though the rules are very simple, a shocking amount of complexity arises from the use of different seeds, and a lot of math has been proven about it.  For instance, given a sufficiently large field and the right seeds, you can actually encode the circuitry of a general computer into Life (that is, it is capable of *universal computation*).

But there are other rules!  And these lead to different kinds of behaviors.  In general, this kind of machine is called a *two dimensional cellular automata* (CA).  The *standard rule* for Conway Life is just one kind of 2D CA.  

You can read more about [Conway's Life CA here](https://www.conwaylife.com/).

## Other Rules

There are many different rules for CAs.  We're going to consider a subset of these that can be described by the current state of the cell and count of the live von Neumann neighbors (the 8 immediately adjacent cells that we've been considering).  The *standard rule* can be annotated "S23/B3", meaning a live cell remains alive with 2 or 3 live neighbors, a dead cell becomes alive with precisely 3 live neighbors, otherwise death.  Another rule is the so-called "Exploding" rule (S34/B34).  And there are many more.  [Here's a small list](http://psoup.math.wisc.edu/mcell/rullex_life.html).

In this project, I've given the standard rule for you.  You need to implement at least two more rules, and the "Exploding" rule has to be one of them.  Choose the other for yourself!

## ASCII Art and the ncurses Library

This implementation avoids having to deal with graphics entirely by displaying the CA on a terminal screen in ASCII.  It does this using the [standard Unix library ncurses](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/intro.html).  The program treats the CA as *tauroidal*, meaning the board wraps around both left-to-right and top-to-bottom (the grid is basically in a doughnut shape), just like scrolling games.


## The Code

There is one executable program built by the Makefile in this source:

* **SimulationMain** -- the main program for running Conway's Life CA.

There are several source files:

* **Rule.h** -- The header for the abstract class representing a rule for the CA.
* **StandardRule.h** -- The header for the rule representing the standard rule for Conway's Life.
* **StandardRule.cc** -- The body implementing the standard rule.  This is a good prototype for the rules you have to implement.
* **TwoDCharArray.h** -- The header for the dynamically sized, 2D character array.
* **TwoDCharArray.cc** -- This body source implements the dynamically sized, 2D character array.
* **BoardVisualizer.h** -- The header for for the class that warps around the *ncurses* library to visualize characters on the screen.
* **BoardVisualizer.cc** -- This body source that implements a simple wrapper around ncurses to visualize a TwoDCharArray on the screen.
* **ConwayLife.h** -- The header for for the simulation.
* **ConwayLife.cc** -- The body implementing the simulation
* **SimulationMain.cc** -- The main file for the 2D simulation. This now queries the user for many things, including which rule they want to use.
* **doxygen.cfg** -- The configuration file for the Doxygen documentation generation tool


## Where to Start

I assume you have mastered Project 2, and so you understand the code at a high level.  In Project three, you must accomplish the following extensions to the program:

* Move *all* functionality in the *Initialize()* methods of ConwayLife and TwoDCharArray into constructors
* Make sure there are proper destructors for those classes so that there are no memory leaks.  There are comments in the code to help prompt you about these.
* Write at least *two more* classes implementing different CA rules for our simulation.  One must be the *Exploding* rule mentioned above, the other is your choice.  Make sure they can be selected by the user.

## Coding Standards
Use good naming conventions for variables, functions, and classes.  Ideally, I suggest sticking with [Google's C++ Style](https://google.github.io/styleguide/cppguide.html).
