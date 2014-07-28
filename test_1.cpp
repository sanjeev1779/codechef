
#include<iostream>
#include<fstream>
#include<stack>

using namespace std;

int main()
{
    string line ,temp,dummy;
    ifstream in("demo.xml");
    stack<string> st;
    pair<string,string> parent[1000];
    int c=0,i,j;
    while(getline(in,line))
    {

    for( i=0;i<line.size();i++)
    {
        temp="";
        if(line[i]=='<'  && line[i+1]!='/' )
        {
        for(j=i+1;j<line.size();j++)
        {
            if(line[j]=='>')
                break;
            temp+=line[j];
        }
        st.push(temp);

        }
        else if(line[i]=='<'  && line[i+1]=='/' )
        {
            for( j=i+2;j<line.size();j++)
        {
            //if(line[j]=='/')
            //    continue;
            if(line[j]=='>')
                break;
            temp+=line[j];
        }
        if(st.size()==1)
        {
            parent[c]=make_pair(temp,"none");
            c++;
        }
        else if(!st.empty() && st.top()==temp )
        {
            st.pop();
            parent[c]=make_pair(temp,st.top());
            c++;
        }

        }
    }
    }

    for(int i=0;i<c;i++)
    {
        cout<<"tag="<<parent[i].first<<"   "<<"parent-"<<parent[i].second<<endl;
    }
}

