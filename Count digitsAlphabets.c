#include<stdio.h>
#include<string.h>

void action(char *s, int l)

{
int i=0, c=0, n=0;
for(i=0;i<l;i++)

{
if((s[i]>='A' && s[i]<='Z')||(s[i]>='a'&& s[i]<='z'))
{
c++;
}

if(s[i]>='0'&&s[i]<='9')

{
n++;
}

}


printf("Character=%d", c);
printf("\nNumber=%d", n);
}



int main()

{

char s[]="Mohona";
int l=strlen(s);
action(s,l);
return 0;

}
