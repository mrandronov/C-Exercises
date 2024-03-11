# Implement Table of Contents Parser

- [Problem Example](#problem-example)
- [Constraints](#constraints)
- [Building](#building)
- [Execution](#execution)

This code exercise implements a parser in C for taking a set of input text that contains markup syntax for denoting headings and converts them to a table of contents.

Most markdown document viewers should include a feature for this kind of input.

## Problem Example

The code should be able to take the following:
```
# First Chapter
Lorem Ipsum dolor sit amit
## First Section
Here is some info for the first section
## Second Section
This is info for the second section
# Second Chapter
## Another section
Here is more text
```
And convert it to this:
```
1. First Chapter
1.1. First Section
1.2. Second Section
2. Second Chapter
2.1. Another section
```

### Constraints

There are only two real constraints to this problem:

1. There shall always be a space in between the markdown heading syntax ( i.e, the '#'s ) and the actual heading text.
2. Heading numbers are always followed by a '.'.
3. The number of sections will be within `INT_MAX`.
4. The size of a line of text will be less than 1024 bytes worth of characters.

And that's it!

## Building

Simply run make:

```
make
```

## Execution

To run the program, build it and supply an argument for a file containing the input text. 

```
./main /path/to/input_text.txt
```

> Note: Make sure the first line of the input text file contains the number of lines to read to be parsed into a table of contents.

For example, the contents of 'sample_text.txt' should be the following in order for the program to generate a table of contents:
```
9
# First Chapter
Lorem Ipsum dolor sit amit
## First Section
Here is some info for the first section
## Second Section
This is info for the second section
# Second Chapter
## Another section
Here is more text
```
A number smaller than the number of lines can be supplied, if you wish to limit the number of lines converted to a table of contents.



