/*************************************************************************
    > File Name: useGeometry.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Tue 06 Nov 2018 08:25:41 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
#include <Eigen/Core>
#include <Eigen/Geometry>
int main()
{
	Eigen::Matrix3d rotation_matrix=Eigen::Matrix3d::Identity();//旋转矩阵 Matrix3d或Matrix3f
	Eigen::AngleAxisd rotation_vector (M_PI/4,Eigen::Vector3d(0,0,1));//旋转向量 沿Z轴45度
	cout .precision(3);
	//cout<<"rotation vector\n" << rotation_vector.matrix()<<endl;
	cout<<"rotation vector in matrix=\n"<<rotation_vector.matrix()<<endl;
	rotation_matrix=rotation_vector.toRotationMatrix();

	Eigen::Vector3d v(1,0,0);
	Eigen::Vector3d v_rotated=rotation_vector*v;
	cout<<v_rotated.transpose()<<endl<<endl;
	v_rotated=rotation_matrix*v;
	cout<<v_rotated.transpose()<<endl<<endl;

	Eigen::Vector3d euler_angles=rotation_matrix.eulerAngles(2,1,0);//2 1 0 ZYX  此处为弧度表达式
	cout<<"yaw pitch roll"<<endl<<euler_angles.transpose()<<endl;

	//欧式变换矩阵用Eigen::Isometry
	Eigen::Isometry3d T=Eigen::Isometry3d::Identity();//4*4matrix
	T.rotate(rotation_vector);
	T.pretranslate(Eigen::Vector3d(1,3,4));
	cout<<"transform matrix=\n"<<T.matrix()<<endl;

	Eigen::Vector3d v_transformed=T*v;
	cout<<"transformed vector=\n"<<v_transformed.transpose()<<endl;
	//Eigen::Affine3d Eigen::Projective3d
	
	//四元数
	Eigen::Quaterniond q=Eigen::Quaterniond(rotation_vector);
	cout<<"quaternion=\n"<<q.coeffs()<<endl;//x y z w w为实部
	q=Eigen::Quaterniond(rotation_matrix);
	cout<<"quaternion=\n"<<q.coeffs()<<endl;
	v_rotated=q*v;
	cout<<v_rotated.transpose()<<endl<<endl;


	return 0;
}

