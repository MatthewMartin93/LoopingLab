#include <iostream>
#include <random>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
string days[7];
string week[7] = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int supplies = 0;
int energy = 5;
int choice;
int day = 1;
int randomNum;
bool guessed = false;
int guess;
char give;
random_device rd;
uniform_int_distribution<int> dist(100, 999);
int lockCombination = dist(rd); // Generate the lock combination once
int main() {
    cout << dist(rd) << endl;
   //Exercise 1
    for (int i = 0; i < 7; i++) {
        cout << "Enter a quote" << endl;
        cin >> days[i];
    }
    for (int i = 0; i < 7; i++) {
        cout << week[i] << ": ";
        cout << days[i] << endl;
    }
    //Exercise 2
    while(supplies < 10) {
        if (energy <= 0) {
            cout << "YOU LOSE" << endl;
            cout << "You survived " << day << " days and collected " << supplies << " supplies." << endl;
        }
        cout << endl;
        cout << "Day " << day << endl;
        cout << "Supplies: " << supplies << endl;
        cout << "Energy: " << energy << endl;
        cout << "1. Search for supplies" << endl;
        cout << "2. Rest" << endl;
        cin >> choice;
        if (choice == 1) {
            supplies++;
            energy--;
            day++;
        }
        else if (choice == 2) {
            energy += 2;
            day++;
        }
        else {
            cout << "NICE TRY PAL -5 ENERGY";
            energy -= 5;
            day += 3;
        }
        if (supplies == 10) {
            cout << "YOU WIN!" << endl;
            cout << "It took you " << day << " days to collect your supplies!" << endl;
        }
    }
    //Exercise 3


    do {
        cout << "Guess the lock combination" << endl;
        cin >> guess;
        if (guess == lockCombination) { // Compare guess with the fixed lock combination
            guessed = true;
            cout << "You guessed the combination. The box was empty." << endl;
        } else {
            cout << "Your guess was incorrect." << endl;
            cout << "Give up? (y/n)" << endl;
            cin >> give;
            if (give == 'y') {
                cout << "You gave up." << endl;
                break;
            }
        }
    } while (!guessed); // Continue until guessed is true

    return 0;
}
