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
  //Matrix4d R1,R2;
  Quaterniond q1,q2;
  q1=Quaterniond(0.35,0.2,0.3,0.1);
  q2=Quaterniond(-0.5,0.4,-0.1,0.2);
  Matrix<double,3,1> t1,t2;
  t1<<0.3,0.1,0.1;
  t2<<-0.1,0.5,0.3;
  q1.normalize();
  q2.normalize();
  
  cout<<q1.coeffs()<<endl<<endl;
  cout<<q2.coeffs()<<endl;
  Vector3d p1,p2,pw;
  p1<<0.5,0,0.2;
  
  //欧式变换矩阵用Eigen::Isometry
  Isometry3d T1=Isometry3d::Identity();
  Isometry3d T2=Isometry3d::Identity();//4*4matrix
  T1.rotate(q1);
  T1.pretranslate(t1);
  
  T2.rotate(q2);
  T2.pretranslate(t2);
  
  pw=T1.inverse()*p1;
  p2=T2*pw;
  
  cout<<"\np2\n"<<p2<<endl;
  
  
  
  return 0;
}