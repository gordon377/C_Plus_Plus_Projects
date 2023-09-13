//playground for coding experimentation

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  int str_len = 20;
  char str[str_len]; //technically an array of chars (length is a taken parameter)
  char str2[str_len];

  cin.get(str,20);
  cin.get(); //to get rid of the return character at the end
  cin.get(str2, 20);
  cin.get();
  if (strcpy(str, str2) == 0) {  //copy string
    
  }
  

  return 0;
}
