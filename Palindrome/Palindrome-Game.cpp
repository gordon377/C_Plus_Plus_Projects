//Palindrome Game
//Gordon Chen
//September 19th, 2023


#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  int str_len = 81; //circumvent this? take as user input? | 81 due tot he automated null character addded at the end

  char str_preprocess[str_len];
  char str_postprocess[str_len];

  
  cout << "Give a word/phrase to check if it's a palindrome! (Max 80 characters)" << endl;
  cin.get(str_preprocess, 80);

  //strcpy(str_preprocess, raw_str_input); 

  //cout << str_preprocess << endl << str_len;


  int k = 0;
  int p = 0;
  
  str_len = strlen(str_preprocess); 
  for (int i = 0; i < str_len + 1; i++){ //strlen() vs. str.size()?   
    if (ispunct(str_preprocess[i]) == false && str_preprocess[i] != ' '){ //checks character is not punctation or white space (should leave alphanumerics)
      
      str_postprocess[k] = tolower(str_preprocess[i]); //makes lower case
      //cout << str_postprocess[k] << endl;
      k++;
      
    }
    
  }
  
  //cout << "Post Proccess Array: " << strlen(str_postprocess) << endl;

  char str_BW[k];
  k--;
  for (k > -1; k--;){ //reverses array
    str_BW[p] = str_postprocess[k];
    p++;
  }

  str_BW[p] = '\0'; //adds null character to end of array

  //cout << str_BW << endl;

  if(strcmp(str_postprocess, str_BW) == 0){ //check if palindrome
    cout << "This is a palindrome! (excluding punctation and spaces)" << endl;
  }
  else{
    cout << "This is not a palindrome!" << endl;
  }

    
  return 0;

}
