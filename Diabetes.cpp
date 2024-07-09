#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;

class Diabetes {
private:
    string name;
    float age;
    int weight;
    float height;
    char sex;
    char symptoms[20];

public:
    void welcomeScreen();
    void getValue();
    void getLevel1Symptoms();
    void getLevel2Symptoms();
    void getLevel3Symptoms();
    int analyzeSymptoms(int level);
    char displayMessage(int level, int result);
};

void clearScreen() {
   //cout << "\033[2J\033[1;1H";
   system("clear");
}

void Diabetes::welcomeScreen() {
    clearScreen();
    cout << "_____________________________________________\n";
    cout << "             W E L C O M E                   \n";
    cout << "               IIT ROPAR                     \n";
    cout << "       DIABETES DIAGNOSIS SOFTWARE           \n";
    cout << "        PRESS ANY KEY TO CONTINUE            \n";
    cout << "_____________________________________________\n";
    cin.get();
}

void Diabetes::getValue() {
    clearScreen();
    cout << "PERSONAL INFORMATION\n";
    cout << "NAME: ";
    cin >> name;
    cout << "AGE: ";
    cin >> age;
    cout << "WEIGHT: ";
    cin >> weight;
    cout << "HEIGHT: ";
    cin >> height;
    cout << "SEX (M/F): ";
    cin >> sex;
}

void diagnosis() {
    clearScreen();
    cout << "_________DIAGNOSIS WINDOW______________\n";
    cout << "Let's have a look at symptoms...\n";
    cout << "Please enter the form on the next page.\n";
    cout << "___________PRESS ANY KEY_______________\n";
    cin.get();
}

void Diabetes::getLevel1Symptoms() {

    clearScreen();
    cout << "*** MEDICAL DIAGNOSIS FORM ***\n";
    cout << "APPETITE (H/HIGH, L/LOW, N/NORMAL): ";
    cin >> symptoms[0];
    symptoms[0] = toupper(symptoms[0]);

    cout << "FREQUENCY OF THIRST (H/HIGH, L/LOW, N/NORMAL): ";
    cin >> symptoms[1];
    symptoms[1] = toupper(symptoms[1]);

    cout << "FREQUENCY OF URINATION (H/HIGH, L/LOW, N/NORMAL): ";
    cin >> symptoms[2];
    symptoms[2] = toupper(symptoms[2]);

    cout << "VISION (I/IMPAIRMENT, N/NORMAL): ";
    cin >> symptoms[3];
    symptoms[3] = toupper(symptoms[3]);

    cout << "URINE SUGAR (P/PASSIVE, A/ACTIVE): ";
    cin >> symptoms[4];
    symptoms[4] = toupper(symptoms[4]);

    cout << "KETONUREA (P/PASSIVE, A/ACTIVE): ";
    cin >> symptoms[5];
    symptoms[5] = toupper(symptoms[5]);

    cout << "FASTING BLOOD SUGAR (H/HIGH, L/LOW, N/NORMAL): ";
    cin >> symptoms[6];
    symptoms[6] = toupper(symptoms[6]);

    cout << "RANDOM BLOOD SUGAR (RBS) (H/HIGH, L/LOW, N/NORMAL): ";
    cin >> symptoms[7];
    symptoms[7] = toupper(symptoms[7]);

    cout << "FAMILY HISTORY OF DIABETES (P/PASSIVE, A/ACTIVE): ";
    cin >> symptoms[8];
    symptoms[8] = toupper(symptoms[8]);

    cout << "ORAL GLUCOSE TOLERANCE TEST (OGTT) (D/DIABETIC, N/NON-DIABETIC): ";
    cin >> symptoms[9];
    symptoms[9] = toupper(symptoms[9]);
}

int Diabetes::analyzeSymptoms(int level) {
    int count = 0;
    int result = 0;

    switch (level) {
        case 1:
            if (symptoms[9] == 'D')
                result = -1;
            else if (symptoms[5] == 'P' && symptoms[6] == 'P' && symptoms[7] == 'H')
                result = -1;
            else {
                for (int i = 0; i < 10; ++i) {
                    if (symptoms[i] == 'H' || symptoms[i] == 'P' || symptoms[i] == 'D' || symptoms[i] == 'I')
                        count++;
                }
                if (count > 5)
                    result = -1;
            }
            break;
        case 2:
            if ((symptoms[0] == 'P') || (symptoms[1] == 'P') || (symptoms[2] == 'P') || 
                (symptoms[3] == 'H') || (symptoms[4] == 'P') || (symptoms[5] == 'P') || 
                (symptoms[6] == 'P'))
                result = -1;
            else
                result = 0;
            break;

        case 3:
            if ((symptoms[0] == 'Y' && symptoms[1] == 'N' && symptoms[2] == 'W' && 
                symptoms[3] == 'P' && symptoms[4] == 'P') ||
                (symptoms[0] == 'Y' && symptoms[1] == 'B' && symptoms[2] == 'W' && 
                symptoms[3] == 'P' && symptoms[4] == 'P') ||
                (symptoms[0] == 'Y' && symptoms[1] == 'N' && symptoms[2] == 'M' && 
                symptoms[3] == 'P' && symptoms[4] == 'P') ||
                (symptoms[0] == 'Y' && symptoms[1] == 'N' && symptoms[2] == 'Y' && 
                symptoms[3] == 'P' && symptoms[4] == 'P'))
                result = 0;
            else
                result = -1;
            break;
        default:
            break;
    }
    return result;
}

char Diabetes::displayMessage(int level, int result) {
    char choice;
    clearScreen();

    switch (level) {
        case 1:
            if (result == 0) {
                cout << "THE PERSON IS NOT DIABETIC\n";
                
                exit(0);
            } else {
                cout << "THE PERSON IS DIABETIC\n";
                cout << "PROCEED (Y/N)? ";
                cin >> choice;
            }
            break;
        case 2:
            if (result == 0) {
                cout << "IT IS PRIMARY DIABETES.\n";
                cout << "PROCEED (Y/N)? ";
                cin >> choice;
            } else {
                cout << "IT IS SECONDARY DIABETES\n";
                
                exit(0);
            }
            break;
        case 3:
            if (result == 0) {
                cout << "TYPE-1 DIABETES : IT IS INSULIN DEPENDENT DIABETES\n";
                cout << "PRESS ANY KEY TO QUIT.\n";
                cin.get();
                exit(0);
            } else {
                cout << "TYPE_2 DIABETES : IT IS NON INSULIN DEPENDENT DIABETES\n";
                cout << "PRESS ANY KEY TO QUIT.\n";
                cin.get();
                exit(0);
            }
            break;
        default:
            break;
    }

    return choice;
}

void Diabetes::getLevel2Symptoms() {
    clearScreen();
    cout << "PANCREATITIS (P/A): ";
    cin >> symptoms[10];
    symptoms[10] = toupper(symptoms[10]);

    cout << "CARCINOMA (P/A): ";
    cin >> symptoms[11];
    symptoms[11] = toupper(symptoms[11]);

    cout << "CIRRHOSIS (P/A): ";
    cin >> symptoms[12];
    symptoms[12] = toupper(symptoms[12]);

    cout << "HEMATOCRIT(HCTS) (H/L/N): ";
    cin >> symptoms[13];
    symptoms[13] = toupper(symptoms[13]);

    cout << "ARTERIOSCLEROSIS (P/A): ";
    cin >> symptoms[14];
    symptoms[14] = toupper(symptoms[14]);

    cout << "BLOOD UREA (H/L/N): ";
    cin >> symptoms[15];
    symptoms[15] = toupper(symptoms[15]);
}

void Diabetes::getLevel3Symptoms() {
    clearScreen();
    cout << "HYPERLIPIDAEMIA (Y/N): ";
    cin >> symptoms[0];
    symptoms[0] = toupper(symptoms[0]);

    cout << "CETONURIA (B/N): ";
    cin >> symptoms[1];
    symptoms[1] = toupper(symptoms[1]);

    cout << "BLOOD SUGAR MORE THAN 200 mg/dl (Y/N): ";
    cin >> symptoms[2];
    symptoms[2] = toupper(symptoms[2]);

    cout << "FASTING BLOOD SUGAR MORE THAN 120 mg/dl (Y/N): ";
    cin >> symptoms[3];
    symptoms[3] = toupper(symptoms[3]);

    cout << "PARENTS DIABETIC (Y/N): ";
    cin >> symptoms[4];
    symptoms[4] = toupper(symptoms[4]);
}

int main() {
    Diabetes d;
    d.welcomeScreen();
    diagnosis();
    d.getValue();
    d.getLevel1Symptoms();

    int result = d.analyzeSymptoms(1);
    char choice = d.displayMessage(1, result);

    if (choice == 'Y' || choice == 'y') {
        d.getLevel2Symptoms();
        result = d.analyzeSymptoms(2);
        choice = d.displayMessage(2, result);

        if (choice == 'Y' || choice == 'y') {
            d.getLevel3Symptoms();
            result = d.analyzeSymptoms(3);
            d.displayMessage(3, result);
        }
    }

    return 0;
}
