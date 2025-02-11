#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
string square(int& h)
{
	string content = "";
	for(int i = 0; i<h; i++)
	{
		for(int j = 0; j<h; j++)
		{
			content += "* ";
		}
		content += "\n";
	}
	return content;
}
string rectangle(int& w,int& h)
{
	string content = "";
	for(int i = 0; i<h; i++)
	{
		for(int j = 0; j<w; j++)
		{
			content += "* ";
		}
		content += "\n";
	}
	return content;
}
string triangle(int& h)
{
	string content = "";
	for(int i = 1; i<=h; i++)
	{
		for(int j = 1; j<=i; j++)
		{
			content += "* ";
		}
		content += "\n";
	}
	content += "\n";
	for(int i = 1; i<=h; i++)
	{
		for(int j = 1; j<=h-i; j++)
		{
			content += "  ";
		}
		for(int j = 1; j<=2*i-1; j++)
		{
			content += "* ";
		}
		content += "\n";
	}
	content += "\n";
	for(int i = h; i>0; i--)
	{
		for(int j = 1; j<=h-i; j++)
		{
			content += "  ";
		}
		for(int j = 1; j<=2*i-1; j++)
		{
			content += "* ";
		}
		content += "\n";
	}
	return content;
}
string diamond(int& h)
{
	string content = "";
	for(int i = 1; i<=h; i++)
	{
		for(int j = 1; j<=h-i; j++)
		{
			content += "  ";
		}
		for(int j = 1; j<=2*i-1; j++)
		{
			content += "* ";
		}
		content += "\n";
	}
	for(int i = h-1; i>0; i--)
	{
		for(int j = 1; j<=h-i; j++)
		{
			content += "  ";
		}
		for(int j = 1; j<=2*i-1; j++)
		{
			content += "* ";
		}
		content += "\n";
	}
	return content;
}
string parallelogram(int& h)
{
	string content = "";
	for(int i = 1; i<=h; i++)
	{
		for(int j = 1; j<=h-i; j++)
		{
			content += "  ";
		}
		for(int j = 1; j<=2*h; j++)
		{
			content += "* ";
		}
		content += "\n";
	}
	return content;
}
string trapezoid(int& h)
{
	string content = "";	
	for(int i = 5; i<=h; i++)
	{
		for(int j = 1; j<=h-i; j++)
		{
			content += "  ";
		}
		for(int j = 1; j<=2*i; j++)
		{
			content += "* ";
		}
		content += "\n";
	}
	return content; 
}
int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int w, h, color;
	char shape;
	start:
	SetConsoleTextAttribute(hConsole, 1);
	cout<<"s: Square"<<endl;
	Sleep(400);
	SetConsoleTextAttribute(hConsole, 2);
	cout<<"r: Rectangle"<<endl;
	Sleep(400);
	SetConsoleTextAttribute(hConsole, 3);
	cout<<"t: Triangle"<<endl;
	Sleep(400);
	SetConsoleTextAttribute(hConsole, 8);
	cout<<"d: Diamond"<<endl;
	Sleep(400);
	SetConsoleTextAttribute(hConsole, 6);
	cout<<"p: Parallelogram"<<endl;
	Sleep(400);
	SetConsoleTextAttribute(hConsole, 11);
	cout<<"z: Trapezoid"<<endl;
	Sleep(400);
	SetConsoleTextAttribute(hConsole, 4);
	cout<<"Please enter your choice: ";
	SetConsoleTextAttribute(hConsole, 7);
	cin>>shape;
	for(int i = 1; i<=15; i++)
	{
		SetConsoleTextAttribute(hConsole, i);
		cout<<i<<"- "<<"Color\n";
		Sleep(200);
	}
	SetConsoleTextAttribute(hConsole, 4);
	cout<<"Please choice your color: ";
	cin>>color;
	cout<<"\n";
	SetConsoleTextAttribute(hConsole, color);
	switch(shape)
	{	
		case 'r':
			cout<<"Width: ";
			cin>>w;
			cout<<"Height: ";
			cin>>h;	
			break;
		default:
			cout<<"Height: ";
			cin>>h;	
	}
	cout<<"\n\n";	
	switch(shape)
	{
		case 's':
			cout<<square(h);
			break;
		case 'r':
			cout<<rectangle(w,h);
			break;
		case 't':
			cout<<triangle(h);	
			break;
		case 'd':
			cout<<diamond(h);
			break;
		case 'p':
			cout<<parallelogram(h);
			break;
		case 'z':
			cout<<trapezoid(h);
			break;	
	}
	SetConsoleTextAttribute(hConsole, 7);
	lable:
	cout<<"\n\nPress r to return to main menu";
	cout<<"\n\nPress x to exit the program\n";
	char ch = getch();
	if(ch=='r')
	{
		system("cls");
		goto start;
	}
	else if(ch=='x')
		exit(0);
	else
	{
		cout<<"\nInvalid !";
		goto lable;	
	}			
}
