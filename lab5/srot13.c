/*
  Alejandro Alvarado
  CS35L
  srot13.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE        1
#define FALSE       0
#define BUFFER_SIZE 1024 
#define ROTATE_BY   13


void quit_with_error();
int rot13cmp(const void* first, const void* second ); 
int rot_cmp_helper(int ASCII_char); 

int main(int argv, char** argc) {

  unsigned long long int size_of_buffer = BUFFER_SIZE;
  int file_is_empty = TRUE;
  int count = 0; 
  
  char* list = (char*) malloc(size_of_buffer * sizeof(char));
  if ( list == NULL) quit_with_error();
  
  while(TRUE) {
    int character = getc(stdin);

    if ( character == EOF) {
      if( list[count-1] != '\n')
	list[count++] = '\n';
      break; 
    }
    file_is_empty = FALSE;
    
    list[count++] = character;
    if ( count == size_of_buffer-1) {
      size_of_buffer = 2 * size_of_buffer; 
      list = (char*) realloc(list, size_of_buffer);
      if ( list == NULL) quit_with_error();
    } 
  }

  if ( file_is_empty) quit_with_error();

  int count_new_lines = 0;
  int i;
  for(i = 0; i < count; i++) {
      if ( list[i] == '\n') {
	count_new_lines++;
      }
  }

  /* Points to elements between newlines from list */
  char** list_pointers =(char**) malloc(count_new_lines * sizeof(char*));
  /* Contains all the lengths of each element in list_pointers */
  int* list_elem_lens = (int*) malloc(count_new_lines * sizeof(int));

  if (list_pointers == NULL || list_elem_lens == NULL)
    quit_with_error();


  int list_pointers_count = 0;
  char* temp_list = list;
  for( i = 0 ; i < count_new_lines; i++) {
    list_pointers[list_pointers_count++] = temp_list;

    while ( *temp_list != '\n') {
      temp_list++;
    }    
    temp_list++; 
  }
  
  temp_list = NULL;

  qsort(list_pointers, list_pointers_count, sizeof(char*), rot13cmp); 

  int length = 1; 
  int list_elem_lens_count = 0;   

  /* After the list is sorted, calculate the lengths */
  for ( i = 0; i < count_new_lines; i++) {
    temp_list = list_pointers[i];

    while ( *temp_list != '\n' ) {
      temp_list++;
      length++; 
    }
    list_elem_lens[list_elem_lens_count++] = length;
    length = 1; 
  }

  /* Print the sorted list to STDOUT */

  int j;
  for( i = 0; i < count_new_lines; i++) {
    char* str = (char*) list_pointers[i];

    for ( j = 0; j < list_elem_lens[i]; j++) {
      printf("%c", *str);
      str++; 
    }
  }
  
  free(list_pointers);
  free(list_elem_lens);
  free(list);

  return 0; 
}

void quit_with_error() {
  
  fprintf(stderr, "Error: Could not satisfy request");
  exit(1); 
}

int rot13cmp(const void* first, const void* second) {

  char* first_str = *(char**) first;
  char* second_str = *(char**) second;

  while (TRUE)
    {

      int first_ASCII  = (int) *first_str;
      int second_ASCII = (int) *second_str;
      
      if (first_ASCII == 10 && second_ASCII == 10)
	return 0;
      else if (first_ASCII == 10)
	return -1;
      else if (second_ASCII == 10)
	return 1;
     
      first_ASCII += rot_cmp_helper(first_ASCII);
      second_ASCII += rot_cmp_helper(second_ASCII); 

      long long int compare = first_ASCII - second_ASCII;
      if (compare != 0) return compare;
      
      first_str++;
      second_str++;
    }
}

int rot_cmp_helper(int ASCII_char) {
  
  if ((ASCII_char > 64 && ASCII_char < 78) || (ASCII_char > 96 && ASCII_char < 110))
    return ROTATE_BY;
  else if ((ASCII_char > 77 && ASCII_char < 91) || (ASCII_char > 109 && ASCII_char < 123))
    return -ROTATE_BY;
  else
    return 0; 
}

