#include <iostream>
#include <limits>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include "course.h"
#include "TypeWriter.h"
#include "ClearScreen.h"
//fixes limits issue
#define MAX
/*
	1.Collect Grading policy
	2.Collect grades per category
	3.
				TODO'
	delete vars on the heap after use
*/
void CreateFile(Course, std::string);
void printGrades(Course);
int main() {
	/*
	Course grades;
	std::vector<std::string> menu;
	menu.push_back("Gpa Estimator");
	menu.push_back("Class Grade");
	int cursorPos{ 0 };
	while (true) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		for (int i{ 0 }; i < menu.size(); i++) {
			if (i == cursorPos) {
				//Change color and display
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				std::cout << std::setw(8) << " -> "; TypeWriter(menu[i], 15);
				std::cout << " <- "; std::cout << std::endl;
			}
			else {
				//display with no color

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				TypeWriter(menu[i], 05); std::cout << std::endl;
			}
		}
		//move cursor
		while (true) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			if (GetAsyncKeyState(VK_UP) != 0) {
				cursorPos -= 1;
				if (cursorPos == -1) {
					cursorPos = menu.size() - 1;
				}
				break;
			}

			else if (GetAsyncKeyState(VK_DOWN) != 0) {
				cursorPos += 1;
				if (cursorPos == menu.size()) {
					cursorPos = 0;
				}
				break;
			}

			else if (GetAsyncKeyState(VK_ESCAPE) != 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 + rand() % 15));
				TypeWriter("\tExiting Now...\n", 30);
				exit(0);
			}

			else if (GetAsyncKeyState(VK_RETURN) != 0) {
				switch (cursorPos) {
				case 0: //Lab 1
				{
					break;
				}
				case 1: {
					classSetUp(grades);
					main();
				}
				default: {
					break;
				}
				}//end switch
			}//end else
		}//end while loop
		Sleep(100);
	}//end while loop
	//grades.GradingPolicy();
	//system("cls");
	*/
	
	std::string className{ " " };
	std::cout << "\t\tEnter Class Name: ";
	std::cin >> className;
	Course firstClass;
	firstClass.setClassName(className);
	ClearScreen();
	firstClass.numberOfGrades();
	ClearScreen();
	firstClass.Grades();
	ClearScreen();
	firstClass.GradingPolicy();
		//Collect grades per criteria
	ClearScreen(); //clear the screen
	//classes.Grades();
		//Collect Grading policy for class
	//classes.GradingPolicy(classNames.classNames);
		//print grades
	printGrades(firstClass);
	
	
}//main()
	
void printGrades(Course object) {
	ClearScreen(); //Clear the Screen
		std::cout << "\t\t\t\t\tPrinting Average Grades For Class " << object.getClassName()<< "\n\n";
			//Set decimal place to 2
		std::cout << std::setprecision(0);

						//Discussion Board Average
		if (object.discussionBoardGrade.size() > 0) {
			TypeWriter("\t\t\n[-]Discussion Board Stats\n", 30);
			for (int i{ 0 }; i < object.discussionBoardGrade.size(); i++) {
				std::setw(10);
				std::cout << "\tDiscussion Board #" << i + 1 << " Grade = " << object.discussionBoardGrade[i] << "%" << std::endl;
			}
			std::cout << "\tAverage = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageDiscussionBoard());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "%";
			std::cout << "\t\tWeighted Grade = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageDiscussionBoard() * object.DiscussionBoardPolicy());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "% out of " << object.discussionBoard << "%\n" << std::endl;
		}
						//Homework Average
		if (object.homewordGrade.size() > 0) {
			TypeWriter("\t\t\n[-]Homework Assignment Stats\n", 30);
			for (int i{ 0 }; i < object.homewordGrade.size(); i++) {
				std::setw(10);
				std::cout << "\tHomework Assignment #" << i + 1 << " Grade = " << object.homewordGrade[i] << "%" << std::endl;
			}
			std::cout << "\tAverage = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageHomeworkGrade());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "%";
			std::cout << "\t\tWeighted Grade = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageHomeworkGrade() * object.HomeworkPolicy());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "% out of " << object.homework << "%\n" << std::endl;
		}
					//Labs Average
		if (object.labsGrade.size() > 0) {
			TypeWriter("\t\t\n[-]Semester Labs Stats\n", 30);
			for (int i{ 0 }; i < object.labsGrade.size(); i++) {
				std::setw(10);
				std::cout << "\tLab #" << i + 1 << " Grade = " << object.labsGrade[i] << "%" << std::endl;
			}
			std::cout << "\tAverage = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageLabGrade());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "%";
			std::cout << "\t\tWeighted Grade = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageLabGrade() * object.LabsPolicy());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "% out of " << object.labs << "%\n" << std::endl;
		}
					//Quizes Average
		if (object.quizGrade.size() > 0) {
			TypeWriter("\t\t\n[-]Semester Quiz Stats\n", 30);
			for (int i{ 0 }; i < object.quizGrade.size(); i++) {
				std::setw(10);
				std::cout << "\tQuiz #" << i + 1 << " Grade = " << object.quizGrade[i] << "%" << std::endl;
			}
			std::cout << "\tAverage = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageQuizGrade());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "%";
			std::cout << "\t\tWeighted Grade = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageQuizGrade() * object.QuizesPolicy());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "% out of " << object.quizes << "%\n" << std::endl;
		}
						//Tests Average
		if (object.testGrade.size() > 0) {
			TypeWriter("\t\t\n[-]Semester Tests Stats\n", 30);
			for (int i{ 0 }; i < object.testGrade.size(); i++) {
				std::setw(10);
				std::cout << "\tTest #" << i + 1 << " Grade = " << object.testGrade[i] << "%" << std::endl;
			}
			std::cout << "\tAverage = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageTestGrade());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "%";
			std::cout << "\t\tWeighted Grade = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageTestGrade() * object.TestsPolicy());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "% out of " << object.tests << "%\n" << std::endl;
		}
						//Reserch  Paper Average
		if (object.researchPaperGrade.size() > 0) {
			TypeWriter("\t\t\n[-]Research Paper Stats\n", 30);
			for (int i{ 0 }; i < object.researchPaperGrade.size(); i++) {
				std::setw(10);
				std::cout << "\tResearch Paper #" << i + 1 << " Grade = " << object.researchPaperGrade[i] << "%" << std::endl;
			}
			std::cout << "\tAverage = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageResearchPaperGrade());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "%";
			std::cout << "\t\tWeighted Grade = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageResearchPaperGrade() * object.ResearchPaperPolicy());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "% out of " << object.researchPaper << "%\n" << std::endl;
		}
							//Midterm Grade
		if (object.AverageMidtermGrade() > 0) {
			TypeWriter("\t\t\n[-]Midterm Stat\n", 30);
			std::setw(10);
			std::cout << "\tMidterm Grade = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageMidtermGrade());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "%";
			std::cout << "\t\tWeighted Grade = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageMidtermGrade() * object.MidtermPolicy());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "% out of " << object.midterm << "%\n" << std::endl;
		}
							//Final Exam Grade
		if (object.AverageFinalExamGrade() > 0) {
			TypeWriter("\t\t\n[-]Final Exam Stat\n", 30);
			std::setw(10);
			std::cout << "\tFinal Exam Grade = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageFinalExamGrade());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "%";
			std::cout << "\t\tWeighted Grade = ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << static_cast<int>(object.AverageFinalExamGrade() * object.FinalExamPolicy());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "% out of " << object.finalExam << "%\n" << std::endl;
		}
		std::cout << "\n\t\t\t\t\t\tGrading Policy\n";
		std::setw(40);
		if (object.discussionBoard > 0) {
			std::cout << "\tDiscussion Board = " << object.discussionBoard << "% of total grade " << std::endl;
		}
		if (object.homework > 0) {
			std::cout << "\tHomework Assignments = " << object.homework << "% of total grade " << std::endl;

		}
		if (object.labs > 0) {
			std::cout << "\tLabs = " << object.labs << "% of total grade " << std::endl;
		}
		if (object.quizes > 0) {
			std::cout << "\tQuizes = " << object.quizes << "% of total grade " << std::endl;
		}
		if (object.tests > 0) {
			std::cout << "\tTests = " << object.tests << "% of total grade " << std::endl;
		}
		if (object.researchPaper > 0) {
			std::cout << "\tResearch Papers = " << object.researchPaper << "% of total grade " << std::endl;
		}
		if (object.midterm > 0) {
			std::cout << "\tMidtem Exam = " << object.midterm << "% of total grade " << std::endl;
		}
		if (object.finalExam > 0) {
			std::cout << "\tFinal Exam = " << object.finalExam << "% of total grade " << std::endl;
		}
		std::cout << "\n\n\n";
					//Course Grade
		std::setw(20);
		std::setprecision(2);
		std::cout << "\tCurrent Grade = " <<object.CalculteCourseGrade() <<" OR "<< object.getCourseGrade();
		std::cout << std::endl;
		system("pause");
		ClearScreen();
		main();
} //end printGrades()


	//Create files
void CreateFile(Course object, std::string nameOfClass){
			//Seed random generator
	srand(time(NULL));
	int randomNumber = 1 + rand() % 100;
	std::string fileName = "report";
	fileName += std::to_string(randomNumber);
	fileName += ".txt";
	std::fstream file(fileName, std::ios::out);
	if (!file.is_open()) {
		std::cout << "\tCould open " << fileName << " !" << std::endl;
	}
	//if open then write to file
	if (file.is_open()) {
		file << object.AverageHomeworkGrade() << std::endl;
	}
	std::cout << "\tSuccesfully created report! \n";
	file.close(); //close file
}