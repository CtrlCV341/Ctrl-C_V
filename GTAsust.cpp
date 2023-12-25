#include<iostream>
#include<windows.h>
#include<conio.h>

const int width; // not determined
const int height;  // not determined

struct position{
    int x;
    int y;
};

void gotoxy(int x,int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  //copied, used to set the position of the cursor
}


void border(){

}

void mapSUST(){

}

int main(){
    position playerPos={2,2};
    position destPos;
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    gotoxy(width/2,height/2)
    cout << "                     Hey! Welcome to GTAsust game app" << endl;
    cout << "**********************************************************************************" << endl;
    cout << "This game is about Shahjalal University of Science and Technology(SUST) where you"<<endl;
    cout << "can travel at any point of the university and reach to your desired destination" << endl;
    cout << endl;

    system("pause");

    system("cls");
    cout<<"Where do you want to go?"<<endl;
    cout<<"1.IICT"<<endl;
    cout<<"2.A-building"<<endl;
    cout<<"3.B-building"<<endl;
    cout<<"You're Answer: ";
    int userDest;
    cin>>userDest;

    switch (userDest)
    {
        case 1:
            destPos = {20, Height - 2};
            break;
        case 2:
            destPos = {Width - 3, 5};
            break;
        case 3:
            destPos = {Width / 2, Height / 2};
            break;
        default:
            break;
    }
    system("cls");
    border();
    mapSUST();
}
