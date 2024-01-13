#pragma once
using namespace std;






void mainmenu()
{
	system("cls");
	cout << "Welcome to BSc Grades and Attendance System\n";
	cout << "Main Menu\n";
	cout << "(1) Manage Students ("+ to_string((Data_Student.size())) + ")\n";
	cout << "(2) Manage Semesters (" + to_string((Data_YearAndSemesters.size())) + ")\n";
	cout << "(3) View Modules (" + to_string((Data_Module.size())) + ")\n";
	cout << "(4) Manage Grades and Attendance(" + to_string((Data_StudentRecords.size())) + ")\n";
	cout << "(5) View BSc : average mark, grade, ranking and attendance.\n";
	cout << "(q) Exit\n";
	cout << lastline() + "\n";
	getline(cin, input);
	if (input == "1")
	{
		MenuManageUser();
	}
	else if (input == "2")
	{
		MenuManageSemesters();
	}
	else if (input == "3")
	{
		MenuManageModules();
	}
	else if (input == "4")
	{
		MenuGradesandAttendance();
	}
	else if (input == "5")
	{
		ViewBSc();
	}
	else if (input == "q")
	{
		exit(0);
	}
	else 
	{
		Lastline = "Wrong input please try again\n";
		mainmenu();
	}
}

void MenuManageUser()
{
	system("cls");
	cout << "Manage Students(" + to_string((Data_Student.size())) + ")\n";
	cout << "(1) Add\n";
	cout << "(2) Edit\n";
	cout << "(3) View All\n";
	cout << "(b) Back\n";
	cout << lastline() + "\n";
	getline(cin, input);
	if (input == "1")
	{
		ManageUsersAddUser();
	}
	else if (input == "2")
	{
		ManageUsersEditUser();
	}
	else if (input == "3")
	{
		ManageUsersViewAllUser();
	}
	else if (input == "b")
	{
		mainmenu();
	}
	else
	{
		Lastline = "Wrong input please try again\n";
		MenuManageUser();
	}
}

void MenuManageSemesters()
{
	system("cls");
	cout << "Manage Semesters(" + to_string((Data_YearAndSemesters.size())) + ")\n";
	cout << "(1) Add\n";
	cout << "(2) Edit\n";
	cout << "(3) View All\n";
	cout << "(b) Back\n";
	cout << lastline() + "\n";
	getline(cin, input);
	if (input == "1")
	{
		ManageSemestersAdd();
	}
	else if (input == "2")
	{
		ManageSemestersEdit();
	}
	else if (input == "3")
	{
		ManageSemestersViewAll();
	}
	else if (input == "b")
	{
		mainmenu();
	}
	else
	{
		Lastline = "Wrong input please try again\n";
		MenuManageSemesters();
	}
}


void MenuManageModules()
{
	system("cls");
	cout << "Manage Modules(" + to_string((Data_YearAndSemesters.size())) + ")\n";
	cout << "(1) View All\n";
	cout << "(b) Back\n";
	cout << lastline() + "\n";
	getline(cin, input);
	
	 if (input == "1")
	{
		ManageModulesViewAll();
	}
	else if (input == "b")
	{
		mainmenu();
	}
	else
	{
		Lastline = "Wrong input please try again\n";
		MenuManageModules();
	}
}


void MenuGradesandAttendance()
{
	system("cls");
	cout << "Manage Grades and Attendance(" + to_string((Data_StudentRecords.size())) + ")\n";
	cout << "(1) Add\n";
	cout << "(2) Edit\n";
	cout << "(3) View All\n";
	cout << "(b) Back\n";
	cout << lastline() + "\n";
	getline(cin, input);
	if (input == "1")
	{
		ManageRecordAdd();
	}
	else if (input == "2")
	{
		ManageRecordEdit();
	}
	else if (input == "3")
	{
		ManageRecordViewAll();
	}
	else if (input == "b")
	{
		mainmenu();
	}
	else
	{
		Lastline = "Wrong input please try again\n";
		MenuGradesandAttendance();
	}
}
