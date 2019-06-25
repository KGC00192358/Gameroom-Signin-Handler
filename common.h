#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <map>
using namespace std;


/****************  
 * 
 * PUBLIC DATA
 *
 ***************/

typedef std::string timestamp;


struct infoBlock{ 
	std::string  Name;
	std::string Id;
	std::string Controller;
	timestamp opDate;
	timestamp timeIn;
	timestamp timeOut;
	struct infoBlock* next;
} ;	

/*
 *
 * PUBLIC FUNCTIONS
 *
 * */

/* PUBLIC FUNCTIONS*/
void signIn(std::map<std::string, infoBlock*> &b);
void signOut(std::map<std::string, infoBlock*> &b);
void menu(std::map<std::string, infoBlock*> &b);
void printSignedIn(std::map<std::string, infoBlock*> &b);

timestamp monthDayYear();
timestamp hourMinuteTime();


timestamp monthDayYear() {
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	std::ostringstream oss;
	oss << std::put_time(&tm, "%m-%d-%y");
	auto monthDayYear = oss.str();
	return monthDayYear;
}


timestamp hourMinuteTime(){
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	std::ostringstream oss;
	oss << std::put_time(&tm, "%H:%M:%S");
	auto hourMinuteTime = oss.str();
	return hourMinuteTime;
};




#endif
