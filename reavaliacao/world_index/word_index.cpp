#include <bits/stdc++.h>

using namespace std;

int main()
{

  map<string,int> mp;
  int i, j ,k ,l , m;
  string alf = "abcdefghijklmnopqrstuvwxyz";
  string s1, s2, s3, s4, s5, sum;
  int p = 1;
  
  for( i = 0; i < 26; i++)
  {
      s1 = alf[i];
      mp[s1] = p;
      p++;
  }

  for(i =0 ; i < 26; i++)
  {
      for(j = i+1; j < 26; j++)
      {
          s1 = alf[i];
          s2 = alf[j];
          sum = s1+s2;
          mp[sum] = p;
          p++;
      }
  }

  for(i = 0; i < 26; i++)
  {
      for(j = i + 1; j < 26; j++)
      {
          for(k = j + 1; k < 26; k++)
          {
              s1 = alf[i];
              s2 = alf[j];
              s3 = alf[k];
              sum = s1+s2+s3;
              mp[sum] = p;
              p++;
          }
      }
  }


  for(i = 0; i < 26; i++)
  {
      for(j = i + 1; j < 26; j++)
      {
          for(k = j + 1; k < 26; k++)
          {
              for(l = k + 1; l < 26; l++)
              {
                  s1 = alf[i];
                  s2 = alf[j];
                  s3 = alf[k];
                  s4 = alf[l];
                  sum = s1 + s2 + s3 + s4;
                  mp[sum] = p;
                  p++;
              }
          }
      }
  }



  for(i=0; i<26; i++)
  {
      for(j=i+1; j<26; j++)
      {
          for(k=j+1; k<26; k++)
          {
              for(l=k+1; l<26; l++)
              {
                  for(m=l+1; m<26; m++)
                  {

                      s1 = alf[i];
                      s2 = alf[j];
                      s3 = alf[k];
                      s4 = alf[l];
                      s5 = alf[m];
                      sum = s1 + s2 + s3 + s4 + s5;
                      mp[sum] = p;
                      p++;
                  }
              }
          }
      }
  }

   string str;
   
   while(cin >> str)
   {
       cout << mp[str] << endl;
   }

   return 0;
}