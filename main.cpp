#include <iostream>
#include <ctime>
#include "functions.h"

using namespace std;

int main() {

	ifstream Slot1_read("Slot1.txt"), Slot2_read("Slot2.txt"), Slot3_read("Slot3.txt");
	ifstream Template1_read("Template1.txt"), Template2_read("Template2.txt"), Template3_read("Template3.txt");
	ifstream Solved1_read("Solved1.txt"), Solved2_read("Solved2.txt"), Solved3_read("Solved3.txt");
	ifstream Slot1_score_read("Slot1_score.txt"), Slot2_score_read("Slot2_score.txt"), Slot3_score_read("Slot3_score.txt");

	int solution1[row][column] = {
								4, 3, 5, 2, 6, 9, 7, 8, 1,
								6, 8, 2, 5, 7, 1, 4, 9, 3,
								1, 9, 7, 8, 3, 4, 5, 6, 2,
								8, 2, 6, 1, 9, 5, 3, 4, 7,
								3, 7, 4, 6, 8, 2, 9, 1, 5,
								9, 5, 1, 7, 4, 3, 6, 2, 8,
								5, 1, 9, 3, 2, 6, 8, 7, 4,
								2, 4, 8, 9, 5, 7, 1, 3, 6,
								7, 6, 3, 4, 1, 8, 2, 5, 9};
	int solution2[row][column] = {
								7, 3, 5, 6, 1, 4, 8, 9, 2,
								8, 4, 2, 9, 7, 3, 5, 6, 1,
								9, 6, 1, 2, 8, 5, 3, 7, 4,
								2, 8, 6, 3, 4, 9, 1, 5, 7,
								4, 1, 3, 8, 5, 7, 9, 2, 6,
								5, 7, 9, 1, 2, 6, 4, 3, 8,
								1, 5, 7, 4, 9, 2, 6, 8, 3,
								6, 9, 4, 7, 3, 8, 2, 1, 5,
								3, 2, 8, 5, 6, 1, 7, 4, 9};
	int solution3[row][column] = {
								1, 5, 2, 4, 8, 9, 3, 7, 6,
								7, 3, 9, 2, 5, 6, 8, 4, 1,
								4, 6, 8, 3, 7, 1, 2, 9, 5,
								3, 8, 7, 1, 2, 4, 6, 5, 9,
								5, 9, 1, 7, 6, 3, 4, 2, 8,
								2, 4, 6, 8, 9, 5, 7, 1, 3,
								9, 1, 4, 6, 3, 7, 5, 8, 2,
								6, 2, 5, 9, 4, 8, 1, 3, 7,
								8, 7, 3, 5, 1, 2, 9, 6, 4};

	int Template[row][column] = {0};
	int board[row][column] = {0};
	int solution_current[row][column] = {0};
	int user_score = 0;

	string option_mainMenu, option_operationMenu, option_difficultyLevel, option_savingMenu;
	do {
		
		option_mainMenu = displayMainMenu(1);
		if (option_mainMenu == "a")
		{
			displayCredits(1);
			continue;
		}

		if (option_mainMenu == "i") {
			do {
				option_operationMenu = displayOperationMenu(1);

				if (option_operationMenu == "n") {
					user_score = 10000;

					for (int i = 0; i < row; i++) {
						for (int j = 0; j < column; j++) {
							Template[i][j] = 0;
							board[i][j] = 0;
						}
					}

					int hints_total = 0; 
					option_difficultyLevel = displayModeSelectionMenu(1);
					if (option_difficultyLevel == "l") {
						hints_total = 45;
					}
					else if (option_difficultyLevel == "s") {
						hints_total = 30;
					}
					else {
						hints_total = 15;
					}

					srand((unsigned int)time(0));
					int choiceOfSolution = rand() % 3;
					if (choiceOfSolution == 0)
						createTemplate(solution1, Template, board, solution_current, hints_total);
					if (choiceOfSolution == 1)
						createTemplate(solution2, Template, board, solution_current, hints_total);
					if (choiceOfSolution == 2)
						createTemplate(solution3, Template, board, solution_current, hints_total);
					option_savingMenu = displaySavingMenu(1);

					if (option_savingMenu == "1") {
						ofstream Slot1_write("Slot1.txt"), Template1_write("Template1.txt"), Solved1_write("Solved1.txt"), Slot1_score_write("Slot1_score.txt");
						Slot1_score_write << user_score;
						for (int i = 0; i < row; i++) {
							for (int j = 0; j < column; j++) {
								Slot1_write << board[i][j] << " ";
								Template1_write << Template[i][j] << " ";
								Solved1_write << solution_current[i][j] << " ";
							}
						}
						Slot1_write.close();
						Template1_write.close();
						Solved1_write.close();
						Slot1_score_write.close();
					}
					if (option_savingMenu == "2") {
						ofstream Slot2_write("Slot2.txt"), Template2_write("Template2.txt"), Solved2_write("Solved2.txt"), Slot2_score_write("Slot2_score.txt");
						Slot2_score_write << user_score;
						for (int i = 0; i < row; i++) {
							for (int j = 0; j < column; j++) {
								Slot2_write << board[i][j] << " ";
								Template2_write << Template[i][j] << " ";
								Solved2_write << solution_current[i][j] << " ";
							}
						}
						Slot2_write.close();
						Template2_write.close();
						Solved2_write.close();
						Slot2_score_write.close();
					}
					if (option_savingMenu == "3") {
						ofstream Slot3_write("Slot3.txt"), Template3_write("Template3.txt"), Solved3_write("Solved3.txt"), Slot3_score_write("Slot3_score.txt");
						Slot3_score_write << user_score;

						for (int i = 0; i < row; i++) {
							for (int j = 0; j < column; j++) {
								Slot3_write << board[i][j] << " ";
								Template3_write << Template[i][j] << " ";
								Solved3_write << solution_current[i][j] << " ";
							}
						}
						Slot3_write.close();
						Template3_write.close();
						Solved3_write.close();
						Slot3_score_write.close();
					}
				}

				else if (option_operationMenu == "s") {
					option_savingMenu = displaySavingMenu(1);
					if (option_savingMenu == "1") {
						if (!Slot1_read.is_open()) {
							cout << "**** SLOT 1 JE PRAZAN, ZAPOCNI NOVU IGRU ili ODABERI DRUGI SLOT ****\n\n";
							system("pause");
							continue;
						}
						else {
							Slot1_score_read >> user_score;
							for (int i = 0; i < row; i++) {
								for (int j = 0; j < column; j++) {
									Slot1_read >> board[i][j];
									Template1_read >> Template[i][j];
									Solved1_read >> solution_current[i][j];
								}
							}
							Slot1_read.close();
							Template1_read.close();
							Solved1_read.close();
							Slot1_score_read.close();
						}
					}
					else if (option_savingMenu == "2") {
						if (!Slot2_read.is_open()) {
							cout << "**** SLOT 2 JE PRAZAN, ZAPOCNI NOVU IGRU ili ODABERI DRUGI SLOT ****\n\n";
							system("pause");
							continue;
						}
						else {
							Slot2_score_read >> user_score;
							for (int i = 0; i < row; i++) {
								for (int j = 0; j < column; j++) {
									Slot2_read >> board[i][j];
									Template2_read >> Template[i][j];
									Solved2_read >> solution_current[i][j];
								}
							}
							Slot2_read.close();
							Template2_read.close();
							Solved2_read.close();
							Slot2_score_read.close();
						}
					}
					else if (option_savingMenu == "3") {
						if (!Slot3_read.is_open()) {
							cout << "**** SLOT 3 JE PRAZAN, ZAPOCNI NOVU IGRU ili ODABERI DRUGI SLOT ****\n\n";
							system("pause");
							continue;
						}
						else {
							Slot3_score_read >> user_score;
							for (int i = 0; i < row; i++) {
								for (int j = 0; j < column; j++) {
									Slot3_read >> board[i][j];
									Template3_read >> Template[i][j];
									Solved3_read >> solution_current[i][j];
								}
							}
							Slot3_read.close();
							Template3_read.close();
							Solved3_read.close();
							Slot3_score_read.close();
						}
					}
				}

				else if (option_operationMenu == "p")
					continue;

				showLoadingScreen(1);

				do {

					takeInput(Template, board, solution_current, option_savingMenu, user_score);

					if (checkEnding(board)) {
						DisplayEndingScreen(1);

						if (option_savingMenu == "1")
						{
							remove("Slot1.txt");
							remove("Template1.txt");
							remove("Solved1.txt");
							remove("Slot1_score.txt");
						}
						else if (option_savingMenu == "2")
						{
							remove("Slot2.txt");
							remove("Template2.txt");
							remove("Solved2.txt");
							remove("Slot2_score.txt");
						}
						else if (option_savingMenu == "3")
						{
							remove("Slot3.txt");
							remove("Template3.txt");
							remove("Solved3.txt");
							remove("Slot1_score.txt");
						}
					}

				} while (!checkEnding(board));

			} while (option_operationMenu != "p");
		}

	} while (1);

	return 0;
}
