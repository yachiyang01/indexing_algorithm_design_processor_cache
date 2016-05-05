#include <stdio.h>
#include <string.h>
#include <math.h>

int main()//取得資訊
{
	
    int m; // address bus
    int e; // entries
    int a; // associative
    int k; // select bits
    int address[100];
    int run_bit=0;
    int i;
    int add[100];
    int index[e][a];
    int tag[k];
    int j=0;
    int flag=0;
	int str_no[20];
    int entry=1;
    int y=1;
	int *cacheA=NULL, *data1=NULL, *data2=NULL,*data3=NULL,*data4=NULL,*data5=NULL,*fp=NULL;
    int status=0;
    int Y=1;
    int miss=0;
    int hit=0;
    //讀到結束才跳出
	
	cacheA=fopen("config/cacheA.org", "rt");

	fp=fopen("index.rpt", "w");
    fscanf(cacheA, "%s", &str_no);
	char *p=NULL;
	
	
    	for(p=str_no; *p!='\0'; p++){
    	if(*p==':') *p=' ';// 把含冒號部分改空白
    	else if(*p=='\n') *p=' ';
    	}
        sscanf(str_no, "%*s %d %*s %d %*s %d", &m,&e,&a);
        
    k = log (e)/log(2);

        printf("Student ID: 100070023\n\n");
        printf("Addressing Bus: %d\n\n",m);
        printf("Entries: %d\n\n",e);
        printf("Associativity: %d\n\n",a);
        printf("Indexing bits count: %d\n\n",k);
        printf("Indexing bits:");
        for(i=k;i<m-k+1;i--)
            printf("%d",i);
        printf("\n\n");
        
        
            fprintf(fp,"Student ID: 100070023\n\n");
        fprintf(fp,"Addressing Bus: %d\n\n",m);
        fprintf(fp,"Entries: %d\n\n",e);
        fprintf(fp,"Associativity: %d\n\n",a);
        fprintf(fp,"Indexing bits count: %d\n\n",k);
        fprintf(fp,"Indexing bits:");
        for(i=k;i<m-k+1;i--)
            fprintf("%d",i);
        fprintf(fp,"\n\n");

    
        
    while(flag==0)
    {
        while(*p!='\n') //把資料寫進陣列並記成a0a1a2a3
        {
            sscanf(str_no, " %d ", &address);
            status=0;
        }
        flag=1;
    }


    for(i=0; i<k; i++) //用來比較的tag
    {
        tag[i]=address[m-k+1];
    }
    for(i=0; i<k; i++)
    {
        Y=Y*2;
        entry=entry+tag[j]*Y;//entries #
    }

    for(j=0; j<a; j++) //associative
    {
        if(index[entry][j]==0)//空的可以放
        {
            index[entry][j]=address;
            status=-1;//miss
            break;
        }
        else if(index[entry][j]==address)//hit
        {
            status=1;//hit

            break;
        }
        else if(index[entry][j+1]==0 && index[entry][j]!=0 && status==0)//associative 下一個可以放
        {
            index[i][j+1]=address;
            status=-1;//miss
            break;
        }
        else if (j==a-1 && index[entry][j]!=0)//都滿了就取代吧~~ 
        {
            index[entry][0]=address;
            status=-1;//miss

            break;
        }
    }

    while(status!=0)
    {
        if(status==-1)//miss
        {
            printf("%s miss\n\n",address);
            miss=miss+1;
        }
        else
            {
            hit=hit+1;
            printf("%s hit\n\n",address);
            }
        status=0;
    }


        fprintf(fp,"Student ID: 100070023\n\n");
        fprintf(fp,"Addressing Bus: %d\n\n",m);
        fprintf(fp,"Entries: %d\n\n",e);
        fprintf(fp,"Associativity: %d\n\n",a);
        fprintf(fp,"Indexing bits count: %d\n\n",k);
        fprintf(fp,"Indexing bits:");
        for(i=k;i<m-k+1;i--)
            fprintf("%d",i);
        fprintf(fp,"\n\n");
        fprintf(fp,"Total cache miss: %d\n\n",miss);




	fclose(cacheA);
	fclose("release/DataReference_n_comp.lst");
	fclose("release/DataReference_n_real.lst.");
	fclose("release/InstReference_iir_one.lst");
	fclose("release/InstReference_lms.lst");
	fclose(fp);
	
	return 0;
}


