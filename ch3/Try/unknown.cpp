#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

string createString(int i){
    if(i == 1)
        return "0";
    else{
        string s1 = createString(i-1);
        string s = s1 + "1";
        //printf("%d\n", s1.length());
        for(int j = s1.length()-1; j >=0 ; j--)//same as s1.size()-1
            s += (s1[j] == '1')?"0":"1";
        return s;
    }
}

char findTheBit(int n, int k){
    string s = createString(n);
    //printf("%s", s);
    //cout<<s<<endl;
    for(int i = 0; i < s.size(); i++)
        printf("%c", s[i]);
    printf("\n");
    return s[k-1];
}

int main(){
    int n,k;
    scanf("%d%d", &n, &k);
	/*cin>>n>>k;
	//char c=findTheBit(n, k);
	cout<<c;*/
    printf("%c", findTheBit(n, k));
    /*int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    printf("%d",findTheBit(n, k));*/
}