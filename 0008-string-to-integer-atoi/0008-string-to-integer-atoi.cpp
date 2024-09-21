class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, i=0;
        long long res=0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-') {
        sign = -1; 
        i++;
    }
    else if (str[i] == '+') {
        sign = 1; 
        i++;
    }
    for( ;i<str.length();i++)
    {
      if(str[i]>='0' && str[i]<='9')
      res=res*10+ (str[i]-'0');

      else if(str[i]!='+' || str[i]!='-' || str[i]!='.') break;

      if(sign==-1 && (-1*res)<=INT_MIN) return INT_MIN; 
      if(sign==1 && res>=INT_MAX) return INT_MAX; 
    }
    return res * sign;
    }
};