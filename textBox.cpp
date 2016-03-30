#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <string>


using namespace std;

class textBox {

private: int length;
private: string text;
public:
	void setLength(int _length) {
		length = _length;
	}

	void setText(string _text) {
		text = _text;
	}

	string getText() {
		return text;
	}



	textBox(int length, int positionX, int positionY) {

		COORD c0 = { positionX, positionY };
		HANDLE h0 = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleCursorPosition(h0, c0);

		//set cursor size and visibility example

		CONSOLE_CURSOR_INFO cci0 = { 2000, FALSE };
		SetConsoleCursorInfo(h0, &cci0);

		//set foreground color

		DWORD wAttr = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
		SetConsoleTextAttribute(h0, wAttr);


		cout << "\xC9";
		for (int i = 0; i < length; i++) {
			cout << "\xCD";
		}

		cout << "\xBB" << endl;
		COORD c = { positionX, positionY+1};
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleCursorPosition(h, c);

		//set cursor size and visibility example

		CONSOLE_CURSOR_INFO cci = { 2000, FALSE };
		SetConsoleCursorInfo(h, &cci);

	
		cout << "\xBA";

		COORD c2 = { positionX+length+1, positionY+1 };
		HANDLE h2 = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleCursorPosition(h2, c2);

		//set cursor size and visibility example

		CONSOLE_CURSOR_INFO cci2 = { 2000, FALSE };
		SetConsoleCursorInfo(h2, &cci2);

		cout << "\xBA" << endl;


		COORD c3 = { positionX, positionY+2 };
		HANDLE h3 = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleCursorPosition(h3, c3);

		//set cursor size and visibility example

		CONSOLE_CURSOR_INFO cci3 = { 2000, FALSE };
		SetConsoleCursorInfo(h3, &cci3);

		cout << "\xC8";


		for (int i = 0; i < length; i++) {
			cout << "\xCD";
		}

		cout << "\xBC";
	}


};


void main2() {

	//set cursor position example

	COORD c = { 7, 7 };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(h, c);

	//set cursor size and visibility example

	CONSOLE_CURSOR_INFO cci = { 100, FALSE };
	SetConsoleCursorInfo(h, &cci);

	//set foreground color

	DWORD wAttr = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(h, wAttr);

	printf("Enter your name : ");

	textBox t(20, 34, 9);




	COORD c1 = { 27, 8 };
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(h1, c1);

	//set cursor size and visibility example

	CONSOLE_CURSOR_INFO cci1 = { 100, FALSE };
	SetConsoleCursorInfo(h1, &cci1);




	char text1[20];
	cin >> text1;



		cout<<"Your name is : " << text1 << endl <<
		"Your hobbies are : " << "daads" << endl;

	system("pause");
}