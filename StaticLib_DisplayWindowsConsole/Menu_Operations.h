#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>

class Menu_Operations
{

public:
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // tutaj uchwyt do standardowego wyj�cia konsoli pozyskuj�


    void drawingPartMenuOperations();

    void gotoxy(int x, int y);// pozycjonowanie rysowania na ekranie

    // rysowanie pojedynczej pozycji w menu
    void WriteMenuPos(std::string& str, int id, int idset);

    // rysowanie linii sk�adaj�cej si� z znak�w = a ich liczba okre�la d�ugo�� linii
    void WriteLine(unsigned int width);

    int menu(std::string title, std::vector<std::string>& tMenu, int& id);// a tu menu rysuj�

    void displayMenuOperations();




};

