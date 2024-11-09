#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<windows.h>

typedef struct marks
{
char sub[4][10];
double cat1[4],cat2[4],fat[4];
} marks;

typedef struct leave
{
char frm[11],tt[11];
char from[11],to[11],reason[200];
bool permission,applied;
} leave;

typedef struct profile
{
char father[50], mother[50], address[100], phone[15], blood[4], email[50], name[50];
} profile;


typedef struct student
{
profile p;
marks m;
leave l;
char reg[20];
int room_no;
char password[20];
char reason[50];
//student* next;
} student;


typedef struct node node; struct node
{
student x;
node* next;
};

typedef struct faculty
{
char fac_no[20];
char sub_code[10];
char name[50];
char password[20];
} faculty;


typedef struct nodef nodef; struct nodef
{
faculty y;
nodef *next;
};

typedef struct warden
{
char ward_no[20];
char name[20];
char password[20];
} warden;


typedef struct nodew nodew; struct nodew
{
warden z;
nodew* next;
};

typedef struct admin
{
char admin_no[20];
char name[20];
char password[20];
} admin;


typedef struct nodea nodea; struct nodea
{
admin m;
nodea *next;
};


/*	function decls	*/
void a_login();
void w_login();
void s_login();
void f_login();
void add_student();
void get_admin(admin* );
void extract_to(student s[]);
int studentid[50] = { -1 };
int s_count = 0;

node* top = NULL;
nodef* topf = NULL;
nodew* topw = NULL;
nodea *topa = NULL;

marks default_marks1 =
{
.sub[0] = "MAT2001",
.sub[1] = "CSE2004",
.sub[2] = "ECE2001",
.sub[3] = "BIT1020",
.cat1[0] = -1,
.cat1[1] = -1,
.cat1[2] = -1,
.cat1[3] = -1,
.cat2[0] = -1,
.cat2[1] = -1,
.cat2[2] = -1,
.cat2[3] = -1,
.fat[0] = -1,
.fat[1] = -1,
.fat[2] = -1,
.fat[3] = -1
};

leave default_leave1 =
{
.permission = 0,
.applied = 0,
};


/*	struct marks impls	*/

void print_marks(marks* ptr, char a[]) //a contains teacher code if displaying for teacher
{
    int pos = -1; int i;
    if(strcmp(a,"Nil") != 0)
        {
            for(i = 0;i < 5; ++i)
            {
                if(strcmp(a, (ptr->sub)[i]) == 0)
                {
                    pos=i; break;
                }
            }
            if(pos!=-1)
                {
                    if((ptr->cat1)[pos] != -1)
                        {
                            printf("\n\t\t\t\tCAT-1 : "); printf("%f\n", (ptr->cat1)[pos]);
                        }
                    else
                        {
                            printf("\n\t\t\t\tCAT-1 : "); printf("Nil\n");
                        }
                    if((ptr->cat2)[pos] != -1)
                        {
                            printf("\n\t\t\t\tCAT-2 : "); printf("%f\n", (ptr->cat2)[pos]);
                        }
                    else
                        {
                            printf("\n\t\t\t\tCAT-2 : "); printf("Nil\n");
                        }
                    if((ptr->fat)[pos] != -1)
                        {
                            printf("\n\t\t\t\tFAT : "); printf("%f\n", (ptr->fat)[pos]);
                        }
                    else
                        {
                            printf("\n\n\t\t\t\tFAT : "); printf("Nil\n");
                        }
                    }
                else
                    printf("\n\n\t\t\t\tYou have entered the wrong subject code. Pls start from the beginning.\n");
            }
        else
        {
            for(i = 0; i < 4; ++i)
            {
                pos = i;
        printf("\n\t\t\t\t%s", (ptr->sub)[pos]);
        if((ptr->cat1)[pos] != -1){
            printf("\n\t\t\t\tCAT-1 : %f\n", (ptr->cat1)[pos]);
            }
        else
            printf("\n\t\t\t\tCAT-1 : Nil\n");

        if((ptr->cat2)[pos] != -1){
            printf("\n\t\t\t\tCAT-2 : %f\n", (ptr->cat2)[pos]);
        }
        else
            printf("\n\t\t\t\tCAT-2 : Nil\n");

        if((ptr->fat)[pos] != -1){
            printf("\n\t\t\t\tFAT : %f\n", (ptr->fat)[pos]);
        }
        else
            printf("\n\t\t\t\tFAT : Nil\n");
        }
    }
}

void enter_marks_m(char c[], marks* ptr) //for getting input from the teacher for the marks of a particular subject
{
    char code[10];
    int pos = -1;
    int i;
    strcpy(code,c);
    for(i=0;i<4;i++)
        {
            if(strcmp(code,(ptr->sub)[i]) == 0)
            {
                pos = i; break;
            }
        }
        if(pos>=0)
            {
                printf("\n\n\t\t\tEnter the marks for subject ");
                printf("%s ", (ptr->sub)[pos]);

                int n;
                printf("\n\t\t\t1:CAT 1\t\t2:CAT 2\t\t3:FAT\n");
                printf("\n\n\t\t\tEnter your option : ");
                scanf("%d", &n);
                switch(n)
                {
                    case 1:
                        printf("\n\t\t\tEnter CAT-1 marks : ");
                        scanf("%lf",&((ptr->cat1)[pos]));
                        if((ptr->cat1)[pos]>50.00 || (ptr->cat1)[pos]<0.00){
                                (ptr->cat1)[pos] = -1;
                                printf("\n\t\t\tCAT-1 marks must be between 0 and 50");
                        }
                        printf("\n");
                        break;
                    case 2:
                        printf("\n\t\t\tEnter CAT-2 marks : ");
                        scanf("%lf", &((ptr->cat2)[pos]));
                        if((ptr->cat2)[pos] > 50.00 || (ptr->cat2)[pos] < 0.00){
                                (ptr->cat2)[pos] = -1;
                                printf("\n\t\t\tCAT-2 marks must be between 0 and 50");
                        }
                        printf("\n");
                        break;


                   case 3:
                       printf("\n\t\t\tEnter FAT marks : ");
                       scanf("%lf", &((ptr->fat)[pos]));
                       if((ptr->fat)[pos]>100.00 || (ptr->fat)[pos]<0.00){
                            (ptr->fat)[pos]=-1;
                            printf("\n\t\t\tFAT marks must be between 0 and 100");
                        }
                        printf("\n");
                        break;

                    default:
                        printf("\n\n\t\t\tYou have entered the wrong option. Pls start from the beginning.\n");
                        break;
                }

                system("cls");
        }
        else
            {
                printf("You have entered the wrong option. Pls start from the beginning.\n");
            }
}


void update_student(student* ptr)
{
    FILE* student_fp = fopen("student.dat", "r+");
    student s;
    int sz=sizeof(student);
    int back_size = -1 * (sz);
    do
        {
            fread(&s, sz, 1, student_fp);
        }while(strcmp(ptr->reg, s.reg));

        printf("\n\nOutside do while\n\n");
        fseek(student_fp, back_size, SEEK_CUR);
        fwrite(ptr, sz, 1, student_fp);
        fseek(student_fp, 0, SEEK_SET);
        fclose(student_fp);
}

bool s_search(int a[],int n, int e)
{
    int i = 0;
    for(i = 0; i < n; i++)
        {
            if(a[i] == e)
            {
                return 1;
            }
        }
return 0;
}

void extract_to(student s[])
{
    FILE* student_fp = fopen("student.dat", "r"); int i = 0;
    while(fread(&s[i], sizeof(student), 1, student_fp))
        {
            if(s_search(studentid,50,s[i].room_no))
            {}
            else
            {
                i++;
            }
            studentid[s_count++] = s[i].room_no;
            node* temp;
            temp = malloc(sizeof(node));
            temp->x = s[i];
            temp->next = top; top = temp;
        }
fclose(student_fp);
}

bool isLeap(int year)
{
    return (((year%4==0) && (year%100!=0)) ||(year%400==0));
}

bool check(char fr[])
{
    int d, m, y;
    d=((fr[0]-48)*10)+(fr[1]-48);
    m=((fr[3]-48)*10)+(fr[4]-48);
    y=((fr[6]-48)*1000)+((fr[7]-48)*100)+((fr[8]-48)*10)+(fr[9]-48);
    if (y > 9999 || y < 1800)
        return 0;

    if (m < 1 || m > 12)
        return 0;

    if (d < 1 || d > 31)
        return 0;

    if (m == 2)
    {
        if (isLeap(y))
            return (d <= 29);
        else
            return (d <= 28);
    }

    if (m==4 || m==6 || m==9 || m==11)
        return (d <= 30);

    return 1;
}



bool check_duration(char fr[], char to[])
{

    int dayf, dayt, mf, mt;
    bool chk = 1;
    dayf = ((fr[0]-48)*10)+(fr[1]-48);
    dayt = ((to[0]-48)*10)+(to[1]-48);
    mf = ((fr[3]-48)*10)+(fr[4]-48);
    mt = ((to[3]-48)*10)+(to[4]-48);
    if(mf == mt)
        {
            if(dayf > dayt)
            chk = 0;
        }
    if(mt < mf)
        chk = 0;
    return chk;
}

bool find(char from[], char to[])
{
    if((check(from) == 1)&&(check(to) == 1)&&(check_duration(from,to) == 1))
        {
            return 1;
        }
    return 0;
}

void apply_leave(int n, student* ptr)
{
    char date1[11]; char temp[3],yr[5];
    char date2[11];
    int fd,fm,fy,td,tm,ty;
    if(n==1)
        {
            ptr->l.permission = 0;
            printf("\n\t\t\t\t	Enter from date(dd)	: ");
            scanf("%s",temp);

            strcpy(date1,temp);
            strcat(date1,"-");
            printf("\n\t\t\t\t	Enter from month(mm) : ");
            scanf("%s",temp);
            strcat(date1,temp);
            strcat(date1,"-");
            printf("\n\t\t\t\t	Enter from year(yyyy) : ");
            scanf("%s", yr);
            strcat(date1,yr);
            strcpy(ptr->l.from,date1);
            printf("\n\n\t\t\t\t	From date : %s\n", date1);
            printf("\n\t\t\t\t	Enter to date(dd)	: ");
            scanf("%s",temp);




            strcpy(date2,temp); strcat(date2,"-");
            printf("\n\t\t\t\t	Enter to month(mm)	: ");
            scanf("%s",temp);
            strcat(date2,temp);
            strcat(date2,"-");
            printf("\n\t\t\t\t	Enter to year(yyyy)	: ");
            scanf("%s",yr);
            strcat(date2,yr);
            strcpy(ptr->l.to,date2);
            printf("\n\n\t\t\t\t	To date : %s\n", date2);


            fd=((ptr->l.from[0]-48)*10)+(ptr->l.from[1]-48);
            fm=((ptr->l.from[3]-48)*10)+(ptr->l.from[4]-48);
            fy=((ptr->l.from[6]-48)*1000)+((ptr->l.from[7]-48)*100)+((ptr->l.from[8]-48)*10)+(ptr->l.from[9]-48);
            td=((ptr->l.to[0]-48)*10)+(ptr->l.to[1]-48);
            tm=((ptr->l.to[3]-48)*10)+(ptr->l.to[4]-48);
            ty=((ptr->l.to[6]-48)*1000)+((ptr->l.to[7]-48)*100)+((ptr->l.to[8]- 48)*10)+(ptr->l.to[9]-48);

            if(check(ptr->l.from)==0)
            {
                printf("\n\n\t\t\tWrong input for from date"); return;
            }

            if(check(ptr->l.to)==0)
            {
                printf("\n\n\t\t\tWrong input for to date"); return;
            }

            if(find(ptr->l.from, ptr->l.to)==1)
            {

                printf("\n\t\t\t\t	Enter Reason for Leave : ");
                fflush(stdin);
                scanf("%[^\n]s", ptr->reason);
                fflush(stdin);
                ptr->l.applied = 1;
                printf("\n\n\t\t\tLeave Saved.\n");
            }

            else
            {
                printf("\n\n\t\t\tFrom date cannot be greater than to date");
            return;
            }
        }
    if((find(ptr->l.from ,ptr->l.to)==1))
        {
            printf("\n\n\t\t\tReason	: ");
            printf("%s\n",ptr->reason);
            printf("\n\n\t\t\tLeave status : ");
            printf("%s\n",((ptr->l.permission!=1)?"Not Approved Yet":"Approved"));
        }
    else
        {
            printf("\n\t\t\tLeave not yet appplied\n");
        }
}

void get_warden(warden* ptr)
{

    printf("\n\t\t\t\t	Warden no : ");
    scanf("%s",ptr->ward_no);
    printf("\n");
    printf("\n\t\t\t\t	Name	: ");
    scanf("%s",ptr->name);
    printf("\n");
    printf("\n\t\t\t\t	Password : "); scanf("%s",ptr->password); printf("\n");
}

void print_warden(warden* ptr)
{
    printf("\n\t\t\t\t	Warden No :\t");
    printf("%s\n", ptr->ward_no);
    printf("\n\t\t\t\t	Name	:\t");
    printf("%s\n", ptr->name);
}


void change_password_w(warden* ptr)
{
    char current_pass[20]; char new_pass[20];
    printf("\n\t\t\t\t	Enter current password : ");
    scanf("%s", current_pass);
    printf("\n\t\t\t\t	Enter the new password : "); scanf("%s", new_pass);
    if(strcmp(current_pass, ptr->password) == 0)
    {
        if(strcmp(new_pass, ptr->password) == 0)
        {
            printf("\n\t\t\tYou have entered the Same Password.\n");
            return;
        }
    strcpy(ptr->password, new_pass);
    printf("\n\t\t\tPassword Saved.\n");
    system("pause");
    }
    else
    {
        printf("\n\t\t\tPassword does not match\n");
        system("pause");
    }
}

void warden_search()
{
    node* temp = top;
    while(temp)
    {
        printf("\n		\n");
        printf("\n\t\t\t\t	Reg: ");
        printf("%s\n", temp->x.reg);
        printf("\n\t\t\t\tName : ");
        printf("%s\n", temp->x.p.name);
        printf("\n\t\t\t\tRoom No : ");
        printf("%d\n", temp->x.room_no);
        temp = temp->next;
    }
    printf("\n	\n");
}

void approve_leave()
{
    char l;
    int flag = 0;
    node* temp_s = top;
    while(temp_s)
    {
        if((temp_s->x).l.applied)
        {
            flag = 1;
            printf("\n\n\t\t\t%s (reg no : %s) has applied for leave.\n", (temp_s->x).p.name, (temp_s->x).reg);
            apply_leave(0, &((temp_s->x))); printf("\n\n\t\t\tDo you want to approve the leave? (y/n) \n");
            printf("\n\n\t\t\t");
            fflush(stdin);
            scanf("%c", &l);
            fflush(stdin);

            (temp_s->x).l.applied = 0;
            (temp_s->x).l.permission = 0;
            if(l == 'y')
            {
                (temp_s->x).l.permission = 1;
            }
            update_student(&(temp_s->x));
        }
    temp_s = temp_s->next;
    }
    if(!flag)
    {
        printf("\n\n\t\t\t\t	No leave applications yet\n"); system("pause");
    }
}

void update_war(warden* ptr)
{
    FILE* warden_fp = fopen("warden.dat", "r+");
    warden w;
    int sz=sizeof(warden);
    int back_size = -1 * (sz);
    do{
        fread(&w, sz, 1, warden_fp);
    }while(strcmp(ptr->ward_no, w.ward_no));
    printf("\n\nOutside do while\n\n");
    fseek(warden_fp, back_size, SEEK_CUR);
    fwrite(ptr, sz, 1, warden_fp);
    fseek(warden_fp, 0, SEEK_SET);
    fclose(warden_fp);
}

void w_login()
{
    char r[20];
    char p[20];
    warden w;
    printf("\n\t\t\t\tWarden no : ");
    scanf("%s", r);
    nodew* tempw;
    FILE* warden_fp = fopen("warden.dat", "r");
    while(fread(&w, sizeof(warden), 1, warden_fp))
    {
    tempw = malloc(sizeof(nodew));
    tempw->z = w;
    tempw->next = topw;
    topw = tempw;
    fclose(warden_fp);
    }
    while(tempw)
    {
        if(strcmp(r,(tempw->z).ward_no) == 0)
        {
            w = tempw->z; break;
        }
        tempw = tempw->next;
    }
    printf("\n\t\t\t\tPassword : "); scanf("%s", p);
    if(strcmp(p,w.password) != 0)
    {
        printf("\n\n\t\t\t");
        printf("Wrong Reg no/Password combination!!\n");
        printf("\n\n\t\t\t\n");
        system("pause");
        return;
    }
    char ch='0';
    while(ch!='5')
    {
    system("cls");
    printf("\n\n\t\t\t\t\t\t****************\n\n");
    printf("\t\t\t\t\t	WELCOME %s", w.name);
    printf("\n\n\t\t\t\t\t\t****************\n\n\n");
    printf("\t\t		\n");
    printf("\n\n\t\t\t\t	1\t:\tVIEW PROFILE\n\n\t\t\t\t 2\t:\tAPPROVE LEAVE\n\n\t\t\t\t	3\t:\tVIEW STUDENT DETAILS\n\n\t\t\t\t	4\t:\tCHANGE PASSWORD\n\n\t\t\t\t 5\t:\tLOGOUT\n\n\n");
    printf("\t\t\n");
    printf("\n\t\t\tEnter Your Choice : ");
    scanf("%c", &ch);
    switch(ch)
    {
    case '1':
        printf("\n"); print_warden(&w);
        printf("\n\n\t\t\t\n");
        system("pause");
        break;

    case '2':
        printf("\n");
        approve_leave();
        printf("\n\n\t\t\t");
        break;

    case '3':
        printf("\n");
        warden_search();
        printf("\n\n\t\t\t\n");
        system("pause");
        break;

    case '4':
        printf("\n");
        //change_password_w(&w);
        {
        char current_pass[20]; char new_pass[20];
        printf("\n\t\t\t\t	Enter current password : ");
        scanf("%s", current_pass);
        printf("\n\t\t\t\t	Enter the new password : ");
        scanf("%s", new_pass);
        if(strcmp(current_pass, (tempw->z).password) == 0)
        {
            if(strcmp(new_pass, (tempw->z).password) == 0)
            {
                printf("\n\t\t\tYou have entered the Same Password.\n");
                return;
            }
            strcpy((tempw->z).password, new_pass);
            printf("\n\t\t\tPassword Saved.\n");
            update_war(&(tempw->z));
            system("pause");
        }
        else
        {
            printf("\n\t\t\tPassword does not match\n");
            system("pause");
        }
        }
        printf("\n\n\t\t\t\n");
        system("pause");
        break;

    case '5':
        break;

    default: ;
    }
    }
}

void get_faculty(faculty* ptr)
{
    printf("\n\t\t\t\t	Faculty No	: ");
    scanf("%s",ptr->fac_no);
    printf("\n\t\t\t\t	Subject Code : ");
    scanf("%s", ptr->sub_code);
    printf("\n\t\t\t\t	Faculty Name : ");
    scanf("%s", ptr->name);
    printf("\n\t\t\t\t	Password	: ");
    scanf("%s", ptr->password);
}

void print_faculty(faculty* ptr)
{
    printf("\n\t\t\t\t	Faculty No	: ");
    printf("%s\n", ptr->fac_no);
    printf("\n\t\t\t\t	Subject Code : ");
    printf("%s\n", ptr->sub_code);
    printf("\n\t\t\t\t	Faculty Name : ");
    printf("%s\n", ptr->name);
}

void change_password_f(faculty* ptr)
{
    char current_pass[20];
    char new_pass[20];
    printf("\n\t\t\t\t	Enter current password : ");
    scanf("%s", current_pass);
    printf("\n\t\t\t\t	Enter the new password : ");
    scanf("%s", new_pass);
    if(strcmp(current_pass, ptr->password) == 0)
    {
        if(strcmp(new_pass, ptr->password) == 0)
        {
            printf("\n\t\t\tYou have entered the same password.\n");
            return;
        }
        strcpy(ptr->password,new_pass);
        printf("\n\t\t\tPassword Saved.\n");
        system("pause");
    }
    else
    {
        printf("\n\t\t\tPassword does not match\n");
        system("pause");
    }
}

void view_marks(faculty* ptr)
{
    node* temp = top; while(temp)
    {
        printf("\n\t\t\tReg No : %s\n", temp->x.reg);
        print_marks(&(temp->x.m), ptr->sub_code);
        temp = temp->next;
    }
}

void enter_marks(faculty* ptr)
{
    int i;
    // extract_to
    student s[9];
    for(i = 0; i < 9; ++i)
    {
        s[i].l = default_leave1;
        s[i].m = default_marks1;
    }
    node* temp;
    char reg_no[20] = "0";
    while(strcmp(reg_no,"-1") != 0)
    {
        view_marks(ptr);
        printf("\t\t	\n");
        printf("\n\n\t\t\tEnter Reg No of the Student to Enter Marks or -1 to Quit : ");
        scanf("%s", reg_no);
        temp = top;
        while(temp){
            if(strcmp(reg_no,temp->x.reg)==0)
            {
                enter_marks_m(ptr->sub_code, &((temp->x).m)); break;
            }
            temp = temp->next;
        }
    }
    student s_temp;
    FILE* student_fp = fopen("student.dat", "w");
    int offset = sizeof(student);
    int offset1 = offset;
    node* temp1 = top;
    while(temp1)
    {

    s_temp = temp1->x;
    fwrite(&s_temp, sizeof(s_temp), 1, student_fp); fseek(student_fp, offset, SEEK_SET);
    offset += offset1; temp1 = temp1->next;
    }
fseek(student_fp, 0, SEEK_SET); fclose(student_fp);
}

void update_fac(faculty* ptr)
{

    FILE* faculty_fp = fopen("faculty.dat", "r+"); faculty f;
    int sz=sizeof(faculty);


    int back_size = -1 * (sz);
    do
    {
        fread(&f, sz, 1, faculty_fp);
    }while(strcmp(ptr->fac_no, f.fac_no));

    printf("\n\nOutside do while\n\n");
    fseek(faculty_fp, back_size, SEEK_CUR);
    fwrite(ptr, sz, 1, faculty_fp);
    fseek(faculty_fp, 0, SEEK_SET);
    fclose(faculty_fp);
}

void f_login()
{
        char p[20],r[20];
        faculty f;
        printf("\n\t\t\t\tFaculty no : ");
        scanf("%s", r);
        nodef* tempf;
        FILE* faculty_fp = fopen("faculty.dat", "r");
        while(fread(&f, sizeof(faculty), 1, faculty_fp))
        {
        tempf = malloc(sizeof(nodef)); tempf->y = f;
        tempf->next = topf; topf = tempf;
        }
        fclose(faculty_fp); while(tempf)
        {
        if(strcmp(r,(tempf->y).fac_no)==0)
        {
        f = (tempf->y); break;
        }
        tempf = tempf->next;
        }
        printf("\n\t\t\t\tPassword	: ");
        scanf("%s", p);
        if(strcmp(p,f.password)!=0)
        {
        printf("\n\t\t\tWrong Reg no/Password combination!!\n"); printf("\n\t\t\t\n");
        system("pause");
        return;
        }
        char ch='0'; while(ch!='5')
        {
        system("cls");
        printf("\n\n\t\t\t\t\t*******************\n\n");
        printf("\t\t\t\t	WELCOME %s", f.name);
        printf("\n\n\t\t\t\t\t*******************\n\n");
        printf("\t\t\n");
        printf("\n\n\t\t\t\t	1\t:\tVIEW PROFILE\n\n\t\t\t\t	2\t:\tVIEW STUDENT MARKS\n\n\t\t\t\t 3\t:\tENTER STUDENT MARKS\n\n\t\t\t\t	4\t:\tCHANGE PASSWORD\n\n\t\t\t\t	5\t:\tLOGOUT\n\n\t\t\t\t\n");
        printf("\t\t\n");
        printf("\n\t\t\tEnter Your Choice : "); scanf("%c", &ch);
        switch(ch)
        {
        case '1':
            printf("\n");
            print_faculty(&f);
            printf("\n\t\t\t\n");
            system("pause");
            break;
        case '2':
            printf("\n");
            view_marks(&f);
            printf("\n\t\t\t\n");
            system("pause");
            break;
        case '3':
            printf("\n");
            enter_marks(&(tempf->y));
            update_fac(&(tempf->y));
            printf("\n\t\t\t");
            break;
        case '4':
            printf("\n");
            {
            char current_pass[20];
            char new_pass[20];
            printf("\n\t\t\t\t	Enter current password : ");
            scanf("%s", current_pass);
            printf("\n\t\t\t\t	Enter the new password : ");
            scanf("%s", new_pass);
            if(strcmp(current_pass, (tempf->y).password) == 0)
            {
                if(strcmp(new_pass, (tempf->y).password) == 0)
                    {
                        printf("\n\t\t\tYou have entered the same password.\n");
                        return;
                    }
            strcpy((tempf->y).password,new_pass);
            printf("\n\t\t\tPassword Saved.\n");
            update_fac(&(tempf->y));
            system("pause");
            }
            else
            {
                printf("\n\t\t\tPassword does not match\n");
            }
        }
        nodef* tempf1 = topf; int count = 0;
        while(tempf1)
        {
            count += 1;
            tempf1 = tempf1->next;
        }
        printf("\n\nNum of nodes after pwd change : %d\n\n", count);
        printf("\n\t\t\t");
        break;

        case '5':
            break;
        default: ;
        }
    }
}



void get_profile(profile* ptr)
{
    char temp_name[50], temp_phone[15], temp_blood[4], temp_email[50], temp_father[50], temp_mother[50];
    int r = 1;
    int p;
    printf("\n\t\t\tEnter details of the Student mentioned as below, in the same order\n");
    printf("\n\t\t\tStudent's name, Father's name, Mother's name, Address, phone, blood group, Email-ID\n");
    //Student Name
    printf("\n\t\t\t\t	");
    fflush(stdin);
    scanf("%[^\n]s", temp_name);
    fflush(stdin);
    for(p = 0;temp_name[p] != '\0'; ++p)
    {
        if(!isalpha(temp_name[p]))
        {
            r = 0;
            printf("\n\t\t\t");
            printf("Invalid Name format\n");
        }
        if(r == 0)
        {
            return;
        }
    }
    strcpy(ptr->name,temp_name);

    //Father Name
    printf("\n\t\t\t\t	");
    fflush(stdin);
    scanf("%[^\n]s", temp_father);
    fflush(stdin);
    for(p = 0; temp_father[p] != '\0'; ++p)
    {
        if(!isalpha(temp_father[p]))
        {
            r = 0;
            printf("\n\t\t\t");
            printf("Invalid Name format\n");
        }
        if(r==0)
        {
            return;
        }
    }
    strcpy(ptr->father,temp_father);

    //Mother Name
    printf("\n\t\t\t\t	");
    fflush(stdin);
    scanf("%[^\n]s", temp_mother);
    fflush(stdin);
    for(p = 0; temp_mother[p] != '\0'; ++p)
    {
        if(!isalpha(temp_mother[p]))
        {
            r = 0;
            printf("\n\t\t\t");
            printf("Invalid Name format\n");
        }
        if(r == 0)
        {
            return;
        }
    }
    strcpy(ptr->mother,temp_mother);

    //Address
    printf("\n\t\t\t\t	");
    fflush(stdin); scanf("%[^\n]s", ptr->address);
    fflush(stdin);

    //Phone No
    printf("\n\t\t\t\t	");
    fflush(stdin);
    scanf("%[^\n]s", temp_phone);
    fflush(stdin);

    for(p = 0; temp_phone[p] != '\0'; ++p)
    {
        if(!isdigit(temp_phone[p]))
        {
            r = 0;
            printf("\n\t\t\t");
            printf("Invalid Phone format\n");
        }
        if(r == 0)
        {
            return;
        }
    }
    strcpy(ptr->phone,temp_phone);

    //Blood Group
    printf("\n\t\t\t\t	");
    fflush(stdin);
    scanf("%[^\n]s", temp_blood);
    fflush(stdin);
    if((strcmp(temp_blood,"A-") != 0 && strcmp(temp_blood,"B-") != 0 && strcmp(temp_blood,"A+") != 0 && strcmp(temp_blood,"B+") !=0 && strcmp(temp_blood,"AB+") != 0 && strcmp(temp_blood,"AB-") != 0 && strcmp(temp_blood,"O+") != 0 && strcmp(temp_blood,"O+") != 0 && strcmp(temp_blood,"Hh") != 0))
    {
        printf("\n\t\t\t");
        printf("Invalid Blood Group\n");
        return;
    }
    strcpy(ptr->blood,temp_blood);

    //Email
    printf("\n\t\t\t\t	");
    //cin.getline(temp_email,50);
    fflush(stdin);
    scanf("%[^\n]s", temp_email);
    strcpy(ptr->email,temp_email);
    //If No Error Add
    if(r == 1)
    {
        printf("\n\n\t\t\t");
        printf("Student Added Successfully\n");
        system("pause");
    }
}


void print_profile(profile* ptr) // to print the details
{
    printf("\n\t\t\t\t	Student's name : ");
    printf("%s\n",ptr->name);
    printf("\n\t\t\t\t	Father's name : ");
    printf("%s\n",ptr->father);
    printf("\n\t\t\t\t	Mother's name : ");
    printf("%s\n",ptr->mother);
    printf("\n\t\t\t\t	Address	: ");
    printf("%s\n",ptr->address);
    printf("\n\t\t\t\t	Phone Number	: ");
    printf("%s\n",ptr->phone);
    printf("\n\t\t\t\t	Blood group		: ");
    printf("%s\n",ptr->blood);
    printf("\n\t\t\t\t	Email-ID	: ");
    printf("%s\n",ptr->email);
}



void modify_profile(student* ptr)
{
    int p,q;
    char a[50];
    char detail[20];
    printf("\n\t\t");
    printf("Enter the detail name you want to modify as given in the profile : ");
    fflush(stdin);
    scanf("%[^\n]s", detail);
    fflush(stdin);
    printf("\n\t\tEnter the changes you want to make : ");
    //cin.ignore();
    fflush(stdin);
    scanf("%[^\n]s", a);
    fflush(stdin);
    printf("\n");
    if(strcmp(detail,"Father's name")==0)
    {
        int r=1;
        for(p=0;a[p]!='\0';++p)
        {
            if(!isalpha(a[p]))
            {
                r = 0;
                printf("\n\t\t");
                printf("Invalid Name Format\n");
                break;
            }
        }
        if(r==1)
        {
            strcpy(ptr->p.father,a);
            printf("\n\t\t");
            printf("Changes Saved.\n");
        }
    }
    else if(strcmp(detail,"Mother's name")==0)
    {
        int r = 1;
        for(p=0;a[p]!='\0';++p)
        {
            if(!isalpha(a[p]))
            {
                r = 0;
                printf("\n\t\t");
                printf("Invalid Name format\n");
                break;
            }
        }
        if(r==1)
        {
            strcpy(ptr->p.mother,a);
            printf("\n\t\t\t");
            printf("Changes Saved.\n");
        }
    }
    else if(strcmp(detail,"Student's name")==0)
    {
        int r = 1;
        for(p=0;a[p]!='\0';++p)
        {
            if(!isalpha(a[p]))
            {
                r = 0;
                printf("\n\t\t");
                printf("Invalid Name format.");
                break;
            }
        }

        if(r==1)
        {
            strcpy(ptr->p.name,a);
            printf("\n\t\t\t");
            printf("Changes Saved.\n");
        }
    }

    else if(strcmp(detail,"Address")==0)
    {
        strcpy(ptr->p.address,a);
        printf("\n\n\t\t\t");
        printf("Changes Saved.\n");
    }

    else if(strcmp(detail,"Phone Number")==0)
    {
        int z=1;
        for(q=0;a[q]!='\0';++q)
        {
            if(!isdigit(a[q]))
            {
                z = 0;
                printf("\n\t\t");
                printf("Invalid number\n");
                break;
            }
        }

        if(z==1)
        {
            strcpy(ptr->p.phone,a);
            printf("\n\n\t\t\t");
            printf("Changes Saved.\n");
        }
    }

    else if(strcmp(detail,"Blood group")==0)
    {
        if(strcmp(a,"A-")!=0 && strcmp(a,"B-")!=0 && strcmp(a,"A+")!=0 && strcmp(a,"B+")!=0 && strcmp(a,"AB+")!=0 && strcmp(a,"AB-")!=0 && strcmp(a,"O+")!=0 && strcmp(a,"O+")!=0 && strcmp(a,"Hh")!=0)
        {
            printf("\n\t\t");
            printf("Invalid Blood group\n");
        }

        else
        {
            strcpy(ptr->p.blood,a);
            printf("\n\n\t\t\t");
            printf("Changes Saved.\n");
        }
    }

    else if(strcmp(detail,"Email-ID")==0)
    {
        if(strlen(a)<9)
        {
            printf("\n\t\t");
            printf("Invalid Email format\n");
        }
        else
            {
                char b[50];
                int i;
                for(i=0;i<8;++i)
                {
                    b[i]=a[strlen(a)-i-1];
                }
                b[i]='\0';
                if(strcmp(b,"moc.zyx@")!=0)
                {
                    printf("\n\t\t");
                    printf("Invalid Email format.\n");
                }
                else
                {
                    strcpy(ptr->p.email,a);
                    printf("\n\n\t\t\t");
                    printf("Changes Saved.\n");
                }
            }
        }
    else
    {
        printf("\n\t\t");
        printf("Entered detail is not same as given in the profile.\n");
    }
}


void get_student(student* ptr)
{
    printf("\n\t\t\t\t	Reg No	: ");
    scanf("%s",ptr->reg);
    printf("\n\t\t\t\t	Password : ");
    scanf("%s",ptr->password);
    printf("\n\t\t\t\t	Room No : ");
    scanf("%d",&(ptr->room_no));
    get_profile(&(ptr->p));
}





void change_password(student* ptr)
{
    char current_pass[20];
    char new_pass[20];
    printf("\n\t\t\t\t	Enter current password : ");
    scanf("%s", current_pass);
    printf("\n\t\t\t\t	Enter the new password : ");
    scanf("%s", new_pass);
    if(strcmp(current_pass,ptr->password)==0)
    {
        if(strcmp(new_pass,ptr->password)==0)
            {
                printf("\n\t\t\tYou have entered the same password.\n");
                return;
            }
            strcpy(ptr->password,new_pass);
            printf("\n\t\t\tPassword Saved.\n");
            system("pause");
    }
    else
    {
        printf("\n\t\t\tPassword does not match\n");
        system("pause");
    }
}

void s_login()
{
    char r[20];
    char p[20],pos;
    student s1[9], s;
    int i;
    s.l = default_leave1;
    s.m = default_marks1;

    for(i = 0; i < 9; ++i)
    {
        s1[i].l = default_leave1;
        s1[i].m = default_marks1;
    }
    printf("\n\t\t\t\tReg No	: ");
    scanf("%s",r);
    extract_to(s1);
    node *temp = top;
    while(temp)
    {
        if(strcmp(r,temp->x.reg)==0)
        {
            s = temp->x; break;
        }
    temp=temp->next;
    }
    printf("\n\t\t\t\tPassword : "); scanf("%s",p);
    //printf("Entered pwd : %s\n", p);
    //printf("Actual pwd : %s\n", s.password);
    if(strcmp(p,s.password)!=0)
    {
        printf("\n\n\t\tWrong Reg no/Password combination!!\n");
        printf("\n\t\t\n");
        system("pause");
        return;
    }
    int ch=0;
    while(ch!=9)
    {
        system("cls"); printf("\n\n\t\t\t\t\t*******************\n\n");
        printf("\t\t\t\t	WELCOME %s", s.p.name);
        printf("\n\n\t\t\t\t\t*******************\n\n");
        printf("\t\t\n");
        printf("\n\n\t\t\t\t	1\t:\tVIEW PROFILE\n\n\t\t\t\t 2\t:\tMODIFY PROFILE\n\n\t\t\t\t	3\t:\tVIEW MARKS\n\n\t\t\t\t 4\t:\tAPPLY LEAVE\n\n\t\t\t\t	5\t:\tCHANGE PASSWORD\n\n\t\t\t\t 9\t:\tLOGOUT\n\n\t\t\t\t\n");
        printf("\t\t\n");
        printf("\n\t\t\tEnter Your Choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("\n");
                print_profile(&(s.p));
                printf("\n\n\t\t\t\n");
                system("pause");
                break;
            case 2:
                printf("\n");
                print_profile(&(s.p));
                printf("\n");
                modify_profile(&s);
                printf("\n\n\t\t\t");
                break;
            case 3:
                printf("\n");
                print_marks(&(s.m), "Nil");
                printf("\n\n\t\t\t\n"); system("pause");
                break;
            case 4:
                printf("\n");
                apply_leave(1, &s);
                printf("\n\n\t\t\t\n");
                system("pause");
                break;
            case 5:
                printf("\n");
                change_password(&s);
                printf("\n\n\t\t\t");
                break;
            default :
                break;
            }

        }
        temp->x = s;
        FILE* student_fp = fopen("student.dat", "w");
        temp = top;
        int offset = sizeof(student);
        int offset1 = offset;
        while(temp)
        {
            s = temp->x;
            fwrite(&s, sizeof(student), 1, student_fp);
            fseek(student_fp, offset, SEEK_SET);
            offset += offset1;
            temp = temp->next;
        }
        fseek(student_fp, 0, SEEK_SET); fclose(student_fp);
}




void get_admin(admin* ptr)
{
    printf("Admin no : ");
    scanf("%s", ptr->admin_no);
    printf("Name : ");
    scanf("%s", ptr->name);
    printf("password : ");
    scanf("%s", ptr->password);
}
void print_admin(admin* ptr)
{
    printf("\n\t\t\t\t	Admin No :\t");
    printf("%s",ptr->admin_no);
    printf("\n\t\t\t\t	Name	:\t");
    printf("%s\n", ptr->name);
}


void add_student()
{
    student s1;
    s1.l = default_leave1;
    s1.m = default_marks1;
    get_student(&s1);
    FILE* student_fp = fopen("student.dat", "a");
    fseek(student_fp, 0, SEEK_END);
    fwrite(&s1, sizeof(student), 1, student_fp);
    fseek(student_fp, 0, SEEK_SET);
    fclose(student_fp);
}


void add_faculty()
{
    faculty f;
    get_faculty(&f);
    FILE* faculty_fp = fopen("faculty.dat", "a");
    fseek(faculty_fp, 0, SEEK_END);
    fwrite(&f, sizeof(faculty), 1, faculty_fp);
    fseek(faculty_fp, 0, SEEK_SET);
    fclose(faculty_fp);
    printf("\n\n\t\t\t");
    printf("Faculty Added Successfully\n");
    system("pause");
}


void add_warden()
{
    warden w;
    get_warden(&w);
    FILE* warden_fp = fopen("warden.dat", "a");
    fseek(warden_fp, 0, SEEK_END);
    fwrite(&w, sizeof(warden), 1, warden_fp);
    fseek(warden_fp, 0, SEEK_SET);
    fclose(warden_fp);
    printf("\n\n\t\t\t");
    printf("Warden Added Successfully\n");
    system("pause");
}


void a_login()
{
    char r[20];
    char p[20];
    admin a;
    printf("\n\t\t\t\tAdmin No : ");
    scanf("%s",r);
    nodea *tempa;
    FILE* admin_fp = fopen("admin.dat", "r");
    while(fread(&a, sizeof(admin), 1, admin_fp))
    {
        tempa = malloc(sizeof(nodea));
        tempa->m = a;
        tempa->next = topa;
        topa = tempa;
    }
    fclose(admin_fp);
    while(tempa)
    {
        if(strcmp(r,tempa->m.admin_no)==0)
        {
            a = tempa->m; break;
        }
        tempa=tempa->next;
    }
    printf("\n\t\t\t\tPassword : ");
    scanf("%s",p);
    if(strcmp(p,a.password)!=0)
    {
        printf("\n\n\t\t\t");
        printf("Wrong Reg no/Password combination!!\n");
        printf("\n\n\t\t\t\n");
        system("pause");
        return;
    }
    char ch = '0';
    while(ch != '5')
    {
        system("cls"); printf("\n\n\t\t\t\t\t*******************\n\n");
        printf("\t\t\t\t	WELCOME %s", a.name);
        printf("\n\n\t\t\t\t\t*******************\n\n");
        printf("\t\t\n");
        printf("\n\n\t\t\t\t	1\t:\tVIEW PROFILE\n\n\t\t\t\t	2\t:\tADD STUDENT\n\n\t\t\t\t	3\t:\tADD FACULTY\n\n\t\t\t\t	4\t:\tADD WARDEN\n\n\t\t\t\t	5\t:\tLOGOUT\n\n\n");
        printf("\t\t	\n");
        printf("\n\t\t\tEnter Your Choice : ");
        scanf("%c", &ch);
        switch(ch)
        {
        case '1':

            printf("\n");
            print_admin(&a);
            printf("\n\n\t\t\t\n");
            system("pause");
            break;
        case '2':
            printf("\n");
            add_student();
            printf("\n\n\t\t\t");
            break;
        case '3':
            printf("\n");
            add_faculty();
            printf("\n\n\t\t\t");
            break;
        case '4':
            printf("\n");
            add_warden();
            printf("\n\n\t\t\t");
            break;
        default:
            break;
        }
    }
}

marks default_marks =
{
.sub[0] = "MAT2001",
.sub[1] = "CSE2004",
.sub[2] = "ECE2001",
.sub[3] = "BIT1020",

.cat1[0] = -1,
.cat1[1] = -1,
.cat1[2] = -1,
.cat1[3] = -1,

.cat2[0] = -1,
.cat2[1] = -1,
.cat2[2] = -1,
.cat2[3] = -1,

.fat[0] = -1,
.fat[1] = -1,
.fat[2] = -1,
.fat[3] = -1
};

leave default_leave =
{
.permission = 0,
.applied = 0,
};


int main()
{
int i;
student s[9];
for(i = 0; i < 9; ++i)
{
    s[i].m = default_marks;
    s[i].l = default_leave;
}
extract_to(s);
FILE* admin_fp = fopen("admin.dat", "w");
admin a;
get_admin(&a);
fwrite (&a, sizeof(admin), 1, admin_fp);
fclose(admin_fp);
char choice = '0';
while(choice != '5')
{
    system("cls"); printf("\n\n\t\t\t\t\t*****************\n\n");
    printf("\t\t\t\t	WELCOME");
    printf("\n\n\t\t\t\t\t*****************\n\n");
    printf("\t\t	\n");
    printf("\n\n\t\t\t\t	1\t:\tADMIN LOGIN\n\n\t\t\t\t 2\t:\tSTUDENT LOGIN\n\n\t\t\t\t	3\t:\tFACULTY LOGIN\n\n\t\t\t\t 4\t:\tWARDEN LOGIN\n\n\t\t\t\t	5\t:\tEXIT\n\n\n"); printf("\t\t		\n");
    printf("\n\t\t\t\tChoose Your Login Portal : ");
    scanf("%c", &choice);
    switch(choice)
    {
        case '1':
            system("cls"); printf("\n\n\t\t\t\t\t*****************\n\n"); printf("\t\t\t\t	ADMIN LOGIN"); printf("\n\n\t\t\t\t\t*****************\n\n");
            printf("\t\t\n\n");
            a_login();
            break;
        case '2':
            system("cls");
            printf("\n\n\t\t\t\t\t*****************\n\n");
            printf("\t\t\t\t	STUDENT LOGIN");
            printf("\n\n\t\t\t\t\t*****************\n\n");
            printf("\t\t\n\n");
            s_login();
            break;
        case '3':
            system("cls");
            printf("\n\n\t\t\t\t\t*****************\n\n");
            printf("\t\t\t\t	FACULTY LOGIN");
            printf("\n\n\t\t\t\t\t*****************\n\n");
            printf("\t\t	\n\n");
            f_login();
            system("cls");
            break;
        case '4':
            system("cls");
            printf("\n\n\t\t\t\t\t*****************\n\n");
            printf("\t\t\t\t	WARDEN LOGIN");
            printf("\n\n\t\t\t\t\t*****************\n\n");
            printf("\t\t	\n\n");
            w_login();
            system("cls");
            break;
        case '5':
            exit(0);
            break;
        default:
            break;
        }
    }
}
