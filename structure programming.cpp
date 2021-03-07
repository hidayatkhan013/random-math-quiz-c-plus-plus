#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

// main function
int main()
{
	/*
	Declearing all required Variables
	*/
	char choice_from_user;
	int operand1 =0;
	int operand2 =0;
	int oprator_index = 0;
	int answer_from_user = 0;
	int no_of_problmes = 0;
	int computer_answer = 0;
	// assigning marks according to level of questions
	int easy_score = 2, medium_score = 4, hard_score = 5,your_score=0,total_score=0;
	// total number correct and incorrect answers 
	int no_of_incorrect_ans = 0, no_of_correct_ans=0;
	// selection of operator from array 
	// oth index for addition than subtraction then multiplication than addition
	char oprators[] = { '+','-','*','/' };
	// for generating random oprands minimum and maximum limit is declear
	// generic score will be assign accoding to level of hardness
	int min =0,max =0, generic_score = 0;

	while (true){
		// for every operation no of correcT and incorrect counting array
		int correct_ansers[4] = { 0,0,0,0 };
		int incorrect_ansers[4] = { 0,0,0,0 };

		// displaying menu to user
		cout << "P: Practice Math \nS : Show Score \nQ : Quit\n ";
		// asking for input from user and store in choice variable
		cout << "What do you want to do: ";
		cin >> choice_from_user;

		// srand function will help in generating random numbers according to time
		srand((unsigned)time(0));

		// decision according to user choice if user enter P mean pratice menu must appear
		switch (choice_from_user)
		{
		case'P': {
			// practice menu is appearing of screen
			cout << "E: Easy \nM: Medium \nH: Hard";
			cout << "\nEnter difficult level: ";
			cin >> choice_from_user;
			switch (choice_from_user)
			{
			case'E': {
				// if user select E for easy mean the random number must be from -10 to 10
				// min and max is defined here to avoid the repetation of code which is displaying questions accoding to user choice
				min = -10, max = 10;
				generic_score = easy_score;
				break;
			}
			case'M': {
				// min and max for medium  the limit for random number is -50 to 50 for medium level
				min = -50, max = 50;
				generic_score = medium_score;
				break;
			}
			case'H': {
				// min and max for medium  the limit for random number is -100 to 100 for medium level
				min = -100, max = 100;
				generic_score = hard_score;
				break;
			}
			default:
				// if select not select from above choices default case will run
				cout << "\n Wrong selection" << endl;
				break;
			}
			// if user choose any level then computer must display questions to user if user make wrong select there must be no questions
			if (choice_from_user == 'E' || choice_from_user == 'M' || choice_from_user == 'H')
			{
				// asking user that how many questions he want to pratice
				cout << "\nHow many problems do you want? ";
				cin >> no_of_problmes;
				// displaying user entered number of questions to user
				for (int i = 0; i < no_of_problmes; i++)
				{
					// getting 1st oprand of expression which can be -limit to +limit
					operand1 = min + rand() % (max - min);
					//getting 2nd oprand  this oprand must not be negative because in middle there is operation so no need of negative numbers here
					operand2 = (rand() % max) + 1;
					// generating random number to display random questions on screen it maybe +  -  / or *
					oprator_index = rand() % 4;
					if (oprators[oprator_index] == '+') computer_answer = operand1 + operand2;
					else if (oprators[oprator_index] == '-') computer_answer = operand1 - operand2;
					else if (oprators[oprator_index] == '*') computer_answer = operand1 * operand2;
					// operand1 % operand2 == 0 means the divisble answer must not be in fraction form
					else if (oprators[oprator_index] == '/' && operand1 % operand2 == 0) computer_answer = operand1 / operand2;
					// if fraction for occur while loop will generate numbers untill the folling condition
					// For division, you want to ensure the answer is a whole number.
					else
					{
						do
						{
							operand1 = -10 + rand() % (10 - (-10));
							operand2 = (rand() % 10) + 1;

						} while (operand1 % operand2 != 0);
						// when while loop succesful the answer will be assign to computer answer variable
						computer_answer = operand1 / operand2;

					}

					// asking question from user
					cout << "\nWhat is " << operand1 << oprators[oprator_index] << operand2 << "?	";
					cin >> answer_from_user;
					// if user answer and computer answer matched then count correct answer of relevent operation and display message to user
					if (answer_from_user == computer_answer) {
						correct_ansers[oprator_index]++;
						cout << "Correct, great job!";
					}
					else {
						// if answer is correct modify incorrect answer value according to its operation type
						//display correct answer to user with message
						incorrect_ansers[oprator_index]++;
						cout << "Sorry, that's incorrect, the answer is " << computer_answer;
					}
				}
				// every index contain operation count so add all to get total for incorrect answer
				no_of_incorrect_ans = (incorrect_ansers[0] + incorrect_ansers[1] + incorrect_ansers[2] + incorrect_ansers[3]);
				// similary for correct answer 
				no_of_correct_ans = (correct_ansers[0] + correct_ansers[1] + correct_ansers[2] + correct_ansers[3]);
				// user score will be no of correct answer and score accoring to its level like easy score is 2
				// medium is 4 and hard is 5 so we assign relevent score to generic_score variable and we do calculation here
				your_score = no_of_correct_ans * generic_score;
				// total score will be no of question x score of level
				total_score = no_of_problmes * generic_score;
				// display obtained score to user
				cout << "\nYour score is " << your_score << "/" << total_score << endl;
				// display correct answer out of total to user
				cout << "You got " << no_of_correct_ans << "/" << no_of_problmes << " questions correct." << endl;
				// displaying indivisul correct answers to user in every operation

				cout << "Addition	Subtraction	Multiplication	Division" << endl;
				cout << correct_ansers[0] << "/" << correct_ansers[0] + incorrect_ansers[0] << "		";
				cout << correct_ansers[1] << "/" << correct_ansers[1] + incorrect_ansers[1] << "		";
				cout << correct_ansers[2] << "/" << correct_ansers[2] + incorrect_ansers[2] << "		";
				cout << correct_ansers[3] << "/" << correct_ansers[3] + incorrect_ansers[3] << endl;

				// if all answerr is correct no to to display for practice message
				// if incorrect is greater than correct it mean user need to pratice
				if (no_of_incorrect_ans > no_of_correct_ans) {
					cout << endl << "Need more practice with : " << endl;
				}
				// if addition inorrect answer is greater than correct it mean user need to pratice in addition
				if (correct_ansers[0] < incorrect_ansers[0]) {
					cout << "Addition" << endl;
				}
				// if subtraction inorrect answer is greater than correct it mean user need to pratice in subtraction

				if (correct_ansers[1] < incorrect_ansers[1]) {
					cout << "Subtraction" << endl;
				}
				// if multiplication inorrect answer is greater than correct it mean user need to pratice in multiplication

				if (correct_ansers[2] < incorrect_ansers[2]) {
					cout << "Multiplication" << endl;
				}
				// if Division inorrect answer is greater than correct it mean user need to pratice in divison

				if (correct_ansers[3] < incorrect_ansers[3]) {
					cout << "Division" << endl;
				}
				cout << endl;
			}
			break;
		}
		case'S': {
			// if user didnt try any practice there should be no marks to display 
			// if he pratice once and user want to see their previous marks he can see here
			if (your_score > 0) cout << "Your last score was " << your_score << "/" << total_score << endl;
			else cout << "No score found." << endl;
			break;
		}
		case'Q': {
			// if user wish to quit from program 
			return 0;
			break;
		}
		default:
			// if user didnt make the correct selection from menu default case will run
			cout << "\n Wrong selection" << endl;
			break;
		}
	}
	return 0;

	// That's it 
}
