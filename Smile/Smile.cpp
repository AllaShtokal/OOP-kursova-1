  
#include <time.h>
#include <string.h>
#include <windows.h>
#include "resource3.h"
#include "Class.h"
#include "ffunn.h"
#include "Serial.h"
using namespace std;
#define MAX_LOADSTRING 100
 
HACCEL hAccelTable;

TCHAR szWindowClass[MAX_LOADSTRING];

INT_PTR CALLBACK	NewDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);


LRESULT CALLBACK WndProc(HWND hwnd,UINT Message,WPARAM wParam,LPARAM lParam) 
{
	int x, y;
	PAINTSTRUCT ps;
	HDC hdc;
	HPEN hPen, holdPen;
	RECT rt;
	HICON hIcon;
	static int  first_time=1;
	if(first_time==1)
	{
		
	first_time=0;
	srand(time(NULL));
	InitializeArray();
	InitializeArrayKino();
	
	AddNewKino("KiNoTeATR <sAKURA>",300,500);
	AddNewKino("kiNO_vINNITSA",100,200);
	AddNewKino("KiNo1",500,100); 
	AddNewSmile("SMiLe", true, 100, 50,100,49);
	AddNewSmile22("SMiLe", true, 100, 120,200,200);
	AddNewSmile33("SMiLe", true, 100, 250,300,400);
	arr[3] = new Smile(*arr[2]); //copy const 1
	Smile a;
	a = *arr[1];//operator= для обєктів а не для вказівників 
	a.return_smile();//copy const 2
	a.get_smile(a);//copy const 3

	SetTimer(hwnd,1,180,NULL);
	SetTimer(hwnd,2,10000,NULL);
	

	
	}
	static int nHorizDifference=0,nVertDifference=0;
	static int nHorizPosition=0,nVertPosition;
	switch(Message)
	{ case WM_INITDIALOG:
	{hIcon = LoadIcon(GetModuleHandle(NULL),MAKEINTRESOURCE(IDI_ICON1));
	SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM) hIcon);}  
	
	
		break;
	
	case WM_COMMAND:
		// Parse the menu selections:
		switch (LOWORD(wParam))
		{
		
		
		
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
		}
	
	
	
	case WM_TIMER:
	switch (wParam)
	{
	case 1 :
		srand(time(NULL));
		AutoMove();
		vzaemodiya ();
		makrovzaemodiya();
		
		break;
	case 2:
		exitmakro();
		break;
		
	}


		WM_VSCROLL:
		switch (LOWORD(wParam))					
		{
		case SB_LINEDOWN:
			if (nVertPosition<nVertDifference)
				nVertPosition += 10;
			break;
		case SB_LINEUP:
			if (nVertPosition>0)
				nVertPosition -= 10;
			break;
		case SB_THUMBTRACK:
			nVertPosition = HIWORD(wParam);
			break;
		}
		SetScrollPos(hwnd, SB_VERT, nVertPosition, TRUE);
		InvalidateRect(hwnd, NULL, true);
		return 0;

	case WM_HSCROLL:
		switch (LOWORD(wParam))
		{
		case SB_LINEDOWN:
			if (nHorizPosition<nHorizDifference)
				nHorizPosition ++;
			break;
		case SB_LINEUP:
			if (nHorizPosition>0)
				nHorizPosition --;
			break;
		case SB_THUMBTRACK:
			nHorizPosition = (HIWORD(wParam));
			break;
		}
		SetScrollPos(hwnd, SB_HORZ, nHorizPosition, true);
		InvalidateRect(hwnd, NULL, true);

		
	
	
	case WM_KEYDOWN:
		{
		switch(wParam)
		{
		case VK_LEFT:
			MoveArray(-5,0);
			break;
		case VK_RIGHT:
			MoveArray(5,0);
			break;
		case VK_UP:
			MoveArray(0,-5);
			break;
		case VK_DOWN:
			MoveArray(0,5);
			break;
		case VK_ESCAPE:
			Active();
			break;
		case VK_DELETE:
		    Delete();
			break;
		case VK_F1:
		x=5+rand()%700;
		y=5+rand()%700;
		AddNewSmile( "SMiLe", (((x+y)%2)?true:false),x, y);
		::InvalidateRect(hwnd, NULL, FALSE);
		break;
		case VK_F2:
		x=5+rand()%700;
		y=5+rand()%700;
		AddNewSmile22( "SMiLe", (((x+y)%2)?true:false),x, y);
		::InvalidateRect(hwnd, NULL, FALSE);
		break;
		case VK_F3:
		x=5+rand()%700;
		y=5+rand()%700;
		AddNewSmile33( "SMiLe", (((x+y)%2)?true:false),x, y);
		::InvalidateRect(hwnd, NULL, FALSE);
		break;
		case VK_INSERT:
		DialogBoxA(hInst, MAKEINTRESOURCE(IDD_INSERT), hwnd, NewDialog);
		break;
		case 'T':
		case 't':
			DELETEPTALL();
			break;
			case 'm':
		case 'M':
			AutoMove2 ();
			break;
			
		//
		case 'a':
		case'A':
			if(pos_x<0)
			{
			MoveArrayNoActive(20,0);
			pos_x=pos_x+20;
			MoveArrayKino(20,0);}
			
			break;
		case 'w':
		case'W':
			if( pos_y<=0 )
			{MoveArrayNoActive(0,20);
			pos_y=pos_y+20;
			MoveArrayKino(0,20);}
			
			break;
		case 'd':
		case'D':
			if(pos_x+2200>1100)
			{
			MoveArrayNoActive(-20,0);
			pos_x=pos_x-20;
			MoveArrayKino(-20,0);}
			break;
			case 's':
		case'S':
			if( pos_y+1600>800 )
			{
			MoveArrayNoActive(0,-20);
			pos_y=pos_y-20;
			MoveArrayKino(0,-20);}
			break;
		case'z':
		case'Z':
			save();
			break;
			case'x':
		case'X':
			load();
			break;
		}
		::InvalidateRect(hwnd, NULL, FALSE);
		}break;
	case WM_RBUTTONDOWN:
		{
		x=LOWORD(lParam);
		y=HIWORD(lParam);
		if(Mouse_arrey(x,y))
		{
			::InvalidateRect(hwnd, NULL, FALSE);
		}
		}break;
	case WM_LBUTTONDOWN :
		x=LOWORD(lParam);
		y=HIWORD(lParam);
		
		AddNewSmile( "SMiLe", (((x+y)%2)?true:false),x, y);
		::InvalidateRect(hwnd, NULL, FALSE);
		break;
	case WM_PAINT:
		{

			hdc=BeginPaint(hwnd, &ps);
			{
			HDC hdcMem;
			RECT rt;
			HBITMAP hMemBitmap, holdbitmap;
			HBRUSH holdbrush;
			HPEN holdpen;
			
   
			::GetClientRect(hwnd, (LPRECT)&rt);
			hdcMem=CreateCompatibleDC(hdc);
			hMemBitmap=CreateCompatibleBitmap(hdc,rt.right, rt.bottom);
			holdbitmap=(HBITMAP)::SelectObject(hdcMem, hMemBitmap);
			holdbrush=(HBRUSH)::SelectObject(hdcMem, ::GetStockObject(WHITE_BRUSH));
			holdpen=(HPEN)::SelectObject(hdcMem, ::GetStockObject(NULL_PEN));
			::Rectangle(hdcMem, rt.left,rt.top, rt.right, rt.bottom);
			::SelectObject(hdcMem,holdbrush);
			::SelectObject(hdcMem, holdpen);
		
			if(kinomas[0]!=NULL)
				if(Misto::DrawBackground(hdcMem,2200,1600)==1 )
			{
			DrawArreyKino(hdcMem);}
			DrawArrey(hdcMem);
			//////////////////////////
			BitBlt(hdc, 0, 0, rt.right, rt.bottom, hdcMem, nHorizPosition, nVertPosition, SRCCOPY);
					 if ((nHorizDifference = (rt.right)) > 0)
						 SetScrollRange(hwnd, SB_HORZ, 0, nHorizDifference, TRUE);
					 else
						 SetScrollRange(hwnd, SB_HORZ, 0, 0, TRUE);

					 if ((nVertDifference = (rt.bottom)) > 0)
						 SetScrollRange(hwnd, SB_VERT, 0, nVertDifference, TRUE);
					 else
						 SetScrollRange(hwnd, SB_VERT, 0, 0, TRUE);
					 ////////
			
			::SelectObject(hdcMem, holdbitmap);
			::DeleteObject(hMemBitmap);
			::DeleteObject(hdcMem);
			}

			EndPaint(hwnd, &ps);
		}break;
	case WM_DESTROY:
		{
        
		PostQuitMessage(0);
		break;
		}
	default: return DefWindowProc(hwnd, Message, wParam, lParam);

	}
return 0;	
}
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;

	}
	return (INT_PTR)FALSE;
}

//////////////////////////
INT_PTR CALLBACK NewDialog(HWND hDlg, UINT Message, WPARAM wParam, LPARAM lParam)
{
	int x, y,tt=1;
	char buf[10];
	HWND hwndCtrl;
	UNREFERENCED_PARAMETER(lParam);
	switch (Message)
	{
	case WM_INITDIALOG:
		CheckRadioButton(hDlg, IDC_RADIO1, IDC_RADIO3, 0);
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{	EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			
		}
		//////
		if (LOWORD(wParam) == IDOK)
		{
			hwndCtrl = GetDlgItem(hDlg, IDC_EDIT2);
			GetWindowTextA(hwndCtrl, (LPSTR)buf, 100);
			x = atoi(buf);

			hwndCtrl = GetDlgItem(hDlg, IDC_EDIT3);
			GetWindowTextA(hwndCtrl, (LPSTR)buf, 100);
			y = atoi(buf);
			bool tr;
			hwndCtrl = GetDlgItem(hDlg, IDC_RADIO1);
			tr = SendMessageA(hwndCtrl, BM_GETCHECK, 0, 0);
			if (tr) tt = 1;
			hwndCtrl = GetDlgItem(hDlg, IDC_RADIO2);
			tr = SendMessageA(hwndCtrl, BM_GETCHECK, 0, 0);
			if (tr) tt = 2;
			hwndCtrl = GetDlgItem(hDlg, IDC_RADIO3);
			tr = SendMessageA(hwndCtrl, BM_GETCHECK, 0, 0);
			if (tr) tt = 3;
			if (tt==1) 			
		AddNewSmile( "SMiLe", (((x+y)%2)?true:false),x, y);
			if (tt==2) 			
		AddNewSmile22( "SMiLe", (((x+y)%2)?true:false),x, y);
			if (tt==3) 			
		AddNewSmile33( "SMiLe", (((x+y)%2)?true:false),x, y);

		

			
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}



		/////

		
		break;
	}
	return (INT_PTR)FALSE;
}








//////////////////////////////////
//LoadString(hInst, IDR_MENU1, szWindowClass, MAX_LOADSTRING);
//hAccelTable=LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_MENU1));
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
WNDCLASSEX wc;
HWND hwnd;
MSG Msg;
WNDCLASSEX wcex;

memset(&wc, 0, sizeof(wc));
wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; 
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; 
	wc.hInstance	 = hInstance;
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDR_MENU1);
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+2);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); 
	//wc.hIconSm		 = LoadIcon(NULL, IDI_ICON1); 
	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Smile_program",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		1100, /* width */
		800, /* height */
		NULL,NULL,hInstance,NULL);
		
		if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	
	while(GetMessage(&Msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&Msg); /* Translate key codes to chars if present */
		DispatchMessage(&Msg); /* Send it to WndProc */
	}
	return Msg.wParam;
}

