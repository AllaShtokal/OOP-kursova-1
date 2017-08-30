#pragma once
#include <string.h>
#include <windows.h>
#include "Class.h"
#define ARR_SIZE 50
#define KINOMAS_SIZE 3
#define tx 50
#define ty 50
#define tul 15
#define tulx 15
#define tuly 15


 Kinoteatr**kinomas;
 Smile **arr;
 void Active()
{
	for(int i=0; i<ARR_SIZE; i++)
	{
	if(arr[i]!=NULL)
	{
		if(arr[i]->active)
			arr[i]->active=!(arr[i]->active);
	}
	}
}
void Delete()
{
	
	for(int i=0; i<ARR_SIZE; i++)
	{
	if(arr[i]!=NULL)
	{
		if(arr[i]->active)
			{
				arr[i]=NULL;
			}
	}
	}

}
void MoveArray(int dx,int dy)
{
	for(int i=0; i<ARR_SIZE; i++)
	{
	if(arr[i]!=NULL)
	{
		if(arr[i]->active)
			arr[i]->Move(dx,dy);
	}
	}
}
void MoveArrayNoActive(int dx,int dy)
{
	for(int i=0; i<ARR_SIZE; i++)
	{
	if(arr[i]!=NULL)
	{
				arr[i]->MoveAll(dx,dy);
	}
	}
}
void MoveArrayKino(int dx,int dy)
{
	for(int i=0; i<KINOMAS_SIZE; i++)
	{
	if(kinomas[i]!=NULL)
	{
				kinomas[i]->MoveKino(dx,dy);
	}
	}
}
 bool Mouse_arrey(int mx, int my)
{
	bool result = false;
	bool r;
	for(int i=0; i<ARR_SIZE; i++)
	{
	if(arr[i]!=NULL)
	{
		r=arr[i]->Mouse_for_active(mx,my);
		result=result||r;
	}
	}
	return result;
}
 void InitializeArray()
{
arr=new Smile*[ARR_SIZE];
for(int i=0; i< ARR_SIZE; i++)
{
arr[i]=NULL;
}
}
 void InitializeArrayKino()
{
kinomas=new Kinoteatr*[ARR_SIZE];
for(int i=0; i< ARR_SIZE; i++)
{
kinomas[i]=NULL;
}
}
 bool AddNewSmile(char *name="Tom", bool _active=false, int _x=50, int _y=50,int _x_m=rand()%300,int _y_m=rand()%200 , int _wx=50, int _wy=50, int _textx=16, int _texty=13)
{
if(arr==NULL)return false;
for(int i=0; i<ARR_SIZE; i++)
{
if(arr[i]==NULL)
{
arr[i]= new Smile(name, _active, _x, _y,_x_m, _y_m,  _wx, _wy, _textx,  _texty);
return true;
}
}
return false;
}
 bool AddNewSmile22(char *name="Tom", bool _active=false, int _x=50,int _y=50,int _x_m=rand()%800,int _y_m=rand()%200 , int _wx=50, int _wy=50, int _textx=16, int _texty=13)
{
if(arr==NULL)return false;
for(int i=0; i<ARR_SIZE; i++)
{
if(arr[i]==NULL)
{
arr[i]= new Smile22(name, _active, _x, _y,_x_m, _y_m, _wx, _wy, _textx,  _texty);
return true;
}
}
return false;
}
  bool AddNewSmile33(char *name="Tom", bool _active=false, int _x=50, int _y=50,int _x_m=rand()%800,int _y_m=rand()%200 , int _wx=50, int _wy=50,int _textx=16, int _texty=13)
{
if(arr==NULL)return false;
for(int i=0; i<ARR_SIZE; i++)
{
if(arr[i]==NULL)
{
arr[i]= new Smile33(name, _active, _x, _y,_x_m, _y_m, _wx, _wy, _textx,  _texty);
return true;
}
}
return false;
}
   bool AddNewKino(char *name="Tom", int _x=50, int _y=50, int _wx=100, int _wy=100,int _textx=30, int _texty=35)
{
if(kinomas==NULL)return false;
for(int i=0; i<ARR_SIZE; i++)
{
if(kinomas[i]==NULL)
{
kinomas[i]= new Kinoteatr(name, _x, _y,  _wx, _wy, _textx,  _texty);
return true;
}
}
return false;
}
 void DrawArrey(HDC hdc)
{
	if(arr==NULL)return;
	else
	for(int i=0; i<ARR_SIZE; i++)
	{
	if(arr[i]!=NULL) arr[i]->Draw(hdc);
	}
}
 void DrawArreyKino(HDC hdc)
{
	if(kinomas==NULL)return;
	else
	for(int i=0; i<ARR_SIZE; i++)
	{
	if(kinomas[i]!=NULL) kinomas[i]->DrawKino(hdc);
	}
}
 bool DELETEPT(Entity* my_a)
{//лише 3-ого типу
	
	
	Smile33* m_t = dynamic_cast<Smile33*>(my_a);
 	if ( m_t  )
		return true;
	
}
 void DELETEPTALL()
 {for(int i(0);i<ARR_SIZE;i++)
 { if (arr[i]!=NULL)
	{if( DELETEPT(arr[i]))
	//delete arr[i];
	 arr[i]=NULL;}
  
 }

 }
 void Tochkanaznaceniya() //встановлює початкову точку призначення 
 {
	 for(int i=0; i<ARR_SIZE; i++)
	{
	if(arr[i]!=NULL)
	{ srand(time(NULL));
		arr[i]->x_m=rand()%1000;
		srand(time(NULL));
	arr[i]->y_m=rand()%700 +i^2+55;
	
	}
	}
 }
 void AutoMove2 ()
 {
	 for(int i=0; i<ARR_SIZE; i++)
	{
	if(arr[i]!=NULL)//якшо не NUUL
	{ srand(time(NULL));
	int k;
	k=rand()%3+1;
	if(k==1)
		{arr[i]->x_m=kinomas[0]->x+30;
	     arr[i]->y_m=kinomas[0]->y+30;}
			if(k==2)
{arr[i]->x_m=kinomas[1]->x+30;
	     arr[i]->y_m=kinomas[1]->y+30;}

			if(k==3)
				{arr[i]->x_m=kinomas[2]->x+30;
	     arr[i]->y_m=kinomas[2]->y+30;}
	      
	}
 
 }
 }
  void AutoMove() // автоматичний рух
 { 
	for(int i=0; i<ARR_SIZE; i++)
	{
	if(arr[i]!=NULL)//якшо не NUUL
	{ srand(time(NULL));
	        if (arr[i]->x>arr[i]->x_m-25 && arr[i]->x<arr[i]->x_m+25 && arr[i]->y>arr[i]->y_m-25 && arr[i]->y<arr[i]->y_m+25 ) //якщо вже знаходиться у кінцевій точці
			      { srand(time(NULL));
					  arr[i]->x_m=rand()%2200-400; //нові координати обираємо для кінцевої точки
					  
				               arr[i]->y_m=rand()%1600;}
			else {
				//перевірка чи співпадають координати по іксу
				            if(arr[i]->x>arr[i]->x_m-25 && arr[i]->x<arr[i]->x_m+25)  // якщо так то
							{          
								            //змінюємо ігрик
								if(arr[i]->y>arr[i]->y_m)//якщо координата по у більша ніж ігрикова координата кінцевої точки
								{     arr[i]->Move(0,-5);      //зменшити координату по ігрику на 1
								
								}
								else arr[i]->Move(0,5); //інакше збільшити координату по ігрику

							}
							else           //змінюємо ікс
							{
							    if(arr[i]->x>arr[i]->x_m)
									arr[i]->Move(-5,0);
								else arr[i]->Move(5,0);;
							
							}
			}
	}
	 }
 }
  int tip(Smile* my_a)
{		
	Smile33* m_t = dynamic_cast<Smile33*>(my_a);
 	if ( m_t  )
		return 3;
	else
 {  Smile22* m_t = dynamic_cast<Smile22*>(my_a);
 	if ( m_t  )
	return 2;
	else{
 Smile* m_t = dynamic_cast<Smile*>(my_a);
 	if ( m_t  )
		return 1;}}
}
  void vzaemodiya ()
  {for(int i=0; i<ARR_SIZE; i++)
	{
	if(arr[i]!=NULL)
	{
			for(int j=0; j<ARR_SIZE; j++)
			{ if(arr[j]!=NULL)
				{if (arr[i]->x>(arr[j]->x-50) && (arr[i]->x)<(arr[j]->x+50) &&  arr[i]->y>(arr[j]->y-50) && arr[i]->y<(arr[j]->y+50) )
							{
								
							if (tip(arr[i])==1 && tip(arr[j])==2)
									{           
										        
												AddNewSmile22("SMiLe", true, arr[i]->x, arr[i]->y,rand()%300,rand()%600);
												 arr[i]=NULL;
												 return;
								
								   }
								if(tip(arr[i])==1 && tip(arr[j])==3)
								{
										AddNewSmile22("SMiLe", true, arr[i]->x, arr[i]->y,rand()%300,rand()%600);
												 arr[i]=NULL;
												 return;
								
								}

								if(tip(arr[i])==2 && tip(arr[j])==3)
								{
										AddNewSmile33("SMiLe", true, arr[i]->x, arr[i]->y,rand()%300,rand()%600);
												arr[i]=NULL;
												return;
								
								}
									
							}
						
				
				}

			}
			}
			
	}
	}
 void makrovzaemodiya()  
 {  for(int j=0; j<KINOMAS_SIZE; j++)
			{	if(kinomas[j]!=NULL)	 
						    {	for(int i=0; i<ARR_SIZE; i++)
								 {
	               if(arr[i]!=NULL)
			    {

					if(arr[i]->x+50<kinomas[j]->x+kinomas[j]->wx*2 && arr[i]->x>kinomas[j]->x &&
						arr[i]->y+50<kinomas[j]->y+kinomas[j]->wy*2 && arr[i]->y>kinomas[j]->y)
										{
											if (tip(arr[i])==1)
											{kinomas[j]->T1++;
											arr[i]=NULL;}
											
											else
											if (tip(arr[i])==2)
											{kinomas[j]->T2++;
											arr[i]=NULL;}else
											

											if (tip(arr[i])==3)
											{kinomas[j]->T3++;
											arr[i]=NULL;
											}
										}





				}



								  }
							 }
										        

	}
  }
  void exitmakro()  
 { 
	 srand(time(NULL));
	 int ran,rann;
    ran=rand()%KINOMAS_SIZE;
	rann=1||2||3;

  if (rann==1 && kinomas[ran]->T1>0)
			{
				 kinomas[ran]->T1--;
				AddNewSmile("SMiLe", true, kinomas[ran]->x-kinomas[ran]->wx , 
					kinomas[ran]->y,rand()%2200-30000,rand()%2200-30000);
	 
			 }
  else 
	  if (rann==2 && kinomas[ran]->T2>0)
			{
				 kinomas[ran]->T2--;
				AddNewSmile22("SMiLe", true, kinomas[ran]->x-kinomas[ran]->wx , 
					kinomas[ran]->y,rand()%2200-30000,rand()%2200-30000);
	 
			 }
	  else 
		   if (rann==3 && kinomas[ran]->T3>0)
			{
				 kinomas[ran]->T3--;
				AddNewSmile33("SMiLe", true, kinomas[ran]->x-kinomas[ran]->wx , 
					kinomas[ran]->y ,rand()%2200-30000,rand()%2200-30000);
	 
			 }



  

 }
											
