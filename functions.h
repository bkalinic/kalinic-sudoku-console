#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;

const int row = 9, column = 9;
const int leaderboard_size = 7;

int main();
string displayMainMenu(int);
string displayOperationMenu(int);
string displayModeSelectionMenu(int);
string displaySavingMenu(int);
void createTemplate(int solution[][column], int Template[][column], int board[][column], int solution_current[][column], int);
void validateOption(string&, string, string, string);
void validateMenu(string&, string, string);
void displayCredits(int);
void displayInstructions(int);
bool validateNumber(string);
void setCord(int, int);
void printSudoku(int board[][column], int Template[][column],int);
void printSudoku(int board[][column], int Template[][column]);
void takeInput(int Template[][column], int board[][column], int solution_current[][column], string slot,int&score);
bool checkRowColumnBox(int arr[][column], int i, int j, int valueToInsert);
void createHeading(string, char);
void setColor(int);
void shuffle(int arr[][column]);
void showLoadingScreen(int);
void sideMenu(string,string, int Template[][column], int board[][column],int user_score);
void getSolution(string, int Template[][column], int solution_current[][column]);
bool checkEnding(int baord[][column]);
void DisplayEndingScreen(int go);
void sortArray(int arr[], int size, string name[]);
