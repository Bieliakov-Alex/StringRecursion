#include <iostream>
#include <conio.h>
#include <list>
#include <string.h>

using namespace std;

//void change(char* string, list<char*> lst);
void change(char* string, list<char*> *lst, int l);

int main()
{
	char string[101];
	cin >> string;
	//char string[101] = "xy";
	list<char*> lst;
	change(string, &lst,0);
	for (auto i = lst.begin(); i != lst.end(); i++)
	{
		cout << *i << endl;
	}

	_getch();
	return 0;
}

void change(char* string, list<char*> *lst, int l)
{
	if (strlen(string + l) == 2)
	{
		char* temp = new char[strlen(string) + 1];
		strcpy(temp, string);
		lst->push_back(temp);
		char* temp0 = new char[strlen(string) + 1];
		strcpy(temp0, string);
		char temp1 = *(temp0 + l);
		*(temp0 + l) = *(temp0 + l + 1);
		*(temp0 + l + 1) = temp1;
		lst->push_back(temp0);
	}
	else
	{
		change(string, lst, l + 1);
		for (int i = 1;i < strlen(string + l);i++)
		{
			char temp = string[l];
			string[l] = string[l + i];
			string[l + i] = temp;
			change(string, lst, l + 1);
		}
	}
}