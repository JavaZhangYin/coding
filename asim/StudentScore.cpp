#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <ctime> 

class StudentScore {
public: 
  //  StudentScore(int nt) {
  //  *this("Simon", 100, nt); 
  // }
  StudentScore (std::string n, int i, int nt) {
    name = n; id = i; numTests = nt; 

    scores = new double[nt]; 
    double score;
    for(int i = 0; i < nt; i++) {
      do {
	score = rand() % 50 + 50; 
      } while(score < 0); 
      *(scores + i) = score;
    }
    avgScore = average(scores, nt); 
    setGrade(); 
  }

  // compute the average of the score. 
  double average(double *scores, int s) {
    double avg = 0; 
    for(int i = 0; i < s; i++) {
      avg += *(scores + i);
    }
    return avg / s; 
  }

  void setGrade () {
    if(avgScore <= 60) grade = 'F'; 
    else if(avgScore >= 61 && avgScore <= 70) grade = 'D'; 
    else if(avgScore >= 71 && avgScore <= 80) grade = 'D'; 
    else if(avgScore >= 81 && avgScore <= 90) grade = 'D'; 
    else grade = 'A'; 
  }

  void print() {
    std::cout << "Name: " << name << std::endl
	      << "Average: " << avgScore << std::endl
	      << "Grade: " << grade << std::endl;

    std::cout << "Scores: " << std::endl;
    for( int i = 0 ; i < numTests; i++) {
      std::cout << *(scores + i) << " "; 
    }
    std::cout << std::endl << std::endl; 
  }

private: 
  std::string name; 
  int id; 
  double *scores; 
  int numTests;
  double avgScore; 
  char grade; 
}; 

int main(int argc, char** argv) {
  int numStudents = -1, numTests = -1; 
  while(numStudents < 0) {
    std::cout << "How many student? "; 
    std::cin >> numStudents; 
  }
  while(numTests < 0) {
    std::cout << "How many tests? ";
    std::cin >> numTests;
  }

  StudentScore* scores[numStudents]; 
  for(int i = 0; i < numStudents; i++) {
    scores[i] = new StudentScore("Simon", 191, numTests); 
  }

  // print scores for all students. 
  srand(time(NULL)); 
  for(int i = 0; i < numStudents; i++) {
    scores[i] -> print(); 
  }
  return 0; 
}
