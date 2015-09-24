/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

#include <string>
#include <iostream>
#include <stdlib.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Solution {
public:
    int myAtoi(string str) {
        int size = str.size();
        int result = 0;
        int multi = 1;
        bool ifStart = false;
        bool ifMinus = false;
        bool ifOverflow = false;

        //purify
        if(size == 0){
        	return 0;
        } else{
        	for(int i = 0; i != size; i ++){
        		if(!ifStart){
        			if(str[i] == ' '){
        				continue;
        			} else if((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'){
        				ifStart = true;
        			} else{
        				return 0;
        			}
        		} else{
        			if(str[i] >= '0' && str[i] <= '9'){
        				continue;
        			} else{
        				size = i;
        				break;
        			}
        		}
        	}
        }
        
        for(int i = size - 1; i != -1; i --){
        	if(str[i] >= '0' && str[i] <= '9'){
        		result += (str[i] - '0') * multi;
        		multi = multi * 10;
        	} else if(str[i] == '-'){
        		result = 0 - result;
        		ifMinus = true;
        	} else if(str[i] == '+'){
        		///*nothing to do
        	} else if(str[i] == ' '){
        		continue;
        	} else{
        		return 0;
        	}

        	if(i == size - 10 && ((str[i] > '2' && str[i] <= '9') || (result < 0 && !ifMinus))){
        		ifOverflow = true;
        		cout << str[i] << endl;
        	} else if(i == size - 11 && str[i] <= '9' && str[i] >= '0'){
        		ifOverflow = true;
        		cout << "2" << endl;
        	}
        }


        
        if(!ifMinus){
        	if(ifOverflow){
        		return 2147483647;
        	}
        } else{
        	if(ifOverflow || result > 0){
        		return -2147483648;
        	}
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution test;
	string str;
	cout << "input the string to change" << endl;
	cin >> str;
	int result = test.myAtoi(str);
	cout << result << endl;
	return 0;
}
