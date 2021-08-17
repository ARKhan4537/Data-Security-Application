#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include <string>
#include <windows.h>
//#include <stdlib.h>
/*  Declare Windows procedure with name ARx */
LRESULT CALLBACK WindowProcedure (HWND,UINT, WPARAM, LPARAM);

void Buttons(HWND);
void addMenues(HWND);
void Loadfile(HWND);
void LoadLogoImage(HWND);
void registerDialogClass(HINSTANCE);
void displayDialog(HWND);
void addMenues1(HWND);
//void OpenDialogBox(HWND) with ARx;
HWND hwnd;
HMENU hMenu;

/*  Make the class name into a global variable Named ARx   */
char szClassName[ ] = "WindowsApp";
int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)



{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);
    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME +3+5+8);
    // COLOR_WINDOWFRAME +3+5+8
    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;
   // registerDialogClass(hThisInstance) ;   
    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "File Security V1.0 By Abdul Rehman Khan 37904",       /* Title Text */
           WS_SYSMENU,          /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           444,                 /* The programs width */
           275,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );
    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);
    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }
    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

HWND Add_Email;
HWND Remove;
#define ID_BTN 1
#define ID_BTN2 2
#define ID_BTN3 3
#define ID_BTN4 4
#define ID_BTN5 5
#define ID_TEXTBOX 2
#define BROWSEINFO 0
#define Add_Email1 12
#define Remove 0


static HWND hwndTextbox;

/*  This function is called by the Windows function DispatchMessage()  */
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

HWND hWnd1 = GetConsoleWindow();
ShowWindow( hWnd1, SW_HIDE );

    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
             {


                   // hwndTextbox = CreateWindow(TEXT("EDIT"), TEXT("Type Here"),
                   // WS_VISIBLE|WS_CHILD|WS_BORDER|ES_AUTOHSCROLL,
                   // 10,10,200,20,
                   // hwnd, (HMENU) ID_TEXTBOX, NULL, NULL);

                Buttons(hwnd);
                addMenues(hwnd);
                addMenues1(hwnd);
            //LoadLogoImage(hwnd);
			//displayDialog(hwnd);       
			//OpenDialogBox(hwnd);

                               //asds
                    break;

             }




        case WM_COMMAND:
        {


        switch(wParam) {


        case ID_BTN:{
			
    
	system("call UsbLockUnlock.exe");
     
        //if (LOWORD(wParam) == ID_BTN)
        //     {
                //create variables
                //int length = GetWindowTextLength(hwndTextbox) + 1;
                //static char title[500] = "";
                //GetWindowText(hwndTextbox,title,length);
                //MessageBox(hwnd, title, "Debug Box", MB_OK);
                // Creates a window displaying the text typed in the box.
                //SetWindowText(hwnd, title);
               //Loadfile(hwnd);
        //   }
        // else if (LOWORD(wParam) == ID_BTN2)
        //{



        //}
            return -1;
			 break;
}
        case ID_BTN2:{
			
        MessageBeep(MB_OK);
        //Loadfile(hwnd);
        system("call DriveLockUnlock.exe");
        //OpenDialogBox(hwnd);   
           return -1;
        
           	break;
                     }
        case ID_BTN4:{
			
			MessageBox(hwnd, "Browse USB Path For Install Module Please...", "USB Path", MB_OK);
			
            system("start StandAloneUsb.bat");
           	

            return -1;
           	break;
}
        case ID_BTN3:{
			

        
			
             
        	break;
}
        case ID_BTN5:{
		

         MessageBeep(MB_OK);
              
              return -1;
             //action for button
           break;
       }
       
       case Add_Email1:
	   {
       	
       	system("start Emailbody.exe");
       	
       	 //MessageBeep(MB_OK);
       	 
       	return -1;
		break;
		
	   }
	    
}

        }
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);



	}
    return 0;
}


void Buttons(HWND hwnd)
{


	 CreateWindow(TEXT("button"), TEXT("USB Mode"),
                               WS_VISIBLE|WS_CHILD,
                               60,50,120,20,
                               hwnd, (HMENU) ID_BTN, NULL, NULL);


     CreateWindow(TEXT("button"), TEXT("Drive Mode"),
                               WS_VISIBLE|WS_CHILD,
                               260,50,120,20,
                               hwnd, (HMENU) ID_BTN2, NULL, NULL);

	 CreateWindow(TEXT("button"), TEXT("Exit"),
                               WS_VISIBLE|WS_CHILD,
                               260,140,120,20,
                               hwnd, (HMENU) ID_BTN3, NULL, NULL);


     CreateWindow(TEXT("button"), TEXT("USB Standalone "),
                               WS_VISIBLE|WS_CHILD,
                               60,140,120,20,
                               hwnd, (HMENU) ID_BTN4, NULL, NULL);

}

void addMenues1(HWND hwnd)
{
//hMenu=CreateMenu();
//HMENU hFileMenu1= CreateMenu();
//HMENU hSubMenu1 = CreateMenu();	
//AppendMenu(hFileMenu1,MF_POPUP,(UINT_PTR)hSubMenu1,"Monitoring History");
//AppendMenu(hSubMenu1,MF_STRING,NULL,"USB Plugin");
//AppendMenu(hSubMenu1,MF_STRING,NULL,"Files Lock/Unlock");
//AppendMenu(hSubMenu1,MF_STRING,NULL,"Program Uses");	
	std::cout<<"hi";
}

void addMenues(HWND hwnd)
{
	
hMenu=CreateMenu();
HMENU hFileMenu= CreateMenu();
HMENU hSubMenu = CreateMenu();
HMENU hDisplayMenu = CreatePopupMenu();
//HMENU hFileMenu1= CreateMenu();
//HMENU hSubMenu1 = CreateMenu();

AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hFileMenu,"File");
AppendMenu(hFileMenu,MF_POPUP,(UINT_PTR)hSubMenu,"Email Reporting");
AppendMenu(hSubMenu,MF_STRING,Add_Email1,"Add Email");
AppendMenu(hSubMenu,MF_STRING,NULL,"Remove Email");
AppendMenu(hFileMenu,MF_SEPARATOR,NULL,NULL);


//AppendMenu(hFileMenu,MF_POPUP,(UINT_PTR)hSubMenu,"Monitoring History");
//AppendMenu(hSubMenu,MF_STRING,NULL,"USB Plugin");

//AppendMenu(hFileMenu,MF_STRING,NULL,"Email Report");

//AppendMenu(hSubMenu,MF_STRING,NULL,"Files Lock/Unlock");
//AppendMenu(hSubMenu,MF_STRING,NULL,"Program Uses");
//AppendMenu(hFileMenu,MF_STRING,NULL,"Monitoring History");


    //AppendMenu(hFileMenu,MF_STRING,NULL,"Monitoring History");
    AppendMenu(hFileMenu,MF_STRING,NULL,"Firewall");
    AppendMenu(hFileMenu,MF_STRING,NULL,"USB Plugin History");
    AppendMenu(hFileMenu,MF_STRING,NULL,"Lock/Unlock History");
    AppendMenu(hFileMenu,MF_STRING,NULL,"Program Uses History");
    AppendMenu(hFileMenu,MF_STRING,NULL,"Exit");
	AppendMenu(hMenu,MF_STRING,NULL,"View");
	AppendMenu(hMenu,MF_STRING,NULL,"About");
	AppendMenu(hMenu,MF_STRING,NULL,"Help");
	SetMenu(hwnd,hMenu);
	
}

void Loadfile(HWND hwnd)
{

        system("call filee.bat");
        std::string STRING;
	    std::ifstream infile;
	    infile.open ("Pathe.txt");
        while(!infile.eof()) // To get you all the lines.
        {
	        getline(infile,STRING); // Saves the line in STRING.
	        //std::cout<<STRING; // Prints our STRING.
             
         std::cout<<STRING;
 
        }
        
	    infile.close();	         
 
        system("call 123.vbs");
}



//void OpenDialogBox(HWND hwnd)
//{                                          Open DialogBox in C++
//OPENFILENAME ofn;
//char filename[100];
//ZeroMemory(&ofn,sizeof (OPENFILENAME));
//ofn.lStructSize = sizeof (OPENFILENAME);
//ofn.hwndOwner=hwnd;
//ofn.lpstrFile = filename;
//ofn.lpstrFile[0] = '\0';
//ofn.lpstrFilter="All files\0*.*\0Source Files\0*.cpp\0Text Files\0*.TXT\0";
//ofn.nMaxFile=100;
//ofn.nFilterIndex=1;
//GetOpenFileName(&ofn);
//}

//void LoadLogoImage(HWND hwnd)
//{
//	std::cout<<"helo";
	
//}

//LRESULT CALLBACK dialogProcedure(HWND hwnd,UINT msg, WPARAM wp, LPARAM IP)
//{
//switch(msg)
//{
//	case WM_CLOSE:
//		DestroyWindow(hwnd);
//		break;
	
//	default:
  //      return DefWindowProcW(hwnd,msg,wp,IP);	
//}	
	
	
//}


//void registerDialogClass(HINSTANCE hThisInstance)
//{

//WNDCLASS wincl={0};
//wincl.hbrBackground=(HBRUSH)COLOR_WINDOW;
//wincl.hCursor = LoadCursor (NULL,IDC_CROSS);
//wincl.hInstance=hThisInstance;
//wincl.lpszClassName = "myDialogClass";
//wincl.lpfnWndProc = WindowProcedure;

//dialog.lpfnWndProc = DialogProcedure;
//RegisterClassExW (&wincl);
	
//}


//void displayDialog(HWND hwnd)
//{

//CreateWindowW(L"myDialogClass",L"Dialog",WS_VISIBLE | WS_OVERLAPPEDWINDOW,400,400,200,200,hwnd,NULL,NULL,NULL);	
	
//}

//void loadImages()
//{
	
//hLogoImage=(HBITMAP)LoadImageW (NULL,L, "Logo.bmp", IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
//hGenerate Image=(HBITMAP)LoadImageW (NULL,L, "GENERATE.bmp", IMAGE_BITMAP,98,38,LR_LOADFROMFILE);
	
	
	
//}
