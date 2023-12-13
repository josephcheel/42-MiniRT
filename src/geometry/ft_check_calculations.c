#include "../inc/minirt.h"
void ft_check_calculations(void)
{
	t_vec3 p1, v1;
	t_vec3 p2,v2;
	t_vec3 *out;
	t_vec3 aux;
	double r, m;

	out = (t_vec3 *)malloc(2 * sizeof(t_vec3));
	p1 = create_vect(64, 20, -11);
	v1 = create_vect(-11.384,26.972, -17.192);
	r = prod_escalar(p1, v1);
	printf("%sprod escalar vectores perp%s\n", CHR_GREEN, RESET);
	printf("vector 1 x= %f y=%f z=%f \n", p1.x, p1.y, p1.z);
	printf("vector 2 x= %f y=%f z=%f \n", v1.x, v1.y, v1.z);
	printf("result= %f \n", r);	
	p1 = create_vect(66, 139, 75);
	v1 = create_vect(-24, -33, -25);
	v2 = resta_vector(p1, v1);
	printf("%sresta vector%s\n", CHR_GREEN, RESET);
	printf("vector 1 x= %f y=%f z=%f \n", p1.x, p1.y, p1.z);
	printf("vector 2 x= %f y=%f z=%f \n", v1.x, v1.y, v1.z);
	printf("vector 3 x= %f y=%f z=%f \n", v2.x, v2.y, v2.z);
	v2 = suma_vector(p1, v1);
	printf("%ssuma vector%s\n", CHR_MGENTA, RESET);
	printf("vector 1 x= %f y=%f z=%f \n", p1.x, p1.y, p1.z);
	printf("vector 2 x= %f y=%f z=%f \n", v1.x, v1.y, v1.z);
	printf("vector 3 x= %f y=%f z=%f \n", v2.x, v2.y, v2.z);
	r = prod_escalar(p1, v1);
	printf("%sproducto escalar%s\n", CHR_GREEN, RESET);
	printf("vector 1 x= %f y=%f z=%f \n", p1.x, p1.y, p1.z);
	printf("vector 2 x= %f y=%f z=%f \n", v1.x, v1.y, v1.z);
	printf("result= %f \n", r);
	v2 = prod_vectorial(p1, v1);
	printf("%sprod. vectorial%s\n", CHR_MGENTA, RESET);
	printf("vector 1 x= %f y=%f z=%f \n", p1.x, p1.y, p1.z);
	printf("vector 2 x= %f y=%f z=%f \n", v1.x, v1.y, v1.z);
	printf("vector 3 x= %f y=%f z=%f \n", v2.x, v2.y, v2.z);
	printf("%scomprobacion%s\n", CHR_GREEN, RESET);
	r = prod_escalar(p1, v2);
	printf("result= %f \n", r);
	r = prod_escalar(v1, v2);
	printf("result= %f \n", r);

	//estudio para plano
	p2 = create_vect(25, 40, 66);
	v2 = create_vect(64, 20, -11);
	out[0] = int_vect_plano(p1, v1, p2, v2);
	printf("%sPlano%s\n", CHR_GREEN, RESET);
	printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[0].x, out[0].y, out[0].z);
	printf("%scomprobacion%s\n", CHR_GREEN, RESET);
	aux = resta_vector(out[0],p2);
	r = prod_escalar(v2, aux);
	printf("result= %f \n", r);
	free(out);
	//distancia punto vector
	p2  = create_vect(108, 245, 138);
	r = 57;
	m = dist_pto_vector(p1, p2, v1);
	printf("%sprod. vectorial%s\n", CHR_MGENTA, RESET);
	printf("punto 1 x= %f y=%f z=%f \n", p1.x, p1.y, p1.z);
	printf("punto 2 x= %f y=%f z=%f \n", p2.x, p2.y, p2.z);
	printf("vector  x= %f y=%f z=%f \n", v1.x, v1.y, v1.z);
	printf("%sdistancia punto vector%s\n", CHR_GREEN, RESET);
	printf("result= %f \n", m);
	// estudio para esfera

	out = int_vect_esfera(p1, v1, p2, r);
	printf("%sESFERA%s\n", CHR_YELLOW, RESET);
	printf("punto 1 x= %f y=%f z=%f \n", p1.x, p1.y, p1.z);
	printf("vector  x= %f y=%f z=%f \n", v1.x, v1.y, v1.z);
	printf("pt esfe x= %f y=%f z=%f \n", p2.x, p2.y, p2.z);
	printf("radio= %f \n", r);
	if (out != NULL)
	{
		printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[0].x, out[0].y, out[0].z);
		printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[1].x, out[1].y, out[1].z);
	}
	else
		printf("Sin interseccion\n");
	free(out);
	// estudio para cilindro
	p2 = create_vect(174, 384, 213);
	v2 = create_vect(248, -165, 126);
	r = 104;
	out = int_vect_cilind(p1, v1, p2, v2, r);
	printf("%sCILINDRO%s\n", CHR_BLUE, RESET);
	printf("punto 1  x= %f y=%f z=%f \n", p1.x, p1.y, p1.z);
	printf("vector   x= %f y=%f z=%f \n", v1.x, v1.y, v1.z);
	printf("pt cili  x= %f y=%f z=%f \n", p2.x, p2.y, p2.z);
	printf("vect cil x= %f y=%f z=%f \n", p2.x, p2.y, p2.z);
	printf("radio= %f \n", r);
	if (out != NULL)
	{
		printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[0].x, out[0].y, out[0].z);
		printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[1].x, out[1].y, out[1].z);
	}
	else
		printf("Sin interseccion\n");
	free(out);
}