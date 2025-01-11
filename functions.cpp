#include <iostream>
#include"functions.h"

using namespace std;

string displayMainMenu(int go) {
	system("CLS");
	system("color f8");
	string heading = "\n\t\t\t\t      DOBRODOSLI U SUDOKU\n";
	createHeading(heading, '=');
	string option;
	cout << "\n\t<i> IGRAJ\n";
	cout << "\t<a> AUTOR\n\n";
	validateMenu(option, "i", "a");
	return option;

}

string displayOperationMenu(int go) {
	system("CLS");
	system("color f1");
	string heading = "\t\t\t	GLAVNI IZBORNIK";
	createHeading(heading, '=');
	string option="garbage";
	cout << "\n\t<n> NOVA IGRA\n";
	cout << "\t<s> SPREMLJENA IGRA\n";
	cout << "\t<p> POVRATAK NAZAD\n\n";
    validateOption(option, "n", "s", "p");
	return option;
}

string displayModeSelectionMenu(int) {
	system("CLS");
	system("color 1f");
	string heading = "\t\t\tODABIR MODA";
	createHeading(heading, '=');
	string option = "garbage";
	cout << "\nOdaberite tezinu igre :\n";
	cout << "\n\t<l> ZA LAGANO\n";
	cout << "\t<s> ZA SREDNJE\n";
	cout << "\t<t> ZA TESKO\n\n";
	validateOption(option, "l", "s", "t");
	return option;
}

string displaySavingMenu(int go) {
	system("CLS");
	system("color 4e");
	string heading = "\t\t\tIZBORNIK ZA SPREMANJE";
	
	createHeading(heading, '=');
	string option = "garbage";
	cout << "ODABERITE SLOT ZA SPREMANJE :\n\n";
	cout << "\n\t<1> ZA SLOT-1\n";
	cout << "\t<2> ZA SLOT-2\n";
	cout << "\t<3> ZA SLOT-3\n\n";
	validateOption(option, "1", "2", "3");
	return option;
}
void createTemplate(int solution[][column], int Template[][column], int board[][column], int solution_current[][column], int hints_total) {
	shuffle(solution); 
	shuffle(solution);
	shuffle(solution);

	for (int i = 0; i < row; i++) {
		for (int j=0;j<column;j++) {
			solution_current[i][j] = solution[i][j];
		}
	}

	for (int n = 0; n < hints_total; n++) {
		int i = rand() % 9;
		int j = rand() % 9;
		Template[i][j] = solution[i][j];
	}

	for (int copy_row = 0; copy_row < row; copy_row++) {
		for (int copy_column = 0; copy_column < column; copy_column++)
		{
			board[copy_row][copy_column] = Template[copy_row][copy_column];
		}
	}

}
void validateOption(string&input, string op1, string op2, string op3) {
	do {
		cout << "Upisi svoj odabir : ";
		cin >> input;
		cin.ignore();
		if (input != op1 && input != op2 && input != op3)
		{
			cout << "Neispravan unos. Pokusaj ponovo\n";
		}
	} while (input != op1 && input != op2 && input != op3);

}

void validateMenu(string& input, string op1, string op2) {
	do {
		cout << "Upisi svoj odabir : ";
		cin >> input;
		cin.ignore();
		if (input != op1 && input != op2)
		{
			cout << "Neispravan unos. Pokusaj ponovo\n";
		}
	} while (input != op1 && input != op2);

}

void displayCredits(int go) {
	system("CLS");
	system("Color 08");
	string text = "\t\t\t AUTOR";
	createHeading(text, '~');
	setColor(80);
	
	cout << "\n\t\t\t\t\t    BARTUL KALINIC    \n\n\n";

	setCord(0, 3);
	setColor(8);
	cout << endl << endl;
	cout << "\t\t\t\t\t SVEUCILISTE U SPLITU\n\n\n";
	cout << "\t\t\t\t SVEUCILISNI ODJEL ZA STRUCNE STUDIJE\n\n\n";
	cout << "\t\t\t\t\t   SMJER RACUNARSTVO\n\n\n";
	
	system("\n\n\npause");
}

void displayInstructions(int go) {
	system("CLS");
	system("color 56");
	cout << "credits ABC";
	system("pause");
}

bool validateNumber(string num) {
	string arr[9] = { "1","2","3","4","5","6","7","8","9" };
	for (int i = 0; i < 9; i++) {
		if (num == arr[i])
			return true;
	}
	cout << "Dopusteni su samo brojevi izmedju 1 i 9!\n";
	return false;
}

void setCord(int x, int y) {
	COORD c = {(short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void printSudoku(int board[][column],int Template[][column], int score) {
	system("CLS");
	system("color 04");
	cout << endl << endl;
	for (int i = 0; i < row; i++) {
		cout << "\t\t\t";
		for (int j = 0; j < column; j++) {
			if (board[i][j] == 0) {
				cout << "-    ";
				if (j % 3 == 2)  cout << " ";
			}
			else {
				if (j % 3 == 2) {
					if (board[i][j] == Template[i][j]) setColor(2);
				    cout << board[i][j] << " ";
					if (board[i][j] == Template[i][j]) setColor(4);
			    }
				else {
					if (board[i][j] == Template[i][j]) setColor(2);
					cout << board[i][j];
					if (board[i][j] == Template[i][j]) setColor(4);
				}
				cout << "    ";
			}
		}
		cout << endl << endl;
	}
	cout << endl << endl;
	setColor(8);
	int x = 20, y = 1, a = 18, b = 50;
	for (int i = 0; i < a; i++) {
		setCord(x, y);
		cout << "||";
		y++;
	}
	x = 69, y = 1;
	for (int i = 0; i < a; i++) {
		setCord(x, y);
		cout << "||";
		y++;
	}
	x = 20, y = 1;
	for (int i = 0; i < b; i++) {
		setCord(x, y);
		cout << "==";
		x++;
	}
	x = 20, y = 19;
	for (int i = 0; i < b; i++) {
		setCord(x, y);
		cout << "==";
		x++;
	}
	x = 37, y = 2;
	for (int i = 0; i < a - 1; i++) {
		setCord(x, y);
		cout << "|";
		y++;
	}
	x = 53, y = 2;
	for (int i = 0; i < a - 1; i++) {
		setCord(x, y);
		cout << "|";
		y++;
	}
	x = 22, y = 7;
	for (int i = 0; i < b - 3; i++) {
		setCord(x, y);
		cout << "-";
		x++;
	}
	x = 22, y = 13;
	for (int i = 0; i < b - 3; i++) {
		setCord(x, y);
		cout << "-";
		x++;
	}
	x = 18, y = 2;
	for (int i = 1; i < 10; i++) {
		setCord(x, y);
		cout << i;
		y += 2;
	}
	x = 24, y = 0;
	bool piano = false;
	for (int i = 0; i < 9; i++) {
		setCord(x, y);
		cout << i + 1;
		if (i % 3 == 2) x++;
		x += 5;
	}
	x = 80, y = 6;
	setCord(x, y);
	setColor(4);
	cout << "--------------------------------" << endl; y++;
	setCord(x, y); 
	cout << "| <s>     Sacuvaj i zavrsi     |" << endl; y++;
	setCord(x, y);
	cout << "| <z>       Zavrsi igru        |" << endl; y++;
	setCord(x, y);
	cout << "| <?>       Rijesi plocu       |" << endl; y++;
	setCord(x, y);
	cout << "--------------------------------\n";
	x+=9,y = 3;
	setCord(x, y);
	setColor(80);
	cout << "BODOVI = " << score;
	setColor(4);

	int r = 0, c = 20;
	setCord(r, c);
}

void printSudoku(int board[][column], int Template[][column]) {
	system("CLS");
	system("color 04");
	cout << endl << endl;
	for (int i = 0; i < row; i++) {
		cout << "\t\t\t";
		for (int j = 0; j < column; j++) {
			if (board[i][j] == 0) {
				cout << "-    ";
				if (j % 3 == 2)  cout << " ";
			}
			else {
				if (j % 3 == 2) {
					if (board[i][j] == Template[i][j]) setColor(2);
					cout << board[i][j] << " ";
					if (board[i][j] == Template[i][j]) setColor(4);
				}
				else {
					if (board[i][j] == Template[i][j]) setColor(2);
					cout << board[i][j];
					if (board[i][j] == Template[i][j]) setColor(4);
				}
				cout << "    ";
			}
		}
		cout << endl << endl;
	}
	cout << endl << endl;
	setColor(8);
	int x = 20, y = 1, a = 18, b = 50;
	for (int i = 0; i < a; i++) {
		setCord(x, y);
		cout << "||";
		y++;
	}
	x = 69, y = 1;
	for (int i = 0; i < a; i++) {
		setCord(x, y);
		cout << "||";
		y++;
	}
	x = 20, y = 1;
	for (int i = 0; i < b; i++) {
		setCord(x, y);
		cout << "==";
		x++;
	}
	x = 20, y = 19;
	for (int i = 0; i < b; i++) {
		setCord(x, y);
		cout << "==";
		x++;
	}
	x = 37, y = 2;
	for (int i = 0; i < a - 1; i++) {
		setCord(x, y);
		cout << "|";
		y++;
	}
	x = 53, y = 2;
	for (int i = 0; i < a - 1; i++) {
		setCord(x, y);
		cout << "|";
		y++;
	}
	x = 22, y = 7;
	for (int i = 0; i < b - 3; i++) {
		setCord(x, y);
		cout << "-";
		x++;
	}
	x = 22, y = 13;
	for (int i = 0; i < b - 3; i++) {
		setCord(x, y);
		cout << "-";
		x++;
	}
	x = 18, y = 2;
	for (int i = 1; i < 10; i++) {
		setCord(x, y);
		cout << i;
		y += 2;
	}
	x = 24, y = 0;
	bool piano = false;
	for (int i = 0; i < 9; i++) {
		setCord(x, y);
		cout << i + 1;
		if (i % 3 == 2) x++;
		x += 5;
	}
	x = 80, y = 6;
	setCord(0,20);
	setColor(4);
}

void takeInput(int Template[][column], int board[][column],int solution_current[][column], string slot, int&user_score) {
	printSudoku(board,Template,user_score);

	int insert = 0;
	int i, j;
	string num;

	do {
		cout << "Odaberi redak unosa : ";
		cin >> num;
		if (num == "s" || num == "z") {
			sideMenu(num,slot,Template,board, user_score);
		}
		else if (num == "?") {
			getSolution(slot,Template, solution_current);
		}
	} while (!validateNumber(num));
	i = stoi(num);

	do {
		cout << "Odaberi stupac unosa : ";
		cin >> num;
		if (num == "s" || num == "z") {
			sideMenu(num,slot, Template, board, user_score);
		}
		else if (num == "?") {
			getSolution(slot,Template, solution_current);
		}
	} while (!validateNumber(num));
	j = stoi(num);

	--i, --j;

	if (Template[i][j] == 0) {
		do {
			cout << "Unesi vrijednost koju zelis unijeti u polje : ";
			cin >> num;
			if (num == "s" || num == "z") {
				sideMenu(num, slot, Template, board,user_score);
			}
			else if (num == "?") {
				getSolution(slot, Template, solution_current);
			}
		} while (!validateNumber(num));

		insert = stoi(num);

		if (checkRowColumnBox(board, i, j, insert)) {
			board[i][j] = insert;
		}
		else {
			user_score -= 50;
			system("pause");
			takeInput(Template,board,solution_current,slot,user_score);
		}
	}
	else {
		cout << "\n\n**** NIJE MOGUCE MIJENJATI VEC ISPUNJENO POLJE ****\n\n";
		system("pause");
		takeInput(Template,board,solution_current,slot, user_score);
	}
	cin.ignore();
}
bool checkRowColumnBox(int arr[][column],int i, int j, int valueToInsert)
{
	for (int n = 0; n < column; n++) {
		if (arr[i][n] == valueToInsert) {
			string text = "\tVRIJEDNOST SE PONAVLJA U RETKU";
			createHeading(text, '*');
			return false;
		}
	}
	for (int m = 0; m < row; m++) {
		if (arr[m][j] == valueToInsert) {
			string text = "\tVRIJEDNOST SE PONAVLJA U STUPCU";
			createHeading(text, '*');
			return false;
		}
	}
	int startOfSmallBox_row=0, startOfSmallBox_column=0;
	startOfSmallBox_row = i - i % 3;
	startOfSmallBox_column = j - j % 3;
	for (int m = 0; m < 3; m++) {
		for (int n = 0; n < 3; n++) {
			if (arr[startOfSmallBox_row +m][startOfSmallBox_column+n]==valueToInsert) {
				string text = "\tVRIJEDNOST SE PONAVLJA U 9x9 KVADRATU";
				createHeading(text, '*');
				return false;
			}
		}
	}

	return true;
}

void createHeading(string text, char pattern) {
	int numberOfPatternsInHeading = 119;
	for (int i = 0; i <= numberOfPatternsInHeading; i++) cout << pattern;
	cout << endl << "\t\t\t"<<text << endl;
	for (int i = 0; i <= numberOfPatternsInHeading; i++) cout << pattern;
	cout << endl;
}

void setColor(int desiredColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

void shuffle(int arr[][column]) {
	srand((unsigned)time(0));
	int shuffle_row[3][9]{ 0 };
	int shuffle_coloumn[9][3]{ 0 };
	//num += 1;
	int row_shuffle_start = 0; 
	int coloumn_shuffle_start = 0;
	int num = (rand() % 2) + 1;
	if (num == 1) {
		row_shuffle_start = 3;
	}
	else if (num == 2) {
		row_shuffle_start = 6;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 9; j++) {
			shuffle_row[i][j] = arr[i + row_shuffle_start][j];
		}
	}
	for (int i = 0, k = row_shuffle_start; i < 3; i++, k++)	{
		for (int j = 0, l = 0; j < 9; j++, l++)	{
			arr[k][l] = arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++)	{
		for (int j = 0; j < 9; j++)	{
			arr[i][j] = shuffle_row[i][j];
		}
	}
	num = (rand() % 2) + 1;
	if (num == 1) {
		coloumn_shuffle_start = 3;
	}
	else if (num == 2) {
		coloumn_shuffle_start = 6;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 9; j++) {
			shuffle_coloumn[j][i] = arr[j][i + coloumn_shuffle_start];
		}
	}
	for (int i = 0, k = coloumn_shuffle_start; i < 3; i++, k++) {
		for (int j = 0, l = 0; j < 9; j++, l++) {
			arr[l][k] = arr[j][i];
		}
	}
	for (int i = 0; i < 3; i++)	{
		for (int j = 0; j < 9; -j++) {
			arr[j][i] = shuffle_coloumn[j][i];
		}
	}
}

void showLoadingScreen(int go) {
	system("CLS");
	system("color 00");
	int x = 0, y = 50;
	int perc = 0, a = 50, b = 16;
	for (int i = 0; i < 11; i++) {
		system("CLS");
		setCord(a+4, b);
		cout << perc << "%";
		setCord(a - 2, b - 2);
		setColor(i + 2);
		cout << "UCITAVANJE";
		Sleep(100);
		cout << "...";
		Sleep(100);
		cout << "...\n";
		Sleep(600);
		setColor(i + 2);
		perc += 10;
	}
}

void sideMenu(string choice,string slot, int Template[][column], int board[][column], int user_score) {
	string confirmation;
	if (choice == "d") {
		cout << "\n**** ZELITE LI SACUVATI IGRU? (d/n) ****\n\n";
		do {
			cout << "Upisi ovdje : ";
			cin >> confirmation;
			if (confirmation != "d" && confirmation != "n") {
				cout << "Neispravan unos! Pokusaj ponovo.";
			}
		} while (confirmation != "d" && confirmation != "n");
		
		if (confirmation == "n") { main(); }
	}
	if (slot == "1") {
		ofstream Slot1_write("txt/Slot1.txt"), Slot1_score_write("txt/Slot1_score.txt");
		Slot1_score_write << user_score;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				Slot1_write << board[i][j] << " ";
			}
		}
		Slot1_write.close();
		Slot1_score_write.close();
	}
	if (slot == "2") {
		ofstream Slot2_write("txt/Slot2.txt"),  Slot2_score_write("txt/Slot2_score.txt");
		Slot2_score_write << user_score;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				Slot2_write << board[i][j]<<" ";
			}
		}
		Slot2_write.close();
		Slot2_score_write.close();
	}
	if (slot == "3") {
		ofstream Slot3_write("txt/Slot3.txt"), Slot3_score_write("txt/Slot3_score.txt");
		Slot3_score_write << user_score;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				Slot3_write << board[i][j]<<" ";
			}
		}
		Slot3_write.close();
		Slot3_score_write.close();
	}
	cout << "\n\n**** IGRA SPREMLJENA U SLOT-" << slot << " ****\n\n";
	system("pause");
	main();

}

void getSolution(string slot, int Template[][column], int solution_current[][column]) {
	system("CLS");
	printSudoku(solution_current, Template);
	cout << "\t\t        -------------------------------------------";
	cout << "\n\t\t        |   ****   OVO JE MOGUCE RJESENJE   ****  |\n";
	cout << "\t\t        |   ****    NATRAG U GLAVNI MENI    ****  |\n";
	cout << "\t\t        -------------------------------------------\n\n";

	if (slot == "1") {
		remove("txt/Slot1.txt");
		remove("txt/Template1.txt");
		remove("txt/Solved1.txt");
		remove("txt/Slot1_score.txt");
	}
	else if (slot == "2") {
		remove("txt/Slot2.txt");
		remove("txt/Template2.txt");
		remove("txt/Solved2.txt");
		remove("txt/Slot2_score.txt");
	}
	else if (slot == "3") {
		remove("txt/Slot3.txt");
		remove("txt/Template3.txt");
		remove("txt/Solved3.txt");
		remove("txt/Slot3_score.txt");
	}
	system("pause");
	main();
}

bool checkEnding(int board[][column]) {
	bool IsComplete = true;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (board[i][j] == 0) {
				IsComplete = false;
				return IsComplete;
			}
		}
	}
	return IsComplete;
}

void DisplayEndingScreen(int go) {
	system("Color F7");
	int x = 0, y = 0;
	for (int i = 0; i < 30; i++) {
		x = 15;
		for (int j = 0; j < 3; j++) {
			x += 16;
			setCord(x, y);
			setColor((i + j + 1) % 13 + 1);
			cout << "Cestitamo";
			Sleep(100);

		}
		y++;
	}
	system("pause>0");
	system("CLS");
}

void sortArray(int arr[],int size,string name[]) {
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		int key = arr[i];
		string name_temp = name[i];
		while (j >= 0 && arr[j] < key) {
			name[j + 1] = name[j];
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		name[j + 1] = name_temp;
	}
}
