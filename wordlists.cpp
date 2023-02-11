#include<bits/stdc++.h>
using namespace std;

void addTofile(string str){
    ofstream file;

    file.open("file.txt", ios::app);
    file<<str<<endl;
    file.close();
    return;
}

void permute(string s, string answer)
{
    if (s.length() == 0) {
        addTofile(answer);
        return;
    }
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        string left_substr = s.substr(0, i);
        string right_substr = s.substr(i + 1);
        string rest = left_substr + right_substr;
        permute(rest, answer + ch);
    }
}

void makePassword(int length, string result, string arr, int n){
    
    if(length == 0){

        bool flag = false;
        for(int i = 0;i<result.length() - 1;i++){
            if(result[i] != result[i + 1]){
                permute(result, "");
                flag = true;
                break;
            }
        }

        if(!flag){
            addTofile(result);
        }
        return;
    }

    if(n == 0){
        return;
    }
    
    string temp = result;
    temp.push_back(arr[n - 1]);
    makePassword(length - 1, temp, arr, n);
    makePassword(length, result, arr, n - 1);
    return;
}

int main(){
    int length = 3;
    string result = "";
    // char arr[] = {
    //     'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
    //     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    //     '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        //  '~', '`', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '[', '{', ']', '}', '|', "'", '"', ':', ';', '<', ',', '>', '.', '?', '/', '\\'};

        // string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890~`!@#$%^&*()_+-={[}]:;'<,>.?/";
    string str = "adee12@#";


    int n = 8;
    // for(int i = 4;i<=30;i++){
    //     makePassword(i, result, str, n);
    // }
    makePassword(length, result, str, n);
    return 0;
}