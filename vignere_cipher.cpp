#include<bits/stdc++.h>
using namespace std;

string equal_key_length(string s, string key)
{
	int x=s.size();
	for(int i=0 ; ; i++)
	{
		if(x==i)
			i=0;
		if(key.length()==s.length())
			break;
		key.push_back(key[i]);
	}
	return key;
}

string cipher_text(string new_key,string s)
{
	string c;
	for(int i=0;i<s.length();i++)
	{
		char x=(s[i]+new_key[i])%26;
		
		x+='A';
		
		c.push_back(x);
	}
	return c;
}

string decrypt(string c,string k)
{
	string d;
	for(int i=0;i<c.length();i++)
	{
		char x=(c[i]-k[i]+26)%26;
		
		x+='A';
		
		d.push_back(x);
	}
	return d;
}

int main()
{
	string s="THAPARUNIVERSITY";
	string key="AKSHAT";
	
	string new_key=equal_key_length(s,key);
	
	string cipher=cipher_text(new_key,s);
	
	cout<<"Encrypted text: "<<cipher<<endl;
	
	string decrypted=decrypt(cipher,new_key);
	
	cout<<"Original text: "<<decrypted;
}
