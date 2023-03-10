// SPDX-FileCopyrightText: 2023 Hiroto Horimoto
// SPDX-License-Identifier: LGPL
// Some lines are derived from https://github.com/ryuichiueda/mcl. 

#include "gl_mcl/Particle.h"
#include <cmath>
using namespace std;

Particle::Particle(double x, double y, double t, double w) : p_(x, y, t)
{
	w_ = w;
}

double Particle::likelihood(LikelihoodFieldMap *map, const vector<double> &ranges,
		double angle_min, double angle_increment)
{
	double ans = 0.0;
	for(int i=0;i<ranges.size();i++){
		if(isinf(ranges[i]) or isnan(ranges[i]))
			continue;

		double ang = angle_min + i*angle_increment;
		double lx = p_.x_ + ranges[i] * cos(ang + p_.t_);
		double ly = p_.y_ + ranges[i] * sin(ang + p_.t_);

		ans += map->likelihood(lx, ly);
	}
	return ans;
}

Particle Particle::operator =(const Particle &p)
{
	p_ = p.p_;
	w_ = p.w_;
	return *this;
}
