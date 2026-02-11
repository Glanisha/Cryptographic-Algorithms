#include <bits/stdc++.h> 
using namespace std; 

int modInverse(int a){
    for(int x = 1 ; x < 26; x++){
        if((a*x)%26==1) return x; 
    }
    return -1;
}

string encryption(string text, int a, int b){
    // formula is (ax+b)%26
    string res = ""; 
    
    for(char c: text){
        if(isupper(c)){
            int x = c - 'A'; 
            int ans = (a*x+b)%26; 
            res = res + char(ans+'A'); 
        }else{
            res = res + c; 
        }
    } 
    return res ; 
}

string decrypt(string text, int a, int b){
    string res = ""; 
    int inv = modInverse(a);
    for(char c : text){
        if(isupper(c)){
            int x = c - 'A'; 
            int P = (inv * (x-b+26))%26; 
            res = res + char(P+ 'A'); 
        }else res = res + c ; 
    }
    return res; 
}



int main(){
  
    string text = "TODAY THURSDAY"; 
    
    string e = encryption(text, 3, 7); 
    cout << e << endl; 
    
    string d = decrypt(e, 3, 7); 
    cout << d << endl ;
   
    return 0 ;
}


