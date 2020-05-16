#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int num;
	int count1,count2,ps,i,rs,x,y;
	int max=0;
	char buff[160],ch[3];
	FILE *fp,*fp1;
	fp =fopen("bank-full.csv","r");

	while(fgets(buff,160,fp))
	{
		count1=0;
		for(i=0;i<strlen(buff);i++)
		{
			if(buff[i]==';')
			{
				count1++;
			}
			if(count1==1)
			{
				ps=i+2;
				break;
			}
		}
		if(buff[ps]=='r')
		{
			count2=0;
			for(i=0;i<strlen(buff);i++)
			{
				if(buff[i]==';')
				{
					count2++;
				}
				if(count2==2)
				{
					rs=i+2;
					break;
				}
			}
		}   
		if(buff[rs]='m')
		{
			num=(10*((int)buff[0]-48))+((int)buff[1]-48);
			if(num>max)
			{
				max=num;
			}
		}
	}
    
    fclose(fp);
	fp=fopen("bank-full.csv","r");
	fgets(buff,sizeof(buff),fp);
  while(fgets(buff,sizeof(buff),fp))
  {
     if((strstr(buff,"retired")&& strstr(buff,"married"))!=NULL)
     {
      num=(10*((int)buff[0]-48))+((int)buff[1]-48);
      if(num==max)
      {
      count1=0;
      for(i=0;i<strlen(buff);i++)
      {
      if(buff[i]==';')
      {
      count1++;
      }

      if(count1==10)
      {
      x=i+2;
      break;
      }
    }

   for(y=0,x=i+2;x<=i+4;x++,y++)
   {
   ch[y]=buff[x];
   }
   }
  }
 }



 printf("the month of married retired person with highest age: %s",ch);

 printf("\n");
 printf("%d",max);


 fclose(fp);
}
 fp1 = fopen("forestfires.csv","r");


 if(fp1==NULL)
 {
 exit(0);
 }
 fgets(buff,sizeof(buff),fp1);

 while(fgets(buff,sizeof(buff),fp1)!=NULL)
 {
 if(strstr(buff,ch)!=NULL)
 {
 count2++;
 puts(buff);
 printf("the total number of forestfires in month %s is %d",ch,count2);
 }

 }
 fclose(fp1);
 }
