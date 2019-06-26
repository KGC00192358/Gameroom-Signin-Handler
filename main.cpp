#include </home/kevin/cppProjects/gameroom/common.h>


int main(int argc, char *argv[]) 
{

	std::map<std::string, infoBlock*> b;
	menu(b);
}

void menu(std::map<std::string, infoBlock*> &b) {
	int opt = 0;
	while(true) {
		std::cout << "Please Select an option\n\t1) Sign In\n\t2) Sign Out\n\t3) List all signed in\n";
		std::cin >> opt;
		if (opt == 1) {
			cout << "map size: " << b.size() << endl;
			signIn(b);
			cout << "map size: " << b.size() << endl;

		} else if (opt == 2) {
			signOut(b);
		} else if (opt == 15){
			writeOut(b);
			return;
		} else if(opt == 3) {
			printSignedIn(b);		
		}else {
			std::cout << "Invalid Option!";
			opt = 0;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::fflush(stdin);
		}
	}
	return;
}

void signIn(std::map<std::string, infoBlock*> &b) {
	infoBlock* newEntry = new infoBlock();
	std::string name = "";
	std::string id = "";
	std::cout << "Please enter your name:\n";
	std::cin >> name;
	std::cout << "Please enter your auburn ID:\n";
	std::cin >> id;
	(*newEntry).Name = name;
	(*newEntry).Id = id;
	(*newEntry).opDate = monthDayYear();
	(*newEntry).timeIn = hourMinuteTime();	
	(*newEntry).timeOut = "-0:-0";
	b.insert(std::pair<std::string, infoBlock*>(id, newEntry));
}

void  signOut(std::map<std::string, infoBlock*> &b) {
	std::string id;
	std::cout << "please enter your Auburn ID:\n";
	std::cin >> id;
	if(b.count(id) != 0){
		b[id]->timeOut = hourMinuteTime();
	} else {
		std::cout << "You are not currently signed in.\n";
	}
}

void printSignedIn(std::map<std::string, infoBlock*> &b) {
	for (auto const& x : b) {
		if(x.second->timeOut.compare("-0:-0") == 0) {
			std::cout << '\t' << x.first << '\t' << x.second->Name 
				<< '\t' << x.second->timeIn << '\t' << x.second->timeOut << endl;
		}
	}
}

void writeOut(std::map<std::string, infoBlock*> &b) {
	std::string filename = "Sign_in_sheet_" + monthDayYear();	
	std::string comma = ", ";
	ofstream outfile;
	outfile.open(filename);
	outfile << "Student Id, " << "Name, " << "Date, " << "Time In, " 
		<< "Time Out" << endl;
	for(auto const& x : b) {
		outfile << x.first << comma 
			<< x.second->Name << comma 
			<< x.second->opDate << comma
			<< x.second->timeIn << comma
			<< x.second->timeOut << endl;	
	}
}
