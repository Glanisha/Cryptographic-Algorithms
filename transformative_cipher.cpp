#include <bits/stdc++.h> 
using namespace std; 

string transencrypt(string s){
    int len = s.length(); 
    int n = ceil(sqrt(len)); 

    vector<vector<char>> matrix(n, vector<char>(n, 'X'));

    int k = 0; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(k < len)
                matrix[i][j] = s[k++];
        }
    }

    vector<vector<char>> trans(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            trans[i][j] = matrix[j][i];
        }
    }

    string res = "";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res += trans[i][j];
        }
    }

    return res;
}

int main(){
  
    string text = "TODAY THURSDAY"; 
    
    
    string det = transencrypt(text);
    cout << det << endl;

    string et = transencrypt(det);
    cout << et << endl;
    
    return 0 ;
}



