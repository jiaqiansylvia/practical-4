#include <iostream>
#include <cmath>
using namespace std;

// read polynomials
double * read_poly(int &n){
  cout << "il grado: ";
  cin >> n;
  double * c=new double[n+1];
  for(int i=0;i<=n;i++){
    cout << "coefficient of degree " << i << ": ";
    cin >> c[i];
  }
  return c;
}

// print polynomials
void print_poly(double *c, int n){
  int i;
  cout << c[0];
  if(n>0)
    cout << " + ";
  for(i=1;i<n;i++)
    cout << c[i] << "*x^" << i << " + ";
  if(n>0)
    cout << c[n] << "*x^" << i;
  cout << endl;
}

//calculate the value of polynomial at given "x"
double poli_value(double * p, int d, double x)
{
  double val = 0;
  for(int i = 0; i <= d; i++)
  {
    val += p[i]*pow(x,i);
  } 
  return val;
}

//calculate the sum of these two polynomials
double * poli_sum (double * p1, int d1, double * p2, int d2, int &dr) {
  double * sum_poli = new double[dr];

  for(int i = 0; i <= dr; i++) 
  {
    if (!p1[i])
      sum_poli[i] = p2[i];
    else if (!p2[i])
      sum_poli[i] = p1[i];
    else
      sum_poli[i] = p1[i] + p2[i];
  }
  print_poly(sum_poli, dr);
  return sum_poli;
}

//calculate the product of these two polynomials
double * poli_product (double * p1, int d1, double * p2, int d2, int & dr){
  double * product_poli = new double[dr];
  for(int i = 0; i <= d1; i++)
  {
    for(int j = 0; j <= d2; j++)
      product_poli[i+j] += p1[i]*p2[j]; 
  }
  print_poly(product_poli, dr);
  return product_poli;
}

int main()
{
  double *p1, *p2, *sum, *product;
  int g1, g2, d1, d2, dr,dr_sum,dr_product;
  double x, v1, v2,s;
  
  p1 = read_poly(g1);
  print_poly(p1, g1);
  p2 = read_poly(g2);
  print_poly(p2, g2);

  cout << "x:";
  cin >> x;

  v1 = poli_value(p1, g1, x);
  v2 = poli_value(p2, g2, x);
  cout << "the vaules of these two polynomials are: "<< v1 << " and " << v2 << endl;
  
  dr_sum = max(g1, g2);
  dr_product = g1+g2;
  cout<<"the sum of two polynomials is: ";
  sum = poli_sum(p1, g1, p2, g2, dr_sum);
  cout<<"the product of two polynomials is: ";
  product = poli_product(p1, g1, p2, g2, dr_product);

  delete[] p1;
  delete[] p2;
  delete[] sum;
  delete[] product;
  return 0;
}