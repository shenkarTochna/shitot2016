#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

HANDLE hStdin;
DWORD fdwSaveOldMode;

VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD);
VOID MouseEventProc(MOUSE_EVENT_RECORD);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);


class checkBox {
private:
	string box = "[ ]";
	string text;
	bool isChecked = false;


public:

	checkBox() {};

	checkBox(string text) {
		setText(text);
		cout << "[ ]" << text << endl;
	}

	void check() {
		this->isChecked = true;

	}

	void uncheck() {
		this->isChecked = false;

	}

	void setText(string _text) {
		this->text = _text;
	}


	string getText() {
		return this->text;
	}

	bool getChecked() {
		return this->isChecked;
	}

};

class checkBoxSet {

private:
	string	lable;
	checkBox  checkBoxObj[3];
public:
	void setLable(string _lable) {
		this->lable = _lable;
	}


	checkBoxSet(string _lable, int positionX, int positionY) {
		this->lable = _lable;

		COORD cLabel = { positionX, positionY };
		HANDLE hLabel = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleCursorPosition(hLabel, cLabel);

		//set cursor size and visibility example

		CONSOLE_CURSOR_INFO cciLabel = { 100, FALSE };
		SetConsoleCursorInfo(hLabel, &cciLabel);


		cout << _lable << endl;
		checkBoxObj[0] = checkBox("food");
		checkBoxObj[1] = checkBox("bacon");
		checkBoxObj[2] = checkBox("humus");

		cout << endl << endl << "submit";
	}



	void submit() {

		COORD cLabel = { 0, 8 };
		HANDLE hLabel = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleCursorPosition(hLabel, cLabel);

		//set cursor size and visibility example

		CONSOLE_CURSOR_INFO cciLabel = { 100, FALSE };
		SetConsoleCursorInfo(hLabel, &cciLabel);

		cout << "Your hobbies are : " << endl;
		for (int i = 0; i < 3; i++) {
			if (checkBoxObj[i].getChecked() == true) {
				cout << this->checkBoxObj[i].getText() << endl;
			}
		}
	}
	void check(int i)
	{
		if (i == 0) {
			if (checkBoxObj[0].getChecked() == false) {
				COORD cLabel = { 1, 1 };
				HANDLE hLabel = GetStdHandle(STD_OUTPUT_HANDLE);

				SetConsoleCursorPosition(hLabel, cLabel);

				//set cursor size and visibility example

				CONSOLE_CURSOR_INFO cciLabel = { 100, FALSE };
				SetConsoleCursorInfo(hLabel, &cciLabel);

				cout << 'x';
				checkBoxObj[0].check();
			}

			else if (checkBoxObj[0].getChecked() == true) {
				COORD cLabel = { 1, 1 };
				HANDLE hLabel = GetStdHandle(STD_OUTPUT_HANDLE);

				SetConsoleCursorPosition(hLabel, cLabel);

				//set cursor size and visibility example

				CONSOLE_CURSOR_INFO cciLabel = { 100, FALSE };
				SetConsoleCursorInfo(hLabel, &cciLabel);

				cout << ' ';
				checkBoxObj[0].uncheck();
			}
		}

		if (i == 1) {
			if (checkBoxObj[1].getChecked() == false) {
				COORD cLabel = { 1, 2 };
				HANDLE hLabel = GetStdHandle(STD_OUTPUT_HANDLE);

				SetConsoleCursorPosition(hLabel, cLabel);

				//set cursor size and visibility example

				CONSOLE_CURSOR_INFO cciLabel = { 100, FALSE };
				SetConsoleCursorInfo(hLabel, &cciLabel);

				cout << 'x';
				checkBoxObj[1].check();
			}
			else if (checkBoxObj[1].getChecked() == true) {
				COORD cLabel = { 1, 2 };
				HANDLE hLabel = GetStdHandle(STD_OUTPUT_HANDLE);

				SetConsoleCursorPosition(hLabel, cLabel);

				//set cursor size and visibility example

				CONSOLE_CURSOR_INFO cciLabel = { 100, FALSE };
				SetConsoleCursorInfo(hLabel, &cciLabel);

				cout << ' ';
				checkBoxObj[1].uncheck();
			}
		}

		if (i == 2) {
			if (checkBoxObj[2].getChecked() == false) {
				COORD cLabel = { 1, 3 };
				HANDLE hLabel = GetStdHandle(STD_OUTPUT_HANDLE);

				SetConsoleCursorPosition(hLabel, cLabel);

				//set cursor size and visibility example

				CONSOLE_CURSOR_INFO cciLabel = { 100, FALSE };
				SetConsoleCursorInfo(hLabel, &cciLabel);

				cout << 'x';
				checkBoxObj[2].check();
			}

			else if (checkBoxObj[2].getChecked() == true) {
				COORD cLabel = { 1, 3 };
				HANDLE hLabel = GetStdHandle(STD_OUTPUT_HANDLE);

				SetConsoleCursorPosition(hLabel, cLabel);

				//set cursor size and visibility example

				CONSOLE_CURSOR_INFO cciLabel = { 100, FALSE };
				SetConsoleCursorInfo(hLabel, &cciLabel);

				cout << ' ';
				checkBoxObj[2].uncheck();
			}
		}
	}

};

checkBoxSet cbs("Enter hobbies", 0, 0);

void main() {

	int MouseEvents = 0;

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



	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter = 0;

	// Get the standard input handle. 

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		ErrorExit("GetStdHandle");

	// Save the current input mode, to be restored on exit. 

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		ErrorExit("GetConsoleMode");

	// Enable the window and mouse input events. 

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		ErrorExit("SetConsoleMode");



	while (1)
	{
		// Wait for the events. 

		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead)) // number of records read 
			ErrorExit("ReadConsoleInput");

		// Dispatch the events to the appropriate handler. 

		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				KeyEventProc(irInBuf[i].Event.KeyEvent);
				break;

			case MOUSE_EVENT: // mouse input 
				MouseEventProc(irInBuf[i].Event.MouseEvent);
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
				break;

			case FOCUS_EVENT:  // disregard focus events 

			case MENU_EVENT:   // disregard menu events 
				break;

			default:
				ErrorExit("Unknown event type");
				break;
			}
		}
	}


	system("pause");


}


VOID ErrorExit(LPSTR lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	ExitProcess(0);
}

VOID KeyEventProc(KEY_EVENT_RECORD ker)
{
	printf("%c", ker.uChar.AsciiChar);
}

VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif


	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			POINT t1;
			GetCursorPos(&t1);
			COORD c = { t1.x, t1.y };
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);



			//set cursor size and visibility example

			CONSOLE_CURSOR_INFO cci = { 2000, FALSE };
			SetConsoleCursorInfo(h, &cci);





			if ((c.X >5 && c.X<20) && (c.Y > 35 && c.Y<45))
			{
				cbs.check(0);
			}

			if ((c.X >5 && c.X<20) && (c.Y > 48 && c.Y<55))
			{
				cbs.check(1);
			}
			if ((c.X >5 && c.X<20) && (c.Y > 60 && c.Y<68))
			{
				cbs.check(2);
			}

			if ((c.X >1 && c.X<50) && (c.Y > 95 && c.Y<105))
			{
				cbs.submit();
			}
		}

		else
		{

		}
		break;

	default:

		break;
	}
}

VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{
	printf("Resize event\n");
	printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}