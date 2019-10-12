#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    priority_queue<int,vector<int>,greater<int> >minpq;
    priority_queue<int>maxpq;

    while(t--)
    {
       int x;
       cin>>x;

       if(minpq.empty() && maxpq.empty())
            minpq.push(x);

       else
       {
           if(x<minpq.top())
           {
               if(maxpq.size()-minpq.size()==1)
               {
                   minpq.push(maxpq.top());
                   maxpq.pop();
                   maxpq.push(x);
               }
               else
                    maxpq.push(x);
           }
           else
           {
               if(minpq.size()-maxpq.size()==1)
               {
                   maxpq.push(minpq.top());
                   minpq.pop();
                   minpq.push(x);
               }
               else
                    minpq.push(x);
           }
       }

       if(maxpq.size()==minpq.size())
       {
           cout<<(maxpq.top()+minpq.top())/2<<endl;;
       }
       else
       {
           if(maxpq.size()>minpq.size())
            cout<<maxpq.top()<<endl;
           else
            cout<<minpq.top()<<endl;
       }

    }
    return 0;
}
