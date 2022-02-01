#include<bits/stdc++.h>
using namespace std;
map<string,string>word_meaning;
map<string,vector<string> >similar_meaning;
void suggestion(string s)
{
    vector<string>v;
    for(auto i:word_meaning)
    {
        string ss = i.first;
        int n1 = s.length(),n2 = ss.length();
        if(n1>=n2)
        {
            int cnt=0;
            for(int j=0;j<n2;++j)
                if(s[j]==ss[j])cnt++;
                else break;
            if(cnt>=2)v.push_back(ss);
        }
    }
    if(v.size()>=2)
    {
        cout<<"Did you mean : ";
        for(auto i:v)
            cout<<i<<" ";
        cout<<"?"<<endl;
    }
}
void search_word()
{
    cout<<"<--------Search--------->"<<endl;
    string s,s1;
    cout<<"Enter the word to be searched : ";cin>>s;
    if(word_meaning.find(s) == word_meaning.end()){
        cout<<"This word does not exists in the dictionary."<<endl;
        suggestion(s);
    }
    else
    {
        cout<<"Meaning is : "<< word_meaning[s]<<endl;
    }
}
void same_meaning()
{
    cout<<"<--------Similar--------->"<<endl;
    string s,s1="-";
    cout<<"Enter the word to be checked : ";cin>>s;
    if(word_meaning.find(s) == word_meaning.end()){
        cout<<"This word does not exists in the dictionary."<<endl;
        suggestion(s);
    }
    else{
        s1 = word_meaning[s];
        //cout<<s1<<endl;
        cout<<"Similar words are : ";
        for(int i=0;i<similar_meaning[s1].size();++i)
            cout<<similar_meaning[s1][i]<<" ";
        cout<<endl;
    }
    getchar();
}
void delete_word()
{
    cout<<"<--------Delete--------->"<<endl;
    string s,s1;
    cout<<"Enter the word to be deleted : ";cin>>s;
    if(word_meaning.find(s) == word_meaning.end()){
        cout<<"This word does not exists in the dictionary."<<endl;
        suggestion(s);
    }
    else
    {
        s1 = word_meaning[s];
        for(int i=0;i<similar_meaning[s1].size();++i)
        {
            if(similar_meaning[s1][i] == s){
                similar_meaning[s1].erase(similar_meaning[s1].begin()+i);
                break;
            }
        }
        word_meaning.erase(s);
        cout<<"Word Deleted!"<<endl;
    }

}
void add_word()
{
    cout<<"<--------Add--------->"<<endl;
    string s,s1,c="-";
    cout<<"Enter word : ";cin>>s;getchar();
    cout<<"Enter meaning : ";getline(cin,s1);
    if(word_meaning.find(s) != word_meaning.end())
        cout<<"This word already exists in the dictionary. Please enter a new word."<<endl;
    else{
        //s1 = c+s1;
        word_meaning[s] = s1;
        similar_meaning[s1].push_back(s);
        cout<<"New word added!"<<endl;
    }

}
void input()
{
    cout<<"###########-Dictionary-##############"<<endl;
    ifstream fin("input.txt");
    string s;
    if(fin.is_open())
    {
        while(getline(fin,s))
        {
            string s1="",s2="";int mark=0;
            for(int i=0;i<s.length();++i)
            {
                if(s[i]=='-')
                    mark=1;
                else if(!mark)
                    s1+=s[i];
                else if(mark)
                    s2+=s[i];
            }
                word_meaning[s1]=s2;
                similar_meaning[s2].push_back(s1);
            //fin.ignore();
        }
    }

    fin.close();
    /*for(auto i=similar_meaning.begin();i!=similar_meaning.end();++i){
        cout<<i->first<<" : ";
        for(int j=0;j<similar_meaning[i->first].size();++j)
            cout<<similar_meaning[i->first][j]<<" ";
        cout<<endl;
    }*/
}
void exit()
{
    ofstream fout("input.txt");
    for(auto i:word_meaning)
        fout<<i.first<<"-"<<i.second<<endl;
    fout.close();
}
int main()
{
    input();
    //getline(cin,s);
    while(1)
    {
        int option;
        cout<<endl;
        cout<<"1. Add a Word in the dictionary."<<endl;
        cout<<"2. Delete a Word from the dictionary."<<endl;
        cout<<"3. Search a Word in the dictionary."<<endl;
        cout<<"4. Look for similar word."<<endl;
        cout<<"5. Exit."<<endl;
        cout<<endl<<"Enter an option: ";
        cin>>option;
        switch(option)
        {
            case 1:
                add_word();
                break;
            case 2:
                delete_word();
                break;
            case 3:
                search_word();
                break;
            case 4:
                same_meaning();
                break;
            case 5:
                exit();
                return 0;
        }
        //getchar();
    }
}
