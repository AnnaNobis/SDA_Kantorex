#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include "../Kantorex_login/ILoggedUser.hpp"

class Menu_Operations
{

public:

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // tutaj uchwyt do standardowego wyj�cia konsoli 


    void gotoxy(int x, int y);// pozycjonowanie rysowania na ekranie

    // rysowanie pojedynczej pozycji w menu
    void WriteMenuPos(std::string& str, int id, int idset);

    // rysowanie linii sk�adaj�cej si� z znak�w = a ich liczba okre�la d�ugo�� linii
    void WriteLine(unsigned int width);

    int menu(std::string title, std::vector<std::string>& tMenu, int& id);// a tu menu rysuj�

    void displayMenuOperations(std::shared_ptr<ILoggedUser> loggedUser);

   std::vector<std::string> tMenuGl();
   //void (std::vector<std::string> tMenuGl);


};

