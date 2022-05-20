#include<bits/stdc++.h>
using namespace std;

string encrypt(string p, int k)
{
	string s;
	for(int i=0;i<p.length();i++)
	{
		if(isupper(p[i]))
			s += char(int(p[i]+k-65)%26 +65);
			
		else
			s+= char(int(p[i]+k-97)%26 +97);
	}
	return s;
}

string decrypt(string c,int k)
{
	for(int i=0;i<c.length();i++)
	{
		char ch=c[i];
		if(isupper(c[i])){
			ch=ch-k;
			if(ch<'A'){
				ch=ch+'Z'-'A'+1;
			}
			c[i]=ch;
		}
		else{
			ch=ch-k;
			if(ch<'a'){
				ch=ch+'z'-'a'+1;
			}
			c[i]=ch;
		}
	}
	return c;
}

int main()
{
	string p="ATTACKatONCE";
	int k=4;
	string encrypted=encrypt(p,k);
	cout<<encrypted<<endl;
	
	string decrypted=decrypt(encrypted,k);
	cout<<decrypted;
}
