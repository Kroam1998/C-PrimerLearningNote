#include<iostream>
int main()
{
	// 标准对象输入输出测试
	// bazel build //chapter1/1.2:iotest
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin>> v1 >> v2;
	std::cout << "The sum of "<<v1<<" and "<<v2<< " is "<< v1+v2<<std::endl;
	return 0;
}
