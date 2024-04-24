#include "Password.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using std::string;
using std::vector;


Password::Password() {
    pass_history.push_back("ChicoCA-95929");
}
/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase) {
    if (phrase.empty()) {
        return 0;
    }
    int repetition = 1;
    int index = 0;
    while (index < phrase.length()-1 && phrase[index] == phrase[index+1]) {
        repetition++;
        index++;
    }
    return repetition;
}

// Implementation A
// #include <cctype>
// bool Password::has_mixed_case(string str)
// {
//   bool has_lower = false;
//   bool has_upper = false;
//   for (char ch : str)
//   {
//     if (std::islower(ch))
//     {
//       has_lower = true;
//     }
//     else if (std::isupper(ch))
//     {
//       has_upper = true;
//     }
//   }
//   return has_lower && has_upper;
// }
// Implementation B
// bool Password::has_mixed_case(string str)
// {
//   int count_lower = 0;
//   for (int i = 0; i < str.length(); i++)
//   {
//     if (str[i] >= 'a' && str[i] <= 'z')
//     {
//       count_lower++;
//     }
//   }
//   return count_lower > 0 && count_lower < str.length();
// }
// Implementation C
// bool Password::has_mixed_case(string str)
// {
//   bool lower = false;
//   bool upper = false;
//   for (int i = 0; i < str.length(); i++)
//   {
//     if (str[i] >= 'a' && str[i] <= 'z')
//     {
//       lower = true;
//     }
//     else if (str[i] >= 'A' && str[i] <= 'Z')
//     {
//       upper = true;
//     }
//   }
//   return upper && lower;
// }
// Implementation D
// #include <cctype>
// bool Password::has_mixed_case(string str)
// {
//   bool is_lower = false;
//   bool is_upper = false;
//   for (char c : str)
//   {
//     if (std::islower(c))
//     {
//       is_lower = true;
//     }
//     else
//     {
//       is_upper = true;
//     }
//   }
//   return is_lower && is_upper;
// }
// Implementation E
bool Password::has_mixed_case(string str)
{
  bool found = false;
  for(char c : str){
    if( !found && c >= 'A' && c <= 'Z' ){
      found = true;
    }
    else if( found && c >= 'a' && c <= 'z'){
      return true;
    }
  }
  return false;
}

void Password::set(string new_password) {
    if (new_password.length() < 8 || new_password.length() > 20)
        return;
  
    if (count_leading_characters(new_password) > 3)
        return;
  
    if (!has_mixed_case(new_password))
        return;
  
    if (std::find(pass_history.begin(), pass_history.end(), new_password) != pass_history.end())
        return;
  
    pass_history.push_back(new_password);
}

bool Password::authenticate(string test_password) {
    if (pass_history.empty())
        return false;
  
    return test_password == pass_history.back();
}