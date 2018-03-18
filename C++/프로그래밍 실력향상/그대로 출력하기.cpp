#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int k = 0; 
    while(k < 100)
    {
        string a;
        getline(cin, a);
        cout<<a<<endl;
        k++;
    }
    return 0;
}
