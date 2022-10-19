#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>

class Menu_Operations
{

public:
<<<<<<< HEAD
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // tutaj uchwyt do standardowego wyjï¿½cia konsoli pozyskujï¿½
=======
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // tutaj uchwyt do standardowego wyjœcia konsoli 
>>>>>>> 493d46e (drobne zmiany display)


    void drawingPartMenuOperations();

    void gotoxy(int x, int y);// pozycjonowanie rysowania na ekranie

    // rysowanie pojedynczej pozycji w menu
    void WriteMenuPos(std::string& str, int id, int idset);

    // rysowanie linii skï¿½adajï¿½cej siï¿½ z znakï¿½w = a ich liczba okreï¿½la dï¿½ugoï¿½ï¿½ linii
    void WriteLine(unsigned int width);

    int menu(std::string title, std::vector<std::string>& tMenu, int& id);// a tu menu rysujï¿½

    void displayMenuOperations();




};

