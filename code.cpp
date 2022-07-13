/*
Conditions that must be TRUE for a card to be valid 
	--- length must be b/w 13 and 16
	--- 4 for Visa cards
	--- 5 for Master cards
	--- 37 for American Express cards
	--- 6 for Discover cards
*/

#include <bits/stdc++.h>
#include <string>
using namespace std;

int cn=0;//stores the prefix of card to get the name of the card

void cname(int n){
	switch(n){
		case 4:
			cout<<"a VISA card"<<endl;
			break;
		case 5:
			cout<<"a MASTER card"<<endl;
			break;
		case 37:
			cout<<"an AMERICAN EXPRESS card"<<endl;
			break;
		case 6:
			cout<<"a DISCOVER card"<<endl;
			break;
		default:
			break;
		}	
}

int size(long long int num){//gives number of digits in 'num'
	string cnum = to_string(num);
	return cnum.length();
}

bool matchPrefix(long long int num, int k){//checks if initial digits matches the desirable digit/number i.e 'k'
	int sz = (to_string(k)).length();//number of digits in 'k'
	if(size(num) > sz){
		string cnum = to_string(num);
		long long int n = stol(cnum.substr(0, sz));//getting initial 'k' digits as substring 
		cn = n;//stores the prefix for future use 
		return n==k;
	}
	return false; 
}

int evenPlace(long long int num){//gets sum of digits in second/even places 
	string cnum = to_string(num);
	int sum = 0;
	for(int i = size(num) - 2; i>=0; i-=2){
		int temp = (cnum[i] - '0') * 2;
		if( temp > 9) sum +=  temp/ 10 + temp % 10; //if number is a 2 digit number -> get sum of both digits and use that 
		else sum += temp;
	}
	return sum;
}

int oddPlace(long long int num){//gets sum of digits in odd places 
	string cnum = to_string(num);
	int sum = 0;
	for(int i = size(num) - 1; i>=0; i-=2){
		int temp = cnum[i] - '0';
		sum += temp;
	}
	return sum;	
}

bool validCard(long long int num){
	if(size(num)>=13 && size(num)<=16){//card number in valid range 
		if(matchPrefix(num, 4) || matchPrefix(num, 5) || matchPrefix(num, 37) || matchPrefix(num, 6)){//checks if card number matches any of the prefixes 
			int sum = evenPlace(num) + oddPlace(num); //Luhn's Algorithm 
			if(sum % 10 ==0 )return true;
		}
	}
	return false;
}

int main(void){
	long long int num;
	cout<<"Hi User\n\nEnter your Credit Card number - ";
	cin>>num;
	if(validCard(num)){
		cout<<endl<<"Your card is valid and is ";
		cname(cn);
		cout<<endl;
	}
	else cout<<"Sorry! Your card is invalid!"<<endl;
}
