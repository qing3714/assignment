#include <iostream>
using namespace std;

void choice(int type, int n);

void printIdentity(int n);
void printALPD(int n);
void printLower(int n);

int main()
{
    cout << "1 Identity | 2 ALPD | 3 Lower | -1 Exit" << endl;
    cout << "Choice:" << endl;

    int type = 0, n = 0;
    while (cin >> type && type != -1)
    {
        cin >> n;
        choice(type, n);
    }

    return 0;
}

void printIdentity(int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (i == j)
            {
                cout << 1;
                if (j != n - 1)cout << " ";
            }
            else
            {
                cout << 0;
                if (j != n - 1)cout << " ";
            }
        }
        cout << endl;
    }
}
void printALPD(int n)
{
    int cnt = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (i > j)
            {
                cout << 0;
                if (j != n - 1)cout << " ";
            }
            else
            {
                cnt++;
                cout << cnt;
                if (j != n - 1)cout << " ";
            }
        }
        cout << endl;
    }
}

void printLower(int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (i >= j)
            {
                cout << 1;
                if (j != n - 1)cout << " ";
            }
            else
            {
                cout << 0;
                if (j != n - 1)cout << " ";
            }
        }
        cout << endl;
    }
}

void choice(int type, int n)
{
    switch (type)
    {
    case 1:cout << "Identity:" << endl;printIdentity(n);break;
    case 2:cout << "ALPD:" << endl;printALPD(n);break;
    case 3:cout << "Lower:" << endl;printLower(n);break;
    }
}
