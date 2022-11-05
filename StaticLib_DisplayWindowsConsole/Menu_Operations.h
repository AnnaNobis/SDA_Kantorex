#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include "../Kantorex_login/ILoggedUser.hpp"
#include <ostream>


class Menu_Operations
{

public:

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // tutaj uchwyt do standardowego wyj�cia konsoli 

    void gotoxy(int x, int y);// pozycjonowanie rysowania na ekranie

    void WriteMenuPos(std::string& str, int id, int idset);

    void WriteLine(unsigned int width);

    int menu(std::string title, std::vector<std::string>& tMenu, int& id);// a tu menu rysuj�

    void displayMenuOperations(std::shared_ptr<ILoggedUser> loggedUser);

    void displayOperationName(std::string _operationName);

   

};

