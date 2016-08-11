// auto_scoring_main.cc
// 2016. 8. 11

#include <stdlib.h> // system()
#include <unistd.h> // chdir()
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv) {

  // change directory and make .exe file
  string file_path = argv[1];
  int score = 0;
  chdir(("./" + file_path).c_str());
  system("make");

  for(int i = 1; i <= 5; i++) {
    system(("./" + file_path + ".exe " + "< " + to_string(i) + ".in " +
            "> result.out").c_str());

    ifstream answer, mine;
    string answerLine, myLine;

    // file open
    answer.open(to_string(i) + ".out");
    mine.open("result.out");

    // getline and compare;
    int lineNum = 1;
    bool correct = true;
    while(getline(answer, answerLine) && getline(mine, myLine)) {
      if(answerLine != myLine) {
        cout << "No." << i << ", LINE " << lineNum << ": " <<
                myLine << " MUST BE " << answerLine << endl;
        correct = false;
      }

      lineNum++;
    }
    if(correct)
      score += 2;
  }
  cout << "SCORE: " << score << endl;

  return 0;
}
