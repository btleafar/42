# 42 School Silicon Valley

## ft_db

The goal of this project was to learn about databases.

### What is a database?

A database is an organized collection of data, a collection of of schemas,
tables, queries, reports, views, and other objects. They offer an organized
mechanism for storing, managing and retrieving information.
They do so through the use of tables.

### Why not just use a piece of paper or the file system?

Because database can store a very large numbers of records efficiently, as they
take up little space. It's also very easy and quick to find information, and to
add new data and to edit or delete old data. Also, security may be better than
in a piece of paper. :)

### ft_db specifications

* Our program relates closely to a DBSM, because it allows users to interact
with one or more databases and provides access to all of the data contained
in the database.
* We can create, read, update, and delete data from a database.
We use records to find the information fast and easy.
* Currently, a database can store integers, floats, and strings.
* We could have done a lot of things to make the DBSM better, but the list is
too long to write :(

## Getting Started

### Compiling

Run the following commands:

* To compile
	- `make`
* To remove objects:
	- `make clean`
* To remove objects and binary file (program):
	- `make fclean`
* To re-compile:
	- `make re`

### Executing

To execute the program:

`./ft_db <arguments> <database.db> <record(s)>`

*See help message to see how this works! :D*

#### Try it!

Try running the following:

`./ft_db -c new_dabase.db`

## Screenshots

**Usage message, help message and program running:**

<img src="resources/ftdb-screenshot01.png" width="550" />
