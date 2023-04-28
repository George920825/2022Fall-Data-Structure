#include <iostream>
#include <string> 
using namespace std;

string createstring(int n){
        if(n==1)
            return "0";
        else{
            string s1=createstring(n-1);//get string(n-1)
			string s;
            s=s1+"1";
            for(int i=s1.size()-1;i>=0;i--){//get reverse(invert(string(n-1)))
                s+=(s1[i]=='1')?"0":"1";
            }
            return s;
        }
    }
char findKthBit(int n, int k) {
    string s=createstring(n);
    cout<<s<<endl;
    return s[k-1];
}

int main()
{
	int n,k;
	cin>>n>>k;
	char c=findKthBit(n, k);
	cout<<c;
//	for(int i=1;i<=5;i++)
//		cout<<i<<" : "<<createstring(i)<<endl;

}

