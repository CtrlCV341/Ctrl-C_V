#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#define loop(i, x, y) for (int i = x; i < y; i++)
#define eline cout << endl;
#define build cout << '#'
#define road cout << '*'
#define space cout << ' '
const int width = 50;  // Random
const int height = 50; // Random
using namespace std;
struct position
{
    int x;
    int y;
};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // copied, used to set the position of the cursor
}
void disAvator(const position &playerPos, const position &destPos)
{
    gotoxy(playerPos.x, playerPos.y);
    cout << "@";

    gotoxy(destPos.x, destPos.y);
    cout << "()";
}
void border()
{
}

void mapSUST()
{
    loop(i, 0, 84) /// shahporan hall
    {
        if (i > 76)
            cout << 'S';
        else
            cout << ' ';
    }
    cout << endl;
    loop(i, 0, 90) /// shahporan hall
    {
        if (i == 77 || i == 83)
            cout << 'S';
        else
            cout << ' ';
    }
    cout << endl;
    loop(i, 0, 84) /// shahporan hall
    {
        if (i > 76)
            cout << 'S';
        else
            cout << ' ';
    }
    cout << endl;
    loop(i, 0, 130) /// shahporan hall road
    {
        if (i < 60)
            cout << ' ';
        else if (i == 129)
            cout << '*';
        else
            cout << '*';
    }
    cout << endl;
    loop(i, 0, 130) /// shahporan hall
    {
        if (i == 60)
            cout << '*';
        else if (i == 129)
            cout << '*';
        else
            cout << ' ';
    }
    cout << endl;
    loop(i, 0, 130) /// shahporan hall
    {
        if (i == 60)
            cout << '*';
        else if (i == 129)
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
    loop(i, 0, 70) /// road + b building
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i > 64)
            cout << 'B';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 70) /// road + b building
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i == 65 || i == 69)
            cout << 'B';
        else
            cout << ' ';
    }
    eline;
    for (int i = 0; i < 90; i++) /// road + c building roof + b building
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i == 65 || i == 69)
            cout << 'B';
        else if (i >= 85)
            cout << 'C';
        else
            cout << ' ';
    }
    eline;
    for (int i = 0; i < 120; i++) /// road + c building roof + b building
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i >= 65 && i <= 69)
            cout << 'B';
        else if (i == 85 || i == 89)
            cout << 'C';
        else
            cout << ' ';
    }
    eline;
    for (int i = 0; i < 120; i++) /// road + c building roof + b building
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i == 85 || i == 89)
            cout << 'C';
        else
            cout << ' ';
    }
    eline;
    for (int i = 0; i < 130; i++) /// road + c building roof
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i >= 85 && i <= 89)
            cout << 'C';
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
        else if (i >= 75 && i <= 78)
            cout << 'T';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// e build
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i == 92 || i == 96)
            cout << 'E';
        else if (i == 75 || i == 78)
            cout << 'T';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// e build
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i == 92 || i == 96)
            cout << 'E';
        else if (i >= 75 && i <= 78)
            cout << 'T';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// E build
    {
        if (i == 60 || i == 64)
            road;
        else if (i >= 92 && i <= 96)
            cout << 'E';
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
            cout << 'D';
        else if (i == 60 || i == 64)
            cout << '*';
        else if (i == 88 || i == 92)
            cout << 'A';
        else if (i > 34 && i < 60)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// d building and a building
    {
        if (i == 30 || i == 34)
            cout << 'D';
        else if (i == 64)
            cout << '*';
        else if (i == 88 || i == 92)
            cout << 'A';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// d building and a building
    {
        if (i >= 30 && i <= 34)
            cout << 'D';
        else if (i == 60 || i == 64)
            cout << '*';
        else if (i >= 88 && i <= 92)
            cout << 'A';
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
            cout << 'L';
        else if (i > 49 && i < 61 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// library
    {
        if (i == 45 || i == 49)
            cout << 'L';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// library
    {
        if (i >= 45 && i <= 49)
            cout << 'L';
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
            cout << 'H';
        else if (i >= 14 && i <= 50 || i == 74)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// ladies hall and chottor
    {
        if (i == 10 || i == 14)
            cout << 'H';
        else if (i == 74)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// ladies hall and chottor
    {
        if (i >= 10 && i <= 14)
            cout << 'H';
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
            cout << 'I';
        else if (i > 49 && i <= 60 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// IICT
    {
        if (i == 41 || i == 49)
            cout << 'I';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// IICT
    {
        if (i == 41 || i == 49)
            cout << 'I';
        else if (i > 49 && i <= 60 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
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
bool obstacle(const position &newPos)
{
    return false;
}

bool finalDest(const position &playerPos, const position &destPos)
{
    if (playerPos.x == destPos.x && playerPos.y == destPos.y)
        return true;
    return false;
}

int main()
{
    system("mode con: lines=700 cols=700");
    position playerPos = {61, 4};
    position destPos;

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    gotoxy(width / 2, height / 2);
    cout << "                     Hey! Welcome to GTAsust game app" << endl;
    cout << "**********************************************************************************" << endl;
    cout << "This game is about Shahjalal University of Science and Technology(SUST) where you" << endl;
    cout << "can travel at any point of the university and reach to your desired destination" << endl;
    cout << endl;

    system("pause");

    system("cls");
    cout << "Where do you want to go?" << endl;
    cout << "1.IICT" << endl;
    cout << "2.A-building" << endl;
    cout << "3.B-building" << endl;
    cout << "You're Answer: ";
    int userDest;
    cin >> userDest;

    switch (userDest)
    {
    case 1:
        destPos = {20, height - 2}; // random
        break;
    case 2:
        destPos = {width - 3, 5}; // random
        break;
    case 3:
        destPos = {width / 2, height / 2}; // random
        break;
    default:
        break;
    }
    system("cls");
    border();
    mapSUST();
    disAvator(playerPos, destPos);
    while (true)
    {

        position newPos = playerPos;

        if (_kbhit())
        {
            char key = _getch();

            if (key == 80)
            {
                newPos.y++;
            }
            else if (key == 72)
            {
                newPos.y--;
            }

            else if (key == 77)
            {
                newPos.x++;
            }

            else if (key == 75)
            {
                newPos.x--;
            }
        }

        if (!obstacle(newPos))
        {
            gotoxy(playerPos.x, playerPos.y);
            cout << " ";

            playerPos = newPos;

            disAvator(playerPos, destPos);
        }

        if (finalDest(playerPos, destPos))
            break;

    }
    system("pause");
}
