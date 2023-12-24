#include<iostream>
#include<windows.h>
#include<conio.h>

const int width; // not determined
const int height;  // not determined


int main(){
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
