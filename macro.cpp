#include <stdio.h>
#include <stdlib.h>
#include<cstdlib>
#define WINVER 0x0500
#include <windows.h>
#include <iostream>
#include<thread>
#include<string>
using namespace std;

bool firstTime = true;
string commands;
int offset;
int newposX;
int newposY;



void commandLine() {
    cout << "Multi Thread test" << endl;
    Sleep(1000);
    cout << "Testing Again" << endl;
}
void runTime() {
    for (int i = 1; ; i++) {

        
        cout << "\r" << "Macro run time:" << i << flush;
        Sleep(1000);
    }
}

void Sneaking() {
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    ip.ki.wVk = 0x10;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
}

void MovingLeft(int duration) {
    // Set up a generic keyboard event.
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scancode for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press the "A" key
    ip.ki.wVk = 0x41;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(duration);

    // Release the "A" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
}

void MovingRight(int duration) {
    INPUT ip;
    
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; 
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    
    ip.ki.wVk = 0x44;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(duration);


    ip.ki.dwFlags = KEYEVENTF_KEYUP; 
    SendInput(1, &ip, sizeof(INPUT));
}

void MovingForward(int duration) {
    INPUT ip;

    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;


    ip.ki.wVk = 0x57;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(duration);


    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

void exitConsole() {
    while (true){
        if (GetKeyState(VK_CONTROL) & 0x8000)
        {
            abort();
        }
    }
}

int main()
{
    cin >> commands;
    if (commands == "farm") {
        if (firstTime == true) {
            firstTime = false;
            cout << "Macro Starting in:" << endl;
            for (int i = 5; i > 0; --i) {
                Sleep(1000);
                cout << "\r" << i << flush;
            }
            cout << "" << endl;
            cout << "Initiated Macro" << endl;

            thread rt(runTime);
            thread ec(exitConsole);
            while (true) {
                MovingLeft(21000);
                Sleep(350);
                MovingForward(2000);
                Sleep(350);
                MovingRight(21000);
                Sleep(350);
                MovingForward(2000);
            }

            ec.join();
            rt.join();
        }
    }
    else if (commands == "mining") {
        if (firstTime == true) {
            firstTime = false;
            cout << "Macro Starting in:" << endl;
            for (int i = 5; i > 0; --i) {
                Sleep(1000);
                cout << "\r" << i << flush;
            }
            cout << "" << endl;
            cout << "Initiated Macro" << endl;

            thread rt(runTime);
            thread ec(exitConsole);
            while (true) {
                Sneaking();
                MovingRight(8800);
                MovingLeft(8800);
            }

            ec.join();
            rt.join();
        }
    }
    return 0;

}




//Ignore
/*            for (int i = 0; i <= 8; i++) {
                MovingLeft();
                Sleep(350);
                MovingForward();
                Sleep(350);
                MovingRight();
                Sleep(350);
                MovingForward();
                Sleep(350);
            }
            MovingLeft();
            Sleep(350);
            for (int i = 0; 1 <= 8; i++) {
                MovingLeft();
                Sleep(350);
                MovingForward();==========
                Sleep(350);
                MovingRight();
                Sleep(350);
                MovingForward();
                Sleep(350);
            }
            MovingLeft();
            Sleep(350);
            MovingForward();
            Sleep(350);
            MovingRight();
            Sleep(350);
            for (int i = 0; i <= 8; ++i) {
                MovingRight();
                Sleep(350);
                MovingForward();
                Sleep(350);
                MovingLeft();
            }*/
