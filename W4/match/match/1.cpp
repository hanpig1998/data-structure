#include <iostream>  
#include <stack>  
using namespace std;  
bool isLeft(char c)  
{  
    return (c == '(' || c == '[' || c == '{');  
}  
bool isMatch(char right, char left)  
{  
    if (right == ')')  
    {  
        return (left == '(');  
    }  
  
    if (right == ']')  
    {  
        return (left == '[');  
    }  
  
    if (right == '}')  
    {  
        return (left == '{');  
    }  
}   
bool matching(char* s)  
{  
    stack<char> cs;  
    char c;  
    while (*s)  
    {  
        c = *s;  
        if (isLeft(c))  
        {  
            cs.push(c);  
        }  
        else  
        {  
            if (cs.empty() || !isMatch(c, cs.top()))  
            {  
                return false;  
            }  
  
            cs.pop();  
        }  
        ++s;  
    }  
  
    if (!cs.empty())  
    {  
        return false;  
    }  
    return true;  
}  
int main()
{
	int time=0;
	scanf("%d",&time);
	char s[100000];
	for (int i=1;i<=time;i++)
	{
		scanf("%s",s);
		if (matching(s))
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}