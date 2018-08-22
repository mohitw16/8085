//including the necessary header files
#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>
using namespace std;

struct Address //Structure for holding the registers of 8085
{
  int mem[10000];
  string data[10000];
}adr;

struct Flags //Structure to hold flags of 8085
{
  int CY;    // CARRY FLAG
  int Z;     // ZERO FLAG
  int S;     // SIGN FLAG
  int AC;    // AUXILLIARY CARRY FLAG
  int P;     // PARITY FLAG
}Flag;
struct Registers //Structure for holding the registers of 8085
{
  int  A[8];                  // ACCUMULATOR
  int  B[8];	  int C[8];   // B&C REGISTERS
  int  D[8];	  int E[8];   // D&E REGISTERS
  int  H[8];      int L[8];   // H&L REGISTERS
  char SP[5];                 // STACK POINTER
  char PC[5];                 // PROGRAM COUNTER
}r;

//for printing the debugger menu
void help()
{
	cout<<"\nThe following are the debugger commands:- \n B or BREAK : TO BREAK AFTER A CERTAIN LINE\n R or RUN : TO RUN TO COMPLETION \n S or STEP : TO RUN STEP BY STEP\n P or PRINT : TO PRINT REGISTER VALUE AFTER A CERTAIN LINE\n Q or QUIT : TO QUIT AFTER A CERTAIN LINE\n H or HELP : TO GET HELP\n";
}

/* This function accepts an integer value 'N' and
   Converts it into it's corresponding HEX value
   And Stores in 'T'
*/
void ToHex(int N,char T[])
{
  int Temp1,i=0;
  while(N)
  {
    Temp1=N%16;
    if(Temp1<=9)
    {
     T[i]=Temp1+48;
     i++;
    }
    else
    {
      T[i]=Temp1+55;
      i++;
    }
    N/=16;
  }
  T[i]='\0';
  strrev(T);
}
//for printing the final result
void print(int a[])
{
		int l,i;
		char s[4];
		for(i=0;i<18;i++)
		{
		if(a[i]!=0)
		{
		ToHex(a[i],s);
		cout<<"\nValue at memory address "<<s[0]<<s[1]<<s[2]<<s[3]<<" is ";
		cout<<adr.data[a[i]];
		}
		}
		cout<<"\n\nA=";
		for(l=0;l<8;l++)
		cout<<r.A[l];
		cout<<"\n";
		cout<<"B=";
		for(l=0;l<8;l++)
		cout<<r.B[l];
		cout<<"\n";
			cout<<"C=";
		for(l=0;l<8;l++)
		cout<<r.C[l];
		cout<<"\n";
			cout<<"D=";
		for(l=0;l<8;l++)
		cout<<r.D[l];
		cout<<"\n";
			cout<<"E=";
		for(l=0;l<8;l++)
		cout<<r.E[l];
		cout<<"\n";
			cout<<"H=";
		for(l=0;l<8;l++)
		cout<<r.H[l];
		cout<<"\n";
			cout<<"L=";
		for(l=0;l<8;l++)
		cout<<r.L[l];
		cout<<"\n";
			cout<<"\tFLAGS\n";
		for(l=0;l<8;l++)
		cout<<"-----";
		cout<<"\n";	
		cout<<"AC="<<Flag.AC;
		cout<<"\n";
		cout<<"CY="<<Flag.CY;
		cout<<"\n";
		cout<<"P="<<Flag.P;
		cout<<"\n";
		cout<<"Z="<<Flag.Z;
		cout<<"\n";
		cout<<"S="<<Flag.S;
		cout<<"\n";
			
}
//to calculate power
int pow(int a,int x)
{
  int res=1,i;
  for(i=0;i<x;i++)
    res*=a;
  return res;
}
//to convert to BCD
void ToBCD(int Mode,int Ar[],char Res[])
{
  int T=0;
  if(Mode==1)
  {
    T=(Ar[3]*pow(2,0))+(Ar[2]*pow(2,1))+(Ar[1]*pow(2,2))+(Ar[0]*pow(2,3));
    if(T<=9)  Res[0]=T+48;
    else      Res[0]=T+55;
    T=(Ar[7]*pow(2,0))+(Ar[6]*pow(2,1))+(Ar[5]*pow(2,2))+(Ar[4]*pow(2,3));
    if(T<=9)  Res[1]=T+48;
    else      Res[1]=T+55;
    Res[2]='\0';
  }
  else if(Mode==2)
  {
    T=(Ar[3]*pow(2,0))+(Ar[2]*pow(2,1))+(Ar[1]*pow(2,2))+(Ar[0]*pow(2,3));
    if(T<=9)  Res[0]=T+48;
    else      Res[0]=T+55;
    T=(Ar[7]*pow(2,0))+(Ar[6]*pow(2,1))+(Ar[5]*pow(2,2))+(Ar[4]*pow(2,3));
    if(T<=9)  Res[1]=T+48;
    else      Res[1]=T+55;
    T=(Ar[11]*pow(2,0))+(Ar[10]*pow(2,1))+(Ar[9]*pow(2,2))+(Ar[8]*pow(2,3));
    if(T<=9)  Res[2]=T+48;
    else      Res[2]=T+55;
    T=(Ar[15]*pow(2,0))+(Ar[14]*pow(2,1))+(Ar[13]*pow(2,2))+(Ar[12]*pow(2,3));
    if(T<=9)  Res[3]=T+48;
    else      Res[3]=T+55;
    Res[4]='\0';
  }
}
//to convert to Decimal
int ToDec(char HexVal[])
{
  int i=0,Res=0;
  while(HexVal[i])
  {
    if((HexVal[i]>=48)&&(HexVal[i]<=57))
       Res=(Res*16)+(HexVal[i]-48);
    else if((HexVal[i]>=65)&&(HexVal[i]<=70))
       Res=(Res*16)+(HexVal[i]-55);
    else return -1;
    i++;
  }
  return Res;
}
//to convert to Binary
void ToBin(int Ar[],char Hex[])
{
  int Temp=ToDec(Hex),i;
  for(i=0;i<8;i++)
    Ar[i]=0;
  i=7;
  while(Temp)
  {
    Ar[i]=Temp%2;
    Temp/=2;
    i--;
  }
}



//This function is used to add two 8-bit binary nmubers
//8 if else conditions are used to implement the truth table
//for a full adder.
void BINADD(int Ar1[],int Ar2[],int &CY)
{
  for(int i=7;i>=0;i--)
  {
    if(Ar1[i]==0&&Ar2[i]==0&&CY==0)
    {  Ar1[i]=0;       CY=0;           }
    else if(Ar1[i]==0&&Ar2[i]==0&&CY==1)
    {  Ar1[i]=1;       CY=0;           }
    else if(Ar1[i]==0&&Ar2[i]==1&&CY==0)
    {  Ar1[i]=1;       CY=0;           }
    else if(Ar1[i]==0&&Ar2[i]==1&&CY==1)
    {  Ar1[i]=0;       CY=1;           }
    else if(Ar1[i]==1&&Ar2[i]==0&&CY==0)
    {  Ar1[i]=1;       CY=0;           }
    else if(Ar1[i]==1&&Ar2[i]==0&&CY==1)
    {  Ar1[i]=0;       CY=1;           }
    else if(Ar1[i]==1&&Ar2[i]==1&&CY==0)
    {  Ar1[i]=0;       CY=1;           }
    else if(Ar1[i]==1&&Ar2[i]==1&&CY==1)
    {  Ar1[i]=1;       CY=1;           }
  }
}





//This function is used to subtract two 8-bit binary nmubers
//8 if else conditions are used to implement the truth table
//for a full subtractor.

void BINSUB(int Ar1[],int Ar2[],int &B)
{
  B=0;
  int Stat=0,Val1,Val2,i;
  char V[3];
  ToBCD(1,Ar1,V);  Val1=ToDec(V);
  ToBCD(1,Ar2,V);  Val2=ToDec(V);
  if(Val1<Val2)    Stat=1;
  for(int i=7;i>=0;i--)
  {
    if(Ar1[i]==0&&Ar2[i]==0&&B==0)
    {  Ar1[i]=0;       B=0;           }
    else if(Ar1[i]==0&&Ar2[i]==0&&B==1)
    {  Ar1[i]=1;       B=1;           }
    else if(Ar1[i]==0&&Ar2[i]==1&&B==0)
    {  Ar1[i]=1;       B=1;           }
    else if(Ar1[i]==0&&Ar2[i]==1&&B==1)
    {  Ar1[i]=0;       B=1;           }
    else if(Ar1[i]==1&&Ar2[i]==0&&B==0)
    {  Ar1[i]=1;       B=0;           }
    else if(Ar1[i]==1&&Ar2[i]==0&&B==1)
    {  Ar1[i]=0;       B=0;           }
    else if(Ar1[i]==1&&Ar2[i]==1&&B==0)
    {  Ar1[i]=0;       B=0;           }
    else if(Ar1[i]==1&&Ar2[i]==1&&B==1)
    {  Ar1[i]=1;       B=1;           }
  }

  if(Stat==1)
  {
    for(i=0;i<8;i++)                 //Here, the result is converted
    {                                //to the 2's complement, as in
      if(Ar1[i]==0)   Ar1[i]=1;      //8085, the result is obtained in
      else            Ar1[i]=0;      //2's complement.
    }
    int A[8]={0,0,0,0,0,0,0,1};
    BINADD(Ar1,A,B);
    if(B==1) B=0;
    else     B=1;
  }
}
//This functions returns decimal value of a Binary value.
int Todec(int a[])
{
	int i,sum=0;
	for(i=0;i<8;i++)
	sum=sum +(pow(2,(7-i))*a[i]);
	return sum;
}


//to set sign flag
void SetSign()
{
 Flag.S=r.A[0];
}
//to set zero flag
void SetZero(int R[])
{
  Flag.Z=1;
  for(int i=0;i<8;i++)
  {
    if(R[i]==1)
      Flag.Z=0;
  }
}
//to set error alert
int SetError()
{
  int Count=0,i;
  for(i=0;i<8;i++)
  {
    if(r.A[i]<0)
      Count++;
  }
  if(Count==0)  return 1;
  else            return 0;
}

//to set zero flag in intermediate calculations
void SetZeroFlag()
{
  int Count=0,i;
  for(i=0;i<8;i++)
  {
    if(r.A[i]==1)
      Count++;
  }
  if(Count==0)  Flag.Z=1;
  else            Flag.Z=0;
}
//to set parity flag
void SetParity()
{
  int Count=0,i;
  for(i=0;i<8;i++)
  {
    if(r.A[i]==1)
      Count++;
  }
  if(Count%2==0)  Flag.P=1;
  else            Flag.P=0;
}


			//FUNCTIONS OF VARIOUS INSTRUCTIONS


void XRA()
{
	int i;
for(i=0;i<8;i++)
r.A[i]=0;
}
void LXI(int R1[],int R2[],int&j,string he)
{
	 char hex[4];
	 int l;
	 	string temp;
	 	strcpy(hex,he.c_str());
	 l=strlen(hex);

	if(l==4){
	
	 temp[0]=he[0];
	temp[1]=he[1];
	strcpy(hex,temp.c_str());
		ToBin(R1,hex);
		temp[2]=he[2];
	temp[3]=he[3];
	strcpy(hex,temp.c_str());
		ToBin(R2,hex);
	}
	else if(l==2)
	{
			temp[0]=he[0];
	temp[1]=he[1];
	strcpy(hex,temp.c_str());
		ToBin(R2,hex);
	}
		else if(l==3){
	
	 temp[0]='0';
	temp[1]=he[0];
	strcpy(hex,temp.c_str());
		ToBin(R1,hex);
		temp[2]=he[1];
	temp[3]=he[2];
	strcpy(hex,temp.c_str());
		ToBin(R2,hex);
	}
	

}
void LDA(int a)
{
	string temp;
	 char hex[4];
	temp=adr.data[a];
	strcpy(hex,temp.c_str());
	ToBin(r.A,hex);

}
void STA(int a)
{
	char hex[4];
	string temp;
	int n,i;
	n=Todec(r.A);
	ToHex(n,hex);
	for(i=0;i<2;i++)
	{	
	temp=temp+hex[i];
    }	
	adr.data[a]=temp;

}
void SHLD(int a)
{
	char hex[4];
	string temp;
	int n,i;
	n=Todec(r.L);
	ToHex(n,hex);
	for(i=0;i<2;i++)
	{	
	temp=temp+hex[i];
    }
	adr.data[a]=temp;
	n=Todec(r.H);
	ToHex(n,hex);
	for(i=0;i<2;i++)
	{	
	temp=temp+hex[i];
    }
	adr.data[a+1]=temp;

}
void LHLD(int a)
{
	string temp;
	 char hex[4];
	temp=adr.data[a];
	strcpy(hex,temp.c_str());
	ToBin(r.L,hex);

	temp=adr.data[a+1];
	strcpy(hex,temp.c_str());
	ToBin(r.H,hex);
}
void STAX(int a)
{
		char hex[4];
	string temp;
	int n,i;
	n=Todec(r.A);
	ToHex(n,hex);
	for(i=0;i<2;i++)
	{

	
	temp=temp+hex[i];


}
	adr.data[a]=temp;

}
void SET(int a,string temp)
{
	
	adr.data[a]=temp;
}
void XCHG()
{
	int i;
	for(i=0;i<8;i++)
	{
		swap(r.H[i],r.D[i]);
		swap(r.L[i],r.E[i]);		
	}
}
void XOR(int R[],int &i)
{
  for(int k=0;k<8;k++)
  {
    if((r.A[k]==1&&R[k]==1)||(r.A[k]==0&&R[k]==0))
       r.A[k]=0;
    else
       r.A[k]=1;
  }
  Flag.CY=0;
  SetParity();
  SetZero(r.A);
  SetSign();
  i++;
  ToHex(i+16639,r.PC);
}

void CMA(int &i)
{
	int k;
	for(k=0;k<8;k++)
	{
		if(r.A[k]==0)
		r.A[k]=1;
		else if(r.A[k]==1)
		r.A[k]=0;
	}


}

void CMP(int Ar[],int &i)
{
  char A[3],R[3];
  int Val1,Val2;
  ToBCD(1,r.A,A); Val1=ToDec(A);
  ToBCD(1,Ar,R);         Val2=ToDec(R);
  if(Val1<Val2)
  { Flag.CY=1;  Flag.Z=0; SetSign(); SetParity();  }
  else if(Val1>Val2)
  { Flag.Z=0;   Flag.CY=0; SetSign(); SetParity(); }
  else if(Val1==Val2)
  {  Flag.Z=1;Flag.CY=0; SetSign(); SetParity();     }
  i++;
  ToHex(i+16639,r.PC);
}

void ADD(int R[],int &i)
{
  Flag.CY=0;
  BINADD(r.A,R,Flag.CY);
  SetParity();
  SetSign();
  SetZero(r.A);
  i++;
  ToHex(i+16639,r.PC);
}

void SUB(int R[],int &i)
{
  Flag.CY=0;
  BINSUB(r.A,R,Flag.CY);
  SetParity();
  SetZero(r.A);
  SetSign();
  i++;
  ToHex(i+16639,r.PC);
}

void DCR(int R[],int &i)
{
  int Ar[8]={0,0,0,0,0,0,0,1};
  int T=0;
  BINSUB(R,Ar,T);
  SetParity();
  SetSign();
  SetZero(R);
  i++;
  ToHex(i+16639,r.PC);
}

void INX(int R1[],int R2[],int&i)
{
  int Ar1[8]={0,0,0,0,0,0,0,0};
  int Ar2[8]={0,0,0,0,0,0,0,1};
  int T=0;
  BINADD(R2,Ar2,T);
  BINADD(R1,Ar1,T);
  i++;
  ToHex(i+16639,r.PC);
}

void DCX(int R1[],int R2[],int&i)
{
  int Ar1[8]={0,0,0,0,0,0,0,0};
  int Ar2[8]={0,0,0,0,0,0,0,1};
  int T=0;
  BINSUB(R2,Ar2,T);
  BINSUB(R1,Ar1,T);
  i++;
  ToHex(i+16639,r.PC);
}

void INR(int R[],int &i)
{
  int Ar[8]={0,0,0,0,0,0,0,1};
  int T=0,l;
  BINADD(R,Ar,T);
  SetParity();
  SetSign();
  SetZero(R);
  i++;
  ToHex(i+16639,r.PC);
}

void MOV(int Des[],int Sou[],int &i)
{
  int j;
  for(j=0;j<8;j++)
    Des[j]=Sou[j];
  i++;
  ToHex(i+16639,r.PC);
}

void MVI(char ch[],int t)
{
int ar[8];
ToBin(ar,ch);
MOV(r.A,ar,t);

}

void DAD(int R1[],int R2[],int R3[],int R4[],int &i)
{
  Flag.CY=0;
  BINADD(R3,R2,Flag.CY);
  BINADD(R4,R1,Flag.CY);
  i++;
  ToHex(i+16639,r.PC);

}

void ADI(char ch[],int t)
{
int ar[8];
ToBin(ar,ch);
ADD(ar,t);
}

void SUI(char ch[],int t)
{
int ar[8];
ToBin(ar,ch);
SUB(ar,t);

}	
