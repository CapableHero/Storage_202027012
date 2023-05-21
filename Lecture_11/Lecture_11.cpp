#include <iostream>
#include <conio.h> // Windows에서 화살표 키 입력을 받기 위한 헤더

void clearScreen()
{
    // 화면을 지우는 코드 (Windows와 Linux/macOS에 따라 다름)
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void printMainMenu()
{
    clearScreen();
    std::cout << "Main Menu" << std::endl;
    std::cout << "1. Start Game" << std::endl;
    std::cout << "2. Instructions" << std::endl;
    std::cout << "3. Game Rankings" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void printBox(int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                std::cout << "#";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void waitForInput()
{
    while (true)
    {
        char key = _getch(); // 화살표 키 입력 받음
        if (key == 27) // ESC 키 입력 시 종료
            break;
    }
}

void printSelectionMenu()
{
    clearScreen();
    std::cout << "Do you want to exit? (Y/N)" << std::endl;
    std::cout << "Y";
    std::cout << "  N";
}

void handleInput()
{
    while (true)
    {
        char key = _getch(); // 화살표 키 입력 받음
        if (key == 75) // 왼쪽 화살표 키
        {
            std::cout << "\b\b"; // 현재 선택지 위치에서 왼쪽으로 2번 이동하여 노란색 출력
            std::cout << "\033[33m" << "Y" << "\033[0m"; // 노란색으로 출력
            std::cout << "  N";
        }
        else if (key == 77) // 오른쪽 화살표 키
        {
            std::cout << "\b\b"; // 현재 선택지 위치에서 왼쪽으로 2번 이동하여 노란색 출력
            std::cout << "Y  ";
            std::cout << "\033[33m" << "N" << "\033[0m"; // 노란색으로 출력
        }
        else if (key == 13) // 엔터 키
        {
            break;
        }
    }
}

int main()
{
    bool exitProgram = false;
    while (!exitProgram)
    {
        printMainMenu();

        char choice = _getch();
        clearScreen();

        switch (choice)
        {
        case '1':
        {
            printBox(10, 5);
            std::cout << std::endl;
            std::cout << "Press ESC to exit." << std::endl;
            waitForInput();
            break;
        }
        case '4':
        {
            printSelectionMenu();
            handleInput();
            std::cout << std::endl;
            if (_getch() == 'Y')
                exitProgram = true;
            break;
        }
        }
    }

    return 0;
}
