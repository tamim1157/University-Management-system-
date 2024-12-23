/*
Project Name: University Management System (Project Olivia)
Student Roll: 1907031
Student Name: Naimur Rahman
*/

/*
Project Objetives ---

Create Teacher and student Structure

Admin Panel:
1.	Login using Function + File
2.	Create Teacher and student account using Function + ___
3.	Updating Teachers & students Information using Function +  Pointer + File
4.	Assigning courses to teacher using Function + File

Teacher’s Panel:
1.	Login using Function + File
2.	Provide class test marks using Function + File
3.	Find the student by the given first name using Function + File + pointer
4.	Count of Students using Function + File

Student’s Panel:
1.	Login using Function + File
2.	Check the class test marks using Function + File
*/

#include<stdio.h>
#include<string.h>

/* Declaring Global Structures For Admin, Teacher & Student */

struct admin
{
    char f_name[20];
    char l_name[20];
    char id[20];
    char pass[20];
    char repass[20];
};

struct teacher
{
    char f_name[20];
    char l_name[20];
    char id[20];
    char pass[20];
    char repass[20];
    char course[3][15];
};

struct student
{
    char f_name[20];
    char l_name[20];
    char id[20];
    char pass[20];
    char repass[20];
    char dept[20];
    int roll;
    char course[5][15];
    int mark[5];
};

/* Creating A Menu For Primary Choice */

void menu()
{
    system("cls");
    /* Used For Clearing Screen */
    int x;
    printf("******Welcome To Olivia's Panel Menu******\n\n");
    printf("Please, Choose Your Desired Place To Go ---\n");
    printf("1. Admin Panel\n");
    printf("2. Teachers Panel\n");
    printf("3. Students Panel\n\n");
    printf("Please Select Your Desired Move: ");
    fflush(stdin);
    /* Used To Clear The Garbage Values Left In Buffer Area */
    scanf("%d", &x);
    if(x==1){
        admin_login();
    }
    else if(x==2){
        teacher_login();
    }
    else if(x==3){
        student_login();
    }
    else{
        printf("Invalid Value Entered\n");
        printf("Please, Try Again\n\n");
        printf("Press Any Key To Continue");
        getch();
        menu();
    }
}

/* Creating Admin Login Function */

void admin_login()
{
    system("cls");
    printf("******Welcome To Olivia's Admin Login Menu******\n\n");
    FILE *fp;
    struct admin a;
    fp = fopen("admin.txt","rb+");
    if(fp == NULL){
        fclose(fp);
        fp=fopen("admin.txt","wb+");
        printf("Your Program Is Getting Ready For First Use\n");
        printf("There Is No Admin Added To This Program Yet\n");
        printf("Please Enter Admin Details For The First Time ---\n\n");
        printf("Enter Your First Name: ");
        fflush(stdin);
        gets(a.f_name);
        printf("Enter Your Last Name: ");
        gets(a.l_name);
        printf("Enter New Admin User ID: ");
        gets(a.id);
        while(1){
            printf("Enter New Password: ");
            scanf("%s", &a.pass);
            printf("Re Enter Password: ");
            scanf("%s", &a.repass);
            if(strcmp(a.pass,a.repass)==0)
            {
                break;
            }
            else
            {
                printf("Error In Password Matching\n");
                printf("Please, Try Again\n");
            }
        }
        fwrite(&a,sizeof(a),1,fp);
        printf("\n***Successfully Added Admin***\n\n");
        printf("Press Any Key To Continue");
        getch();
        fclose(fp);
        admin_login();
    }

    else{
        char id[20];
        char pass[20];
        printf("Please Enter Admin Login Details ---\n\n");
        printf("Enter Admin User ID: ");
        fflush(stdin);
        gets(id);
        printf("Enter Admin Password: ");
        gets(pass);
        while(fread(&a,sizeof(a),1,fp)){
            if(strcmp(id,a.id)==0 && strcmp(pass,a.pass)==0){
                printf("\n***Admin Login Successful***\n\n");
                printf("Press Any Key To Continue");
                getch();
                fclose(fp);
                admin_menu();
            }
            else{
                printf("Invalid User ID or Password Entered\n");
                printf("Please Try Again and Enter Correct User ID and Password\n\n");
                printf("Press Any Key To Continue");
                getch();
                fclose(fp);
                admin_login();
            }
        }
    }
}

/* Creating A Menu For Admin */

void admin_menu()
{
    system("cls");
    int x;
    printf("******Welcome To Olivia's Admin Panel Menu******\n\n");
    printf("Please, Choose Your Desired Place To Go ---\n");
    printf("1.  Add Teacher\n");
    printf("2.  Add Student\n");
    printf("3.  Update Teacher\n");
    printf("4.  Update Student\n");
    printf("5.  Add Courses To Teachers\n");
    printf("6.  Add Courses To Students\n");
    printf("7.  Update Teacher's Courses\n");
    printf("8.  Update Student,s Courses\n");
    printf("9.  View Teacher's Information\n");
    printf("10. View Student's Information\n");
    printf("11. View Admin's Information\n");
    printf("0.  Exit To Main Menu\n\n");
    printf("Please Select Your Desired Move: ");
    fflush(stdin);
    scanf("%d", &x);
    if(x==1){
        add_teacher();
    }
    else if(x==2){
        add_student();
    }
    else if(x==3){
        update_teacher();
    }
    else if(x==4){
        update_student();
    }
    else if(x==5){
        assign_courses_teacher();
    }
    else if(x==6){
        assign_courses_student();
    }
    else if(x==7){
        update_courses_teacher();
    }
    else if(x==8){
        update_courses_student();
    }
    else if(x==9){
        view_teachers();
    }
    else if(x==10){
        view_students();
    }
    else if(x==11){
        view_admin();
    }
    else if(x==0){
        menu();
    }
    else{
        printf("Invalid Input\n");
        printf("Please, Try Again\n\n");
        printf("Press Any Key To Continue");
        getch();
        admin_menu();
    }
}

/* Adding A Teacher Using A Function */

void add_teacher()
{
    system("cls");
    printf("******Welcome To Olivia's Adding Teachers Panel******\n\n");
    FILE *fp;
    struct teacher t;
    char x ='y';
    fp = fopen("teacher.txt","ab+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    while(x == 'y')
    {
        printf("Add Details Of Teacher ---\n");
        printf("Enter Teacher's First Name: ");
        fflush(stdin);
        gets(t.f_name);
        printf("Enter Teacher's Last Name: ");
        gets(t.l_name);
        printf("Enter Teacher's User ID: ");
        gets(t.id);
        while(1){
            printf("Enter New Password For The Teacher: ");
            scanf("%s", &t.pass);
            printf("Re Enter Password For The Teacher: ");
            scanf("%s", &t.repass);
            if(strcmp(t.pass,t.repass)==0)
            {
                break;
            }
            else
            {
                printf("Error In Password Matching\n");
                printf("Please, Try Again\n");
            }
        }
        fflush(stdin);
        for(int j=0; j<3; j++){
            strcpy(t.course[j], "None");
        }
        fwrite(&t,sizeof(t),1,fp);
        printf("\n***Successfully Added Teacher***\n\n");
        printf("Want To Add Another Teacher? Then Press 'y' ---\n");
        printf("Else, Press Any Other Key To Continue\n\n");
        fflush(stdin);
        x = getch();
    }
    fclose(fp);
    admin_menu();
}

/* Adding A Student Using A Function */

void add_student()
{
    system("cls");
    printf("******Welcome To Olivia's Adding Students Panel******\n\n");
    FILE *fp;
    struct student s;
    char x ='y';
    fp = fopen("student.txt","ab+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    while(x == 'y')
    {
        printf("Add Details Of Student ---\n");
        printf("Enter Student's First Name: ");
        fflush(stdin);
        gets(s.f_name);
        printf("Enter Student's Last Name: ");
        gets(s.l_name);
        printf("Enter Student's User ID: ");
        gets(s.id);
        while(1){
            printf("Enter New Password For The Student: ");
            scanf("%s", &s.pass);
            printf("Re Enter Password For The Student: ");
            scanf("%s", &s.repass);
            if(strcmp(s.pass,s.repass)==0)
            {
                break;
            }
            else
            {
                printf("Error In Password Matching\n");
                printf("Please, Try Again\n");
            }
        }
        printf("Enter Student's Department: ");
        fflush(stdin);
        gets(s.dept);
        printf("Enter Student's Roll No: ");
        scanf("%d", &s.roll);
        for(int j=0; j<5; j++){
            strcpy(s.course[j], "Empty");
            s.mark[j] = -1;
        }
        fwrite(&s,sizeof(s),1,fp);
        printf("\n***Successfully Added Student***\n\n");
        printf("Want To Add Another Student? Then Press 'y' ---\n");
        printf("Else, Press Any Other Key To Continue\n\n");
        fflush(stdin);
        x = getch();
    }
    fclose(fp);
    admin_menu();
}

/* Updating Teacher Using A Function */

void update_teacher()
{
    system("cls");
    printf("******Welcome To Olivia's Updating Teachers Panel******\n\n");
    FILE *fp;
    struct teacher t;
    struct teacher *p;
    p = &t;
    fp = fopen("teacher.txt","rb+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    printf("These Teachers Have Been Added Till Now\n\n");
    int i=1;
    while(fread(p,sizeof(t),1,fp) == 1){
        printf("SL No. %d\n", i);
        printf("First Name: ");
        puts(t.f_name);
        printf("Last Name: ");
        puts(t.l_name);
        printf("User ID: ");
        puts(t.id);
        printf("Password: ");
        puts(t.pass);
        printf("\n");
        i++;
    }
    char t_id[20];
    printf("Enter User ID Of Teacher To Modify: ");
    fflush(stdin);
    gets(t_id);
    rewind(fp);
    while(fread(p,sizeof(t),1,fp) == 1)
    {
        if(strcmp(t_id,t.id) == 0){
            printf("Add Details Of Teacher ---\n");
            printf("Enter Teacher's First Name: ");
            fflush(stdin);
            gets(t.f_name);
            printf("Enter Teacher's Last Name: ");
            gets(t.l_name);
            printf("Enter Teacher's User ID: ");
            gets(t.id);
            while(1){
                printf("Enter New Password For The Teacher: ");
                scanf("%s", &t.pass);
                printf("Re Enter Password For The Teacher: ");
                scanf("%s", &t.repass);
                if(strcmp(t.pass,t.repass)==0)
                {
                    break;
                }
                else
                {
                    printf("Error In Password Matching\n");
                    printf("Please, Try Again\n");
                }
            }
            fseek(fp,-sizeof(t),SEEK_CUR);
            fwrite(p,sizeof(t),1,fp);
            printf("\n***Successfully Updated Teacher***\n\n");
            break;
        }
        else{
            printf("No Information Found With That User ID\n");
            printf("Please, Try Again\n\n");
            fclose(fp);
            printf("Press Any Key To Continue");
            getch();
            update_teacher();
        }
    }
    fclose(fp);
    printf("Press Any Key To Continue");
    getch();
    admin_menu();
}

/* Updating Student Using A Function */

void update_student()
{
    system("cls");
    printf("******Welcome To Olivia's Updating Students Panel******\n\n");
    FILE *fp;
    struct student s;
    struct student *p;
    p = &s;
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    printf("These Students Have Been Added Till Now\n\n");
    int i=1;
    while(fread(p,sizeof(s),1,fp) == 1){
        printf("SL No. %d\n", i);
        printf("First Name: ");
        puts(s.f_name);
        printf("Last Name: ");
        puts(s.l_name);
        printf("User ID: ");
        puts(s.id);
        printf("Password: ");
        puts(s.pass);
        printf("Department: ");
        puts(s.dept);
        printf("Roll No: %d\n", s.roll);
        printf("\n");
        i++;
    }
    char s_id[20];
    printf("Enter User Id Of Student To Modify: ");
    fflush(stdin);
    gets(s_id);
    rewind(fp);
    while(fread(p,sizeof(s),1,fp) == 1)
    {
        if(strcmp(s_id,s.id) == 0){
            printf("Add Details Of Student ---\n");
            printf("Enter Student's First Name: ");
            fflush(stdin);
            gets(s.f_name);
            printf("Enter Student's Last Name: ");
            gets(s.l_name);
            printf("Enter Student's User ID: ");
            gets(s.id);
            while(1){
                printf("Enter New Password For The Student: ");
                scanf("%s", &s.pass);
                printf("Re Enter Password For The Student: ");
                scanf("%s", &s.repass);
                if(strcmp(s.pass,s.repass)==0)
                {
                    break;
                }
                else
                {
                    printf("Error In Password Matching\n");
                    printf("Please, Try Again\n");
                }
            }
            printf("Enter Student's Department: ");
            fflush(stdin);
            gets(s.dept);
            printf("Enter Student's Roll No: ");
            scanf("%d", &s.roll);
            fseek(fp,-sizeof(s),SEEK_CUR);
            fwrite(p,sizeof(s),1,fp);
            printf("\n***Successfully Updated Student***\n\n");
            break;
        }
        else{
            printf("No Information Found With That User ID\n");
            printf("Please, Try Again\n\n");
            fclose(fp);
            printf("Press Any Key To Continue");
            getch();
            update_student();
        }
    }
    fclose(fp);
    printf("Press Any Key To Continue");
    getch();
    admin_menu();
}

/* Assigning Courses To A Teacher Using A Function */

void assign_courses_teacher()
{
    system("cls");
    printf("******Welcome To Olivia's Assigning Teacher's Courses Panel******\n\n");
    FILE *fp;
    struct teacher t;
    fp = fopen("teacher.txt","rb+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    printf("These Teachers Have Been Added Till Now\n\n");
    int i=1;
    while(fread(&t,sizeof(t),1,fp) == 1){
        printf("SL No. %d\n", i);
        printf("First Name: ");
        puts(t.f_name);
        printf("Last Name: ");
        puts(t.l_name);
        printf("User ID: ");
        puts(t.id);
        printf("Password: ");
        puts(t.pass);
        printf("\n");
        i++;
    }
    char t_id[20];
    printf("Enter User Id Of Teacher To Assign Courses: ");
    fflush(stdin);
    gets(t_id);
    rewind(fp);
    char x;
    while(fread(&t,sizeof(t),1,fp) == 1)
    {
        if(strcmp(t_id,t.id) == 0){
            printf("Add Courses Of Teacher ---\n");
            printf("Enter First Course Name: ");
            fflush(stdin);
            gets(t.course[0]);
            printf("Do You Want To Add Another Course To This Teacher?\n");
            printf("If Yes...Press 'y'...\n");
            fflush(stdin);
            x = getch();
            if(x == 'y'){
                printf("Enter Second Course Name: ");
                gets(t.course[1]);
                printf("Do You Want To Add Another Course To This Teacher?\n");
                printf("If Yes...Press 'y'...\n");
                fflush(stdin);
                x = getch();
            }
            if(x == 'y'){
                printf("Enter Third Course Name: ");
                gets(t.course[2]);
                printf("The Maximum Amount Of Courses Has Been Assigned To This Teacher\n");
            }
            fseek(fp,-sizeof(t),SEEK_CUR);
            fwrite(&t,sizeof(t),1,fp);
            printf("\n***Successfully Added Courses To This Teacher***\n\n");
            break;
        }
        else{
            printf("No Information Found With That User ID\n");
            printf("Please Try Again\n\n");
            fclose(fp);
            printf("Press Any Key To Continue");
            getch();
            assign_courses_teacher();
        }
    }
    fclose(fp);
    printf("Press Any Key To Continue");
    getch();
    admin_menu();
}

/* Assigning Courses To A Student using A Function */

void assign_courses_student()
{
    system("cls");
    printf("******Welcome To Olivia's Assigning Student's Courses Panel******\n\n");
    FILE *fp;
    struct student s;
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    printf("These Students Have Been Added Till Now\n\n");
    int i=1;
    while(fread(&s,sizeof(s),1,fp) == 1){
        printf("SL No. %d\n", i);
        printf("First Name: ");
        puts(s.f_name);
        printf("Last Name: ");
        puts(s.l_name);
        printf("User ID: ");
        puts(s.id);
        printf("Password: ");
        puts(s.pass);
        printf("Department: ");
        puts(s.dept);
        printf("Roll No: %d\n", s.roll);
        printf("\n");
        i++;
    }
    char s_id[20];
    printf("Enter User Id Of Student To Assign Courses: ");
    fflush(stdin);
    gets(s_id);
    rewind(fp);
    char x;
    while(fread(&s,sizeof(s),1,fp) == 1)
    {
        if(strcmp(s_id,s.id) == 0){
            printf("Add Courses Of Student ---\n");
            printf("Enter First Course Name: ");
            fflush(stdin);
            gets(s.course[0]);
            printf("Do You Want To Add Another Course To This Student?\n");
            printf("If Yes...Press 'y'...\n");
            fflush(stdin);
            x = getch();
            if(x == 'y'){
                printf("Enter Second Course Name: ");
                gets(s.course[1]);
                printf("Do You Want To Add Another Course To This Student?\n");
                printf("If Yes...Press 'y'...\n");
                fflush(stdin);
                x = getch();
            }
            if(x == 'y'){
                printf("Enter Third Course Name: ");
                gets(s.course[2]);
                printf("Do You Want To Add Another Course To This Student?\n");
                printf("If Yes...Press 'y'...\n");
                fflush(stdin);
                x = getch();
            }
            if(x == 'y'){
                printf("Enter Fourth Course Name: ");
                gets(s.course[3]);
                printf("Do You Want To Add Another Course To This Student?\n");
                printf("If Yes...Press 'y'...\n");
                fflush(stdin);
                x = getch();
            }
            if(x == 'y'){
                printf("Enter Fifth Course Name: ");
                gets(s.course[4]);
                printf("The Maximum Amount Of Courses Has Been Assigned To This Student\n");
            }
            fseek(fp,-sizeof(s),SEEK_CUR);
            fwrite(&s,sizeof(s),1,fp);
            printf("\n***Successfully Added Courses To This Student***\n\n");
            break;
        }
        else{
            printf("No Information Found With That User ID\n");
            printf("Please Try Again\n\n");
            fclose(fp);
            printf("Press Any Key To Continue");
            getch();
            assign_courses_student();
        }
    }
    fclose(fp);
    printf("Press Any Key To Continue");
    getch();
    admin_menu();
}

/* Updating Courses Of A Teacher using A Function */

void update_courses_teacher()
{
    system("cls");
    printf("******Welcome To Olivia's Updating Teacher's Courses Panel******\n\n");
    FILE *fp;
    struct teacher t;
    fp = fopen("teacher.txt","rb+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    printf("These Teachers Have Been Added Till Now\n\n");
    int i=1;
    while(fread(&t,sizeof(t),1,fp) == 1){
        printf("SL No. %d\n", i);
        printf("First Name: ");
        puts(t.f_name);
        printf("Last Name: ");
        puts(t.l_name);
        printf("User ID: ");
        puts(t.id);
        printf("Password: ");
        puts(t.pass);
        for(int j=0; j<3; j++){
            printf("Course No. %d: ", j+1);
            puts(t.course[j]);
        }
        printf("\n");
        i++;
    }
    char t_id[20];
    int k;
    printf("Enter User ID Of Teacher To Update Courses: ");
    fflush(stdin);
    gets(t_id);
    printf("Enter Course No. To Update: ");
    scanf("%d", &k);
    if(k<1 && k>3){
        printf("Invalid Course No.\n");
    }
    else{
        rewind(fp);
        while(fread(&t,sizeof(t),1,fp) == 1)
        {
            if(strcmp(t_id,t.id) == 0){
                printf("Update Course Of Teacher ---\n");
                printf("Enter New Course Name: ");
                fflush(stdin);
                gets(t.course[k-1]);
                fseek(fp,-sizeof(t),SEEK_CUR);
                fwrite(&t,sizeof(t),1,fp);
                printf("\n***Successfully Updated Course To This Teacher***\n\n");
                break;
            }
            else{
                printf("No Information Found With That User ID\n");
                printf("Please Try Again\n\n");
                fclose(fp);
                printf("Press Any Key To Continue");
                getch();
                update_courses_teacher();
            }
        }
    }
    fclose(fp);
    printf("Press Any Key To Continue");
    getch();
    admin_menu();
}

/* Updating Courses Of A Student using A Function */

void update_courses_student()
{
    system("cls");
    printf("******Welcome To Olivia's Updating Student's Courses Panel******\n\n");
    FILE *fp;
    struct student s;
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    printf("These Students Have Been Added Till Now\n\n");
    int i=1;
    while(fread(&s,sizeof(s),1,fp) == 1){
        printf("SL No. %d\n", i);
        printf("First Name: ");
        puts(s.f_name);
        printf("Last Name: ");
        puts(s.l_name);
        printf("User ID: ");
        puts(s.id);
        printf("Password: ");
        puts(s.pass);
        printf("Department: ");
        puts(s.dept);
        printf("Roll No: %d\n", s.roll);
        for(int j=0; j<5; j++){
            printf("Course No. %d: ", j+1);
            puts(s.course[j]);
        }
        printf("\n");
        i++;
    }
    char s_id[20];
    int k;
    printf("Enter User ID Of Student To Update Courses: ");
    fflush(stdin);
    gets(s_id);
    printf("Enter Course No. To Update: ");
    scanf("%d", &k);
    if(k<1 && k>5){
        printf("Invalid Course No.\n");
    }
    else{
        rewind(fp);
        while(fread(&s,sizeof(s),1,fp) == 1)
        {
            if(strcmp(s_id,s.id) == 0){
                printf("Update Course Of Student ---\n");
                printf("Enter New Course Name: ");
                fflush(stdin);
                gets(s.course[k-1]);
                fseek(fp,-sizeof(s),SEEK_CUR);
                fwrite(&s,sizeof(s),1,fp);
                printf("\n***Successfully Updated Course To This Student***\n\n");
                break;
            }
            else{
                printf("No Information Found With That User ID\n");
                printf("Please Try Again\n\n");
                fclose(fp);
                printf("Press Any Key To Continue");
                getch();
                update_courses_student();
            }
        }
    }
    fclose(fp);
    printf("Press Any Key To Continue");
    getch();
    admin_menu();
}

/* Viewing All Added Teachers Using A Function */

void view_teachers()
{
    system("cls");
    printf("******Welcome To Olivia's Viewing Teacher Details Panel******\n\n");
    FILE *fp;
    struct teacher t;
    fp = fopen("teacher.txt","rb+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    printf("These Teachers Have Been Added Till Now\n\n");
    int i=1;
    while(fread(&t,sizeof(t),1,fp) == 1){
        printf("SL No. %d\n", i);
        printf("First Name: ");
        puts(t.f_name);
        printf("Last Name: ");
        puts(t.l_name);
        printf("User ID: ");
        puts(t.id);
        printf("Password: ");
        puts(t.pass);
        for(int j=0; j<3; j++){
            printf("Course No. %d: ", j+1);
            puts(t.course[j]);
        }
        printf("\n");
        i++;
    }
    fclose(fp);
    printf("Press Any Key To Continue");
    getch();
    admin_menu();
}

/* Viewing All Added Students Using A Function */

void view_students()
{
    system("cls");
    printf("******Welcome To Olivia's Viewing Student Details Panel******\n\n");
    FILE *fp;
    struct student s;
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    printf("These Students Have Been Added Till Now\n\n");
    int i=1;
    while(fread(&s,sizeof(s),1,fp) == 1){
        printf("SL No. %d\n", i);
        printf("First Name: ");
        puts(s.f_name);
        printf("Last Name: ");
        puts(s.l_name);
        printf("User ID: ");
        puts(s.id);
        printf("Password: ");
        puts(s.pass);
        printf("Department: ");
        puts(s.dept);
        printf("Roll No: %d\n", s.roll);
        for(int j=0; j<5; j++){
            printf("Course No. %d: ", j+1);
            puts(s.course[j]);
            printf("Mark For Course No. %d, %s: %d\n", j+1, s.course[j], s.mark[j]);
        }
        printf("\n");
        i++;
    }
    fclose(fp);
    printf("Press Any Key To Continue");
    getch();
    admin_menu();
}

/* Viewing The Admin Using A Function */

void view_admin()
{
    system("cls");
    printf("******Welcome To Olivia's Viewing Admin Details Panel******\n\n");
    FILE *fp;
    struct admin a;
    fp = fopen("admin.txt","rb+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    printf("This Is The Admin For This Program\n\n");
    while(fread(&a,sizeof(a),1,fp) == 1){
        printf("First Name: ");
        puts(a.f_name);
        printf("Last Name: ");
        puts(a.l_name);
        printf("User ID: ");
        puts(a.id);
        printf("Password: ");
        puts(a.pass);
        printf("\n");
    }
    fclose(fp);
    printf("Press Any Key To Continue");
    getch();
    admin_menu();
}

/* Creating Teacher Login Function */

void teacher_login()
{
    system("cls");
    printf("******Welcome To Olivia's Teacher Login Panel******\n\n");
    FILE *fp;
    struct teacher t;
    fp = fopen("teacher.txt","rb+");
    if(fp == NULL){
        printf("There Is No Teacher Information Available Yet\n");
        printf("Ask The Admin To Create Your Information First\n");
        printf("Thank You\n\n");
        printf("Press Any Key To Continue");
        getch();
        fclose(fp);
        menu();
    }

    else{
        char id[20];
        char pass[20];
        printf("Please Enter Teacher Login Details ---\n");
        printf("Enter Teacher User ID: ");
        fflush(stdin);
        gets(id);
        printf("Enter Teacher Password: ");
        gets(pass);
        while(fread(&t,sizeof(t),1,fp)){
            if(strcmp(id,t.id)==0 && strcmp(pass,t.pass)==0){
                printf("\n***Teacher Login Successful***\n\n");
                printf("Press Any Key To Continue");
                getch();
                teacher_menu();
            }
            else{
                printf("Invalid User ID or Password Entered\n");
                printf("Please Try Again and Enter Correct User ID and Password\n\n");
                printf("Press Any Key To Continue");
                getch();
                teacher_login();
            }
        }
    fclose(fp);
    }
}

/* Creating A Menu For Teachers */

void teacher_menu()
{
    system("cls");
    printf("******Welcome To Olivia's Teacher's Menu******\n\n");
    int x;
    printf("1. Add Or Update Student's Marks\n");
    printf("2. Find Student By First Name\n");
    printf("3. Count and View Total Students of Your Courses\n");
    printf("4. Count and View All Student's Information\n");
    printf("0. Exit To Main Menu\n\n");
    printf("Please, Select Your Desired Move: ");
    fflush(stdin);
    scanf("%d", &x);
    if(x==1){
        add_student_marks();
    }
    else if(x==2){
        find_student();
    }
    else if(x==3){
        count_view_students_course();
    }
    else if(x==4){
        count_view_students_all();
    }
    else if(x==0){
        menu();
    }
    else{
        printf("Invalid Input\n");
        printf("Please, Try Again\n\n");
        printf("Press Any Key To Continue");
        getch();
        teacher_menu();
    }
}

/* Adding Or Updating Marks To A Student For A Specific Course Using A Function */

void add_student_marks()
{
    system("cls");
    printf("******Welcome To Olivia's Adding Or Updating Student's Marks Panel******\n\n");
    FILE *fp;
    struct student s;
    char c_name[15];
    printf("Enter Course Name To Add Or Update Marks: ");
    fflush(stdin);
    gets(c_name);
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    rewind(fp);
    int i=1;
    while(fread(&s,sizeof(s),1,fp) == 1){
        int k=0;
        while(k<5){
            if(strcmp(c_name,s.course[k])==0){
                printf("SL No. %d\n", i);
                printf("First Name: ");
                puts(s.f_name);
                printf("Last Name: ");
                puts(s.l_name);
                printf("User ID: ");
                puts(s.id);
                printf("Department: ");
                puts(s.dept);
                printf("Roll No: %d\n", s.roll);
                printf("Course No: %d\n", k+1);
                printf("Marks: %d\n", s.mark[k]);
                printf("\n");
                i++;
            }
            k++;
        }
    }
    char x;
    x = 'y';
    while(x == 'y'){
        char s_id[20];
        int k;
        printf("Enter User ID Of Student To Add Or Update Marks: ");
        fflush(stdin);
        gets(s_id);
        printf("Enter Course No. To Add Or Update Marks: ");
        scanf("%d", &k);
        if(k<1 && k>5){
            printf("Invalid Course No.\n");
        }
        else{
            rewind(fp);
            while(fread(&s,sizeof(s),1,fp) == 1)
            {
                if(strcmp(s_id,s.id) == 0){
                    printf("Enter Marks: ");
                    fflush(stdin);
                    scanf("%d", &s.mark[k-1]);
                    fseek(fp,-sizeof(s),SEEK_CUR);
                    fwrite(&s,sizeof(s),1,fp);
                    printf("\n***Successfully Added Marks To This Student***\n\n");
                    break;
                }
                else{
                    printf("No Information Found With That User ID\n");
                    printf("Please Try Again\n\n");
                    fclose(fp);
                    printf("Press Any Key To Continue");
                    getch();
                    add_student_marks();
                }
            }
        }
        printf("Want To Add Or Update Marks To Another Student? Then Press 'y' ---\n");
        printf("Else, Press Any Other Key To Continue\n\n");
        fflush(stdin);
        x = getch();
    }
    fclose(fp);
    printf("Press Any Key To Continue");
    getch();
    teacher_menu();
}

/* Finding A Student Using First Name Using A Function */

void find_student()
{
    system("cls");
    printf("******Welcome To Olivia's Finding A Student Panel******\n\n");
    FILE *fp;
    struct student s;
    struct student *p;
    p = &s;
    char s_name[20];
    printf("Enter First Name Of Student To Find: ");
    fflush(stdin);
    gets(s_name);
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    while(fread(p,sizeof(s),1,fp) == 1){
        if(strcmp(s_name,s.f_name) == 0){
            printf("First Name: ");
            puts(s.f_name);
            printf("Last Name: ");
            puts(s.l_name);
            printf("User ID: ");
            puts(s.id);
            printf("Department: ");
            puts(s.dept);
            printf("Roll No: %d\n", s.roll);
            for(int j=0; j<5; j++){
                printf("Course No. %d: ", j+1);
                puts(s.course[j]);
                printf("Mark for Course No. %d, %s: %d\n", j+1, s.course[j], s.mark[j]);
            }
            printf("\n");
            printf("***Successfully Found Student***\n\n");
        }
        else{
            printf("No Information Found With That First Name\n");
            printf("Please Try Again\n\n");
            fclose(fp);
            printf("Press Any Key To Continue");
            getch();
            find_student();
            }
    }
    fclose(fp);
    printf("Press Any Key To Continue");
    getch();
    teacher_menu();
}

/* Viewing & Counting Students For A Specific Course Using A Function */

void count_view_students_course()
{
    system("cls");
    printf("******Welcome To Olivia's Viewing And Counting Your Course's Student Panel******\n\n");
    FILE *fp;
    struct student s;
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    rewind(fp);
    char c_name[15];
    printf("Enter Course Name To View And Count Students For: ");
    fflush(stdin);
    gets(c_name);
    int i=1;
    while(fread(&s,sizeof(s),1,fp) == 1){
        int k=0;
        while(k<5){
            if(strcmp(c_name,s.course[k])==0){
                printf("SL No. %d\n", i);
                printf("First Name: ");
                puts(s.f_name);
                printf("Last Name: ");
                puts(s.l_name);
                printf("User ID: ");
                puts(s.id);
                printf("Department: ");
                puts(s.dept);
                printf("Roll No: %d\n", s.roll);
                printf("Course No: %d\n", k+1);
                printf("Marks: %d\n", s.mark[k]);
                printf("\n");
                i++;
            }
            k++;
        }
    }
    printf("Total Students For Course %s Are: %d\n\n", c_name, i-1);
    fclose(fp);
    printf("Press Any Key To Continue");
    getch();
    teacher_menu();
}

/* Viewing & Counting All Students Using A Function */

void count_view_students_all()
{
    system("cls");
    printf("******Welcome To Olivia's Viewing And Counting All Students Panel******\n\n");
    FILE *fp;
    struct student s;
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    int i=1;
    while(fread(&s,sizeof(s),1,fp) == 1){
        printf("SL No. %d\n", i);
        printf("First Name: ");
        puts(s.f_name);
        printf("Last Name: ");
        puts(s.l_name);
        printf("User ID: ");
        puts(s.id);
        printf("Department: ");
        puts(s.dept);
        printf("Roll No. %d\n", s.roll);
        for(int j=0; j<5; j++){
            printf("Course no. %d: ", j+1);
            puts(s.course[j]);
            printf("Mark for Course No. %d, %s: %d\n", j+1, s.course[j], s.mark[j]);
        }
        printf("\n");
        i++;
    }
    printf("Total Students Are: %d\n\n", i-1);
    fclose(fp);
    printf("Press Any Key To Continue");
    getch();
    teacher_menu();
}

/* Creating Student Login Function */

void student_login()
{
    system("cls");
    printf("******Welcome To Olivia's Student Login Panel******\n\n");
    FILE *fp;
    struct student s;
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        printf("There Is No Student Information Available Yet\n");
        printf("Ask The Admin To Create Your Information First\n");
        printf("Thank You\n\n");
        printf("Press Any Key To Continue");
        getch();
        fclose(fp);
        menu();
    }

    else{
        char id[20];
        char pass[20];
        printf("Please Enter Student Login Details ---\n");
        printf("Enter Student User ID: ");
        fflush(stdin);
        gets(id);
        printf("Enter Student Password: ");
        gets(pass);
        while(fread(&s,sizeof(s),1,fp)){
            if(strcmp(id,s.id)==0 && strcmp(pass,s.pass)==0){
                printf("\n***Student Login Successful***\n\n");
                printf("Press Any Key To Continue");
                getch();
                student_menu();
            }
            else{
                printf("Invalid User ID or Password Entered\n");
                printf("Please Try Again and Enter Correct User ID and Password\n\n");
                printf("Press Any Key To Continue");
                getch();
                student_login();
            }
        }
    fclose(fp);
    }
}

/* Creating A  Menu For Students */

void student_menu()
{
    system("cls");
    printf("******Welcome To Olivia's Student's Menu******\n\n");
    int x;
    printf("1. View Student's Marks\n");
    printf("0. Exit To Main Menu\n\n");
    printf("Please, Select Your Desired Move: ");
    fflush(stdin);
    scanf("%d", &x);
    if(x==1){
        view_student_marks();
    }
    else if(x==0){
        menu();
    }
    else{
        printf("Invalid Input\n");
        printf("Please, Try Again\n\n");
        printf("Press Any Key To Continue");
        getch();
        student_menu();
    }
}

/* Creating A Function To View Student's Marks */

void view_student_marks()
{
    system("cls");
    printf("******Welcome To Olivia's Viewing Student's Marks Panel******\n\n");
    FILE *fp;
    struct student s;
    char s_name[20];
    printf("Enter First Name Of Student To See Marks: ");
    fflush(stdin);
    gets(s_name);
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        printf("Error Opening File\n");
        printf("The File Either Doesn't Exist Or Corrupted\n");
    }
    while(fread(&s,sizeof(s),1,fp) == 1){
        if(strcmp(s_name,s.f_name) == 0){
            printf("First Name: ");
            puts(s.f_name);
            printf("Last Name: ");
            puts(s.l_name);
            printf("User ID: ");
            puts(s.id);
            printf("Department: ");
            puts(s.dept);
            printf("Roll No. %d\n", s.roll);
            for(int j=0; j<5; j++){
                printf("Course no. %d: ", j+1);
                puts(s.course[j]);
                printf("Mark for Course No. %d, %s: %d\n", j+1, s.course[j], s.mark[j]);
            }
            printf("\n");
            printf("***Successfully Viewed Marks For This Student***\n\n");
        }
        else{
            printf("No Information Found With That First Name\n");
            printf("Please Try Again\n\n");
            fclose(fp);
            printf("Press Any Key To Continue");
            getch();
            view_student_marks();
        }
    }
    fclose(fp);
    printf("Press Any Key To Continue");
    getch();
    student_menu();
}

/* Declaring Main Function */

int main()
{
    printf("******Welcome To Olivia's University Management Program******\n\n");
    printf("Hello, Sir/Mam\nI'm Olivia, The AI Assistant For This Program\nI'll Help You Throughout Your Journey\n\n");
    printf("Press Any Key To Continue");
    getch();
    menu();
    return 0;
}
