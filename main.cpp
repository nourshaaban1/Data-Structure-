#include <vector>
#include <stack>
#include <set>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <functional>
#include <chrono>
using namespace std;
using namespace std::chrono;
//-----------------------------------------------class--------------------------------------------------------------------------
class Student
{
private:
    string id;
    string name;
    double gpa;

public:
    // Regular constructor
    Student(string name, string id, double gpa);

    // Copy constructor
    Student(const Student &other);

    // Getter methods
    string get_id() const;
    string get_name() const;
    double get_gpa() const;

    // Display method
    void display(ostream &os) const;
    void display() const;

    // Overload comparison operators
    friend bool operator<(const Student &s1, const Student &s2);
    friend bool operator>(const Student &s1, const Student &s2);
    friend bool operator==(const Student &s1, const Student &s2);
};
//-----------------------------------------------class_implementation----------------------------------------------------------------

Student::Student(string name, string id, double gpa)
{
    this->name = name;
    this->id = id;
    this->gpa = gpa;
}

Student::Student(const Student &other) : name(other.name), id(other.id), gpa(other.gpa) {}

string Student::get_name() const
{
    return name;
}

string Student::get_id() const
{
    return id;
}

double Student::get_gpa() const
{
    return gpa;
}

void Student::display(ostream &os) const
{
    os << "Name: " << name << "\n";
    os << "ID: " << id << "\n";
    os << "Gpa: " << gpa << "\n";
}

void Student::display() const
{
    cout << "Name: " << name << "\n";
    cout << "ID: " << id << "\n";
    cout << "Gpa: " << gpa << "\n";
}

bool operator<(const Student &s1, const Student &s2)
{
    return s1.name < s2.name;
}

bool operator>(const Student &s1, const Student &s2)
{
    return s1.name > s2.name;
}

bool operator==(const Student &s1, const Student &s2)
{
    return s1.name == s2.name;
}
//-----------------------------------------------comparefunctions-------------------------------------------------------------------

// compare for sorting Students by GPA
bool compareByGPA(const Student &s1, const Student &s2)
{
    return s1.get_gpa() < s2.get_gpa();
}

// compare for sorting Students by name
bool compareByName(const Student &s1, const Student &s2)
{
    return s1.get_name() > s2.get_name();
}

//-----------------------------------------------insertionsort-------------------------------------------------------------------
template <typename T>
void insertionSort(vector<T> &arr, bool (*compare)(const T &, const T &), int &numComparisons)
{
    for (int i = 1; i < arr.size(); i++)
    {
        T tmp = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            numComparisons++;
            if (compare(arr[j], tmp))
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = tmp;
    }
}

//-----------------------------------------------selectionsort-------------------------------------------------------------------
template <typename T>
void selectionSort(vector<T> &arr, bool (*compare)(const T &, const T &), int &numComparisons)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int least = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            numComparisons++;
            if (compare(arr[least], arr[j]))
            {
                least = j;
            }
        }
        if (least != i)
        {
            swap(arr[i], arr[least]);
        }
    }
}

//-----------------------------------------------Bubblesort-------------------------------------------------------------------
template <typename T>
void bubbleSort(vector<T> &arr, bool (*compare)(const T &, const T &), int &numComparisons)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 1; i < arr.size(); i++)
        {
            numComparisons++;
            if (compare(arr[i - 1], arr[i]))
            {
                swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
    } while (swapped);
}

//-----------------------------------------------shellsort-------------------------------------------------------------------
template <typename T>
void shellSort(vector<T> &arr, bool (*compare)(const T &, const T &), int &numComparisons)
{
    for (int gap = arr.size() / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < arr.size(); i++)
        {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap; j -= gap)
            {
                numComparisons++;
                if (compare(arr[j - gap], temp))
                {
                    arr[j] = arr[j - gap];
                }
                else
                {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}

//-----------------------------------------------mergesort---------------------------------------------------------------------------
template <typename T>
void mergeSort(vector<T> &arr, bool (*compare)(const T &, const T &), int &numComparisons)
{
    auto merge = [&](int l, int m, int r)
    {
        // other ways for filling the temp arrays

        // vector<T> L(arr.begin() + l, arr.begin() + m + 1);
        // vector<T> R(arr.begin() + m + 1, arr.begin() + r + 1);

        // vector<T> L, R;
        // L.insert(L.end(), arr.begin() + l, arr.begin() + m + 1);
        // R.insert(R.end(), arr.begin() + m + 1, arr.begin() + r + 1);

        vector<T> L, R;
        for (int i = l; i <= m; ++i)
        {
            L.push_back(arr[i]);
        }
        for (int i = m + 1; i <= r; ++i)
        {
            R.push_back(arr[i]);
        }

        int left_idx = 0, right_idx = 0, merged_idx = l;
        while (left_idx < L.size() && right_idx < R.size())
        {
            numComparisons++;
            if (compare(R[right_idx], L[left_idx]))
            {
                arr[merged_idx++] = L[left_idx++];
            }
            else
            {
                arr[merged_idx++] = R[right_idx++];
            }
        }

        while (left_idx < L.size())
            arr[merged_idx++] = L[left_idx++];
        while (right_idx < R.size())
            arr[merged_idx++] = R[right_idx++];
    };

    function<void(int, int)> recursiveSort = [&](int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;
            recursiveSort(l, m);
            recursiveSort(m + 1, r);
            merge(l, m, r);
        }
    };

    recursiveSort(0, arr.size() - 1);
}
//-----------------------------------------------quicksort---------------------------------------------------------------------------
template <typename T>
void quickSort(vector<T> &arr, bool (*compare)(const T &, const T &), int &numComparisons)
{
    auto partition = [&](int low, int high)
    {
        T pivot = arr[low];
        int i = low;

        for (int j = low + 1; j <= high; j++)
        {
            numComparisons++;
            if (compare(pivot, arr[j]))
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[low], arr[i]);
        return i;
    };

    function<void(int, int)> recursiveQuickSort = [&](int low, int high)
    {
        if (low < high)
        {
            int pi = partition(low, high);
            recursiveQuickSort(low, pi - 1);
            recursiveQuickSort(pi + 1, high);
        }
    };

    recursiveQuickSort(0, arr.size() - 1);
}
//---------------------------------------------------output----------------------------------------------------------------------------
template <typename T>
void sortAndMeasure(vector<Student> &students, bool (*compare)(const T &, const T &), const string &algorithmName, ofstream &outFile)
{
    int numComparisons = 0;
    auto start = chrono::high_resolution_clock::now();

    if (algorithmName == "Quick Sort")
    {
        quickSort(students, compare, numComparisons);
    }
    else if (algorithmName == "Merge Sort")
    {
        mergeSort(students, compare, numComparisons);
    }
    else if (algorithmName == "Bubble Sort")
    {
        bubbleSort(students, compare, numComparisons);
    }
    else if (algorithmName == "Insertion Sort")
    {
        insertionSort(students, compare, numComparisons);
    }
    else if (algorithmName == "Selection Sort")
    {
        selectionSort(students, compare, numComparisons);
    }
    else if (algorithmName == "Shell Sort")
    {
        shellSort(students, compare, numComparisons);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;

    outFile << "Algorithm: " << algorithmName << "\n";
    outFile << "Running Time: " << elapsed.count() << " milliseconds\n";
    outFile << "Comparisons: " << numComparisons << "\n";
    for (const auto &student : students)
    {
        student.display(outFile);
    }
    outFile << "\n";
}

//---------------------------------------------------main----------------------------------------------------------------------------

int main()
{
    vector<Student> students;
    ifstream file("students.txt");
    ofstream sortedByGPA("SortedByGPA.txt"), sortedByName("SortedByName.txt");
    if (!file)
    {
        cerr << "Could not open the file."<< "\n";
        return 1;
    }

    int numStudents;
    file >> numStudents;
    file.ignore();

    for (int i = 0; i < numStudents; ++i)
    {
        string name;
        string id;
        double gpa;

        getline(file, name);
        getline(file, id);
        file >> gpa;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        students.emplace_back(name, id, gpa);
    }

    file.close();

    vector<string> algorithms = {"Quick Sort", "Merge Sort", "Bubble Sort", "Insertion Sort", "Selection Sort", "Shell Sort"};
    for (const auto &alg : algorithms)
    {
        sortAndMeasure(students, compareByGPA, alg, sortedByGPA);
    }

    for (const auto &alg : algorithms)
    {
        sortAndMeasure(students, compareByName, alg, sortedByName);
    }

    sortedByGPA.close();
    sortedByName.close();

    return 0;
}
