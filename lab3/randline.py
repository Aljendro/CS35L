#!/usr/local/cs/bin/python3

"""
Output lines selected randomly from a file

Copyright 2005, 2007 Paul Eggert.
Copyright 2010 Darrell Benjamin Carbajal.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Please see <http://www.gnu.org/licenses/> for a copy of the license.

$Id: randline.py,v 1.4 2010/04/05 20:04:43 eggert Exp $

Modified by: Alejandro Alvarado

-Added option -u (unique)
--The list of available lines would be unique
-Added option -w (without-replacement)
--The line would not be output more than once
--unless there were multiple lines that were
--identical
-Added several error handling try block and 
--if statements
-Changed the algorithm to take the lines from
--a list rather than straight from a file
"""

import random, sys
from optparse import OptionParser

def main():
    version_msg = "%prog 2.0"
    usage_msg = """%prog [OPTION]... FILE

Output randomly selected lines from FILE."""

    parser = OptionParser(version=version_msg,
                          usage=usage_msg)
    parser.add_option("-n", "--numlines",
                      action="store", dest="numlines", default=1,
                      help="output NUMLINES lines (default 1)")

    parser.add_option("-u", "--unique", 
                      action="store_true", dest="unique", default=False,
                      help="only uses a unique set of lines from files")

    parser.add_option("-w", "--without-replacement)",
                      action="store_true", dest="without_replacement", 
                      default=False,
                      help="does not output the same line more than once")

    options, args = parser.parse_args(sys.argv[1:])

    try:
        numlines = int(options.numlines)
    except:
        parser.error("invalid NUMLINES: {0}".
                     format(options.numlines))
    if numlines < 0:
        parser.error("negative count: {0}".
                     format(numlines))
    
    line_list = []
    
    try:
        for file in args:
            with open(file) as infile:
                for line in infile:
                    if not line.endswith('\n'):
                        line = line + '\n'
                    line_list.append(line)
    except IOError:
        print("A file does not exist, exiting")
        sys.exit()
                    
    if options.unique:
        line_list = list(set(line_list))

    if (options.without_replacement and (numlines > len(line_list))):
        print("The amount of wanted lines exceeds the supply, exiting")
        sys.exit()

    try:
        for index in range(numlines):
            random_line = random.choice(line_list)

            if options.without_replacement:
                line_list.remove(random_line)

            sys.stdout.write(random_line)
    except IndexError:
        print("The files contained no lines, exiting...")

if __name__ == "__main__":
    main()
