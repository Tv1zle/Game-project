#include <iostream>
#include <windows.h> 
#include <conio.h> 
#include <string>
//#include "Level1.h"
#pragma comment(lib, "winmm.lib")


HWND console = GetConsoleWindow();
RECT r;
HANDLE h = GetStdHandle(-11);
HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); // дескриптор окна для работы с мышкой
const int events_count = 512;
INPUT_RECORD all_events[events_count]; // массив событий, произошедших в консоли
DWORD read_event; // переменная, в которую запишется количество произошедших событий
COORD c; // переменная, отвечающая за координаты в консоли
bool musictemp = true, musicfirsttime = true, isfire = true, createthreadfirsttime = true, loginfirsttime = true;
int countclickvolume = 0, countclicktheme = 0, countclicklanguage = 0, countclicksize = 0, levelcap = 1;
std::string nickname;
const int width = 54, height = 12;


int main();
void login(CONSOLE_CURSOR_INFO cursor);
void registration(CONSOLE_CURSOR_INFO cursor);
void level1();
void level2();
void level3();
void level4();
void level5();
void level6();
void levelchoice();
void description();
void page1();
void page2();
void page3();
void page4();
void page5();
void page6();


DWORD WINAPI menufire(void* p)
{
	SYSTEMTIME firetime;
	SYSTEMTIME firetemp;
	GetLocalTime(&firetemp);
	COORD forfire1;
	forfire1.X = 6;
	forfire1.Y = 8;
	COORD forfire2;
	forfire2.X = 48;
	forfire2.Y = 8;
	bool rightshoot = false, leftshoot = true;
	SetConsoleTextAttribute(h, 14);


		while (true)
		{
			if (isfire)
			{
				GetLocalTime(&firetime);


				if (firetime.wMilliseconds > firetemp.wMilliseconds + 50)
				{
					GetLocalTime(&firetemp);
					

					if (leftshoot)
					{
						SetConsoleCursorPosition(h, forfire1);
						std::cout << " ";
						if (forfire1.X == 54)
							leftshoot = false;
						else if (forfire1.X == 34)
						{
							rightshoot = true;
							forfire2.X = 48;
							forfire2.Y = 8;
						}


						if (forfire1.X <= 54)
						{
							forfire1.X++;
							if (forfire1.X % 4 == 0 && forfire1.X <= 25)
							{
								forfire1.Y--;
							}
							else if (forfire1.X % 5 == 0 && forfire1.X >= 33)
							{
								forfire1.Y++;
							}
						}
						SetConsoleCursorPosition(h, forfire1);
						SetConsoleTextAttribute(h, 14);
						std::cout << "*";
					}


					if (rightshoot)
					{
						SetConsoleCursorPosition(h, forfire2);
						std::cout << " ";
						if (forfire2.X == 1)
							rightshoot = false;
						else if (forfire2.X == 20)
						{
							leftshoot = true;
							forfire1.X = 6;
							forfire1.Y = 8;
						}


						if (forfire2.X >= 1)
						{
							forfire2.X--;
							if (forfire2.X % 5 == 0 && forfire2.X >= 33)
							{
								forfire2.Y--;
							}
							else if (forfire2.X % 6 == 0 && forfire2.X <= 23)
							{
								forfire2.Y++;
							}
						}
						SetConsoleCursorPosition(h, forfire2);
						SetConsoleTextAttribute(h, 14);
						std::cout << "*";
					}
				}


				if (firetemp.wMilliseconds > 899)
					GetLocalTime(&firetemp);
			}
		}
}


DWORD WINAPI level1moves(void* p)
{


	while (true)
	{

	}
}


void registration(CONSOLE_CURSOR_INFO cursor)
{
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); // установка режима использования мышки


	std::string playerlog;
	std::string playerpass;
	int logcount = 0, passcount = 0;


	//setlocale(LC_ALL, "C");
	SetConsoleTextAttribute(h, 14);
	c.X = 18;
	c.Y = 1;
	SetConsoleCursorPosition(h, c);
	std::cout << "New account";


	c.X = 17;
	c.Y = 2;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 9);
	std::cout << (char)-38 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-65;


	c.X = 17;
	c.Y = 3;
	SetConsoleCursorPosition(h, c);
	std::cout << (char)-77;
	c.X = 18;
	c.Y = 3;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 14);
	std::cout << "Login";


	c.X = 38;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 9);
	std::cout << (char)-77;

	c.X = 17;
	c.Y = 4;
	SetConsoleCursorPosition(h, c);
	std::cout << (char)-64 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-39;


	c.X = 17;
	c.Y = 6;
	SetConsoleCursorPosition(h, c);
	std::cout << (char)-38 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-65;


	c.X = 17;
	c.Y = 7;
	SetConsoleCursorPosition(h, c);
	std::cout << (char)-77;
	SetConsoleTextAttribute(h, 14);
	c.X = 18;
	c.Y = 7;
	SetConsoleCursorPosition(h, c);
	std::cout << "Password";


	c.X = 38;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 9);
	std::cout << (char)-77;

	c.X = 17;
	c.Y = 8;
	SetConsoleCursorPosition(h, c);
	std::cout << (char)-64 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-39;


	c.X = 24;
	c.Y = 10;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 14);
	std::cout << "Register";


	c.X = 15;
	c.Y = 12;
	SetConsoleCursorPosition(h, c);
	std::cout << "Login";


	int button = 0, logcordinate = 18, passcordinate = 18;
	char ch = '\0';


	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{ // пройтись по всем событиям
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X; // запомнить координаты мышки
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


			if (c.X >= 17 && c.X <= 37 && c.Y == 3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				SetConsoleTextAttribute(h, 14);
				if (button == 2 && playerpass.length() <= 0)
				{
					c.X = 18;
					c.Y = 7;
					SetConsoleCursorPosition(h, c);
					std::cout << "Password";
				}


				if (playerlog.length() <= 0)
				{
					c.X = 18;
					c.Y = 3;
					SetConsoleCursorPosition(h, c);
					std::cout << "     ";
				}


				cursor.bVisible = true;
				SetConsoleCursorInfo(h, &cursor);
				c.X = logcordinate;
				c.Y = 3;
				SetConsoleCursorPosition(h, c);
				button = 1;


				while (true)
				{
					int code = _getch();


					if (code == 8)
					{
						if (!playerlog.empty())
						{
							playerlog.pop_back();
							c.X--;
							logcordinate--;
							SetConsoleCursorPosition(h, c);
							std::cout << " ";
							SetConsoleCursorPosition(h, c);
						}
					}
					else if (code == 13)
					{
						cursor.bVisible = false;
						SetConsoleCursorInfo(h, &cursor);
						break;
					}
					else
					{
						if (playerlog.length() < 20)
						{
							ch = (char)code;
							std::cout << ch;
							c.X++;
							logcordinate++;
							playerlog += ch;
						}
					}
				}
			}
			else if (c.X >= 17 && c.X <= 37 && c.Y == 7 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				SetConsoleTextAttribute(h, 14);
				if (button == 1 && playerlog.length() <= 0)
				{
					c.X = 18;
					c.Y = 3;
					SetConsoleCursorPosition(h, c);
					std::cout << "Login";
				}


				if (playerpass.length() <= 0)
				{
					c.X = 18;
					c.Y = 7;
					SetConsoleCursorPosition(h, c);
					std::cout << "        ";
				}


				cursor.bVisible = true;
				SetConsoleCursorInfo(h, &cursor);
				c.X = passcordinate;
				c.Y = 7;
				SetConsoleCursorPosition(h, c);
				button = 2;


				while (true)
				{
					int code = _getch();


					if (code == 8)
					{
						if (!playerpass.empty())
						{
							playerpass.pop_back();
							c.X--;
							passcordinate--;
							SetConsoleCursorPosition(h, c);
							std::cout << " ";
							SetConsoleCursorPosition(h, c);
						}
					}
					else if (code == 13)
					{
						cursor.bVisible = false;
						SetConsoleCursorInfo(h, &cursor);
						break;
					}
					else
					{
						if (playerpass.length() < 20)
						{
							ch = (char)code;
							std::cout << "*";
							c.X++;
							passcordinate++;
							playerpass += ch;
						}
					}
				}
			}
			else if (c.X >= 24 && c.X <= 31 && c.Y == 10 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				if (playerlog.length() < 2)
				{
					c.X = 9;
					c.Y = 9;
					SetConsoleCursorPosition(h, c);
					SetConsoleTextAttribute(h, 12);
					std::cout << " Login must be more than 2 characters";
				}
				else if (playerpass.length() < 8)
				{
					c.X = 9;
					c.Y = 9;
					SetConsoleCursorPosition(h, c);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Password must be more than 8 characters";
				}
				else
				{
					FILE* f;
					fopen_s(&f, "D:/C++_gameProject/GameProject/login.txt", "a+");
					nickname = playerlog;
					playerlog += "`";
					fputs(playerlog.c_str(), f);
					fclose(f);


					fopen_s(&f, "D:/C++_gameProject/GameProject/password.txt", "a+");
					playerpass += "`";
					fputs(playerpass.c_str(), f);
					fclose(f);


					system("cls");
					main();
				}
			}
			else if (c.X >= 15 && c.X <= 19 && c.Y == 12 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				login(cursor);
			}
			else if ((c.X < 17 || c.X > 37 || c.Y != 3) && button == 1 && playerlog.length() <= 0 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				c.X = 18;
				c.Y = 3;
				SetConsoleCursorPosition(h, c);
				SetConsoleTextAttribute(h, 14);
				std::cout << "Login";
				cursor.bVisible = false;
				SetConsoleCursorInfo(h, &cursor);
			}
			else if ((c.X < 17 || c.X > 37 || c.Y != 7) && button == 2 && playerpass.length() <= 0 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				c.X = 18;
				c.Y = 7;
				SetConsoleCursorPosition(h, c);
				SetConsoleTextAttribute(h, 14);
				std::cout << "Password";
				cursor.bVisible = false;
				SetConsoleCursorInfo(h, &cursor);
			}
			else if ((c.X < 17 || c.X > 37 || c.Y != 3) && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED ||
				(c.X < 17 || c.X > 37 || c.Y != 7) && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				cursor.bVisible = false;
				SetConsoleCursorInfo(h, &cursor);
			}
		}
	}
}


void login(CONSOLE_CURSOR_INFO cursor)
{
	if (musictemp)
		PlaySound(TEXT("D:\\C++_gameProject\\MenuSong.wav"), NULL, SND_ASYNC);
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); // установка режима использования мышки


	std::string playerlog, randlog = "";
	std::string playerpass, randpass = "";
	int logcount = 0, passcount = 0;


	//setlocale(LC_ALL, "C");
	SetConsoleTextAttribute(h, 14);
	c.X = 18;
	c.Y = 1;
	SetConsoleCursorPosition(h, c);
	std::cout << "Account";


	c.X = 17;
	c.Y = 2;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 9);
	std::cout << (char)-38 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-65;


	c.X = 17;
	c.Y = 3;
	SetConsoleCursorPosition(h, c);
	std::cout << (char)-77;
	c.X = 18;
	c.Y = 3;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 14);
	std::cout << "Login";


	c.X = 38;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 9);
	std::cout << (char)-77;

	c.X = 17;
	c.Y = 4;
	SetConsoleCursorPosition(h, c);
	std::cout << (char)-64 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-39;


	c.X = 17;
	c.Y = 6;
	SetConsoleCursorPosition(h, c);
	std::cout << (char)-38 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-65;


	c.X = 17;
	c.Y = 7;
	SetConsoleCursorPosition(h, c);
	std::cout << (char)-77;
	SetConsoleTextAttribute(h, 14);
	c.X = 18;
	c.Y = 7;
	SetConsoleCursorPosition(h, c);
	std::cout << "Password";


	c.X = 38;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 9);
	std::cout << (char)-77;

	c.X = 17;
	c.Y = 8;
	SetConsoleCursorPosition(h, c);
	std::cout << (char)-64 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-60 << (char)-39;


	c.X = 25;
	c.Y = 10;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 14);
	std::cout << "Login";


	c.X = 12;
	c.Y = 12;
	SetConsoleCursorPosition(h, c);
	std::cout << "Registration       Login as a guest";

	int button = 0, logcordinate = 18, passcordinate = 18;
	char ch = '\0';

	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{ // пройтись по всем событиям
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X; // запомнить координаты мышки
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


			if (c.X >= 17 && c.X <= 37 && c.Y == 3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				SetConsoleTextAttribute(h, 14);
				if (button == 2 && playerpass.length() <= 0)
				{
					c.X = 18;
					c.Y = 7;
					SetConsoleCursorPosition(h, c);
					std::cout << "Password";
				}


				if (playerlog.length() <= 0)
				{
					c.X = 18;
					c.Y = 3;
					SetConsoleCursorPosition(h, c);
					std::cout << "     ";
				}


				cursor.bVisible = true;
				SetConsoleCursorInfo(h, &cursor);
				c.X = logcordinate;
				c.Y = 3;
				SetConsoleCursorPosition(h, c);
				button = 1;


				while (true) 
				{
					int code = _getch();


					if (code == 8)
					{
						if (!playerlog.empty())
						{
							playerlog.pop_back();
							c.X--;
							logcordinate--;
							SetConsoleCursorPosition(h, c);
							std::cout << " ";
							SetConsoleCursorPosition(h, c);
						}
					}
					else if (code == 13)
					{
						cursor.bVisible = false;
						SetConsoleCursorInfo(h, &cursor);
						break;
					}
					else
					{
						if (playerlog.length() < 20)
						{
							ch = (char)code;
							std::cout << ch;
							c.X++;
							logcordinate++;
							playerlog += ch;
						}
					}
				}
			}
			else if (c.X >= 17 && c.X <= 37 && c.Y == 7 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				SetConsoleTextAttribute(h, 14);
				if (button == 1 && playerlog.length() <= 0)
				{
					c.X = 18;
					c.Y = 3;
					SetConsoleCursorPosition(h, c);
					std::cout << "Login";
				}


				if (playerpass.length() <= 0)
				{
					c.X = 18;
					c.Y = 7;
					SetConsoleCursorPosition(h, c);
					std::cout << "        ";
				}


				cursor.bVisible = true;
				SetConsoleCursorInfo(h, &cursor);
				c.X = passcordinate;
				c.Y = 7;
				SetConsoleCursorPosition(h, c);
				button = 2;


				while (true)
				{
					int code = _getch();


					if (code == 8)
					{
						if (!playerpass.empty())
						{
							playerpass.pop_back();
							c.X--;
							passcordinate--;
							SetConsoleCursorPosition(h, c);
							std::cout << " ";
							SetConsoleCursorPosition(h, c);
						}
					}
					else if (code == 13)
					{
						cursor.bVisible = false;
						SetConsoleCursorInfo(h, &cursor);
						break;
					}
					else
					{
						if (playerpass.length() < 20)
						{
							ch = (char)code;
							std::cout << "*";
							c.X++;
							passcordinate++;
							playerpass += ch;
						}
					}
				}
			}
			else if (c.X >= 25 && c.X <= 29 && c.Y == 10 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				if (playerlog.length() < 2)
				{
					c.X = 10;
					c.Y = 9;
					SetConsoleCursorPosition(h, c);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Login must be more than 2 characters";
				}
				else if (playerpass.length() < 8)
				{
					c.X = 9;
					c.Y = 9;
					SetConsoleCursorPosition(h, c);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Password must be more than 8 characters";
				}
				else
				{
					SetConsoleTextAttribute(h, 14);
					FILE* f;
					fopen_s(&f, "D:/C++_gameProject/GameProject/login.txt", "r");
					fseek(f, 0, SEEK_END); // перемещение в конец файла
					int size1 = ftell(f); // узнаём текущую позицию курсора (сколько символов)
					char* str1 = new char[size1 + 1]; // выделяем строку под это количество символов
					rewind(f); // переводим курсор в начало файла
					int symbols1 = fread(str1, sizeof(char), size1, f); // считываем весь файл одним куском
					// в symbols запишется количество успешно считанных символов
					// str - куда будут помещены все считанные символы
					// sizeof(char) - размер ячеек (1Б), которыми будет читаться файл
					// size - это сколько всего надо считать ячеек типа char
					// f - указатель на файл, из которого производится чтение
					fclose(f);


					str1[symbols1] = '\0';
					AnsiToOem(str1, str1); // для корректного считывания кириллицы, текстовый файл должен быть сохранён в кодировке ANSI
					std::string logins = str1;


					fopen_s(&f, "D:/C++_gameProject/GameProject/password.txt", "r");
					fseek(f, 0, SEEK_END); // перемещение в конец файла
					int size2 = ftell(f); // узнаём текущую позицию курсора (сколько символов)
					char* str2 = new char[size2 + 1]; // выделяем строку под это количество символов
					rewind(f); // переводим курсор в начало файла
					int symbols2 = fread(str2, sizeof(char), size2, f);
					fclose(f);


					str2[symbols2] = '\0';
					AnsiToOem(str2, str2);
					std::string passwords = str2;


					while (true)
					{
						for (; logcount < logins.length(); logcount++)
						{
							if (logins[logcount] == '`')
							{
								logcount++;
								break;
							}
							else
							{
								randlog += logins[logcount];
							}
						}


						for (; passcount < passwords.length(); passcount++)
						{
							if (passwords[passcount] == '`')
							{
								passcount++;
								break;
							}
							else
							{
								randpass += passwords[passcount];
							}
						}


						if (playerlog == randlog && playerpass == randpass)
						{
							delete[] str1;
							delete[] str2;
							nickname = playerlog;
							system("cls");
							main();
						}
						else if (logcount == logins.length() || passcount == passwords.length())
						{
							c.X = 14;
							c.Y = 9;
							SetConsoleCursorPosition(h, c);
							SetConsoleTextAttribute(h, 12);
							std::cout << "Not correct password or login";
							break;
						}
						else
						{
							randlog = "";
							randpass = "";
						}
					}
				}
			}
			else if (c.X >= 12 && c.X <= 23 && c.Y == 12 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				registration(cursor);
			}
			else if (c.X >= 31 && c.X <= 46 && c.Y == 12 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				nickname = "Guest";
				system("cls");
				main();
			}
			else if ((c.X < 17 || c.X > 37 || c.Y != 3) && button == 1 && playerlog.length() <= 0 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && randlog == "")
			{
				c.X = 18;
				c.Y = 3;
				SetConsoleCursorPosition(h, c);
				SetConsoleTextAttribute(h, 14);
				std::cout << "Login";
				cursor.bVisible = false;
				SetConsoleCursorInfo(h, &cursor);
			}
			else if ((c.X < 17 || c.X > 37 || c.Y != 7) && button == 2 && playerpass.length() <= 0 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && randpass == "")
			{
				c.X = 18;
				c.Y = 7;
				SetConsoleCursorPosition(h, c);
				SetConsoleTextAttribute(h, 14);
				std::cout << "Password";
				cursor.bVisible = false;
				SetConsoleCursorInfo(h, &cursor);
			}
			else if ((c.X < 17 || c.X > 37 || c.Y != 3) && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED ||
				(c.X < 17 || c.X > 37 || c.Y != 7) && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				cursor.bVisible = false;
				SetConsoleCursorInfo(h, &cursor);
			}
		}
	}
}


void menu() // Меню начала
{
	COORD menubox;
	menubox.X = 34;
	menubox.Y = 1;
	SetConsoleCursorPosition(h, menubox);
	SetConsoleTextAttribute(h, 9);
	std::cout << (char)31 << " " << nickname;


	menubox.X = 24;
	menubox.Y = 4;
	SetConsoleCursorPosition(h, menubox);
	std::cout << "Play";

	menubox.Y = 6;
	SetConsoleCursorPosition(h, menubox);
	std::cout << "Settings";

	menubox.Y = 8;
	SetConsoleCursorPosition(h, menubox);
	std::cout << "News";

	menubox.Y = 10;
	SetConsoleCursorPosition(h, menubox);
	std::cout << "Exit";


	menubox.X = 4;
	menubox.Y = 9;
	SetConsoleCursorPosition(h, menubox);
	SetConsoleTextAttribute(h, 9);
	std::cout << "|\\" << (char)1 << "/|";
	menubox.X = 4;
	menubox.Y = 10;
	SetConsoleCursorPosition(h, menubox);
	std::cout << "| T |";
	menubox.X = 4;
	menubox.Y = 11;
	SetConsoleCursorPosition(h, menubox);
	std::cout << " |_| ";
	menubox.X = 4;
	menubox.Y = 12;
	SetConsoleCursorPosition(h, menubox);
	std::cout << "|___|";


	menubox.X = 47;
	menubox.Y = 9;
	SetConsoleCursorPosition(h, menubox);
	std::cout << "|\\" << (char)1 << "/|";
	menubox.X = 47;
	menubox.Y = 10;
	SetConsoleCursorPosition(h, menubox);
	std::cout << "| T |";
	menubox.X = 47;
	menubox.Y = 11;
	SetConsoleCursorPosition(h, menubox);
	std::cout << " |_| ";
	menubox.X = 47;
	menubox.Y = 12;
	SetConsoleCursorPosition(h, menubox);
	std::cout << "|___|";
	menubox.X = 3;
}


void levelchoice() // выбор уровней нажав "Play"
{
	if (musictemp)
		PlaySound(TEXT("D:\\C++_gameProject\\MenuSong.wav"), NULL, SND_ASYNC);
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); // установка режима использования мышки
	COORD textforchoice;
	textforchoice.X = 2;
	textforchoice.Y = 1;


	SetConsoleCursorPosition(h, textforchoice);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Quit";


	textforchoice.X = 43;
	textforchoice.Y = 1;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "Description";


	textforchoice.Y = 2;
	SetConsoleCursorPosition(h, textforchoice);
	SetConsoleTextAttribute(h, 9);
	setlocale(LC_ALL, "C");
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 54; x++)
		{

			if (y > 1 && y < 5 || y > 6 && y < 10)
			{

				if (x == 3) {
					std::cout << char(1971);
				}
				else if (x == 15) {
					std::cout << char(1971);
				}
				else if (x == 19) {
					std::cout << char(1971);
				}
				else if (x == 31) {
					std::cout << char(1971);
				}
				else if (x == 35) {
					std::cout << char(1971);
				}
				else if (x == 47) {
					std::cout << char(1971);
				}
			}

			if (y == 1 && x > 3 && x < 16) {
				std::cout << "_";
			}
			else if (y == 4 && x > 2 && x < 15) {
				std::cout << "_";
			}
			else if (y == 1 && x > 21 && x < 34) {
				std::cout << "_";
			}
			else if (y == 4 && x > 18 && x < 31) {
				std::cout << "_";
			}
			else if (y == 1 && x > 39 && x < 52) {
				std::cout << "_";
			}
			else if (y == 4 && x > 34 && x < 47) {
				std::cout << "_";
			}
			else if (y == 6 && x > 3 && x < 16) {
				std::cout << "_";
			}
			else if (y == 9 && x > 2 && x < 15)
			{
				std::cout << "_";
			}
			else if (y == 6 && x > 21 && x < 34)
			{
				std::cout << "_";
			}
			else if (y == 9 && x > 18 && x < 31)
			{
				std::cout << "_";
			}
			else if (y == 6 && x > 39 && x < 52)
			{
				std::cout << "_";
			}
			else if (y == 9 && x > 34 && x < 47)
			{
				std::cout << "_";
			}
			else
			{
				std::cout << " ";
			}
		}
		if (y != 12 - 1)
			std::cout << "\n";
	}
	textforchoice.X = 6;
	textforchoice.Y = 5;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "Level 1";


	textforchoice.X = 24;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "Level 2";


	textforchoice.X = 42;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "Level 3";


	textforchoice.X = 6;
	textforchoice.Y = 10;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "Level 4";


	textforchoice.X = 24;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "Level 5";


	textforchoice.X = 42;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "Level 6";


	if (levelcap == 1)
	{
		textforchoice.X = 25;
		textforchoice.Y = 3;
		SetConsoleCursorPosition(h, textforchoice);
		SetConsoleTextAttribute(h, 12);
		std::cout << char(218) << char(-60) << char(-60) << char(-60) << char(-65);

		textforchoice.X = 25;
		textforchoice.Y = 4;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << "_____";
		textforchoice.X = 24;
		textforchoice.Y = 5;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << "/     \\";
		textforchoice.X = 24;
		textforchoice.Y = 6;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << "|  " << char(2069) << "  |";
		textforchoice.X = 24;
		textforchoice.Y = 7;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << "\\_____/";


		textforchoice.X = 43;
		textforchoice.Y = 3;
		SetConsoleCursorPosition(h, textforchoice);
		SetConsoleTextAttribute(h, 12);
		std::cout << char(218) << char(-60) << char(-60) << char(-60) << char(-65);

		textforchoice.X = 41;
		textforchoice.Y = 4;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << "  _____";
		textforchoice.X = 41;
		textforchoice.Y = 5;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << " /     \\   \n";
		textforchoice.X = 42;
		textforchoice.Y = 6;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << "|  " << char(2069) << "  |\n";
		textforchoice.X = 41;
		textforchoice.Y = 7;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << " \\_____/     \n";


		textforchoice.X = 7;
		textforchoice.Y = 8;
		SetConsoleCursorPosition(h, textforchoice);
		SetConsoleTextAttribute(h, 12);
		std::cout << char(218) << char(-60) << char(-60) << char(-60) << char(-65);

		textforchoice.X = 5;
		textforchoice.Y = 9;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << "  _____";
		textforchoice.X = 5;
		textforchoice.Y = 10;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << " /     \\   \n";
		textforchoice.X = 6;
		textforchoice.Y = 11;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << "|  " << char(2069) << "  |\n";
		textforchoice.X = 5;
		textforchoice.Y = 12;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << " \\_____/     \n";


		textforchoice.X = 25;
		textforchoice.Y = 8;
		SetConsoleCursorPosition(h, textforchoice);
		SetConsoleTextAttribute(h, 12);
		std::cout << char(218) << char(-60) << char(-60) << char(-60) << char(-65);

		textforchoice.X = 23;
		textforchoice.Y = 9;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << "  _____";
		textforchoice.X = 23;
		textforchoice.Y = 10;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << " /     \\   \n";
		textforchoice.X = 24;
		textforchoice.Y = 11;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << "|  " << char(2069) << "  |\n";
		textforchoice.X = 23;
		textforchoice.Y = 12;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << " \\_____/     \n";
		

		textforchoice.X = 43;
		textforchoice.Y = 8;
		SetConsoleCursorPosition(h, textforchoice);
		SetConsoleTextAttribute(h, 12);
		std::cout << char(218) << char(-60) << char(-60) << char(-60) << char(-65);

		textforchoice.X = 41;
		textforchoice.Y = 9;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << "  _____";
		textforchoice.X = 41;
		textforchoice.Y = 10;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << " /     \\   \n";
		textforchoice.X = 42;
		textforchoice.Y = 11;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << "|  " << char(2069) << "  |\n";
		textforchoice.X = 41;
		textforchoice.Y = 12;
		SetConsoleCursorPosition(h, textforchoice);
		std::cout << " \\_____/     \n";
	}
	else if (levelcap == 2)
	{
	textforchoice.X = 43;
	textforchoice.Y = 3;
	SetConsoleCursorPosition(h, textforchoice);
	SetConsoleTextAttribute(h, 12);
	std::cout << char(218) << char(-60) << char(-60) << char(-60) << char(-65);

	textforchoice.X = 41;
	textforchoice.Y = 4;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "  _____";
	textforchoice.X = 41;
	textforchoice.Y = 5;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << " /     \\   \n";
	textforchoice.X = 42;
	textforchoice.Y = 6;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "|  " << char(2069) << "  |\n";
	textforchoice.X = 41;
	textforchoice.Y = 7;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << " \\_____/     \n";


	textforchoice.X = 7;
	textforchoice.Y = 8;
	SetConsoleCursorPosition(h, textforchoice);
	SetConsoleTextAttribute(h, 12);
	std::cout << char(218) << char(-60) << char(-60) << char(-60) << char(-65);

	textforchoice.X = 5;
	textforchoice.Y = 9;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "  _____";
	textforchoice.X = 5;
	textforchoice.Y = 10;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << " /     \\   \n";
	textforchoice.X = 6;
	textforchoice.Y = 11;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "|  " << char(2069) << "  |\n";
	textforchoice.X = 5;
	textforchoice.Y = 12;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << " \\_____/     \n";


	textforchoice.X = 25;
	textforchoice.Y = 8;
	SetConsoleCursorPosition(h, textforchoice);
	SetConsoleTextAttribute(h, 12);
	std::cout << char(218) << char(-60) << char(-60) << char(-60) << char(-65);

	textforchoice.X = 23;
	textforchoice.Y = 9;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "  _____";
	textforchoice.X = 23;
	textforchoice.Y = 10;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << " /     \\   \n";
	textforchoice.X = 24;
	textforchoice.Y = 11;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "|  " << char(2069) << "  |\n";
	textforchoice.X = 23;
	textforchoice.Y = 12;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << " \\_____/     \n";


	textforchoice.X = 43;
	textforchoice.Y = 8;
	SetConsoleCursorPosition(h, textforchoice);
	SetConsoleTextAttribute(h, 12);
	std::cout << char(218) << char(-60) << char(-60) << char(-60) << char(-65);

	textforchoice.X = 41;
	textforchoice.Y = 9;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "  _____";
	textforchoice.X = 41;
	textforchoice.Y = 10;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << " /     \\   \n";
	textforchoice.X = 42;
	textforchoice.Y = 11;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << "|  " << char(2069) << "  |\n";
	textforchoice.X = 41;
	textforchoice.Y = 12;
	SetConsoleCursorPosition(h, textforchoice);
	std::cout << " \\_____/     \n";
	}
	setlocale(LC_ALL, "Russian");


	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{ // пройтись по всем событиям
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X; // запомнить координаты мышки
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


			if (c.X >= 2 && c.X <= 8 && c.Y >= 0 && c.Y <= 1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // если нажата ЛЕВАЯ КНОПКА МЫШКИ
				SetConsoleCursorPosition(h, c); // установка координат в то место, где курсор
				system("cls");
				main();
			}
			else if (c.X >= 43 && c.X <= 54 && c.Y >= 0 && c.Y <= 1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ 
				system("cls");
				description();
			}
			else if (c.X >= 2 && c.X <= 17 && c.Y >= 4 && c.Y <= 7 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				level1();
			}
			else if (c.X >= 20 && c.X <= 35 && c.Y >= 4 && c.Y <= 7 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				//if (levelcap >= 2)
					level2();
			}
			/*else if (c.X >= && c.X <= && c.Y >= && c.Y <= && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				level3(count, killscount, width, height);
			}
			else if (c.X >= && c.X <= && c.Y >= && c.Y <= && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				level4(count, killscount, width, height);
			}
			else if (c.X >= && c.X <= && c.Y >= && c.Y <= && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				level5(count, killscount, width, height);
			}
			else if (c.X >= && c.X <= && c.Y >= && c.Y <= && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				level6(count, killscount, width, height);
			}
			else if (c.X >= && c.X <= && c.Y >= && c.Y <= && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				menu();
			}*/
			else if (c.X >= 2 && c.X <= 8 && c.Y == 1)
			{
				SetConsoleTextAttribute(h, 14);
				c.X = 2;
				c.Y = 1;
				SetConsoleCursorPosition(h, c);
				std::cout << "Quit";
			}
			else if (c.Y > 1 || c.Y < 1 || c.X > 6 || c.X < 2)
			{
				SetConsoleTextAttribute(h, 12);
				c.X = 2;
				c.Y = 1;
				SetConsoleCursorPosition(h, c);
				std::cout << "Quit";
			}
		}
	}
}


void description()
{
	PlaySound(NULL, NULL, SND_ASYNC);
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);


	COORD infobox;
	infobox.X = 2;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Quit";


	infobox.X = 15;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "What do you want to know?";


	setlocale(LC_ALL, "C");


	SetConsoleTextAttribute(h, 14);
	infobox.X = 5;
	infobox.Y = 4;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(218);
	std::cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	std::cout << char(191);


	infobox.Y = 5;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(179);
	std::cout << "        ";
	std::cout << char(179);


	infobox.Y = 6;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(192);
	std::cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	std::cout << char(217);

	///////////////////////////////////////////////////////////////////

	infobox.Y = 7;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(218);
	std::cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	std::cout << char(191);


	infobox.Y = 8;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(179);
	std::cout << "        ";
	std::cout << char(179);


	infobox.Y = 9;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(192);
	std::cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	std::cout << char(217);

	///////////////////////////////////////////////////////////////////

	infobox.Y = 10;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(218);
	std::cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	std::cout << char(191);


	infobox.Y = 11;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(179);
	std::cout << "        ";
	std::cout << char(179);


	infobox.Y = 12;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(192);
	std::cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	std::cout << char(217);

	setlocale(LC_ALL, "Russian");


	infobox.X = 6;
	infobox.Y = 5;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 9);
	std::cout << "Levels";


	infobox.X = 6;
	infobox.Y = 8;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 9);
	std::cout << "Enemies";


	infobox.X = 6;
	infobox.Y = 11;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 9);
	std::cout << "Weapons";


	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X;
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


			if (c.X >= 2 && c.X <= 6 && c.Y >= 0 && c.Y <= 1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				if (musictemp)
					PlaySound(TEXT("D:\\C++_gameProject\\MenuSong.wav"), NULL, SND_ASYNC);
				system("cls");
				levelchoice();
			}
			else if (c.X >= 5 && c.X <= 14 && c.Y >= 4 && c.Y <= 6 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				page1();
			}
			else if (c.X >= 5 && c.X <= 14 && c.Y >= 7 && c.Y <= 9 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				page3();
			}
			else if (c.X >= 5 && c.X <= 14 && c.Y >= 10 && c.Y <= 12 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				page5();
			}
		}

	}
}


void page1()
{
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);


	COORD infobox;
	SetConsoleTextAttribute(h, 9);
	for (int y = 0; y <= 12; y++)
	{
		for (int x = 0; x < 54; x++)
		{
			if (x == 7 || x == 48)
				std::cout << "|";
			else
				std::cout << " ";
		}
		std::cout << "\n";
	}


	infobox.X = 2;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Quit";

	
	setlocale(LC_ALL, "C");


	infobox.X = 51;
	infobox.Y = 10;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(218);
	std::cout << char(196);
	std::cout << char(191);


	infobox.Y = 11;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(179);
	std::cout << char(26);
	std::cout << char(179);


	infobox.Y = 12;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(192);
	std::cout << char(196);
	std::cout << char(217);


	setlocale(LC_ALL, "Russian");


	infobox.X = 24;
	infobox.Y = 0;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Levels";


	infobox.X = 9;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "There are only 12 levels in the game, ";


	infobox.X = 9;
	infobox.Y = 2;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "the first 6 levels are defense, last 6 ";


	infobox.X = 9;
	infobox.Y = 3;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "are attack. ";


	infobox.X = 9;
	infobox.Y = 4;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "Defense - the main goal of this type is";


	infobox.X = 9;
	infobox.Y = 5;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "to ensure that no enemy reaches the end";


	infobox.X = 9;
	infobox.Y = 6;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "of the road, your ability to build";


	infobox.X = 9;
	infobox.Y = 7;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "buildings for protection from enemies.";


	infobox.X = 9;
	infobox.Y = 8;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "Each level of this type opens";


	infobox.X = 9;
	infobox.Y = 9;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "sequentially, passing the previous";


	infobox.X = 9;
	infobox.Y = 10;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "level opens the next one, and so on up";



	infobox.X = 9;
	infobox.Y = 11;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "to level 6.";


	infobox.X = 9;
	infobox.Y = 12;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "However, starting at 7th level, your";


	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X;
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


			if (c.X >= 2 && c.X <= 6 && c.Y >= 0 && c.Y <= 1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				description();
			}
			else if (c.X >= 51 && c.X <= 53 && c.Y >= 10 && c.Y <= 12 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{

				page2();
			}
		}
	}
}


void page2()
{
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);


	COORD infobox;
	SetConsoleTextAttribute(h, 9);
	for (int y = 0; y <= 12; y++)
	{
		for (int x = 0; x < 54; x++)
		{
			if (x == 7 || x == 48)
				std::cout << "|";
			else
				std::cout << " ";
		}
		std::cout << "\n";
	}


	infobox.X = 2;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Quit";


	setlocale(LC_ALL, "C");
	infobox.X = 2;
	infobox.Y = 10;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(218);
	std::cout << char(196);
	std::cout << char(191);


	infobox.Y = 11;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(179);
	std::cout << char(27);
	std::cout << char(179);


	infobox.Y = 12;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(192);
	std::cout << char(196);
	std::cout << char(217);
	setlocale(LC_ALL, "Russian");


	infobox.X = 24;
	infobox.Y = 0;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Levels";

	
	infobox.X = 9;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "goal is not to defend, but to attack.";


	infobox.X = 9;
	infobox.Y = 2;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "Attack - the main goal is to attack the";


	infobox.X = 9;
	infobox.Y = 3;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "enemy with your army. To win, you need";
	

	infobox.X = 9;
	infobox.Y = 4;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "to reach a certain point.";


	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X;
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


			if (c.X >= 2 && c.X <= 6 && c.Y >= 0 && c.Y <= 1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				description();
			}
			else if (c.X >= 2 && c.X <= 4 && c.Y >= 10 && c.Y <= 12 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				page1();
			}
		}

	}
}


void page3()
{
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);


	COORD infobox;
	SetConsoleTextAttribute(h, 9);
	for (int y = 0; y <= 12; y++)
	{
		for (int x = 0; x < 54; x++)
		{
			if (x == 7 || x == 48)
				std::cout << "|";
			else
				std::cout << " ";
		}
		std::cout << "\n";
	}


	infobox.X = 2;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Quit";


	setlocale(LC_ALL, "C");


	infobox.X = 51;
	infobox.Y = 10;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(218);
	std::cout << char(196);
	std::cout << char(191);


	infobox.Y = 11;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(179);
	std::cout << char(26);
	std::cout << char(179);


	infobox.Y = 12;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(192);
	std::cout << char(196);
	std::cout << char(217);


	setlocale(LC_ALL, "Russian");


	infobox.X = 24;
	infobox.Y = 0;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Enemies";


	infobox.X = 9;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "There are two types of enemies in the";


	infobox.X = 9;
	infobox.Y = 2;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "game. They are divided into:";


	infobox.X = 9;
	infobox.Y = 3;
	SetConsoleCursorPosition(h, infobox);
	setlocale(LC_ALL, "C");
	std::cout << (char)1 << " - normal soldier, have only 100 hp,";
	setlocale(LC_ALL, "Russian");


	infobox.X = 9;
	infobox.Y = 4;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "speed - cell per second, kill reward -";


	infobox.X = 9;
	infobox.Y = 5;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "5000 UAH.";


	infobox.X = 9;
	infobox.Y = 6;
	SetConsoleCursorPosition(h, infobox);
	setlocale(LC_ALL, "С");
	std::cout << (char)2 << " - lieutenant, have from 500 to 5000";
	setlocale(LC_ALL, "Russian");


	infobox.X = 9;
	infobox.Y = 7;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "hp depending on the level, speed - from";


	infobox.X = 9;
	infobox.Y = 8;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "one to three blocks per second,";


	infobox.X = 9;
	infobox.Y = 9;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "reward for killing - from 15000 to";


	infobox.X = 9;
	infobox.Y = 10;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "25000 UAH, all lieutenants differ from";



	infobox.X = 9;
	infobox.Y = 11;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "each other, at the very first levels";


	infobox.X = 9;
	infobox.Y = 12;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "they are quite simple, but what ";


	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X;
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


			if (c.X >= 2 && c.X <= 6 && c.Y >= 0 && c.Y <= 1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				description();
			}
			else if (c.X >= 51 && c.X <= 53 && c.Y >= 10 && c.Y <= 12 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				page4();
			}
		}
	}
}


void page4()
{
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);


	COORD infobox;
	SetConsoleTextAttribute(h, 9);
	for (int y = 0; y <= 12; y++)
	{
		for (int x = 0; x < 54; x++)
		{
			if (x == 7 || x == 48)
				std::cout << "|";
			else
				std::cout << " ";
		}
		std::cout << "\n";
	}


	infobox.X = 2;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Quit";


	setlocale(LC_ALL, "C");
	infobox.X = 2;
	infobox.Y = 10;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(218);
	std::cout << char(196);
	std::cout << char(191);


	infobox.Y = 11;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(179);
	std::cout << char(27);
	std::cout << char(179);


	infobox.Y = 12;
	SetConsoleCursorPosition(h, infobox);
	std::cout << char(192);
	std::cout << char(196);
	std::cout << char(217);
	setlocale(LC_ALL, "Russian");


	infobox.X = 24;
	infobox.Y = 0;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Enemies";


	infobox.X = 9;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "further, the stronger and faster they";


	infobox.X = 9;
	infobox.Y = 2;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "become, but the reward for them";


	infobox.X = 9;
	infobox.Y = 3;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "increases.";


	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X;
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


			if (c.X >= 2 && c.X <= 6 && c.Y >= 0 && c.Y <= 1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				description();
			}
			else if (c.X >= 2 && c.X <= 4 && c.Y >= 10 && c.Y <= 12 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				page3();
			}
		}
	}
}


void page5()
{

}


void settings() // выбор настроек нажав "Settings"
{
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); // установка режима использования мышки
	setlocale(LC_ALL, "Russian");
	COORD textforsettings;
	textforsettings.X = 20;
	textforsettings.Y = 3;
	SetConsoleCursorPosition(h, textforsettings);
	SetConsoleTextAttribute(h, 9);
	std::cout << "Volume : On";


	textforsettings.Y = 5;
	SetConsoleCursorPosition(h, textforsettings);
	std::cout << "Theme : Ukrainian";


	textforsettings.Y = 7;
	SetConsoleCursorPosition(h, textforsettings);
	std::cout << "Language : English";


	textforsettings.Y = 9;
	SetConsoleCursorPosition(h, textforsettings);
	std::cout << "Font size : 72";


	textforsettings.X = 2;
	textforsettings.Y = 1;
	SetConsoleCursorPosition(h, textforsettings);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Quit";


	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{ // пройтись по всем событиям
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X; // запомнить координаты мышки
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


			if (c.X >= 2 && c.X <= 8 && c.Y >= 0 && c.Y <= 1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // если нажата ЛЕВАЯ КНОПКА МЫШКИ
				SetConsoleCursorPosition(h, c); // установка координат в то место, где курсор
				system("cls");
				main();
			}
			else if (c.X >= 20 && c.X <= 32 && c.Y >= 3 && c.Y <= 3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // если нажата ЛЕВАЯ КНОПКА МЫШКИ
				countclickvolume++;
				if (countclickvolume % 2 == 0)
				{
					musictemp = true;
					textforsettings.X = 20;
					textforsettings.Y = 3;
					SetConsoleCursorPosition(h, textforsettings);
					SetConsoleTextAttribute(h, 9);
					std::cout << "Volume : On ";
					PlaySound(TEXT("D:\\C++_gameProject\\MenuSong.wav"), NULL, SND_ASYNC);
				}
				else if (countclickvolume % 2 != 0)
				{
					musictemp = false;
					textforsettings.X = 20;
					textforsettings.Y = 3;
					SetConsoleCursorPosition(h, textforsettings);
					SetConsoleTextAttribute(h, 9);
					std::cout << "Volume : Off";
					PlaySound(NULL, NULL, SND_ASYNC);
				}
			}
			else if (c.X >= 20 && c.X <= 32 && c.Y >= 5 && c.Y <= 5 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				countclicktheme++;
				if (countclicktheme == 3)
				{
					countclicktheme = 0;
				}


				if (countclicktheme == 0)
				{
					textforsettings.X = 20;
					textforsettings.Y = 5;
					SetConsoleCursorPosition(h, textforsettings);
					SetConsoleTextAttribute(h, 9);
					std::cout << "Theme : Ukrainian      ";
				}
				else if (countclicktheme == 1)
				{
					textforsettings.X = 20;
					textforsettings.Y = 5;
					SetConsoleCursorPosition(h, textforsettings);
					SetConsoleTextAttribute(h, 9);
					std::cout << "Theme : Russian        ";
				}
				else if (countclicktheme == 2)
				{
					textforsettings.X = 20;
					textforsettings.Y = 5;
					SetConsoleCursorPosition(h, textforsettings);
					SetConsoleTextAttribute(h, 9);
					std::cout << "Theme : Black and white";
				}
			}
			else if (c.X >= 20 && c.X <= 32 && c.Y >= 7 && c.Y <= 7 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				countclicklanguage++;
				if (countclicklanguage == 3)
				{
					countclicklanguage = 0;
				}

				
				if (countclicklanguage == 0)
				{
					textforsettings.X = 20;
					textforsettings.Y = 7;
					SetConsoleCursorPosition(h, textforsettings);
					SetConsoleTextAttribute(h, 9);
					std::cout << "Language : English   ";
				}
				else if (countclicklanguage == 1)
				{
					textforsettings.X = 20;
					textforsettings.Y = 7;
					SetConsoleCursorPosition(h, textforsettings);
					SetConsoleTextAttribute(h, 9);
					std::cout << "Language : Русский   ";
				}
				else if (countclicklanguage == 2)
				{
					textforsettings.X = 20;
					textforsettings.Y = 7;
					SetConsoleCursorPosition(h, textforsettings);
					SetConsoleTextAttribute(h, 9);
					std::cout << "Language : Українська";
				}
			}
			else if (c.X >= 20 && c.X <= 32 && c.Y >= 9 && c.Y <= 9 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				countclicksize++;
				if (countclicksize == 2)
				{
					countclicksize = 0;
				}


				if (countclicksize == 0)
				{
					textforsettings.X = 20;
					textforsettings.Y = 9;
					SetConsoleCursorPosition(h, textforsettings);
					SetConsoleTextAttribute(h, 9);
					std::cout << "Font size : 72";
				}
				else if (countclicksize == 1)
				{
					textforsettings.X = 20;
					textforsettings.Y = 9;
					SetConsoleCursorPosition(h, textforsettings);
					SetConsoleTextAttribute(h, 9);
					std::cout << "Font size : 36";
				}
			}


			if (musictemp)
			{
				if (c.X >= 20 && c.X <= 32 && c.Y == 3)
				{
					SetConsoleTextAttribute(h, 14);
					c.X = 20;
					c.Y = 3;
					SetConsoleCursorPosition(h, c);
					std::cout << "Volume : On";
				}
				else if (c.Y >= 3 || c.Y <= 3 || c.X > 32 || c.X < 20)
				{
					SetConsoleTextAttribute(h, 9);
					c.X = 20;
					c.Y = 3;
					SetConsoleCursorPosition(h, c);
					std::cout << "Volume : On";
				}
			}
			else 
			{
				if (c.X >= 20 && c.X <= 32 && c.Y == 3)
				{
					SetConsoleTextAttribute(h, 14);
					c.X = 20;
					c.Y = 3;
					SetConsoleCursorPosition(h, c);
					std::cout << "Volume : Off";
				}
				else if (c.Y >= 3 || c.Y <= 3 || c.X > 32 || c.X < 20)
				{
					SetConsoleTextAttribute(h, 9);
					c.X = 20;
					c.Y = 3;
					SetConsoleCursorPosition(h, c);
					std::cout << "Volume : Off";
				}
			}


			if (countclicktheme == 0)
			{
				if (c.X >= 20 && c.X <= 32 && c.Y == 5)
				{
					SetConsoleTextAttribute(h, 14);
					c.X = 20;
					c.Y = 5;
					SetConsoleCursorPosition(h, c);
					std::cout << "Theme : Ukrainian";
				}
				else if (c.Y >= 5 || c.Y <= 5 || c.X > 32 || c.X < 20)
				{
					SetConsoleTextAttribute(h, 9);
					c.X = 20;
					c.Y = 5;
					SetConsoleCursorPosition(h, c);
					std::cout << "Theme : Ukrainian";
				}
			}
			else if (countclicktheme == 1)
			{
				if (c.X >= 20 && c.X <= 32 && c.Y == 5)
				{
					SetConsoleTextAttribute(h, 14);
					c.X = 20;
					c.Y = 5;
					SetConsoleCursorPosition(h, c);
					std::cout << "Theme : Russian";
				}
				else if (c.Y >= 5 || c.Y <= 5 || c.X > 32 || c.X < 20)
				{
					SetConsoleTextAttribute(h, 9);
					c.X = 20;
					c.Y = 5;
					SetConsoleCursorPosition(h, c);
					std::cout << "Theme : Russian";
				}
			}
			else if (countclicktheme == 2)
			{
				if (c.X >= 20 && c.X <= 32 && c.Y == 5)
				{
					SetConsoleTextAttribute(h, 14);
					c.X = 20;
					c.Y = 5;
					SetConsoleCursorPosition(h, c);
					std::cout << "Theme : Black and white";
				}
				else if (c.Y >= 5 || c.Y <= 5 || c.X > 32 || c.X < 20)
				{
					SetConsoleTextAttribute(h, 9);
					c.X = 20;
					c.Y = 5;
					SetConsoleCursorPosition(h, c);
					std::cout << "Theme : Black and white";
				}
			}
				

			if (countclicklanguage == 0)
			{
				if (c.X >= 20 && c.X <= 32 && c.Y == 7)
				{
					SetConsoleTextAttribute(h, 14);
					c.X = 20;
					c.Y = 7;
					SetConsoleCursorPosition(h, c);
					std::cout << "Language : English   ";
				}
				else if (c.Y >= 7 || c.Y <= 7 || c.X > 32 || c.X < 20)
				{
					SetConsoleTextAttribute(h, 9);
					c.X = 20;
					c.Y = 7;
					SetConsoleCursorPosition(h, c);
					std::cout << "Language : English   ";
				}
			}
			else if (countclicklanguage == 1)
			{
				if (c.X >= 20 && c.X <= 32 && c.Y == 7)
				{
					SetConsoleTextAttribute(h, 14);
					c.X = 20;
					c.Y = 7;
					SetConsoleCursorPosition(h, c);
					std::cout << "Language : Русский   ";
				}
				else if (c.Y >= 7 || c.Y <= 7 || c.X > 32 || c.X < 20)
				{
					SetConsoleTextAttribute(h, 9);
					c.X = 20;
					c.Y = 7;
					SetConsoleCursorPosition(h, c);
					std::cout << "Language : Русский   ";
				}
			}
			else if (countclicklanguage == 2)
			{
				if (c.X >= 20 && c.X <= 32 && c.Y == 7)
				{
					SetConsoleTextAttribute(h, 14);
					c.X = 20;
					c.Y = 7;
					SetConsoleCursorPosition(h, c);
					std::cout << "Language : Українська";
				}
				else if (c.Y >= 7 || c.Y <= 7 || c.X > 32 || c.X < 20)
				{
					SetConsoleTextAttribute(h, 9);
					c.X = 20;
					c.Y = 7;
					SetConsoleCursorPosition(h, c);
					std::cout << "Language : Українська";
				}
			}
			

			if (countclicksize == 0)
			{
				if (c.X >= 20 && c.X <= 32 && c.Y == 9)
				{
					SetConsoleTextAttribute(h, 14);
					c.X = 20;
					c.Y = 9;
					SetConsoleCursorPosition(h, c);
					std::cout << "Font size : 72";
				}
				else if (c.Y >= 9 || c.Y <= 9 || c.X > 32 || c.X < 20)
				{
					SetConsoleTextAttribute(h, 9);
					c.X = 20;
					c.Y = 9;
					SetConsoleCursorPosition(h, c);
					std::cout << "Font size : 72";
				}
			}
			else if (countclicksize == 1)
			{
				if (c.X >= 20 && c.X <= 32 && c.Y == 9)
				{
					SetConsoleTextAttribute(h, 14);
					c.X = 20;
					c.Y = 9;
					SetConsoleCursorPosition(h, c);
					std::cout << "Font size : 36";
				}
				else if (c.Y >= 9 || c.Y <= 9 || c.X > 32 || c.X < 20)
				{
					SetConsoleTextAttribute(h, 9);
					c.X = 20;
					c.Y = 9;
					SetConsoleCursorPosition(h, c);
					std::cout << "Font size : 36";
				}
			}


			if (c.X >= 2 && c.X <= 8 && c.Y == 1)
			{
				SetConsoleTextAttribute(h, 14);
				c.X = 2;
				c.Y = 1;
				SetConsoleCursorPosition(h, c);
				std::cout << "Quit";
			}
			else if (c.Y >= 1 || c.Y <= 1 || c.X > 6 || c.X < 2)
			{
				SetConsoleTextAttribute(h, 12);
				c.X = 2;
				c.Y = 1;
				SetConsoleCursorPosition(h, c);
				std::cout << "Quit";
			}
		}
	}
}


void news()
{
	PlaySound(NULL, NULL, SND_ASYNC);
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);


	SetConsoleTextAttribute(h, 9);
	for (int y = 0; y <= 12; y++)
	{
		for (int x = 0; x < 54; x++)
		{
			if (y == 0 && x >= 7 && x <= 48 || y == 3 && x >= 8 && x <= 47)
			{
				std::cout << "_";
			}
			else if (x == 7 && y >= 0 && y <= 3 || x == 48 && y >= 0 && y <= 3)
			{
				std::cout << "|";
			}
			else
				std::cout << " ";
		}
	std::cout << "\n";
	}


	COORD infobox;
	infobox.X = 2;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Quit";


	infobox.X = 8;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "Do you want to support us or become our";
		
		
	infobox.X = 8;
	infobox.Y = 2;
	SetConsoleCursorPosition(h, infobox);
	std::cout << " sponsor? ";
	SetConsoleTextAttribute(h, 13);
	std::cout << "Then click on this text.";


	infobox.X = 2;
	infobox.Y = 3;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "13.11";


	SetConsoleTextAttribute(h, 9);
	infobox.X = 4;
	infobox.Y = 4;
	SetConsoleCursorPosition(h, infobox);
	for (int y = 4; y <= 12; y++)
	{
		for (int x = 4; x < 54; x++)
		{
			if (y == 4 && x >= 7 && x <= 48 || y == 7 && x >= 8 && x <= 47)
			{
				std::cout << "_";
			}
			else if (x == 7 && y >= 4 && y <= 7 || x == 48 && y >= 4 && y <= 7)
			{
				std::cout << "|";
			}
			else
				std::cout << " ";
		}
		std::cout << "\n";
		infobox.X = 4;
		infobox.Y++;
		SetConsoleCursorPosition(h, infobox);
	}


	infobox.X = 8;
	infobox.Y = 5;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "Beta version 1.0 is already available!";


	infobox.X = 8;
	infobox.Y = 6;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "Come in and try new features. ";


	SetConsoleTextAttribute(h, 13);
	std::cout << "Patch note";


	infobox.X = 2;
	infobox.Y = 7;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "13.11";
	

	SetConsoleTextAttribute(h, 9);
	infobox.X = 4;
	infobox.Y = 8;
	SetConsoleCursorPosition(h, infobox);
	for (int y = 8; y <= 12; y++)
	{
		for (int x = 4; x < 54; x++)
		{
			if (y == 8 && x >= 7 && x <= 48 || y == 11 && x >= 8 && x <= 47)
			{
				std::cout << "_";
			}
			else if (x == 7 && y >= 4 && y <= 11 || x == 48 && y >= 4 && y <= 11)
			{
				std::cout << "|";
			}
			else
				std::cout << " ";
		}
		std::cout << "\n";
		infobox.X = 4;
		infobox.Y++;
		SetConsoleCursorPosition(h, infobox);
	}


	infobox.X = 8;
	infobox.Y = 9;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "Want to save your progress? Now you can";


	infobox.X = 8;
	infobox.Y = 10;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "register and log into your account!";


	infobox.X = 2;
	infobox.Y = 11;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "22.11";


	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X;
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


			if (c.X >= 2 && c.X <= 6 && c.Y >= 0 && c.Y <= 1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				if (musictemp)
					PlaySound(TEXT("D:\\C++_gameProject\\MenuSong.wav"), NULL, SND_ASYNC);
				system("cls");
				main();
			}
			else if (c.X >= 18 && c.X <= 41 && c.Y >= 2 && c.Y <= 2 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				ShellExecuteW(NULL, L"open", L"https://www.google.com/search?q=%D0%9A%D1%82%D0%BE+%D1%82%D1%8B+%D0%B8%D0%B7+%D0%B1%D1%80%D0%B0%D0%B2%D0%BB+%D1%81%D1%82%D0%B0%D1%80%D1%81+%D0%BF%D0%BE+%D0%BD%D0%BE%D0%BC%D0%B5%D1%80%D1%83+%D0%BA%D0%B0%D1%80%D1%82%D1%8B&source=lnms&tbm=isch&sa=X&ved=2ahUKEwjpoMLMt6v7AhV9SvEDHbeZBhoQ_AUoAXoECAEQAw&biw=1920&bih=937&dpr=1#imgrc=GYjLny6c4Fwd1M", NULL, NULL, SW_SHOW);
			}
			else if (c.X >= 38 && c.X <= 47 && c.Y >= 6 && c.Y <= 6 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				ShellExecuteW(NULL, L"open", L"https://www.leagueoflegends.com/ru-ru/news/game-updates/patch-12-21-notes/", NULL, NULL, SW_SHOW);
			}
		}

	}
}


void losemenu(int time, int killed, int level)
{
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	if (musictemp)
		PlaySound(TEXT("D:\\C++_gameProject\\lose.wav"), NULL, SND_ASYNC);


	COORD infobox;
	infobox.X = 23;
	infobox.Y = 2;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "You lose";


	infobox.X = 17;
	infobox.Y = 5;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "You lasted ";
	SetConsoleTextAttribute(h, 12);
	std::cout << time;
	SetConsoleTextAttribute(h, 14);
	std::cout << " seconds";


	infobox.X = 20;
	infobox.Y = 7;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "Killed ";
	SetConsoleTextAttribute(h, 12);
	std::cout << killed;
	SetConsoleTextAttribute(h, 14);
	if (killed > 1)
		std::cout << " enemies";
	else
		std::cout << " enemy";


	infobox.X = 20;
	infobox.Y = 10;
	SetConsoleTextAttribute(h, 12);
	SetConsoleCursorPosition(h, infobox);
	std::cout << "Retry       Quit"; //Сделать кнопку красивой и всё меню тож


	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X;
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


			if (level == 1)
			{
				if (c.X >= 20 && c.X <= 24 && c.Y == 10 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					level1();
				}
			}
			else if (level == 2)
			{
				if (c.X >= 20 && c.X <= 24 && c.Y == 10 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					level2();
				}
			}
			
			
			if (c.X >= 32 && c.X <= 35 && c.Y == 10 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				levelchoice();
			}
		}
	}
}


void winmenu(int time, int killed, int level)
{
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	if (musictemp)
		PlaySound(TEXT("D:\\C++_gameProject\\win.wav"), NULL, SND_ASYNC);


	COORD infobox;
	infobox.X = 23;
	infobox.Y = 2;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "You win !";


	infobox.X = 17;
	infobox.Y = 5;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "You lasted ";
	SetConsoleTextAttribute(h, 12);
	std::cout << time;
	SetConsoleTextAttribute(h, 14);
	std::cout << " seconds";


	infobox.X = 20;
	infobox.Y = 7;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "Killed ";
	SetConsoleTextAttribute(h, 12);
	std::cout << killed;
	SetConsoleTextAttribute(h, 14);
	if (killed > 1)
		std::cout << " enemies";
	else
		std::cout << " enemy";


	infobox.X = 10;
	infobox.Y = 10;
	SetConsoleTextAttribute(h, 12);
	SetConsoleCursorPosition(h, infobox);
	std::cout << "Retry      Next level      Quit"; //Сделать кнопку красивой и всё меню тож


	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X;
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;

			if (level == 1)
			{
				if (c.X >= 10 && c.X <= 14 && c.Y == 10 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					level1();
				}
				else if (c.X >= 21 && c.X <= 30 && c.Y == 10 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					level2();
				}
			}
			else if (level == 2)
			{
				if (c.X >= 10 && c.X <= 14 && c.Y == 10 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					level2();
				}
				else if (c.X >= 21 && c.X <= 30 && c.Y == 10 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					level3();
				}
			}


			if (c.X >= 37 && c.X <= 40 && c.Y == 10 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				levelchoice();
			}
		}
	}
}


void level1() // первый уровень нажав мышкой в выборе уровня на "Level 1"
{
	PlaySound(NULL, NULL, SND_ASYNC);
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); // установка режима использования мышки
	std::cout << "\n\n";
	SYSTEMTIME time, miltime;
	SYSTEMTIME temp, miltemp;
	GetLocalTime(&temp);
	GetLocalTime(&miltemp);
	int killscount = 10;
	int level = 1, mistcount = 0, timecount = 0, uahcount = 40000, timeforspawn = 0, kindofgun1, kindofgun2, mortarsound = 0, ind = 0;
	bool isput1 = false, isput2 = false, istext = false, isstay1 = false, isstay2 = false, isput3 = false, isstay3 = false;
	int Trapplaces[36][2] = {}; //для записи и проверки, где находиться ежи


	// заполнение массива
	setlocale(LC_ALL, "C");
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 42; x++)
		{
			int stone = rand() % 15; //15
			int bush = rand() % 25; //25
			int grass = rand() % 20; //20


			if (x == 5 || x == 11)
			{
				SetConsoleTextAttribute(h, 15);
				if (y > 1 && y <= 5)
				{
					std::cout << char(1971);
				}
				else if (y > 1 && y <= 6 && x != 5)
				{
					std::cout << char(1984);
				}
				else if (x == 5 && y > 4 && y <= 8)
				{
					std::cout << char(1971);
				}
				else if (x == 5 && y > 4 && y <= 9)
				{
					std::cout << char(1984);
				}
			}
			else if (x > 5 && x < 45 && y > 5)
			{
				SetConsoleTextAttribute(h, 15);
				if (y == 9)
				{
					std::cout << char(1988);
				}
				else if (y == 6 && x > 10 && x <= 40)
				{
					std::cout << char(1988);
				}
				else
				{
					std::cout << " ";
				}
			}
			//разметка башен, !потом заменить на сами башни!

			else if (x > 15 && x < 18 && y == 3)
			{
				SetConsoleTextAttribute(h, 15);
				std::cout << "_"; // башня 1
			}
			else if (x == 15 && y == 4)
			{
				SetConsoleTextAttribute(h, 15);
				std::cout << "|";
			}
			else if (x > 15 && x < 18 && y == 4)
			{
				SetConsoleTextAttribute(h, 15);
				std::cout << "_";
			}
			else if (x == 18 && y == 4)
			{
				SetConsoleTextAttribute(h, 15);
				std::cout << "|";
			}
			else if (x > 27 && x < 30 && y == 3)
			{
				SetConsoleTextAttribute(h, 15);
				std::cout << "_"; // башня 2
			}
			else if (x == 27 && y == 4)
			{
				SetConsoleTextAttribute(h, 15);
				std::cout << "|";
			}
			else if (x > 27 && x < 30 && y == 4)
			{
				std::cout << "_";
			}
			else if (x == 30 && y == 4)
			{
				SetConsoleTextAttribute(h, 15);
				std::cout << "|";
			}
			else if (stone == 1 && y > 1)
			{
				SetConsoleTextAttribute(h, 7);
				std::cout << ".";
			}
			else if (bush == 1 && y > 1)
			{
				SetConsoleTextAttribute(h, 2);
				std::cout << "*";
			}
			else if (grass == 1 && y > 1)
			{
				SetConsoleTextAttribute(h, 10);
				std::cout << "\"";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
	setlocale(LC_ALL, "Russian");


	struct russkiy
	{
		int russians0;
		bool iscan0;
		bool iskilled0;
		bool isactive0;
		bool isshoot0;
	};


	int russians[10] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 500}; //хп врагов
	bool iscan[10] = {true, true, true, true, true, true, true, true, true, true}; //можно ли удалить врагов
	bool iskilled[10] = { true, true, true, true, true, true, true, true, true, true }; //можно ли убавлять здоровье и засчитать при убийстве за килл
	bool isactive[10] = { true, false, false, false, false, false, false, false, false, false };
	bool isshoot[4] = { true, true, true, true };
	COORD russiansenemy[10];


	for (int i = 0; i < 10; i++) // иниацилизация массива врагов
	{
		russiansenemy[i].X = 8;
		russiansenemy[i].Y = 4;
		if (i == 0)
		{
			SetConsoleCursorPosition(h, russiansenemy[i]);
			SetConsoleTextAttribute(h, 12);
			std::cout << (char)1;
		}
	}


	// информация по всем показателям
	COORD infobox;
	infobox.X = 2;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Quit";


	infobox.X = 19;
	infobox.Y = 0;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 9);
	std::cout << " Level 1:Kharkiv\n";


	infobox.X = 26;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "For win:eliminate all enemies \n";


	infobox.X = 26;
	infobox.Y = 2;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "UAH:";
	SetConsoleTextAttribute(h, 12);
	std::cout << uahcount;


	infobox.X = 40;
	infobox.Y = 2;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "Left to kill:";
	SetConsoleTextAttribute(h, 12);
	std::cout << killscount;
	SetConsoleTextAttribute(h, 14);
	std::cout << "\n________________________________________________________";


	for (int i = 4; i < 13; i++)
	{
		infobox.X = 41;
		infobox.Y = i;
		SetConsoleCursorPosition(h, infobox);
		std::cout << "|\n";
	}


	infobox.X = 42;
	infobox.Y = 4;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 9);
	std::cout << "Machine gun";
	infobox.X = 42;
	infobox.Y = 5;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "buy:20000 UAH";


	infobox.X = 42;
	infobox.Y = 6;
	SetConsoleTextAttribute(h, 14);
	SetConsoleCursorPosition(h, infobox);
	std::cout << "______________";

									
	infobox.X = 42;
	infobox.Y = 7;
	SetConsoleTextAttribute(h, 9);
	SetConsoleCursorPosition(h, infobox);
	std::cout << "Mortar";
	infobox.X = 42;
	infobox.Y = 8;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "buy:40000 UAH";


	infobox.X = 42;
	infobox.Y = 9;
	SetConsoleTextAttribute(h, 14);
	SetConsoleCursorPosition(h, infobox);
	std::cout << "______________";


	infobox.X = 42;
	infobox.Y = 10;
	SetConsoleTextAttribute(h, 9);
	SetConsoleCursorPosition(h, infobox);
	std::cout << "Trap";
	infobox.X = 42;
	infobox.Y = 11;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "buy:5000 UAH";


	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{ // пройтись по всем событиям
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X; // запомнить координаты мышки
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;



			//СДЕЛАТЬ ЧТОБЫ ПРИ ВЫБОРЕ ОРУЖИЯ БЫЛО ОБВЕДЕНО КРАСНЫМ КУДА МОЖНО СТАВИТЬ !!!



			GetLocalTime(&time);
			GetLocalTime(&miltime);
			if (c.X >= 2 && c.X <= 8 && c.Y >= 0 && c.Y <= 1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // если нажата ЛЕВАЯ КНОПКА МЫШКИ
				if (musictemp)
					PlaySound(TEXT("D:\\C++_gameProject\\MenuSong.wav"), NULL, SND_ASYNC);
				system("cls");
				levelchoice();


				/*infobox.Y = 2;
				infobox.X = 9;
				SetConsoleTextAttribute(h, 12);


				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 38; j++)
					{
						SetConsoleCursorPosition(h, infobox);
						if (infobox.Y == 2 || infobox.Y == 10)
							std::cout << "_";
						else if (infobox.X == 9 || infobox.X == 46)
							std::cout << "|";
						else
							std::cout << " ";


						infobox.X++;
					}
					infobox.Y++;
					infobox.X = 9;
				}
				infobox.Y = 4;
				infobox.X = 17;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "Do you want to leave?";


				infobox.Y = 6;
				infobox.X = 16;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "Progress at this level";



				infobox.Y = 7;
				infobox.X = 18;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "will not be saved!";


				infobox.Y = 9;
				infobox.X = 21;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "Yes        No";

				while (true)
				{
					ReadConsoleInput(hin, all_events, events_count, &read_event);
					c.X = all_events[i].Event.MouseEvent.dwMousePosition.X; // запомнить координаты мышки
					c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


					if (c.X >= 21 && c.X <= 23 && c.Y == 9 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					{
						if (musictemp)
							PlaySound(TEXT("D:\\C++_gameProject\\MenuSong.wav"), NULL, SND_ASYNC);
						system("cls");
						levelchoice();
					}
					else if (c.X >= 31 && c.X <= 32 && c.Y == 9 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					{

						break;
					}
				}*/
			}
			else if (c.X >= 42 && c.X <= 54 && c.Y >= 4 && c.Y <= 6 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ //при нажатии в выборе на пушку
				infobox.X = 42;
				infobox.Y = 4;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 14);
				std::cout << "Machine gun";
				infobox.X = 42;
				infobox.Y = 5;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:20000 UAH";
				isput1 = true;
			}
			else if (c.X >= 27 && c.X <= 30 && c.Y >= 5 && c.Y <= 7 && isput1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке пушки на второе место
				if (uahcount < 20000)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 20000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					kindofgun2 = 1;
					SetConsoleTextAttribute(h, 7);
					infobox.X = 26;
					infobox.Y = 5;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "--d ";
					infobox.X = 27;
					infobox.Y = 6;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "/'\\ ";
					isstay2 = true;
				}


				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)  
					std::cout << uahcount << "    ";              
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";


				infobox.X = 42;
				infobox.Y = 4;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Machine gun";
				infobox.X = 42;
				infobox.Y = 5;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:20000 UAH";
				isput1 = false;
			}
			else if (c.X >= 14 && c.X <= 17 && c.Y >= 5 && c.Y <= 7 && isput1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке пушки на первое место
				if (uahcount < 20000)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 20000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					kindofgun1 = 1;
					SetConsoleTextAttribute(h, 7);
					infobox.X = 14;
					infobox.Y = 5;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "--d ";
					infobox.X = 15;
					infobox.Y = 6;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "/'\\ ";
					isstay1 = true;
				}


				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)  // СДЕЛАТЬ ТАК ВО ВСЕХ МЕСТАХ ГДЕ МЕНЯЕТЬСЯ uahcount
					std::cout << uahcount << "    ";              // И ЕСЛИ НЕДОСТАТОЧНО ДЕНЕГ ДЛЯ ПОКУПКИ, ТО НАПИСАТЬ ЧТО НЕ ХВАТАЕТ ДЕНЕГ И НЕ ОТНИМАТЬ ИХ В МИНУС !
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";


				infobox.X = 42;
				infobox.Y = 4;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Machine gun";
				infobox.X = 42;
				infobox.Y = 5;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:20000 UAH";
				isput1 = false;
			}
			else if ((c.X < 27 || c.X > 30 || c.Y < 6 || c.Y > 6) && isput1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // Если промахнулся то убирает выделение
				infobox.X = 42;
				infobox.Y = 4;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Machine gun";
				infobox.X = 42;
				infobox.Y = 5;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:20000 UAH";


				isput1 = false;
				mistcount++;
				if (mistcount >= 3)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << " Can't put here "; 
					istext = true;
					mistcount = 0;
				}
			}


			else if (c.X >= 42 && c.X <= 54 && c.Y >= 7 && c.Y <= 9 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ //при нажатии в выборе на мортиру
				infobox.X = 42;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 14);
				std::cout << "Mortar";
				infobox.X = 42;
				infobox.Y = 8;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:40000 UAH";
				isput2 = true;
			}
			else if (c.X >= 27 && c.X <= 30 && c.Y >= 5 && c.Y <= 7 && isput2 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке мортиры на второе место
				if (uahcount < 40000)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 40000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					kindofgun2 = 2;
					SetConsoleTextAttribute(h, 7);
					infobox.X = 26;
					infobox.Y = 5;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "\"\\\\ ";
					infobox.X = 27;
					infobox.Y = 6;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "/\\\\ ";
					isstay2 = true;
				}


				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";


				infobox.X = 42;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Mortar";
				infobox.X = 42;
				infobox.Y = 8;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:40000 UAH";
				isput2 = false;
			}
			else if (c.X >= 14 && c.X <= 17 && c.Y >= 5 && c.Y <= 7 && isput2 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке мортиры на первое место
				if (uahcount < 40000)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 40000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					kindofgun1 = 2;
					SetConsoleTextAttribute(h, 7);
					infobox.X = 14;
					infobox.Y = 5;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "\"\\\\ ";
					infobox.X = 15;
					infobox.Y = 6;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "/\\\\ ";
					isstay1 = true;
				}


				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";


				infobox.X = 42;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Mortar";
				infobox.X = 42;
				infobox.Y = 8;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:40000 UAH";
				isput2 = false;
			}
			else if ((c.X < 27 || c.X > 30 || c.Y < 6 || c.Y > 6) && isput2 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // Если промахнулся то убирает выделение
				infobox.X = 42;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Mortar";
				infobox.X = 42;
				infobox.Y = 8;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:40000 UAH";


				isput2 = false;
				mistcount++;
				if (mistcount >= 3)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << " Can't put here ";
					istext = true;
					mistcount = 0;
				}
			}


			else if (c.X >= 42 && c.X <= 54 && c.Y >= 10 && c.Y <= 12 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ //при нажатии в выборе на ежа
				infobox.X = 42;
				infobox.Y = 10;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 14);
				std::cout << "Trap";
				infobox.X = 42;
				infobox.Y = 11;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:5000 UAH";
				isput3 = true;
			}

			else if (c.X >= 8 && c.X <= 8 && c.Y >= 6 && c.Y <= 10 && isput3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED ||
			c.X >= 8 && c.X <= 38 && c.Y >= 10 && c.Y <= 10 && isput3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке ежа
				if (uahcount < 5000)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 5000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					SetConsoleTextAttribute(h, 7);
					infobox.X = c.X;
					infobox.Y = c.Y;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "X";
					Trapplaces[ind][0] = c.X;
					Trapplaces[ind][1] = c.Y;
					ind++;
					isstay3 = true;
				}


				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";


				infobox.X = 42;
				infobox.Y = 10;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Trap";
				infobox.X = 42;
				infobox.Y = 11;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:5000 UAH";
				isput3 = false;
			}
			else if ((c.X < 27 || c.X > 30 || c.Y < 6 || c.Y > 6) && isput3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // Если промахнулся то убирает выделение
				infobox.X = 42;
				infobox.Y = 10;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Trap";
				infobox.X = 42;
				infobox.Y = 11;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:5000 UAH";
			

				isput3 = false;
				mistcount++;
				if (mistcount >= 3)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << " Can't put here ";
					istext = true;
					mistcount = 0;
				}
			}
			

			else if (c.X >= 2 && c.X <= 8 && c.Y == 1)
			{
				SetConsoleTextAttribute(h, 14);
				c.X = 2;
				c.Y = 1;
				SetConsoleCursorPosition(h, c);
				std::cout << "Quit";
			}
			else if (c.Y > 1 || c.Y < 1 || c.X > 6 || c.X < 2)
			{
				SetConsoleTextAttribute(h, 12);
				c.X = 2;
				c.Y = 1;
				SetConsoleCursorPosition(h, c);
				std::cout << "Quit";
			}


			if (isstay1) // стоит ли оружие на первой позиции
			{
				if (kindofgun1 == 1)
				{
					isshoot[0] = true; // для обновления разрешения на стрельбу
					for (int i = 0; i < 10; i++)
					{
						if (russiansenemy[i].Y > 4 && russiansenemy[i].X < 23 && iskilled[i] && isactive[i] && isshoot[0]) // находиться ли враг в зоне действия оружия
						{
							if (miltime.wMilliseconds > miltemp.wMilliseconds + 10)
							{
								infobox.X = 13;
								infobox.Y = 5;
								SetConsoleCursorPosition(h, infobox);
								SetConsoleTextAttribute(h, 7);
								std::cout << "*";
							}
							else if (temp.wSecond == time.wSecond)
							{
								GetLocalTime(&miltemp);
								infobox.X = 13;
								infobox.Y = 5;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}


							if (temp.wSecond < time.wSecond) // сносит урон раз в секунду
							{
								russians[i] -= 12;
								isshoot[0] = false;
								if (russians[i] <= 0)
								{
									killscount--;
									infobox.X = 40;  // обновляет счётчик при убийстве
									infobox.Y = 2;
									SetConsoleCursorPosition(h, infobox);
									SetConsoleTextAttribute(h, 14);
									std::cout << "Left to kill:";
									SetConsoleTextAttribute(h, 12);
									if (killscount < 10)
									{
										std::cout << "0" << killscount;
									}
									iskilled[i] = false;
								}


								if (musictemp)
									PlaySound(TEXT("D:\\C++_gameProject\\machinegun.wav"), NULL, SND_ASYNC);
							}


							if (russiansenemy[i].X == 22 || iskilled[i] == false)
							{
								GetLocalTime(&miltemp);
								infobox.X = 13;
								infobox.Y = 5;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}
						}
					}
				}
				else if (kindofgun1 == 2)
				{
					isshoot[1] = true; // для обновления разрешения на стрельбу
					for (int i = 0; i < 10; i++)
					{
						if (russiansenemy[i].Y > 4 && russiansenemy[i].X < 41 && iskilled[i] && isactive[i] && isshoot[1]) // находиться ли враг в зоне действия оружия
						{
							if (miltime.wMilliseconds > miltemp.wMilliseconds + 20) // звёздочка стреляющая из пушки на первом месте
							{
								infobox.X = 15;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								SetConsoleTextAttribute(h, 7);
								std::cout << "*";
							}
							else if (temp.wSecond == time.wSecond)
							{
								GetLocalTime(&miltemp);
								infobox.X = 15;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}


							if (temp.wSecond < time.wSecond) // сносит урон раз в секунду
							{
								russians[i] -= 20;
								isshoot[1] = false;
								if (russians[i] <= 0)
								{
									killscount--;
									infobox.X = 40;  // обновляет счётчик при убийстве
									infobox.Y = 2;
									SetConsoleCursorPosition(h, infobox);
									SetConsoleTextAttribute(h, 14);
									std::cout << "Left to kill:";
									SetConsoleTextAttribute(h, 12);
									if (killscount < 10)
									{
										std::cout << "0" << killscount;
									}
									iskilled[i] = false;
								}
								mortarsound++;
								if (mortarsound % 2 == 0) // Каждую вторую секунду должен быть звук выстрела
								{
									if (musictemp)
										PlaySound(TEXT("D:\\C++_gameProject\\mortira.wav"), NULL, SND_ASYNC);
								}
							}


							if (russiansenemy[i].X == 22 || iskilled[i] == false) // убрать звёздочку если враг ушёл с диапозона поражения или умер
							{
								GetLocalTime(&miltemp);
								infobox.X = 15;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}
						}
					}
				}
			}
			
			
			if (isstay2)
			{
				if (kindofgun2 == 1)
				{ 
					isshoot[2] = true; // для обновления разрешения на стрельбу
					for (int i = 0; i < 10; i++)
					{
						if (russiansenemy[i].Y > 6 && russiansenemy[i].X > 22 && iskilled[i] && isactive[i] && isshoot[2]) // находиться ли враг в зоне действия оружия
						{
							if (miltime.wMilliseconds > miltemp.wMilliseconds + 10) // звёздочка стреляющая из пушки на первом месте
							{
								infobox.X = 25;
								infobox.Y = 5;
								SetConsoleCursorPosition(h, infobox);
								SetConsoleTextAttribute(h, 7);
								std::cout << "*";
							}
							else if (temp.wSecond == time.wSecond)
							{
								GetLocalTime(&miltemp);
								infobox.X = 25;
								infobox.Y = 5;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}


							if (temp.wSecond < time.wSecond) // сносит урон раз в секунду
							{
								russians[i] -= 12;
								isshoot[2] = false;
								if (russians[i] <= 0)
								{
									killscount--;
									infobox.X = 40;  // обновляет счётчик при убийстве
									infobox.Y = 2;
									SetConsoleCursorPosition(h, infobox);
									SetConsoleTextAttribute(h, 14);
									std::cout << "Left to kill:";
									SetConsoleTextAttribute(h, 12);
									if (killscount < 10)
									{
										std::cout << "0" << killscount;
									}
									iskilled[i] = false;
								}
								if (musictemp)
									PlaySound(TEXT("D:\\C++_gameProject\\machinegun.wav"), NULL, SND_ASYNC);
							}


							if (iskilled[i] == false) // убрать звёздочку если враг ушёл с диапозона поражения или умер
							{
								GetLocalTime(&miltemp);
								infobox.X = 25;
								infobox.Y = 5;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}
						}
					}
				}
				else if (kindofgun2 == 2)
				{
					isshoot[3] = true; // для обновления разрешения на стрельбу
					for (int i = 0; i < 10; i++)
					{
						if (russiansenemy[i].Y > 4 && russiansenemy[i].X < 41 && iskilled[i] && isactive[i] && isshoot[3]) // находиться ли враг в зоне действия оружия
						{
							if (miltime.wMilliseconds > miltemp.wMilliseconds + 10) // звёздочка стреляющая из пушки на первом месте
							{
								infobox.X = 27;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								SetConsoleTextAttribute(h, 7);
								std::cout << "*";
							}
							else if (temp.wSecond == time.wSecond)
							{
								GetLocalTime(&miltemp);
								infobox.X = 27;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}


							if (temp.wSecond < time.wSecond) // сносит урон раз в секунду
							{
								russians[i] -= 20;
								isshoot[3] = false;
								if (russians[i] <= 0)
								{
									killscount--;
									infobox.X = 40;  // обновляет счётчик при убийстве
									infobox.Y = 2;
									SetConsoleCursorPosition(h, infobox);
									SetConsoleTextAttribute(h, 14);
									std::cout << "Left to kill:";
									SetConsoleTextAttribute(h, 12);
									if (killscount < 10)
									{
										std::cout << "0" << killscount;
									}
									iskilled[i] = false;
								}
								mortarsound++;
								if (mortarsound % 2 == 0) // Каждую вторую секунду должен быть звук выстрела
								{
									if (musictemp)
										PlaySound(TEXT("D:\\C++_gameProject\\mortira.wav"), NULL, SND_ASYNC);
								}
							}


							if (iskilled[i] == false) // убрать звёздочку если враг ушёл с диапозона поражения или умер
							{
								GetLocalTime(&miltemp);
								infobox.X = 27;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}
						}
					}
				}
			}


			if (isstay3) // почему отдельная проверка от пушек на ловушки ? Потому что если бы проверка была б в isstay1 и isstay2 и на поле не было б пушек то ёж бы не работал, хотя с точки зрения оптимизации кода так лучше(
			{
				for (int i = 0; i < 36; i++) 
				{
					for (int j = 0; j < 10; j++)
					{
						if (Trapplaces[i][0] == russiansenemy[j].X && Trapplaces[i][1] == russiansenemy[j].Y)
						{
							russians[j] -= 50;
							Trapplaces[i][0] = 0;
							Trapplaces[i][1] = 0;
							if (musictemp)
								PlaySound(TEXT("D:\\C++_gameProject\\trap.wav"), NULL, SND_ASYNC);
						}
					}
				}


				for (int i = 0; i < 10; i++)
				{
					if (russians[i] <= 0 && iskilled[i])
					{
						killscount--;
						infobox.X = 40;  // обновляет счётчик при убийстве
						infobox.Y = 2;
						SetConsoleCursorPosition(h, infobox);
						SetConsoleTextAttribute(h, 14);
						std::cout << "Left to kill:";
						SetConsoleTextAttribute(h, 12);
						if (killscount < 10)
						{
							std::cout << "0" << killscount;
						}
						iskilled[i] = false;
					}
				}
			}


			if (temp.wSecond < time.wSecond) // temp.wSecond + 1 < time.wSecond - добавит ещё секунду к ожиданию
			{
				timeforspawn++;
				GetLocalTime(&temp);
				SetConsoleTextAttribute(h, 12);


				for (int i = 0; i < 10; i++)
				{
					if (russiansenemy[i].Y <= 9 && russians[i] > 0 && isactive[i]) //движения врага
					{
						SetConsoleCursorPosition(h, russiansenemy[i]);
						std::cout << " ";
						russiansenemy[i].Y++;
						SetConsoleCursorPosition(h, russiansenemy[i]);
						if (i == 9)
							std::cout << char(2);
						else
							std::cout << char(1);
					}
					else if (russiansenemy[i].X <= 39 && russians[i] > 0 && isactive[i]) //движения врага
					{
						SetConsoleCursorPosition(h, russiansenemy[i]);
						std::cout << " ";
						russiansenemy[i].X++;
						SetConsoleCursorPosition(h, russiansenemy[i]);
						if (i == 9)
							std::cout << char(2);
						else
							std::cout << char(1);
					}
					else if (russians[i] <= 0 && iscan[i] && isactive[i]) // только для удаления врага
					{
						uahcount += 5000;
						infobox.X = 30;
						infobox.Y = 2;
						SetConsoleCursorPosition(h, infobox);
						SetConsoleTextAttribute(h, 12);
						std::cout << uahcount;


						SetConsoleCursorPosition(h, russiansenemy[i]);
						std::cout << " ";
						if (musictemp)
							PlaySound(TEXT("D:\\C++_gameProject\\kill.wav"), NULL, SND_ASYNC);
						iscan[i] = false;
						isactive[i] = false;
					}
				}


				if (istext) // текст предупреждающий писать три секунды
				{
					timecount++;
					if (timecount >= 3)
					{
						infobox.X = 15;
						infobox.Y = 7;
						SetConsoleCursorPosition(h, infobox);
						std::cout << "                ";
						timecount = 0;
						istext = false;
					}
				}
			}
			else if (temp.wSecond == 59)
			{
				GetLocalTime(&temp);
			}


			if (timeforspawn == 5) // Если с начала боя прошло 5 секунд то спавниться следующий враг
			{
				isactive[1] = true;
				SetConsoleCursorPosition(h, russiansenemy[1]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 10)
			{
				isactive[2] = true;
				SetConsoleCursorPosition(h, russiansenemy[2]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 15)
			{
				isactive[3] = true;
				SetConsoleCursorPosition(h, russiansenemy[3]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 20)
			{
				isactive[4] = true;
				SetConsoleCursorPosition(h, russiansenemy[4]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 25)
			{
				isactive[5] = true;
				SetConsoleCursorPosition(h, russiansenemy[5]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 30)
			{
				isactive[6] = true;
				SetConsoleCursorPosition(h, russiansenemy[6]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 35)
			{
				isactive[7] = true;
				SetConsoleCursorPosition(h, russiansenemy[7]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 40)
			{
				isactive[8] = true;
				SetConsoleCursorPosition(h, russiansenemy[8]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 45)
			{
				isactive[9] = true;
				SetConsoleCursorPosition(h, russiansenemy[9]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			if (timeforspawn >= 45 && timeforspawn <= 48)
			{
				infobox.X = 16;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 12);
				if (timeforspawn == 48)
				{
					std::cout << "                    ";
				}
				else if (timeforspawn == 45)
				{
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\boss.wav"), NULL, SND_ASYNC);
					std::cout << "Lieutenant is coming";
				}
			}


			if (killscount == 0) // если победил то
			{
				if (levelcap < 2)
				{
					levelcap = 2;
				}
				winmenu(timeforspawn, 10 - killscount, level);
			}
			else
			{ //если проиграл то
				for (int i = 0; i < 10; i++)
				{
					if (russiansenemy[i].X == 40)
						losemenu(timeforspawn, 10 - killscount, level);
				}
				
			}
		}
	}
}


void level2()
{
	PlaySound(NULL, NULL, SND_ASYNC);
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); // установка режима использования мышки
	std::cout << "\n\n";
	SYSTEMTIME timee, miltime;
	SYSTEMTIME temp, miltemp;
	GetLocalTime(&temp);
	GetLocalTime(&miltemp);
	int killscount = 20;
	int level = 2, mistcount = 0, timecount = 0, uahcount = 40000, timeforspawn = 0, kindofgun1, kindofgun2, mortarsound = 0, ind = 0, upordown[20];
	bool isput1 = false, isput2 = false, istext = false, isstay1 = false, isstay2 = false, isput3 = false, isstay3 = false;
	int Trapplaces[36][2] = {}; //для записи и проверки, где находиться ежи


	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		upordown[i] = rand() % 2;
	}


	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 41; x++) {
			int stone = rand() % 15;
			int bush = rand() % 25;
			int grass = rand() % 20;


			SetConsoleTextAttribute(h, 15);
			if (y == 4 && x >= 0 && x <= 20) {
				std::cout << "_";
			}
			else if (y == 7 && x >= 0 && x <= 20) {
				std::cout << "_";
			}
			else if (x == 21 && y <= 4 && y >= 2) {
				std::cout << char(1971);
			}
			else if (x == 21 && y <= 10 && y >= 8) {
				std::cout << char(1971);
			}
			else if (x >= 22 && x <= 47 && y == 10) {
				std::cout << "_";
			}
			else if (x >= 22 && x <= 47 && y == 1) {
				std::cout << "_";
			}
			else if (x >= 28 && x <= 47 && y == 7) {
				std::cout << "_";
			}
			else if (x >= 28 && x <= 47 && y == 4) {
				std::cout << "_";
			}
			else if (x == 27 && y >= 5 && y <= 7) {
				std::cout << char(1971);
			}

			//разметка башен, !потом заменить на сами башни!

			else if (x > 13 && x < 16 && y == 2)
				std::cout << "_"; // башня 1
			else if (x == 13 && y == 3)
				std::cout << "|";
			else if (x > 13 && x < 16 && y == 3)
				std::cout << "_";
			else if (x == 16 && y == 3)
				std::cout << "|";

			else if (x > 30 && x < 33 && y == 5)
				std::cout << "_"; // башня 2
			else if (x == 30 && y == 6)
				std::cout << "|";
			else if (x > 30 && x < 33 && y == 6)
				std::cout << "_";
			else if (x == 33 && y == 6)
				std::cout << "|";

			else if (x > 13 && x < 16 && y == 8)
				std::cout << "_"; // башня 3
			else if (x == 13 && y == 9)
				std::cout << "|";
			else if (x > 13 && x < 16 && y == 9)
				std::cout << "_";
			else if (x == 16 && y == 9)
				std::cout << "|";


			else if (x >= 3 && x <= 27 && y >= 5 && y <= 6) {
				std::cout << " ";
			}
			else if (x >= 20 && x <= 26 && y >= 2 && y <= 9) {
				std::cout << " ";
			}
			else if (x >= 27 && x <= 47 && y >= 2 && y <= 3) {
				std::cout << " ";
			}
			else if (x >= 27 && x <= 47 && y >= 8 && y <= 9) {
				std::cout << " ";
			}



			else if (stone == 1 && y > 1) {
				SetConsoleTextAttribute(h, 7);
				std::cout << ".";
			}
			else if (bush == 1 && y > 1) {
				SetConsoleTextAttribute(h, 2);
				std::cout << "*";
			}
			else if (grass == 1 && y > 1) {
				SetConsoleTextAttribute(h, 10);
				std::cout << "\"";
			}
			else std::cout << " ";
		}
		std::cout << "\n";
	}


	int russians[20] = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 500, 100, 100, 100, 100, 100, 100, 100, 100, 100, 1000}; //хп врагов
	bool iscan[20] = { true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true }; //можно ли удалить врагов
	bool iskilled[20] = { true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true }; //можно ли убавлять здоровье и засчитать при убийстве за килл
	bool isactive[20] = { true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };
	bool isshoot[4] = { true, true, true, true };
	COORD russiansenemy[20];


	for (int i = 0; i < 20; i++) // иниацилизация массива врагов
	{
		russiansenemy[i].X = 0;
		russiansenemy[i].Y = 8;
		if (i == 0)
		{
			SetConsoleCursorPosition(h, russiansenemy[i]);
			SetConsoleTextAttribute(h, 12);
			std::cout << (char)1;
		}
	}


	// информация по всем показателям
	COORD infobox;
	infobox.X = 2;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Quit";


	infobox.X = 19;
	infobox.Y = 0;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 9);
	std::cout << " Level 2:Kherson";


	infobox.X = 26;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "For win:eliminate all enemies";


	infobox.X = 26;
	infobox.Y = 2;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "UAH:";
	SetConsoleTextAttribute(h, 12);
	std::cout << uahcount;


	infobox.X = 40;
	infobox.Y = 2;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "Left to kill:";
	SetConsoleTextAttribute(h, 12);
	std::cout << killscount;
	SetConsoleTextAttribute(h, 14);
	std::cout << "\n________________________________________________________";


	for (int i = 4; i < 13; i++)
	{
		infobox.X = 41;
		infobox.Y = i;
		SetConsoleCursorPosition(h, infobox);
		std::cout << "|\n";
	}


	infobox.X = 42;
	infobox.Y = 4;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 9);
	std::cout << "Machine gun";
	infobox.X = 42;
	infobox.Y = 5;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "buy:20000 UAH";


	infobox.X = 42;
	infobox.Y = 6;
	SetConsoleTextAttribute(h, 14);
	SetConsoleCursorPosition(h, infobox);
	std::cout << "______________";


	infobox.X = 42;
	infobox.Y = 7;
	SetConsoleTextAttribute(h, 9);
	SetConsoleCursorPosition(h, infobox);
	std::cout << "Mortar";
	infobox.X = 42;
	infobox.Y = 8;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "buy:40000 UAH";


	infobox.X = 42;
	infobox.Y = 9;
	SetConsoleTextAttribute(h, 14);
	SetConsoleCursorPosition(h, infobox);
	std::cout << "______________";


	infobox.X = 42;
	infobox.Y = 10;
	SetConsoleTextAttribute(h, 9);
	SetConsoleCursorPosition(h, infobox);
	std::cout << "Trap";
	infobox.X = 42;
	infobox.Y = 11;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "buy:5000 UAH";


	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{ // пройтись по всем событиям
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X; // запомнить координаты мышки
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


			GetLocalTime(&timee);
			GetLocalTime(&miltime);
			if (c.X >= 2 && c.X <= 8 && c.Y >= 0 && c.Y <= 1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // если нажата ЛЕВАЯ КНОПКА МЫШКИ
				if (musictemp)
					PlaySound(TEXT("D:\\C++_gameProject\\MenuSong.wav"), NULL, SND_ASYNC);
				system("cls");
				levelchoice();
			}
			else if (c.X >= 42 && c.X <= 54 && c.Y >= 4 && c.Y <= 6 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ //при нажатии в выборе на пушку
				infobox.X = 42;
				infobox.Y = 4;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 14);
				std::cout << "Machine gun";
				infobox.X = 42;
				infobox.Y = 5;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:20000 UAH";
				isput1 = true;
			}
			else if (c.X >= 30 && c.X <= 33 && c.Y >= 7 && c.Y <= 9 && isput1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке пушки на второе место
				if (uahcount < 20000)
				{
					infobox.X = 11;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 20000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					kindofgun2 = 1;
					SetConsoleTextAttribute(h, 7);
					infobox.X = 29;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "--d ";
					infobox.X = 30;
					infobox.Y = 8;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "/'\\ ";
					isstay2 = true;
				}


				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";


				infobox.X = 42;
				infobox.Y = 4;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Machine gun";
				infobox.X = 42;
				infobox.Y = 5;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:20000 UAH";
				isput1 = false;
			}
			else if (c.X >= 13 && c.X <= 16 && c.Y >= 4 && c.Y <= 6 && isput1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке пушки на первое место
				if (uahcount < 20000)
				{
					infobox.X = 11;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 20000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					kindofgun1 = 1;
					SetConsoleTextAttribute(h, 7);
					infobox.X = 12;
					infobox.Y = 4;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "--d ";
					infobox.X = 13;
					infobox.Y = 5;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "/'\\ ";
					isstay1 = true;
				}


				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)  
					std::cout << uahcount << "    ";             
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";


				infobox.X = 42;
				infobox.Y = 4;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Machine gun";
				infobox.X = 42;
				infobox.Y = 5;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:20000 UAH";
				isput1 = false;
			}
			else if ((c.X < 27 || c.X > 30 || c.Y < 6 || c.Y > 6) && isput1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // Если промахнулся то убирает выделение
				infobox.X = 42;
				infobox.Y = 4;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Machine gun";
				infobox.X = 42;
				infobox.Y = 5;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:20000 UAH";


				isput1 = false;
				mistcount++;
				if (mistcount >= 3)
				{
					infobox.X = 13;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Can't put here";
					istext = true;
					mistcount = 0;
				}
			}


			else if (c.X >= 42 && c.X <= 54 && c.Y >= 7 && c.Y <= 9 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ //при нажатии в выборе на мортиру
				infobox.X = 42;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 14);
				std::cout << "Mortar";
				infobox.X = 42;
				infobox.Y = 8;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:40000 UAH";
				isput2 = true;
			}
			else if (c.X >= 30 && c.X <= 33 && c.Y >= 7 && c.Y <= 9 && isput2 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке мортиры на второе место
				if (uahcount < 40000)
				{
					infobox.X = 11;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 40000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					kindofgun2 = 2;
					SetConsoleTextAttribute(h, 7);
					infobox.X = 29;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "\"\\\\ ";
					infobox.X = 30;
					infobox.Y = 8;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "/\\\\ ";
					isstay2 = true;
				}


				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";


				infobox.X = 42;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Mortar";
				infobox.X = 42;
				infobox.Y = 8;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:40000 UAH";
				isput2 = false;
			}
			else if (c.X >= 13 && c.X <= 16 && c.Y >= 4 && c.Y <= 6 && isput2 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке мортиры на первое место
				if (uahcount < 40000)
				{
					infobox.X = 11;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 40000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					kindofgun1 = 2;
					SetConsoleTextAttribute(h, 7);
					infobox.X = 12;
					infobox.Y = 4;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "\"\\\\ ";
					infobox.X = 13;
					infobox.Y = 5;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "/\\\\ ";
					isstay1 = true;
				}


				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";


				infobox.X = 42;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Mortar";
				infobox.X = 42;
				infobox.Y = 8;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:40000 UAH";
				isput2 = false;
			}
			else if ((c.X < 27 || c.X > 30 || c.Y < 6 || c.Y > 6) && isput2 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // Если промахнулся то убирает выделение
				infobox.X = 42;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Mortar";
				infobox.X = 42;
				infobox.Y = 8;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:40000 UAH";


				isput2 = false;
				mistcount++;
				if (mistcount >= 3)
				{
					infobox.X = 13;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Can't put here";
					istext = true;
					mistcount = 0;
				}
			}


			else if (c.X >= 42 && c.X <= 54 && c.Y >= 10 && c.Y <= 12 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ //при нажатии в выборе на ежа
				infobox.X = 42;
				infobox.Y = 10;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 14);
				std::cout << "Trap";
				infobox.X = 42;
				infobox.Y = 11;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:5000 UAH";
				isput3 = true;
			}

			else if (c.X >= 2 && c.X <= 24 && c.Y >= 8 && c.Y <= 8 && isput3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED ||
				c.X >= 24 && c.X <= 24 && c.Y >= 8 && c.Y <= 11 && isput3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED ||
				c.X >= 24 && c.X <= 24 && c.Y >= 5 && c.Y <= 8 && isput3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED ||
				c.X >= 24 && c.X <= 38 && c.Y >= 5 && c.Y <= 5 && isput3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED ||
				c.X >= 24 && c.X <= 38 && c.Y >= 11 && c.Y <= 11 && isput3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке ежа
				if (uahcount < 5000)
				{
					infobox.X = 11;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 5000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					SetConsoleTextAttribute(h, 7);
					infobox.X = c.X;
					infobox.Y = c.Y;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "X";
					Trapplaces[ind][0] = c.X;
					Trapplaces[ind][1] = c.Y;
					ind++;
					isstay3 = true;
				}


				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";


				infobox.X = 42;
				infobox.Y = 10;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Trap";
				infobox.X = 42;
				infobox.Y = 11;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:5000 UAH";
				isput3 = false;
			}
			else if ((c.X < 27 || c.X > 30 || c.Y < 6 || c.Y > 6) && isput3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // Если промахнулся то убирает выделение
				infobox.X = 42;
				infobox.Y = 10;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Trap";
				infobox.X = 42;
				infobox.Y = 11;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:5000 UAH";


				isput3 = false;
				mistcount++;
				if (mistcount >= 3)
				{
					infobox.X = 13;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Can't put here";
					istext = true;
					mistcount = 0;
				}
			}


			else if (c.X >= 2 && c.X <= 8 && c.Y == 1)
			{
				SetConsoleTextAttribute(h, 14);
				c.X = 2;
				c.Y = 1;
				SetConsoleCursorPosition(h, c);
				std::cout << "Quit";
			}
			else if (c.Y > 1 || c.Y < 1 || c.X > 6 || c.X < 2)
			{
				SetConsoleTextAttribute(h, 12);
				c.X = 2;
				c.Y = 1;
				SetConsoleCursorPosition(h, c);
				std::cout << "Quit";
			}


			if (isstay1) // стоит ли оружие на первой позиции
			{
				if (kindofgun1 == 1)
				{
					isshoot[0] = true; // для обновления разрешения на стрельбу
					for (int i = 0; i < 20; i++)
					{
						if (russiansenemy[i].X > 1 && russiansenemy[i].X < 26 && russiansenemy[i].Y < 9 && iskilled[i] && isactive[i] && isshoot[0]) // находиться ли враг в зоне действия оружия
						{
							if (miltime.wMilliseconds > miltemp.wMilliseconds + 10)
							{
								infobox.X = 11;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								SetConsoleTextAttribute(h, 7);
								std::cout << "*";
							}
							else if (temp.wSecond == timee.wSecond)
							{
								GetLocalTime(&miltemp);
								infobox.X = 11;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}


							if (temp.wSecond < timee.wSecond) // сносит урон раз в секунду
							{
								russians[i] -= 12;
								isshoot[0] = false;
								if (russians[i] <= 0)
								{
									killscount--;
									infobox.X = 40;  // обновляет счётчик при убийстве
									infobox.Y = 2;
									SetConsoleCursorPosition(h, infobox);
									SetConsoleTextAttribute(h, 14);
									std::cout << "Left to kill:";
									SetConsoleTextAttribute(h, 12);
									if (killscount < 10)
									{
										std::cout << "0" << killscount;
									}
									iskilled[i] = false;
								}


								if (musictemp)
									PlaySound(TEXT("D:\\C++_gameProject\\machinegun.wav"), NULL, SND_ASYNC);
							}


							if (russiansenemy[i].X == 26 || iskilled[i] == false)
							{
								GetLocalTime(&miltemp);
								infobox.X = 11;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}
						}
					}
				}
				else if (kindofgun1 == 2)
				{
					isshoot[1] = true; // для обновления разрешения на стрельбу
					for (int i = 0; i < 20; i++)
					{
						if (russiansenemy[i].X > 1 && iskilled[i] && isactive[i] && isshoot[1]) // находиться ли враг в зоне действия оружия
						{
							if (temp.wSecond < timee.wSecond) // сносит урон раз в секунду
							{
								russians[i] -= 20;
								isshoot[1] = false;
								if (russians[i] <= 0)
								{
									killscount--;
									infobox.X = 40;  // обновляет счётчик при убийстве
									infobox.Y = 2;
									SetConsoleCursorPosition(h, infobox);
									SetConsoleTextAttribute(h, 14);
									std::cout << "Left to kill:";
									SetConsoleTextAttribute(h, 12);
									if (killscount < 10)
									{
										std::cout << "0" << killscount;
									}
									iskilled[i] = false;
								}
								mortarsound++;
								if (mortarsound % 2 == 0) // Каждую вторую секунду должен быть звук выстрела
								{
									if (musictemp)
										PlaySound(TEXT("D:\\C++_gameProject\\mortira.wav"), NULL, SND_ASYNC);
								}
							}
						}
					}
				}
			}


			if (isstay2)
			{
				if (kindofgun2 == 1)
				{
					isshoot[2] = true; // для обновления разрешения на стрельбу
					for (int i = 0; i < 20; i++)
					{
						if (russiansenemy[i].X > 16 && iskilled[i] && isactive[i] && isshoot[2]) // находиться ли враг в зоне действия оружия
						{
							if (miltime.wMilliseconds > miltemp.wMilliseconds + 10) // звёздочка стреляющая из пушки на первом месте
							{
								infobox.X = 28;
								infobox.Y = 7;
								SetConsoleCursorPosition(h, infobox);
								SetConsoleTextAttribute(h, 7);
								std::cout << "*";
							}
							else if (temp.wSecond == timee.wSecond)
							{
								GetLocalTime(&miltemp);
								infobox.X = 28;
								infobox.Y = 7;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}


							if (temp.wSecond < timee.wSecond) // сносит урон раз в секунду
							{
								russians[i] -= 12;
								isshoot[2] = false;
								if (russians[i] <= 0)
								{
									killscount--;
									infobox.X = 40;  // обновляет счётчик при убийстве
									infobox.Y = 2;
									SetConsoleCursorPosition(h, infobox);
									SetConsoleTextAttribute(h, 14);
									std::cout << "Left to kill:";
									SetConsoleTextAttribute(h, 12);
									if (killscount < 10)
									{
										std::cout << "0" << killscount;
									}
									iskilled[i] = false;
								}
								if (musictemp)
									PlaySound(TEXT("D:\\C++_gameProject\\machinegun.wav"), NULL, SND_ASYNC);
							}


							if (iskilled[i] == false) // убрать звёздочку если враг ушёл с диапозона поражения или умер
							{
								GetLocalTime(&miltemp);
								infobox.X = 28;
								infobox.Y = 7;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}
						}
					}
				}
				else if (kindofgun2 == 2)
				{
					isshoot[3] = true; // для обновления разрешения на стрельбу
					for (int i = 0; i < 20; i++)
					{
						if (russiansenemy[i].X > 1 && iskilled[i] && isactive[i] && isshoot[3]) // находиться ли враг в зоне действия оружия
						{
							if (temp.wSecond < timee.wSecond) // сносит урон раз в секунду
							{
								russians[i] -= 20;
								isshoot[3] = false;
								if (russians[i] <= 0)
								{
									killscount--;
									infobox.X = 40;  // обновляет счётчик при убийстве
									infobox.Y = 2;
									SetConsoleCursorPosition(h, infobox);
									SetConsoleTextAttribute(h, 14);
									std::cout << "Left to kill:";
									SetConsoleTextAttribute(h, 12);
									if (killscount < 10)
									{
										std::cout << "0" << killscount;
									}
									iskilled[i] = false;
								}
								mortarsound++;
								if (mortarsound % 2 == 0) // Каждую вторую секунду должен быть звук выстрела
								{
									if (musictemp)
										PlaySound(TEXT("D:\\C++_gameProject\\mortira.wav"), NULL, SND_ASYNC);
								}
							}
						}
					}
				}
			}


			if (isstay3) // почему отдельная проверка от пушек на ловушки ? Потому что если бы проверка была б в isstay1 и isstay2 и на поле не было б пушек то ёж бы не работал, хотя с точки зрения оптимизации кода так лучше(
			{
				for (int i = 0; i < 36; i++)
				{
					for (int j = 0; j < 20; j++)
					{
						if (Trapplaces[i][0] == russiansenemy[j].X && Trapplaces[i][1] == russiansenemy[j].Y)
						{
							russians[j] -= 50;
							Trapplaces[i][0] = 0;
							Trapplaces[i][1] = 0;
							if (musictemp)
								PlaySound(TEXT("D:\\C++_gameProject\\trap.wav"), NULL, SND_ASYNC);
						}
					}
				}


				for (int i = 0; i < 20; i++)
				{
					if (russians[i] <= 0 && iskilled[i])
					{
						killscount--;
						infobox.X = 40;  // обновляет счётчик при убийстве
						infobox.Y = 2;
						SetConsoleCursorPosition(h, infobox);
						SetConsoleTextAttribute(h, 14);
						std::cout << "Left to kill:";
						SetConsoleTextAttribute(h, 12);
						if (killscount < 10)
						{
							std::cout << "0" << killscount;
						}
						iskilled[i] = false;
					}
				}
			}


			if (temp.wSecond < timee.wSecond) // temp.wSecond + 1 < time.wSecond - добавит ещё секунду к ожиданию
			{
				timeforspawn++;
				GetLocalTime(&temp);
				SetConsoleTextAttribute(h, 12);


				for (int i = 0; i < 20; i++)
				{
					if (russiansenemy[i].Y == 8 && russiansenemy[i].X <= 23 && russians[i] > 0 && isactive[i]) //движения врага 1
					{
						SetConsoleCursorPosition(h, russiansenemy[i]);
						std::cout << " ";
						russiansenemy[i].X++;
						SetConsoleCursorPosition(h, russiansenemy[i]);
						if (i == 9 || i == 19)
							std::cout << char(2);
						else
							std::cout << char(1);
					}
					if (upordown[i] == 0)
					{
						if (russiansenemy[i].X == 24 && russiansenemy[i].Y <= 10 && russians[i] > 0 && isactive[i]) //движения врага 2
						{
							SetConsoleCursorPosition(h, russiansenemy[i]);
							std::cout << " ";
							russiansenemy[i].Y++;
							SetConsoleCursorPosition(h, russiansenemy[i]);
							if (i == 9 || i == 19)
								std::cout << char(2);
							else
								std::cout << char(1);
						}
						else if (russiansenemy[i].Y == 11 && russiansenemy[i].X <= 39 && russians[i] > 0 && isactive[i]) //движения врага 3
						{
							SetConsoleCursorPosition(h, russiansenemy[i]);
							std::cout << " ";
							russiansenemy[i].X++;
							SetConsoleCursorPosition(h, russiansenemy[i]);
							if (i == 9 || i == 19)
								std::cout << char(2);
							else
								std::cout << char(1);
						}
					}
					else if (upordown[i] == 1)
					{
						if (russiansenemy[i].X == 24 && russiansenemy[i].Y >= 6 && russians[i] > 0 && isactive[i]) //движения врага 2
						{
							SetConsoleCursorPosition(h, russiansenemy[i]);
							std::cout << " ";
							russiansenemy[i].Y--;
							SetConsoleCursorPosition(h, russiansenemy[i]);
							if (i == 9 || i == 19)
								std::cout << char(2);
							else
								std::cout << char(1);
						}
						else if (russiansenemy[i].Y == 5 && russiansenemy[i].X <= 39 && russians[i] > 0 && isactive[i]) //движения врага 3
						{
							SetConsoleCursorPosition(h, russiansenemy[i]);
							std::cout << " ";
							russiansenemy[i].X++;
							SetConsoleCursorPosition(h, russiansenemy[i]);
							if (i == 9 || i == 19)
								std::cout << char(2);
							else
								std::cout << char(1);
						}
					}


					if (russians[i] <= 0 && iscan[i] && isactive[i]) // только для удаления врага
					{
						if (russians[9] <= 0)
							uahcount += 15000;
						else
							uahcount += 5000;
						infobox.X = 30;
						infobox.Y = 2;
						SetConsoleCursorPosition(h, infobox);
						SetConsoleTextAttribute(h, 12);
						std::cout << uahcount;


						SetConsoleCursorPosition(h, russiansenemy[i]);
						std::cout << " ";
						if (musictemp)
							PlaySound(TEXT("D:\\C++_gameProject\\kill.wav"), NULL, SND_ASYNC);
						iscan[i] = false;
						isactive[i] = false;
					}
				}


				if (istext) // текст предупреждающий писать три секунды
				{
					timecount++;
					if (timecount >= 3)
					{
						infobox.X = 11;
						infobox.Y = 7;
						SetConsoleCursorPosition(h, infobox);
						std::cout << "                ";
						timecount = 0;
						istext = false;
					}
				}
			}
			else if (temp.wSecond == 59)
			{
				GetLocalTime(&temp);
			}


			if (timeforspawn == 4) // Если с начала боя прошло 4 секунд то спавниться следующий враг
			{
				isactive[1] = true;
				SetConsoleCursorPosition(h, russiansenemy[1]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 8)
			{
				isactive[2] = true;
				SetConsoleCursorPosition(h, russiansenemy[2]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 12)
			{
				isactive[3] = true;
				SetConsoleCursorPosition(h, russiansenemy[3]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 16)
			{
				isactive[4] = true;
				SetConsoleCursorPosition(h, russiansenemy[4]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 20)
			{
				isactive[5] = true;
				SetConsoleCursorPosition(h, russiansenemy[5]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 24)
			{
				isactive[6] = true;
				SetConsoleCursorPosition(h, russiansenemy[6]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 28)
			{
				isactive[7] = true;
				SetConsoleCursorPosition(h, russiansenemy[7]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 32)
			{
				isactive[8] = true;
				SetConsoleCursorPosition(h, russiansenemy[8]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 36)
			{
				isactive[9] = true;
				SetConsoleCursorPosition(h, russiansenemy[9]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)2;
			}
			if (timeforspawn >= 36 && timeforspawn <= 38)
			{
				infobox.X = 7;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 12);
				if (timeforspawn == 38)
				{
					std::cout << "                    ";
				}
				else if (timeforspawn >= 36) /////////////////////////////   ???
				{
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\boss.wav"), NULL, SND_ASYNC);
					std::cout << "Lieutenant is coming";
				}
			}
			if (timeforspawn == 44)
			{
				isactive[10] = true;
				SetConsoleCursorPosition(h, russiansenemy[10]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 48)
			{
				isactive[11] = true;
				SetConsoleCursorPosition(h, russiansenemy[11]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 52)
			{
				isactive[12] = true;
				SetConsoleCursorPosition(h, russiansenemy[12]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 56)
			{
				isactive[13] = true;
				SetConsoleCursorPosition(h, russiansenemy[13]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 60)
			{
				isactive[14] = true;
				SetConsoleCursorPosition(h, russiansenemy[14]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 64)
			{
				isactive[15] = true;
				SetConsoleCursorPosition(h, russiansenemy[15]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 68)
			{
				isactive[16] = true;
				SetConsoleCursorPosition(h, russiansenemy[16]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 72)
			{
				isactive[17] = true;
				SetConsoleCursorPosition(h, russiansenemy[17]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 76)
			{
				isactive[18] = true;
				SetConsoleCursorPosition(h, russiansenemy[18]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 80)
			{
				isactive[19] = true;
				SetConsoleCursorPosition(h, russiansenemy[19]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)2;
			}
			if (timeforspawn >= 80 && timeforspawn <= 82)
			{
				infobox.X = 7;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 12);
				if (timeforspawn == 82)
				{
					std::cout << "                    ";
				}
				else if (timeforspawn == 80)
				{
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\boss.wav"), NULL, SND_ASYNC);
					std::cout << "Lieutenant is coming";
				}
			}


			if (killscount == 0) // если победил то
			{
				if (levelcap < 3)
				{
					levelcap = 3;
				}
				winmenu(timeforspawn, 20 - killscount, level);
			}
			else
			{ //если проиграл то
				for (int i = 0; i < 20; i++)
				{
					if (russiansenemy[i].X == 40)
						losemenu(timeforspawn, 20 - killscount, level);
				}

			}
		}
	}
}


void level3()
{
	PlaySound(NULL, NULL, SND_ASYNC);
	system("cls");
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); // установка режима использования мышки
	std::cout << "\n\n";
	SYSTEMTIME time, miltime;
	SYSTEMTIME temp, miltemp;
	GetLocalTime(&temp);
	GetLocalTime(&miltemp);
	int killscount = 10;
	int level = 1, mistcount = 0, timecount = 0, uahcount = 40000, timeforspawn = 0, kindofgun1, kindofgun2, mortarsound = 0, ind = 0;
	bool isput1 = false, isput2 = false, istext = false, isstay1 = false, isstay2 = false, isput3 = false, isstay3 = false;
	int Trapplaces[36][2] = {}; //для записи и проверки, где находиться ежи
	
	
	// заполнение массива
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width - 12; x++) {
	
			int stone = rand() % 15; //15
			int bush = rand() % 25; //25
			int grass = rand() % 20; //20
	
			if (x == 5 || x == 10)
			{
				SetConsoleTextAttribute(h, 15);
				if (y > 1 && y <= 6)
				{
					std::cout << "|";
				}
				else if (x == 5 && y > 4 && y <= 9)
				{
					std::cout << "|";
				}
			}
			else if (x > 5 && x < 45 && y > 5)
			{
				SetConsoleTextAttribute(h, 15);
				if (y == 9)
				{
					std::cout << "_";
				}
				else if (y == 6 && x > 11)
				{
					std::cout << "_";
				}
				else
				{
					std::cout << " ";
				}
			}
			//разметка башен, !потом заменить на сами башни!
	
			else if (x > 15 && x < 18 && y == 3)
			{
				SetConsoleTextAttribute(h, 15);
				std::cout << "_"; // башня 1
			}
			else if (x == 15 && y == 4)
			{
				SetConsoleTextAttribute(h, 15);
				std::cout << "|";
			}
			else if (x > 15 && x < 18 && y == 4)
			{
				SetConsoleTextAttribute(h, 15);
				std::cout << "_";
			}
			else if (x == 18 && y == 4)
			{
				SetConsoleTextAttribute(h, 15);
				std::cout << "|";
			}
			else if (x > 27 && x < 30 && y == 3)
			{
				SetConsoleTextAttribute(h, 15);
				std::cout << "_"; // башня 2
			}
			else if (x == 27 && y == 4)
			{
				SetConsoleTextAttribute(h, 15);
				std::cout << "|";
			}
			else if (x > 27 && x < 30 && y == 4)
			{
				std::cout << "_";
			}
			else if (x == 30 && y == 4)
			{
				SetConsoleTextAttribute(h, 15);
				std::cout << "|";
			}
			else if (stone == 1 && y > 1)
			{
				SetConsoleTextAttribute(h, 7);
				std::cout << ".";
			}
			else if (bush == 1 && y > 1)
			{
				SetConsoleTextAttribute(h, 2);
				std::cout << "*";
			}
			else if (grass == 1 && y > 1)
			{
				SetConsoleTextAttribute(h, 10);
				std::cout << "\"";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
	
	
	int russians[10] = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 500 }; //хп врагов
	bool iscan[10] = { true, true, true, true, true, true, true, true, true, true }; //можно ли удалить врагов
	bool iskilled[10] = { true, true, true, true, true, true, true, true, true, true }; //можно ли убавлять здоровье и засчитать при убийстве за килл
	bool isactive[10] = { true, false, false, false, false, false, false, false, false, false };
	bool isshoot[4] = { true, true, true, true };
	COORD russiansenemy[10];
	
	
	for (int i = 0; i < 10; i++) // иниацилизация массива врагов
	{
		russiansenemy[i].X = 8;
		russiansenemy[i].Y = 4;
		if (i == 0)
		{
			SetConsoleCursorPosition(h, russiansenemy[i]);
			SetConsoleTextAttribute(h, 12);
			std::cout << (char)1;
		}
	}
	
	
	// информация по всем показателям
	COORD infobox;
	infobox.X = 2;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 12);
	std::cout << "Quit";
	
	
	infobox.X = 19;
	infobox.Y = 0;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 9);
	std::cout << " Level 1:Kharkiv\n";
	
	
	infobox.X = 26;
	infobox.Y = 1;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "For win:eliminate all enemies \n";
	
	
	infobox.X = 26;
	infobox.Y = 2;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "UAH:";
	SetConsoleTextAttribute(h, 12);
	std::cout << uahcount;
	
	
	infobox.X = 40;
	infobox.Y = 2;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 14);
	std::cout << "Left to kill:";
	SetConsoleTextAttribute(h, 12);
	std::cout << killscount;
	SetConsoleTextAttribute(h, 14);
	std::cout << "\n________________________________________________________";
	
	
	for (int i = 4; i < 13; i++)
	{
		infobox.X = 41;
		infobox.Y = i;
		SetConsoleCursorPosition(h, infobox);
		std::cout << "|\n";
	}
	
	
	infobox.X = 42;
	infobox.Y = 4;
	SetConsoleCursorPosition(h, infobox);
	SetConsoleTextAttribute(h, 9);
	std::cout << "Machine gun";
	infobox.X = 42;
	infobox.Y = 5;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "buy:20000 UAH";
	
	
	infobox.X = 42;
	infobox.Y = 6;
	SetConsoleTextAttribute(h, 14);
	SetConsoleCursorPosition(h, infobox);
	std::cout << "______________";
	
	
	infobox.X = 42;
	infobox.Y = 7;
	SetConsoleTextAttribute(h, 9);
	SetConsoleCursorPosition(h, infobox);
	std::cout << "Mortar";
	infobox.X = 42;
	infobox.Y = 8;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "buy:40000 UAH";
	
	
	infobox.X = 42;
	infobox.Y = 9;
	SetConsoleTextAttribute(h, 14);
	SetConsoleCursorPosition(h, infobox);
	std::cout << "______________";
	
	
	infobox.X = 42;
	infobox.Y = 10;
	SetConsoleTextAttribute(h, 9);
	SetConsoleCursorPosition(h, infobox);
	std::cout << "Trap";
	infobox.X = 42;
	infobox.Y = 11;
	SetConsoleCursorPosition(h, infobox);
	std::cout << "buy:5000 UAH";
	
	
	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{ // пройтись по всем событиям
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X; // запомнить координаты мышки
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;
	
	
	
			//СДЕЛАТЬ ЧТОБЫ ПРИ ВЫБОРЕ ОРУЖИЯ БЫЛО ОБВЕДЕНО КРАСНЫМ КУДА МОЖНО СТАВИТЬ !!!
	
	
	
			GetLocalTime(&time);
			GetLocalTime(&miltime);
			if (c.X >= 2 && c.X <= 8 && c.Y >= 0 && c.Y <= 1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // если нажата ЛЕВАЯ КНОПКА МЫШКИ
				if (musictemp)
					PlaySound(TEXT("D:\\C++_gameProject\\MenuSong.wav"), NULL, SND_ASYNC);
				system("cls");
				levelchoice();
	
	
				/*infobox.Y = 2;
				infobox.X = 9;
				SetConsoleTextAttribute(h, 12);
	
	
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 38; j++)
					{
						SetConsoleCursorPosition(h, infobox);
						if (infobox.Y == 2 || infobox.Y == 10)
							std::cout << "_";
						else if (infobox.X == 9 || infobox.X == 46)
							std::cout << "|";
						else
							std::cout << " ";
	
	
						infobox.X++;
					}
					infobox.Y++;
					infobox.X = 9;
				}
				infobox.Y = 4;
				infobox.X = 17;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "Do you want to leave?";
	
	
				infobox.Y = 6;
				infobox.X = 16;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "Progress at this level";
	
	
	
				infobox.Y = 7;
				infobox.X = 18;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "will not be saved!";
	
	
				infobox.Y = 9;
				infobox.X = 21;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "Yes        No";
	
				while (true)
				{
					ReadConsoleInput(hin, all_events, events_count, &read_event);
					c.X = all_events[i].Event.MouseEvent.dwMousePosition.X; // запомнить координаты мышки
					c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;
	
	
					if (c.X >= 21 && c.X <= 23 && c.Y == 9 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					{
						if (musictemp)
							PlaySound(TEXT("D:\\C++_gameProject\\MenuSong.wav"), NULL, SND_ASYNC);
						system("cls");
						levelchoice();
					}
					else if (c.X >= 31 && c.X <= 32 && c.Y == 9 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					{
	
						break;
					}
				}*/
			}
			else if (c.X >= 42 && c.X <= 54 && c.Y >= 4 && c.Y <= 6 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ //при нажатии в выборе на пушку
				infobox.X = 42;
				infobox.Y = 4;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 14);
				std::cout << "Machine gun";
				infobox.X = 42;
				infobox.Y = 5;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:20000 UAH";
				isput1 = true;
			}
			else if (c.X >= 27 && c.X <= 30 && c.Y >= 5 && c.Y <= 7 && isput1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке пушки на второе место
				if (uahcount < 20000)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 20000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					kindofgun2 = 1;
					SetConsoleTextAttribute(h, 7);
					infobox.X = 26;
					infobox.Y = 5;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "--d ";
					infobox.X = 27;
					infobox.Y = 6;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "/'\\ ";
					isstay2 = true;
				}
	
	
				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";
	
	
				infobox.X = 42;
				infobox.Y = 4;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Machine gun";
				infobox.X = 42;
				infobox.Y = 5;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:20000 UAH";
				isput1 = false;
			}
			else if (c.X >= 14 && c.X <= 17 && c.Y >= 5 && c.Y <= 7 && isput1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке пушки на первое место
				if (uahcount < 20000)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 20000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					kindofgun1 = 1;
					SetConsoleTextAttribute(h, 7);
					infobox.X = 14;
					infobox.Y = 5;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "--d ";
					infobox.X = 15;
					infobox.Y = 6;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "/'\\ ";
					isstay1 = true;
				}
	
	
				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)  // СДЕЛАТЬ ТАК ВО ВСЕХ МЕСТАХ ГДЕ МЕНЯЕТЬСЯ uahcount
					std::cout << uahcount << "    ";              // И ЕСЛИ НЕДОСТАТОЧНО ДЕНЕГ ДЛЯ ПОКУПКИ, ТО НАПИСАТЬ ЧТО НЕ ХВАТАЕТ ДЕНЕГ И НЕ ОТНИМАТЬ ИХ В МИНУС !
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";
	
	
				infobox.X = 42;
				infobox.Y = 4;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Machine gun";
				infobox.X = 42;
				infobox.Y = 5;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:20000 UAH";
				isput1 = false;
			}
			else if ((c.X < 27 || c.X > 30 || c.Y < 6 || c.Y > 6) && isput1 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // Если промахнулся то убирает выделение
				infobox.X = 42;
				infobox.Y = 4;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Machine gun";
				infobox.X = 42;
				infobox.Y = 5;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:20000 UAH";
	
	
				isput1 = false;
				mistcount++;
				if (mistcount >= 3)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << " Can't put here ";
					istext = true;
					mistcount = 0;
				}
			}
	
	
			else if (c.X >= 42 && c.X <= 54 && c.Y >= 7 && c.Y <= 9 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ //при нажатии в выборе на мортиру
				infobox.X = 42;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 14);
				std::cout << "Mortar";
				infobox.X = 42;
				infobox.Y = 8;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:40000 UAH";
				isput2 = true;
			}
			else if (c.X >= 27 && c.X <= 30 && c.Y >= 5 && c.Y <= 7 && isput2 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке мортиры на второе место
				if (uahcount < 40000)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 40000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					kindofgun2 = 2;
					SetConsoleTextAttribute(h, 7);
					infobox.X = 26;
					infobox.Y = 5;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "\"\\\\ ";
					infobox.X = 27;
					infobox.Y = 6;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "/\\\\ ";
					isstay2 = true;
				}
	
	
				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";
	
	
				infobox.X = 42;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Mortar";
				infobox.X = 42;
				infobox.Y = 8;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:40000 UAH";
				isput2 = false;
			}
			else if (c.X >= 14 && c.X <= 17 && c.Y >= 5 && c.Y <= 7 && isput2 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке мортиры на первое место
				if (uahcount < 40000)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 40000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					kindofgun1 = 2;
					SetConsoleTextAttribute(h, 7);
					infobox.X = 14;
					infobox.Y = 5;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "\"\\\\ ";
					infobox.X = 15;
					infobox.Y = 6;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "/\\\\ ";
					isstay1 = true;
				}
	
	
				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";
	
	
				infobox.X = 42;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Mortar";
				infobox.X = 42;
				infobox.Y = 8;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:40000 UAH";
				isput2 = false;
			}
			else if ((c.X < 27 || c.X > 30 || c.Y < 6 || c.Y > 6) && isput2 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // Если промахнулся то убирает выделение
				infobox.X = 42;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Mortar";
				infobox.X = 42;
				infobox.Y = 8;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:40000 UAH";
	
	
				isput2 = false;
				mistcount++;
				if (mistcount >= 3)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << " Can't put here ";
					istext = true;
					mistcount = 0;
				}
			}
	
	
			else if (c.X >= 42 && c.X <= 54 && c.Y >= 10 && c.Y <= 12 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ //при нажатии в выборе на ежа
				infobox.X = 42;
				infobox.Y = 10;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 14);
				std::cout << "Trap";
				infobox.X = 42;
				infobox.Y = 11;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:5000 UAH";
				isput3 = true;
			}
	
			else if (c.X >= 8 && c.X <= 8 && c.Y >= 6 && c.Y <= 10 && isput3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED ||
				c.X >= 8 && c.X <= 38 && c.Y >= 10 && c.Y <= 10 && isput3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // при поставке ежа
				if (uahcount < 5000)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << "Not enough money";
					istext = true;
				}
				else
				{
					uahcount -= 5000;
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\build.wav"), NULL, SND_ASYNC);
					SetConsoleTextAttribute(h, 7);
					infobox.X = c.X;
					infobox.Y = c.Y;
					SetConsoleCursorPosition(h, infobox);
					std::cout << "X";
					Trapplaces[ind][0] = c.X;
					Trapplaces[ind][1] = c.Y;
					ind++;
					isstay3 = true;
				}
	
	
				SetConsoleTextAttribute(h, 12);
				infobox.X = 30;
				infobox.Y = 2;
				SetConsoleCursorPosition(h, infobox);
				if (uahcount >= 0 && uahcount <= 9)
					std::cout << uahcount << "       ";
				else if (uahcount >= 10 && uahcount <= 99)
					std::cout << uahcount << "      ";
				else if (uahcount >= 100 && uahcount <= 999)
					std::cout << uahcount << "     ";
				else if (uahcount >= 1000 && uahcount <= 9999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 10000 && uahcount <= 99999)
					std::cout << uahcount << "    ";
				else if (uahcount >= 100000 && uahcount <= 999999)
					std::cout << uahcount << "   ";
	
	
				infobox.X = 42;
				infobox.Y = 10;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Trap";
				infobox.X = 42;
				infobox.Y = 11;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:5000 UAH";
				isput3 = false;
			}
			else if ((c.X < 27 || c.X > 30 || c.Y < 6 || c.Y > 6) && isput3 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // Если промахнулся то убирает выделение
				infobox.X = 42;
				infobox.Y = 10;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 9);
				std::cout << "Trap";
				infobox.X = 42;
				infobox.Y = 11;
				SetConsoleCursorPosition(h, infobox);
				std::cout << "buy:5000 UAH";
	
	
				isput3 = false;
				mistcount++;
				if (mistcount >= 3)
				{
					infobox.X = 15;
					infobox.Y = 7;
					SetConsoleCursorPosition(h, infobox);
					SetConsoleTextAttribute(h, 12);
					std::cout << " Can't put here ";
					istext = true;
					mistcount = 0;
				}
			}
	
	
			else if (c.X >= 2 && c.X <= 8 && c.Y == 1)
			{
				SetConsoleTextAttribute(h, 14);
				c.X = 2;
				c.Y = 1;
				SetConsoleCursorPosition(h, c);
				std::cout << "Quit";
			}
			else if (c.Y > 1 || c.Y < 1 || c.X > 6 || c.X < 2)
			{
				SetConsoleTextAttribute(h, 12);
				c.X = 2;
				c.Y = 1;
				SetConsoleCursorPosition(h, c);
				std::cout << "Quit";
			}
	
	
			if (isstay1) // стоит ли оружие на первой позиции
			{
				if (kindofgun1 == 1)
				{
					isshoot[0] = true; // для обновления разрешения на стрельбу
					for (int i = 0; i < 10; i++)
					{
						if (russiansenemy[i].Y > 4 && russiansenemy[i].X < 23 && iskilled[i] && isactive[i] && isshoot[0]) // находиться ли враг в зоне действия оружия
						{
							if (miltime.wMilliseconds > miltemp.wMilliseconds + 10)
							{
								infobox.X = 13;
								infobox.Y = 5;
								SetConsoleCursorPosition(h, infobox);
								SetConsoleTextAttribute(h, 7);
								std::cout << "*";
							}
							else if (temp.wSecond == time.wSecond)
							{
								GetLocalTime(&miltemp);
								infobox.X = 13;
								infobox.Y = 5;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}
	
	
							if (temp.wSecond < time.wSecond) // сносит урон раз в секунду
							{
								russians[i] -= 15;
								isshoot[0] = false;
								if (russians[i] <= 0)
								{
									killscount--;
									infobox.X = 40;  // обновляет счётчик при убийстве
									infobox.Y = 2;
									SetConsoleCursorPosition(h, infobox);
									SetConsoleTextAttribute(h, 14);
									std::cout << "Left to kill:";
									SetConsoleTextAttribute(h, 12);
									if (killscount < 10)
									{
										std::cout << "0" << killscount;
									}
									iskilled[i] = false;
								}
	
	
								if (musictemp)
									PlaySound(TEXT("D:\\C++_gameProject\\machinegun.wav"), NULL, SND_ASYNC);
							}
	
	
							if (russiansenemy[i].X == 22 || iskilled[i] == false)
							{
								GetLocalTime(&miltemp);
								infobox.X = 13;
								infobox.Y = 5;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}
						}
					}
				}
				else if (kindofgun1 == 2)
				{
					isshoot[1] = true; // для обновления разрешения на стрельбу
					for (int i = 0; i < 10; i++)
					{
						if (russiansenemy[i].Y > 4 && russiansenemy[i].X < 41 && iskilled[i] && isactive[i] && isshoot[1]) // находиться ли враг в зоне действия оружия
						{
							if (miltime.wMilliseconds > miltemp.wMilliseconds + 20) // звёздочка стреляющая из пушки на первом месте
							{
								infobox.X = 15;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								SetConsoleTextAttribute(h, 7);
								std::cout << "*";
							}
							else if (temp.wSecond == time.wSecond)
							{
								GetLocalTime(&miltemp);
								infobox.X = 15;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}
	
	
							if (temp.wSecond < time.wSecond) // сносит урон раз в секунду
							{
								russians[i] -= 25;
								isshoot[1] = false;
								if (russians[i] <= 0)
								{
									killscount--;
									infobox.X = 40;  // обновляет счётчик при убийстве
									infobox.Y = 2;
									SetConsoleCursorPosition(h, infobox);
									SetConsoleTextAttribute(h, 14);
									std::cout << "Left to kill:";
									SetConsoleTextAttribute(h, 12);
									if (killscount < 10)
									{
										std::cout << "0" << killscount;
									}
									iskilled[i] = false;
								}
								mortarsound++;
								if (mortarsound % 2 == 0) // Каждую вторую секунду должен быть звук выстрела
								{
									if (musictemp)
										PlaySound(TEXT("D:\\C++_gameProject\\mortira.wav"), NULL, SND_ASYNC);
								}
							}
	
	
							if (russiansenemy[i].X == 22 || iskilled[i] == false) // убрать звёздочку если враг ушёл с диапозона поражения или умер
							{
								GetLocalTime(&miltemp);
								infobox.X = 15;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}
						}
					}
				}
			}
	
	
			if (isstay2)
			{
				if (kindofgun2 == 1)
				{
					isshoot[2] = true; // для обновления разрешения на стрельбу
					for (int i = 0; i < 10; i++)
					{
						if (russiansenemy[i].Y > 6 && russiansenemy[i].X > 22 && iskilled[i] && isactive[i] && isshoot[2]) // находиться ли враг в зоне действия оружия
						{
							if (miltime.wMilliseconds > miltemp.wMilliseconds + 10) // звёздочка стреляющая из пушки на первом месте
							{
								infobox.X = 25;
								infobox.Y = 5;
								SetConsoleCursorPosition(h, infobox);
								SetConsoleTextAttribute(h, 7);
								std::cout << "*";
							}
							else if (temp.wSecond == time.wSecond)
							{
								GetLocalTime(&miltemp);
								infobox.X = 25;
								infobox.Y = 5;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}
	
	
							if (temp.wSecond < time.wSecond) // сносит урон раз в секунду
							{
								russians[i] -= 15;
								isshoot[2] = false;
								if (russians[i] <= 0)
								{
									killscount--;
									infobox.X = 40;  // обновляет счётчик при убийстве
									infobox.Y = 2;
									SetConsoleCursorPosition(h, infobox);
									SetConsoleTextAttribute(h, 14);
									std::cout << "Left to kill:";
									SetConsoleTextAttribute(h, 12);
									if (killscount < 10)
									{
										std::cout << "0" << killscount;
									}
									iskilled[i] = false;
								}
								if (musictemp)
									PlaySound(TEXT("D:\\C++_gameProject\\machinegun.wav"), NULL, SND_ASYNC);
							}
	
	
							if (iskilled[i] == false) // убрать звёздочку если враг ушёл с диапозона поражения или умер
							{
								GetLocalTime(&miltemp);
								infobox.X = 25;
								infobox.Y = 5;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}
						}
					}
				}
				else if (kindofgun2 == 2)
				{
					isshoot[3] = true; // для обновления разрешения на стрельбу
					for (int i = 0; i < 10; i++)
					{
						if (russiansenemy[i].Y > 4 && russiansenemy[i].X < 41 && iskilled[i] && isactive[i] && isshoot[3]) // находиться ли враг в зоне действия оружия
						{
							if (miltime.wMilliseconds > miltemp.wMilliseconds + 10) // звёздочка стреляющая из пушки на первом месте
							{
								infobox.X = 27;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								SetConsoleTextAttribute(h, 7);
								std::cout << "*";
							}
							else if (temp.wSecond == time.wSecond)
							{
								GetLocalTime(&miltemp);
								infobox.X = 27;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}
	
	
							if (temp.wSecond < time.wSecond) // сносит урон раз в секунду
							{
								russians[i] -= 25;
								isshoot[3] = false;
								if (russians[i] <= 0)
								{
									killscount--;
									infobox.X = 40;  // обновляет счётчик при убийстве
									infobox.Y = 2;
									SetConsoleCursorPosition(h, infobox);
									SetConsoleTextAttribute(h, 14);
									std::cout << "Left to kill:";
									SetConsoleTextAttribute(h, 12);
									if (killscount < 10)
									{
										std::cout << "0" << killscount;
									}
									iskilled[i] = false;
								}
								mortarsound++;
								if (mortarsound % 2 == 0) // Каждую вторую секунду должен быть звук выстрела
								{
									if (musictemp)
										PlaySound(TEXT("D:\\C++_gameProject\\mortira.wav"), NULL, SND_ASYNC);
								}
							}
	
	
							if (iskilled[i] == false) // убрать звёздочку если враг ушёл с диапозона поражения или умер
							{
								GetLocalTime(&miltemp);
								infobox.X = 27;
								infobox.Y = 4;
								SetConsoleCursorPosition(h, infobox);
								std::cout << " ";
							}
						}
					}
				}
			}
	
	
			if (isstay3) // почему отдельная проверка от пушек на ловушки ? Потому что если бы проверка была б в isstay1 и isstay2 и на поле не было б пушек то ёж бы не работал, хотя с точки зрения оптимизации кода так лучше(
			{
				for (int i = 0; i < 36; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (Trapplaces[i][0] == russiansenemy[j].X && Trapplaces[i][1] == russiansenemy[j].Y)
						{
							russians[j] -= 50;
							Trapplaces[i][0] = 0;
							Trapplaces[i][1] = 0;
							if (musictemp)
								PlaySound(TEXT("D:\\C++_gameProject\\trap.wav"), NULL, SND_ASYNC);
						}
					}
				}
	
	
				for (int i = 0; i < 10; i++)
				{
					if (russians[i] <= 0 && iskilled[i])
					{
						killscount--;
						infobox.X = 40;  // обновляет счётчик при убийстве
						infobox.Y = 2;
						SetConsoleCursorPosition(h, infobox);
						SetConsoleTextAttribute(h, 14);
						std::cout << "Left to kill:";
						SetConsoleTextAttribute(h, 12);
						if (killscount < 10)
						{
							std::cout << "0" << killscount;
						}
						iskilled[i] = false;
					}
				}
			}
	
	
			if (temp.wSecond < time.wSecond) // temp.wSecond + 1 < time.wSecond - добавит ещё секунду к ожиданию
			{
				timeforspawn++;
				GetLocalTime(&temp);
				SetConsoleTextAttribute(h, 12);
	
	
				for (int i = 0; i < 10; i++)
				{
					if (russiansenemy[i].Y <= 9 && russians[i] > 0 && isactive[i]) //движения врага
					{
						SetConsoleCursorPosition(h, russiansenemy[i]);
						std::cout << " ";
						russiansenemy[i].Y++;
						SetConsoleCursorPosition(h, russiansenemy[i]);
						std::cout << char(1);
					}
					else if (russiansenemy[i].X <= 39 && russians[i] > 0 && isactive[i]) //движения врага
					{
						SetConsoleCursorPosition(h, russiansenemy[i]);
						std::cout << " ";
						russiansenemy[i].X++;
						SetConsoleCursorPosition(h, russiansenemy[i]);
						std::cout << char(1);
					}
					else if (russians[i] <= 0 && iscan[i] && isactive[i]) // только для удаления врага
					{
						uahcount += 5000;
						infobox.X = 30;
						infobox.Y = 2;
						SetConsoleCursorPosition(h, infobox);
						SetConsoleTextAttribute(h, 12);
						std::cout << uahcount;
	
	
						SetConsoleCursorPosition(h, russiansenemy[i]);
						std::cout << " ";
						if (musictemp)
							PlaySound(TEXT("D:\\C++_gameProject\\kill.wav"), NULL, SND_ASYNC);
						iscan[i] = false;
						isactive[i] = false;
					}
				}
	
	
				if (istext) // текст предупреждающий писать три секунды
				{
					timecount++;
					if (timecount >= 3)
					{
						infobox.X = 15;
						infobox.Y = 7;
						SetConsoleCursorPosition(h, infobox);
						std::cout << "                ";
						timecount = 0;
						istext = false;
					}
				}
			}
			else if (temp.wSecond == 59)
			{
				GetLocalTime(&temp);
			}
	
	
			if (timeforspawn == 5) // Если с начала боя прошло 5 секунд то спавниться следующий враг
			{
				isactive[1] = true;
				SetConsoleCursorPosition(h, russiansenemy[1]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 10)
			{
				isactive[2] = true;
				SetConsoleCursorPosition(h, russiansenemy[2]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 15)
			{
				isactive[3] = true;
				SetConsoleCursorPosition(h, russiansenemy[3]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 20)
			{
				isactive[4] = true;
				SetConsoleCursorPosition(h, russiansenemy[4]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 25)
			{
				isactive[5] = true;
				SetConsoleCursorPosition(h, russiansenemy[5]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 30)
			{
				isactive[6] = true;
				SetConsoleCursorPosition(h, russiansenemy[6]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 35)
			{
				isactive[7] = true;
				SetConsoleCursorPosition(h, russiansenemy[7]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 40)
			{
				isactive[8] = true;
				SetConsoleCursorPosition(h, russiansenemy[8]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			else if (timeforspawn == 45)
			{
				isactive[9] = true;
				SetConsoleCursorPosition(h, russiansenemy[9]);
				SetConsoleTextAttribute(h, 12);
				std::cout << (char)1;
			}
			if (timeforspawn >= 45 && timeforspawn <= 48)
			{
				infobox.X = 16;
				infobox.Y = 7;
				SetConsoleCursorPosition(h, infobox);
				SetConsoleTextAttribute(h, 12);
				if (timeforspawn == 48)
				{
					std::cout << "                    ";
				}
				else if (timeforspawn == 45)
				{
					if (musictemp)
						PlaySound(TEXT("D:\\C++_gameProject\\boss.wav"), NULL, SND_ASYNC);
					std::cout << "Lieutenant is coming";
				}
			}
	
	
			if (killscount == 0) // если победил то
			{
				if (levelcap < 2)
				{
					levelcap = 2;
				}
				winmenu(timeforspawn, 10 - killscount, level);
			}
			else
			{ //если проиграл то
				for (int i = 0; i < 10; i++)
				{
					if (russiansenemy[i].X == 40)
						losemenu(timeforspawn, 10 - killscount, level);
				}
	
			}
		}
	}
}


void level4();


void level5();


void level6();


int main()
{
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 1920, 1080, TRUE); //1920 width, 1080 height
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 100;
	cursor.bVisible = false;
	SetConsoleCursorInfo(h, &cursor);
	if (loginfirsttime)
	{
		loginfirsttime = false;
		login(cursor);
	}
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);


	if (musicfirsttime)
	{
		PlaySound(TEXT("D:\\C++_gameProject\\MenuSong.wav"), NULL, SND_ASYNC);
		musicfirsttime = false;
	}
	srand(time(0));


	menu();
	if (createthreadfirsttime)
	{
		createthreadfirsttime = false;
		CreateThread(0, 0, menufire, 0, 0, 0); // создание потока с стрельбой башенек
	}

	bool isup = false;

	while (true)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++)
		{ // пройтись по всем событиям
			isfire = true;
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X; // запомнить координаты мышки
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


			if (c.X >= 34 && c.X <= 54 && c.Y == 1 && isup == false && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				c.X = 34;
				c.Y = 1;
				SetConsoleCursorPosition(h, c);
				SetConsoleTextAttribute(h, 9);
				std::cout << (char)30;


				c.X = 36;
				c.Y = 2;
				SetConsoleCursorPosition(h, c);
				SetConsoleTextAttribute(h, 12);
				std::cout << "Sign out";
				isup = true;
			}
			else if (c.X >= 34 && c.X <= 54 && c.Y == 1 && isup && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				c.X = 34;
				c.Y = 1;
				SetConsoleCursorPosition(h, c);
				SetConsoleTextAttribute(h, 9);
				std::cout << (char)31;


				c.X = 36;
				c.Y = 2;
				SetConsoleCursorPosition(h, c);
				std::cout << "          ";
				isup = false;
			}
			else if (c.X >= 36 && c.X <= 43 && c.Y == 2 && isup && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				isfire = false;
				setlocale(LC_ALL, "C");
				login(cursor);
				setlocale(LC_ALL, "Russian");
			}
			else if (c.X >= 24 && c.X <= 27 && c.Y == 4 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{ // если нажата ЛЕВАЯ КНОПКА МЫШКИ
				isfire = false;
				levelchoice();
			}	
			else if (c.X >= 24 && c.X <= 32 && c.Y == 6 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				isfire = false;
				settings();
			}
			else if (c.X >= 24 && c.X <= 27 && c.Y == 8 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				isfire = false;
				news();
			}
			else if (c.X >= 24 && c.X <= 28 && c.Y == 10 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				system("cls");
				exit(0);
			}
			/*else if (c.X >= 24 && c.X <= 27 && c.Y == 4)
			{
				SetConsoleTextAttribute(h, 14);
				c.X = 24;
				SetConsoleCursorPosition(h, c);
				std::cout << "Play";
			}
			else if (c.X >= 24 && c.X <= 32 && c.Y == 6)
			{
				SetConsoleTextAttribute(h, 14);
				c.X = 24;
				SetConsoleCursorPosition(h, c);
				std::cout << "Settings";
			}
			else if (c.X >= 24 && c.X <= 28 && c.Y == 8)
			{
				SetConsoleTextAttribute(h, 14);
				c.X = 24;
				SetConsoleCursorPosition(h, c);
				std::cout << "Exit";
			}*/
		}
	}
}
