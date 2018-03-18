#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int num;
	cin>>num;
	
	string *str_arr = new string [num];
	string *val_arr = new string [num]; 
	
	for(int i=0; i<num; i++) {
		cin>>str_arr[i];
		val_arr[i] = "";
	}
	
	int chk_zero = 0;
	
	for(int i=0; i<num; i++) {
		for(int j=0; j<str_arr[i].length(); j++) {
			if(str_arr[i][j] == 48){
				if(j > 0 && chk_zero) val_arr[i].push_back(str_arr[i][j]);
			}else if(str_arr[i][j] >= 49 && str_arr[i][j] <= 57) {
				val_arr[i].push_back(str_arr[i][j]);
				chk_zero = 1;
			}else if(str_arr[i][j] >= 97 && str_arr[i][j] <= 122) chk_zero = 0;
		}
	}
	
	for(int i=0; i<num; i++) cout<<val_arr[i]<<endl;
	
	return 0;
}
