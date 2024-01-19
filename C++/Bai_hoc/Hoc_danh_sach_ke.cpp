#include <bits/stdc++.h>
using namespace std;

// Ma trận kề
// Danh sách cạnh
// Danh sách kề

vector<int> adj[100001];
vector<pair<int, int>> edge;

void danh_sach_canh_sang_ma_tran_ke()
{
    
    
    cout << "Nhap do thi danh sach canh: " << endl;
    int n, m;
    cin >> n >> m;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = 0;
        }
    }
    int x, y;
    while (m--)
    {
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    cout << "Ma tran ke: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
}

void danh_sach_canh_sang_danh_sach_ke()
{
    // Chuyen danh sach canh sang danh sach ke
    
    cout << "Nhap do thi danh sach canh: " << endl;
    int n, m;
    cin >> n >> m;
    int x, y;
    while (m--)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"Danh sach ke: "<<endl;
    for (int i=1;i<=n;i++)
    {
        cout<<i<<" : "<<"{"<<adj[i][0];
        for (int j=1;j<adj[i].size();j++)
        {
            cout<<"; "<<adj[i][j];
        }
        cout<<"}"<<endl;
    }
    
}

void ma_tran_ke_sang_danh_sach_canh()
{
    // Ma tran ke sang danh sach canh

    
    cout << "Nhap do thi ma tran ke: " << endl;
    int n;
    cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] && i < j)
            {
                edge.push_back({i, j});
            }
        }
    }
    cout << "Danh sach canh: " << endl;
    for (auto it : edge)
    {
        cout << it.first << " " << it.second << endl;
    }
    
}

void ma_tran_ke_sang_danh_sach_ke()
{
     // Ma tran ke sang danh sach ke

    
    cout << "Nhap do thi ma tran ke: " << endl;
    int n;
    cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j])
                adj[i].push_back(j);
        }
    }

    cout << "Danh sach ke: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : "
             << "{" << adj[i][0];
        for (int j = 1; j < adj[i].size(); j++)
        {
            cout << "; " << adj[i][j];
        }
        cout << "}" << endl;
    }
    
}

void danh_sach_ke_sang_ma_tran_ke()
{
    // Danh sach ke sang ma tran ke

    
    cout<<"Nhap do thi danh sach ke: "<<endl;
    int n;
    cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = 0;
        }
    }
    string s;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        string num;
        stringstream ss(s);
        while (ss >> num)
        {
            a[i][stoi(num)] = 1;
        }
    }
    cout<<"Ma tran ke: "<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
}

void danh_sach_ke_sang_danh_sach_canh()
{
    // Danh sach ke sang danh sach canh

    cout << "Nhap do thi danh sach ke: " << endl;
    int n;
    cin >> n;
    string s;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        string num;
        stringstream ss(s);
        while (ss >> num)
        {
            if (stoi(num)>i)
            {
                edge.push_back({i,stoi(num)});
            }
        }
    }
    cout << "Danh sach canh: " << endl;
    for (auto it : edge)
    {
        cout << it.first << " " << it.second << endl;
    }
}

int main()
{
    danh_sach_canh_sang_danh_sach_ke();    
}