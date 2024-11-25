#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {

    vector<vector<int>> grades = {
        {85, 90, 88, 92},
        {78, 82, 80, 85},
        {92, 88, 95, 91},
        {79, 75, 80, 83},
        {89, 94, 91, 90},
        {72, 85, 78, 77},
        {92, 91, 93, 95},
        {68, 70, 65, 74},
        {86, 89, 84, 90},
        {78, 80, 77, 79}
    };


    int num_students = grades.size();
    int num_subjects = grades[0].size();

    // Calculate average grade for each student and each subject
    for (int i = 0; i < num_students; i++) {
        double student_avg = 0;
        int highest = *max_element(grades[i].begin(), grades[i].end());
        int lowest = *min_element(grades[i].begin(), grades[i].end());

        for (int j = 0; j < num_subjects; j++) {
            student_avg += grades[i][j];
        }
        student_avg /= num_subjects;

        cout << "Student " << i + 1 << ": Avg Grade = " << fixed << setprecision(2) << student_avg
             << ", Highest = " << highest << ", Lowest = " << lowest << endl;
    }


    for (int j = 0; j < num_subjects; j++) {
        double subject_avg = 0;
        int highest = INT_MIN;
        int lowest = INT_MAX;

        for (int i = 0; i < num_students; i++) {
            subject_avg += grades[i][j];
            highest = max(highest, grades[i][j]);
            lowest = min(lowest, grades[i][j]);
        }
        subject_avg /= num_students;

        cout << "Subject " << j + 1 << ": Avg Grade = " << fixed << setprecision(2) << subject_avg
             << ", Highest = " << highest << ", Lowest = " << lowest << endl;
    }

    return 0;
}
