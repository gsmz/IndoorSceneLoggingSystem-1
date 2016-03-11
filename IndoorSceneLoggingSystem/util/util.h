#pragma once
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>
#include <opencv2\opencv.hpp>
/**
* Util���O���
*/
namespace util
{
	/**
	* @fn void toString( int n )
	* �������̌^(���l�Ȃ�)�𕶎���ɕϊ�����֐�
	* @brief ������ɕϊ�����֐�
	* @param t �ϊ��������l
	* @return �ԊҌ�̕�����
	* @detail
	*/
	template<typename T>
	std::string ToString( T t );

	/**
	* @fn void replaceAll( std::string &str, const std::string from, const std::string to )
	* �����񒆂Ɋ܂܂��S�Ă̎w�肵�������������ʂ̕�����ɒu��������
	* @brief �u���֐�
	* @param str ���̕�����
	* @param from �u���Ώۂ̕�����
	* @param to �u��������
	* @return �u����̕�����
	* @detail ������str�Ɋ܂܂�镶����from�𕶎���to�ɒu��������B�����܂܂��ꍇ�͂��ׂĒu���B���ʂ�str�Ɋi�[�����B
	*/
	void ReplaceAll( std::string &str, const std::string from, const std::string to );

	/**
	* @fn std::vector<std::string> split( std::string s, const std::string t )
	* ��������w�蕶����ŋ�؂�
	* @brief ��������w�蕶����ŋ�؂�
	* @param s ��؂肽��������
	* @param t ��؂�L���i������j
	* @return ��؂�����̕�����̔z��
	* @detail ������s�ɑ΂��ċ�؂蕶��(��)t�ɂ���ċ�؂�B��؂�ꂽ�������string��vector�z��Ɋi�[����Ԃ����B
	*/
	std::vector<std::string> Split( std::string s, std::string t );

	std::vector<std::string> SplitFirst( std::string s, const std::string t );

	cv::Mat ConvertVec2Mat( const std::vector<unsigned char>& vec );
	cv::Mat ConvertString2Mat( std::string str );
	std::string ConvertMat2String( cv::Mat mat );

}