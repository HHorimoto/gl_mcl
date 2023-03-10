// SPDX-FileCopyrightText: 2023 Hiroto Horimoto
// SPDX-License-Identifier: LGPL
// Some lines are derived from https://github.com/ryuichiueda/mcl. 

#ifndef PARTICLE_H__
#define PARTICLE_H__

#include "gl_mcl/Pose.h"
#include "gl_mcl/LikelihoodFieldMap.h"
using namespace std;

class Particle
{
public:
	Particle(double x, double y, double t, double w);

	double likelihood(LikelihoodFieldMap *map, const vector<double> &ranges,
		double angle_min, double angle_increment);
	Pose p_;
	double w_;

	Particle operator =(const Particle &p);
};

#endif