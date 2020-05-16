#include <iostream>
#include <string>
using namespace std;

int main()
{
	string bin_string = "100";
	int number =0;

	number = stoi(bin_string, 0, 2);
	cout<<"bin_string: "<<bin_string<<endl;
	cout<<"number: "<<number<<endl;

	bin_string = "011";
	number = stoi(bin_string, 0, 2);
	cout<<"bin_string: "<<bin_string<<endl;
	cout<<"number: "<<number<<endl;

	return 0;
}
