// SPDX-FileCopyrightText: 2023 Hiroto Horimoto
// SPDX-License-Identifier: LGPL
// Some lines are derived from https://github.com/ryuichiueda/mcl.

#ifndef PF_H__
#define PF_H__

#include <vector>
#include <sstream>
#include <random>

#include "gl_mcl/Particle.h"
#include "gl_mcl/OdomModel.h"

#include "nav_msgs/OccupancyGrid.h"
#include "sensor_msgs/LaserScan.h"
#include "gl_mcl/LikelihoodFieldMap.h"
using namespace std;

class ParticleFilter
{
public: 
	ParticleFilter(double x, double y, double t, int num,
			const shared_ptr<OdomModel> &odom_model,
			const shared_ptr<LikelihoodFieldMap> &map);
	~ParticleFilter();

	vector<Particle> particles_;
	void sensorUpdate(void);
	void motionUpdate(double x, double y, double t);

	void initialize(double x, double y, double t);

	void setScan(const sensor_msgs::LaserScan::ConstPtr &msg);
	void meanPose(double &x_mean, double &y_mean, double &t_mean,
			double &x_var, double &y_var, double &t_var,
			double &xy_cov, double &yt_cov, double &tx_cov);
private:
	Pose *last_odom_;
	Pose *prev_odom_;

	Scan scan_;

	double normalizeAngle(double t);
	void resampling(void);
	bool normalize(void);
	void resetWeight(void);
	void copyScanSafely(vector<double> &ranges, double &angle_min, double &angle_increment);

	shared_ptr<OdomModel> odom_model_;
	shared_ptr<LikelihoodFieldMap> map_;
};

#endif