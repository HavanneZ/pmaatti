#include <stdio.h>
#include <string.h>

void lueRoskat(void);
void luesaldo(void);
void nosto(void);
void talletus (void);


int main(void) {

	char tilinumero[256];
	FILE * tili;
	char pinkoodi[256];
	char tarkistusPin[256];
	int valinta;


	printf("\nAnna tilinumero: ");
	fgets( tilinumero, 256, stdin );

	if( tilinumero[ strlen(tilinumero) -1] == '\n')
		tilinumero[ strlen(tilinumero) -1] = '\0';
	else
		lueRoskat();

	strcat(tilinumero, ".tili");

	if( ( tili = fopen( tilinumero, "r" ))!=NULL) {

		printf("Anna pinkoodisi: ");

		fgets( pinkoodi, 256, stdin );

		if( pinkoodi[ strlen(pinkoodi) -1] == '\n')
			pinkoodi[ strlen(pinkoodi) -1] = '\0';
		else
			lueRoskat();


		fgets( tarkistusPin, 256, tili );

		if( tarkistusPin[ strlen(tarkistusPin) -1] == '\n')
			tarkistusPin[ strlen(tarkistusPin) -1] = '\0';

		if( tarkistusPin[ strlen(tarkistusPin) -1] == '\r')
			tarkistusPin[ strlen(tarkistusPin) -1] = '\0';


		if( strcmp( pinkoodi, tarkistusPin )  == 0 ) {

			printf("\nPin-koodi Ok!\n\n");
			printf("Tervetuloa! \n");
			while (1) {

				paluu:
				printf("\n1. Saldo. \n");
				printf("2. Nosto. \n");
				printf("3. Talletus. \n");
				printf("0. Lopeta. \n\n");
				scanf("%d", &valinta);

				switch (valinta) {

					case 1:
						luesaldo();

						break;

					case 2:
						nosto();


						break;

					case 3:
						talletus();


						break;

					case 0:
						printf("Kiitos asioinnistasi!");

						break;

					default:
						printf("Virheellinen valinta!\n");
						goto paluu;

						break;
				}
				if(valinta==0)
					break;
			}



		} else {

			printf("Vaara pin-koodi, yrita uudelleen\n");

		}

	} else {
		printf("\nVirheellinen tilinumero!\n");
	}



	return 0;

}

void lueRoskat(void) {

	while(fgetc(stdin) != '\n');
		
}

void luesaldo(void) {
	printf("Saldosi on: \n");

}

void nosto(void) {
	printf("Ilmoita nostettava summa: ");
}

void talletus(void) {
	printf("Ilmoita talletettava summa: ");
}
