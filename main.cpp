#include <iostream>
#include <random>

using namespace std;

int randomIntGenerator() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(1,20);

    int x = distribution(gen);

    return x;
}


int main() {

    int randomINT = randomIntGenerator();
    int bet,guess;

    cout << "Please Type a Bet (Min: 10) : ";
    cin >> bet;

    cout << "Please Type a Guess 1-20: ";
    cin >> guess;

    try {
        if(guess > 20 && bet < 10) {
            throw 50;
        }
    }

    catch (int errorCode1) {
        cout << "The guess should be between 1 with 20 and bet should be bigger than 10$!";
        terminate();
    }


    try {
        if(bet < 10) {
            throw 99;
        }
    }

    catch (int errorCode2){
        cout << "The min. bet should be bigger than 10$!";
        terminate();
    }

    try {
        if (guess > 20) {
            throw 22;
        }
    }

    catch (int errorCode3) {
        cout << "The guess should be between 1 with 20!";
        terminate();
    }

    if(guess == randomINT) {
        bet = bet * 2;
        cout << "Congratulations! You Win: " << bet;
    }
    else {
        bet = bet / 2;
        cout << "Unfortunately... You Lost! " << bet << "$";
        cout << endl << "The number was: " << randomINT;
    }

    return 0;
}

