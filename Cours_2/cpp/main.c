#include <func.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	double masse = 70.;
	double vitesse = (130. * 1000. / 3600.);

	printf("Pour %.2f kg lancé(s) à %.2f m.s-1 :\n", masse, vitesse);
	printf("Ec = %.4f Joule(s)\n", compute_ec(masse, vitesse) );
	return 0;
}
