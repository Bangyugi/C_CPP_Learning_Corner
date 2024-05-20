#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

void bubbleSort(vector<int> &score, vector<string> &name, int numberOfStudent)
{
    for (int i = 0; i < numberOfStudent - 1; i++)
    {
        for (int j = i + 1; j < numberOfStudent; j++)
        {
            if (score[i] < score[j])
            {
                swap(name[i], name[j]);
                swap(score[i], score[j]);
            }
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);

    vector<int> score;
    vector<string> name;
    int numberOfStudent;
    cout << "Enter number of student in class: ";
    cin >> numberOfStudent;
    for (int i = 0; i < numberOfStudent; i++)
    {
        string n;
        int s;
        cout << "Enter name: ";
        cin >> n;
        cout << "Enter score: ";
        cin >> s;
        name.push_back(n);
        score.push_back(s);
    }
    bubbleSort(score, name, numberOfStudent);
    for (int i = 0; i < numberOfStudent; i++)
    {
        cout << name[i] << " : " << score[i] << endl;
    }

    return 0;
}