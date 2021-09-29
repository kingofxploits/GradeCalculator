#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>
#include <fstream>
#include "TypeWriter.h"
//#include "ClearScreen.h"
class Course{
public:
	Course();
	~Course();
	void numberOfGrades();
	void Grades();
	void GradingPolicy();
				//Calculate Grades
	double AverageDiscussionBoard();
	double AverageHomeworkGrade();
	double AverageQuizGrade();
	double AverageTestGrade();
	double AverageLabGrade();
	double AverageMidtermGrade();
	double AverageResearchPaperGrade();
	double AverageFinalExamGrade();
			//Midterm and final has grade already calculated
	double DiscussionBoardPolicy();
	double HomeworkPolicy();
	double ResearchPaperPolicy();
	double QuizesPolicy();
	double LabsPolicy();
	double TestsPolicy();
	double MidtermPolicy();
	double FinalExamPolicy();
			//Grading Policy
	double discussionBoard{ 0 };
	double researchPaper{ 0 };
	double finalExam{ 0 };
	double homework{ 0 };
	double midterm{ 0 };
	double quizes{ 0 };
	double tests{ 0 };
	double labs{ 0 };
	void setClassName(std::string);
	std::string getClassName() const;
	//Vector to hold grades
	std::vector<double> homewordGrade, discussionBoardGrade,
		quizGrade, testGrade, labsGrade, researchPaperGrade, midtermGrade, finalExamGrade;
	std::string getCourseGrade();
	//Calculate course grade
	double CalculteCourseGrade();
private:

	//Average HomeWork Grade
	std::string ClassName{ "" };
		//Grades received per Criteria
	int* totalDiscussionBoard = new int{ 0 };
	int* totalHomework = new int{ 0 };
	int* totalResearchPaper = new int{ 0 };
	int* totalQuizes = new int{ 0 };
	int* totalTests = new int{ 0 };
	int* totalLabs = new int{ 0 };
	int* totalMidterm = new int{ 0 };
	int* totalFinalExam = new int{ 0 };
	//Grading Policy percentage

		//Class Name

};
#endif