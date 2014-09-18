#include <iostream>
#include <string> 

using namespace std; 

struct Student {
  string name; 
  string idNum; 
  int *testScore; 
  double avg; 
  char grade; 
} ; 

void getStudentInfo(Student**, int, int); 
void sortScores(int *, int); 
double calcAverage(Student*, int); 
double calcAverageWithoutLowest(Student* , int );
char calcGrade(Student*); 
void showInfo(Student*, int);

int main() {
  int numStudents, numTests; 
  cout << "How many students? "; 
  cin >> numStudents; 
  cout << "How many tests? "; 
  cin >> numTests; 

  Student *st[numStudents]; 

  getStudentInfo(st, numTests, numStudents); 

  for(int i = 0; i < numStudents; i++) {
    // Sort scores. 
    sortScores(st[i]->testScore, numTests); 

    // Get average.
    st[i]->avg = calcAverage(st[i], numTests); 
    
    // get grade. 
    st[i]->grade = calcGrade(st[i]); 

    // print the student info. 
    showInfo(st[i], numTests); 

    // delete dynamic objects. 
    delete st[i];
    delete [] st[i]->testScore; 
  }
}

void getStudentInfo(Student *st[], int numTests, int numStudents) {
  for(int i = 0; i < numStudents; i++) {
    st[i] = new Student(); 
    cout << "Name of student: "; cin >> st[i]->name; 
    cout << "Id of student  : "; cin >> st[i]->idNum; 

    // get scores from user.
    st[i]->testScore = new int[numTests]; 

    for(int j = 0; j < numTests; j++) {
      double score = -1; 
      while (score < 0) {
	cout << "Enter score " << j + 1 << ":"; cin >> score; 
      	if(score < 0) cout << "Invalid score value" << endl; 
	*(st[i]->testScore + j) = score;
      }
    }
  }
}

void sortScores(int *array, int size) {
  for(size_t i = 0; i < size; i++) {
    for(size_t j = 0; j < size; j++) {
      if(array[i] < array[j]) {
	
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
      }
    }
  }
}

double calcAverage(Student* st, int numTests) {
  double sum = 0; 
  for(int i = 0; i < numTests; i++) {
    sum += *(st->testScore + i);
  }
  return sum / numTests; 
}

double calcAverageWithoutLowest(Student* st, int numTests) {
  double sum = 0;
  for(int i = 1; i < numTests; i++) {
    sum += *(st->testScore + i);
  }
  return sum / (numTests - 1);
}

char calcGrade(Student* st) {
  double avg = st->avg; 
  if(avg > 90) return 'A'; 
  if(avg > 80) return 'B';
  if(avg > 70) return 'C'; 
  if(avg > 60) return 'D'; 
  return 'F'; 
}

void showInfo(Student* st, int numTests) {
  cout << endl << "------Student info------" << endl;
  cout << "Student Name: " << st->name << endl
       << "Student Id  : " << st->idNum << endl;
  cout << "Test scores: "; 
  for(int i = 0; i < numTests; i++) {
    cout << *(st->testScore + i) << " "; 
  }
  cout << endl;

  cout << "Test Average: " << st->avg << endl
    //       << "Average w/o lowest score: " << calcAverageWithoutLowest(st, numTests) << endl 
       << "Test Grade  : " << st->grade << endl << endl; 
}
