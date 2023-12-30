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
void disAvator(const position &playerPos,string s)
{
    gotoxy(playerPos.x, playerPos.y);
    cout << s;

    //gotoxy(destPos.x, destPos.y);
    //cout << "()";
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
    // gotoxy(82,4);   //s
    // cout<<"*";
    gotoxy(33,12);      //o
    cout<<"*";
    gotoxy(33,21);      //m
    cout<<"*";
    // gotoxy(77,30);      //cafe
    // cout<<"*";
    // gotoxy(87,30);  //c
    // cout<<"*";
    gotoxy(99,30);  //e
    cout<<"*";
    // gotoxy(36,40);      //d
    // cout<<"*";
    gotoxy(95,43);      //a
    cout<<"*";
    // gotoxy(51,49);      //L
    // cout<<"*";
    // gotoxy(16,59);      //h
    // cout<<"*";
    // gotoxy(51,68);      //i
    // cout<<"*";
    gotoxy(62,80);      //maingate
    cout<<"*";
}
bool obstacle(const position &newPos)
{
    loop(i, 60, 130){ /// shahporan hall road
        if(newPos.x>=i&&newPos.y==3)return true;
    }
    if((newPos.x==60||newPos.x==129)&&newPos.y==4)return true;  /// shahporan hall
    loop(i, 63, 130){    /// shahporan hall
        if(newPos.x>=i&&newPos.y==5)return true;
    }
    loop(i,5,81){   /// two roads
        if((newPos.x==60||newPos.x==64)&&newPos.y==i&&(newPos.y!=12||newPos.x==64)&&(newPos.y!=21||newPos.x==64)&&(newPos.y!=30||newPos.x==60)&&(newPos.y!=40||newPos.x==64)&&(newPos.y!=43||newPos.x==60)&&(newPos.y!=49||newPos.x==64)&&(newPos.y!=68||newPos.x==64)&&(newPos.y>=63||newPos.y<=54))return true;
    }
    loop(i, 0, 61){     /// auditorium,minar,D-building,library,IICT,golchottor
        if(newPos.x==i&&(newPos.y==11||newPos.y==13||newPos.y==20||newPos.y==22||newPos.y==39||newPos.y==41||newPos.y==48||newPos.y==50||newPos.y==67||newPos.y==69||newPos.y==54||newPos.y==63))return true;
    }
    loop(i,64,100){     // C-building,A-building, gol chottor
        if(newPos.x==i&&(newPos.y==29||newPos.y==31||newPos.y==42||newPos.y==44||newPos.y==54||newPos.y==63)){return true;}
    }
    loop(i,54,64){      // golchottor
        //if(i==59)continue;
        if((newPos.x==50||newPos.x==74)&&(newPos.y==i)&&(newPos.y!=59||newPos.x==74))return true;
    }
    loop(i,0,51){   //hall
        if(newPos.x==i&&(newPos.y==58||newPos.y==60))return true;
    }
    if((newPos.x==33&&newPos.y==12)||(newPos.x==34&&newPos.y==21)||(newPos.x==99&&newPos.y==30)||(newPos.x==35&&newPos.y==40)||(newPos.x==95&&newPos.y==43)||(newPos.x==50&&newPos.y==49)||(newPos.x==15&&newPos.y==59)||(newPos.x==50&&newPos.y==68)||(newPos.x==62&&newPos.y==81))return true;
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
    position playerPos = {62,80};
    position destPos;

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    gotoxy(width / 2, height / 2);
    cout << "Hey! Welcome to GTAsust game app" << endl;
    cout << "**********************************************************************************" << endl;
    cout << "This game is about Shahjalal University of Science and Technology(SUST) where you" << endl;
    cout << "can travel at any point of the university and reach to your desired destination" << endl;
    cout << endl;

    system("pause");

    system("cls");
    cout << "Where do you want to go?" << endl;
    cout << "1.Shahporan Hall" << endl;
    cout << "2.Auditorium" << endl;
    cout << "3.Shahid Minar" << endl;
    cout << "4.B-building" << endl;
    cout << "5.Cafeteria" << endl;
    cout << "6.C-building" << endl;
    cout << "7.E-building" << endl;
    cout << "8.D-building" << endl;
    cout << "9.A-building" << endl;
    cout << "10.Central Library" << endl;
    cout << "11.Ladies Hall" << endl;
    cout << "12.IICT" << endl;
    cout << "You're Answer: ";
    int userDest;
    cin >> userDest;

    switch (userDest)
    {
    case 1:
        destPos = {80,4}; // s
        break;
    case 2:
        destPos = {34,12}; // o
        break;
    case 3:
        destPos = {34,21}; // m
        break;
    case 4:
        destPos = {62,25}; // b
        break;
    case 5:
        destPos = {77,30}; // cafe
        break;
    case 6:
        destPos = {87,30}; // c
        break;
    case 7:
        destPos = {94,30}; // e
        break;
    case 8:
        destPos = {36,40}; // d
        break;
    case 9:
        destPos = {90,43}; // a
        break;
    case 10:
        destPos = {51,49}; // L
        break;
    case 11:
        destPos = {16,59}; // h
        break;
    case 12:
        destPos = {51,68}; // i
        break;
    default:
        cout<<"Does Not Exist"<<endl;
        break;
    }
    system("cls");
    border();
    mapSUST();
    disAvator(playerPos,"@");
    if(abs(playerPos.y-destPos.y)<=49)disAvator(destPos,"()");
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
            if(playerPos.y<=49){gotoxy(0,0);cout<<"";}
            //if(playerPos.y>=50){gotoxy(0,80);cout<<"";}
            //if(playerPos.y>)
            disAvator(playerPos,"@");
            if(abs(playerPos.y-destPos.y)<=45)disAvator(destPos,"()");
        }

        if (finalDest(playerPos, destPos))
            break;

    }
    system("cls");
    cout<<"Congrats! you've reached your destination"<<endl;
    loop(i,0,50){
        loop(j,0,40 )cout<<"BLAH ";
        eline
    }
    system("pause");
}
