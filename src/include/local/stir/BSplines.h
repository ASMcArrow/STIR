//
// $Id$
//
/*
    Copyright (C) 2005- $Date$, Hammersmith Imanet Ltd
    This file is part of STIR.

    This file is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.

    This file is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    See STIR/LICENSE.txt for details
*/
/*!
  \file 
  \ingroup numerics_buildblock
  \brief Implementation of the (cubic) B-Splines Interpolation 

  \author Charalampos Tsoumpas
  \author Kris Thielemans

  $Date$
  $Revision$
*/

#include "stir/shared_ptr.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include "local/stir/IR_filters.h"

START_NAMESPACE_STIR

typedef double pos_type;

template <typename out_elemT, typename in_elemT>
class BSplines1DRegularGrid
{
private:
	typedef typename std::vector<out_elemT>::iterator RandIterOut; 
	int input_size; // create in the constructor 
	std::vector<out_elemT> BSplines_coef_vector;  
public:
	
/*
void
inline  
BSplines1DRegular();
				  */
 //! default constructor: no input
  inline BSplines1DRegularGrid();
  
  //! constructor given a vector as an input, estimates the Coefficients 
  inline explicit BSplines1DRegularGrid(const std::vector<in_elemT> & input_vector);
  		
  //! constructor given a begin_ and end_ iterator as input, estimates the Coefficients 
  template <class IterT>
  inline BSplines1DRegularGrid(const IterT input_begin_iterator, 
				  const IterT input_end_iterator)
  {
	 set_coef(input_begin_iterator, input_end_iterator);
  }

 //! destructor
inline ~BSplines1DRegularGrid();

  // sadly,VC6.0 needs definition of template members in the class definition
  template <class IterT>
inline
  void
  set_coef(IterT input_begin_iterator, IterT input_end_iterator)
  {	
	input_size = input_end_iterator - input_begin_iterator;
	BSplines_coef_vector.resize(input_size);
	BSplines_coef(BSplines_coef_vector.begin(),BSplines_coef_vector.end(), 
			input_begin_iterator, input_end_iterator);				
  }

inline 
out_elemT
BSpline(const pos_type relative_position, const bool deriv) ;

inline 
out_elemT
BSpline_1st_der(const pos_type relative_position) ;

inline
out_elemT
BSpline_product(const int index, const pos_type relative_position, const bool deriv);

inline
const out_elemT 
operator() (const pos_type relative_position) const;

inline
out_elemT 
operator() (const pos_type relative_position);

inline
const std::vector<out_elemT> 
BSpline_output_sequence(RandIterOut output_relative_position_begin_iterator,  //relative_position might be better float
						RandIterOut output_relative_position_end_iterator);
inline
const std::vector<out_elemT> 
BSpline_output_sequence(std::vector<pos_type> output_relative_position);
};

template <class IterT>
inline 
#if defined(_MSC_VER) && _MSC_VER<=1300
  float
#else
  typename std::iterator_traits<IterT>::value_type
#endif
		cplus0(const IterT input_iterator,  
		const IterT input_end_iterator,
		unsigned int Nmax,
		double pole, // to be complex as well?
		const double precision, const bool periodicity);

template <class RandIterOut, class IterT>
inline  
void
BSplines_coef(RandIterOut c_begin_iterator, 
			   RandIterOut c_end_iterator,
			   IterT input_begin_iterator, 
			   IterT input_end_iterator);

template <typename pos_type>
inline 
pos_type 
BSplines_weight(const pos_type relative_position);

template <typename pos_type>
inline 
pos_type 
BSplines_1st_der_weight(const pos_type relative_position) ;

//*/
END_NAMESPACE_STIR

#include "local/stir/BSplines.inl"