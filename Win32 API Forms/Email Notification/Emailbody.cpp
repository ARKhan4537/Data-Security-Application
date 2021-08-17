#include <windows.h>
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

void LoadFrontend(HWND);
void BrowsePath(HWND);
HWND hwndTextbox;
HWND hEmail;

const char g_szClassName[] = "myWindowClass";
#define ID_BTN  0
#define ID_BTN1 1
#define ID_BTN2 2
#define ID_TEXTBOX 0
//Step 4: the Window Procedure
//by Arx


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
HWND hWnd1 = GetConsoleWindow();
ShowWindow( hWnd1, SW_HIDE );
	//HWND hwndTextbox;
    switch(msg)
    {
    	case WM_CREATE:
		{
			
    		
    		LoadFrontend(hwnd);
    		
    	    break;	
    	
        }
    	
    	break;
    	
    	
    	case WM_COMMAND:
		{
	  		
    	switch (wParam) 
		{
        
        case ID_BTN:{
			
        	
        
        char Email[30];
        GetWindowText(hEmail,Email,30);
        system("echo >Email");
        std::ofstream EmailFile;
        EmailFile.open("Email");
        EmailFile<<Email;
        EmailFile.close();
        system("xcopy Email %systemdrive%\\FileSecurity\\standaloneUSB\\ /y");
        system("xcopy Email %systemdrive%\\FileSecurity\\DriveMode\\ /y");
        system("del Email ");
    //    BrowsePath(hwnd);
        MessageBox(hwnd, "Email Add Successfully ..Now You Receive Report", "Yo!", MB_OK);
        
		break;
}
		case ID_BTN1:{
			
		MessageBeep(MB_OK); 
		exit(0);  
		break;
	}
		
	       }
           }
	    break;	
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE+2);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Email Panel",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 444, 275,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Step 3: The Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}


//void BrowsePath(HWND hwnd)
//{
	
 //system("call filee.bat");
         //std::string STRING;
	     //std::ifstream infile;
	    //infile.open ("Pathe.txt");
        //while(!infile.eof()) // To get you all the lines.
        //{
	      //  getline(infile,STRING); // Saves the line in STRING.
	        //std::cout<<STRING; // Prints our STRING.
             
        // std::cout<<STRING;
 
      //  }
        
	//    infile.close();	         
 
  //      system("call 123.vbs");	
//}


void LoadFrontend(HWND hwnd)
{	                   
            //CreateWindow(TEXT("STATIC"),TEXT("Enter Email::"),WS_CHILD | WS_VISIBLE |WS_CHILD, 20,100,400,400,hwnd,0,0,0);
            //CreateWindow(TEXT("EDIT"), TEXT(""),
            //WS_VISIBLE|WS_CHILD|WS_BORDER|ES_AUTOHSCROLL,
            //140,100,150,20,
            //hwnd, (HMENU) ID_TEXTBOX1, NULL, NULL);
 
            CreateWindow(TEXT("STATIC"),TEXT("Enter Email::"),WS_CHILD |WS_VISIBLE, 10,100,150,20,hwnd,0,0,0);     
            hEmail=CreateWindowW(L"EDIT", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 170,100,250,20, hwnd, (HMENU)2, NULL, NULL);
 
                    
                    
           CreateWindow(TEXT("button"), TEXT("OK"),
                    WS_VISIBLE|WS_CHILD,
                    330,200,80,20,
                    hwnd, (HMENU) ID_BTN, NULL, NULL);
                    
           CreateWindow(TEXT("button"), TEXT("Exit"),
                    WS_VISIBLE|WS_CHILD,
                    230,200,80,20,
                    hwnd, (HMENU) ID_BTN1, NULL, NULL);
         
 	
}
