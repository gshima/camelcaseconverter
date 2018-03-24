

%{
#include <stdio.h>
#include <string.h>
#include "ccc_lib.h"

char output[50];

%}
%%
.*([a-z]+[_])+([a-z]+)([A-Z]+[a-z]+)+.* {
printf("ERRO");
}

.*([A-Z]+[a-z]+)+([_][a-z]+)+.* {
printf("ERRO");
}

[A-Z]+[a-z]+([A-Z]+[a-z]+)+[^_] { //encontra cadeias de CamelCase
  //printf("Encontrei a cadeia: %s\n", yytext);
  camelcase_to_underline(yytext, output);
  //printf("Converti a string: %s", output);
  printf("%s", output);
  clear_string(output);
}

([a-z]+_)+([a-z]+) { //encontra cadeias de underline
  //printf("Encontrei a cadeia: %s\n", yytext);
  underline_to_camelcase(yytext, output);
  //printf("Converti a string: %s", output);
  printf("%s", output);
  clear_string(output);
}

%%

int main() {
  yylex();
  return 0;
}
