#include<reg51.h>
 
unsigned char ch1;
unsigned char s;
 
sbit m1f=P2^0;             
sbit m1b=P2^1;             
sbit m2f=P2^2;             
sbit m2b=P2^3;  
sbit en=P2^4;

  
void delay(unsigned int);        
char rxdata(void);                  
void txdata(unsigned char);
void speedl();
void speedm();
void speedh();
void delayt();

 
void main(void)
 {
unsigned char i;
unsigned char msg1[]={"low speed=1.2"};
unsigned char msg2[]={"medium speed"};
unsigned char msg3[]={"high speed"};
unsigned char msg4[]={"very high speed"};
unsigned char msg5[]={" stopped"};
unsigned char msg6[]={" reverse"};
unsigned char msg7[]={" acc=0.8"};
unsigned char msg8[]={" right"};
unsigned char msg9[]={" left"};
unsigned char msg10[]={"  forward right"};





 
TMOD=0x21;   
SCON=0x50;    //8bit data , 1 stop bit , REN enabled
TH1=0xfd;     //timer value for 9600 bits per second(bps)
TR1=1;            
 
while(1)             
{
     s=rxdata(); 
if(s=='f') 
     {
         m1f=1;
   delay(1);
         m1b=0;
   delay(1);
         m2f=1;
   delay(1);
         m2b=0;
   delay(1);
        for(i=0;msg1[i]!='\0';i++)
{
    txdata(msg1[i]);
} 
while(s=='f')
{
	
  speedl();
	s=rxdata(); 
}
    }
	else if(s=='m') 
     {
         m1f=1;
   delay(1);
         m1b=0;
   delay(1);
         m2f=1;
   delay(1);
         m2b=0;
   delay(1);
        for(i=0;msg2[i]!='\0';i++)
{
    txdata(msg2[i]);
} 
while(s=='m')
{
 speedm();
	s=rxdata();
 }
}
 else if(s=='h') 
     {
         m1f=1;
   delay(1);
         m1b=0;
   delay(1);
         m2f=1;
   delay(1);
         m2b=0;
   delay(1);
        for(i=0;msg3[i]!='\0';i++)
{
    txdata(msg3[i]);
} 
while(s=='h')
{
 speedh();
  s=rxdata();
    }
	}
	else if(s=='v') 
     {
			 for(i=0;msg4[i]!='\0';i++)
{
    txdata(msg4[i]);
} 
			 while('v'==rxdata())
			 {
				 en=1;
         m1f=1;
   delay(1);
         m1b=0;
   delay(1);
         m2f=1;
   delay(1);
         m2b=0;
   delay(1);
        
 
	}
}
		 
 
	else if(s=='s') //stop
     {
			  for(i=0;msg5[i]!='\0';i++)
{
    txdata(msg5[i]);
} 
while(s=='s')
{
         m1f=0;
   delay(1);
         m1b=0;
   delay(1);
         m2f=0;
   delay(1);
         m2b=0;
   delay(1);
	s=rxdata();
}    
 
	}
		  else if(s=='b') //back
     {
			 for(i=0;msg6[i]!='\0';i++)
{
    txdata(msg6[i]);
} 
			 while('b'==rxdata())
			 {
				 en=1;
         m1f=0;
   delay(1);
         m1b=1;
   delay(1);
         m2f=0;
   delay(1);
         m2b=1;
   delay(1);
	}
    }
		 else if(s=='r') //right
     {
			 for(i=0;msg8[i]!='\0';i++)
{
    txdata(msg8[i]);
} 
			 while('r'==rxdata())
			 {
				 en=1;
         m1f=1;
   delay(1);
         m1b=0;
   delay(1);
         m2f=0;
   delay(1);
         m2b=1;
   delay(1);
        
 
	}
}
		 else if(s=='l') //left
     {
			 for(i=0;msg9[i]!='\0';i++)
{
    txdata(msg9[i]);
} 
			 while('l'==rxdata())
			 {
				 en=1;
         m1f=0;
   delay(1);
         m1b=1;
   delay(1);
         m2f=1;
   delay(1);
         m2b=0;
   delay(1);
        
 
	}
}
		 else if(s=='R') // F right
     {
			 for(i=0;msg10[i]!='\0';i++)
{
    txdata(msg10[i]);
} 
			 while('R'==rxdata())
			 {
				 en=1;
         m1f=1;
   delay(1);
         m1b=0;
   delay(1);
         m2f=0;
   delay(1);
         m2b=0;
   delay(1);
        
 
	}
}
		 else if(s=='L') // F left
     {
			 for(i=0;msg9[i]!='\0';i++)
{
    txdata(msg9[i]);
} 
			 while('L'==rxdata())
			 {
				 en=1;
         m1f=0;
   delay(1);
         m1b=0;
   delay(1);
         m2f=1;
   delay(1);
         m2b=0;
   delay(1);
        
 
	}
}
			 
		 else if (s=='a')//acceleration if s=a then acceleration is produced
		 {
			 
			 for(i=0;msg7[i]!='\0';i++)
{
    txdata(msg7[i]);
} 
    m1f=1;
   delay(1);
         m1b=0;
   delay(1);
         m2f=1;
   delay(1);
         m2b=0;
   delay(1);

for(i=0;i<8;i++)
{
speedl();
}
for(i=0;i<3;i++)
{
speedm();
}
for(i=0;i<3;i++)
{
speedh();
}
while(s=='a')
{
	 en=1;
         m1f=1;
   delay(1);
         m1b=0;
   delay(1);
         m2f=1;
   delay(1);
         m2b=0;
   delay(1);
s=rxdata();
}}}}
 	char rxdata()//function recieves data and sends to main
{
	if(RI=0){
		ch1=SBUF;
		return ch1;}
  else if (RI=1)
	{		
  RI=0;           
  ch1=SBUF;      
  return ch1;
	}		
}
  void txdata(unsigned char x)//function to transmit data
{
   SBUF=x; 
   while(TI==0); 
   TI=0; 
}
 
void delay(unsigned int z)//creates dealay 
{
  unsigned int p ,q;
  for(p=0 ; p<z ; p++)    
  {
    for(q=0 ; q<1375 ; q++);   
  }
}

void speedl()//low speed function
{
int j;
en=1;
for(j=0;j<3;j++)
	{
delayt();
	}
en=0	
for(j=0;j<3;j++)
	{
delayt();
	}
}
void speedm()//medium speed function
{
int j;
en=1;
for(j=0;j<2;j++)
	{
delayt();
	}
en=0;
for(j=0;j<2;j++)
	{
delayt();
	}}
void speedh()//high speed function
{
en=1;
delayt();
en=0;
delayt();}
void delayt()//delay function
{
TMOD=0x21;
TL0=0x00;
TH0=0x00;
TF0=0;
TR0=1;
while(TF0==0);
TR0=0;
TF0=0;	
}
