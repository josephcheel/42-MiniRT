#include "../inc/minirt.h"
void ft_check_calculations(void)
{
	t_vec_pos vp1, vp2;
	t_vec_pos *out;
	t_vec3 aux;
	double r, m;

	out = (t_vec_pos *)malloc(2 * sizeof(t_vec_pos));
	vp1.pt = create_vect(64, 20, -11);
	vp1.v = create_vect(-11.384,26.972, -17.192);
	r = prod_escalar(vp1.pt, vp1.v);
	printf("%sprod escalar vectores perp%s\n", CHR_GREEN, RESET);
	printf("vector 1 x= %f y=%f z=%f \n", vp1.pt.x, vp1.pt.y, vp1.pt.z);
	printf("vector 2 x= %f y=%f z=%f \n", vp1.v.x, vp1.v.y, vp1.v.z);
	printf("result= %f \n", r);	
	vp1.pt = create_vect(66, 139, 75);
	vp1.v = create_vect(-24, -33, -25);
	vp2.v = resta_vector(vp1.pt, vp1.v);
	printf("%sresta vector%s\n", CHR_GREEN, RESET);
	printf("vector 1 x= %f y=%f z=%f \n", vp1.pt.x, vp1.pt.y, vp1.pt.z);
	printf("vector 2 x= %f y=%f z=%f \n", vp1.v.x, vp1.v.y, vp1.v.z);
	printf("vector 3 x= %f y=%f z=%f \n", vp2.v.x, vp2.v.y, vp2.v.z);
	vp2.v = suma_vector(vp1.pt, vp1.v);
	printf("%ssuma vector%s\n", CHR_MGENTA, RESET);
	printf("vector 1 x= %f y=%f z=%f \n", vp1.pt.x, vp1.pt.y, vp1.pt.z);
	printf("vector 2 x= %f y=%f z=%f \n", vp1.v.x, vp1.v.y, vp1.v.z);
	printf("vector 3 x= %f y=%f z=%f \n", vp2.v.x, vp2.v.y, vp2.v.z);
	r = prod_escalar(vp1.pt, vp1.v);
	printf("%sproducto escalar%s\n", CHR_GREEN, RESET);
	printf("vector 1 x= %f y=%f z=%f \n", vp1.pt.x, vp1.pt.y, vp1.pt.z);
	printf("vector 2 x= %f y=%f z=%f \n", vp1.v.x, vp1.v.y, vp1.v.z);
	printf("result= %f \n", r);
	vp2.v = prod_vectorial(vp1.pt, vp1.v);
	printf("%sprod. vectorial%s\n", CHR_MGENTA, RESET);
	printf("vector 1 x= %f y=%f z=%f \n", vp1.pt.x, vp1.pt.y, vp1.pt.z);
	printf("vector 2 x= %f y=%f z=%f \n", vp1.v.x, vp1.v.y, vp1.v.z);
	printf("vector 3 x= %f y=%f z=%f \n", vp2.v.x, vp2.v.y, vp2.v.z);
	printf("%scomprobacion%s\n", CHR_GREEN, RESET);
	r = prod_escalar(vp1.pt, vp2.v);
	printf("result= %f \n", r);
	r = prod_escalar(vp1.v, vp2.v);
	printf("result= %f \n", r);

	//estudio para plano
	vp2.pt = create_vect(25, 40, 66);
	vp2.v = create_vect(64, 20, -11);
	out[0] = int_vect_plano(vp1, vp2);
	printf("%sPlano%s\n", CHR_GREEN, RESET);
	printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[0].pt.x, out[0].pt.y, out[0].pt.z);
	printf("%scomprobacion%s\n", CHR_GREEN, RESET);
	aux = resta_vector(out[0].pt, vp2.pt);
	r = prod_escalar(vp2.v, aux);
	printf("result= %f \n", r);
	free(out);
	//distancia punto vector
	vp2.pt  = create_vect(108, 245, 138);
	r = 57;
	m = dist_pto_vector(vp1.pt, vp2.pt, vp1.v);
	printf("%sprod. vectorial%s\n", CHR_MGENTA, RESET);
	printf("punto 1 x= %f y=%f z=%f \n", vp1.pt.x, vp1.pt.y, vp1.pt.z);
	printf("punto 2 x= %f y=%f z=%f \n", vp2.pt.x, vp2.pt.y, vp2.pt.z);
	printf("vector  x= %f y=%f z=%f \n", vp1.v.x, vp1.v.y, vp1.v.z);
	printf("%sdistancia punto vector%s\n", CHR_GREEN, RESET);
	printf("result= %f \n", m);
	// estudio para esfera

	out = int_vect_esfera(vp1, vp2.pt, r);
	printf("%sESFERA%s\n", CHR_YELLOW, RESET);
	printf("punto 1 x= %f y=%f z=%f \n", vp1.pt.x, vp1.pt.y, vp1.pt.z);
	printf("vector  x= %f y=%f z=%f \n", vp1.v.x, vp1.v.y, vp1.v.z);
	printf("pt esfe x= %f y=%f z=%f \n", vp2.pt.x, vp2.pt.y, vp2.pt.z);
	printf("radio= %f \n", r);
	if (out != NULL)
	{
		printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[0].pt.x, out[0].pt.y, out[0].pt.z);
		printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[1].pt.x, out[1].pt.y, out[1].pt.z);
	}
	else
		printf("Sin interseccion\n");
	free(out);
	// estudio para cilindro
	vp2.pt = create_vect(174, 384, 213);
	vp2.v = create_vect(248, -165, 126);
	r = 104;
	out = int_vect_cilind(vp1, vp2, r);
	printf("%sCILINDRO%s\n", CHR_BLUE, RESET);
	printf("punto 1  x= %f y=%f z=%f \n", vp1.pt.x, vp1.pt.y, vp1.pt.z);
	printf("vector   x= %f y=%f z=%f \n", vp1.v.x, vp1.v.y, vp1.v.z);
	printf("pt cili  x= %f y=%f z=%f \n", vp2.pt.x, vp2.pt.y, vp2.pt.z);
	printf("vect cil x= %f y=%f z=%f \n", vp2.v.x, vp2.v.y, vp2.v.z);
	printf("radio= %f \n", r);
	if (out != NULL)
	{
		printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[0].pt.x, out[0].pt.y, out[0].pt.z);
		printf("Punto de itnerseccion x= %f y=%f z=%f \n", out[1].pt.x, out[1].pt.y, out[1].pt.z);
	}
	else
		printf("Sin interseccion\n");
	free(out);
}