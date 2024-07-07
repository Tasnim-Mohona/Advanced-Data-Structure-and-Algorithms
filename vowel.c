// Capital consonant to small case, if consonant already in small case then no change



//Solution:



#include<stdio.h>

#include<string.h>

int main()

{

    int l, i;

    char s[100];

    gets(s);

    l = strlen(s);

    for(i=0; i<l; i++)

    {

        if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O' && s[i]!='U')

        {

            if(s[i]>='A' && s[i]<='Z')

                s[i] = s[i] + 32;

        }

    }

    puts(s);

    return 0;

}


