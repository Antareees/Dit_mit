#include <bits/stdc++.h>

using namespace std;
vector<string> spisok({"MUSIC", "BOY", "GIRL", "EGG", "PEN", "PAPER", "ROOM", "SCHOOL", "COUNTRY", "COLOR", "CAR", "BROTHER", "BOOK"}); // ������ ���� 
int main() {
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    string alf="ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    int count = 7; // ���������� �����
    bool lastcor=true; // ����, ������� �������� �� �������������� �����
    string word = spisok[rand() % spisok.size()]; // ��������� ����� �� ������
    string guessed(word.size(), '_'); // ���������� 
    while (count > 0) {
        system("cls"); // ������� �������
        cout << alf << endl; 
        cout << "�������� �����: " <<  count << endl;
        cout << guessed << endl;
        if (lastcor) {
            cout << "������� �����: ";
        }
        else 
            cout << "������! ������� ���������� �����: ";   
        string bukva;
        cin >> bukva;
        for (int i=0; i<bukva.size();i++){
            bukva[i] = toupper(bukva[i]); // ��������� ��������
        }
        if (bukva.size() == 1){ 
            int poz = find (alf.begin(), alf.end(), bukva[0]) - alf.begin(); //����� ������� ����� � �������� 
            if (poz == 26) {
                lastcor = false;
                continue;
            }
            alf[poz] = '_'; //������ ���� ����� � �������� �� �������
            lastcor = true;
            if (find (word.begin(), word.end(), bukva[0]) == word.end()){
                --count; // ���� ����� ��� � ����� �� - ��� 
                continue;
            }
            for (int i=0; i<word.size(); i++){ // �������� ������ ����� 
                if (bukva[0] == word[i]) {
                    guessed[i] = bukva[0];
                } 
            }
            if (find (guessed.begin(), guessed.end(), '_') == guessed.end()){ //���� � ���������� ����� �� �������� _ �� ����� ������� 
                system("cls");
                cout << "���������� �����: " << guessed << endl;
                cout << "�� ��������!"; 
                break; 
            }
        }
        if (bukva.size() != 1) { // ���� �������� ����� �������  
            if (bukva == word) {
            }
                guessed = bukva;
            else {
                --count;
            }
        }
        if (find (guessed.begin(), guessed.end(), '_') == guessed.end()){
            system("cls");
            cout << "���������� �����: " << guessed << endl;
            cout << "�� ��������!";
            break;
        }
        } 
    if (count == 0) {
            system("cls");
            cout << "�� ���������( ";
            cout << "���������� �����: "<< word << endl;
    }
}
