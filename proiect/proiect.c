#include<stdio.h>
#include<string.h>
int main()
{
	struct utilizator
	{
		char nume[50];
		char prenume[50];
		int ziua_nasterii;
		int luna_nasterii;
		char zodie[13][30];
		char trasaturi[15][50];
	};

	int optiune;
	int i=0;
	char zodieu[13];
	char trasaturiu[15];
	int perioade[20];

	printf("Optiuni disponibile: \n");
	printf("1. Informatii astrologice pentru o singura persoana\n");
	printf("2. Compatibilitate pentru 2 persoane\n");
	printf("\nIntroduceti optiunea dorita: ");
	fflush(stdout);
	scanf("%d", &optiune);

	if(optiune==1)
	{

	struct utilizator u;

	printf("\nIntroduceti numele si prenumele dumneavoastra: ");
	fflush(stdout);
	scanf("%s%s", u.nume, u.prenume);

	printf("Introduceti ziua si luna nasterii dumneavoastra: ");
	fflush(stdout);
	scanf("%d%d", &u.ziua_nasterii, &u.luna_nasterii);

	while(u.luna_nasterii<1 || u.luna_nasterii>12)
	{
		printf("Luna de nastere introdusa gresit! ");
		printf("Reintroduceti datele de nastere: ");
		fflush(stdout);
		scanf("%d%d", &u.ziua_nasterii, &u.luna_nasterii);
	}

	switch(u.luna_nasterii)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		while(u.ziua_nasterii<1 || u.ziua_nasterii>31)
		{
			printf("Ziua de nastere introdusa gresit! ");
			printf("Reintroduceti datele de nastere: ");
			fflush(stdout);
			scanf("%d%d", &u.ziua_nasterii, &u.luna_nasterii);
		}
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{	while(u.ziua_nasterii<1 || u.ziua_nasterii>30)
				{
					printf("Ziua de nastere introdusa gresit! ");
					printf("Reintroduceti datele de nastere: ");
					fflush(stdout);
					scanf("%d%d", &u.ziua_nasterii, &u.luna_nasterii);
				}
		break;
	}
	case 2:
	{
		while(u.ziua_nasterii<1 || u.ziua_nasterii>29)
						{
							printf("Ziua de nastere introdusa gresit! ");
							printf("Reintroduceti datele de nastere: ");
							fflush(stdout);
							scanf("%d%d", &u.ziua_nasterii, &u.luna_nasterii);
						}
				break;
	}
	}

	FILE *f, *f1, *f2;

	f=fopen("infozodie.txt","r");
	f1=fopen("calitati.txt","r");
	f2=fopen("perioadezodii.txt","r");
	if(f==NULL)
		{
			printf("Eroare la citirea fisierului f!\n");
			return 1;
		}
	if(f1==NULL)
	{
		printf("Eroare la citirea fisierlui!");
		return 1;
	}
	if(f2==NULL)
	{
		printf("Eroare la citirea fisierlui f2!");
		return 1;
	}

	for(i=0;i<13;i++)
		 fscanf(f2, "%d", &perioade[i]);

	for(i=0;i<13;i++)
		fscanf(f, "%s", u.zodie[i]);

	while(fgets(u.trasaturi[i], 50, f1)!=NULL)
				     i++;

		int n=i;

		//aici trb modificat infozodie.txt ca sa mi citeasca pt fiecare zodie datile in care se cuprinde

		for(i=0;i<n;i++)
			  if(u.luna_nasterii==i)
				{ if(u.ziua_nasterii>perioade[i])
					{ strcpy(zodieu,u.zodie[i+1]);
					  strcpy(trasaturiu, u.trasaturi[i+1]);
					}
				else
					{ strcpy(zodieu, u.zodie[i]);
					  strcpy(trasaturiu, u.trasaturi[i]);
					}
				}

		printf("\nZodia ta este %s", zodieu);
		printf("Cateva calitati care va pot descrie prin raporare la zodia dumneavoastra sunt: %s", trasaturiu);
		}


    return 0;
}

