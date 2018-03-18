#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
using namespace std; 
class bigint 
{ 
private: 
   vector<int> num; 
   int len; 
public: 
   bigint() 
   { 
      len = 0; 
      num.push_back(0); 
   } 
   
   bigint(int n) 
   { 
      num.erase(num.begin(), num.end()); 
      if (n != 0) 
      { 
         len = 1; 
         int temp = n; 
         while (temp /= 10) 
        	 len++; 
         for (int i = 0; i<len; i++) 
        	 num.push_back((int)(n / (int)pow(10.0, len - i - 1)) % 10); 
      } 
      else { 
         len = 0; 
         num.push_back(0); 
      } 
   } 
   
   bigint(string s) 
   { 
      len = s.length(); 
      num.erase(num.begin(), num.end()); 
      for (int i = 0; i<len; i++) 
     	 num.push_back(s.at(i) - 48); 
   } 
   
   bigint(const char* s) 
   : bigint(string(s)) // delegating constructors (since C++11) 
   { 
   } 
   
   bigint& operator= (const string s) 
   { 
      len = s.length(); 
      num.erase(num.begin(), num.end()); 
      for (int i = 0; i<len; i++) 
      num.push_back(s.at(i) - 48); 
      return *this; 
   } 
   
   bigint& operator= (const char* s) 
   { 
      return operator=(string(s)); 
   } 
   bigint& operator= (const bigint& b) 
   { 
      len = b.len; 
      num.erase(num.begin(), num.end()); 
      for (int i = 0; i<len; i++) 
      num.push_back(b.num.at(i)); 
      return *this; 
   } 
   friend ostream& operator<< (ostream& os, const bigint& b); 
   friend istream& operator>> (istream& is, bigint& b); 
}; 
ostream& operator<< (ostream& os, const bigint& b) 
{ 
   for (int i = 0; i<b.num.size(); i++) 
   os << b.num[i]; 
   return os; 
} 
istream& operator>> (istream& is, bigint& b) 
{ 
   string str; 
   is >> str; 
   b = str; 
   return is; 
} 
int main(void) 
{ 
   bigint a = "12345"; // bigint(const char* s) 
   bigint b = a; // bigint& operator= (const char* s) 
   bigint c = 789; // bigint(int n) 
   cout << a << endl << b << endl << c << endl; 
   return 0; 
} 
