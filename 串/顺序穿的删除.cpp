#include<stdio.h>
 typedef struct
 {char ch[100];
 int len;
 }sstring;
 void shanchu(sstring *s,sstring *w)
 {int pos,a,i;
  pos=0;
  a=0;
  while(s->ch[pos]!='\0')
  	{if(s->ch[pos]==w->ch[a])
  		{pos++;a++;
		  }
		  if(s->ch[pos]==w->ch[a])
		  	{for(i=pos+w->len;i<s->len;i++)
			  	s->ch[i-w->len]=s->ch[i];
			  s->len=s->len-w->len; }
	a=0;
	  }
 }
 int main()
 {int i;
 sstring s;
 sstring w;
 printf("输入s的最大值下表:");
 scanf("%d",&s.len); 
 printf("输入字符串s:");
 for(i=0;i<s.len;i++)
 	scanf("%c",&s.ch[i]);
 printf("输入w的最大值下表:");
 	scanf("%d",&w.len); 
 printf("输入字符串w:");
 for(i=0;i<w.len;i++)
 	scanf("%c",&w.ch[i]);
 shanchu(&s,&w);
 for(i=0;i<s.len;i++)
 printf("%c",s.ch[i]);	
 	
 
 }
