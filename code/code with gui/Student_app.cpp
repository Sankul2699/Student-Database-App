/*
* Project Name: Student-Database-App

* File Name:Student_app.cpp

* Author : Sanchit Kulkarni
*/


#include <iostream>
#include<fstream>
#include<conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include<sstream>
#define ENTER_DETAILS 1
#define CHECK_DETAILS 2
#define EXIT_KEY 3
#define SUBMIT_DETAILS 4
#define SUBMIT_ROLLNO 5
#define SUBMIT_STUDENTSNO 6
#define next 7
using namespace std;

/*/////////////////////////////////FUNCTION PROTOTYPES////////////////////////////*/
void passwordDialog1(HWND);
void enter(int);
void checkDetails(int);
void AddMenus(HWND);
void AddControls(HWND);
LRESULT CALLBACK DialogProcedure1(HWND,UINT,WPARAM,LPARAM);
void registerDialogClass1(HINSTANCE);
void displayDialog1(HWND);
LRESULT CALLBACK DialogProcedure2(HWND,UINT,WPARAM,LPARAM);
void registerDialogClass2(HINSTANCE);
void displayDialog2(HWND);
LRESULT CALLBACK DialogProcedure3(HWND,UINT,WPARAM,LPARAM);
void registerDialogClass3(HINSTANCE);
void displayDialog3(HWND);
LRESULT CALLBACK WProc(HWND,UINT,WPARAM,LPARAM);
HWND hMain,hDlg1,hDlg2,hDlg3,hOut,hOut1,hName,hDOB,hRno,hNo,hpass,hkey;
HMENU hMenu;
int flag;
char name[20];
char pass[20];
char DOB[11];
char namef[20];
char DOBf[11];
char stno[4];
int student_no;
int rno;
int k=0;
int maxim=0;
int maxilim=8;

ofstream myFile;


/*/////////////////////////////////Conversion to Char////////////////////////////*/


/*/////////////////////////////////////////////////////////////////////////////////////*/
struct student
{
    char DOBS[8];
    char nameS[20];
    int roll_no;
}*temp,*fina,*mid;


//////////////////////////////////ENTER STUDENT DETAILS////////////////////////////*/
void enter(int n4)
{
    if(k==0)
    {
        temp=new student;
        fina=temp;
    }
    for(int i=0;i<n4;i++)
    {
        strcpy((*temp).DOBS,DOB);
        strcpy((*temp).nameS,name);
        (*temp).roll_no=k++;
        temp++;
    }
}
/*//////////////////////////////CHECK DETAILS//////////////////////////////////*/
void checkDetails(int n4)
{
    if(n4<=k)
    {
        temp=fina;
        temp+=n4-1;
        cout<<"Student Name :"<<(*temp).nameS<<endl;
        cout<<"Student Date Of Birth :"<<(*temp).DOBS<<endl;
    }
    else
    {
         cout<<"Student with "<<" Roll Number "<<n4<<"does not exist."<<endl;
    }


    temp=fina;
    for(int j=0;j<k;j++)
    {
    delete temp;
    temp++;
    }
    delete fina;

}
/*////////////////////////////////////MENU BAR////////////////////////////////////////*/
void AddMenus(HWND hWnd)
{
    hMenu =CreateMenu();
    HMENU hOptionsMenu=CreateMenu();
    HMENU hSubMenu=CreateMenu();


    AppendMenu(hSubMenu,MF_STRING,ENTER_DETAILS,"Enter");
    AppendMenu(hSubMenu,MF_STRING,CHECK_DETAILS,"Check");
    AppendMenu(hOptionsMenu,MF_POPUP,(UINT_PTR)hSubMenu,"Details");
    AppendMenu(hOptionsMenu,MF_STRING,EXIT_KEY,"Exit");
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hOptionsMenu,"Options");
    SetMenu(hWnd,hMenu);
}
/*/////////////////////////////////BUTTONS//////////////////////////////*/
void AddControls(HWND hWnd)
{   CreateWindowW(L"static",L"DATABASE APP",WS_VISIBLE|WS_CHILD,70,20,400,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"BUTTON",L" ADMIN",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,40,80,200,50,hWnd,(HMENU)ENTER_DETAILS,NULL,NULL);
    CreateWindowW(L"BUTTON",L" DATABASE",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,40,150,200,50,hWnd,(HMENU)CHECK_DETAILS,NULL,NULL);

}
/*///////////////////////////////// ENTRY WINDOW(DIALOG BOX 1)////////////////////////////////////*/
LRESULT CALLBACK DialogProcedure1(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch(msg)
    {
    case WM_CLOSE:
        DestroyWindow(hWnd);
        EnableWindow(hMain,true);
        break;
    case WM_COMMAND:
        switch(wp)
        {


        case next:
        GetWindowText(hkey,pass,20);
        displayDialog1(hWnd);








        break;



        case SUBMIT_DETAILS:

            GetWindowText(hName,name,20);
            GetWindowText(hDOB,DOB,10);
            int flag=0;
            int i;

            for(i=0;i<20;i++)
            {
              if((name[i]>=33 && name[i]<=64))
              {
                  flag=1;
                    break;
              }

            }
           for(i=0;i<2;i++)
            {
              if((DOB[i]>=48 && DOB[i]<=57))
              {
                  continue;
                }
                else
                {
                  flag=1;
                  break;
                }
            }


             if(flag==1)
            {
                MessageBoxW(hDlg1,L"Please fill  valid details to proceed",L"Invalid Input",MB_OK|MB_ICONERROR);
                return 0;
            }

            if(strcmp(name,"")==0||strcmp(DOB,"")==0)
            {   MessageBoxW(hDlg1,L"Please fill  the details to proceed",L"Missing Input",MB_OK|MB_ICONERROR);
                    return 0;
            }
            else
            {   if(k==0)
                    {
                        temp=new student;
                        fina=temp;
                        mid=temp;
                    }
                    temp=mid;
                    strcpy((*temp).DOBS,DOB);
                    strcpy((*temp).nameS,name);
                    k+=1;
                    (*temp).roll_no=k;
                    temp++;
                    mid=temp;
                    myFile<<name<<","<<DOB<<endl;
            }
            DestroyWindow(hWnd);
            DestroyWindow(hpass);
            break;
        }
        break;


    default:
        return DefWindowProcW(hWnd,msg,wp,lp);

    }
}
void registerDialogClass1(HINSTANCE hInst)
{

    WNDCLASSW dialog1={0};
    dialog1.hbrBackground=(HBRUSH)COLOR_WINDOW;
    dialog1.hCursor=LoadCursor(NULL,IDC_CROSS);
    dialog1.hInstance=hInst;
    dialog1.lpszClassName=L"MyDialogClass1";
    dialog1.lpfnWndProc=DialogProcedure1;

    RegisterClassW(&dialog1);

}
void passwordDialog1(HWND hWnd)
{
    hpass=CreateWindowW(L"MyDialogClass1",L"Enter password :",WS_VISIBLE|WS_OVERLAPPEDWINDOW,100,100,400,300,hWnd,NULL,NULL,NULL);
    hkey=CreateWindowW(L"edit",L"",WS_VISIBLE|WS_CHILD|WS_BORDER|ES_MULTILINE|ES_AUTOVSCROLL,155,105,100,50,hpass,NULL,NULL,NULL);
    CreateWindowW(L"static",L"PASSWORD:",WS_VISIBLE|WS_CHILD,50,105,100,50,hpass,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"VERIFY",WS_VISIBLE|WS_CHILD,132,160,150,50,hpass,(HMENU)next,NULL,NULL);
}
void displayDialog1(HWND hWnd)
{


 hDlg1=CreateWindowW(L"MyDialogClass1",L"Please enter Student Details",WS_VISIBLE|WS_OVERLAPPEDWINDOW,100,100,400,300,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"static",L"STUDENT INFORMATION ENTRY ",WS_VISIBLE|WS_CHILD,100,20,400,20,hDlg1,NULL,NULL,NULL);
    CreateWindowW(L"static",L"Name:",WS_VISIBLE|WS_CHILD,50,50,100,50,hDlg1,NULL,NULL,NULL);
    hName=CreateWindowW(L"edit",L"",WS_VISIBLE|WS_CHILD|WS_BORDER|ES_MULTILINE|ES_AUTOVSCROLL,155,50,100,50,hDlg1,NULL,NULL,NULL);
    CreateWindowW(L"static",L"DOB:",WS_VISIBLE|WS_CHILD,50,105,100,50,hDlg1,NULL,NULL,NULL);
    hDOB=CreateWindowW(L"edit",L"",WS_VISIBLE|WS_CHILD|WS_BORDER|ES_MULTILINE|ES_AUTOVSCROLL,155,105,100,50,hDlg1,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE|WS_CHILD,132,160,150,50,hDlg1,(HMENU)SUBMIT_DETAILS,NULL,NULL);
    }




/*/////////////////////////////////GETTING DETAILS(DIALOG BOX 2)////////////////////////////////////*/
LRESULT CALLBACK DialogProcedure2(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch(msg)
    {
    case WM_CLOSE:
        DestroyWindow(hWnd);
        EnableWindow(hMain,true);
        break;

    case WM_COMMAND:
        switch(wp)
        {
        case SUBMIT_ROLLNO:
            char rollno[4];

            GetWindowText(hRno,rollno,4);
            rno=atoi(rollno);
            if(strcmp(rollno,"")==0)
                {   MessageBoxW(hDlg2,L"Please fill  the details to proceed",L"Missing Input",MB_OK|MB_ICONERROR);
                    return 0;
                }
            else if(rno>k||rno==0)
                {
                    MessageBoxW(hDlg2,L"Roll number does not exist , please enter a valid choice",L"Exceeding Limit",MB_OK|MB_ICONERROR);
                    return 0;
                }
            else
                {   char out2[50]="NAME : ";
                    temp=fina;
                    temp+=rno-1;
                    strcpy(namef,(*temp).nameS);
                    strcpy(DOBf,(*temp).DOBS);
                    strcat(out2,namef);
                    strcat(out2,"       ");
                    strcat(out2," Date Of Birth : ");
                    strcat(out2,DOBf);
                    SetWindowText(hOut1,out2);
                }
                break;
            }break;
    default:
        return DefWindowProcW(hWnd,msg,wp,lp);

    }
}
void registerDialogClass2(HINSTANCE hInst)
{

    WNDCLASSW dialog2={0};
    dialog2.hbrBackground=(HBRUSH)COLOR_WINDOW;
    dialog2.hCursor=LoadCursor(NULL,IDC_CROSS);
    dialog2.hInstance=hInst;
    dialog2.lpszClassName=L"MyDialogClass2";
    dialog2.lpfnWndProc=DialogProcedure2;

    RegisterClassW(&dialog2);

}
void displayDialog2(HWND hWnd)
{
    hDlg2=CreateWindowW(L"MyDialogClass2",L" USER WINDOW ",WS_VISIBLE|WS_OVERLAPPEDWINDOW,100,100,500,500,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"static",L"STUDENT DETAILS",WS_VISIBLE|WS_CHILD,100,20,400,20,hDlg2,NULL,NULL,NULL);
    CreateWindowW(L"static",L"POSITION:",WS_VISIBLE|WS_CHILD,50,70,100,50,hDlg2,NULL,NULL,NULL);
    hRno=CreateWindowW(L"edit",L"",WS_VISIBLE|WS_CHILD|WS_BORDER,155,70,100,50,hDlg2,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"SUBMIT",WS_VISIBLE|WS_CHILD,132,130,150,50,hDlg2,(HMENU)SUBMIT_ROLLNO,NULL,NULL);
    hOut1=CreateWindowW(L"edit",L"",WS_VISIBLE|WS_CHILD|WS_BORDER|ES_MULTILINE|ES_AUTOVSCROLL,50,220,300,100,hDlg2,NULL,NULL,NULL);
    EnableWindow(hWnd,false);
}
/*/////////////////////////////////DIALOG BOX 3////////////////////////////////////*/
LRESULT CALLBACK DialogProcedure3(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch(msg)
    {
    case WM_CLOSE:
        DestroyWindow(hWnd);
        EnableWindow(hMain,true);
        break;

    case WM_COMMAND:
            switch(wp)
            {
            case SUBMIT_STUDENTSNO:
                char stno[4];
                GetWindowText(hNo,stno,4);
                student_no=atoi(stno);
                if(strcmp(stno,"")==0)
                {   MessageBoxW(hDlg3,L"Please fill  the details to proceed",L"Missing Input",MB_OK|MB_ICONERROR);
                    return 0;
                }
                else if(student_no >60 )
                {
                    MessageBoxW(hDlg3,L"So many slots unavailable , please enter a valid choice",L"Exceeding Limit",MB_OK|MB_ICONERROR);
                    return 0;
                }
                else
                {   flag=1;
                    if(k==0)
                    {
                        temp=new student;
                        fina=temp;
                    }
                    for(int i=0;i<student_no;i++)
                    {
                        displayDialog1(hWnd);


                    }


                }

                break;
            }break;
    default:
        return DefWindowProcW(hWnd,msg,wp,lp);

    }
}
void registerDialogClass3(HINSTANCE hInst)
{

    WNDCLASSW dialog3={0};
    dialog3.hbrBackground=(HBRUSH)COLOR_WINDOW;
    dialog3.hCursor=LoadCursor(NULL,IDC_CROSS);
    dialog3.hInstance=hInst;
    dialog3.lpszClassName=L"MyDialogClass";
    dialog3.lpfnWndProc=DialogProcedure3;

    RegisterClassW(&dialog3);

}
void displayDialog3(HWND hWnd)
{
    hDlg3=CreateWindowW(L"MyDialogClass",L" Number",WS_VISIBLE|WS_OVERLAPPEDWINDOW,200,200,280,200,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"static",L"No.Of Students:",WS_VISIBLE|WS_CHILD,20,50,150,20,hDlg3,NULL,NULL,NULL);
    hNo=CreateWindowW(L"edit",L"",WS_VISIBLE|WS_CHILD|WS_BORDER,180,50,50,20,hDlg3,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE|WS_CHILD,80,90,100,50,hDlg3,(HMENU)SUBMIT_STUDENTSNO,NULL,NULL);

    EnableWindow(hWnd,false);
}




LRESULT CALLBACK WProc(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch(msg)
    {   case WM_COMMAND:
            switch (wp)
            {

            case  ENTER_DETAILS:
                if(k==maxilim)
                {
                    MessageBoxW(hWnd,L"Maximum Number of Students reached",L"Limit",MB_OK|MB_ICONEXCLAMATION);
                    break;
                }
                else
                {
                     passwordDialog1(hWnd);
                    break;
                }
                break;

            case  CHECK_DETAILS:
                displayDialog2(hWnd);
                break;

            case  EXIT_KEY:
                int val;
                val=MessageBoxW(hWnd,L"Are you sure you want to exit ??",L"Exit",MB_YESNO|MB_ICONEXCLAMATION);
                if (val==IDYES)
                    {
                        temp=fina;
                    for(int j=0;j<k;j++)
                    {
                        delete temp;
                        temp++;
                    }
                    delete fina;
                    DestroyWindow(hWnd);
                    }
                break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_CLOSE:
            temp=fina;
            for(int j=0;j<k;j++)
            {
                delete temp;
                temp++;
            }
            delete fina;
            DestroyWindow(hWnd);
            break;
        case WM_CREATE:
             AddMenus(hWnd);
            AddControls(hWnd);

             myFile.open("Database.csv");
            myFile<<"NAME:"<<","<<"DOB:"<<endl;

            break;
        default:
            return DefWindowProcW(hWnd,msg,wp,lp);
    }
}

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR args,int ncmdshow)
{
    WNDCLASSW wc={0};
    wc.hbrBackground=(HBRUSH)COLOR_WINDOW;
    wc.hCursor=LoadCursor(NULL,IDC_ARROW);
    wc.hInstance=hInst;
    wc.lpszClassName=L"MyClass";
    wc.lpfnWndProc=WProc;

    if(!RegisterClassW(&wc))
        return -1;
    registerDialogClass1( hInst);
    registerDialogClass2( hInst);



    hMain=CreateWindowW(L"MyClass",L"Student DataBase",WS_OVERLAPPED|WS_VISIBLE,50,50,300,300,NULL,NULL,NULL,NULL);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

