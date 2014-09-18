#include <iostream> 
#include <cstdlib> 
#include <ctime>

class TestScore {
public: 
  TestScore() {
  }

  // load existing scores. 
  void loadScores(double *scores, int s) {
    double score; 
    // for(int i = 0; i < s; i++) {
    //   do {
    // 	std::cout << "Please enter score: " << std::endl;
    // 	std::cin >> score;
    //   } while (score < 0); 
    //   *(scores + i) = score; 
    // }

    // generate random scores and save to array. 
    srand(time(NULL)); 
    for(int i = 0; i < s; i++) {
      do {
	score = rand() % 100; 
      } while(score < 0); 
      *(scores + i) = score;
    }
  }

  // sort the score using some sort algorithm. 
  void sortScores(double *scores, int s) {
    selectionSort(scores, s); 
  }

  // compute the average of the score. 
  double average(double *scores, int s) {
    double avg = 0; 
    for(int i = 0; i < s; i++) {
      avg += *(scores + i);
    }
    return avg / s; 
  }

  double averageWOlowest(double *scores, int s) {
    double avg = 0;
    for(int i = 1; i < s; i++) {
      avg += *(scores + i);
    }
    return avg / (s - 1);
  }

  // print out the scores. 
  void print(double *scores, int s) {
    std::cout << "Test scores: " << std::endl; 
      
    for( int i = 0; i < s; i++) {
      std::cout << *(scores + i) << std::endl; 
    }
  }

private: 
  template<typename T>
  void selectionSort(T array[], size_t size) {
    bool sorted = false; 
    T maxVal; 
    int maxIndex; 
    for(size_t i = 0; i < size && !sorted; i++) {
      maxVal = array[0]; 
      maxIndex = 0; 
      sorted = true; 
      for(size_t j = 1; j < size - i; j++) {
	if(array[j] >= maxVal) {
	  maxVal = array[j]; 
	  maxIndex = j; 
	} else sorted = false; 
      }
      array[maxIndex] = array[size - i - 1]; 
      array[size - i - 1] = maxVal; 

      //printArray(array, size); 
    }
  }
}; 

int main() {
  int size = -10; 
  while(size < 0) {
    std::cout << "How many scores do you have? "; 
    std::cin >> size; 
  }

  double *scores = new double[size]; 
  TestScore *scoreList = new TestScore(); 
  scoreList->loadScores(scores, size);
  scoreList->sortScores(scores, size); 
  std::cout << "Average score: " << scoreList->average(scores, size) << std::endl; 

  std::cout << "Average score w/o lowest: " << scoreList->averageWOlowest(scores, size) << std::endl;

  scoreList->print(scores, size); 

  return 0; 
}
