#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdalign.h> // c++ style alignas, alignof

int main()
{
#ifdef __clang_major__
	printf("clang detected version %d.%d\n", __clang_major__, __clang_minor__);
#endif

#ifdef __GNUC__
	// note that clang 3.7 declares itself as a gcc 4.2"
	printf("gcc detected version %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif

	//printf("Alignment of char = %zu\n", alignof(char));
	//printf("alignof(float[10]) = %zu\n", alignof(float[10]));
	//printf("alignof(struct{char c; int n;}) = %zu\n",
	//	alignof(struct { char c; int n; }));

	//double dx;
	//char ca;
	//char cx;
	//double dz;
	//char cb;
	////char _Alignas(double) cz;
	//char alignas(16) cz;
	////char cz;

	////printf("char alignment: %zd\n", _Alignof(char));
	////printf("double alignment: %zd\n", _Alignof(double));
	//printf("char alignment: %zd\n", alignof(char));
	//printf("double alignment: %zd\n", alignof(double));

	//printf("&dx: %p %lld\n", &dx, (long long)& dx % 8);
	//printf("&ca: %p %lld\n", &ca, (long long)& ca % 8);
	//printf("&cx: %p %lld\n", &cx, (long long)& cx % 8);
	//printf("&dz: %p %lld\n", &dz, (long long)& dz % 8);
	//printf("&cb: %p %lld\n", &cb, (long long)& cb % 8);
	//printf("&cz: %p %lld\n", &cz, (long long)& cz % 16);

	//unsigned char alignas(long double) c_arr[sizeof(long double)];

	return 0;
}