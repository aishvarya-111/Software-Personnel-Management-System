#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define size 1

//Data Structure for storing details
static struct emp_data
	{
		char name[50];
		char title[50];
		char qualification[50];
		char lang[50];
		char prog_lang[50];
		char gender;
		int age;
		int id;
		int exp;
		long int salary;
		long long int ph_no;
	}details;

//Function declaration
void loading(int n);
void header();
void add_employee();
void display_details();
void disp_male();
void disp_female();
void disp_all_details();
void update_details();
void delete_employee();
void search_employee();
void swap(int* xp, int* yp);
void bubblesort(int arr[],int id_arr[], int n);
void sort_name(int id_arr[],char arr[50][50],int n);
void rev_arr(int id_arr[],int n);
void print_rec(int id_arr[], int n);
void sort_employee();
void exiting();
void menu();

//Delay function 	
void loading(int n)
{
    int msec = 0;
    const int trigger = 500; // ms
    const int printWidth = 4;
    int counter = 0;
    clock_t before = clock();
	
    while (n)
    {
        clock_t difference = clock() - before;
        msec = difference * 1000 / CLOCKS_PER_SEC;
        int i;
        if (msec >= trigger)
        {
            counter++;
            msec = 0;
            before = clock();
        }
        for (i = 0; i < counter; ++i)
        {            
            fputc(' ', stdout);
        }
        for (i = 0; i < printWidth - counter; ++i)
        {
            fputc(' ', stdout);
        }
        fputc('\r', stdout);
        fflush(stdout);

        if (counter == printWidth)
        {
            counter = 0;
        }
        n--;
    }
}

//Display header	
void header()
{
	system("cls");
	system("color 03");
	printf("\n");
	printf("\t\t************************************************************************\n\n");
	printf("\t\t\t 	WELCOME TO SOFTWARE PERSONNEL MANAGEMENT SYSTEM\t\t\t\n\n");
	printf("\t\t************************************************************************\n");
};

//Adding new employee details
void add_employee()
{
	system("cls");
	system("color 0E");
	FILE *data;
	int id;
	data = fopen("employeeRecord.txt","a");
	printf("\n \tEmployee ID:\t");
	scanf("%d",&details.id);	
	printf("\n \tEmployee Name:\t");
	fflush(stdin);
	gets(details.name);
	printf("\n \tEmployee Gender:\t");
	scanf("%c",&details.gender);
	printf("\n \tEmployee Title:\t");
	fflush(stdin);
	gets(details.title);
	printf("\n \tEmployee Age:\t");
	scanf("%d",&details.age);
	printf("\n \tEmployee Work Experience:\t");
	scanf("%d",&details.exp);
	printf("\n \tEmployee Salary:\t");
	scanf("%ld",&details.salary);
	printf("\n \tEmployee Phone Number:\t");
	scanf("%lld",&details.ph_no);
	printf("\n \tEmployee Qualifications:\t");
	fflush(stdin);
	gets(details.qualification);
	printf("\n \tProgramming languages Known:\t");
	fflush(stdin);
	gets(details.prog_lang);
	printf("\n \tEmployee Language:\t");
	fflush(stdin);
	gets(details.lang);
	//Wrting in the file
	if(fwrite(&details,sizeof(details),size,data)!=size)
	{
		printf("\n\tError in Writing to File.");
		exiting();
	}
	else
	{
		printf("\n\tEmployee Record Successfully Written.");
	}	
	fclose(data);
}

//Displaying male employee only
void disp_male()
{
	system("cls");
	system("color 0E");
	FILE *data;
	data = fopen("employeeRecord.txt","r");
	int found = 0;
	int c=1;
	char ch='Y';
	char g= 'M';
	while(fread(&details,sizeof(details),size,data)==size)
	{
		char h=details.gender;
		if(h == g)
		{
			found = 1;	
			printf("\n\n\n\tEMPLOYEE %d RECORD IS......",c++);
			printf("\n\n\tEMPLOYEE ID:\t%d",details.id);
			printf("\n\n\tEMPLOYEE NAME:\t%s",details.name);
			printf("\n\n\tEMPLOYEE GENDER:\t%c",details.gender);
			printf("\n\n\tEMPLOYEE POSITION:\t%s",details.title);
			printf("\n\n\tEMPLOYEE AGE:\t%d",details.age);
			printf("\n\n\tEMPLOYEE QUALIFICATIONS:\t%s",details.qualification);
			printf("\n\n\tEMPLOYEE WORK EXPERIENCE:\t%d",details.exp);
			printf("\n\n\tEMLOYEE SALARY:\t%ld",details.salary);
			printf("\n\n\tEMPLOYEE PHONE NUMBER:\t%lld",details.ph_no);
			printf("\n\n\tPROGRAMMING LANGUAGES KNOWN:\t%s",details.prog_lang);	
			printf("\n\n\tLANGUAGES KNOWN:\t%s",details.lang);
		}
	}
	
	if(found == 0 && ch!='N')
	{
		printf("\n\tNO MALE EMPLOYEE RECORD FOUND.");
	}
	fclose(data);
}

//Displaying Female employee only		
void disp_female()
{
	system("cls");
	system("color 0E");
	FILE *data;
	data = fopen("employeeRecord.txt","r");
	int found = 0;
	int c=1;
	char ch='Y';
	char g= 'F';
	while(fread(&details,sizeof(details),size,data)==size)
	{
		char h=details.gender;
		if(h == g)
		{
			found = 1;	
			printf("\n\n\n\tEMPLOYEE %d RECORD IS......",c++);
			printf("\n\n\tEMPLOYEE ID:\t%d",details.id);
			printf("\n\n\tEMPLOYEE NAME:\t%s",details.name);
			printf("\n\n\tEMPLOYEE GENDER:\t%c",details.gender);
			printf("\n\n\tEMPLOYEE POSITION:\t%s",details.title);
			printf("\n\n\tEMPLOYEE AGE:\t%d",details.age);
			printf("\n\n\tEMPLOYEE QUALIFICATIONS:\t%s",details.qualification);
			printf("\n\n\tEMPLOYEE WORK EXPERIENCE:\t%d",details.exp);
			printf("\n\n\tEMLOYEE SALARY:\t%ld",details.salary);
			printf("\n\n\tEMPLOYEE PHONE NUMBER:\t%lld",details.ph_no);
			printf("\n\n\tPROGRAMMING LANGUAGES KNOWN:\t%s",details.prog_lang);	
			printf("\n\n\tLANGUAGES KNOWN:\t%s",details.lang);
		}
	}
	
	if(found == 0 && ch!='N')
	{
		printf("\n\tNO FEMALE EMPLOYEE RECORD FOUND.");
	}
	fclose(data);
}

//Displaying all employee details		
void disp_all_details()
{
	system("cls");
	system("color 0E");
	FILE *data;
	data = fopen("employeeRecord.txt","r");
	int c=1;
	while(fread(&details,sizeof(details),size,data)==size)
	{
		printf("\n\n\n\tEMPLOYEE %d RECORD IS......",c++);
		printf("\n\n\tEMPLOYEE ID:\t%d",details.id);
		printf("\n\n\tEMPLOYEE NAME:\t%s",details.name);
		printf("\n\n\tEMPLOYEE POSITION:\t%s",details.title);
		printf("\n\n\tEMPLOYEE AGE:\t%d",details.age);
		printf("\n\n\tEMPLOYEE GENDER:\t%c",details.gender);
		printf("\n\n\tEMPLOYEE QUALIFICATIONS:\t%s",details.qualification);
		printf("\n\n\tEMPLOYEE WORK EXPERIENCE:\t%d",details.exp);
		printf("\n\n\tEMLOYEE SALARY:\t%ld",details.salary);
		printf("\n\n\tEMPLOYEE PHONE NUMBER:\t%lld",details.ph_no);
		printf("\n\n\tPROGRAMMING LANGUAGES KNOWN:\t%s",details.prog_lang);	
		printf("\n\n\tLANGUAGES KNOWN:\t%s",details.lang);
	}
	fclose(data);
}

//Main function to choose display 
void display_details()
{
	system("cls");
	system("color 0E");
	int found = 0,display_choice;
	printf("\n\tWhat details do you want to display?");
	printf("\n\n\tDisplay all Male Employee details: Enter 1");
	printf("\n\tDisplay all Female Employee details: Enter 2");
	printf("\n\tDisplay all Employee details: Enter 3");
	printf("\n\tINPUT:\t");
	scanf("%d",&display_choice);
	switch(display_choice)
	{
		case 1:
				disp_male();
				break;
		case 2:
				disp_female();
				break;
		case 3:
				disp_all_details();
				break;
		default:
				printf("\n\tWRONG CHOICE.\n");
	}
}

//Updating the details
void update_details()
{
	system("cls");
	system("color 0E");
	FILE *data;
	int id,found=0;
	data = fopen("employeeRecord.txt","r+");
	printf("\n\tEnter Employee ID to Edit Record:\t");
	scanf("%d",&id);
	while(fread(&details,sizeof(details),size,data)==size)
	{
		if(details.id == id)
		{
			found = 1;
			printf("\n\tEMPLOYEE RECORD IS......");
			printf("\n\n\tEMPLOYEE ID:\t%d",details.id);
			printf("\n\n\tEMPLOYEE NAME:\t%s",details.name);
			printf("\n\n\tEMPLOYEE GENDER:\t%c",details.gender);
			printf("\n\n\tEMPLOYEE POSITION:\t%s",details.title);
			printf("\n\n\tEMPLOYEE AGE:\t%d",details.age);
			printf("\n\n\tEMPLOYEE QUALIFICATIONS:\t%s",details.qualification);
			printf("\n\n\tEMPLOYEE WORK EXPERIENCE:\t%d",details.exp);
			printf("\n\n\tEMLOYEE SALARY:\t%ld",details.salary);
			printf("\n\n\tEMPLOYEE PHONE NUMBER:\t%lld",details.ph_no);
			printf("\n\n\tPROGRAMMING LANGUAGES KNOWN:\t%s",details.prog_lang);	
			printf("\n\n\tLANGUAGES KNOWN:\t%s",details.lang);
				
			printf("\n\n\t*****\tMODIFYING EMPLOYEE RECORD\t*****\t\n");
			
			printf("\n \tEmployee Name:\t");
			fflush(stdin);
			gets(details.name);
			printf("\n \tEmployee Gender:\t");
			scanf("%c",&details.gender);
			printf("\n \tEmployee Title:\t");
			fflush(stdin);
			gets(details.title);
			printf("\n \tEmployee Age:\t");
			scanf("%d",&details.age);
			printf("\n \tEmployee Work Experience:\t");
			scanf("%d",&details.exp);
			printf("\n \tEmployee Salary:\t");
			scanf("%ld",&details.salary);
			printf("\n \tEmployee Phone Number:\t");
			scanf("%lld",&details.ph_no);
			printf("\n \tEmployee Qualifications:\t");
			fflush(stdin);
			gets(details.qualification);
			printf("\n \tProgramming languages Known:\t");
			fflush(stdin);
			gets(details.prog_lang);
			printf("\n \tEmployee Language:\t");
			fflush(stdin);
			gets(details.lang);
			//Rewrting the details
			fseek(data,-sizeof(details),SEEK_CUR);
        	fwrite(&details,sizeof(details),size,data);
        	printf("\n\n\tEmployee Record Successfuly Written.");
        	break;
		}
	}
	if(found == 0)
	{
		printf("\n\tRECORD NOT FOUND...");
	}
	fclose(data);
}

//Deleting the details
void delete_employee()
{
	system("cls");
	system("color 0E");
	int found = 0,del_emp_id;
	FILE *data,*temp;
	data = fopen("employeeRecord.txt","r");
	temp = fopen("temp_data.txt","w");
	if(data == NULL)
	{
		printf("\n\tError in Opening File");
		exit(0);
	}
	printf("\n\tEnter Employee ID to delete it's Record:\t");
	scanf("%d",&del_emp_id);	
	while((fread(&details,sizeof(details),size,data)==size))
	{
		if(details.id!=del_emp_id)
			fwrite(&details,sizeof(details),size,temp);	
	}
	fclose(data);
    fclose(temp);
    remove("employeeRecord.txt");
    rename("temp_data.txt","employeeRecord.txt");
    data=fopen("employeeRecord.txt","r");
    loading(5000);
    printf("\n\tRecord successfully deleted.\n\n");
    fclose(data);
}

void search_id_name(int search_emp_id,char search_name[]){
	system("cls");
	system("color 0E");
	FILE *data;
	data = fopen("employeeRecord.txt","r");
	int found = 0,c=1;
	rewind(data);
	while(fread(&details,sizeof(details),size,data)==size)
	{
		if(details.id == search_emp_id || strcmp(details.name,search_name)==0)
		{
			found = 1;	
			printf("\n\n\tEMPLOYEE %d RECORD IS......",c++);
			printf("\n\n\tEMPLOYEE ID:\t%d",details.id);
			printf("\n\n\tEMPLOYEE NAME:\t%s",details.name);
			printf("\n\n\tEMPLOYEE GENDER:\t%c",details.gender);
			printf("\n\n\tEMPLOYEE POSITION:\t%s",details.title);
			printf("\n\n\tEMPLOYEE AGE:\t%d",details.age);
			printf("\n\n\tEMPLOYEE QUALIFICATIONS:\t%s",details.qualification);
			printf("\n\n\tEMPLOYEE WORK EXPERIENCE:\t%d",details.exp);
			printf("\n\n\tEMLOYEE SALARY:\t%ld",details.salary);
			printf("\n\n\tEMPLOYEE PHONE NUMBER:\t%lld",details.ph_no);
			printf("\n\n\tPROGRAMMING LANGUAGES KNOWN:\t%s",details.prog_lang);	
			printf("\n\n\tLANGUAGES KNOWN:\t%s",details.lang);
		}
	}
	
	if(found == 0)
	{
		printf("\n\tNO SUCH EMPLOYEE RECORD FOUND.");
	}
	fclose(data);
}
//Searching employee details
void search_employee()
{
	system("cls");
	system("color 0E");
	int found = 0,search_choice,search_emp_id;
	int c=1;
	char search_name[100],ch='Y';
	printf("\n\tWhat Do You Know about the Employee?");
	printf("\n\n\tEmployee ID: Enter 1");
	printf("\n\tEmployee Name: Enter 2");
	printf("\n\tINPUT:\t");
	scanf("%d",&search_choice);
	switch(search_choice)
	{
		case 1:
			//searching based on ID
			printf("\n\tEnter Employee ID:\t");
			scanf("%d",&search_emp_id);
			search_id_name(search_emp_id,search_name);
			break;
		case 2:
			//Searching based on name
			printf("\n\tEnter Employee Name:\t");
			fflush(stdin);
			gets(search_name);
			search_id_name(search_emp_id,search_name);
			break;
		default:
			printf("\n\tWRONG CHOICE.\n");	
	}
	
}

//Swap function for sorting
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubblesort(int arr[],int id_arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                swap(&id_arr[j],&id_arr[j+1]);
            }
    }
}

//Bubble sort for array of strings--Names
void sort_name(int id_arr[],char arr[50][50],int n)
{
	char temp[30];
	int i,j;
    for(i=0; i<n; i++)
	{
    	for(j=0; j<n-1-i; j++)
		{
      		if(strcmp(&arr[j], &arr[j+1]) > 0)
			{
        		strcpy(temp, arr[j]);
        		strcpy(arr[j], arr[j+1]);
        		strcpy(arr[j+1], temp);
        		swap(&id_arr[j],&id_arr[j+1]);
      		}
    	}
  	}		
}

void rev_arr(int id_arr[],int n)
{
    //reversing the array
	int temp,start=0,end=n-1;
    while (start < end)
    {	
        temp = id_arr[start];  
        id_arr[start] = id_arr[end];
        id_arr[end] = temp;
        start++;
        end--;
    }   
}

//Displaying the record after sorting
void print_rec(int id_arr[], int n)
{
	FILE *data;
	data = fopen("employeeRecord.txt","r");
	int i,c=1;
	for(i=0;i<n;i++){
    	rewind(data);
		while(fread(&details,sizeof(details),1,data)==size)
		{
			if(details.id==id_arr[i])
			{
				printf("\n\n\n\tEMPLOYEE %d RECORD IS......",c++);
				printf("\n\n\tEMPLOYEE ID:\t%d",details.id);
				printf("\n\n\tEMPLOYEE NAME:\t%s",details.name);
				printf("\n\n\tEMPLOYEE POSITION:\t%s",details.title);
				printf("\n\n\tEMPLOYEE AGE:\t%d",details.age);
				printf("\n\n\tEMPLOYEE GENDER:\t%c",details.gender);
				printf("\n\n\tEMPLOYEE QUALIFICATIONS:\t%s",details.qualification);
				printf("\n\n\tEMPLOYEE WORK EXPERIENCE:\t%d",details.exp);
				printf("\n\n\tEMLOYEE SALARY:\t%ld",details.salary);
				printf("\n\n\tEMPLOYEE PHONE NUMBER:\t%lld",details.ph_no);
				printf("\n\n\tPROGRAMMING LANGUAGES KNOWN:\t%s",details.prog_lang);	
				printf("\n\n\tLANGUAGES KNOWN:\t%s",details.lang);
				break;
			}
		}
	}
	fclose(data);	
}

//Sorting the employee
void sort_employee()
{
	system("cls");
	system("color 0E");
	FILE *data;
	data = fopen("employeeRecord.txt","r");
	if(data == NULL)
	{
		printf("\n\n\tError in Opening File");
		exit(0);
	}
	
	int id_arr[50],sal_arr[50],exp_arr[50],dummy[50];
	char nam_arr[50][50];
	int tot_rec=0;
	
	while(fread(&details,sizeof(details),size,data)==size) 
    {
    	sal_arr[tot_rec]=details.salary;
    	id_arr[tot_rec]=details.id;
    	exp_arr[tot_rec]=details.exp;
    	strcpy(nam_arr[tot_rec],details.name);
        tot_rec++;
    }
    fclose(data);
	int choice;   
	printf("\n\n\t1. To Sort the list based on Employee ID");
	printf("\n\n\t2. To Sort the list based on Salary");
	printf("\n\n\t3. To Sort the list based on Experience");
	printf("\n\n\t4. To Sort the list based on Names");
	printf("\n\n\tYour Choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 ://sort id wise

            printf("\n\n\t1. To Sort the list in Ascending order\n\n\t2. To Sort the list based in Descending order\n\n\tYour Choice : ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1 ://sort name ascending
                    bubblesort(id_arr,dummy,tot_rec);
					print_rec(id_arr,tot_rec);         
                    break;
								
				case 2 ://sort name descending
                    bubblesort(id_arr,dummy,tot_rec);
					//reversing the array
					rev_arr(id_arr,tot_rec);
					print_rec(id_arr,tot_rec);
                    break;
                        
                default : 
					printf("\n\n\tInvalid entry");
            }
            break;
        case 2 : //sort salary wise
    		printf("\n\n\t1. To Sort the list in Ascending order\n\n\t2. To Sort the list based in Descending order\n\n\tYour Choice : ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1 ://sort name ascending
                    bubblesort(sal_arr,id_arr,tot_rec);
					print_rec(id_arr,tot_rec);         
                    break;		
				case 2 ://sort name descending
                    bubblesort(sal_arr,id_arr,tot_rec);
                    rev_arr(id_arr,tot_rec);
					print_rec(id_arr,tot_rec);        
                    break;
                default : 
					printf("\n\n\tInvalid entry");
            }
    		break;
        case 3 : //sort experience wise
    		printf("\n\n\t1. To Sort the list in Ascending order\n\n\t2. To Sort the list based in Descending order\n\n\tYour Choice : ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1 ://sort name ascending
                    bubblesort(exp_arr,id_arr,tot_rec);
					print_rec(id_arr,tot_rec);          
                    break;		
				case 2 ://sort name descending
                    bubblesort(exp_arr,id_arr,tot_rec);
                    rev_arr(id_arr,tot_rec);
					print_rec(id_arr,tot_rec);         
                    break;
                default : 
					printf("\n\n\tInvalid entry");
            }
    		break;
        case 4 : //sort Name wise
    		printf("\n\n\t1. To Sort the list in Ascending order\n\n\t2. To Sort the list based in Descending order\n\n\tYour Choice : ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1 ://sort name ascending	
                    sort_name(id_arr,nam_arr,tot_rec);
					print_rec(id_arr,tot_rec);
                    break;		
				case 2 ://sort name descending
                    sort_name(id_arr,nam_arr,tot_rec); 
					rev_arr(id_arr,tot_rec);
					print_rec(id_arr,tot_rec);       
                    break;
                default : 
					printf("\n\n\tInvalid entry");
            }
    		break;

        default : 
			printf("\n\n\tInvalid entry");
    }
    
}

//Function to exit
void exiting()
{
	system("cls");
	system("color 0A");
	printf("\n\tExiting the Application\n");
	loading(3000);
	printf("\n\tThanks for Using the Application");
	exit(0);
}

//Displaying the menu
void menu()
{
	int menu_choice,x=1;
	do
	{
		header();
		printf("\n \t 1.Add New Employee");
		printf("\n \t 2.Display all Employee's Record");
		printf("\n \t 3.Update Employee's Record");
		printf("\n \t 4.Search an Employee Record");
		printf("\n \t 5.Delete an Employee Record");
		printf("\n \t 6.Sort Employee details");
		printf("\n \t 7.Exit the Application");
		printf("\n\n \tINPUT:\t"); 
		scanf("%d",&menu_choice);
		switch(menu_choice)
		{
			case 1:
					add_employee();
					break;
			case 2:
					display_details();
					break;
			case 3:
					update_details();
					break;
			case 4:
					search_employee();
					break;
			case 5:
					delete_employee();
					break;
			case 6:
					sort_employee();
					break;
			case 7:
					exiting();
					break;
			default:
					printf("\n\n\tInvalid Input. Try again\n");
					loading(1500);
					system("cls");				
		}
		printf("\n\n\tDo You Want To Continue? Yes-1 / No-0 ");
		scanf("%d",&x);		
	}while(x);	
	exiting();
}

//Login 
int main()
{
	system("color 03");
    int result;
    char password[20];
    int main_exit1;
    char code[200] = "SPMS";
	header();
	printf("\n\n\n\t\t\t\t\t\tADMIN LOGIN ");
    printf("\n\n\n\t\t ENTER THE PASSWORD TO LOGIN: ");
    scanf(" %s",password);
    result = strcmp(password,code);
    //check whether given password to unlock program is right or wrong
    if (result == 0)
    {
        printf(" \n\t PASSWORD MATCH!");
        printf(" \n\t PLEASE WAIT LOADING: ");
        loading(2000);
        menu();
    }
    else 
	{
        system("cls");
        printf(" \n\n\tINVALID PASSWORD");
        printf(" \n\n\t\tenter 0 to login again and 1 to exit: ");
        scanf(" %d",&main_exit1);
        if(main_exit1 == 0)
        {
            system("cls");
            main();
        }
        if(main_exit1 == 1)
        {
            exiting();
        }
    }
    return 0;
}
