// Array Operations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void curarray(int[], int);
void printarr(int[], int);
void valuefinder(int[], int, int);
void insert(int [], int , int , int );
void del(int[], int&, int);
void reve(int [], int );
void Swap(int [], int , int , int );
void repl(int [], int , int , int );
int main()
{
	const int size = 20;
	int ar[size], cursize;
	cout << "Enter the Number of Elements : ";
	cin >> cursize;
	while (cursize < 1 || cursize>20)
	{
		cout << "*****The Current Size should be 1-20*****" << endl;
		cout << "Enter the Number of Elements again  : ";
		cin >> cursize;
	}
	curarray(ar, cursize);
	cout << endl;
	cout << "            *****Array Operations*****" << endl;
	cout << endl;
	cout << "   To Insert enter     I / i" << endl;
	cout << "   To Delete enter     D / d" << endl;
	cout << "   To Find enter       F / f" << endl;
	cout << "   To Replace enter    R / r" << endl;
	cout << "   To Swap enter       S / s" << endl;
	cout << "   To Reverse enter    V / v" << endl;
	cout << "   To Print enter      P / p" << endl;
	cout << "   To Quit enter       Q / q" << endl;
	cout << endl;
	char choice;
	cout << "To Enter your choice :";
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 'I':
		case 'i':
			int insrtind, value;
			if (size != cursize)
			{
				cout << "Enter the Position where you want to Insert : ";
				cin >> insrtind;
				while (insrtind<0 || insrtind>cursize)
				{
					cout << "***** The Insert Position should be between 0 and " << cursize << " *****" << endl;
					cout << "Enter the Position again where you want to Insert : ";
					cin >> insrtind;

				}
				cout << "Enter the value which you want to insert : ";
				cin >> value;
				insert(ar, cursize, insrtind, value);
				cursize++;
			}
			else
			{
				cout << "*****You can not insert any value because array is full*****" << endl;
			}
			break;
		case 'D':
		case 'd':
			int valu;
			cout << "Enter the Value Which you want to delete : ";
			cin >> valu;
			del(ar, cursize, valu);
			break;
		case 'F':
		case 'f':
			int val;
			cout << "Enter the Value which you want to search : ";
			cin >> val;
			valuefinder(ar, val, cursize);
			break;
		case 'v':
		case 'V':
			reve(ar, cursize);
			break;
		case's':
		case 'S':
			int val1, val2;
			cout << "Enter the first Value : ";
			cin >> val1;
			cout << "Enter the Second Value : ";
			cin >> val2;
			Swap(ar, cursize, val1, val2);
			break;
		case 'R':
		case 'r':
			int val3, val4;
			cout << "Enter the value of Array which you want to replace : ";
			cin >> val3;
			cout << "Enter the value of  with which you want to replace : ";
			cin >> val4;
			repl(ar, cursize, val3, val4);
			break;
		case 'P':
		case 'p':
			printarr(ar, cursize);
			break;

        }
		cout << endl;
		cout << "            *****Array Operations*****" << endl;
		cout << endl;
		cout << "   To Insert enter     I / i" << endl;
		cout << "   To Delete enter     D / d" << endl;
		cout << "   To Find enter       F / f" << endl;
		cout << "   To Replace enter    R / r" << endl;
		cout << "   To Swap enter       S / s" << endl;
		cout << "   To Reverse enter    V / v" << endl;
		cout << "   To Print enter      P / p" << endl;
		cout << "   To Quit enter       Q / q" << endl;
		cout << endl;
		cout << "To Enter your choice :";
		cin >> choice;

	} while (choice!='q' && choice!='Q');
	
	
}
void curarray(int arr[], int noofelem)
{
	int index;
	for (index = 0; index < noofelem; index++)
	{
		cout << "Enter the Number index [" << index << "] : ";
		cin >> arr[index];
	}

}
void printarr(int arr[], int noofelem)
{
	cout << "The Array is = {";
	for (int index = 0; index < noofelem; index++)
	{
		if ((noofelem - 1) > index)
		{
			cout << arr[index] << ",";
		}
		else
		{
			cout << arr[index];
		}

	}
	cout << "}" << endl;
}

void valuefinder(int arr[], int value, int noofelem)
{
	int index, pos = 0,occ=0;
	for (index = 0; index < noofelem; index++)
	{
		if (value == arr[index])
		{
			cout << "The Value exist in the array at index [" << index << "]" << endl;
			occ++;
			pos = 1;
		}

	}
	cout << "The Number of occurances are " << occ << endl;
	if (pos == 0)
	{
		cout << "The Value  does not exist in the array" << endl;
	}
}
void insert(int arr[], int size, int pos, int val)
{
	for (int index = size; index > pos; index--)
	{
		arr[index] = arr[index - 1];
	}
	arr[pos] = val;
}
void del(int arr[], int &size, int val)
{
	int insrtind;
	int cond = 0;
	for (insrtind = 0; insrtind < size; insrtind++)
	{
		if (val == arr[insrtind])
		{
			for (int index = insrtind; index < size; index++)
			{
				arr[index] = arr[index + 1];

			}
			size--;
			cond = 1;
		}
	}
	if (cond == 0)
	{
		cout << "The Value  does not exist in the array" << endl;
	}
}
void reve(int  arr[], int size)
{
	int index, j = 0;
	for (index = (size - 1); index >= (size / 2); index--)
	{
		int temp;
		temp = arr[index];
		arr[index] = arr[j];
		arr[j] = temp;
		j++;
	}
}
void Swap(int arr[], int size, int value, int value1)
{
	int index,j = 0, t = 0, pos = 0, spos = 0;
	for (index = 0; index < size; index++)
	{
		if (value == arr[index])
		{
			j = index;
			pos = 1;
			break;
		}
		else
		{
			pos = -1;
		}
	}
	for (index = 0; index < size; index++)
	{
		if (value1 == arr[index])
		{
			t = index;
			spos = 1;
			break;
		}
		else
		{
			spos = -1;
		}
	}
	if (pos == spos)
	{
		int temp;
		temp = arr[j];
		arr[j] = arr[t];
		arr[t] = temp;
	}
	else
	{
		cout << "***** You can not swap because for swapping both values found in the array *****" << endl;
	}
}
void repl(int arr[], int size, int vala, int valr)
{
	int j = 0, pos = 0;
	int index;
	for (index = 0; index < size; index++)
	{
		if (vala == arr[index])
		{
			j = index;
			pos = 1;
			break;
		}
		else
		{
			pos = -1;
		}
	}
	if (pos == 1)
	{
		arr[j] = valr;
	}
	else
		cout << "***** You cant Replace because value is not found in the array *****" << endl;

}
