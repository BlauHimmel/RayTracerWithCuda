#pragma once

#ifndef __MATRIX_4F__
#define __MATRIX_4F__

#include "Math\Dependency\MathDependency.h"
#include "Math\Dependency\MathMacro.h"

namespace EasyMath
{

	class Matrix4f
	{

	public:

		friend class Transform;

	private:

		float m_Data[4][4];

	public:

		Matrix4f();
		Matrix4f(
			float A11, float A12, float A13, float A14,
			float A21, float A22, float A23, float A24,
			float A31, float A32, float A33, float A34,
			float A41, float A42, float A43, float A44
		);
		Matrix4f(const Matrix4f& other);

	public:

		friend Matrix4f operator + (const Matrix4f& Matrix, float Scale);
		friend Matrix4f operator - (const Matrix4f& Matrix, float Scale);
		friend Matrix4f operator * (const Matrix4f& Matrix, float Scale);
		friend Matrix4f operator * (float Scale, const Matrix4f& Matrix);
		friend Matrix4f operator / (const Matrix4f& Matrix, float Scale);

	public:

		friend std::ostream& operator << (std::ostream &Out, const Matrix4f &Matrix);
		friend std::istream& operator >> (std::istream &In, Matrix4f &Matrix);

	public:

		float& operator () (int32 Row, int32 Column);
		float operator () (int32 Row, int32 Column) const;
		bool operator == (const Matrix4f& Other) const;
		bool operator != (const Matrix4f& Other) const;
		Matrix4f operator * (const Matrix4f& Matrix); 
		Matrix4f& operator = (const Matrix4f& Other);
		Matrix4f& operator += (const Matrix4f& Matrix);
		Matrix4f& operator -= (const Matrix4f& Matrix);
		Matrix4f& operator *= (const Matrix4f& Matrix);
		Matrix4f& operator *= (float Scale);
		Matrix4f operator - () const;

	public:

		void SetIdentity();
		void SetZero();
		void Trim();
		Matrix4f Inverse() const;
		Matrix4f Transpose() const;
		float Determinant() const;

	private:

		float Determinant(
			float A11, float A12, float A13,
			float A21, float A22, float A23,
			float A31, float A32, float A33
		) const;
		float Determinant(
			float A11, float A12,
			float A21, float A22
		) const;

	};
}

#endif