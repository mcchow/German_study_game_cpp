// study_game
// This project is only design for window user
// Martin Chow
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <wchar.h>
#include <iomanip>
using namespace std;

void readFiles(vector<string>& prob, vector<string>& ans);

int main()
{
	char key = 0;
	//int asciiValue;
	string current_ans;     //save user input ans
	vector<string> prob;    // save problem
	vector<string> ans;     //correct ans
	readFiles(prob, ans);   //read question
  
  //start
	cout << "This is the German Studying Game. Esc to exit while playing!\n" << endl;
	srand(time(0));
	system("pause");
  
  //the game
	int time_start = static_cast<int>(time(0)); // cheak for time start the question
	int time_end;
	int time_now = time_start;
	time_end = time_start + 60; //if it is 60 s over then is end
  
	int current_q = rand() % prob.size();// random question number
	char del = 127; // del is always use, make as a valuable
  
	while (prob.size()!=0)//if not all question is ans
	{
  //change time every sec
		if (time(0) != time_now) {
			system("cls");
			cout << prob[current_q] << "(" << setw(2) << time_end - time(0) << "):" << current_ans;
			time_now = time(0);
		}
    
    //check if times up
		if (time(0) == time_end) {
			cout << "\nTimes up!!!!!!\n";
			system("pause");
			current_q = rand() % prob.size();
			time_start = static_cast<int>(time(0));
			time_now = time_start;
			time_end = time_start + 60;
			current_ans.clear();
		}
    
    //check user input and put it to ans
		if (_kbhit()) {
			key = _getch(); //get key
			if (isalpha(key))current_ans += key;
			if (static_cast<int>(key) == 8 && current_ans.size() != 0)//backspace
				current_ans.pop_back();
			if (static_cast<int>(key) == 13) {//enter
				if (current_ans == ans[current_q]) {//check ans
					cout << "\nIt is right\n";
					prob.erase(prob.begin() + current_q);
					ans.erase(ans.begin() + current_q);
				}
				else cout << "\nIt is wrong. The answer is " << ans[current_q] << endl; 
				system("pause");
				if(prob.size()!=0)current_q = rand() % prob.size();
        //reset time
				time_start = static_cast<int>(time(0));
				time_now = time_start;
				time_end = time_start + 60;
				current_ans.clear();
			}
      
			if (static_cast<int>(key) == 27) exit(0); //esc exit the game
			system("cls");
			if (prob.size() != 0)cout << prob[current_q] << "(" << setw(2) << time_end - time(0) << "):" << current_ans;
		}
    ////////////////////////////////////////////////////////////////////////////////////////
		//this is only for testing and learning get keyboad input
		//if (isalpha(key)) {
		//	asciiValue = key;
		//	if (isalpha(key))cout << "Key pressed -> \" " << key << " \"ascii value = " << asciiValue << endl;
		//	key = 0;
		//}
		//cout << "Key pressed -> \" " << key << " \"ascii value = " << asciiValue << endl;
    ///////////////////////////////////////////////////////////////////////////////////////
	}
	cout << "Great job. You are done.\n";
	system("pause");
	return 0;
}

//read a file with preset question
void readFiles(vector<string>& prob, vector<string>& ans) {
	ifstream myfile;
	bool flag = true;
	string filename = "data.input";
  
  //check file
	myfile.open(filename);
	if (!myfile) {
		cerr << "\nFile could not be opened!\n"; // Report error
		system("pause");
		exit(0);
	}
  
  //read
	string s;
	while (!myfile.eof()) {
		getline(myfile, s);
		prob.push_back(s);
		cout << s << endl;
		if (myfile.eof()) {
			cout << "File format error!\n";//need to follow the file format
			system("pause");
			exit(0);
		}
		getline(myfile, s);
		ans.push_back(s);
		cout << s << endl;
	}
  
	myfile.close();
	cout << "::..:: Done Reading! ::..::\n";
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//only if you want, better to use
//bool cheak()
//if ((asciiValue >= 65 && asciiValue < 91) || (asciiValue>96 && asciiValue<123))cout << "Key pressed -> \" " << key << " \"ascii value = " << asciiValue << endl;
//if (asciiValue == 27)
//break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
