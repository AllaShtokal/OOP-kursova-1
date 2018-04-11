#include "Class.h"
int pos_x=-550, pos_y=-400;
void Kinoteatr::DrawKino(HDC hdc)
{
HBRUSH hblackbrush, holdbrush;
HPEN hblackpen, holdpen;
///shdow
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
//door
hblackpen=CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
hblackbrush=CreateSolidBrush(RGB(255,255,100));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Rectangle(hdc, x+60,y+100,x+2*wx-60,y+2*wy-20);
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );
//pillars
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
			::SetTextColor(hdc,RGB(0,0,0) );
            ::TextOut( hdc, (int)(x+textx+25), (int)(y+wy+texty-35), (LPCSTR)name, lstrlen((LPCSTR)name) );  
			::SetTextColor(hdc,oldcol );
		
		::SelectObject(hdc,holdfont);

		::DeleteObject(hfont);

}
void Kinoteatr::MoveKino(int dx,int dy)
{
	x=x+dx;
	y=y+dy;
}
////////////////////////////////////////////////////////////
void Smile::Draw(HDC hdc)
{
HBRUSH hblackbrush, holdbrush;
HPEN hblackpen, holdpen;

//
if (active)
{hblackpen=CreatePen(PS_SOLID, 3, RGB(160, 82 ,45));
hblackbrush=CreateSolidBrush(RGB(160, 82 ,45));
holdpen=(HPEN)::SelectObject( hdc, hblackpen );
holdbrush = (HBRUSH)::SelectObject( hdc, hblackbrush );
::Ellipse(hdc, x-6,y+wy-6,x+wx+6,y+wy+6);
	
::SelectObject( hdc, holdpen );
        DeleteObject( hblackpen );

		::SelectObject( hdc, holdbrush );
        DeleteObject( hblackbrush );


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
bool Smile::Mouse_for_active(int mx, int my)
{
	if(mx<x)return false;
	if(!(mx<(x+wx)))return false;
	if(my<y)return false;
	if(!(my<(y+wy)))return false;

	active=!active;
	return true;
}

////////////////////////////////////////////////////////////
 
 void Smile22::Draw(HDC hdc)
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

// text2
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
//
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
/////////////////////////////////////////////////////////
void Smile33:: Draw(HDC hdc)
{
HBRUSH hblackbrush, holdbrush;
HPEN hblackpen, holdpen;

//
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
//
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
