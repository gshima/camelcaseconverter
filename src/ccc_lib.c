
#include "ccc_lib.h"
#include <string.h>

void camelcase_to_underline(char *input, char *output) {
  int i = 0, j = 0;
  while (input[i] != '\0'){
      if( 64 < input[i] && input[i] < 91 ) { // Pela tabela ASCII: A=65, Z=90, a=97,z=122
        output[j] = input[i] + 32; // transforma em lowcase
        j++;
        if(64 < input[i+1] && input[i+1] < 91) {
          output[j] = '_';
          j++;
        }
      i++;
    }
    else {
      output[j] = input[i];
      j++;
      if(64 < input[i+1] && input[i+1] < 91) {
        output[j] = '_';
        j++;
      }
      i++;
    }
  }
  return;
}

void underline_to_camelcase(char *input, char *output) {
  int i = 1, j = 1;
  output[0] = input[0] - 32;
  while (input[i] != '\0') {
    if(input[i] == '_') {
      i++;
      output[j] = input[i] - 32 ; //transforma em uppercase
      j++;
      i++;
    }
    else {
      output[j] = input[i];
      j++;
      i++;
    }
  }
  return;
}

void clear_string(char *string) {
  int i =0;
  while (string[i] != '\0') {
    string[i] = 0;
    i++;
  }
}
