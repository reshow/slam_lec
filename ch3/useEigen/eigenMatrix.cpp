/*************************************************************************
    > File Name: eigenMatrix.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Tue 06 Nov 2018 03:17:48 PM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;
#include <Eigen/Core>
#include <Eigen/Dense>
#define MATRIX_SIZE 50

int main()
{
	Eigen::Matrix<float,2,3> matrix_23;//2*3 matrix
	Eigen::Vector3d v_3d;//Matrix<double,3,1>
	Eigen::Matrix3d matrix_33=Eigen::Matrix3d::Zero();//Matrix<double,3,3>
	Eigen::Matrix<double ,Eigen::Dynamic,Eigen::Dynamic> matrix_dynamic;
	Eigen::MatrixXd matrix_x;

	matrix_23<<1,2,3,4,5,6;
	cout<<matrix_23<<endl;

	for(int i=0;i<1;i++)
		for(int j=0;j<2;j++)
		{
			cout<<matrix_23(i,j)<<endl;
		}

	v_3d<<3,2,1;
	
	Eigen::Matrix<double,2,1> result =matrix_23.cast<double>()*v_3d;//types should be the same;dimensions should be accurate
	cout<<result<<endl;
	matrix_33=Eigen::Matrix3d::Random();
	cout<<matrix_33<<endl<<endl;

	cout<<matrix_33.transpose()<<endl;
	cout<<matrix_33.sum()<<endl;
	cout<<matrix_33.trace()<<endl;
	cout<<10*matrix_33.trace()<<endl;
	cout<<matrix_33.inverse()<<endl;
	cout<<matrix_33.determinant()<<endl;
	
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver (matrix_33.transpose()*matrix_33);
	cout<<"Eigen values="<<eigen_solver.eigenvalues()<<endl;
	cout<<"Eigen vectors="<<eigen_solver.eigenvectors()<<endl;
	Eigen::Matrix< double ,MATRIX_SIZE,MATRIX_SIZE> matrix_NN;
	matrix_NN=Eigen::MatrixXd::Random(MATRIX_SIZE,MATRIX_SIZE);
	Eigen::Matrix<double,MATRIX_SIZE,1> eigen_Nd;
	eigen_Nd=Eigen::MatrixXd::Random(MATRIX_SIZE,1);
	
	clock_t time_st=clock();
	Eigen::Matrix<double ,MATRIX_SIZE,1> x=matrix_NN.inverse()*eigen_Nd;
	cout<<"normal inverse time "<<1000 * (clock() - time_st) / (double) CLOCKS_PER_SEC << "ms"<<endl;
	time_st=clock();
	x=matrix_NN.colPivHouseholderQr().solve(eigen_Nd);
	cout<<"qr inverse time "<<1000 * (clock() - time_st) / (double) CLOCKS_PER_SEC << "ms"<<endl;
	
	time_st = clock(); x = matrix_NN.partialPivLu().solve(eigen_Nd); 
	cout << "time use in LU composition is " << 1000 * (clock() - time_st) / (double) CLOCKS_PER_SEC << "ms" << endl; 

	//strange QR decomposition is the slowest in test


	return 0;

	
	



}
