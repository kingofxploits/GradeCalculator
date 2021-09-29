#include "course.h"
#define MAXLIMIT

double Course::CalculteCourseGrade() {
	double courseGrade{ 0 };
	if(discussionBoardGrade.size() > 0)
		courseGrade += AverageDiscussionBoard() * DiscussionBoardPolicy();
	if(homewordGrade.size() > 0)
		courseGrade += AverageHomeworkGrade() * HomeworkPolicy();
	if(labsGrade.size() > 0)
		courseGrade += AverageLabGrade() * LabsPolicy();
	if(quizGrade.size() > 0)
		courseGrade += AverageQuizGrade() * QuizesPolicy();
	if(testGrade.size() > 0)
		courseGrade += AverageTestGrade() * TestsPolicy();
	if (researchPaperGrade.size() > 0)
		courseGrade += AverageResearchPaperGrade() * ResearchPaperPolicy();
	if(midtermGrade.size() > 0)
		courseGrade += AverageMidtermGrade() * MidtermPolicy();
	if(finalExamGrade.size() > 0)
		courseGrade += AverageFinalExamGrade() * FinalExamPolicy();

	return courseGrade /100;
}//end CalculteCourseGrade()

std::string Course::getCourseGrade()  {
	double grade = CalculteCourseGrade() * 100;
	std::string currentGrade;
	if (grade >= 93)
		currentGrade = "A";
	else if (grade >= 90)
		currentGrade = "A-";
	else if (grade >= 87.1)
		currentGrade = "B+";
	else if (grade >= 83)
		currentGrade = "B";
	else if (grade >= 80)
		currentGrade = "B-";
	else if (grade >= 77.1)
		currentGrade = "C+";
	else if (grade >= 73)
		currentGrade = "C";
	else if (grade >= 70)
		currentGrade = "C-";
	else if (grade >= 67.1)
		currentGrade = "D+";
	else if (grade >= 63)
		currentGrade = "D";
	else if (grade >= 60)
		currentGrade = "D-";
	else
		currentGrade = "F";
	{
		delete totalDiscussionBoard;
		delete totalHomework;
		delete totalLabs;
		delete totalQuizes;
		delete totalTests;
		delete totalResearchPaper;
		delete totalMidterm;
		delete totalFinalExam;
	}
	return currentGrade;
}//end getCourseGrade()

//Get Midterm Grade
double Course::AverageMidtermGrade() {
	double midTerm{ 0 };
	if (midtermGrade.size() > 0) {
		for (int i{ 0 }; i < midtermGrade.size(); i++) {
			midTerm += midtermGrade[i];
		}
		std::setprecision(2);
		midterm /= midtermGrade.size();
	}
	return midTerm;
}
//Get Final Exam Grade
double Course::AverageFinalExamGrade() {
	double finalExam{ 0 };
	if (finalExamGrade.size() > 0) {
		for (int i{ 0 }; i < finalExamGrade.size(); i++) {
			finalExam += finalExamGrade[i];
		}
		std::setprecision(2);
		finalExam /= finalExamGrade.size();
	}
	return finalExam;
}
	//Research Paper Grade
double Course::AverageResearchPaperGrade() {
	double reasearchPaper{ 0 };
	if (*totalResearchPaper > 0) {
		for (int i{ 0 }; i < researchPaperGrade.size(); i++) {
			reasearchPaper += researchPaperGrade[i];
		}
		std::setprecision(2);
		researchPaper /= researchPaperGrade.size();
	}
	return reasearchPaper;
}
//Calculate labs Average Grade
double Course::AverageLabGrade() {
	double labs{ 0 };
	if (*totalLabs > 0) {
		for (int i{ 0 }; i < labsGrade.size(); i++) {
			labs += labsGrade[i];
		}
		std::setprecision(2);
		labs /= labsGrade.size();
	}
	return labs;
}

//Calculate tests Average Grade
double Course::AverageTestGrade() {
	double test{ 0 };
	if (*totalTests > 0) {
		for (int i{ 0 }; i < testGrade.size(); i++) {
			test += testGrade[i];
		}
		std::setprecision(2);
		test /= testGrade.size();
	}
	return test;
}
	//Calculate Quiz Average Grade
double Course::AverageQuizGrade() {
	double quizes{ 0 };
	if (*totalQuizes > 0) {
		for (int i{ 0 }; i < quizGrade.size(); i++) {
			quizes += quizGrade[i];
		}
		std::setprecision(2);
		quizes /= quizGrade.size();
	}
	return quizes;
}
		//Calculate Average Discussion Board Grades
double Course::AverageDiscussionBoard() {
	double discussionBoard{ 0 };
	if (*totalDiscussionBoard > 0) {
		for (int i{ 0 }; i < discussionBoardGrade.size(); i++) {
			discussionBoard += discussionBoardGrade[i];
		}
		std::setprecision(2);
		discussionBoard /= discussionBoardGrade.size();
	}
	return discussionBoard;
}
		//Calculate Average HomeWork Grades
double Course::AverageHomeworkGrade() {
	double homework{ 0 };
	if (*totalHomework > 0) {
		for (int i{ 0 }; i < homewordGrade.size(); i++) {
			homework += homewordGrade[i];
		}
		std::setprecision(2);
		homework /= homewordGrade.size();
	}
	return homework;
}

void Course::Grades() {
	std::cout << "\t\t\t\t\t[*]Enter Grades Received for " << getClassName() << "[*]\n\n" << std::endl;
		//Get grades for discussion board
	for (int i{ 0 }; i < *totalDiscussionBoard; i++) {
		double temp;
		std::cout << "\t[-]Enter grade for discussion board " << i + 1 << " -> ";
		std::cin >> temp;
		this -> discussionBoardGrade.push_back(temp);
		while (!std::cin.good()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
			std::cout << "\t\t[!]Enter a valid score :) \n";
			std::cout << "\t[-]Enter grade for discussion board " << i + 1 << " -> ";
			std::cin >> temp;
		}
	}
		//Get Grades for Homework
	for (int i{ 0 }; i < *totalHomework; i++) {
		double temp;
		std::cout << "\t[-]Enter grade for homework " << i + 1 << " -> ";
		std::cin >> temp;
		this -> homewordGrade.push_back(temp);
		while (!std::cin.good()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
			std::cout << "\t\t[!]Enter a valid score :) \n";
			std::cout << "\t[-]Enter grade for homework " << i + 1 << " -> ";
			std::cin >> temp;
		}
	}
			//Get grades for quizes
	for (int i{ 0 }; i < *totalQuizes; i++) {
		double temp;
		std::cout << "\t[-]Enter grade for Quiz " << i + 1 << " -> ";
		std::cin >> temp;
		this -> quizGrade.push_back(temp);
		while (!std::cin.good()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
			std::cout << "\t\t[!]Enter a valid score :) \n";
			std::cout << "\t[-]Enter grade for Quiz " << i + 1 << " -> ";
			std::cin >> temp;
		}
	}
			//Get grades for tests
	for (int i{ 0 }; i < *totalTests; i++) {
		double temp;
		std::cout << "\t[-]Enter grade for Test " << i + 1 << " -> ";
		std::cin >> temp;
		this -> testGrade.push_back(temp);
		while (!std::cin.good()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
			std::cout << "\t\t[!]Enter a valid score :) \n";
			std::cout << "\t[-]Enter grade for Test " << i + 1 << " -> ";
			std::cin >> temp;
		}
	}
			//Get grades for labs
	for (int i{ 0 }; i < *totalLabs; i++) {
		double temp;
		std::cout << "\t[-]Enter grade for Lab " << i + 1 << " -> ";
		std::cin >> temp;
		this -> labsGrade.push_back(temp);
		while (!std::cin.good()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
			std::cout << "\t\t[!]Enter a valid score :) \n";
			std::cout << "\t[-]Enter grade for Lab " << i + 1 << " -> ";
			std::cin >> temp;
		}
	}

		//Get grades for research paper
	for (int i{ 0 }; i < *totalResearchPaper; i++) {
		double temp;
		std::cout << "\t[-]Enter grade for Research Paper " << i + 1 << " -> ";
		std::cin >> temp;
		this -> researchPaperGrade.push_back(temp);
		while (!std::cin.good()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
			std::cout << "\t\t[!]Enter a valid score :) \n";
			std::cout << "\t[-]Enter grade for Research Paper " << i + 1 << " -> ";
			std::cin >> temp;
		}
	}
			//Get grades for midterm
	for (int i{ 0 }; i < 1; i++) {
		double temp;
		std::cout << "\t[-]Enter grade for Midterm -> ";
		std::cin >> temp;
		
		if (temp > 0) {
			this->midtermGrade.push_back(temp);
			*totalMidterm += 1;
		}
		while (!std::cin.good()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
			std::cout << "\t\t[!]Enter a valid score :) \n";
			std::cout << "\t[-]Enter grade for Midterm " << i + 1 << " -> ";
			std::cin >> temp;
		}
	}
			//Get grades for final exam
	for (int i{ 0 }; i < 1; i++) {
		double temp;
		std::cout << "\t[-]Enter grade for Final Exam -> ";
		std::cin >> temp;
		if (temp > 0) {
			this->finalExamGrade.push_back(temp);
			*totalFinalExam += 1;
		}
		
		while (!std::cin.good()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
			std::cout << "\t\t[!]Enter a valid score :) \n";
			std::cout << "\t[-]Enter grade for Final Exam " << i + 1 << " -> ";
			std::cin >> temp;
		}
	}
}
				//Number of Grades
void Course::numberOfGrades() {
		std::cout << "\t\t\t\t\t[*]Number of Completed Work For " <<getClassName()<< "[*]\n\n" <<std::endl;
		
		std::cout << "\t[+]Number of Discussion Board Completed: ";
		std::cin >> *totalDiscussionBoard;
				//Check integer validation
		while (!std::cin.good()) {
			std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
			std::cout << "\t\t[!]Enter a valid integer :) \n"; std::cout << "\t[+]Number of Discussion Board Completed: ";
			std::cin >> *totalDiscussionBoard;
		}

		std::cout << "\t[+]Number of Homework Completed: ";
		std::cin >> *totalHomework;
		//Check integer validation
		while (!std::cin.good()) {
			std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
			std::cout << "\t\t[!]Enter a valid integer :) \n"; std::cout << "\t[+]Number of Homework Completed: ";
			std::cin >> *totalHomework;
		}

		std::cout << "\t[+]Number of Quizes Completed: ";
		std::cin >> *totalQuizes;
		//Check integer validation
		while (!std::cin.good()) {
			std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
			std::cout << "\t\t[!]Enter a valid integer :) \n"; std::cout << "\t[+]Number of Quizes Completed: ";
			std::cin >> *totalQuizes;
		}

		std::cout << "\t\t\t(Excluding midterm and final exam)\n\t[+]Number of Tests Completed: ";
		std::cin >> *totalTests;
		//Check integer validation
		while (!std::cin.good()) {
			std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
			std::cout << "\t\t[!]Enter a valid integer :) \n"; std::cout << "\t(Excluding midterm and final exam)\n\t[+]Number of Tests Completed: ";
			std::cin >> *totalTests;
		}

		std::cout << "\t[+]Number of Labs Completed: ";
		std::cin >> *totalLabs;
		//Check integer validation
		while (!std::cin.good()) {
			std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
			std::cout << "\t\t[!]Enter a valid integer :) \n"; std::cout << "\t[+]Number of Labs Completed: ";
			std::cin >> *totalLabs;
		}

		std::cout << "\t[+]Number of Reasearch Papers Completed: ";
		std::cin >> *totalResearchPaper;
		//Check integer validation
		while (!std::cin.good()) {
			std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
			std::cout << "\t\t[!]Enter a valid integer :) \n"; std::cout << "\t[+]Number of Reasearch Papers Completed: ";
			std::cin >> *totalResearchPaper;
		}
}//end numberOfGrades()
		//Get Grading Policy percentage
void Course::GradingPolicy() {
		std::cout << "\t\t\t\t\t[*] Grading Policy for " << getClassName()<<" [*]"<<std::endl;
		//Get Policy for Discussion Board
		if (*totalDiscussionBoard > 0) {
			for (int i{ 0 }; i < 1; i++) {
				std::cout << "\t[+]Discussion Board % -> ";
				std::cin >> this->discussionBoard;
				while (!std::cin.good()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
					std::cout << "\t\t[!]Enter a valid integer :) \n";
					std::cout << "\t[+]Discussion Board % -> ";
					std::cin >> this->discussionBoard;
				}
			}
		}
		//Get policy for Homework Grade
		if (*totalHomework > 0) {
			for (int i{ 0 }; i < 1; i++) {
				std::cout << "\t[+]Homework % -> ";
				std::cin >> this->homework;
				while (!std::cin.good()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
					std::cout << "\t\t[!]Enter a valid integer :) \n";
					std::cout << "\t[+]Homework % -> ";
					std::cin >> this->homework;
				}
			}
		}

			//Get Policy for lab Grade
		if (*totalLabs > 0) {
			for (int i{ 0 }; i < 1; i++) {
				std::cout << "\t[+]Labs % -> ";
				std::cin >> this->labs;
				while (!std::cin.good()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
					std::cout << "\t\t[!]Enter a valid integer :) \n";
					std::cout << "\t[+]Labs % -> ";
					std::cin >> this->labs;
				}
			}
		}
		//Get Policy for Quiz Grade
		if (*totalQuizes > 0) {
			for (int i{ 0 }; i < 1; i++) {
				std::cout << "\t[+]Quizes % -> ";
				std::cin >> this->quizes;
				while (!std::cin.good()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
					std::cout << "\t\t[!]Enter a valid integer :) \n";
					std::cout << "\t[+]Quizes % -> ";
					std::cin >> this->quizes;
				}
			}
		}
			//Get Policy for TEst Scores
		if (*totalTests > 0) {
			for (int i{ 0 }; i < 1; i++) {
				std::cout << "\t[+]Tests % -> ";
				std::cin >> this->tests;
				while (!std::cin.good()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
					std::cout << "\t\t[!]Enter a valid integer :) \n";
					std::cout << "\t[+]Tests % -> ";
					std::cin >> this->tests;
				}
			}
		}

			//Get Policy for Research Paper
		if (*totalResearchPaper > 0) {
			for (int i{ 0 }; i < 1; i++) {
				std::cout << "\t[+]Research Paper % -> ";
				std::cin >> this->researchPaper;
				while (!std::cin.good()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
					std::cout << "\t\t[!]Enter a valid integer :) \n";
					std::cout << "\t[+]Research Paper % -> ";
					std::cin >> this->researchPaper;
				}
			}
		}
			//Get Policy for midterm
		if (*totalMidterm > 0) {
			for (int i{ 0 }; i < 1; i++) {
				std::cout << "\t[+]MidTerm % -> ";
				std::cin >> this->midterm;
				while (!std::cin.good()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
					std::cout << "\t[!]Enter a valid integer :) \n";
					std::cout << "\t[+]MidTerm % -> ";
					std::cin >> this->midterm;
				}
			}
		}
			//Get Policy for Final Exam
		if (*totalFinalExam > 0) {
			for (int i{ 0 }; i < 1; i++) {
				std::cout << "\t[+]Final Exam % -> ";
				std::cin >> this->finalExam;
				while (!std::cin.good()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
					std::cout << "\t\t[!]Enter a valid integer :) \n";
					std::cout << "\t[+]Final Exam % -> ";
					std::cin >> this->finalExam;
				}
			}
		}

}//end GradingPolicy()
double Course::DiscussionBoardPolicy(){
	return this->discussionBoard / 100;;
}
double Course::HomeworkPolicy(){
	return this->homework / 100;;
}
double Course::LabsPolicy() {
	return this->labs / 100;;
}
double Course::QuizesPolicy(){
	return this->quizes / 100;;
}
double Course::TestsPolicy(){
	return this->tests / 100;;
}
double Course::ResearchPaperPolicy() {
	return this->researchPaper / 100;;
}
double Course::MidtermPolicy(){
	return this->midterm / 100;;
}
double Course::FinalExamPolicy(){
	return this->finalExam / 100;;
}

			//Set name of class
void Course::setClassName(std::string name) {
	ClassName = name;
}
		//Get name of class
std::string Course::getClassName() const{
	return ClassName;
}
		//Default constructor
Course::Course(){}
		//Default destructor
Course::~Course(){}
	// get class names
