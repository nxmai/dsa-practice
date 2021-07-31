#include<bits/stdc++.h>
using namespace std;

string logic(int num, char first, char mid, char last){
    string s="";
    if(num <= 3){
        for(int i=1; i<=num; i++)
            s+= first;
    } else if(num == 4){
        s=first;
        s+=mid;
    } else if(num <=8){
        s=mid;
        for(int i=6;i<=num;i++){
            s+=first;
        }
    } else{
        s=first;
        s+=last;
    }
    return s;
}
    
string format(int num){
    unordered_map<int, char> mp;
    mp[1] = 'I'; mp[5] = 'V'; mp[10] = 'X'; mp[50] = 'L'; mp[100] = 'C'; mp[500] = 'D'; mp[1000] = 'M';
    
    int cnt = 0, tmp = num;
    while(tmp != 0){
        cnt++;
        tmp/=10;
    }
    
    if(cnt == 1){
        return logic(num/(pow(10, cnt-1)), 'I', 'V', 'X');
    } else if(cnt==2){
        return logic(num/(pow(10, cnt-1)), 'X', 'L', 'C');
    } else if(cnt==3){
        return logic(num/(pow(10, cnt-1)), 'C', 'D', 'M');
    } else
        return logic(num/(pow(10, cnt-1)), 'M', 'o', 'o');
    
}

string intToRoman(int num) {
    string res ="";
    int tmp;
    int i=0;
    while(num!=0){
        res = format((num%10)*(pow(10, i++))) + res;
        num/=10;
    }
    return res;
}