//Question 1: write a function that accepts an input and then searches myArray for this input. The function should return true if found and false other wise

#include <iostream>
using namespace std;

 bool searchArray(int myArray[], int input) 
 {
    for (int i = 0; i < 10; i++) {
        if (myArray[i] == input) {
            return true;
            }

    }

    return false;

}
int main() 
{
    int myArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int input;
    cout << "Enter a number to search for: ";
    cin >> input;
    if (searchArray(myArray, input)) {
        cout << "Found!" << endl;
         } else {
            cout << "Not found." << endl;
             }
             return 0;
}

 
//Question 2: write a function that accepts myArray and n as inputs then returns (or prints) the minimum value among the first n elements of myArray.
#include <iostream>
#include <cstdlib>
using namespace std;

 int findMin(int myArray[], int n)
{
    int min = myArray[0];
    for (int i = 0; i < n; i++)
    {
        if (myArray[i] < min)
        {
            min = myArray[i];
        }
    }
    return min;
}

int main()
{
    int myArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = 4;
    int min = findMin(myArray, n);
    cout << min << endl;
   system("pause");
    return 0;
}

//Question 3: write a function that returns (or prints) both the maximum and minimum values of myArray. use reference parameters.

#include <iostream>
#include <limits>
using namespace std;

void getArrayMaxMin(float& min, float& max, float myArray [], int arraySize)
{
    min = myArray[0];
    max = myArray[0];
    for (int i = 1; i < arraySize; ++i) {
        if (myArray[i] < min)
            min = myArray[i];
        if (myArray[i] > max)
            max = myArray[i];
    }
}

int main(void)
{
    float myArray[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float min = 0.0;
    float max = 0.0;

   getArrayMaxMin(min, max, myArray, 5);
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    return 0;
}

//Question 4: write a function that returns (or prints) both the largest and second largest 
//values in myArray. use reference parameters. Note: largest and second largest can equal (e.g. a[5] = {3,1,2,3,2}).
#include <iostream>
using namespace std;

void twolargest(float& maxOne, float& maxTwo, float myArray[], int arraySize) {
    for (int i = 0; i < arraySize; i++)
    {
        if (myArray[i] > maxOne)
        {
            maxTwo = maxOne;
            maxOne = myArray[i];
        }
        else if (myArray[i] > maxTwo && myArray[i] < maxOne)
        {
            maxTwo = myArray[i];
        }
    }
    cout << "The largest value in the array is " << maxOne << endl;
    cout << "The second largest value in the array is " << maxTwo << endl;
}

int main()
{
    float maxOne = 0;
    float maxTwo = 0;
    float myArray[] = {3,1,2,3,2};
    int arraySize = 5;
    twolargest(maxOne, maxTwo, myArray, arraySize);
    return 0;
}

//Question 5: write a function that returns (or prints) the standard deviation of a data set

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

float stddev(vector<int> data)
{
    float mean=0.0, variance=0.0;
    int i;
   for(i=0;i<data.size();i++)
    {
         mean+=data[i];
    }

   mean=mean/data.size();
   for(i=0;i<data.size();i++)
    {
       variance+=(data[i]-mean)*(data[i]-mean);
    }

   variance=variance/data.size();
    return sqrt(variance);
}

int main()
{
    vector<int> data={1,2,3,4,5};
    cout << stddev(data) << endl;
    return 0;
}

//Question 6: write a function that accepts one line of text as input and prints out thesame text with upper case characters.

#include <iostream>
#include <string>

using namespace std;

void convertToUpperCase(string &text);

int main()
{
    string text = "This is a test.";
   convertToUpperCase(text);
    cout << text << endl;
    return 0;
}

void convertToUpperCase(string &text)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = toupper(text[i]);
    }
}

//Question 7: write a function that accepts one line of text as 
//input and prints out the text with the words reversed (e.g. input: Thank god its friday; output: friday its god thank)
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
   string text;
   cout << "Enter a line of text: ";
   getline(cin, text);
  reverse(text.begin(), text.end());
   cout << text << endl;
   return 0;
}

//Question 8: write a function that reads full names and 
//prints them out in standard telephone directory format (e.g. input: Martin Luther King; output: King, Martin L.)
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void telephone_directory_format(string name)
{
    istringstream iss(name);
    string last_name, first_name, middle_name;
    iss >> first_name >> last_name;
    if (iss >> middle_name) {
        cout << last_name << ", " << first_name << " " << middle_name[0] << ".";
    } else {

        cout << last_name << ", " << first_name;
    }
    cout << endl;
}

int main()
{
    string name;
    while (getline(cin, name)) {
       telephone_directory_format(name);
    }
    return 0;
}

//Question 9: write a function that returns the number of lines, words and letter frequency in its input.
int count_words(string input)
{
    int word_count = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (isalpha(input[i]))
        {
           word_count++;
            while (isalpha(input[i]))
            {
                i++;
            }
        }
    }
    return word_count;
}

int count_letters(string input)
{
    int letter_count = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (isalpha(input[i]))
        {
           letter_count++;
        }
    }
    return letter_count;
}
void letter_frequency(string input, int *freq)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (isalpha(input[i]))
        {
            char c = tolower(input[i]);
            freq[c - 'a']++;
        }
    }
}

int main()
{
    string input;
    getline(cin, input);
    int word_count = count_words(input);
    int letter_count = count_letters(input);
    int freq[26] = {0};
   letter_frequency(input, freq);
    for (int i = 0; i < 26; i++)
    {
        cout << char('a' + i) << ": " << freq[i] << endl;
    }
    cout << "Words: " << word_count << endl;
    cout << "Letters: " << letter_count << endl;
    return 0;
}

//Question 10: write a function that takes an integer as input and return (or prints) its correspnding roman numeral. (e.g. input: 16; output: XVI).



//Question 11: write a function that accepts a string as input and returns (or prints) the reversed string. (e.g. input: 'fgbcapo'; output: 'opacbgf' ).


//Question 12: Explain the running time of each function you write using big O notation.