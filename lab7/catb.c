/*
 * Alejandro Alvarado
 * CS35L
 * catb.c
 *
 * Description: 
 * Write a C program catb.c that 
 * uses getchar and putchar to copy
 * all the bytes in standard input to
 * standard output. This is roughly
 * equivalent to the cat command
 * with no arguments.
 */

#include <stdio.h>

int main() {
  
  int buffer; 
  while ( ( buffer = getchar() ) != EOF ) {
    putchar( buffer ); 
  }
  return 0; 

}
