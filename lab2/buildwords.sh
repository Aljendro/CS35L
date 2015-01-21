#!/bin/sh

#The purpose of this script is to read a file
#from STDIN and write to STDOUT.

#The file that it will read will be an HTML
#file that contains ENGLISH words with
#HAWAIIAN translations

#The script will write a unique sorted list of
#Hawaiian words to output

#Specifications:
#-Hawaiian words only contain
#  - p, k, `, m, n, w, l, h, a, e, i, o, u
#-Treat underlined <u>...</u> as if they
#were not underlined
#-Treat capital letters as if they were not
#captilized
#-Any words with spaces or commas are to be
#treated as multiple words
#-Any words with letters NOT in the above
#list should be rejected

sed '/<!DOCTYPE/,/<td>[aA]/d' |
sed '/<\/table>/,/<\/html>/d' | 
sed 's/<\/*u>//g' | 
sed '/<tr>/,/<\/td>/d' | 
sed 's/<\/tr>//g' | 
sed '/^[[:space:]]*$/d' | 
sed 's/^[[:space:]]*//g' | 
sed 's/<td>\(.*\)<\/td>/\1/g' | 
sed '/^[[:space:]]*$/d' | 
tr '[:upper:]' '[:lower:]' | 
tr ',' ' ' | 
tr ' ' '\n' | 
sed '/^[[:space:]]*$/d' | 
tr -d '' |  
sed 's/.*[^pkm`'"'"'nwlhaeiou].*//g' | 
sed '/^[[:space:]]*$/d' |
sed 's/`/'"'"'/g' |
sort -u
