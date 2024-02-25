#include<reg51.h>
void delay(unsigned int i)
{
	unsigned int j,k;
	for(j=0;j<i;j++)
	for(k=0;k<1275;k++);
}
void uart()
{
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TF1=0;
	TR1=1;
}
void Tx(unsigned char x)
{
	SBUF=x;
	while(TI==0);
	TI=0;
}
unsigned char Rx()
{
	unsigned char a;
	while(RI==0);
	a=SBUF;
	return(a);
}
void message(unsigned char *c)
{
	while(*c!=0)
	{
		Tx(*c++);
		delay(20);
	}
}	
int main()
{
	unsigned char Data1;
	uart();
	message("Finance Minister Arun Jaitley Tuesday hit out at former RBI governor Raghuram Rajan for predicting that the next banking crisis would be triggered by MSME lending, saying postmortem is easier than taking action when it was required. Rajan, who had as the chief economist at IMF warned of impending financial crisis of 2008, in a note to a parliamentary committee warned against ambitious credit targets and loan waivers, saying that they could be the sources of next banking crisis. Government should focus on sources of the next crisis, not just the last one.In particular, government should refrain from setting ambitious credit targets or waiving loans. Credit targets are sometimes achieved by abandoning appropriate due diligence, creating the environment for future NPAs, Rajan said in the note. Both MUDRA loans as well as the Kisan Credit Card, while popular, have to be examined more closely for potential credit risk. Rajan, who was RBI governor for three years till September 2016, is currently");
	Data1=Rx();
	Tx(Data1);
	return 0;
}

