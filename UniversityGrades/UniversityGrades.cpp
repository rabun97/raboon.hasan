
using namespace std;

#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <string>
#include <fstream>
#include <Windows.h>
#include <algorithm>
#include <format>
#include <utility>
#include "HelpFunctions.h"
#include "Functions.h"
#include "Menu.h"







int main()
{


   
    SetConsoleTitleA("BSc Grades and Attendance System"); // Console Title
    loadData(); // load saved data
    SaveStudents();
    mainmenu(); // show main menu
}
