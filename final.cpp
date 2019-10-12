#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void welcome();
void choice();
void login();
void registration();
void menu();
void order();
int main()
{
	char ch;
	welcome();
	printf("\n\n\t\t\tPress any key to continue (y/n):");
	scanf("%c",&ch);
	if(ch=='y'||'Y')
	{
		choice();
		label:
			menu();	    
	}
	else
	{
		printf("your menu will not be shown");
	}
	getch();
	return 0;
}
void welcome()
{
	//Resturant Management System first page
	printf("                                           *******************************************");
	printf("\n                                           *                                         *");
	printf("\n                                           *      Resturant Management Project       *                        ");
	printf("\n                                           *                                         *");
	printf("\n                                           *******************************************");
	printf("\n\n\n\t\t\t\t\t\t\tSimalchaur,Pokhara");
	printf("\n\n\n\n_______________________________________________________________________________________________________________________\n");
}
void choice()
{
	//to clear the screen and do further work
	system("cls");
	printf("\n***********To go further , please login your details**********");
	printf("\n\n\t1. Login ");
	printf("\n\n\npress enter to login");
	getch();
	login();
}
void login()
{
	//username=owner and password =12345
	//login steps
	FILE *fp;
	char name[10];
	char na[30];
	char add[25];
	int j;
	char pass[5];
	char ch;
	system("cls");
	fp=fopen("customer detail.txt","a");
	if(fp==NULL)
	{
		printf("\nYour login detail is invalid");
		exit(1);
	}
//	do
	//{
		printf("\n\t\tUsername:");
	    //gets(name);
	    scanf("  %s",&name);
	    printf("\n\t\tPassword (5 character):");
	    for(j=0;j<5;j++)
    	{
	    	ch=getch();
	    	pass[j]=ch;
	    	ch='*';
    		printf("%c",ch);
    	}
    	getch();
	//}while(name!="user"&&pass!="12345");
	printf("\n\n\t\tEnter your name:");
	scanf("%s",&na);
	fprintf(fp," name:%s",na);
	fprintf(fp,"\n");
	printf("\n\t\tEnter your address:");
	scanf(" %s",add);
	fprintf(fp,"Address:%s",add);
	fprintf(fp,"\n");
	printf("\n press enter to submit");
	fclose(fp);
	getch();
}
void menu()
{
	char a,op;
    int i=0;
	char f[i][50];
	char pay[15];
	int q[i];
	int c[i];
	int num;
	int re;
	char reme;
	char s[i][20];
	FILE *fp;
	int total[i];
	int sum=0,b=0;
	int net,grand;
	int vat,disc;
	label:
	system("cls");	
	printf("\n\n*******************************************************MENU**********************************************************");
	printf("\n_______________________________________________________________________________________________________________________");
	printf("\n    *****************************");
	printf("\n\n    *   1. Order Food Item      *");
	printf("\n\n    *   2. Remove Food Item     *");
	printf("\n\n    *   3. Bill                 *");
	printf("\n\n    *   4. Exit                 *");
	printf("\n    *****************************");
	printf("\n\nEnter your choice where u want to go ");
	scanf("%d",&num);
    system("cls");
	switch(num)
	{
	  	case 1:
	        fp=fopen("customer detail.txt","a");
	        if(fp==NULL)
	        {
		        printf("your data is invalid ");
	        }
        	printf("\n\t\t\t\tMenu Items");
        	printf("\n- - - - - - - - - - - - - - - - - - -");
        	printf("\n\n| S.N.|  food Name       |  Food Cost  |");
            printf("\n\n| 1.  |  veg.momo        |  90         |");
        	printf("\n\n| 2.  |  chicken momo    |  110        |");
            printf("\n\n| 3.  |  chicken thuppa  |  130        |");
            printf("\n\n| 4.  |  mix thuppa      |  150        |");
        	printf("\n\n 5.   | coffee           | 50          |");
        	printf("\n- - - - - - - - - - - - - - - - - - - - -");
            printf("\n\nTo order your food item, Please fill below details");
            do
            {
    	        i=i+1;
            	printf("\nFood name:\n");
            	scanf("  %s",&f[i]);
            	printf("\nFood quantity:\n");
            	scanf("%d",&q[i]);
            	printf("\nFood cost:\n");
            	scanf("%d",&c[i]);
            	b++;
            	printf("\nDo you want to order more? ");
            	scanf("  %c",&op);
	        }while(op=='y');
	        fclose(fp);
	        printf("\nYour total orders are:\n");
        	for(i=1;i<=b;i++)
	        {
	        	printf(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
	        	printf(" |%d\t |%s\t\t |%d\t |%d |",i,f[i],q[i],c[i]);
		        printf("\n");
        	}
        	printf(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
	        printf("press enter to order");	
	        getch();
	    goto label;
		break;
	    case 2:
        goto remove;
    	break;
    	case 3:
	    goto billing;
		break;
		default:
		goto exit;     
	    break;
			
	}
	remove:
		if(f[i]&&q[i]&&c[i]==NULL)
		{
			printf("You have not ordered any foods");
			printf("\npress enter to go back to menu");
			getch();
			goto label;
		}
		do
		{
			printf("\nyour total orders are :\n");
		    printf("s.n\tfood name\t\tquantity\t\tcost\n");
		    for(i=1;i<=b;i++)
		    {
			    printf("%d   %s    %d  %d",i,f[i],q[i],c[i]);
				printf("\n");	
		    }
		    printf("\nWhich food item no. you want to remove? ");
		    scanf("  %d",&re);
		    for(i=re;i<=b;i++)
		    {
		    	strcpy(s[i],f[i]);
		    	strcpy(f[i],f[i+1]);
		    	q[i]=q[i+1];
		    	c[i]=c[i+1];
			}
			b=b-1;
			printf("\ndo you want to remove any more?");
			scanf("  %c",&reme);
		}while(reme=='y');
		printf("\nYour final orders are: ");
		for(i=1;i<=b;i++)
		{
			printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  \n");
			printf("|%d   |%s   |%d   |%d  |",i,f[i],q[i],c[i]);
			printf("\n");
		}
		printf("press enter to go back to menu");
		getch();
		goto label;
	billing:
		fp=fopen("customer detail.txt","a");
		if(f[i]&&q[i]&&c[i]==NULL)
		{
			printf("You have not ordered any foods");
			printf("\npress enter to go back to menu");
			getch();
			goto label;
		}
		for(i=1;i<=b;i++)
		{
			total[i]=q[i]*c[i];
			sum=sum+total[i];
		}
		/*fp=fopen("customer detail.txt","r");
		if(fp==NULL)
		{
			printf("Your file is not created");
		}
		fscanf(fp,"\nName :%s",na);
		fscanf(fp,"\nAddress :%s",add);
		fclose(fp);*/
		printf("\nTo view your bill please look below");
		printf("\n S.N\tFood item\t\tQuantity\t\tcost\t\tTotal");
		fprintf(fp,"\n S.n\tFood item\t\tQuantity\t\tcost\t\tTotal");
		if(sum>=1000)
		{
			disc=0.10*sum;
		}
		else
		{
			net=sum;
		}
		vat=0.11*sum;
		for(i=1;i<=b;i++)
		{
			printf("\n %d\t%s\t\t\t%d\t\t\t%d\t\t%d",i,f[i],q[i],c[i],total[i]);
			fprintf(fp,"\n %d\t%s\t\t\t%d\t\t\t%d\t\t%d",i,f[i],q[i],c[i],total[i]);
			printf("\n");
		}
		if(sum>=1000)
		{
			printf("\n\t\t\t\t\t\t\t\tdiscount=%d",disc);
			fprintf(fp,"\n\t\t\t\t\t\t\t\tdiscount=%d",disc);
			
		}
		printf("\n\t\t\t\t\t\t\t\tVat(11)=%d",vat);
		if(sum>=1000)
		{
			grand=sum-disc+vat;
			printf("\n\t\t\t\t\t\t\t\tgrand total=%d",grand);
			fprintf(fp,"\n\t\t\t\t\t\t\t\tgrand total=%d",grand);
		}
		else
		{
			grand=sum+vat;
			printf("\n\t\t\t\t\t\t\t\tgrand total=%d",grand);
			fprintf(fp,"\n\t\t\t\t\t\t\t\tgrand total=%d",grand);
		}
		fprintf(fp,"\n*******************************************************************************************************************************************************\n");
		fclose(fp);
	    printf("\n\nPress enter to go to menu");
	    getch();
	    goto label;
		/*intf("\n\n********************How do you want to pay???**************");
		printf("\n___________________Cash / by card____________________");
		printf("\n######################Please let us know#####################");
		scanf(" %s",pay);
		while(pay=="cash")
		{
			printf("\n\n                      Thank u for paying in cash                         ");
			printf("\n########################## Please come again ######################");
		}
		while(pay=="card")
		{
			printf("\n\n                        Thank u for paying with card                       ");
			printf("\n########################## Please come again ######################");
		}	*/
		exit:
			printf("\n\n\n\n\t\t!!!!!!!!Thank you for ordering food from our resturant!!!!!!!!");
		    printf("\n\n\t\t\t\tPlease come again");
	getch();
}

