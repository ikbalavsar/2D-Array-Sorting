#include <iostream>
#include <fstream>

using namespace std;

struct Student{
    string std_name;
    int std_ID;
    int std_grade;
};

int main() {
    int std_num;
    double sum = 0;
    double mean;

    cout << "Please enter the student number: ";
    cin >> std_num;

    struct Student CourseGrades[std_num];
    int i = 1;
    while(i <= std_num){
        cout << "***** Student "<<i<<" *****"<< endl;

        cout<< "Please Enter the Student Name: ";
        cin >> CourseGrades[i].std_name;

        cout << "Please Enter the Student ID: ";
        cin >> CourseGrades[i].std_ID;

        cout << "Please Enter the Student Grade: ";
        cin >> CourseGrades[i].std_grade;

        sum += CourseGrades[i].std_grade;
        i++;
    }
    ofstream std_file;
    std_file.open("Students_Info.txt");
    for(int j = 1; j <= std_num; j++){
        std_file <<"\n***** Student "<< j<<" *****"<< endl;
        std_file<< "Student Name : "<< CourseGrades[j].std_name<< endl;
        std_file<< "Student ID : "<< CourseGrades[j].std_ID<< endl;
        std_file<< "Student Grade : "<< CourseGrades[j].std_grade<< endl;
    }
    cout << "***** List of the students ***** "<< endl;
    int n = 1;
    while(n <= std_num){
        cout << "\n***** Student *****"<< n<< endl;
        cout << "Student Name: "<< CourseGrades[n].std_name<< endl;
        cout << "Student ID: "<< CourseGrades[n].std_ID<< endl;
        cout << "Student Grade : "<< CourseGrades[n].std_grade<< endl;
        if((CourseGrades[n].std_grade >= 0) &&(CourseGrades[n].std_grade <= 60) ){
            cout<< "The letter grade of student is F."<< endl;
        }else if((CourseGrades[n].std_grade >= 60) &&(CourseGrades[n].std_grade <= 75) ){
            cout<< "The letter grade of student is C."<< endl;
        }else if((CourseGrades[n].std_grade >= 75) &&(CourseGrades[n].std_grade <= 90) ){
            cout<< "The letter grade of student is B."<< endl;}
        else{
            cout<< "The letter grade of student is A."<< endl;}
        n++;
    }
    mean = sum/std_num;
    cout<< "The average grade of lecture is "<< mean<<" ."<< endl;
    return 0;
}
