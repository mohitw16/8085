//including the self created header file
 #include"p2.h"

 int main(int argc,char *argv[])

{
	char  hx[10],Hex[5],fn[15],y[5],tt[4];
	adr.data[9]="00AF";//giving input for memeory
	string Target[50][50],s[50]={""},reg[50]={""},hex[50]={""},regx[50]={""},hexx[50]={""},fname,addr[50],choice,debug;
	int Num,e,v=0,g=0,l=0,h=0,p,rt[8],rr,rt1[8],hxd,jj,pp,hh[18]={0},rh=0,noi,adrdec=0,program_counter=0,flag=-1,line_no,b=0,dp,ps,mn=0,ctr=0;
	string inst[26]={"MVI","MOV","DCR","CMA","ADI","SUI","JMP","CMP","DCX","DAD","INR","INX","STA","LDA","LHLD","LXI","STAX","XCHG","SHLD","JC","JNC","JZ","JNZ","ADD","SUB","SET"};
	int instsize[26]={2,1,1,1,2,2,3,1,1,1,1,1,3,3,3,3,1,1,3,3,3,3,3,2,2,3};
	ifstream inFile;
	int len,mm;
	int i=0,j=0,k=0,q,w,c=0;

 	
 		fname=argv[1];	//storing file name
 		if(argc==3)		//checking if debugger is on	
 		debug=argv[2];
 		else
 		debug="OFF";
 		

 strcpy(fn,fname.c_str());
 if(fname!="eof"&&fname!="EOF")		//checking if user want to data through file
 {
 //file handling commands
 
 inFile.open(fn);
 if(!inFile)					//checking for error in opening the file
 {
 	cout<<"Unable to open the file";
 	exit(1);
 }
 while(!inFile.eof())			//taking input from the file
 {
 	inFile>>noi;
 	if((noi<0)||(noi>50))
 	{
 		cout<<"Error in values";
 		return 0;
	 }
 	for(i=0;i<noi;i++)
	{

				inFile>>Target[i][0];
					//taking inputs according to the command entered in file
					if(Target[i][0]=="MVI")
					{
						inFile>>Target[i][2];
						Target[i][1]="X";
					}
					else if(Target[i][0]=="MOV")
					{
						inFile>>Target[i][1];
						Target[i][2]="X";
					}
					else	if(Target[i][0]=="DCR")
					{
						inFile>>Target[i][1];
						Target[i][2]="X";
					}
					else	if(Target[i][0]=="CMP")
					{
						inFile>>Target[i][1];
						Target[i][2]="X";
					}
					else	if(Target[i][0]=="ADI")
					{
						inFile>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="SUI")
					{
						inFile>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="JMP")
					{
						inFile>>Target[i][2];
						Target[i][1]="X";
					}	
					else if(Target[i][0]=="JC")
					{
						inFile>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="JNC")
					{
						inFile>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="JZ")
					{
						inFile>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="JNZ")
					{
						inFile>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="LXI")
					{
						inFile>>Target[i][1];
						inFile>>Target[i][2];
					}
					else if(Target[i][0]=="DCX")
					{
						inFile>>Target[i][1];
						Target[i][2]="X";
					}
					else if(Target[i][0]=="INR")
					{
						inFile>>Target[i][1];
						Target[i][2]="X";
					}
					else if(Target[i][0]=="INX")
					{
						inFile>>Target[i][1];
						Target[i][2]="X";
					}
					else if(Target[i][0]=="ADD")
					{
						inFile>>Target[i][1];
						Target[i][2]="X";
					}
					else if(Target[i][0]=="SUB")
					{
						inFile>>Target[i][1];
						Target[i][2]="X";
					}
					else	if(Target[i][0]=="CMA")
					{
						Target[i][1]="X";
						Target[i][2]="X";
					}
					else	if(Target[i][0]=="DAD")
					{
						inFile>>Target[i][1];
						Target[i][2]="X";
					}
					else if(Target[i][0]=="STA")
					{
						inFile>>Target[i][2];
						Target[i][1]="X";
					}
					else if(Target[i][0]=="LDA")
					{
						inFile>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="LHLD")
					{
						inFile>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="XCHG")
					{
						Target[i][1]="X";
						Target[i][2]="X";
					}
					else	if(Target[i][0]=="STAX")
					{
						inFile>>Target[i][1];
						Target[i][2]="X";
					}
					else	if(Target[i][0]=="SHLD")
					{
						inFile>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="SET")
					{
						inFile>>Target[i][1];
						inFile>>Target[i][2];
						adr.data[ToDec(strcpy(tt,Target[i][2].c_str()))]=Target[i][1];
					}
			
		//}
	}
 	
 }
 inFile.close();

}
else											//checking if user want to data through command line
	{
		cout<<"enter the no. of instruction  ";
		cin>>noi;
		if((noi<0)||(noi>50))
 	{
 		cout<<"Error in values";
 		return 0;
	 }
		cout<<"enter the program\n";
		for(i=0;i<noi;i++)
	{											//taking inputs according to the command entered in command line
					cin>>Target[i][0];
					if(Target[i][0]=="MVI")
					{
						cin>>Target[i][2];
						Target[i][1]="X";
					}
					else if(Target[i][0]=="MOV")
					{
						cin>>Target[i][1];
						Target[i][2]="X";
					}
					else	if(Target[i][0]=="DCR")
					{
						cin>>Target[i][1];
						Target[i][2]="X";
					}
					else	if(Target[i][0]=="CMP")
					{
						cin>>Target[i][1];
						Target[i][2]="X";
					}
					else	if(Target[i][0]=="ADI")
					{
						cin>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="SUI")
					{
						cin>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="JMP")
					{
						cin>>Target[i][2];
						Target[i][1]="X";
					}	
					else if(Target[i][0]=="JC")
					{
						cin>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="JNC")
					{
						cin>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="JZ")
					{
						cin>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="JNZ")
					{
						cin>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="LXI")
					{
						cin>>Target[i][1];
						cin>>Target[i][2];
					}
					else if(Target[i][0]=="DCX")
					{
						cin>>Target[i][1];
						Target[i][2]="X";
					}
					else if(Target[i][0]=="INR")
					{
						cin>>Target[i][1];
						Target[i][2]="X";
					}
					else if(Target[i][0]=="INX")
					{
						cin>>Target[i][1];
						Target[i][2]="X";
					}
					else if(Target[i][0]=="ADD")
					{
						cin>>Target[i][1];
						Target[i][2]="X";
					}
					else if(Target[i][0]=="SUB")
					{
						cin>>Target[i][1];
						Target[i][2]="X";
					}
					else	if(Target[i][0]=="CMA")
					{
						Target[i][1]="X";
						Target[i][2]="X";
					}
					else	if(Target[i][0]=="DAD")
					{
						cin>>Target[i][1];
						Target[i][2]="X";
					}
					else if(Target[i][0]=="STA")
					{
						cin>>Target[i][2];
						Target[i][1]="X";
					}
					else if(Target[i][0]=="LDA")
					{
						cin>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="LHLD")
					{
						cin>>Target[i][2];
						Target[i][1]="X";
					}
					else	if(Target[i][0]=="XCHG")
					{
						Target[i][1]="X";
						Target[i][2]="X";
					}
					else	if(Target[i][0]=="STAX")
					{
						cin>>Target[i][1];
						Target[i][2]="X";
					}
					else	if(Target[i][0]=="SHLD")
					{
						cin>>Target[i][2];
						Target[i][1]="X";
					}
						else	if(Target[i][0]=="SET")
					{
						cin>>Target[i][1];
						cin>>Target[i][2];
						adr.data[ToDec(strcpy(tt,Target[i][2].c_str()))]=Target[i][1];
					}
	}
}

adrdec=0;							//starting address = 0

for(i=0;i<noi;i++)
{
	s[i]=Target[i][0];				//array to store the instructions
	reg[i]=Target[i][1];			//array to store the registers
	hex[i]=Target[i][2];			//array to store the hexadecimal values
	 strcpy(y,hex[i].c_str());
	len=strlen(y);
	
	
	for(mm=0;mm<len;mm++)
	{
		if(y[mm]==','||y[mm]==';'||y[mm]=='-'||y[mm]=='+'||y[mm]=='/'||y[mm]=='.'||y[mm]=='['||y[mm]=='<'||y[mm]=='?'||y[mm]==']'||y[mm]=='>')
		{
			cout<<"Error in code";		//checking for errors
			return 0;
		}
	}

	
		for(j=0;j<26;j++)
	{
			if(s[i]!=inst[j])		//checking if instruction exists
				{
				dp=1;
				}
			else
				 {
				dp=0;
				break;
				}
		
	}
	if(dp==1)
	{
	cout<<"Wrong instruction provided  "<<s[i];
	return 0;
	}
	for(j=0;j<26;j++)
	{
		if(s[i]==inst[j])
		{
			
			ToHex(adrdec,Hex);
			addr[i]=string(Hex);		//providing address to each instruction
			
			adrdec+=instsize[j];
		
		}
		
	}

}
addr[0]="0";

j=0,i=0;

cout<<"\n Programme :\n";		//printing out the program
for(jj=0;jj<noi;jj++)
{
		cout<<"\n"<<addr[jj]<<" ";
	if(s[jj]!="X")
	cout<<s[jj]<<" ";
		if(reg[jj]!="X")
	cout<<reg[jj]<<" ";
		if(hex[jj]!="X")
	cout<<hex[jj];
}


if(debug=="DEBUGGER")		//checking for debugger
{
flag=0;
help();
}
for(jj=0;jj<noi;jj++)
{
j=jj;

		string st=s[jj];
		char hx[4],r1,r2,rx[4];
		strcpy(hx,hex[jj].c_str());		//to copy string value in char array
		string regis=reg[jj];
		strcpy(rx,reg[jj].c_str());
										//DEBUGGER PROGRAMMING
		if(flag==0)						//DEBUGGER  IS ON
		{
		
		if(b==1)
		{
		
			if(jj==line_no)
			break;
		}
		else
		{
		//debugger menu
		cout<<"\nDo you wish to continue.. If stepwise then press S.. Else input any of the debugger command   ";
		cin>>choice;
		if(flag==0&&choice=="S"||choice=="STEP")		//printing instruction at each step
		{
			cout<<"\n"<<addr[jj]<<" ";
	if(s[jj]!="X")
	cout<<s[jj]<<" ";
		if(reg[jj]!="X")
	cout<<reg[jj]<<" ";
		if(hex[jj]!="X")
	cout<<hex[jj];
	cout<<"\nDo you want to print the result till now?....yes-1/no-0	";
	cin>>ctr;
	if(ctr==1)
	{
		print(hh);
	}
		}
		else	if(flag==0&&choice=="R"||choice=="RUN")
		{
			//do nothing
			flag=1;
			
		}
		else	if(flag==0&&choice=="B"||choice=="BREAK")
		{
			cout<<"Break line no.?";//	if you want to break from the whole program enter 0";
			cin>>line_no;
			b=1;			
	
			
		}
		else	if(flag==0&&choice=="P"||choice=="PRINT")
		{
			print(hh);
			//do nothing or print line
		}
		else	if(flag==0&&choice=="Q"||choice=="QUIT")
		{
		
			//do nothing or print line
			return 0;
			//break;
		}
		
		else	if(flag==0&&choice=="H"||choice=="HELP")
		{
			
	
		help();	
		}
		else{
			cout<<"Wrong debugger input";
		}
			
			
	}//else of break
}
	
			for(p=0;p<5;p++)
			{
					if(regis[p]==',')		//checking for MOV instruction
					{
						r1=regis[p-1];
						r2=regis[p+1];
				
							if(r1=='A'&&r2=='B')
						{
							MOV(r.A,r.B,j);
						}
							if(r1=='A'&&r2=='C')
						{
							MOV(r.A,r.C,j);
						}
							if(r1=='A'&&r2=='D')
						{
							MOV(r.A,r.D,j);
						}
							if(r1=='A'&&r2=='E')
						{
							MOV(r.A,r.E,j);
						}
							if(r1=='A'&&r2=='H')
						{
							MOV(r.A,r.H,j);
						}
							if(r1=='A'&&r2=='L')
						{
							MOV(r.A,r.L,j);
						}
								if(r1=='B'&&r2=='A')
						{
							MOV(r.B,r.A,j);
						}
							if(r1=='B'&&r2=='C')
						{
							MOV(r.B,r.C,j);
						}
							if(r1=='B'&&r2=='D')
						{
							MOV(r.B,r.D,j);
						}
							if(r1=='B'&&r2=='E')
						{
							MOV(r.B,r.E,j);
						}
							if(r1=='B'&&r2=='H')
						{
							MOV(r.B,r.H,j);
						}
							if(r1=='B'&&r2=='L')
						{
							MOV(r.B,r.L,j);
						}
								if(r1=='C'&&r2=='B')
						{
							MOV(r.C,r.B,j);
						}
							if(r1=='C'&&r2=='A')
						{
							MOV(r.C,r.A,j);
						}
							if(r1=='C'&&r2=='D')
						{
							MOV(r.C,r.D,j);
						}
							if(r1=='C'&&r2=='E')
						{
							MOV(r.C,r.E,j);
						}
							if(r1=='C'&&r2=='H')
						{
							MOV(r.C,r.H,j);
						}
							if(r1=='C'&&r2=='L')
						{
							MOV(r.C,r.L,j);
						}
								if(r1=='D'&&r2=='B')
						{
							MOV(r.D,r.B,j);
						}
							if(r1=='D'&&r2=='C')
						{
							MOV(r.D,r.C,j);
						}
							if(r1=='D'&&r2=='A')
						{
							MOV(r.D,r.A,j);
						}
							if(r1=='D'&&r2=='E')
						{
							MOV(r.D,r.E,j);
						}
							if(r1=='D'&&r2=='H')
						{
							MOV(r.D,r.H,j);
						}
							if(r1=='D'&&r2=='L')
						{
							MOV(r.D,r.L,j);
						}
								if(r1=='E'&&r2=='B')
						{
							MOV(r.E,r.B,j);
						}
							if(r1=='E'&&r2=='C')
						{
							MOV(r.E,r.C,j);
						}
							if(r1=='E'&&r2=='D')
						{
							MOV(r.E,r.D,j);
						}
							if(r1=='E'&&r2=='A')
						{
							MOV(r.E,r.A,j);
						}
							if(r1=='E'&&r2=='H')
						{
							MOV(r.E,r.H,j);
						}
							if(r1=='E'&&r2=='L')
						{
							MOV(r.E,r.L,j);
						}
								if(r1=='H'&&r2=='B')
						{
							MOV(r.H,r.B,j);
						}
							if(r1=='H'&&r2=='C')
						{
							MOV(r.H,r.C,j);
						}
							if(r1=='H'&&r2=='D')
						{
							MOV(r.H,r.D,j);
						}
							if(r1=='H'&&r2=='E')
						{
							MOV(r.H,r.E,j);
						}
							if(r1=='H'&&r2=='A')
						{
							MOV(r.H,r.A,j);
						}
							if(r1=='H'&&r2=='L')
						{
							MOV(r.H,r.L,j);
						}
								if(r1=='L'&&r2=='B')
						{
							MOV(r.L,r.B,j);
						}
							if(r1=='L'&&r2=='C')
						{
							MOV(r.L,r.C,j);
						}
							if(r1=='L'&&r2=='D')
						{
							MOV(r.L,r.D,j);
						}
							if(r1=='L'&&r2=='E')
						{
							MOV(r.L,r.E,j);
						}
							if(r1=='L'&&r2=='H')
						{
							MOV(r.L,r.H,j);
						}
							if(r1=='L'&&r2=='A')
						{
							MOV(r.L,r.A,j);
						}
					
						
						
					
			}

else{
							//checking for MVI instruction

	if(regis[p]=='A')
	{
		for(rr=0;rr<8;rr++)
		rt[rr]=r.A[rr];
	}
		if(regis[p]=='B')
	{
		for(rr=0;rr<8;rr++)
		rt[rr]=r.B[rr];
	}
		if(regis[p]=='C')
	{
		for(rr=0;rr<8;rr++)
		rt[rr]=r.C[rr];
	}
		if(regis[p]=='D')
	{
		for(rr=0;rr<8;rr++)
		rt[rr]=r.D[rr];
	}
		if(regis[p]=='E')
	{
		for(rr=0;rr<8;rr++)
		rt[rr]=r.E[rr];
	}
		if(regis[p]=='H')
	{
		for(rr=0;rr<8;rr++)
		rt[rr]=r.H[rr];
	}
		if(regis[p]=='L')
	{
		for(rr=0;rr<8;rr++)
		rt[rr]=r.L[rr];
	}
		if(regis[p]=='M')
	{
		for(rr=0;rr<8;rr++)
		{
		}
		
	}
}//else

				//checking for various other instructions
	if(st[p]=='X'&&st[p+1]=='O'&&st[p+2]=='R')
	{

	XOR(rt,j);
	}


		if(st[p]=='A'&&st[p+1]=='D'&&st[p+2]=='D')
	{

	ADD(rt,j);
	}
		if(st[p]=='A'&&st[p+1]=='D'&&st[p+2]=='I')
	{

	ADI(hx,j);
	}	
		if(st[p]=='M'&&st[p+1]=='O'&&st[p+2]=='V')
	{

	MOV(rt1,rt,j);

	}
		if(st[p]=='M'&&st[p+1]=='V'&&st[p+2]=='I')
	{

	MVI(hx,j);
	}
		if(st[p]=='L'&&st[p+1]=='X'&&st[p+2]=='I')
	{

		hh[++mn]=ToDec(hx);
		if(regis[p]=='B')				//checking for register pairs
			{
				for(rr=0;rr<8;rr++)
				rt[rr]=r.B[rr];
				for(rr=0;rr<8;rr++)
				rt1[rr]=r.C[rr];
			}
				if(regis[p]=='D')
			{
				for(rr=0;rr<8;rr++)
				rt[rr]=r.D[rr];
				for(rr=0;rr<8;rr++)
				rt1[rr]=r.E[rr];
			}
				if(regis[p]=='H')
			{
				for(rr=0;rr<8;rr++)
				rt[rr]=r.H[rr];
				for(rr=0;rr<8;rr++)
				rt1[rr]=r.L[rr];
			}
	LXI(rt,rt1,j,hx);
		if(regis[p]=='B')
			{
				for(rr=0;rr<8;rr++)
				r.B[rr]=rt[rr];
				for(rr=0;rr<8;rr++)				
				r.C[rr]=rt1[rr];
			}
				if(regis[p]=='D')
			{
				for(rr=0;rr<8;rr++)				
				r.D[rr]=rt[rr];
				for(rr=0;rr<8;rr++)
				r.E[rr]=rt1[rr];
			}
				if(regis[p]=='H')
			{
				for(rr=0;rr<8;rr++)
				r.H[rr]=rt[rr];
				for(rr=0;rr<8;rr++)				
				r.L[rr]=rt1[rr];
			}
	
	}
		if(st[p]=='L'&&st[p+1]=='D'&&st[p+2]=='A')
	{
		hh[++mn]=ToDec(hx);

	LDA(hh[mn]);
	}
		if(st[p]=='S'&&st[p+1]=='E'&&st[p+2]=='T')
	{

		rh=ToDec(rx);

	SET(rh,hx);

	}
		if(st[p]=='S'&&st[p+1]=='T'&&st[p+2]=='A')
	{
		hh[++mn]=ToDec(hx);

	STA(hh[mn]);
	}
		if(st[p]=='L'&&st[p+1]=='H'&&st[p+2]=='L'&&st[p+3]=='D')
	{
	hh[++mn]=ToDec(hx);
	
	LHLD(hh[mn]);
	}
		if(st[p]=='S'&&st[p+1]=='H'&&st[p+2]=='L'&&st[p+3]=='D')
	{
	hh[++mn]=ToDec(hx);
	SHLD(hh[mn]);

	}
	
		if(st[p]=='S'&&st[p+1]=='T'&&st[p+2]=='A'&&st[p+3]=='X')
	{	hh[++mn]=ToDec(hx);
	
	STAX(hh[mn]);
	}
		if(st[p]=='X'&&st[p+1]=='C'&&st[p+2]=='H'&&st[p+3]=='G')
	{
	
	XCHG();
	}	if(st[p]=='S'&&st[p+1]=='U'&&st[p+2]=='B')
	{

	SUB(rt,j);
	}
		if(st[p]=='I'&&st[p+1]=='N'&&st[p+2]=='R')
	{

	INR(rt,j);

	}
		if(st[p]=='D'&&st[p+1]=='C'&&st[p+2]=='R')
	{
	
	DCR(rt,j);								//rt stores register name
	}
		if(st[p]=='I'&&st[p+1]=='N'&&st[p+2]=='X')
	{
		
				if(regis[p]=='B')
			{
				for(rr=0;rr<8;rr++)
				rt[rr]=r.B[rr];
				for(rr=0;rr<8;rr++)
				rt1[rr]=r.C[rr];
			}
				if(regis[p]=='D')
			{
				for(rr=0;rr<8;rr++)
				rt[rr]=r.D[rr];
				for(rr=0;rr<8;rr++)
				rt1[rr]=r.E[rr];
			}
				if(regis[p]=='H')
			{
				for(rr=0;rr<8;rr++)
				rt[rr]=r.H[rr];
				for(rr=0;rr<8;rr++)
				rt1[rr]=r.L[rr];
			}
		

	INX(rt,rt1,j);
		if(regis[p]=='B')
			{
				for(rr=0;rr<8;rr++)
				r.B[rr]=rt[rr];
				for(rr=0;rr<8;rr++)				
				r.C[rr]=rt1[rr];
			}
				if(regis[p]=='D')
			{
				for(rr=0;rr<8;rr++)				
				r.D[rr]=rt[rr];
				for(rr=0;rr<8;rr++)
				r.E[rr]=rt1[rr];
			}
				if(regis[p]=='H')
			{
				for(rr=0;rr<8;rr++)
				r.H[rr]=rt[rr];
				for(rr=0;rr<8;rr++)				
				r.L[rr]=rt1[rr];
			}
	}
		if(st[p]=='D'&&st[p+1]=='C'&&st[p+2]=='X')
	{
				if(regis[p]=='B')
			{
				for(rr=0;rr<8;rr++)
				rt[rr]=r.B[rr];
				for(rr=0;rr<8;rr++)
				rt1[rr]=r.C[rr];
			}
				if(regis[p]=='D')
			{
				for(rr=0;rr<8;rr++)
				rt[rr]=r.D[rr];
				for(rr=0;rr<8;rr++)
				rt1[rr]=r.E[rr];
			}
				if(regis[p]=='H')
			{
				for(rr=0;rr<8;rr++)
				rt[rr]=r.H[rr];
				for(rr=0;rr<8;rr++)
				rt1[rr]=r.L[rr];
			}
	
	DCX(rt,rt1,j);
		if(regis[p]=='B')
			{
				for(rr=0;rr<8;rr++)
				r.B[rr]=rt[rr];
				for(rr=0;rr<8;rr++)				
				r.C[rr]=rt1[rr];
			}
				if(regis[p]=='D')
			{
				for(rr=0;rr<8;rr++)				
				r.D[rr]=rt[rr];
				for(rr=0;rr<8;rr++)
				r.E[rr]=rt1[rr];
			}
				if(regis[p]=='H')
			{
				for(rr=0;rr<8;rr++)
				r.H[rr]=rt[rr];
				for(rr=0;rr<8;rr++)				
				r.L[rr]=rt1[rr];
			}
	}
		if(st[p]=='D'&&st[p+1]=='A'&&st[p+2]=='D')
	{
			if(regis[p]=='B')
			{
				for(rr=0;rr<8;rr++)
				rt[rr]=r.B[rr];
				for(rr=0;rr<8;rr++)
				rt1[rr]=r.C[rr];
			}
				if(regis[p]=='D')
			{
				for(rr=0;rr<8;rr++)
				rt[rr]=r.D[rr];
				for(rr=0;rr<8;rr++)
				rt1[rr]=r.E[rr];
			}
				if(regis[p]=='H')
			{
				for(rr=0;rr<8;rr++)
				rt[rr]=r.H[rr];
				for(rr=0;rr<8;rr++)
				rt1[rr]=r.L[rr];
			}

	DAD(rt,rt1,r.L,r.H,j);

	}
		if(st[p]=='S'&&st[p+1]=='U'&&st[p+2]=='I')
	{

	SUI(hx,j);
	}
		if(st[p]=='C'&&st[p+1]=='M'&&st[p+2]=='A')
	{
	
	CMA(j);
	}
		if(st[p]=='C'&&st[p+1]=='M'&&st[p+2]=='P')
	{
	
	CMP(rt,j);
	}
		if(st[p]=='J'&&st[p+1]=='M'&&st[p+2]=='P')
	{
		
	for(k=0;k<noi;k++)
	{
		if(addr[k]==hx)
		{
		hh[++mn]=ToDec(hx);

			if(hh[mn]<0||hh[mn]>adrdec)
	{
		cout<<"Wrong address provided";
		return 0;
	}	break;
		}
	}
	jj=k-1;
	
	}
		if(st[p]=='J'&&st[p+1]=='C')
	{
		if(Flag.CY==1)
		{
				for(k=0;k<noi;k++)
	{
		if(addr[k]==hx)
		{
		hh[++mn]=ToDec(hx);

			if(hh[mn]<0||hh[mn]>adrdec)
	{
		cout<<"Wrong address provided";
	}	break;
		}
	}
	jj=k-1;
		}
	}
		if(st[p]=='J'&&st[p+1]=='N'&&st[p+2]=='C')
	{
		if(Flag.CY==0)
		{
				for(k=0;k<noi;k++)
	{
		if(addr[k]==hx)
		{
		hh[++mn]=ToDec(hx);
	
			if(hh[mn]<0||hh[mn]>adrdec)
	{
		cout<<"Wrong address provided";
	}	break;
		}
	}
	jj=k-1;
		}
	}
		if(st[p]=='J'&&st[p+1]=='N'&&st[p+2]=='Z')
	{
	
		if(Flag.Z==0)
		{
				for(k=0;k<noi;k++)
	{
		if(addr[k]==hx)
		{
		hh[++mn]=ToDec(hx);

		if(hh[mn]<0||hh[mn]>adrdec)
	{
		cout<<"Wrong address provided";
	}
		break;
		}
	}
	jj=k-1;
		}
	}
		if(st[p]=='J'&&st[p+1]=='Z')
	{

		if(Flag.Z==1)
		{
				for(k=0;k<noi;k++)
	{
		if(addr[k]==hx)
		{
		hh[++mn]=ToDec(hx);

	if(hh[mn]<0||hh[mn]>adrdec)
	{
		cout<<"Wrong address provided";
	}
		break;
		}
	}
	jj=k-1;
		}
	}
	
					//providing the values back 
	
	if(regis[p]=='A')
	{
		for(rr=0;rr<8;rr++)		
		r.A[rr]=rt[rr];
	}
		if(regis[p]=='B')
	{
		for(rr=0;rr<8;rr++)
				r.B[rr]=rt[rr];
	}
		if(regis[p]=='C')
	{
		for(rr=0;rr<8;rr++)
			r.C[rr]=rt[rr];
	}
		if(regis[p]=='D')
	{
		for(rr=0;rr<8;rr++)
		r.D[rr]=rt[rr];

	}
		if(regis[p]=='E')
	{
		for(rr=0;rr<8;rr++)
				r.E[rr]=rt[rr];
	}
		if(regis[p]=='H')
	{
		for(rr=0;rr<8;rr++)
				r.H[rr]=rt[rr];
	}
		if(regis[p]=='L')
	{
		for(rr=0;rr<8;rr++)		
		r.L[rr]=rt[rr];
	}
		if(regis[p]=='M')
	{
		for(rr=0;rr<8;rr++)
		{}
	}
}

}
SetSign();				//checking sign flag
SetParity();			//checking parity flag
SetZeroFlag();			//checking zero flag
if(SetError()==0)		//checking for error
{
	cout<<"\n"<<"Error in code";
	return 0;
}
cout<<"\n\t\tTHIS IS THE FINAL RESULT:";
print(hh);				//printing the result
return 0;


}



