#include<iostream>
#include<cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>
using namespace std;
using namespace Eigen;
int main()
{
  Matrix<double,5,5> matrix_xx=Eigen::MatrixXd::Random(5,5);
  cout<<matrix_xx<<endl<<endl;
  Matrix<double,3,3> matrix_33=matrix_xx.block(0,0,3,3);
  cout<<matrix_33;
  
  return 0;
}