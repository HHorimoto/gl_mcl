// SPDX-FileCopyrightText: 2023 Hiroto Horimoto
// SPDX-License-Identifier: LGPL
// Some lines are derived from https://github.com/ryuichiueda/mcl.

#ifndef ODOM_MODEL_H__
#define ODOM_MODEL_H__

#include <random>

using namespace std;

class OdomModel
{
public:
	OdomModel(double ff, double fr, double rf, double rr);
	void setDev(double length, double angle);
	double drawFwNoise(void);
	double drawRotNoise(void);

private:
	double fw_dev_;
	double rot_dev_;

	double fw_var_per_fw_;
	double fw_var_per_rot_;
	double rot_var_per_fw_;
	double rot_var_per_rot_;

	std::normal_distribution<> std_norm_dist_;

	std::random_device seed_gen_;
	std::default_random_engine engine_;
};

#endif