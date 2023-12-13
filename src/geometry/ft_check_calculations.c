#include "../inc/minirt.h"
void ft_check_calculations(void)
{
	t_vec3 p1, v1;
	t_vec3 p2,v2;
	t_vec3 *out;
	double r;

	out = (t_vec3 *)malloc(2 * sizeof(t_vec3));
	asign_val(&p1, 66, 139, 75);
	asign_val(&v1, 125.372, 284.845, 103.58);
	//estudio para plano
	asign_val(&p2, 25, 40, 66);
	asign_val(&v2, 64, 20, -11);
	out[0] = int_vect_plano(p1, v1, p2, v2);
	printf("%sPlano%s", CHR_GREEN, RESET);
	printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[0].x, out[0].y, out[0].z);
	free(out);
	// estudio para esfera
	asign_val(&p2, 108, 245, 138);
	r = 57;
	out = int_vect_esfera(p1, v1, p2, r);
	if (out != NULL)
	{
		printf("%sESFERA%s", CHR_YELLOW, RESET);
		printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[0].x, out[0].y, out[0].z);
		printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[1].x, out[1].y, out[1].z);
	}
	free(out);
	// estudio para cilindro
	asign_val(&p2, 174, 384, 213);
	asign_val(&v2, 248, -165, 126);
	r = 104;
	out = int_vect_esfera(p1, v1, p2, r);
	if (out != NULL)
	{
		printf("%sCILINDRO%s", CHR_BLUE, RESET);
		printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[0].x, out[0].y, out[0].z);
		printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[1].x, out[1].y, out[1].z);
	}
	free(out);
}