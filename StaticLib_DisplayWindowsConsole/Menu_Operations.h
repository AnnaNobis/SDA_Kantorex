#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>

class Menu_Operations
{

public:
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // tutaj uchwyt do standardowego wyjœcia konsoli pozyskujê


    void drawingPartMenuOperations();

    void gotoxy(int x, int y);// pozycjonowanie rysowania na ekranie

    // rysowanie pojedynczej pozycji w menu
    void WriteMenuPos(std::string& str, int id, int idset);

    // rysowanie linii sk³adaj¹cej siê z znaków = a ich liczba okreœla d³ugoœæ linii
    void WriteLine(unsigned int width);

    int menu(std::string title, std::vector<std::string>& tMenu, int& id);// a tu menu rysujê

    void displayMenuOperations();




};

