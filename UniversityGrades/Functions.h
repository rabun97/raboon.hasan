#pragma once


using namespace std;





//forward declaration menu functions
void MenuManageUser(); 
void MenuManageSemesters();
void MenuManageModules();
void MenuGradesandAttendance();
void mainmenu();






void loadData()
{
    //GetProgramPath
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    apppath = string(buffer).substr(0, pos);

    //Load Student
    ifstream infile(apppath + "\\DataStudent.txt");
    while (getline(infile, input)) if (!input.empty()) {
        Data_Student.push_back(GetStructStudent(input));
    }

    ifstream infile2(apppath + "\\DataYearAndSemesters.txt");
    while (getline(infile2, input)) if (!input.empty()) {
        Data_YearAndSemesters.push_back(GetSYearandSemester(input));
    }

    ifstream infile3(apppath + "\\DataModule.txt");
    while (getline(infile3, input)) if (!input.empty()) {
        Data_Module.push_back(GetSModule(input));
    }
    ifstream infile4(apppath + "\\DataStudentRecords.txt");
    while (getline(infile4, input)) if (!input.empty()) {
        Data_StudentRecords.push_back(GetSGradeRecords(input));
    }

}

void SaveStudents()
{
    saveData(Data_Student, "\\DataStudent.txt");
}
void SaveDataYearAndSemesters()
{
    saveData(Data_YearAndSemesters, "\\DataYearAndSemesters.txt");
}

void SaveDataStudentRecords()
{
    saveData(Data_StudentRecords, "\\DataStudentRecords.txt");
}


bool isAllowedInput(string i)
{
    if (i.empty()) return false;// no empty input allowed
    if (i.find(';') != string::npos) return false; // no ';' char allowed
    return true;
}

bool isIDExist(string i, list<string>& data)
{
    if (i.empty()) return false;// no empty input allowed
    idsearch = data.begin();
    for (; idsearch != data.end(); ++idsearch)
    {
        string findid = *idsearch;
        findid = findid.substr(0, findid.find(';'));
        if (findid ==i)  return true;
    }
    return false;
}






string GetInputString(string entryname)
{
    screenbuffer += "\n"+ entryname +" is :";
    system("cls");
    cout << screenbuffer + "...\n";
    while (true)
    {
        getline(cin, input);
        if (isAllowedInput(input)) break;
        system("cls");
        cout << screenbuffer + "...\nWrong Entery Try Again\n";
    }
    screenbuffer += input;
    return input;
}
string GetInputNumber(string entryname,int min,int max)
{
    screenbuffer +=  "\n" + entryname + " is :";
    system("cls");
    cout << screenbuffer + "...\n";
    while (true)
    {
        getline(cin, input);
        if (isNumber(input, min, max)) break;
        system("cls");
        cout << screenbuffer + "...\nWrong Entery Try Again with number between "+to_string(min) + " and "+ to_string(max) + "\n";
    }
    screenbuffer += input;
    return input;
}
string GetInputMoudleID(int studentid,int oldmoudleid)
{
    screenbuffer = screenbuffer + "\n" + "Moudle ID" + " is :";
    system("cls");
    cout << screenbuffer + "...\n";
    while (true)
    {
        getline(cin, input);
        if (is_number(input) && isMoudleIDExist(stoi(input))) {
        
            if (oldmoudleid!= -1 and oldmoudleid == stoi(input)) continue;
            if (isMoudleIDandStudentIDExist(studentid, stoi(input)))
            {

                system("cls");
                cout << screenbuffer + "...\nMoudle ID already defnied for same student try diffrent id or edit old entry" + "\n";
                continue;
            }

            break;
        };
        system("cls");
        cout << screenbuffer + "...\nNo Moudle found by that ID" + "\n";
    }
    screenbuffer += input;
    return input;
}
string GetInputStudentID()
{
    screenbuffer = screenbuffer + "\n" + "Student ID" + " is :";
    system("cls");
    cout << screenbuffer + "...\n";
    while (true)
    {
        getline(cin, input);
        if (is_number(input) && isStudentidExist(stoi(input))) break;
        system("cls");
        cout << screenbuffer + "...\nNo Student found by that ID" + "\n";
    }
    screenbuffer += input;
    return input;
}

void ManageUsersAddUser()
{
    SStudent newstudent;
    newstudent.id = Data_Student.back().id + 1;
    screenbuffer = "Manage Student - Add New Student Data entry ID : " + to_string(newstudent.id);
    newstudent.FirstName = GetInputString("FirstName");
    newstudent.LastName = GetInputString("LastName");
    newstudent.Email = GetInputString("Email");
    newstudent.PhoneNumber = GetInputString("Phone Number");
    newstudent.Graduation_YearandSemesterID = stoi(GetInputNumber("Graduation Year",2000,2100));
    Data_Student.push_back(newstudent);
    SaveStudents();
    MenuManageUser();
}

void ManageUsersEditUser()
{
    system("cls");
    View_Data(Data_Student);
    cout << "\nEnter (ID) of Student to edit or (b) for back\n";
    cout << lastline() + "\n";
    getline(cin, input);
    bool foundthecase = false;
    if (input == "b") return;
    else if (is_number(input))
    {
        list<SStudent>::iterator  it = Data_Student.begin();
        for (; it != Data_Student.end(); ++it)
        {
            if ((*it).id == stoi(input)) { // found the case
                foundthecase = true;
                screenbuffer = "Manage Student - Add New Student Data entry ID : " + to_string((*it).id);
                (*it).FirstName = GetInputString("FirstName");
                (*it).LastName = GetInputString("LastName");
                (*it).Email = GetInputString("Email");
                (*it).PhoneNumber = GetInputString("Phone Number");
                (*it).Graduation_YearandSemesterID = stoi(GetInputNumber("Graduation Year", 2010, 2100));
                SaveStudents();
                break;
            }
        }
        if (!foundthecase) { Lastline = "Student ID not Found\n"; ManageUsersEditUser(); }

    }
    else {
        Lastline = "Wrong input please try again\n";
        ManageUsersEditUser();
    }
    MenuManageUser();
}

void ManageUsersViewAllUser()
{
    View_Data(Data_Student);
    cout << "\nEnter to go Back\n";
    getline(cin, input);
    MenuManageUser();
}

void ManageSemestersAdd()
{
    SYearandSemester newentry;
    newentry.id = Data_YearAndSemesters.back().id + 1;
    screenbuffer = "Manage Semesters - Add New Semesters Data entry ID : " + to_string(newentry.id);
    newentry.Semester = GetInputString("Semester Name YYS or YYF");
    Data_YearAndSemesters.push_back(newentry);
    SaveDataYearAndSemesters();
    MenuManageSemesters();
}

void ManageSemestersEdit()
{
    system("cls");
    View_Data(Data_YearAndSemesters);
    cout << "\nEnter (ID) of Semester to edit or (b) for back\n";
    cout << lastline() + "\n";
    getline(cin, input);
    bool foundthecase = false;
    if (input == "b") return;
    else if (is_number(input))
    {
        list<SYearandSemester>::iterator  it = Data_YearAndSemesters.begin();
        for (; it != Data_YearAndSemesters.end(); ++it)
        {
            if ((*it).id == stoi(input)) { // found the case
                foundthecase = true;
                screenbuffer = "Manage Semester - Edit Semester Data entry ID : " + to_string((*it).id);
                (*it).Semester = GetInputString("Semester Name YYS or YYF");
                SaveDataYearAndSemesters();
                break;
            }
        }
        if (!foundthecase) { Lastline = "Semester ID not Found\n"; ManageSemestersEdit(); }

    }
    else {
        Lastline = "Wrong input please try again\n";
        ManageSemestersEdit();
    }
 
    MenuManageSemesters();
}

void ManageSemestersViewAll()
{
    View_Data(Data_YearAndSemesters);
    cout << "\Enter to go Back\n";
    getline(cin, input);
    MenuManageSemesters();

}


void ManageModulesViewAll()
{
    View_Data(Data_Module);
    cout << "\Enter to go Back\n";
    getline(cin, input);
    MenuManageModules();

}


void ManageRecordAdd()
{
    SGradeRecords newentry;
    newentry.id = Data_StudentRecords.back().id + 1;
    screenbuffer = "Manage Grades and Attendance - Add New Record ";
    newentry.studentID = stoi(GetInputStudentID());
    newentry.MoudleID = stoi(GetInputMoudleID(newentry.studentID,-1));
    newentry.AssessmentGrades10Quizz = stoi(GetInputNumber("AssessmentGrades10Quizz", 0, 100));
    newentry.AssessmentGrades20MidtermExam = stoi(GetInputNumber("AssessmentGrades20MidtermExam", 0, 100));
    newentry.AssessmentGrades30Assignment = stoi(GetInputNumber("AssessmentGrades30Assignment", 0, 100));
    newentry.AssessmentGrades40FinalExam = stoi(GetInputNumber("AssessmentGrades40FinalExam", 0, 100));
    newentry.AttendScoor = stoi(GetInputNumber("Attend Scoor 0 - 12", 0, 12));
    Data_StudentRecords.push_back(newentry);
    SaveDataStudentRecords();
    MenuGradesandAttendance();
}

void ManageRecordEdit()
{
   
    system("cls");
    View_Data(Data_StudentRecords);
    cout << "\nEnter (ID) of Grade to edit or (b) for back\n";
    cout << lastline() + "\n";
    getline(cin, input);
    bool foundthecase = false;
    if (input == "b") return;
    else if (is_number(input))
    {
        list<SGradeRecords>::iterator  it = Data_StudentRecords.begin();
        for (; it != Data_StudentRecords.end(); ++it)
        {
            if ((*it).id == stoi(input)) { // found the case
                foundthecase = true;
                screenbuffer = "Manage Grades and Attendance - Edit Data entry ID : " + to_string((*it).id)
                    +"\nStudent ID is : "+ to_string((*it).studentID) + " and Moudle ID is " + to_string((*it).MoudleID);
               // (*it).studentID = stoi(GetInputStudentID());
                //(*it).MoudleID = stoi(GetInputMoudleID((*it).studentID,(*it).MoudleID));
                (*it).AssessmentGrades10Quizz = stoi(GetInputNumber("AssessmentGrades10Quizz", 0, 100));
                (*it).AssessmentGrades20MidtermExam = stoi(GetInputNumber("AssessmentGrades20MidtermExam", 0, 100));
                (*it).AssessmentGrades30Assignment = stoi(GetInputNumber("AssessmentGrades30Assignment", 0, 100));
                (*it).AssessmentGrades40FinalExam = stoi(GetInputNumber("AssessmentGrades40FinalExam", 0, 100));
                (*it).AttendScoor = stoi(GetInputNumber("Attend Scoor 0 - 12", 0, 12));
                SaveDataStudentRecords();
                break;
            }
        }
        if (!foundthecase) { Lastline = "Grade ID not Found\n"; ManageRecordEdit(); }

    }
    else {
        Lastline = "Wrong input please try again\n";
        ManageRecordEdit();
    }

    SaveDataStudentRecords();
    MenuGradesandAttendance();

}



void ManageRecordViewAll()
{
    View_Data(Data_StudentRecords);
    cout << "\Enter to go Back\n";
    getline(cin, input);
    MenuGradesandAttendance();
}

SModule GetMoudlebyID(int moudleid)
{
    list<SModule>::iterator it;
    it = Data_Module.begin();
    SModule tmp;
    for (; it != Data_Module.end(); ++it)
    {
        if ((*it).id == moudleid) return *it;
    }
    return tmp;
}
string getStudentData(SStudent studentrecord)
{
    list<SGradeRecords>::iterator it;
    it = Data_StudentRecords.begin(); 
    int StudentScoreAttent = 0;
    int StudentScoreAttentTotal = 0;
    double StudentScore = 0;
    double StudentScoreTotal = 0;
    for (; it != Data_StudentRecords.end(); ++it)
    {
        if (studentrecord.id == (*it).studentID)
        {
            SGradeRecords gradrecord = *it;
            SModule moudle = GetMoudlebyID(gradrecord.MoudleID);
            StudentScoreAttent = StudentScoreAttent + (*it).AttendScoor;
            StudentScoreAttentTotal = StudentScoreAttentTotal + 12;

            double yearWeight = 0;
            if (moudle.Year == 1) yearWeight = 0.1;  // 10%
            else if (moudle.Year == 2) yearWeight = 0.2; // 20%
            else if (moudle.Year == 3) yearWeight = 0.3; // 30%
            else if (moudle.Year == 4) yearWeight = 0.4; // 40%

            double tmp = (gradrecord.AssessmentGrades10Quizz * 0.1) + (gradrecord.AssessmentGrades20MidtermExam * 0.2) + (gradrecord.AssessmentGrades30Assignment * 0.3) + (gradrecord.AssessmentGrades40FinalExam * 0.4);
            tmp = tmp * moudle.Credit * yearWeight /100;
            StudentScore = StudentScore + tmp;
            StudentScoreTotal = StudentScoreTotal + (moudle.Credit * yearWeight);
        }
    }
    double avrage = 0;
    if(StudentScoreTotal!=0) avrage = StudentScore / StudentScoreTotal*100;
    return to_string(studentrecord.Graduation_YearandSemesterID) + ";" + DoubleToString(avrage,2)  + "%;" + DoubleToString(StudentScore, 2) + "/" + DoubleToString(StudentScoreTotal, 0) + ";" + to_string(StudentScoreAttent) + "/" + to_string(StudentScoreAttentTotal) + ";" + studentrecord.FirstName + " " + studentrecord.LastName + ";";
}


void ViewBSc()
{

    list<SStudent>::iterator it;
    list<string> AllStudentBSc;
    it = Data_Student.begin();
    for (; it != Data_Student.end(); ++it)
    {
        //for each student 
        AllStudentBSc.push_back(getStudentData(*it));
    }

    AllStudentBSc.sort();
    AllStudentBSc.reverse();
    AllStudentBSc.push_front("All BSc order by Years, Avrage Descending\nGraduation Year;Avrage;Weight Credit/Total;Attend/Total;Student Name;");
    View_Data(AllStudentBSc);
    cout << "\Enter to go Back\n";
    getline(cin, input);
    mainmenu();
}






