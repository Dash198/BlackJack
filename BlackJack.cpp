// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "HitStand.h"
#include <vector>
using namespace std;

int main()
{
    HitStand hs;
    int ch = 1;
    while (ch == 1) {
        int ps = 0, pc = 0;;
        while (ps <= 21) {
            cout << "Press 1 to Hit, 2 to Stand\n";
            cin >> pc;
            if (pc == 1) {
                ps += hs.Hit();
                cout << "Current Score " << ps << "\n";
                if (ps > 21)
                {
                    cout << "Busted!";
                    ps = 0;
                    break;
                }
            }
            else if (pc == 2)
                break;
            else
                cout << "Wrong Input!\n";
        }
        vector<int> score{ 0,0,0,0 };
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                score[i] += hs.Hit();
            if (score[i] > 21)
                score[i] = 0;
        }
        score[3] = ps;
        int temp = 0;
        string temps;
        vector<string> name{"CPU1","CPU2","CPU3","You"};
        for (int i = 0; i < 4; i++) {
            for(int j=i+1; j<4; j++)
            if (score[i] < score[j]) {
                temp = score[i];
                score[i] = score[j];
                score[j] = temp;
                temps = name[i];
                name[i] = name[j];
                name[j] = temps;
            }
        }
        cout << "Scores\n\n";
        for (int i = 0; i < 4; i++) {
            cout << name[i] << " : ";
            if (score[i] == 0) {
                cout << "Busted!\n";
            }
            else
                cout << score[i] << "\n";
        }
        cout << "\n";
        if (ps == score[0])
            cout << "First Place!\n";
        else if (ps == score[1])
            cout << "Second Place!\n";
        else if (ps == score[2])
            cout << "Third Place!\n";
        else if (ps == score[3])
            cout << "Last Place!\n";
        cout << "\nPress 1 to play again, any other number to stop\n";
        cin >> ch;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
