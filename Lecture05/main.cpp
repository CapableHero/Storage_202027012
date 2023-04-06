// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다.거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>

int print_title_screen()
{
    std::cout << ("**********************************\n");
    std::cout << ("*                                *\n");
    std::cout << ("*           지렁이 게임          *\n");
    std::cout << ("*            Snake Bite          *\n");
    std::cout << ("*                                *\n");
    std::cout << ("*1. 게임시작                     *\n");
    std::cout << ("*2. 게임 설명                    *\n");
    std::cout << ("*3. 게임 랭킹 보기               *\n");
    std::cout << ("*4. 게임 종료 (esc)              *\n");
    std::cout << ("*                                *\n");
    std::cout << ("**********************************\n");

    return 0;
}

int print_introduction_screen()
{
    std::cout << ("**********************************\n");
    std::cout << ("*                                *\n");
    std::cout << ("*게임 설명 화면입니다.           *\n");
    std::cout << ("*시대가 어느시댄데 메뉴얼을 만드냐\n");
    std::cout << ("*                                *\n");
    std::cout << ("**********************************\n");
    std::cout << ("*타이틀 화면으로 돌아갈까여(Y/N) *\n");

    return 0;

}

int main()
{
    int game_state = 0;
    int is_game_runing = 1;
    int choise = 0;

    print_title_screen();
    while (is_game_runing)
    {
        char key_input = '0';
        switch (game_state)
        {
        case 0:

            key_input = _getch();

            if (key_input == '2') {
                game_state = 2;
                print_introduction_screen();
            }
            else if (key_input == '4' || key_input == 27)
                is_game_runing = 0;
            break;
        case 2:
            if (key_input == '2')
                key_input = 0;
            key_input = _getch();

            if (key_input != 'y') {
                key_input = _getch();
            }
            else {
                print_title_screen();
                game_state = 0;
                continue;

            }

        default:
            continue;
        }

    }
    return 0;
}

