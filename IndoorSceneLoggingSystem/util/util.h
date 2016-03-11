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
* Util名前空間
*/
namespace util
{
	/**
	* @fn void toString( int n )
	* いくつかの型(数値など)を文字列に変換する関数
	* @brief 文字列に変換する関数
	* @param t 変換したい値
	* @return 返還後の文字列
	* @detail
	*/
	template<typename T>
	std::string ToString( T t );

	/**
	* @fn void replaceAll( std::string &str, const std::string from, const std::string to )
	* 文字列中に含まれる全ての指定した部分文字列を別の文字列に置き換える
	* @brief 置換関数
	* @param str 元の文字列
	* @param from 置換対象の文字列
	* @param to 置換文字列
	* @return 置換後の文字列
	* @detail 文字列strに含まれる文字列fromを文字列toに置き換える。複数含まれる場合はすべて置換。結果はstrに格納される。
	*/
	void ReplaceAll( std::string &str, const std::string from, const std::string to );

	/**
	* @fn std::vector<std::string> split( std::string s, const std::string t )
	* 文字列を指定文字列で区切る
	* @brief 文字列を指定文字列で区切る
	* @param s 区切りたい文字列
	* @param t 区切り記号（文字列）
	* @return 区切った後の文字列の配列
	* @detail 文字列sに対して区切り文字(列)tによって区切る。区切られた文字列はstringのvector配列に格納され返される。
	*/
	std::vector<std::string> Split( std::string s, std::string t );

	std::vector<std::string> SplitFirst( std::string s, const std::string t );

	cv::Mat ConvertVec2Mat( const std::vector<unsigned char>& vec );
	cv::Mat ConvertString2Mat( std::string str );
	std::string ConvertMat2String( cv::Mat mat );

}