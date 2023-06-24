#include <stdio.h>
#include <string.h>

char * entirestring;
void RecursivePermute(char * str[], int k){

  if(k == 0) {
  printf("%s\n", entirestring);
    return;
  }
  else{
    int r = 0;
    while(r < k){

    ExchangeCharacters(str[0], str[r]);
    RecursivePermute(str+1, k - 1);
      ExchangeCharacters(str[0], str[r]);
      r++;
    }
    
    
  
}

