#pragma once

#include <iomanip>
#include <sstream>

using namespace std;


string input; // temp string for console inputs
string screenbuffer = ""; // temp screen print data


list<string>::iterator  editIT;
list<string>::iterator  idsearch;
string apppath; // program path


//Data
struct SStudent
{
    int id;
    string FirstName;
    string LastName;
    string Email;
    string PhoneNumber;
    int Graduation_YearandSemesterID;
    friend ostream& operator << (ostream &os, SStudent const& a)
    {
        return os << a.id << ";" << a.FirstName << ";" << a.LastName << ";" << a.Email << ";" << a.PhoneNumber << ";" << a.Graduation_YearandSemesterID<< ";";
    }
};

struct SYearandSemester
{
    int id;
    string Semester;
    friend ostream& operator << (ostream& os, SYearandSemester const& a)
    {
        return os << a.id << ";" << a.Semester << ";";
    }
};

struct SModule
{
    int id;
    int Year; // Year(1,2,3 or 4);
    string Module;
    int Credit; //(Default 15) 5-60;
    friend ostream& operator << (ostream& os, SModule const& a)
    {
        return os << a.id << ";" << a.Year << ";" << a.Module << ";" << a.Credit  << ";";
    }
};



struct SGradeRecords
{
    int id;
    int studentID;
    int MoudleID;
    int AssessmentGrades10Quizz;
    int AssessmentGrades20MidtermExam;
    int AssessmentGrades30Assignment;
    int AssessmentGrades40FinalExam;
    int AttendScoor;
    friend ostream& operator << (ostream& os, SGradeRecords const& a)
    {
        return os << a.id << ";" << a.studentID << ";" << a.MoudleID << ";" << a.AssessmentGrades10Quizz << ";" << a.AssessmentGrades20MidtermExam << ";" << a.AssessmentGrades30Assignment << ";" << a.AssessmentGrades40FinalExam << ";" << a.AttendScoor << ";";
    }
};


list<SStudent> Data_Student;
list<SYearandSemester> Data_YearAndSemesters;
list<SModule> Data_Module;
list<SGradeRecords> Data_StudentRecords;

// Save List to File
template< typename T, typename A >
void saveData(const std::list<T, A>& seq, const char* filename)
{
    std::ofstream file(apppath + filename);
    for (const auto& v : seq)
    {
        T tmp = v;
        file << tmp;
        file << "\n";
    }
}



//Get Last Line once
string Lastline = "";
string lastline() //get last line
{
    string tmp;
    tmp = Lastline;
    Lastline = "";
    return tmp;
}


// check if string is number
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
// check if number between two digits
bool isNumber(string i, int min, int max)
{
    if (!is_number(i))
        return false;
    if (stoi(i) < min)
        return false;
    if (stoi(i) > max)
        return false;
    return true;
}

string leftdelete(string i)
{
    return i.substr(i.find(';') + 1, i.size());
}

string leftget(string i)
{
    return i.substr(0, i.find(';'));
}

string GetRecordByID(string id, list<string>& data)
{
    idsearch = data.begin();
    ++idsearch; ++idsearch;
    for (; idsearch != data.end(); ++idsearch)
    {
        string findid = *idsearch;
        if (findid.substr(0, findid.find(';')) == id)
            return *idsearch;
    }
    return "";
}

// Confirm Save
bool ConfirmSave(string s)
{
    system("cls");
    cout << s;
    cout << "\nPress (y) to confirm save else cancel.\n";
    string tmp;
    getline(cin, tmp);
    return tmp == "y";
}


//View Data
template< typename T, typename A >
void View_Data(const std::list<T, A>& lst)
{
    system("cls");
    if (typeid(T) == typeid(SStudent)) cout << "StudentID;FirstName;LastName;Email:PhoneNumber;GraduationYear\n";
    if (typeid(T) == typeid(SYearandSemester)) cout << "SemseterID; SemesterName\n";
    if (typeid(T) == typeid(SGradeRecords)) cout << "ID;StudentID;MoudleID;Quizz10;MidtermExam20,Assignment30;Final40;AttendScore\n";
    for (const auto& v : lst)
    {
        T tmp = v;
        cout << tmp << "\n";
    }
}


string DoubleToString(double i,int digits = 2)
{
    stringstream stream;
    stream << std::fixed << std::setprecision(digits) << i;
    return stream.str();
}



SStudent GetStructStudent(string s)
{
    SStudent tmp;
    tmp.id = stoi(leftget(s));
    s = leftdelete(s);
    tmp.FirstName = leftget(s);
    s = leftdelete(s);
    tmp.LastName = leftget(s);
    s = leftdelete(s);
    tmp.Email = leftget(s);
    s = leftdelete(s);
    tmp.PhoneNumber = leftget(s);
    s = leftdelete(s);
    tmp.Graduation_YearandSemesterID = stoi(leftget(s));
    return tmp;
}

SYearandSemester GetSYearandSemester(string s)
{
    SYearandSemester tmp;
    tmp.id = stoi(leftget(s));
    s = leftdelete(s);
    tmp.Semester = leftget(s);
    return tmp;
}

SModule GetSModule(string s)
{
    SModule tmp;
    tmp.id = stoi(leftget(s));
    s = leftdelete(s);
    tmp.Year = stoi(leftget(s));
    s = leftdelete(s);
    tmp.Module = leftget(s);
    s = leftdelete(s);
    tmp.Credit = stoi(leftget(s));
    return tmp;
}


SGradeRecords GetSGradeRecords(string s)
{
    SGradeRecords tmp;
    tmp.id = stoi(leftget(s));
    s = leftdelete(s);
    tmp.studentID = stoi(leftget(s));
    s = leftdelete(s);
    tmp.MoudleID = stoi(leftget(s));
    s = leftdelete(s);
    tmp.AssessmentGrades10Quizz = stoi(leftget(s));
    s = leftdelete(s);
    tmp.AssessmentGrades20MidtermExam = stoi(leftget(s));
    s = leftdelete(s);
    tmp.AssessmentGrades30Assignment = stoi(leftget(s));
    s = leftdelete(s);
    tmp.AssessmentGrades40FinalExam = stoi(leftget(s));
    s = leftdelete(s);
    tmp.AttendScoor = stoi(leftget(s));
    return tmp;
}



bool isStudentidExist(int i)
{
    list<SStudent>::iterator  it = Data_Student.begin();
    for (; it != Data_Student.end(); ++it)
    {
        if ((*it).id == stoi(input)) { // found the case
            return true;
        }
    }
    return false;
}
bool isMoudleIDExist(int i)
{
    list<SModule>::iterator  it = Data_Module.begin();
    for (; it != Data_Module.end(); ++it)
    {
        if ((*it).id == stoi(input)) { // found the case
            return true;
        }
    }
    return false;
}

bool isMoudleIDandStudentIDExist(int StudentID, int MoudleID)
{
    list<SGradeRecords>::iterator  it = Data_StudentRecords.begin();
    for (; it != Data_StudentRecords.end(); ++it)
    {
        if ((*it).MoudleID == MoudleID && (*it).studentID == StudentID) { // found the case
            return true;
        }
    }
    return false;
}
