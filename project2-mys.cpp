//course(5)
//Project(2) _ My Solution:

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5 };
char AllOperations[4]{ '+', '-', '*', '/' };

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int ReadNumberOfQuestions() {
    short Number;
    do {
        cout << "How many questions do you want to answer ? ";
        cin >> Number;
    } while (Number <= 0); 
    return Number;
}

enQuestionLevel QuestionLevel() {
    short Choice;
    do {
        cout << "Enter Questions Level [1] Easy , [2] Med , [3] Hard , [4] Mix ? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 4);
    return (enQuestionLevel)Choice;
}

enOperationType OperationType() {
    short Choice;
    do {
        cout << "Enter Operation Type [1] Add , [2] Sub , [3] Mul , [4] Div , [5] Mix ? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 5);
    return (enOperationType)Choice;
}

int forLevel(enQuestionLevel ChoiceLevel) 
{
    switch (ChoiceLevel)
    {
    case enQuestionLevel::Easy:
        return RandomNumber(1, 10);
    case enQuestionLevel::Med:
        return RandomNumber(10, 50);
    case enQuestionLevel::Hard:
        return RandomNumber(50, 100);
    case enQuestionLevel::mix:
        return RandomNumber(1, 100);
    }
    return RandomNumber(1, 10);
}

char forOperation(enOperationType ChoiceOperation) {
    if (ChoiceOperation == enOperationType::Add)
        return AllOperations[0];
    else if (ChoiceOperation == enOperationType::Sub)
        return AllOperations[1];
    else if (ChoiceOperation == enOperationType::Mul)
        return AllOperations[2];
    else if (ChoiceOperation == enOperationType::Div)
        return AllOperations[3];
    else
        return AllOperations[RandomNumber(0, 3)]; 
}

int TrueCalculate(char Op, int Num1, int Num2) {
    if (Op == '+')
        return Num1 + Num2;
    else if (Op == '-')
        return Num1 - Num2; 
    else if (Op == '*')
        return Num1 * Num2;
    else
        return Num1 / Num2;
}

void ScreenColor(int CorrectAnswer, int UserAnswer) {
    if (CorrectAnswer == UserAnswer) {
        system("color 2F");
    }
    else {
        system("color 4F");
    }
}

void CompareAnswers(int CorrectAnswer, int UserAnswer) {
    if (CorrectAnswer == UserAnswer) {
        cout << "Your answer is correct :-)" << endl << endl;
    }
    else {
        cout << "Your answer is not correct :-(" << endl;
        cout << "The correct answer : " << CorrectAnswer << endl << endl;
    }
}

int Quiz1(int Num1, int Num2, char Op) {
    int UserAnswer;
    cout << Num1 << endl;
    cout << Num2 << "  " << Op << endl;
    cout << "__" << endl;
    cin >> UserAnswer;
    return UserAnswer;
}

void PrintQuizes(int Number) {
    enQuestionLevel level = QuestionLevel();
    enOperationType operation = OperationType();

    for (int i = 1; i <= Number; i++) {
        cout << "\nQuestion [" << i << "/" << Number << "] " << endl;

        int Num1 = forLevel(level);
        int Num2 = forLevel(level);
        char Op = forOperation(operation);

        int UserAnswer = Quiz1(Num1, Num2, Op);
        int Correct = TrueCalculate(Op, Num1, Num2);

        ScreenColor(Correct, UserAnswer);
        CompareAnswers(Correct, UserAnswer);
    }
}

int main() {
    srand((unsigned)time(NULL));
    int Number = ReadNumberOfQuestions();
    PrintQuizes(Number);
    return 0;
}