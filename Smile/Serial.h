#pragma once
#include <fstream>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <ctime>
#include <string.h>
#include <algorithm>
#include <functional>
#include "vector"
#include <string>
#include <commdlg.h>
#include <iostream>
using namespace std;
//#include "Class.h"
//#include "ffunn.h"

void save()
{	OPENFILENAME ofn;
	char szFileName[500] = ""; // αστεπ ο³δ ³μÿ τΰιλσ
	memset(&ofn, 0, sizeof(ofn));
	GetCurrentDirectory(sizeof(szFileName), szFileName);
	strcat(szFileName, "\\*.*");
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL; //hWnd;
	ofn.lpstrFile = szFileName;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFileName);
	ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST; //| OFN_FILEMUSTEXIST;
	ofn.Flags = OFN_CREATEPROMPT;

	if (GetSaveFileName(&ofn))
	{
		char buffer[200];
		ofstream ofs(szFileName, std::ofstream::out);
			
		for (int i = 0; i < ARR_SIZE; ++i)
		{
			if (arr[i])
			{
				ofs << arr[i];
			}
		}
		ofs<<100000<<endl;
			for (int i = 0; i < KINOMAS_SIZE; ++i)
		{
			ofs<<kinomas[i]->T1<<" "<<kinomas[i]->T2<<" "<<kinomas[i]->T3<<endl;
		}
		ofs.close();
}
	}
void load()
{
	char szFileName[500] = "";             
	OPENFILENAME ofn;
	memset(&ofn, 0, sizeof(ofn));
	GetCurrentDirectory(sizeof(szFileName), szFileName);
	strcat(szFileName, "\\*.*");
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL; //hWnd;
	ofn.lpstrFile = szFileName;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFileName);
	ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST; 
	ofn.Flags = OFN_CREATEPROMPT | OFN_FILEMUSTEXIST;
	int typ;

		if (GetOpenFileName(&ofn))
	{	ifstream ifs;
	ifs.open(szFileName);
	for(int i = 0; i < ARR_SIZE; ++i)
	{
	arr[i]=NULL;
	}
	for(int i = 0; i < 100; ++i)
	{
		char a[10],*b;
		
		ifs>>typ;
		if (typ==1)
			arr[i]=new Smile;
		if(typ==2)
			arr[i]=new Smile22;
		if(typ==3)
			arr[i]=new Smile33;
			if(typ==100000)
				break;
		ifs>>a>>arr[i]->active>>arr[i]->textx
		>>arr[i]->texty>>arr[i]->x>>arr[i]->wx>>arr[i]->wy>>arr[i]->x_m>>arr[i]->y_m;
		b=a;
		arr[i]->name=new char [strlen(b)+1];
		
		strcpy_s(arr[i]->name,strlen(b)+1,b);

	}

	for (int i = 0; i < KINOMAS_SIZE; ++i)
		{
			ifs>>kinomas[i]->T1>>kinomas[i]->T2>>kinomas[i]->T3;
		}

		
		ifs.close();


	}
}
