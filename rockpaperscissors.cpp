#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits> 

class Game {

private:
  int played;

public:
  int get() { return played; }

  int set(int played) {
    this->played = played;
    return played;
  }

  char getinput() {
    char input;

    do {
      std::cout << "Enter 'r' for Rock\n";
      std::cout << "Enter 'p' for Paper\n";
      std::cout << "Enter 's' for Scissor\n";
      std::cout << "Enter: ";
      std::cin >> input;
    } while (input != 'r' && input != 'p' && input != 's');

    switch (input) {

    case 'r':
      std::cout << "Your choice = Rock\n";
      break;
    case 'p':
      std::cout << "Your choice = Paper\n";
      break;
    case 's':
      std::cout << "Your choice = Scissor\n";
      break;
    }
    return input; // needs to return final product of this function "input"
  }

  char computerinput() {

    srand(time(0));
    int randnum = rand() % 3;

    switch (randnum) {
    case 0:
      std::cout << "Computer = Rock\n";
      return 'r';
    case 1:
      std::cout << "Computer = Paper\n";
      return 'p';
    case 2:
      std::cout << "Computer = Scissors\n";
      return 's';
    }
    return randnum;
  }

  void final(char player, char computer, int &wins, int &lose) {

    if (player == 'r' && computer == 'p') {
      std::cout << "You lose!\n";
      lose ++;
    } else if (player == 'r' && computer == 's') {
      std::cout << "You win!\n";
      wins ++;
    } else if (player == 'r' && computer == 'r') {
      std::cout << "Its a tie!\n";
    }

    else if (player == 'p' && computer == 's') {
      std::cout << "You lose!\n";
      lose ++;
    } else if (player == 'p' && computer == 'r') {
      std::cout << "You win!\n";
      wins ++;
    } else if (player == 'p' && computer == 'p') {
      std::cout << "Its a tie!\n";
    }

    if (player == 's' && computer == 'r') {
      std::cout << "You lose!\n";
      lose ++;
    } else if (player == 's' && computer == 'p') {
      std::cout << "You win!\n";
      wins ++;
    } else if (player == 's' && computer == 's') {
      std::cout << "Its a tie!\n";
    }

    std::cout << "Player = " << wins << "\nComputer = " << lose << "\n";
  }
};

int main() {

  int main;
  Game game;
  int times = game.set(0);
  int playerwin = 0;
  int compwin = 0;

  while (true) {

    std::cout << "Enter '1' to play & '0' to quit: ";
    std::cin >> main;

    if (main == 0) {
      break;
    } else if (main == 1) {
      char play, comp;

      play = game.getinput();
      comp = game.computerinput();
      game.final(play, comp, playerwin, compwin);
      times++;
      std::cout << "You have played " << times << " times.\n";
    }
  }
}
