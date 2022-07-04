#include<reg52.h>
#define GPIO_DIG P0 
#define GPIO_KEY P1
unsigned char code smgduan[17]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8, 0x80,0x90};
sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4; 
unsigned int KeyValue;

sbit k1=P3^1; 
sbit k2=P3^0; 
sbit k3=P3^2; 
sbit k4=P3^3; 
unsigned int a=0;
 unsigned int b;
 unsigned int c;
 unsigned int d;
void delay(unsigned int i)
{
 while(i--);
}
void smgplay()
{
unsigned int i;
for(i=0;i<4;i++)
 { 
  switch(i)
 {
	case(0): LSA=1;LSB=1;LSC=1; GPIO_DIG=~smgduan[d]; break;
	case(1): LSA=0;LSB=1;LSC=1;GPIO_DIG=~smgduan[c];  break;
	case(2): LSA=1;LSB=0;LSC=1; GPIO_DIG=~smgduan[b]; break; 
	case(3): LSA=0;LSB=0;LSC=1;GPIO_DIG=~smgduan[a];  break;
	
  }
  	delay(100);
    P0=0x00;
 }
}

 void keypros() 
 {  

  if(k1==0)  
   { delay(1000);  
     if(k1==0)  
      {a +=1 ;
      }
	 }
	else  if(k2==0) 
   { delay(1000);  
     if(k2==0)  
      {a-=1 ;
      }
	  }
		else  if(k3==0) 
   { delay(1000);  
     if(k3==0)  
      {a=0;
	  b=0 ;
	   c=0 ;
	    d=0 ;
      }
	  }
	 	else if(k4==0) 
   { delay(1000);  
     if(k4==0)  
      { a+=KeyValue;
      }
	  }
	    while(!k1);
		  while(!k2);
		    while(!k3);
			  while(!k4);
		}


void KeyDown(void)
{ char i =0;
GPIO_KEY=0x0f; 
 if(GPIO_KEY!=0x0f)
   { 
      if(GPIO_KEY!=0x0f)
        { GPIO_KEY=0X0F;
           switch(GPIO_KEY) 
             { case(0X07): KeyValue=0;break;
               case(0X0b): KeyValue=1;break; 
               case(0X0d): KeyValue=2;break; 
               case(0X0e): KeyValue=3;break; }
     GPIO_KEY=0XF0;
	 switch(GPIO_KEY) 
	  { case(0X70): KeyValue=KeyValue;break; 
     	case(0Xb0): KeyValue=KeyValue+4;break; 
	    case(0Xd0): KeyValue=KeyValue+8;break;
	    case(0Xe0): KeyValue=KeyValue+12;break; }
 	  } 
   }
	 
while((i<50)&&(GPIO_KEY!=0xf0))
{ ;
  i++;
	}
}
void panduan()
{if(a>=10){a-=10;b++;}
{if(b>=10){b-=10;c++;}
{if(a<=0){a=0;}
{if(c>=10){c-=10;d++;}

{if(d>=10){d-=10;}
}
}
}
}
}
		
void main() 
{ while(1) 
 { KeyDown(); 
   smgplay();
   keypros(); 
   panduan();
 } 

}










