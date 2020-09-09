#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


bool isPerfectSquareNumber(int number) {
    long double sr = sqrt(number);
    return ((sr - floor(sr)) == 0);
}

int main() {
    
    int numberOfTestCases;
    int sqaureSize;
    vector<int> perfectSquareNumberArray;

    cin >> numberOfTestCases;
    
    for (int i=0; i<numberOfTestCases; i++) {
        cin >> sqaureSize;

        int sum = 0;
        int inputedNumber;

        for (int row=0; row<sqaureSize; row++) {
            for (int col=0; col<sqaureSize; col++) {
                cin >> inputedNumber;
                
                if (isPerfectSquareNumber(inputedNumber)) {
                    sum += inputedNumber;
                }
            }
        }

        perfectSquareNumberArray.push_back(sum);
    }

    for(int i=0; i<perfectSquareNumberArray.size(); ++i) {
        std::cout << perfectSquareNumberArray[i] << '\n';
    }
}
----------------------------------------------------------------


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int getMaxNumber(int firstNumber, int secondNumber, int thirdNumber) {
    return fmax(thirdNumber, fmax(firstNumber, secondNumber));
}

int main() {
    
    int numberOfTestCases;
    vector<int> maxNumbersArray;

    int firstNumber;
    int secondNumber;
    int thirdNumber;

    cin >> numberOfTestCases;
    
    for (int i=0; i<numberOfTestCases; i++) {
        cin >> firstNumber;
        cin >> secondNumber;
        cin >> thirdNumber;
        
        maxNumbersArray.push_back(getMaxNumber(firstNumber, secondNumber, thirdNumber));
    }
    
    for(int i=0; i<maxNumbersArray.size(); ++i) {
        std::cout << maxNumbersArray[i] << '\n';
    }
}

--------------------------------------------------

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int calculateAbsoluteValues(int firstNumber, int secondNumber) {
    return abs(firstNumber) + abs(secondNumber);
}

int main() {
    
    int numberOfTestCases;
    vector<int> absoluteValues;

    int firstNumber;
    int secondNumber;
    
    cin >> numberOfTestCases;
    
    for (int i=0; i<numberOfTestCases; i++) {
        cin >> firstNumber;
        cin >> secondNumber;
        
        absoluteValues.push_back(calculateAbsoluteValues(firstNumber, secondNumber));
    }
    
    for(int i=0; i<absoluteValues.size(); ++i) {
        std::cout << absoluteValues[i] << '\n';
    }
}
------------------------------------------

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

char getMaxRepeatedChar(string word) {
    
    sort(word.begin(), word.end());
    map<char, int> charactersMapCount;
    int defaultCharCount = 1;

    char maxRepeatedChar;
    int maxCount = 0;
    
    for(int i = 0; i < word.size(); i++) {

        bool isCharacterAlreadySet = charactersMapCount.count(word[i]);

        if (isCharacterAlreadySet) {
            
            charactersMapCount[word[i]] += 1;

        } else {
            charactersMapCount.insert(std::make_pair(word[i], defaultCharCount));
        }

        // if new value is greated than maxCount, set new maxRepeatedChar
        if (charactersMapCount[word[i]] > maxCount) {
            maxRepeatedChar = word[i];
            maxCount = charactersMapCount[word[i]];
        }
        
    }

    return maxRepeatedChar;
}

int main() {

    int numberOfTestCases;
    vector<char> maxRepeatedCharactersArray;
    vector<string> wordsArray;

    cin >> numberOfTestCases;

    for (int i=0; i < numberOfTestCases; i++) {

        string inputWord;
        int numberOfChars;
        

        cin >> numberOfChars;
        cin >> inputWord;

        wordsArray.push_back(inputWord);
    }
    
    for (int i = 0; i < wordsArray.size(); i++) {
        cout << getMaxRepeatedChar(wordsArray[i]);
        cout << endl;

    }
}


-------------------------------------------------------------

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;


int calulateSummation(vector<int> numbersArray) {
    
    if (numbersArray.size() == 1) {
        return numbersArray.back();
    }

    int removedElementValue = numbersArray.back();
    numbersArray.pop_back();
    
    return calulateSummation(numbersArray) + removedElementValue;
}

int main() {

    int numberOfTestCases;
    int sizeOfArray;

    cin >> numberOfTestCases;

    for (int i=0; i<numberOfTestCases; i++) {
        
        vector<int> numbersArray;
        cin >> sizeOfArray;
        
        int inputedNumber;

        for (int j = 0; j < sizeOfArray; j++) {
            cin >> inputedNumber;
            numbersArray.push_back(inputedNumber);
        }

        cout << "Case " << i+1 << ": " << calulateSummation(numbersArray);
        cout << endl;
    }
}

-----------------

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;


vector<char> getRowStars(int rowNumber, int matrixSize, int numberOfStars) {
    
    vector<char> rowData;
    int matrixMedianRowNumber = (matrixSize / 2) + 1;
    
    if (rowNumber == matrixMedianRowNumber) {

        // return a char array that is filled with stars same as the matrixSize
        for (int i=0; i < matrixSize; i++) {
            rowData.push_back('*');
        }
        
        return rowData;

    }
    
    int numberOfStarsOnEachSide = numberOfStars / 2;
    int numberOfSpaces = matrixSize - numberOfStars;

    for (int i=0; i < numberOfStarsOnEachSide; i++) {
        rowData.push_back('*');
    }
    
    for (int i=0; i < numberOfSpaces; i++) {
        rowData.push_back(' ');
    }
    
    for (int i=0; i < numberOfStarsOnEachSide; i++) {
        rowData.push_back('*');
    }

    return rowData;
        
}

int main() {

    vector<vector<char>> matrix;
    int matrixSize;

    cin >> matrixSize;
    int matrixMedianRowNumber = (matrixSize / 2) + 1;

    if (matrixSize == 1) {
        cout << "*";
        return 0;
    }

    int numberOfStars = 0;

    vector<char> row;

    for (int row = 1; row <= matrixSize; row++) {
        
        // With each row iteration, the number of stars increase by 2 till we reach the median row
        row <= matrixMedianRowNumber ?  numberOfStars += 2 : numberOfStars -= 2;

        matrix.push_back(getRowStars(row, matrixSize, numberOfStars));
        
    }
    
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
          cout << matrix[i][j];
      }
      cout << endl;
    }
}
