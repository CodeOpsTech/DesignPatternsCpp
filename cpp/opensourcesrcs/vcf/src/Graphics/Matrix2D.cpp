/**
*Copyright (c) 2000-2001, Jim Crafton
*All rights reserved.
*Redistribution and use in source and binary forms, with or without
*modification, are permitted provided that the following conditions
*are met:
*	Redistributions of source code must retain the above copyright
*	notice, this list of conditions and the following disclaimer.
*
*	Redistributions in binary form must reproduce the above copyright
*	notice, this list of conditions and the following disclaimer in 
*	the documentation and/or other materials provided with the distribution.
*
*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
*AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
*OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
*PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
*SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*NB: This software will not save the world.
*/

/* Generated by Together */
#include "GraphicsKit.h"
#include "VCFMath.h"


using namespace VCF;

Matrix2D::Matrix2D()
{
	this->identity();
}

Matrix2D::Matrix2D( const Matrix2D& matrix )
{
	memcpy( this->m_matrix, matrix.m_matrix, 9 * sizeof(double) );
}

Matrix2D::~Matrix2D()
{

}

void Matrix2D::transpose( Matrix2D* dest )
{
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			dest->m_matrix[i][j] = this->m_matrix[j][i];
		}
	}
}

void Matrix2D::reflect( const bool& reflectX, const bool& reflectY )
{
	this->identity();
	if ( true == reflectX ){
		m_matrix[1][1] = -1;
	}
	if ( true == reflectY ){
		m_matrix[0][0] = -1;
	}
}

void Matrix2D::rotate( const double& theta )
{
	this->identity();
	m_matrix[0][0] = cos( theta );
	m_matrix[0][1] = sin( theta );
	m_matrix[1][0] = -m_matrix[0][1];
	m_matrix[1][1] = m_matrix[0][0];
}

void Matrix2D::shear( const double& shearX, const double& shearY )
{
	/**
	*the shear values come into us as degrees - we need to converto 
	*radians
	*/
	this->identity();
	m_matrix[1][0] = Math::degreesToRadians( shearX );
	m_matrix[0][1] = Math::degreesToRadians( shearY );
}

void Matrix2D::scale( const double& scaleX, const double& scaleY )
{
	this->identity();
	m_matrix[0][0] = scaleX;
	m_matrix[1][1] = scaleY;
}

void Matrix2D::identity()
{
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			if ( i == j ){
				this->m_matrix[i][j] = 1.0;
			}
			else {
				this->m_matrix[i][j] = 0.0;
			}
		}
	}
}

Matrix2D* Matrix2D::multiply( Matrix2D* m1, Matrix2D* m2 )
{
	if ( (NULL != m1) && (NULL != m2) ) {
		this->m_matrix[0][0] = m1->m_matrix[0][0] * m2->m_matrix[0][0] + m1->m_matrix[0][1] * m2->m_matrix[1][0];
		this->m_matrix[0][1] = m1->m_matrix[0][0] * m2->m_matrix[0][1] + m1->m_matrix[0][1] * m2->m_matrix[1][1];
		this->m_matrix[0][2] = 0.0;
		
		this->m_matrix[1][0] = m1->m_matrix[1][0] * m2->m_matrix[0][0] + m1->m_matrix[1][1] * m2->m_matrix[1][0];
		this->m_matrix[1][1] = m1->m_matrix[1][0] * m2->m_matrix[0][1] + m1->m_matrix[1][1] * m2->m_matrix[1][1];
		this->m_matrix[1][2] = 0.0;
		
		this->m_matrix[2][0] = (m1->m_matrix[2][0] * m2->m_matrix[0][0]) + (m1->m_matrix[2][1] * m2->m_matrix[1][0]) + m2->m_matrix[2][0];
		this->m_matrix[2][1] = (m1->m_matrix[2][0] * m2->m_matrix[0][1]) + (m1->m_matrix[2][1] * m2->m_matrix[1][1]) + m2->m_matrix[2][1];
		this->m_matrix[2][2] = 1.0;
		return this;
	}
	else {
		return NULL;
	}
}

void Matrix2D::translate( const double& transX, const double& transY )
{
	this->identity();
	m_matrix[2][0] = transX;
	m_matrix[2][1] = transY;
}

void Matrix2D::invert()
{

}

Point* Matrix2D::apply( Point* point )
{
	return NULL;
}

bool Matrix2D::isEqual( Object* object )const
{
	Matrix2D* m = dynamic_cast<Matrix2D*>(object);
	if ( NULL != m ){
		for ( int i=0;i<3;i++){
			for (int j=0;j<3;j++){
				if ( this->m_matrix[i][j] != m->m_matrix[i][j] ){
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

void Matrix2D::copy( Object* source )
{
	Matrix2D* m = dynamic_cast<Matrix2D*>( source );
	memcpy( this->m_matrix, m->m_matrix, 9 * sizeof(double) );
	/** 
	slow way
	if ( NULL != m ){
		for ( int i=0;i<3;i++){
			for (int j=0;j<3;j++){
				this->m_matrix[i][j] = m->m_matrix[i][j];
			}
		}
	}
	*/
}

Matrix2D& Matrix2D::operator=( const Matrix2D& matrix )
{
	this->copy( (Object*)&matrix );	
	return *this;
}

bool Matrix2D::operator == ( const Matrix2D& matrix )const
{	
	return this->isEqual( (Object*)&matrix );
}

double Matrix2D::operator[]( int subscript )
{
	double result = 0.0;
	switch ( subscript ){
		case M_00 : {
			result = this->m_matrix[0][0];
		}
		break;

		case M_01 : {
			result = this->m_matrix[0][1];
		}
		break;

		case M_02 : {
			result = this->m_matrix[0][2];
		}
		break;

		case M_10 : {
			result = this->m_matrix[1][0];
		}
		break;

		case M_11 : {
			result = this->m_matrix[1][1];			
		}
		break;

		case M_12 : {
			result = this->m_matrix[1][2];
		}
		break;

		case M_20 : {
			result = this->m_matrix[2][0];
		}
		break;

		case M_21 : {
			result = this->m_matrix[2][1];
		}
		break;

		case M_22 : {
			result = this->m_matrix[2][2];
		}
		break;
	}

	return result;
}