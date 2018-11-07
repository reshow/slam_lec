#include<iostream>
#include<cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <Eigen/Dense>
#include <ctime>
using namespace std;
using namespace Eigen;
int main()
{
  //Ax=b   x=A^(-1)b
  int A_sizem,A_sizen;
  cout<<"input A"<<endl;
  //cin>>A_sizem>>A_sizen;
  A_sizem=3;//*
  A_sizen=3;//*
  
  Matrix<double,Eigen::Dynamic,Eigen::Dynamic> A=MatrixXd::Random(A_sizem,A_sizen);
  double temp;
  for (int i=0;i<A_sizem;i++)
    for (int j=0;j<A_sizen;j++)
    {
      //cin>>temp;
      //A(i,j)=temp;
      //cin>>A(i,j);
    }
  A=A.transpose()*A;//*
  cout<<"A\n"<<A<<endl<<endl;
  Matrix<double,Eigen::Dynamic,Eigen::Dynamic> x=MatrixXd::Random(A_sizen,1);
  Matrix<double,Eigen::Dynamic,Eigen::Dynamic> b=MatrixXd::Random(A_sizem,1);
  cout<<"input b\n";
  for (int i=0;i<A_sizem;i++)
  {
    //cin>>b(i,0);
    b(i,0)=i+i*i;//*
  }
  cout<<"1.求逆\n";
  clock_t time_st=clock();
  Matrix<double,Eigen::Dynamic,Eigen::Dynamic> A_inverse=A.inverse();
  cout<<"1.A.inverse\n"<<A.inverse()<<endl;
  x=A_inverse*b;
  cout<<"1.x\n"<<x<<endl<<endl;
  cout<<"normal inverse time "<<1000 * (clock() - time_st) / (double) CLOCKS_PER_SEC << "ms"<<endl;
  time_st=clock();
  
  cout<<"2.Qr\n";
  x=A.colPivHouseholderQr().solve(b);
  cout<<"2.x\n"<<x<<endl<<endl;
  cout<<"qr inverse time "<<1000 * (clock() - time_st) / (double) CLOCKS_PER_SEC << "ms"<<endl;
  time_st = clock(); 
  
  cout<<"3.LU\n";
  x = A.partialPivLu().solve(b); 
  cout<<"3.x\n"<<x<<endl<<endl;
  cout<<"lu inverse time "<<1000 * (clock() - time_st) / (double) CLOCKS_PER_SEC << "ms"<<endl;
  time_st = clock(); 
  
  cout<<"4.最小二乘法\n";//A^TAx=A^Tb 可以解非方阵
  x=(A.transpose()*A).partialPivLu().solve(A.transpose()*b);
  cout<<"4.x\n"<<x<<endl<<endl;
  cout<<"Lu最小二乘 inverse time "<<1000 * (clock() - time_st) / (double) CLOCKS_PER_SEC << "ms"<<endl;
  time_st = clock(); 
  
  //http://www.cnblogs.com/newneul/p/8306442.html jacobi方法迭代求解
  return 0;
}