#include<stdio.h>
#include<conio.h>
#include<conio.h>
#include<math.h>
#include<errno.h>
void main()
{
int creatsofa,platesofa;
int bilsofa,Respsofa,gcssofa;
int grandsofa,base,basalsofa;
int pO2,count;
int e,v,m,gcstot;
float plate,bil,Resp;
int gender,age;
float eGFR,creat,alpha,beta,kappa,creatkappa,creatkappapow,agepow;
int choice,sofa,inochoice,MAP;
int pp,sys,dias,mapsofa,mapavail;
float cc,wgt,dose,ml;
/* cc=IV Rate(cc/Hr);  wgt=Body Weight(Kg);
 /*  dose=Dose Available; ml=mL Available*/
float mghr,mcmin;

clrscr();
beta=0.993;
count=1;
while(count<=16)
{
/*creat*/
printf("\n Enter the Creatinine value: \n");
scanf("%f",&creat);
printf("\n The Creatinine value is: %f \n",creat);
/*eGFR CALCULATION*/ printf("\n Enter the Gender 0f the patient: 1= MALE 2= FEMALE \n");
scanf("%d",&gender);
printf("Enter the Age of the Patient : \n");
scanf("%d",&age);
/*IF MALE*/if(gender==1)
	     {
	      kappa=0.9;
/* First Strat on MALE creat value*/if(creat>0.9)
				{
				alpha= -1.209;
				creatkappa=creat/kappa;
				creatkappapow=pow(creatkappa,alpha);
				agepow=pow(beta,age);
				eGFR=(141*(creatkappapow)*(agepow));
				printf("The eGFR using CKD-EPI Formula  is %f mL/Min \n",eGFR);
				getch();
				}
/* Second Strat on MALE creat value*/else if(creat<=0.9)
				{
				alpha= -0.411;
				creatkappa=creat/kappa;
				creatkappapow=pow(creatkappa,alpha);
				agepow=pow(beta,age);
				eGFR=(141*(creatkappapow)*(agepow));
				printf("The eGFR using CKD-EPI Formula is %f mL/Min \n",eGFR);
				getch();
				}
				else
				printf("Unable to calculate GFR for Male \n");
				getch();
				}
/*IF FEMALE*/else if(gender==2)
				{
				kappa=0.7;
/* First Strat on FEMALE creat value*/if(creat>0.7)
				{
				alpha= -1.209;
				creatkappa=creat/kappa;
				creatkappapow=pow(creatkappa,alpha);
				agepow=pow(beta,age);
				eGFR=141*(creatkappapow)*(agepow)*1.018;
				printf("The eGFR using CKD-EPI Formula  is %f mL/Min \n",eGFR);
				getch();
				}
/* Second Strat on FEMALE creat value*/else if(creat<=0.7)
				{
				alpha= -0.329;
				creatkappa=(creat/kappa);
				creatkappapow=pow(creatkappa,alpha);
				agepow=pow(beta,age);
				eGFR=141*(creatkappapow)*(agepow)*1.018;
				printf("The eGFR using CKD-EPI Formula  is %f mL/Min \n",eGFR);
				getch();
				}
				else
				printf("Unable to calculate for Female \n");
				}
else
printf("\n Unable to Calculate eGFR for any Gender \n");
if(eGFR<15)
{
printf("\n eGFR IS TOO LOW! EXCLUDE THIS PATIENT!\n");
}
else
printf("\n This patient could be included...\n");


if(creat<=1.2)
{
creatsofa=0;
printf("The SOFA score for Creatinine for the Subject: %d is: %d \n",count,creatsofa);
getch();
}
else if((creat<1.9)&(creat>=1.2))     /*what if 1.97*/
	{
	creatsofa=1;
	printf("The SOFA score for Creatinine for the Subject: %d is %d \n",count,creatsofa);
	getch();
	}
else if((creat<=3.4)&(creat>=2.0))
	{
	creatsofa=2;
	printf("The SOFA score for Creatinine for the Subject: %d is: %d \n",count,creatsofa);
	getch();
	}
else if((creat<=4.9)&(creat>=3.5))
	{
	creatsofa=3;
	printf("The SOFA score for Creatinine for the Subject: %d is %d: \n",count,creatsofa);
	getch();
	}
else if(creat>=5.0)
	{
	creatsofa=4;
	printf("The SOFA score for Creatinine for the Subject: %d is: %d \n",count,creatsofa);
	getch();
	}
	else
	{
	printf("Incorrect Creatinine value \n");
	}
/*MAP*/
printf("\n Is the Patient under Inotrophs? \n");
printf("\n 1= YES   2= NO  \n");
scanf("\n %d",&inochoice);

/*beginning of loop with inotrops*/if(inochoice==1)
{
printf("\n    Choose the Adrenergic agent from the list below (Example: DOPAMINE): \n");
printf(" \n   1= DOPAMINE                 2=DOBUTAMINE     \n");
printf(" \n   3= EPINEPHRIN (ADRENALIN)   4=NOREPINEPHRINE (NORADRENALINE) \n");
scanf("%d",&choice);

	if(choice==1)
	{
	printf("\n The Agent you entered is: DOPAMINE \n");
	}
	else if(choice==2)
	{
	printf("\n The Agent you entered is: DOBUTAMINE \n");
	}
	else if(choice==3)
	{
	printf("\n The Agent you entered is: EPINEPHRIN (ADRENALIN) \n");
	}
	else if(choice==4)
	{
	printf("\n The Agent you entered is: NOREPINEPHRIN (NORADRENALIN) \n");
	}
	else
	{
	printf("\n The Name of the Agent is not clear \n");
	}
printf("\n Enter the IV Rate (cc/Hr) (Example: 2 To 14 cc/Hr): \n");
scanf("%f",&cc);
printf("\n\n Enter the Body weight (Kg)(Example: 50 Kg): \n");
scanf("%f",&wgt);
printf("\n\n Enter the Dose Available (mG) (Example: 8mG): \n");
scanf("%f",&dose);
printf("\n\n Enter the mL Available (Example: 50 mL) : \n");
scanf("%f",&ml);
mghr=(cc/ml)*dose;
mcmin=(mghr*1000)/(60*wgt);     /*(mghr/60)*(1000/wgt);*/
/*printf("The Infusion Rate as Milligram per Hour is %f \n",mghr);*/
printf("\n\n The Infusion Rate as Microgram per Kg.Min (uG/kG.Min) is: %f \n",mcmin);
getch();
if(choice==1)
 {
       if(mcmin<=5)
       {
       mapsofa=2;
       printf("\n\n The SOFA score for Cardiovascular system is %d \n",mapsofa);
       }
       else if(mcmin>5)
       {
       mapsofa=3;
       printf("\n\n The SOFA score for Cardiovascular system is %d \n",mapsofa);
       }
       else if(mcmin>15)
       {
       mapsofa=4;
       printf("\n\n The SOFA score for Cardiovascular system is %d \n",mapsofa);
       }
      else
       printf("\n\n Unable to calcular SOFA score \n");
 }
else if(choice==2)
      {
	mapsofa=2;
	printf("\n\n The SOFA score for Cardiovascular system is %d \n",mapsofa);
       }
else if(choice==3)
      {
	if(mcmin<=0.1)
	  {
	   mapsofa=3;
	    printf("\n\n The SOFA score for Cardiovascular system is %d \n",mapsofa);
	  }
	else if(mcmin>0.1)
	   {
	     mapsofa=4;
	     printf("\n\n The SOFA score for Cardiovascular system is %d \n",mapsofa);
	     }
	else
	    printf("\n\n Unable to calculate the score \n");
	}
else if(choice==4)
	   {
	   if(mcmin<=0.1)
		{
		mapsofa=3;
		printf("\n\n The SOFA score for Cardiovascular system is %d \n",mapsofa);
		}
	   else if(mcmin>0.1)
		{
		mapsofa=4;
		printf("\n\n The SOFA score for Cardiovascular system is %d \n",mapsofa);
		}
	   else
		printf("\n\n Unable to calculate the score\n");
	     }
else
printf("\n\n Unable to calculate the score\n");
getch();
/*End of if loop for SOFA score analysis in presence of Infusion*/}
else if(inochoice==2)
{
printf("\n So the patient is not under Inotrops.....\n ");
printf("MAP reading available? 1=YES 2=NO \n");
scanf("%d",&mapavail);
	if(mapavail==1)
			{
			printf("Enter the MAP value (In Integers): \n");
			scanf("%d",&MAP);
			printf("The MAP value is: %d \n",MAP);
			if(MAP>=70)
			{
			mapsofa=0;
			printf("The SOFA score for MAP for the Subject: %d is: %d \n",count,mapsofa);
			}
			else if(MAP<=70)
			{
			mapsofa=1;
			printf("The SOFA score for MAP for the Subject: %d is: %d \n",count,mapsofa);
			}
			else
			printf("INCORRECT MAP VALUE \n");
			}
	else if(mapavail==2)
			{
			printf("\n Enter the Systolic pressure\n ");
			scanf("%d",&sys);
			printf("\n Enter the Diastolic pressure\n");
			scanf("%d",&dias);
			pp=sys-dias;
			MAP=dias+(pp/3);
			printf("\n The MAP value is %d \n",MAP);


				if(MAP>=70)
				{
				mapsofa=0;
				printf("The SOFA score for MAP for the Subject: %d is: %d \n",count,mapsofa);
				}
				else if(MAP<=70)
				{
				mapsofa=1;
				printf("The SOFA score for MAP for the Subject: %d is: %d \n",count,mapsofa);
				}
				}
	 else
		printf("INCORRECT MAP VALUE \n");

getch();
}  /* End of else if loop for SOFA analysis without Inotrophs*/
else
{
printf("\n Unable to calculate SOFA scores....\n");
}


/* bil*/ printf("\n Enter the Biliubin value: \n");
scanf("%f",&bil);
printf("The Bilirubin value is: %f \n",bil);
getch();
if(bil<=1.2)
{
bilsofa=0;
printf("The SOFA score for Bilirubin for the Subject: %d is: %d \n",count,bilsofa);
}
else if((bil<=1.9)&(bil>=1.2))
	{
	bilsofa=1;
	printf("The SOFA score for Bilirubin for the Subject: %d is: %d \n",count,bilsofa);
	}
else if((bil<=5.9)&(bil>=2.0))
	{
	bilsofa=2;
	printf("The SOFA score for Bilirubin for the Subject: %d is: %d \n",count,bilsofa);
	}
else if((bil<=11.9)&(bil>=6.0))
	{
	bilsofa=3;
	printf("The SOFA score for Bilirubin for the Subject: %d is: %d \n",count,bilsofa);
	}
else if(bil>=12)
	{
	bilsofa=4;
	printf("The SOFA score for Bilirubin for the Subject: %d is: %d \n",count,bilsofa);
	}
	else
	{
	printf("Incorrect Bilirubin Value \n");
	}
/*gcs*/
printf("\n ENTER THE VALUE FOR EYE MOVEMENT:  \n");
scanf("%d",&e);
printf("\n ENTER THE VALUE FOR VERBAL SKILLS: \n");
scanf("%d",&v);
printf("\n ENTER THE VALUE FOR MOTOR CAPACITY: \n");
scanf("%d",&m);
printf("\n THE GCS YOU ENTERED IS E: %d V: %d M: %d \n",e,v,m);
gcstot=e+v+m;
printf("\n The Total GCS value is: %d \n",gcstot);
if(gcstot==15)
{
gcssofa=0;
printf("THE SOFA SCORE FOR THE GCS VALUE for the Subject: %d IS: %d \n",count,gcssofa);
getch();
}
else if((gcstot>=13)&(gcstot<=14))
{
gcssofa=1;
printf("THE SOFA SCORE FOR THE GCS VALUE for the Subject: %d IS: %d \n",count,gcssofa);
getch();
}
else if((gcstot>=10)&(gcstot<=12))
{
gcssofa=2;
printf("THE SOFA SCORE FOR THE GCS VALUE for the Subject: %d IS: %d \n",count,gcssofa);
getch();
}
else if((gcstot>=6)&(gcstot<=9))
{
gcssofa=3;
printf("THE SOFA SCORE FOR THE GCS VALUE for the Subject: %d IS: %d \n",count,gcssofa);
getch();
}
else if(gcstot<6)
{
gcssofa=4;
printf("THE SOFA SCORE FOR THE GCS VALUE for the Subject: %d IS: %d \n",count,gcssofa);
getch();
}
else
{
printf("INCORRECT VALUE \n");
}
printf("\n Enter the Platelet value (in Thousands): \n");
scanf("%f",&plate);
printf("\n The Platelet value (in Thousands) is %f \n",plate);
getch();
if(plate>=150)
{
platesofa=0;
printf("The SOFA score for Platelet for the Subject: %d is: %d \n",count,platesofa);
getch();
}
else if((plate<150)&(plate>=100))
	{
	platesofa=1;
	printf("The SOFA score for Platelet for the Subject: %d is: %d \n",count,platesofa);
	getch();
	}
else if((plate<100)&(plate>=50))
	{
	platesofa=2;
		printf("The SOFA score for Platelet for the Subject: %d is: %d \n",count,platesofa);
	getch();
	}
else if((plate>=20)&(plate<50))
	{
	platesofa=3;
	printf("The SOFA score for Platelet for the Subject: %d is: %d \n",count,platesofa);
	getch();
	}
else if(plate<20)
	{
	platesofa=4;
	printf("The SOFA score for Platelet for the Subject: %d is: %d \n",count,platesofa);
	getch();
	}
else
{
printf("Incorrect Platelet value \n");
}
printf("\n Enter the pO2 value: \n");
scanf("%d",&pO2);
Resp=(pO2/0.4);
printf("\nThe Resp value is: %f \n",Resp);
if(Resp>=400)
{
Respsofa=0;
printf("The SOFA score for Respiration for the Subject: %d is: %d \n",count,Respsofa);
getch();
}
else if((Resp<400)&(Resp>=300))
{
Respsofa=1;
printf("The SOFA score for Respiration for the Subject: %d is: %d \n",count,Respsofa);
getch();
}
else if((Resp<300)&(Resp>=200))
{
Respsofa=2;
printf("The SOFA score for Respiration for the Subject: %d is: %d\n",count,Respsofa);
getch();
}
else if((Resp<200)&(Resp>=100))
{
Respsofa=3;
printf("The SOFA score for Respiration for the Subject: %d is: %d \n",count,Respsofa);
getch();
}
else if(Resp<100)/*&(Resp!=(0&1&2&3)))*/
{
Respsofa=4;
printf("The SOFA score for Respiration for the Subject: %d is: %d \n",count,Respsofa);
getch();
}
else
{
printf("INCORRECT RESPIRATION VALUE \n");
}
printf("\n Given below are the Systems with their respective SOFA Scores for this Patient \n");
printf("\n 1.CARDIAC SYSTEM (SOFA SCORE: %d)        2.RENAL SYSTEM (SOFA SCORE:%d)  \n",mapsofa,creatsofa);
printf("\n 3.CIRCULATORY SYSTEM (SOFA SCORE: %d)    4. HEPATIC SYSTEM (SOFA SCORE: %d) \n",platesofa,bilsofa);
printf("\n 5.RESPIRATORY SYSTEM (SOFA SCORE: %d)    6. CEREBROSPINAL SYSTEM (SOFA SCORE: %d) \n",Respsofa,gcssofa);
printf("\n WHICH ONE OF THE SYSTEMS GIVEN ABOVE GOT PRIMARILY AFFECTED IN THIS PATIENT ?: \n");
scanf("%d",&base);
grandsofa=(bilsofa+Respsofa+gcssofa+mapsofa+creatsofa+platesofa);
if(base==1)
{
basalsofa=grandsofa-mapsofa;
}
else if(base==2)
{
basalsofa=grandsofa-creatsofa;
}
else if(base==3)
{
basalsofa=grandsofa-platesofa;
}
else if(base==4)
{
basalsofa=grandsofa-bilsofa;
}
else if(base==5)
{
basalsofa=grandsofa-Respsofa;
}
else if(base==6)
{
basalsofa=grandsofa-gcssofa;
}
/*else if(base==1&2)
{
basalsofa=grandsofa-(mapsofa+creatsofa);
}
else if(base==1&3)
{
basalsofa=grandsofa-(mapsofa+platesofa);
}
else if(base==1&4)
{
basalsofa=grandsofa-(mapsofa+bilsofa);
}
else if(base==1&5)
{
basalsofa=grandsofa-(mapsofa+Respsofa);
}
else if(base==1&6)
{
basalsofa=grandsofa-(mapsofa+gcssofa);
}
else if(base==1&5)
{
basalsofa=grandsofa-(mapsofa+Respsofa);
}
else if(base==2&1)
{
basalsofa=grandsofa-(creatsofa+mapsofa);
}
else if(base==2&3)
{
basalsofa=grandsofa-(creatsofa+platesofa);
}
else if(base==2&3)
{
basalsofa=grandsofa-(creatsofa+platesofa);
}
else if(base==2&4)
{
basalsofa=grandsofa-(creatsofa+bilsofa);
}
else if(base==2&5)
{
basalsofa=grandsofa-(creatsofa+Respsofa);
}
else if(base==2&6)
{
basalsofa=grandsofa-(creatsofa+gcssofa);
}
  changes are needed hereafter- else if(base==3&1)
{
basalsofa=grandsofa-(platesofa+mapsofa);
}
else if(base==3&2)
{
basalsofa=grandsofa-(platesofa+creatsofa);
}
else if(base==3&4)
{
basalsofa=grandsofa-(platesofa+bilsofa);
}
else if(base==3&5)
{
basalsofa=grandsofa-(platesofa+Respsofa);
}
else if(base==3&6)
{
basalsofa=grandsofa-(platesofa+gcssofa);
}
else if(base==4&1)
{
basalsofa=grandsofa-(bilsofa+mapsofa);
}
else if(base==4&2)
{
basalsofa=grandsofa-(bilsofa+creatsofa);
}
else if(base==4&3)
{
basalsofa=grandsofa-(bilsofa+platesofa);
}
else if(base==4&5)
{
basalsofa=grandsofa-(bilsofa+Respsofa);
}
else if(base==4&6)
{
basalsofa=grandsofa-(bilsofa+gcssofa);
}
else if(base==5&1)
{
basalsofa=grandsofa-(Respsofa+mapsofa);
}
else if(base==5&2)
{
basalsofa=grandsofa-(Respsofa+creatsofa);
}
else if(base==5&3)
{
basalsofa=grandsofa-(Respsofa+platesofa);
}
else if(base==5&4)
{
basalsofa=grandsofa-(Respsofa+bilsofa);
}
else if(base==5&6)
{
basalsofa=grandsofa-(Respsofa+gcssofa);
}

else if(base==6&1)
{
basalsofa=grandsofa-(gcssofa+mapsofa);
}
else if(base==6&2)
{
basalsofa=grandsofa-(gcssofa+creatsofa);
}
else if(base==6&3)
{
basalsofa=grandsofa-(gcssofa+platesofa);
}
else if(base==6&4)
{
basalsofa=grandsofa-(gcssofa+bilsofa);
}
else if(base==6&5)
{
basalsofa=grandsofa-(gcssofa+Respsofa);
}  */
else
{
printf(" CANNOT ASSESS BASELINE SOFA SCORE \n");
}
printf("------------------------------------------------\n");
printf("SOFA Score for Bilirubin level  : %f   is   : %d \n",bil,bilsofa);
printf("SOFA Score for Creatinine level : %f   is   : %d \n",creat,creatsofa);
printf("SOFA Score for MAP              : %d          is : %d \n",MAP,mapsofa);
printf("SOFA Score for Platelet level   : %d          is : %d \n",plate,platesofa);
printf("SOFA Score for Respiration level: %f  (pO2: %d) is : %d \n",Resp,pO2,Respsofa);
printf("SOFA Score for GCS(Sensorium)   : %d          is : %d \n",gcstot,gcssofa);
printf("\n -------------------------------------------------\n");
printf("    THE GRAND SOFA SCORE FOR THE SUBJECT : %d IS %d \n",count,grandsofa);
printf("    THE BASELIINE SOFA FOR THE SUBJECT   : %d IS %d \n",count,basalsofa);
printf("\n -------------------------------------------------\n");
printf("\n -------------END OF PROGRAM----------------------\n");
getch();
count=count+1;
}
}
