// SPDX-FileCopyrightText: 2023 Hiroto Horimoto
// SPDX-License-Identifier: LGPL
// Some lines are derived from https://github.com/ryuichiueda/mcl.

#ifndef OCC_GRID_MAP_H__
#define OCC_GRID_MAP_H__

#include <vector>
#include "gl_mcl/Scan.h"
#include "nav_msgs/OccupancyGrid.h"

class LikelihoodFieldMap
{
public:
	LikelihoodFieldMap(const nav_msgs::OccupancyGrid &map, double likelihood_range);
	~LikelihoodFieldMap();

	void setLikelihood(int x, int y, double range);
	double likelihood(double x, double y);

	std::vector<double *> likelihoods_;
	int width_;
	int height_;

	double resolution_;
	double origin_x_;
	double origin_y_;
};

#endif