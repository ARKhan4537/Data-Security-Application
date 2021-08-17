#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include <string>
#include <bits/stdc++.h>
#include <windows.h>

void LoadFrontend(HWND);
void BrowsePath(HWND);
void Unlock(HWND);
HWND hwndTextbox;
HWND hpassword;

const char g_szClassName[] = "myWindowClass";
#define ID_BTN 0
#define ID_BTN1 1
#define ID_BTN2 2
#define ID_TEXTBOX 0
#define ID_TEXTBOX1 1
#define ID_TEXTBOX2 2

// Step 4: the Window Procedure



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
        

        case ID_BTN:
        MessageBeep(MB_OK);
        BrowsePath(hwnd);
        
		break;
		
		case ID_BTN1:
		  
		  	Unlock(hwnd);
		  
		  break;
		  
		  case ID_BTN2:
		  	exit(0);
    
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
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME +3+5+8);
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
        "UnlockUSB Mode Selected",
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


void BrowsePath(HWND hwnd)
{
	
 system("call standaloneUSBUNLOCK.bat");
 system("echo 1 >Pathe ");
 system("attrib +h +s Pathe");
         std::string STRING;
	     std::ifstream infile;
	    infile.open ("Pathe");
        while(!infile.eof()) // To get you all the lines.
        {
	        getline(infile,STRING); // Saves the line in STRING.
	        //std::cout<<STRING; // Prints our STRING.
             
         std::cout<<STRING;
 
        }
        
	    infile.close();	         
 
        system("call 123.vbs");	
}


void LoadFrontend(HWND hwnd)
{	

	
            //char Create[100];
            //system("echo 1 >Pathe1.txt");
            //std::ifstream file("Pathe1.txt");
            //if(!file)
	        //{
     	     //std::cout<<"Error in opening file";
     	     //exit(1);
	        //}
	         //while(!file.eof())
	        //{
	 	     //file>>Create;
        	//}
	         //file.close();
         
		    
         //CreateWindow(TEXT("STATIC"),TEXT("Path::"),WS_CHILD | WS_VISIBLE |WS_CHILD, 6,30,40,20,hwnd,0,0,0);
		 //CreateWindow(TEXT("EDIT"), TEXT(Create),
                    //WS_VISIBLE|WS_CHILD|WS_BORDER|ES_AUTOHSCROLL,
                    //50,30,260,20,
                    //hwnd, (HMENU) ID_TEXTBOX, NULL, NULL);
 
         
                    
         //CreateWindow(TEXT("button"), TEXT("Browse"),
                    //WS_VISIBLE|WS_CHILD,
                    //330,30,80,20,
                    //hwnd, (HMENU) ID_BTN, NULL, NULL);
                             
                                       
                    CreateWindow(TEXT("STATIC"),TEXT("Unlock Password::"),WS_CHILD | WS_VISIBLE |WS_CHILD, 30,100,130,20,hwnd,0,0,0);
                    hpassword=CreateWindow(TEXT("EDIT"), TEXT(""),
                    WS_VISIBLE|WS_CHILD|WS_BORDER|ES_AUTOHSCROLL,
                    170,100,230,20,
                    hwnd, (HMENU) ID_TEXTBOX1, NULL, NULL);
 
 
                    //CreateWindow(TEXT("STATIC"),TEXT("Confirm Password::"),WS_CHILD | WS_VISIBLE |WS_CHILD |ES_PASSWORD|ES_READONLY, 5,130,400,400,hwnd,0,0,0);
                    //CreateWindow(TEXT("EDIT"), TEXT(""),
                    //WS_VISIBLE|WS_CHILD|WS_BORDER|ES_AUTOHSCROLL,
                    //140,130,150,20,
                    //hwnd, (HMENU) ID_TEXTBOX2, NULL, NULL);
                    
                    
          CreateWindow(TEXT("button"), TEXT("Unlock"),
                    WS_VISIBLE|WS_CHILD,
                    330,200,80,20,
                    hwnd, (HMENU) ID_BTN1, NULL, NULL);
                    
          CreateWindow(TEXT("button"), TEXT("Exit"),
                    WS_VISIBLE|WS_CHILD,
                    230,200,80,20,
                    hwnd, (HMENU) ID_BTN2, NULL, NULL);
         
 	
}

void Unlock(HWND hwnd)
{
	
	
	char password[30];
    GetWindowText(hpassword,password,30);
     
     for(int i = 0; (i < 100 && password[i] != '\0'); i++)
         password[i] = password[i] + 3;
		
		 std::ifstream ifile(password);
         if (!ifile) {
         //system("start 123.vbs");
         MessageBox(hwnd, "Your Password is not Correct ", "ho!", MB_OK);
                       system("echo 1>12345.txt");
					   std::ofstream myfile;
					   myfile.open("12345.txt");
					   myfile<<password;
					   myfile.close();
					  
					             
                     } 
		       
	  FILE *loginFile;



struct save 
    {
	 char Load_Pass[50];
	};
	
	char login1[50];
	char App_Password[50];
	char CreatePassword[50] ,confirm_Password[50];
	long int recsizelogin;
	 struct save e;
	 recsizelogin = sizeof(e);
	
	loginFile=fopen(password,"rb+");  //binary read/write files
    //  system("attrib +h +s login.txt");
    if (loginFile == NULL)
    {
        loginFile = fopen(password,"wb+");                 //rule defining for Creating Files 

        if (loginFile==NULL)
        {
            puts("Cannot open file");            //puts dispaly name on screen
                
        }
    }
    DWORD attributes = GetFileAttributes(password);
SetFileAttributes(password, attributes + FILE_ATTRIBUTE_HIDDEN);
    
    //fseek(loginFile, 0, SEEK_END);
    
		
    
    
	if (ftell(loginFile) == 0) 
 {
 	
 	 for(int i = 0; (i < 100 && password[i] != '\0'); i++)
     password[i] = password[i] - 3;
            
 	while (fread(CreatePassword,recsizelogin,1,loginFile) == 1)              //Read string from a file and store into a variable e with loop
            {
						                                                             //use as input stream/output streem        
			for(int i = 0; (i < 100 && CreatePassword[i] != '\0'); i++)
            CreatePassword[i] = CreatePassword[i] - 2;
			                                                          //the key for encryption is 3 that is subtracted to ASCII value
			if (strcmp(password , CreatePassword) == 0)        
				{
	
	             system("taskkill /f /im cmd.exe");
	             remove("file.txt");
	             system("call Extdec.exe");
				 system("start CryptoDec.exe");
				 system("call UnLockxml.exe");
				 system("attrib -h -s *.*");
				 system("ren *.exe *.fileexe");
				 system("ren *.bat *.filebat");
				 system("ren USB.fileexe USB.exe");
				 system("attrib +h +s *.fileexe");	
				 system("attrib +h +s *.filebat");
				  MessageBox(hwnd, "Your Files are Unlock Successfully ", "Yo!", MB_OK);
	                
				  
				}                 
				else
				{
					
				  MessageBox(hwnd, "Your Password is not Correct ", "ho!", MB_OK);
		                  
				}                  
            
			}	
}
}
