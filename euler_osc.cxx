#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void euler_vor(const int n, double arr_vor[][2], const double step);
void make_file_vor (const int n, double arr_vor[][2],  const double step);
void euler_back(const int n, double arr_vor[][2], const double step);
void make_file_back (const int n, double arr_back[][2],  const double step);
int main()
{
	const double PI=3.14;
	const double t_beg=0.0;
	const double t_end=20.0*PI;
	const double step=PI/100;
	const int n=2000;


	double arr_vor[n][2];
	double arr_back[n][2];

	euler_vor(n, arr_vor,step);
	make_file_vor (n, arr_vor,step);
	euler_back(n,arr_back,step);
	make_file_back(n,arr_back,step);

    return 0;
}

void euler_vor(const int n, double arr_vor[][2], const double step)
{
	arr_vor[0][0]=1;
	arr_vor[0][1]=0;
	for(int i=1; i<n; i++)
	{
		arr_vor[i][0]=arr_vor[i-1][0]+step*arr_vor[i-1][1] ;
		arr_vor[i][1]=arr_vor[i-1][0]*(-step)+arr_vor[i-1][1];

	}
}
void euler_back(const int n, double arr_back[][2], const double step)
{
	arr_back[0][0]=1;
	arr_back[0][1]=0;
	for(int i=1; i<n; i++)
	{
		arr_back[i][0]=(arr_back[i-1][0]+step*arr_back[i-1][1])/(pow(step,2)+1) ;
		arr_back[i][1]=(arr_back[i-1][0]*(-step)+arr_back[i-1][1])/(pow(step,2)+1) ;

	}

}

void make_file_vor (const int n, double arr_vor[][2],  const double step)
{
	ofstream out ("euler_vor.txt");
	for(int i=0; i<n; i++)
		out<<i*step<<" \t "<<arr_vor[i][0]<<" \t "<<arr_vor[i][1]<<endl;
	out.close();
}
void make_file_back (const int n, double arr_back[][2],  const double step)
{
	ofstream out ("euler_back.txt");
	for(int i=0; i<n; i++)
		out<<i*step<<" \t "<<arr_back[i][0]<<" \t "<<arr_back[i][1]<<endl;
	out.close();
}
