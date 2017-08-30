#pragma once
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <string.h>
#include <windows.h>
#include "iostream"
using namespace std;
 int pos_x=-550, pos_y=-400;
 HBITMAP bmpExercising;
 HINSTANCE hInst;
 
//////////////////////////
class Misto
{public:
	static int zm;
static int DrawBackground( HDC hdc, int wx, int wy )
			{bmpExercising = (HBITMAP)LoadImage( hInst ,"fon1.bmp",
			IMAGE_BITMAP,0,0,LR_LOADFROMFILE | LR_CREATEDIBSECTION ) ;
			HDC cDC=CreateCompatibleDC(hdc);
			HBITMAP old=(HBITMAP)SelectObject(cDC,bmpExercising); // bitmap=LoadBitmap(hMod,MAKEINTRESOURCE(BIT2)); - загружается из ресурсов dll
			wx=2200;
			wy=1600;
			StretchBlt( hdc,pos_x,pos_y,wx,wy,cDC,0,0,wx ,wy, SRCCOPY);
			SelectObject(cDC,old);
 
			 DeleteDC(cDC);
			 DeleteObject(bmpExercising);
   return 1;

} 
	 
};
class Entity
{
public:
	int x,y;
public:
Entity(int _x=50, int _y=50)
{	
x=_x; 
y=_y;}
virtual void fun()=0;
};
////////////////////////////////
class Kinoteatr:public Entity
{public:
int T1,T2,T3;
int wx, wy;
private:
int textx, texty;
char *name;
public:
 Kinoteatr(char *name="kinoteatr",  int _x=50, int _y=50, int _wx=200, int _wy=100, int _textx=30, int _texty=25,int _T1=0,int _T2=0,int _T3=0):Entity(_x,_y)
 {
 this->name= new char[strlen(name)+1];
		strcpy(this->name, name);

				 
	    wx=_wx; 
   	    wy=_wy;
		textx = _textx;
		texty = _texty;
		T1=_T1;
		T2=_T2;
		T3=_T3;
 
 }
 void fun()
 {int a;
 a++;
 
 }
void MoveKino(int dx,int dy)
{
	x=x+dx;
	y=y+dy;
}
 void DrawKino(HDC hdc)
{
HBRUSH hblackbrush, holdbrush;
HPEN hblackpen, holdpen;
///тєнь
hblackpen=CreatePen(PS_SOLID, 3, RGB(139,134, 130));
hblackbrush=CreateSolidBrush(RGB(139, 134, 130));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x,y+wy*2-23,x+wx*2+12,y+wy*2+20);
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
/////
hblackpen=CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
hblackbrush=CreateSolidBrush(RGB(148,0,211));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Rectangle(hdc, x,y,x+2*wx,y+2*wy);
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
//двері
hblackpen=CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
hblackbrush=CreateSolidBrush(RGB(255,255,100));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Rectangle(hdc, x+60,y+100,x+2*wx-60,y+2*wy-20);
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
//kolonu
hblackpen=CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
hblackbrush=CreateSolidBrush(RGB(255,255,100));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Rectangle(hdc, x+20,y+10,x+wx/3+5 ,y+2*wy-20);
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
//
hblackpen=CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
hblackbrush=CreateSolidBrush(RGB(255,255,100));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Rectangle(hdc, x+wx*2-40,y+10,x+wx*2-23,y+2*wy-20);
	POINT oldpoint;

::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
//текст
HFONT hfont;
LOGFONT lf;
		memset(&lf, 0, sizeof(lf));
		lf.lfHeight=-12;
		lf.lfItalic=false;
		lstrcpy((LPSTR)lf.lfFaceName, (LPCSTR)"Arial");
		hfont = CreateFontIndirect(&lf);
	HFONT holdfont= (HFONT)::SelectObject(hdc,hfont);
					COLORREF oldcol = ::GetTextColor(hdc);
			::SetTextColor(hdc,RGB(0,0,0) );
            ::TextOut( hdc, (int)(x+textx+50), (int)(y+wy+texty-5), (LPCSTR)name, lstrlen((LPCSTR)name) );  
			::SetTextColor(hdc,oldcol );
		
		::SelectObject(hdc,holdfont);

		::DeleteObject(hfont);
		///////////////11111
		
					char buffer[20];
			::SetTextColor(hdc,RGB(0,0,0) );
            ::TextOut( hdc, (int)(x+textx+25), (int)(y+wy+texty-65), (LPCSTR)itoa(T1,buffer,10), lstrlen((LPCSTR)itoa(T1,buffer,10)) );  
			::SetTextColor(hdc,oldcol );
		
		::SelectObject(hdc,holdfont);

		::DeleteObject(hfont);
		/////////////////2222
		char buffer2[20];
		::SetTextColor(hdc,RGB(0,0,0) );
            ::TextOut( hdc, (int)(x+textx+45), (int)(y+wy+texty-65),(LPCSTR)itoa(T2,buffer2,10), lstrlen((LPCSTR)itoa(T2,buffer2,10))  );  
			::SetTextColor(hdc,oldcol );
		
		::SelectObject(hdc,holdfont);

		::DeleteObject(hfont);
		///////////333
		char buffer3[20];
		::SetTextColor(hdc,RGB(0,0,0) );
            ::TextOut( hdc, (int)(x+textx+65), (int)(y+wy+texty-65), (LPCSTR)itoa(T3,buffer3,10), lstrlen((LPCSTR)itoa(T3,buffer3,10)) );  
			::SetTextColor(hdc,oldcol );
		
		::SelectObject(hdc,holdfont);

		::DeleteObject(hfont);


		


}
 ~Kinoteatr(){
  delete name;
  }
};
///////////////////////////////////
class Smile:public Entity
{
public:
char *name;
int wx, wy;
int x_m,y_m;
bool active;
int textx, texty;
public:
Smile(char *name="Smile",bool _active=false, int _x=50, int _y=50,int _x_m=10,int _y_m=555, int _wx=50, int _wy=50,
	  int _textx=30, int _texty=25)
	:Entity(_x,_y)
{
		this->name= new char[strlen(name)+1];
		strcpy(this->name, name);
		active=_active;
		 x_m=_x_m;
		 y_m=_y_m;
	    wx=_wx; 
   	    wy=_wy;
		textx = _textx;
		texty = _texty;
		
}
//////
Smile(const Smile &obj)
	{
		name = new char[strlen(obj.name) + 1];
        strcpy_s(name, strlen(obj.name) + 1, obj.name);
		wx = obj.wx;
		wy = obj.wy;
		x_m = obj.x_m;
		y_m = obj.y_m;
		textx=obj.textx;
		texty=obj.texty;
		active=obj.active;
		
	}
////
Smile & operator= (Smile &obj)
	{
		if (this == &obj) return (*this);
		delete []name ;
	    name = new char[strlen(obj.name) + 1];
        strcpy_s(name, strlen(obj.name) + 1, obj.name);
		wx = obj.wx;
		wy = obj.wy;
		x_m = obj.x_m;
		y_m = obj.y_m;
		textx=obj.textx;
		texty=obj.texty;
		active=obj.active;
		return (*this);

	}
////
friend ofstream &operator <<(ofstream&,Smile*);
void fun()
{int q=0;
}
void operator ++()//ynarnii operator++ 10
{
wx=wx+5;
wy=wy+5;
}
void operator --()//ynarnii operator-- 10
{
wx=wx-10;
wy=wy-10;
}
void get_smile(Smile rhs)
{
//для копіюючого конструктора
}
Smile return_smile()
{
return *this;
}
virtual int type()
{
return 1;}
//+
Smile operator+(Smile obj) { 
          Smile tmp;      
 tmp.wx = wx + obj.wx;  
 tmp.wy = wy + obj.wy;    
 return tmp;      // Повертає модифікований тимчасовий об'єкт 
}
 virtual void Draw(HDC hdc)
{
HBRUSH hblackbrush, holdbrush;
HPEN hblackpen, holdpen;

//ñìàéë
if (active)
{hblackpen=CreatePen(PS_SOLID, 3, RGB(160, 82 ,45));
hblackbrush=CreateSolidBrush(RGB(160, 82 ,45));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x-6,y+wy-6,x+wx+6,y+wy+6);
	//////
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );

////////
hblackpen=CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
hblackbrush=CreateSolidBrush(RGB(255, 0, 0));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x,y,x+wx,y+wy);
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
}
else
{hblackpen=CreatePen(PS_SOLID, 3, RGB(160, 82 ,45));
hblackbrush=CreateSolidBrush(RGB(160, 82 ,45));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x-6,y+wy-6,x+wx+6,y+wy+6);
	//////
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
////////
hblackpen=CreatePen(PS_SOLID, 1, RGB(255,165,0));
hblackbrush=CreateSolidBrush(RGB(255, 0, 0));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x,y,x+wx,y+wy);
}
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );

// 
		POINT oldpoint;
if (active)
{
hblackpen=CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
hblackbrush=CreateSolidBrush(RGB(255, 255, 255));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x+wx/4+10,y+wx/4,x+wx/4+10+12,y+wy/4+10);//î÷³
::Ellipse(hdc, x+wx/2+wx/4-10-12,y+wx/4,x+wx/2+wx/4-10,y+wx/4+10);//î÷³
Arc(hdc, x, y+27 , x+wx ,y+wy ,  x+wx, y+wy-21,x+5, y+wy-21 );  //óëèáêà

}
else
{
hblackpen=CreatePen(PS_SOLID, 2, RGB(0,0,0));
hblackbrush=CreateSolidBrush(RGB(255, 255, 0));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x+wx/4+10,y+wx/4,x+wx/4+10+12,y+wy/4+10);//î÷³
::Ellipse(hdc, x+wx/2+wx/4-10-12,y+wx/4,x+wx/2+wx/4-10,y+wx/4+10);//î÷³
Arc(hdc, x, y+27 , x+wx ,y+wy ,  x+wx, y+wy-21,x+5, y+wy-21 );
}
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
//text
HFONT hfont;
LOGFONT lf;
		memset(&lf, 0, sizeof(lf));
		lf.lfHeight=-12;
		lf.lfItalic=false;
		lstrcpy((LPSTR)lf.lfFaceName, (LPCSTR)"Arial");
		hfont = CreateFontIndirect(&lf);
	HFONT holdfont= (HFONT)::SelectObject(hdc,hfont);
					COLORREF oldcol = ::GetTextColor(hdc);
			::SetTextColor(hdc,RGB(255, 0, 0) );
            ::TextOut( hdc, (int)(x+textx-6), (int)(y+wy+texty-5), (LPCSTR)name, lstrlen((LPCSTR)name) );  
			::SetTextColor(hdc,oldcol );
		
		::SelectObject(hdc,holdfont);

		::DeleteObject(hfont);

}
bool Mouse_for_active(int mx, int my)
{
	if(mx<x)return false;
	if(!(mx<(x+wx)))return false;
	if(my<y)return false;
	if(!(my<(y+wy)))return false;

	active=!active;
	return true;
}
virtual void Move(int dx,int dy)
{   if (x+dx>pos_x && x+dx+wx<pos_x+2200)
 	x=x+dx;
if(y+dy>pos_y && y+dy+wy<pos_y+1600)
	y=y+dy;
}
void MoveAll(int dx,int dy)
{ if (x>=pos_x && x+wx<=pos_x+2200)
	x=x+dx;
if(y+dy>=pos_y && y+wy<=pos_y+1600)
	y=y+dy;

}
 virtual ~Smile(	)
{delete  []name;
}

};

ofstream &operator<<(ofstream&of,Smile*smile )
{  


	of<<smile->type()<<" "<<smile->name<<" "<<smile->active<<" "<<smile->textx<<" "
		<<smile->texty<<" "<<smile->x<<" "<<smile->wx<<" "<<smile->wy<<" "<<smile->x_m<<" "<<smile->y_m<<endl;
	return of;

}
///////////////////////////////////
class Smile22: public Smile
{
public:
   Smile22(char *name="Smile", bool _active=false, int _x=50, int _y=50,int _x_m=10,int _y_m=555,int _wx=100, int _wy=100,  int _textx=30, int _texty=25):
	   Smile(name,_active,_x,_y,_x_m,_y_m,_wx,_wy,_textx,_texty)
   {   }
   void Move(int dx,int dy)
{if (x+dx*2>=pos_x && x+dx*2+wx<=pos_x+2200)
	x=x+dx*2;
   	if(y+dy*2>=pos_y && y+dy*2+wy<=pos_y+1600)
	y=y+dy*2;
}
	
  void fun()
  {int k=0;}
  int type()
{
return 2;}
void Draw(HDC hdc)
{
HBRUSH hblackbrush, holdbrush;
HPEN hblackpen, holdpen;

//ñìàéë
if (active)
{
	hblackpen=CreatePen(PS_SOLID, 3, RGB(160, 82 ,45));
hblackbrush=CreateSolidBrush(RGB(160, 82 ,45));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x-6,y+wy-6,x+wx+6,y+wy+6);
	/////////
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
		//////////
hblackpen=CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
hblackbrush=CreateSolidBrush(RGB(255, 255, 0));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x,y,x+wx,y+wy);
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
}
else
{
	hblackpen=CreatePen(PS_SOLID, 3, RGB(160, 82 ,45));
hblackbrush=CreateSolidBrush(RGB(160, 82 ,45));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x-6,y+wy-6,x+wx+6,y+wy+6);
	////////
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
		////////
hblackpen=CreatePen(PS_SOLID, 1, RGB(0,0,0));
hblackbrush=CreateSolidBrush(RGB(255, 255, 0));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x,y,x+wx,y+wy);
}
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );

// текст
		POINT oldpoint;
if (active)
{
hblackpen=CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
hblackbrush=CreateSolidBrush(RGB(255, 255, 255));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x+wx/4+10,y+wx/4,x+wx/4+10+12,y+wy/4+10);//î÷³
::Ellipse(hdc, x+wx/2+wx/4-10-12,y+wx/4,x+wx/2+wx/4-10,y+wx/4+10);//î÷³
 ::MoveToEx(hdc,x+1.5*wx/8,y+wy/2+wy/4-10,&oldpoint);//óëèáêà
::LineTo (hdc,x+7*wx/8,y+wy/2+wy/4-10);//óëèáêà//óëèáêà

}
else
{
hblackpen=CreatePen(PS_SOLID, 2, RGB(0,0,0));
hblackbrush=CreateSolidBrush(RGB(255, 255, 0));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x+wx/4+10,y+wx/4,x+wx/4+10+12,y+wy/4+10);//î÷³
::Ellipse(hdc, x+wx/2+wx/4-10-12,y+wx/4,x+wx/2+wx/4-10,y+wx/4+10);//î÷³
::MoveToEx(hdc,x+1.5*wx/8,y+wy/2+wy/4-10,&oldpoint);//óëèáêà
::LineTo (hdc,x+7*wx/8,y+wy/2+wy/4-10);//óëèáêà
}
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
//òåêñò
HFONT hfont;
LOGFONT lf;
		memset(&lf, 0, sizeof(lf));
		lf.lfHeight=-12;
		lf.lfItalic=false;
		lstrcpy((LPSTR)lf.lfFaceName, (LPCSTR)"Arial");
		hfont = CreateFontIndirect(&lf);
	HFONT holdfont= (HFONT)::SelectObject(hdc,hfont);
					COLORREF oldcol = ::GetTextColor(hdc);
			::SetTextColor(hdc,RGB(255, 0, 0) );
            ::TextOut( hdc, (int)(x+textx-6), (int)(y+wy+texty-12), (LPCSTR)name, lstrlen((LPCSTR)name) );  
			::SetTextColor(hdc,oldcol );
		
		::SelectObject(hdc,holdfont);

		::DeleteObject(hfont);

}
~Smile22()
{};
};
//////////////////////////////////
class Smile33: public Smile22
{public: Smile33(char *name="Smile", bool _active=false, int _x=50, int _y=50,int _x_m=10,int _y_m=555, int _wx=100, int _wy=100,
int _textx=30, int _texty=25):
	Smile22(name,_active,_x,_y,_x_m,_y_m,_wx,_wy,_textx,_texty)
	{	
	
	}
	
void Draw(HDC hdc)
{
HBRUSH hblackbrush, holdbrush;
HPEN hblackpen, holdpen;


//ñìàéë
if (active)
{
	hblackpen=CreatePen(PS_SOLID, 3, RGB(160, 82 ,45));
hblackbrush=CreateSolidBrush(RGB(160, 82, 45));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x-6,y+wy-6,x+wx+6,y+wy+6);
	////
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
////////
hblackpen=CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
hblackbrush=CreateSolidBrush(RGB(0, 255, 0));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x,y,x+wx,y+wy);
///////
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );

}
else
{///
	hblackpen=CreatePen(PS_SOLID, 3, RGB(160, 82 ,45));
hblackbrush=CreateSolidBrush(RGB(160, 82 ,45));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x-6,y+wy-6,x+wx+6,y+wy+6);
	///
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
////////
hblackpen=CreatePen(PS_SOLID, 1, RGB(0,0,0));
hblackbrush=CreateSolidBrush(RGB(0, 255, 0));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x,y,x+wx,y+wy);
}
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );

// Î×² ³ óëèáêà
		POINT oldpoint;
if (active)
{
hblackpen=CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
hblackbrush=CreateSolidBrush(RGB(0, 255, 255));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x+wx/4+10,y+wx/4,x+wx/4+10+12,y+wy/4+10);//î÷³
::Ellipse(hdc, x+wx/2+wx/4-10-12,y+wx/4,x+wx/2+wx/4-10,y+wx/4+10);//î÷³
Arc(hdc, x, y , x+wx ,y+wy-21 , x+5, y+wy-21, x+wx, y+wy-21 );  //óëèáêà

}
else
{
hblackpen=CreatePen(PS_SOLID, 2, RGB(0,0,0));
hblackbrush=CreateSolidBrush(RGB(0, 255, 255));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x+wx/4+10,y+wx/4,x+wx/4+10+12,y+wy/4+10);//î÷³
::Ellipse(hdc, x+wx/2+wx/4-10-12,y+wx/4,x+wx/2+wx/4-10,y+wx/4+10);//î÷³
Arc(hdc, x, y , x+wx ,y+wy-21 , x+5, y+wy-21, x+wx, y+wy-21 );  //óëèáêà
}
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
//òåêñò
HFONT hfont;
LOGFONT lf;
		memset(&lf, 0, sizeof(lf));
		lf.lfHeight=-12;
		lf.lfItalic=false;
		lstrcpy((LPSTR)lf.lfFaceName, (LPCSTR)"Arial");
		hfont = CreateFontIndirect(&lf);
	HFONT holdfont= (HFONT)::SelectObject(hdc,hfont);
					COLORREF oldcol = ::GetTextColor(hdc);
			::SetTextColor(hdc,RGB(255, 0, 0) );
            ::TextOut( hdc, (int)(x+textx-6), (int)(y+wy+texty-12), (LPCSTR)name, lstrlen((LPCSTR)name) );  
			::SetTextColor(hdc,oldcol );
		
		::SelectObject(hdc,holdfont);

		::DeleteObject(hfont);

}
void Move(int dx,int dy)
{if (x+dx*3>=pos_x && x+dx*3+wx<=pos_x+2200)
	x=x+dx*3;
if(y+dy*3>=pos_y && y+dy*3+wy<=pos_y+1600)
	y=y+dy*3;
}
int type()
{
return 3;}
~Smile33()
{};
};
/////////////////////////////////////////////////
