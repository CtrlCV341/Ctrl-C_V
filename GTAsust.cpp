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
    loop(i, 0, 81) /// shahporan hall
    {
        if (i > 76)
            cout << 'S';
        else
            cout << ' ';
    }
    cout << endl;
    loop(i, 0, 90) /// shahporan hall
    {
        if (i == 77 || i == 80)
            cout << '#';
        else
            cout << ' ';
    }
    cout << endl;
    loop(i, 0, 81) /// shahporan hall
    {
        if (i > 76)
            cout << '#';
        else
            cout << ' ';
    }
    cout << endl;
    loop(i, 0, 130) /// shahporan hall road
    {
        if (i < 60)
            cout << ' ';
        else
            cout << '*';
    }
    cout << endl;
    loop(i, 0, 61) /// shahporan hall
    {
        if (i == 60)
            cout << '*';
        else
            cout << ' ';
    }
    cout << endl;
    loop(i, 0, 130) /// shahporan hall
    {
        if (i == 60)
            cout << '*';
        else if (i > 63)
            cout << '*';
        else
            cout << ' ';
    }
    cout << endl;
    loop(j, 0, 2) /// tennis court turning road
    {
        for (int i = 0; i < 65; i++)
        {
            if (i == 60)
                cout << '*';
            else if (i > 63)
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }
    loop(i, 0, 65) /// auditorium
    {
        if (i > 32 && i < 37)
            cout << 'O';
        else if (i == 60)
            cout << '*';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 65) /// auditorium
    {
        if (i == 33 || i == 36)
            cout << '#';
        else if (i == 60)
            cout << '*';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 65) /// auditorium
    {
        if (i > 32 && i < 37)
            cout << '#';
        else if (i == 60)
            cout << '*';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 65) /// auditorium front road
    {
        if (i > 32 && i < 61)
            cout << '*';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 65) /// auditorium front road
    {
        if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 65) /// auditorium front road
    {
        if (i > 60 && i < 64)
            cout << ' ';
        else if (i < 33)
            cout << ' ';
        else
            cout << '*';
    }
    eline;
    loop(j, 0, 3)
    {
        loop(i, 0, 65) /// audit to minar
        {
            if (i == 60 || i == 64)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 65) ///  s minar
    {
        if (i > 32 && i < 37)
            cout << 'M';
        else if (i == 60)
            cout << '*';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 65) ///  s minar
    {
        if (i == 33 || i == 36)
            cout << '#';
        else if (i == 60)
            cout << '*';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 65) ///  s minar
    {
        if (i > 32 && i < 37)
            cout << '#';
        else if (i == 60)
            cout << '*';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 65) ///  s minar road
    {
        if (i > 32 && i < 61)
            cout << '*';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 65) ///  s minar road
    {
        if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 65)
    {
        if (i > 60 && i < 64)
            cout << ' ';
        else if (i < 33)
            cout << ' ';
        else
            cout << '*';
    }
    eline;
    loop(j, 0, 2) /// s minar to chetona
    {
        loop(i, 0, 65)
        {
            if (i == 60 || i == 64)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    for (int i = 0; i < 90; i++) /// road + c building roof
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i >= 85)
            cout << 'C';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 2)
    {
        for (int i = 0; i < 120; i++) /// road + c building roof
        {
            if (i == 60 || i == 64)
                cout << '*';
            else if (i == 85 || i == 89)
                cout << '#';
            else
                cout << ' ';
        }
        eline;
    }
    for (int i = 0; i < 130; i++) /// road + c building roof
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i >= 85 && i <= 89)
            cout << '#';
        else
            cout << ' ';
    }
    eline;
    for (int i = 0; i < 100; i++)
    {
        if (i == 60)
            cout << '*';
        else if (i > 63)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 1) /// s minar to chetona
    {
        loop(i, 0, 65)
        {
            if (i == 60)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    for (int i = 0; i < 100; i++) /// chetona to E
    {
        if (i == 60)
            cout << '*';
        else if (i > 63)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// E build
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i >= 92 && i <= 96)
            cout << 'E';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 2)
    {
        loop(i, 0, 100) /// e build
        {
            if (i == 60 || i == 64)
                cout << '*';
            else if (i == 92 || i == 96)
                cout << '#';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 100) /// E build
    {
        if (i == 60 || i == 64)
            road;
        else if (i >= 92 && i <= 96)
            cout << '#';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 2)
    {
        loop(i, 0, 65) /// chetona to arjuntola
        {
            if (i == 60 || i == 64)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 100) /// d building and a building
    {
        if (i >= 30 && i <= 34)
            cout << 'D';
        else if (i == 60 || i == 64)
            cout << '*';
        else if (i >= 88 && i <= 92)
            cout << 'A';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// d building and a building
    {
        if (i == 30 || i == 34)
            cout << '#';
        else if (i == 60 || i == 64)
            cout << '*';
        else if (i == 88 || i == 92)
            cout << '#';
        else if (i > 34 && i < 60)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// d building and a building
    {
        if (i == 30 || i == 34)
            cout << '#';
        else if (i == 64)
            cout << '*';
        else if (i == 88 || i == 92)
            cout << '#';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// d building and a building
    {
        if (i >= 30 && i <= 34)
            cout << '#';
        else if (i == 60 || i == 64)
            cout << '*';
        else if (i >= 88 && i <= 92)
            cout << '#';
        else if (i > 34 && i < 60)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// a building to library
    {
        if (i == 60)
            cout << '*';
        else if (i >= 64 && i < 96)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90)
    {
        if (i == 60)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 96) /// a building road
    {
        if (i == 60)
            cout << '*';
        else if (i > 63)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 2) /// a building to library
    {
        loop(i, 0, 90)
        {
            if (i == 60 || i == 64)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 90) /// library
    {
        if (i >= 45 && i <= 49)
            cout << 'L';
        else if (i == 60 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// library
    {
        if (i == 45 || i == 49)
            cout << '#';
        else if (i > 49 && i < 61 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// library
    {
        if (i == 45 || i == 49)
            cout << '#';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// library
    {
        if (i >= 45 && i <= 49)
            cout << '#';
        else if (i > 49 && i < 61 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 3) /// library to chottor
    {
        loop(i, 0, 90)
        {
            if (i == 60 || i == 64)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 90) /// chottor
    {
        if (i >= 50 && i < 61)
            cout << '*';
        else if (i > 63 && i < 75)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 2) /// chottor
    {
        loop(i, 0, 90)
        {
            if (i == 50 || i == 74)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 90) /// ladies hall and chottor
    {
        if (i >= 10 && i <= 14)
            cout << 'H';
        else if (i == 50 || i == 74)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// ladies hall and chottor
    {
        if (i == 10 || i == 14)
            cout << '#';
        else if (i >= 14 && i <= 50 || i == 74)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// ladies hall and chottor
    {
        if (i == 10 || i == 14)
            cout << '#';
        else if (i == 74)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// ladies hall and chottor
    {
        if (i >= 10 && i <= 14)
            cout << '#';
        else if (i >= 14 && i <= 50 || i == 74)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 2) /// chottor
    {
        loop(i, 0, 90)
        {
            if (i == 50 || i == 74)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 90) /// chottor
    {
        if (i >= 50 && i < 61)
            cout << '*';
        else if (i > 63 && i < 75)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 2) /// lICT to chottor
    {
        loop(i, 0, 90)
        {
            if (i == 60 || i == 64)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 90) /// IICT
    {
        if (i >= 41 && i <= 49)
            cout << 'I';
        else if (i == 60 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// IICT
    {
        if (i == 41 || i == 49)
            cout << '#';
        else if (i > 49 && i <= 60 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// IICT
    {
        if (i == 41 || i == 49)
            cout << '#';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// IICT
    {
        if (i == 41 || i == 49)
            cout << '#';
        else if (i > 49 && i <= 60 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// IICT
    {
        if (i >= 41 && i <= 49)
            cout << '#';
        else if (i == 60 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 9) /// kilo road
    {
        loop(i, 0, 90)
        {
            if (i == 60 || i == 64)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 76)
    {
        if (i >= 50 && i <= 60)
            cout << 'G';
        else if (i >= 64 && i <= 74)
            cout << 'G';
        else
            cout << ' ';
    }
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
