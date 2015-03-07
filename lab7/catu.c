/*
 * Alejandro Alvarado
 * CS35L
 * catu.c
 *
 * Description: 
 * Write a C program catu.c that 
 * uses read and write to read 
 * and write each byte, instead 
 * of using getchar and putchar.
 * The nbyte arguments to read 
 * and write should be 1, so that
 * the program reads and writes 
 * single bytes at a time.
 */

#include <unistd.h>

int main() {
  
  char input;
  while ( read( 0, &input, 1) > 0 ) {
    write(1, &input, 1); 
  } 
  return 0; 

}
