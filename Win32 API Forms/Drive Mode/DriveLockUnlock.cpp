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
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND,UINT, WPARAM, LPARAM);

void Buttons(HWND);
void addMenues(HWND);
void Loadfile(HWND);
void LoadLogoImage(HWND);
void displayDialog(HWND);
//void OpenDialogBox(HWND);
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
#define ID_BTN 1
#define ID_BTN2 2
#define ID_BTN3 3
#define ID_BTN4 4
#define ID_BTN5 5
#define ID_TEXTBOX 2
#define BROWSEINFO 0
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

                
                
                //LoadLogoImage(hwnd);
				//displayDialog(hwnd);       
				//OpenDialogBox(hwnd);

                               //asds
                    break;

             }




        case WM_COMMAND:
        {


        switch(wParam) {


        case ID_BTN:

        system("call LockDrive.exe");
    
            return -1;
			 break;

        case ID_BTN2:
        //MessageBeep(MB_OK);
        //Loadfile(hwnd);
        system("call UnlockDrive.exe");
        //OpenDialogBox(hwnd);
            

         
           return -1;
        
           	break;

        
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


	 CreateWindow(TEXT("button"), TEXT("Lock"),
                               WS_VISIBLE|WS_CHILD,
                               90,110,80,40,
                               hwnd, (HMENU) ID_BTN, NULL, NULL);


     CreateWindow(TEXT("button"), TEXT("Unlock"),
                               WS_VISIBLE|WS_CHILD,
                               270,110,80,40,
                               hwnd, (HMENU) ID_BTN2, NULL, NULL);

	 

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

void LoadLogoImage(HWND hwnd)
{
	std::cout<<"helo";
	
}

