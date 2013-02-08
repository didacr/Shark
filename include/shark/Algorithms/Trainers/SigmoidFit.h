//===========================================================================
/*!
 *  \file SigmoidFit.h
 *
 *  \brief Optimization of the SigmoidModel according to Platt, 1999.
 *
 *  \author  T. Glasmachers, O.Krause
 *  \date    2010
 *
 *  \par Copyright (c) 1999-2006:
 *      Institut f&uuml;r Neuroinformatik<BR>
 *      Ruhr-Universit&auml;t Bochum<BR>
 *      D-44780 Bochum, Germany<BR>
 *      Phone: +49-234-32-25558<BR>
 *      Fax:   +49-234-32-14209<BR>
 *      eMail: Shark-admin@neuroinformatik.ruhr-uni-bochum.de<BR>
 *      www:   http://www.neuroinformatik.ruhr-uni-bochum.de<BR>
 *
 *
 *  <BR><HR>
 *  This file is part of Shark. This library is free software;
 *  you can redistribute it and/or modify it under the terms of the
 *  GNU General Public License as published by the Free Software
 *  Foundation; either version 3, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this library; if not, see <http://www.gnu.org/licenses/>.
 *  
 */
//===========================================================================


#ifndef SHARK_ALGORITHMS_TRAINERS_SIGMOIDFIT_H
#define SHARK_ALGORITHMS_TRAINERS_SIGMOIDFIT_H

#include <shark/Algorithms/Trainers//AbstractTrainer.h>
#include <shark/Models/SigmoidModel.h>

namespace shark{
	
	
//! \brief Optimizes the parameters of a sigmoid to fit a validation dataset via backpropagation on the negative log-likelihood.
//! 
//! \par
//! The SigmoidFitPlatt class implements a non-iterative optimizer,
//! despite the optimization task and optimizer being iterative in nature.
//! This class simply relies on a user-definable number of Rprop optimization steps
//! to adapt the sigmoid parameters.
//! 
class SigmoidFitRpropNLL: public AbstractTrainer<SigmoidModel, unsigned int>
{
public:
	SigmoidFitRpropNLL( unsigned int iters = 100 );

	void train(SigmoidModel& model, LabeledData<RealVector, unsigned int> const& dataset);
	
private:
	unsigned int m_iterations;
};


//!
//! \brief Optimizes the parameters of a sigmoid to fit a validation dataset via Platt's method.
//!
//! \par
//! The SigmoidFitPlatt class implements a non-iterative optimizer,
//! despite the optimization task and optimizer being iterative in nature.
//! The algorithm corresponds to the one suggested by John Platt in 
//! 1999, and is almost literally taken from <br> <i>Probabilistic Outputs for
//! Support Vector Machines and Comparisons to Regularized Likelihood Methods,
//! Advances in Large Margin Classifiers, pp. 61-74,
//! MIT Press, (1999).</i><br>
//! The full paper can be downloaded from<br>
//! <i>http://www.research.microsoft.com/~jplatt</i><br>
//! --- pseudo-code is given in the paper.
//!
class SigmoidFitPlatt: public AbstractTrainer<SigmoidModel, unsigned int>
{
public:
	void train(SigmoidModel& model, LabeledData<RealVector, unsigned int> const& dataset);
};


}
#endif