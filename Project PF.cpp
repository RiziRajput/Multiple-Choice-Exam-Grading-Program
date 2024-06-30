#include <iostream>
#include <string>
using namespace std;

const int NUM_QUESTIONS = 5;
const int NUM_STUDENTS = 5;

void initializeQuestions(string questions[], string choices[][4], char correctAnswers[])
{
    cout << "Enter the questions and choices: \n";
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        cout << "Enter Question " << i + 1 << " (end with '?'): ";
        getline(cin, questions[i]);
        for (int j = 0; j < 4; j++)
        {
            cout << "Enter Choice " << j + 1 << " (end with '.'): ";
            getline(cin, choices[i][j]);
        }
        while (true)
        {
            cout << "Enter correct answer (a, b, c, or d): ";
            cin >> correctAnswers[i];
            cin.ignore();
            correctAnswers[i] = tolower(correctAnswers[i]);
            if (correctAnswers[i] >= 'a' && correctAnswers[i] <= 'd')
                break;
            else
                cout << "Invalid choice. Please enter a, b, c, or d.\n";
        }
    }
}

void takeQuiz(int studentIDs[], char studentAnswers[][NUM_QUESTIONS], string questions[], string choices[][4])
{
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        cout << "Enter Student ID for student " << i + 1 << ": ";
        cin >> studentIDs[i];
        cin.ignore();
        for (int j = 0; j < NUM_QUESTIONS; j++)
        {
            cout << questions[j] << "\n";
            for (int k = 0; k < 4; k++)
            {
                cout << char('a' + k) << ") " << choices[j][k] << "\n";
            }
            while (true)
            {
                cout << "Your answer: ";
                cin >> studentAnswers[i][j];
                cin.ignore();
                studentAnswers[i][j] = tolower(studentAnswers[i][j]);
                if (studentAnswers[i][j] >= 'a' && studentAnswers[i][j] <= 'd')
                    break;
                else
                    cout << "Invalid choice. Please enter a, b, c, or d.\n";
            }
        }
    }
}

void displayResults(int studentIDs[], char studentAnswers[][NUM_QUESTIONS], char correctAnswers[])
{
    cout << "\nStudents Answers Are As Follows:\n";
    cout << "Student ID  Q1  Q2  Q3  Q4  Q5\n";
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        cout << studentIDs[i] << "       ";
        for (int j = 0; j < NUM_QUESTIONS; j++)
        {
            cout << studentAnswers[i][j] << "   ";
        }
        cout << "\n";
    }

    cout << "\nExam Report:\n";
    cout << "Answer key\n";
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        cout << correctAnswers[i] << " ";
    }
    cout << "\n";

    int scores[NUM_STUDENTS] = {0};
    int missedQuestions[NUM_QUESTIONS] = {0};

    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        int correctCount = 0;
        for (int j = 0; j < NUM_QUESTIONS; j++)
        {
            if (studentAnswers[i][j] == correctAnswers[j])
            {
                correctCount++;
            }
            else
            {
                missedQuestions[j]++;
            }
        }
        scores[i] = (correctCount * 100) / NUM_QUESTIONS;
    }

    cout << "\nStudent Scores:\n";
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        cout << "ID " << studentIDs[i] << " Score(%) " << scores[i] << "\n";
    }

    cout << "\nQuestions Missed by Students:\n";
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        cout << "Question " << i + 1 << " missed by " << missedQuestions[i] << " students\n";
    }
}

int main()
{
    string questions[NUM_QUESTIONS];
    string choices[NUM_QUESTIONS][4];
    char correctAnswers[NUM_QUESTIONS];

    initializeQuestions(questions, choices, correctAnswers);

    int studentIDs[NUM_STUDENTS];
    char studentAnswers[NUM_STUDENTS][NUM_QUESTIONS];

    takeQuiz(studentIDs, studentAnswers, questions, choices);

    displayResults(studentIDs, studentAnswers, correctAnswers);

    return 0;
}
