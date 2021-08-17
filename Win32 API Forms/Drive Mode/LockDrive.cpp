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
#include <bits/stdc++.h>
#include <windows.h>

void LoadFrontend(HWND);
void BrowsePath(HWND);
void LoginPanel(HWND);
HWND hwndTextbox;
HWND hpassword ,hcpassword;

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
HWND hwndTextbox;
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
        //MessageBeep(MB_OK);
        BrowsePath(hwnd);
        
		break;
    
        case ID_BTN1:
        	
        //std::cout<<sty;
        
    //int len = GetWindowTextLengthW(GetDlgItem(hwnd, 2)) + 1;
    //wchar_t text[len];
    //GetWindowTextW(GetDlgItem(hwnd, 2), text, len);
    char password[30];
    
    GetWindowText(hpassword,password,30);
    //std::cout<<password;
    LoginPanel(hwnd);
    //MessageBoxW(NULL, name, L"MsgFromTextBox", MB_OK);
        	
        	
        	
        	//if (strcmp(password , cpassword) == 0)        
			//	{
			//	  system("start 123.vbs");
			//	} 
				//else{
					
					//MessageBoxW(NULL, "Password is not Correct", L"MsgFromTextBox", MB_OK);
				//}    
        	
        	
         break;
         
         
         case ID_BTN2:
         	
    char cpassword[30];
    
    //GetWindowText(hcpassword,cpassword,30);
    //std::cout<<cpassword;
       exit(0);
    
         	break;
    
    
    
    
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
        "LockDrive Mode Selected",
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

 system("call LockDrive.bat");
 system("echo 1 >Pathe8.txt");
// system("attrib +h +s Pathe8");
         std::string STRING;
	     std::ifstream infile;
	    infile.open("Pathe8.txt");
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

	        system("start ARx.vbs");
            char Create[100];
            std::ifstream file("Pathe8");
            if(!file)
	        {
     	     std::cout<<"Error in opening file";
     	     exit(1);
	        }
	         while(!file.eof())
	        {
	 	     file>>Create;
        	}
	         file.close();
	         
	        
	       
            //Logic For Creating Paths
         CreateWindow(TEXT("STATIC"),TEXT("Path::"),WS_CHILD | WS_VISIBLE |WS_CHILD, 6,30,40,20,hwnd,0,0,0);
		 CreateWindow(TEXT("EDIT"), TEXT(Create),
                    WS_VISIBLE|WS_CHILD|WS_BORDER|ES_AUTOHSCROLL,
                    50,30,260,20,
                    hwnd, (HMENU) ID_TEXTBOX, NULL, NULL);
 
               
                    
         CreateWindow(TEXT("button"), TEXT("Browse"),
                    WS_VISIBLE|WS_CHILD,
                    330,30,80,20,
                    hwnd, (HMENU) ID_BTN, NULL, NULL);
                    
        
		 
		
		        
                                       
        //           
        //            CreateWindow(TEXT("EDIT"), TEXT(""),
        //            WS_VISIBLE|WS_CHILD|WS_BORDER|ES_AUTOHSCROLL,
        //            140,80,150,20,
        //            hwnd, (HMENU) ID_TEXTBOX1, NULL, NULL);
                     
                     
                   CreateWindow(TEXT("STATIC"),TEXT("Enter Password::"),WS_CHILD | WS_VISIBLE |WS_CHILD, 5,80,120,20,hwnd,0,0,0); 
                   hpassword= CreateWindowW(L"EDIT", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 140,80,150,20, hwnd, (HMENU)2, NULL, NULL);
 
 
 
                   CreateWindow(TEXT("STATIC"),TEXT("Confirm Password::"),WS_CHILD | WS_VISIBLE |WS_CHILD |ES_READONLY, 5,130,130,20,hwnd,0,0,0);
                   hcpassword=CreateWindowW(L"EDIT", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 140,130,150,20, hwnd, (HMENU)2, NULL, NULL);
                   // CreateWindow(TEXT("EDIT"), TEXT(""),
                   // WS_VISIBLE|WS_CHILD|WS_BORDER|ES_AUTOHSCROLL,
                   // 140,130,150,20,
                   // hwnd, (HMENU) ID_TEXTBOX2, NULL, NULL);
                         
						
         CreateWindow(TEXT("button"), TEXT("Lock"),
                    WS_VISIBLE|WS_CHILD,
                    330,200,80,20,
                    hwnd, (HMENU) ID_BTN1, NULL, NULL);
                    
          CreateWindow(TEXT("button"), TEXT("Exit"),
                    WS_VISIBLE|WS_CHILD,
                    230,200,80,20,
                    hwnd, (HMENU) ID_BTN2, NULL, NULL);
         
 	
}

void LoginPanel(HWND hwnd)
{
	char cpassword[50];
    GetWindowText(hcpassword,cpassword,30);
    
    char password[50];
    
    GetWindowText(hpassword,password,30);
        
    //Convert Password into Strings For Login ID
                               
      for(int i = 0; (i < 100 && cpassword[i] != '\0'); i++)
      cpassword[i] = cpassword[i] + 3;
      
      
//std::ifstream fin(cpassword);

//if(fin.is_open()){
  //  std::cout<<"file is already Exist";
//}
    //system("pause");
    
FILE *loginFile;

struct employ 
    {
	 char Load_Pass[50];
	};
	char login1[50];
	char App_Password[50];
	char CreatePassword[50] ,confirm_Password[50];
	long int recsizelogin;
	struct employ e;
	recsizelogin = sizeof(e);
	
	loginFile=fopen(cpassword,"rb+");  //binary read/write files
      //system("attrib +h +s login.txt");
    if (loginFile == NULL)
    {
        loginFile = fopen(cpassword,"wb+");                 //rule defining for Creating Files 

        if (loginFile==NULL)
        {
            puts("Cannot open file");            //puts dispaly name on screen
                  
        }
        
    }
    
DWORD attributes = GetFileAttributes(cpassword);
SetFileAttributes(cpassword, attributes + FILE_ATTRIBUTE_HIDDEN);    
    
    for(int i = 0; (i < 100 && cpassword[i] != '\0'); i++)
    cpassword[i] = cpassword[i] - 3;
     //std::cout<<password;
     //std::cout<<cpassword;
     //system("pause");
     
     
    if (strcmp(password , cpassword) == 0)        
				{
							 
							 
				 for(int i = 0; (i < 100 && password[i] != '\0'); i++)
                 password[i] = password[i] + 2;                         //the key for encryption is 3 that is added to ASCII value
                 //cout<<CreatePassword<<endl;
				                            		                       //save new string in file
	             fseek(loginFile, - recsizelogin, SEEK_CUR);            //replace text string using seek_cur 
                 fwrite(password,recsizelogin,1,loginFile);
				 
				 
				 system("call Extenc.exe");			 
				 system("call Enc.exe ");
				 system("echo. >>FilesActive");
                 system("echo Drive Files Locked at %date% with %time% >>FilesActive");
				 system("echo. >>FilesActive");				 
				 system("call Lockxml.exe");
				// MessageBox(hwnd, "Your Password is Created Successfully", "Yo!", MB_OK);
				 
				 
				} 
				else
				{      system("echo 1 >12345");
					   for(int i = 0; (i < 100 && cpassword[i] != '\0'); i++)
                       cpassword[i] = cpassword[i] + 3;
					   MessageBox(hwnd, "Your Password did not match ", "damm", MB_OK);
					   std::ofstream myfile;
					   myfile.open("12345");
					   myfile<<cpassword;
					   myfile.close();
					   //system("start 12345.bat");
				}
    
	
}
