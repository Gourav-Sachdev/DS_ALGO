#include<bits/stdc++.h>
using namespace std;



class Node{

public:
 char data;
 unordered_map<char,Node*>children;
 bool terminal;
     

      // constructor
      Node(char d)          // whwnver creating new Node
      {
          data=d;
          terminal=false;
      }
};

class Trie
{
      
       Node* root;
       int cnt;

      public:

       Trie()
       {
            root=new Node('\0');
            cnt=0;
       } 


       void insert(string s)
       {
           Node* temp=root;
           for(int i=0;i<s.length();i++)
           {
                  char ch=s[i];
                  if(temp->children.count(ch))
                  {
                       temp=temp->children[ch];
                  }
                  else{
                      // suppose i reach end-1 character of leet which is e now i want to insert 
                      // t at end but now i am at (e) so creat new node usme t daalo and us node ko e pe attach karo
                      // kyoki tum toh e pe the na
                      Node* n=new Node(ch); 

                      temp->children[ch]=n;
                      temp=n;
                  }
           }

           temp->terminal=true;
       }

       bool find(string s)
       {
           Node* temp=root;
           for(int i=0;i<s.length();i++)
           {
               char ch=s[i];
              if(temp->children.count(ch)==0)
                  {
                      return false;
                  }
                  else{
                       temp=temp->children[ch];
                  }

           }

           return temp->terminal; // return true or false depending last node is terminal or not
       }        
};


int main()
{
    Trie t;

    vector<string>words{"Leet","code"};

   for(int i=0;i<words.size();i++)
   {
       t.insert(words[i]);
   }

   if(t.find("code"))
     cout<<"present";
     else{
         cout<<"not present";
     }

return 0;
}